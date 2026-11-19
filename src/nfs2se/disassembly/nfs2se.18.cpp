#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_47c525(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c525  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c526  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c527  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c528  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c529  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047c52f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c531  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047c533  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047c535  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c536  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0047c53b  2eff15bc744b00         -call dword ptr cs:[0x4b74bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945084) /* 0x4b74bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c542  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c544  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c546  7507                   -jne 0x47c54f
    if (!cpu.flags.zf)
    {
        goto L_0x0047c54f;
    }
    // 0047c548  e8b5da0100             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 0047c54d  eb20                   -jmp 0x47c56f
    goto L_0x0047c56f;
L_0x0047c54f:
    // 0047c54f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c551  7520                   -jne 0x47c573
    if (!cpu.flags.zf)
    {
        goto L_0x0047c573;
    }
    // 0047c553  40                     -inc eax
    (cpu.eax)++;
    // 0047c554  39c6                   +cmp esi, eax
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
    // 0047c556  7602                   -jbe 0x47c55a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c55a;
    }
    // 0047c558  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047c55a:
    // 0047c55a  e8b4da0100             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 0047c55f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c561  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c563  7519                   -jne 0x47c57e
    if (!cpu.flags.zf)
    {
        goto L_0x0047c57e;
    }
    // 0047c565  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x0047c56a:
    // 0047c56a  e891db0100             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
L_0x0047c56f:
    // 0047c56f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c571  eb28                   -jmp 0x47c59b
    goto L_0x0047c59b;
L_0x0047c573:
    // 0047c573  39f0                   +cmp eax, esi
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
    // 0047c575  7607                   -jbe 0x47c57e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c57e;
    }
    // 0047c577  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0047c57c  ebec                   -jmp 0x47c56a
    goto L_0x0047c56a;
L_0x0047c57e:
    // 0047c57e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047c580  41                     -inc ecx
    (cpu.ecx)++;
    // 0047c581  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047c583  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0047c584  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0047c586  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0047c588  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c589  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c58b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047c58e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047c590  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047c592  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047c595  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047c597  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c598  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0047c599  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047c59b:
    // 0047c59b  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047c5a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c5a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c5a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c5a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c5a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c5a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c5a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c5a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c5a8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c5ab  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047c5ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c5af  7419                   -je 0x47c5ca
    if (cpu.flags.zf)
    {
        goto L_0x0047c5ca;
    }
    // 0047c5b1  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0047c5b3  b25c                   -mov dl, 0x5c
    cpu.dl = 92 /*0x5c*/;
    // 0047c5b5  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0047c5b8  88542402               -mov byte ptr [esp + 2], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dl;
    // 0047c5bc  b43a                   -mov ah, 0x3a
    cpu.ah = 58 /*0x3a*/;
    // 0047c5be  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0047c5c0  88642401               -mov byte ptr [esp + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.ah;
    // 0047c5c4  88742403               -mov byte ptr [esp + 3], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 0047c5c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0047c5ca:
    // 0047c5ca  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c5ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c5cf  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c5d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c5d4  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047c5d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c5d9  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047c5dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c5de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c5df  2eff15d0744b00         -call dword ptr cs:[0x4b74d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945104) /* 0x4b74d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c5e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c5e8  7507                   -jne 0x47c5f1
    if (!cpu.flags.zf)
    {
        goto L_0x0047c5f1;
    }
    // 0047c5ea  e813da0100             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 0047c5ef  eb1d                   -jmp 0x47c60e
    goto L_0x0047c60e;
L_0x0047c5f1:
    // 0047c5f1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c5f5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047c5f7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c5fb  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c5fe  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047c602  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c605  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c609  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047c60c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c60e:
    // 0047c60e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c611  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c612  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c613  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c621  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c622  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c623  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c625  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047c627  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c629  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c62b  7e41                   -jle 0x47c66e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c66e;
    }
L_0x0047c62d:
    // 0047c62d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c62f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047c631  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047c633  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0047c635  743b                   -je 0x47c672
    if (cpu.flags.zf)
    {
        goto L_0x0047c672;
    }
    // 0047c637  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c639  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047c63b  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
L_0x0047c63e:
    // 0047c63e  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0047c640  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047c642  7425                   -je 0x47c669
    if (cpu.flags.zf)
    {
        goto L_0x0047c669;
    }
    // 0047c644  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c646  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0047c648  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047c64a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0047c64c  742f                   -je 0x47c67d
    if (cpu.flags.zf)
    {
        goto L_0x0047c67d;
    }
    // 0047c64e  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047c650  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0047c653  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c655  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0047c657  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c65d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x0047c660:
    // 0047c660  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c662  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c664  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0047c666  881431                 -mov byte ptr [ecx + esi], dl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.dl;
L_0x0047c669:
    // 0047c669  40                     -inc eax
    (cpu.eax)++;
    // 0047c66a  39d8                   +cmp eax, ebx
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
    // 0047c66c  7cbf                   -jl 0x47c62d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c62d;
    }
L_0x0047c66e:
    // 0047c66e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c66f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c670  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c671  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c672:
    // 0047c672  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047c674  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c676  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 0047c679  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0047c67b  ebc1                   -jmp 0x47c63e
    goto L_0x0047c63e;
L_0x0047c67d:
    // 0047c67d  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047c67f  80e6f0                 -and dh, 0xf0
    cpu.dh &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0047c682  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c684  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0047c686  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0047c68c  ebd2                   -jmp 0x47c660
    goto L_0x0047c660;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0047c691:
    // 0047c691  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047c693  40                     -inc eax
    (cpu.eax)++;
    // 0047c694  80f9ff                 +cmp cl, 0xff
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
    // 0047c697  7506                   -jne 0x47c69f
    if (!cpu.flags.zf)
    {
        goto L_0x0047c69f;
    }
    // 0047c699  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c69a  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c69b  75f4                   -jne 0x47c691
    if (!cpu.flags.zf)
    {
        goto L_0x0047c691;
    }
    // 0047c69d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c69e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c69f:
    // 0047c69f  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 0047c6a1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047c6a2  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c6a3  75ec                   -jne 0x47c691
    if (!cpu.flags.zf)
    {
        goto L_0x0047c691;
    }
    // 0047c6a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47c6a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c6a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0047c6a9:
    // 0047c6a9  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0047c6ac  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0047c6af  750b                   -jne 0x47c6bc
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6bc;
    }
    // 0047c6b1  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047c6b4  83c202                 +add edx, 2
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
    // 0047c6b7  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c6b8  75ef                   -jne 0x47c6a9
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6a9;
    }
    // 0047c6ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c6bc:
    // 0047c6bc  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0047c6bf  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047c6c2  83c202                 +add edx, 2
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
    // 0047c6c5  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c6c6  75e1                   -jne 0x47c6a9
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6a9;
    }
    // 0047c6c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c6cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c6cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c6cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c6ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c6cf  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 0047c6d4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0047c6d6:
    // 0047c6d6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047c6d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c6da  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047c6de  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047c6e0  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047c6e7  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047c6e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c6eb  750d                   -jne 0x47c6fa
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6fa;
    }
    // 0047c6ed  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047c6f0  83c203                 +add edx, 3
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
    // 0047c6f3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c6f4  75e0                   -jne 0x47c6d6
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6d6;
    }
    // 0047c6f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c6fa:
    // 0047c6fa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047c6fc  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047c6fe  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047c701  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047c704  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0047c707  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047c70a  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047c70d  83c203                 +add edx, 3
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
    // 0047c710  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c711  75c3                   -jne 0x47c6d6
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6d6;
    }
    // 0047c713  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c714  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c715  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47c718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c718  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c719  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0047c71a:
    // 0047c71a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047c71c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047c71e  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 0047c721  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047c723  750c                   -jne 0x47c731
    if (!cpu.flags.zf)
    {
        goto L_0x0047c731;
    }
    // 0047c725  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c728  83c204                 +add edx, 4
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
    // 0047c72b  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c72c  75ec                   -jne 0x47c71a
    if (!cpu.flags.zf)
    {
        goto L_0x0047c71a;
    }
    // 0047c72e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c72f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c730  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c731:
    // 0047c731  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047c733  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c736  83c204                 +add edx, 4
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
    // 0047c739  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047c73a  75de                   -jne 0x47c71a
    if (!cpu.flags.zf)
    {
        goto L_0x0047c71a;
    }
    // 0047c73c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c73d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c73e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47c740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c742  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c743  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c744  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0047c74a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047c74c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047c74e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047c750  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047c753  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0047c759  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c75b  83f804                 +cmp eax, 4
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
    // 0047c75e  0f8580000000           -jne 0x47c7e4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c7e4;
    }
    // 0047c764  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047c766:
    // 0047c766  8b0cad709f5200         -mov ecx, dword ptr [ebp*4 + 0x529f70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414768) /* 0x529f70 */ + cpu.ebp * 4);
    // 0047c76d  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 0047c774  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c776  890de0a94c00           -mov dword ptr [0x4ca9e0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024224) /* 0x4ca9e0 */) = cpu.ecx;
    // 0047c77c  890cad709f5200         -mov dword ptr [ebp*4 + 0x529f70], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414768) /* 0x529f70 */ + cpu.ebp * 4) = cpu.ecx;
    // 0047c783  83fa08                 +cmp edx, 8
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
    // 0047c786  752d                   -jne 0x47c7b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047c7b5;
    }
    // 0047c788  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c78f  7524                   -jne 0x47c7b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047c7b5;
    }
    // 0047c791  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047c793  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c795  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 0047c79a  e831a30100             -call 0x496ad0
    cpu.esp -= 4;
    sub_496ad0(app, cpu);
    if (cpu.terminate) return;
    // 0047c79f  ba3ca14900             -mov edx, 0x49a13c
    cpu.edx = 4825404 /*0x49a13c*/;
    // 0047c7a4  a398d95100             -mov dword ptr [0x51d998], eax
    app->getMemory<x86::reg32>(x86::reg32(5364120) /* 0x51d998 */) = cpu.eax;
    // 0047c7a9  890de8a94c00           -mov dword ptr [0x4ca9e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024232) /* 0x4ca9e8 */) = cpu.ecx;
    // 0047c7af  8915e0a94c00           -mov dword ptr [0x4ca9e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5024224) /* 0x4ca9e0 */) = cpu.edx;
L_0x0047c7b5:
    // 0047c7b5  b9c8a94c00             -mov ecx, 0x4ca9c8
    cpu.ecx = 5024200 /*0x4ca9c8*/;
    // 0047c7ba  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047c7bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c7be  e819a90100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 0047c7c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c7c5  8b842400040000         -mov eax, dword ptr [esp + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0047c7cc  891de8a94c00           -mov dword ptr [0x4ca9e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5024232) /* 0x4ca9e8 */) = cpu.ebx;
    // 0047c7d2  8904ad709f5200         -mov dword ptr [ebp*4 + 0x529f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5414768) /* 0x529f70 */ + cpu.ebp * 4) = cpu.eax;
    // 0047c7d9  81c404040000           +add esp, 0x404
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
    // 0047c7df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c7e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c7e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c7e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c7e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c7e4:
    // 0047c7e4  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0047c7e9  e978ffffff             -jmp 0x47c766
    goto L_0x0047c766;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c7f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c7f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c7f2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047c7f5  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047c7f8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047c7fb  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0047c7fe  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047c801  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047c804  e837ffffff             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0047c809  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c80a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c80b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c80c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c80c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c80d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047c810  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047c813  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c815  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047c818  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047c81b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c81d  e81effffff             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0047c822  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c824  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c825  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c826  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047c829  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047c82c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047c82f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0047c832  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047c835  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047c838  e803ffffff             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0047c83d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c83e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c83f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c841  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047c844  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047c847  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c849  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047c84c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047c84f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c851  e8eafeffff             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0047c856  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c857  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c861  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047c866  e811000000             -call 0x47c87c
    cpu.esp -= 4;
    sub_47c87c(app, cpu);
    if (cpu.terminate) return;
    // 0047c86b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c86c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c871  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c873  e804000000             -call 0x47c87c
    cpu.esp -= 4;
    sub_47c87c(app, cpu);
    if (cpu.terminate) return;
    // 0047c878  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c879  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c87c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c87c  e823000000             -call 0x47c8a4
    cpu.esp -= 4;
    sub_47c8a4(app, cpu);
    if (cpu.terminate) return;
    // 0047c881  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c883  7402                   -je 0x47c887
    if (cpu.flags.zf)
    {
        goto L_0x0047c887;
    }
    // 0047c885  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0047c887:
    // 0047c887  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c889  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047c88e  e811000000             -call 0x47c8a4
    cpu.esp -= 4;
    sub_47c8a4(app, cpu);
    if (cpu.terminate) return;
    // 0047c893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c898  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c899  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c89b  e804000000             -call 0x47c8a4
    cpu.esp -= 4;
    sub_47c8a4(app, cpu);
    if (cpu.terminate) return;
    // 0047c8a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c8a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c8a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c8a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c8a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c8a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c8a8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047c8ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047c8ad  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047c8b1  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047c8b3  e8bcb70100             -call 0x498074
    cpu.esp -= 4;
    sub_498074(app, cpu);
    if (cpu.terminate) return;
    // 0047c8b8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c8ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c8bc  7417                   -je 0x47c8d5
    if (cpu.flags.zf)
    {
        goto L_0x0047c8d5;
    }
L_0x0047c8be:
    // 0047c8be  833d80ce4c0000         +cmp dword ptr [0x4cce80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033600) /* 0x4cce80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c8c5  0f8590000000           -jne 0x47c95b
    if (!cpu.flags.zf)
    {
        goto L_0x0047c95b;
    }
    // 0047c8cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c8cd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047c8d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c8d5:
    // 0047c8d5  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0047c8da  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0047c8dc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c8e0  e88fc20100             -call 0x498b74
    cpu.esp -= 4;
    sub_498b74(app, cpu);
    if (cpu.terminate) return;
    // 0047c8e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c8e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c8e8  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c8ec  e897060000             -call 0x47cf88
    cpu.esp -= 4;
    sub_47cf88(app, cpu);
    if (cpu.terminate) return;
    // 0047c8f1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047c8f4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c8f6  7511                   -jne 0x47c909
    if (!cpu.flags.zf)
    {
        goto L_0x0047c909;
    }
    // 0047c8f8  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c8fc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c8fe  74be                   -je 0x47c8be
    if (cpu.flags.zf)
    {
        goto L_0x0047c8be;
    }
    // 0047c900  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c902  e869090000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0047c907  ebb5                   -jmp 0x47c8be
    goto L_0x0047c8be;
L_0x0047c909:
    // 0047c909  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c90d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047c90f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c911  e84ed9ffff             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047c916  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c918  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c91a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c91c  742f                   -je 0x47c94d
    if (cpu.flags.zf)
    {
        goto L_0x0047c94d;
    }
    // 0047c91e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047c921  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c923  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 0047c928  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047c92b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047c92d  05c8000000             +add eax, 0xc8
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
    // 0047c932  e83dc20100             -call 0x498b74
    cpu.esp -= 4;
    sub_498b74(app, cpu);
    if (cpu.terminate) return;
    // 0047c937  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047c93a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c93e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047c940  e833090000             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0047c945  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047c948  a340a44c00             -mov dword ptr [0x4ca440], eax
    app->getMemory<x86::reg32>(x86::reg32(5022784) /* 0x4ca440 */) = cpu.eax;
L_0x0047c94d:
    // 0047c94d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c951  e81a090000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0047c956  e963ffffff             -jmp 0x47c8be
    goto L_0x0047c8be;
L_0x0047c95b:
    // 0047c95b  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c95f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047c961  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047c963  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c965  ff1580ce4c00           -call dword ptr [0x4cce80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033600) /* 0x4cce80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c96b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c96d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c96f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047c972  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c973  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c974  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c975  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c976  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c982  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c983  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c984  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c985  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c987  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047c98a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c98c  8b400d                 -mov eax, dword ptr [eax + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0047c98f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c992  a318ca4c00             -mov dword ptr [0x4cca18], eax
    app->getMemory<x86::reg32>(x86::reg32(5032472) /* 0x4cca18 */) = cpu.eax;
    // 0047c997  8b420e                 -mov eax, dword ptr [edx + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 0047c99a  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047c99f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c9a2  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047c9a7  a31cca4c00             -mov dword ptr [0x4cca1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5032476) /* 0x4cca1c */) = cpu.eax;
    // 0047c9ac  8b420f                 -mov eax, dword ptr [edx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0047c9af  89158cca4c00           -mov dword ptr [0x4cca8c], edx
    app->getMemory<x86::reg32>(x86::reg32(5032588) /* 0x4cca8c */) = cpu.edx;
    // 0047c9b5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c9b8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047c9ba  a328ca4c00             -mov dword ptr [0x4cca28], eax
    app->getMemory<x86::reg32>(x86::reg32(5032488) /* 0x4cca28 */) = cpu.eax;
    // 0047c9bf  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0047c9c2  891d88ca4c00           -mov dword ptr [0x4cca88], ebx
    app->getMemory<x86::reg32>(x86::reg32(5032584) /* 0x4cca88 */) = cpu.ebx;
    // 0047c9c8  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c9cb  893524ca4c00           -mov dword ptr [0x4cca24], esi
    app->getMemory<x86::reg32>(x86::reg32(5032484) /* 0x4cca24 */) = cpu.esi;
    // 0047c9d1  a32cca4c00             -mov dword ptr [0x4cca2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5032492) /* 0x4cca2c */) = cpu.eax;
    // 0047c9d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c9d8  a128ca4c00             -mov eax, dword ptr [0x4cca28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032488) /* 0x4cca28 */);
    // 0047c9dd  893dbcca4c00           -mov dword ptr [0x4ccabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5032636) /* 0x4ccabc */) = cpu.edi;
    // 0047c9e3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c9e5  893db8ca4c00           -mov dword ptr [0x4ccab8], edi
    app->getMemory<x86::reg32>(x86::reg32(5032632) /* 0x4ccab8 */) = cpu.edi;
    // 0047c9eb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c9ed  891d30ca4c00           -mov dword ptr [0x4cca30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5032496) /* 0x4cca30 */) = cpu.ebx;
    // 0047c9f3  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c9f5  891d34ca4c00           -mov dword ptr [0x4cca34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5032500) /* 0x4cca34 */) = cpu.ebx;
    // 0047c9fb  668b420a               -mov ax, word ptr [edx + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0047c9ff  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047ca01  a380ca4c00             -mov dword ptr [0x4cca80], eax
    app->getMemory<x86::reg32>(x86::reg32(5032576) /* 0x4cca80 */) = cpu.eax;
    // 0047ca06  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0047ca09  890d94ca4c00           -mov dword ptr [0x4cca94], ecx
    app->getMemory<x86::reg32>(x86::reg32(5032596) /* 0x4cca94 */) = cpu.ecx;
    // 0047ca0f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ca13  891d90ca4c00           -mov dword ptr [0x4cca90], ebx
    app->getMemory<x86::reg32>(x86::reg32(5032592) /* 0x4cca90 */) = cpu.ebx;
    // 0047ca19  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ca1b  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047ca1e  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0047ca24  a320ca4c00             -mov dword ptr [0x4cca20], eax
    app->getMemory<x86::reg32>(x86::reg32(5032480) /* 0x4cca20 */) = cpu.eax;
    // 0047ca29  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0047ca2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ca2e  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047ca31  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ca33  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047ca36  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0047ca3c  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0047ca3f  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047ca42  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047ca44  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0047ca47  a384ca4c00             -mov dword ptr [0x4cca84], eax
    app->getMemory<x86::reg32>(x86::reg32(5032580) /* 0x4cca84 */) = cpu.eax;
    // 0047ca4c  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047ca4f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047ca52  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047ca55  83f802                 +cmp eax, 2
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
    // 0047ca58  740c                   -je 0x47ca66
    if (cpu.flags.zf)
    {
        goto L_0x0047ca66;
    }
    // 0047ca5a  813d80ca4c00ff000000   +cmp dword ptr [0x4cca80], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032576) /* 0x4cca80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ca64  7e38                   -jle 0x47ca9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ca9e;
    }
L_0x0047ca66:
    // 0047ca66  c705acca4c002ca24900   -mov dword ptr [0x4ccaac], 0x49a22c
    app->getMemory<x86::reg32>(x86::reg32(5032620) /* 0x4ccaac */) = 4825644 /*0x49a22c*/;
L_0x0047ca70:
    // 0047ca70  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0047ca75  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ca77  b840ca4c00             -mov eax, 0x4cca40
    cpu.eax = 5032512 /*0x4cca40*/;
    // 0047ca7c  893d38ca4c00           -mov dword ptr [0x4cca38], edi
    app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */) = cpu.edi;
    // 0047ca82  893d3cca4c00           -mov dword ptr [0x4cca3c], edi
    app->getMemory<x86::reg32>(x86::reg32(5032508) /* 0x4cca3c */) = cpu.edi;
    // 0047ca88  e80f420000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0047ca8d  e8b6d20100             -call 0x499d48
    cpu.esp -= 4;
    sub_499d48(app, cpu);
    if (cpu.terminate) return;
    // 0047ca92  893db0ca4c00           -mov dword ptr [0x4ccab0], edi
    app->getMemory<x86::reg32>(x86::reg32(5032624) /* 0x4ccab0 */) = cpu.edi;
    // 0047ca98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ca9e:
    // 0047ca9e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047caa3  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047caa6  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047caaa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047caac  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047cab3  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047cab5  3dff000000             +cmp eax, 0xff
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
    // 0047caba  77aa                   -ja 0x47ca66
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ca66;
    }
    // 0047cabc  c705acca4c0000a24900   -mov dword ptr [0x4ccaac], 0x49a200
    app->getMemory<x86::reg32>(x86::reg32(5032620) /* 0x4ccaac */) = 4825600 /*0x49a200*/;
    // 0047cac6  eba8                   -jmp 0x47ca70
    goto L_0x0047ca70;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cad0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cad1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cad2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cad3  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 0047cad8  be0cca4c00             -mov esi, 0x4cca0c
    cpu.esi = 5032460 /*0x4cca0c*/;
    // 0047cadd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047cadf  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cae1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cae2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cae3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cae4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cae8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cae8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cae9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047caea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047caeb  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 0047caf0  bf0cca4c00             -mov edi, 0x4cca0c
    cpu.edi = 5032460 /*0x4cca0c*/;
    // 0047caf5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047caf7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047caf9  e8a6d20100             -call 0x499da4
    cpu.esp -= 4;
    sub_499da4(app, cpu);
    if (cpu.terminate) return;
    // 0047cafe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047caff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb10  a130ca4c00             -mov eax, dword ptr [0x4cca30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032496) /* 0x4cca30 */);
    // 0047cb15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47cb18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb18  a310ca4c00             -mov dword ptr [0x4cca10], eax
    app->getMemory<x86::reg32>(x86::reg32(5032464) /* 0x4cca10 */) = cpu.eax;
    // 0047cb1d  891514ca4c00           -mov dword ptr [0x4cca14], edx
    app->getMemory<x86::reg32>(x86::reg32(5032468) /* 0x4cca14 */) = cpu.edx;
    // 0047cb23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cb24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb24  a324ca4c00             -mov dword ptr [0x4cca24], eax
    app->getMemory<x86::reg32>(x86::reg32(5032484) /* 0x4cca24 */) = cpu.eax;
    // 0047cb29  e91ad20100             -jmp 0x499d48
    return sub_499d48(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47cb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb30  a124ca4c00             -mov eax, dword ptr [0x4cca24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032484) /* 0x4cca24 */);
    // 0047cb35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cb41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cb42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cb43  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cb46  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047cb48  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047cb4c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047cb50  0fb635d8a64c00         -movzx esi, byte ptr [0x4ca6d8]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */));
    // 0047cb57  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047cb5a  83c607                 -add esi, 7
    (cpu.esi) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047cb5d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cb5f  6683e6f8               -and si, 0xfff8
    cpu.si &= x86::reg16(x86::sreg16(65528 /*0xfff8*/));
    // 0047cb63  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0047cb67:
    // 0047cb67  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047cb6b  4a                     -dec edx
    (cpu.edx)--;
    // 0047cb6c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047cb70  83faff                 +cmp edx, -1
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
    // 0047cb73  0f847f000000           -je 0x47cbf8
    if (cpu.flags.zf)
    {
        goto L_0x0047cbf8;
    }
    // 0047cb79  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0047cb7c  3b7c2408               +cmp edi, dword ptr [esp + 8]
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
    // 0047cb80  7d22                   -jge 0x47cba4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047cba4;
    }
L_0x0047cb82:
    // 0047cb82  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047cb84  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047cb86  e8e5d60100             -call 0x49a270
    cpu.esp -= 4;
    sub_49a270(app, cpu);
    if (cpu.terminate) return;
    // 0047cb8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cb8d  83fe10                 +cmp esi, 0x10
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
    // 0047cb90  7315                   -jae 0x47cba7
    if (!cpu.flags.cf)
    {
        goto L_0x0047cba7;
    }
    // 0047cb92  83fe08                 +cmp esi, 8
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
    // 0047cb95  7504                   -jne 0x47cb9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb9b;
    }
    // 0047cb97  41                     -inc ecx
    (cpu.ecx)++;
    // 0047cb98  8851ff                 -mov byte ptr [ecx - 1], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
L_0x0047cb9b:
    // 0047cb9b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cb9f  47                     -inc edi
    (cpu.edi)++;
    // 0047cba0  39df                   +cmp edi, ebx
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
    // 0047cba2  7cde                   -jl 0x47cb82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cb82;
    }
L_0x0047cba4:
    // 0047cba4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047cba5  ebc0                   -jmp 0x47cb67
    goto L_0x0047cb67;
L_0x0047cba7:
    // 0047cba7  7713                   -ja 0x47cbbc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047cbbc;
    }
    // 0047cba9  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cbac  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0047cbb0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cbb4  47                     -inc edi
    (cpu.edi)++;
    // 0047cbb5  39df                   +cmp edi, ebx
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
    // 0047cbb7  7cc9                   -jl 0x47cb82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cb82;
    }
    // 0047cbb9  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047cbba  ebab                   -jmp 0x47cb67
    goto L_0x0047cb67;
L_0x0047cbbc:
    // 0047cbbc  83fe18                 +cmp esi, 0x18
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
    // 0047cbbf  72da                   -jb 0x47cb9b
    if (cpu.flags.cf)
    {
        goto L_0x0047cb9b;
    }
    // 0047cbc1  7617                   -jbe 0x47cbda
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047cbda;
    }
    // 0047cbc3  83fe20                 +cmp esi, 0x20
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
    // 0047cbc6  75d3                   -jne 0x47cb9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb9b;
    }
    // 0047cbc8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cbcb  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0047cbce  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cbd2  47                     -inc edi
    (cpu.edi)++;
    // 0047cbd3  39df                   +cmp edi, ebx
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
    // 0047cbd5  7cab                   -jl 0x47cb82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cb82;
    }
    // 0047cbd7  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047cbd8  eb8d                   -jmp 0x47cb67
    goto L_0x0047cb67;
L_0x0047cbda:
    // 0047cbda  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047cbdf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047cbe1  e809610000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cbe6  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cbe9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cbed  47                     -inc edi
    (cpu.edi)++;
    // 0047cbee  39df                   +cmp edi, ebx
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
    // 0047cbf0  7c90                   -jl 0x47cb82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cb82;
    }
    // 0047cbf2  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047cbf3  e96fffffff             -jmp 0x47cb67
    goto L_0x0047cb67;
L_0x0047cbf8:
    // 0047cbf8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cbfb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbfc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbfe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cc04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cc04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cc05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cc06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cc07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cc09  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0047cc0e  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047cc11  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047cc13  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047cc19  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cc1b  a1d0a64c00             -mov eax, dword ptr [0x4ca6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 0047cc20  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cc22  8b1dcca64c00           -mov ebx, dword ptr [0x4ca6cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0047cc28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cc2a  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0047cc2f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cc31  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047cc34  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0047cc37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cc39  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047cc3c  c1e203                 +shl edx, 3
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
    // 0047cc3f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047cc41  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0047cc44  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0047cc47  83f908                 +cmp ecx, 8
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
    // 0047cc4a  7505                   -jne 0x47cc51
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc51;
    }
    // 0047cc4c  0500030000             -add eax, 0x300
    (cpu.eax) += x86::reg32(x86::sreg32(768 /*0x300*/));
L_0x0047cc51:
    // 0047cc51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cc58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cc58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cc59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cc5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cc5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cc5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cc5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cc5e  81ec08030000           -sub esp, 0x308
    (cpu.esp) -= x86::reg32(x86::sreg32(776 /*0x308*/));
    // 0047cc64  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047cc66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cc68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cc6a  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0047cc6f  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047cc75  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047cc78  8b2dd4a64c00           -mov ebp, dword ptr [0x4ca6d4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0047cc7e  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047cc80  8b1dcca64c00           -mov ebx, dword ptr [0x4ca6cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0047cc86  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047cc88  a1d0a64c00             -mov eax, dword ptr [0x4ca6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 0047cc8d  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cc8f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cc91  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cc96  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 0047cc9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cc9f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047cca1  e849600000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cca6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047ccab  83ff08                 +cmp edi, 8
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
    // 0047ccae  0f8564010000           -jne 0x47ce18
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce18;
    }
    // 0047ccb4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0047ccb6:
    // 0047ccb6  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047ccb9  e831600000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047ccbe  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047ccc3  83ff08                 +cmp edi, 8
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
    // 0047ccc6  0f8553010000           -jne 0x47ce1f
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce1f;
    }
    // 0047cccc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0047ccce:
    // 0047ccce  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0047ccd1  e819600000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047ccd6  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047ccdb  8d4103                 -lea eax, [ecx + 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0047ccde  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cce0  e80a600000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cce5  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047ccea  83ff08                 +cmp edi, 8
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
    // 0047cced  0f8536010000           -jne 0x47ce29
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce29;
    }
    // 0047ccf3  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0047ccf8:
    // 0047ccf8  8d4105                 -lea eax, [ecx + 5]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0047ccfb  e8ef5f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd00  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cd05  83ff08                 +cmp edi, 8
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
    // 0047cd08  0f8522010000           -jne 0x47ce30
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce30;
    }
    // 0047cd0e  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
L_0x0047cd13:
    // 0047cd13  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0047cd16  e8d45f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd1b  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047cd20  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047cd26  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047cd29  e8c15f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd2e  a1c4a64c00             -mov eax, dword ptr [0x4ca6c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023428) /* 0x4ca6c4 */);
    // 0047cd33  2b05d4a64c00           -sub eax, dword ptr [0x4ca6d4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
    // 0047cd39  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 0047cd3c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047cd41  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 0047cd48  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cd4a  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0047cd51  e8995f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd56  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047cd5b  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0047cd62  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047cd65  e8855f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd6a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047cd6f  8d410e                 -lea eax, [ecx + 0xe]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0047cd72  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047cd74  e8765f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd79  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cd7e  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047cd81  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047cd83  e8675f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd88  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cd8d  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0047cd92  8d4111                 -lea eax, [ecx + 0x11]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 0047cd95  83c612                 -add esi, 0x12
    (cpu.esi) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0047cd98  e8525f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047cd9d  83ff08                 +cmp edi, 8
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
    // 0047cda0  7532                   -jne 0x47cdd4
    if (!cpu.flags.zf)
    {
        goto L_0x0047cdd4;
    }
    // 0047cda2  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047cda4  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047cda9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cdab  e8a0500100             -call 0x491e50
    cpu.esp -= 4;
    sub_491e50(app, cpu);
    if (cpu.terminate) return;
    // 0047cdb0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047cdb2:
    // 0047cdb2  46                     -inc esi
    (cpu.esi)++;
    // 0047cdb3  46                     -inc esi
    (cpu.esi)++;
    // 0047cdb4  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 0047cdb7  46                     -inc esi
    (cpu.esi)++;
    // 0047cdb8  8a5c0402               -mov bl, byte ptr [esp + eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 0047cdbc  8a4c0401               -mov cl, byte ptr [esp + eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0047cdc0  885efd                 -mov byte ptr [esi - 3], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0047cdc3  884efe                 -mov byte ptr [esi - 2], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.cl;
    // 0047cdc6  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047cdc9  8856ff                 -mov byte ptr [esi - 1], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0047cdcc  3d00030000             +cmp eax, 0x300
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
    // 0047cdd1  75df                   -jne 0x47cdb2
    if (!cpu.flags.zf)
    {
        goto L_0x0047cdb2;
    }
    // 0047cdd3  90                     -nop 
    ;
L_0x0047cdd4:
    // 0047cdd4  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0047cdd9  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0047cddf  8b1dc8a64c00           -mov ebx, dword ptr [0x4ca6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047cde5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cde7  8b15cca64c00           -mov edx, dword ptr [0x4ca6cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0047cded  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cdef  a1d0a64c00             -mov eax, dword ptr [0x4ca6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 0047cdf4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cdf5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cdf7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047cdf9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047cdfb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047cdfd  e83efdffff             -call 0x47cb40
    cpu.esp -= 4;
    sub_47cb40(app, cpu);
    if (cpu.terminate) return;
    // 0047ce02  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ce09  742c                   -je 0x47ce37
    if (cpu.flags.zf)
    {
        goto L_0x0047ce37;
    }
    // 0047ce0b  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 0047ce11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ce18:
    // 0047ce18  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047ce1a  e997feffff             -jmp 0x47ccb6
    goto L_0x0047ccb6;
L_0x0047ce1f:
    // 0047ce1f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0047ce24  e9a5feffff             -jmp 0x47ccce
    goto L_0x0047ccce;
L_0x0047ce29:
    // 0047ce29  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047ce2b  e9c8feffff             -jmp 0x47ccf8
    goto L_0x0047ccf8;
L_0x0047ce30:
    // 0047ce30  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047ce32  e9dcfeffff             -jmp 0x47cd13
    goto L_0x0047cd13;
L_0x0047ce37:
    // 0047ce37  8b9c2404030000         -mov ebx, dword ptr [esp + 0x304]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0047ce3e  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0047ce41  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ce43  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ce45  e8ded40100             -call 0x49a328
    cpu.esp -= 4;
    sub_49a328(app, cpu);
    if (cpu.terminate) return;
    // 0047ce4a  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 0047ce50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ce58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ce58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ce59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ce5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ce5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ce5c  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047ce5f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ce61  e89efdffff             -call 0x47cc04
    cpu.esp -= 4;
    sub_47cc04(app, cpu);
    if (cpu.terminate) return;
    // 0047ce66  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ce68  e8531e0100             -call 0x48ecc0
    cpu.esp -= 4;
    sub_48ecc0(app, cpu);
    if (cpu.terminate) return;
    // 0047ce6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ce6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ce71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ce73  750a                   -jne 0x47ce7f
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce7f;
    }
    // 0047ce75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ce77  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047ce7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ce7f:
    // 0047ce7f  e8d4fdffff             -call 0x47cc58
    cpu.esp -= 4;
    sub_47cc58(app, cpu);
    if (cpu.terminate) return;
    // 0047ce84  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047ce86  e8d5ab0100             -call 0x497a60
    cpu.esp -= 4;
    sub_497a60(app, cpu);
    if (cpu.terminate) return;
    // 0047ce8b  e88cb0ffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047ce90  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ce92  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ce94  e837000000             -call 0x47ced0
    cpu.esp -= 4;
    sub_47ced0(app, cpu);
    if (cpu.terminate) return;
    // 0047ce99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ce9b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047ce9d  e8e2ab0100             -call 0x497a84
    cpu.esp -= 4;
    sub_497a84(app, cpu);
    if (cpu.terminate) return;
    // 0047cea2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047cea4  e87f1e0100             -call 0x48ed28
    cpu.esp -= 4;
    sub_48ed28(app, cpu);
    if (cpu.terminate) return;
    // 0047cea9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ceab  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047ceae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cec0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cec1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047cec6  e811000000             -call 0x47cedc
    cpu.esp -= 4;
    sub_47cedc(app, cpu);
    if (cpu.terminate) return;
    // 0047cecb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cecc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ced0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ced0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ced1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ced3  e804000000             -call 0x47cedc
    cpu.esp -= 4;
    sub_47cedc(app, cpu);
    if (cpu.terminate) return;
    // 0047ced8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ced9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47cedc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cedc  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047cedf  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047cee2  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047cee6  8b153ca44c00           -mov edx, dword ptr [0x4ca43c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 0047ceec  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047ceee  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047cef2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047cef4  e823000000             -call 0x47cf1c
    cpu.esp -= 4;
    sub_47cf1c(app, cpu);
    if (cpu.terminate) return;
    // 0047cef9  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047cefc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cf00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cf01  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cf06  e811000000             -call 0x47cf1c
    cpu.esp -= 4;
    sub_47cf1c(app, cpu);
    if (cpu.terminate) return;
    // 0047cf0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cf10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cf11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cf13  e804000000             -call 0x47cf1c
    cpu.esp -= 4;
    sub_47cf1c(app, cpu);
    if (cpu.terminate) return;
    // 0047cf18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47cf1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cf1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cf1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cf1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cf20  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cf23  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047cf25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cf27  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cf2b  e804dcffff             -call 0x47ab34
    cpu.esp -= 4;
    sub_47ab34(app, cpu);
    if (cpu.terminate) return;
    // 0047cf30  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047cf32  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cf34  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047cf38  e823d3ffff             -call 0x47a260
    cpu.esp -= 4;
    sub_47a260(app, cpu);
    if (cpu.terminate) return;
    // 0047cf3d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047cf3f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047cf41  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047cf43  e89c010000             -call 0x47d0e4
    cpu.esp -= 4;
    sub_47d0e4(app, cpu);
    if (cpu.terminate) return;
    // 0047cf48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cf4a  7508                   -jne 0x47cf54
    if (!cpu.flags.zf)
    {
        goto L_0x0047cf54;
    }
    // 0047cf4c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cf4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cf54:
    // 0047cf54  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047cf57  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047cf59  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047cf5b  e820030000             -call 0x47d280
    cpu.esp -= 4;
    sub_47d280(app, cpu);
    if (cpu.terminate) return;
    // 0047cf60  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cf62  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047cf65  e806030000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0047cf6a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cf6c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cf6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf80  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047cf82  e989c4fcff             -jmp 0x449410
    return sub_449410(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47cf88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cf89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cf8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cf8b  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047cf8e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047cf92  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047cf94  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047cf96  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047cf98  ba05030000             -mov edx, 0x305
    cpu.edx = 773 /*0x305*/;
    // 0047cf9d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cf9f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047cfa3  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047cfa7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047cfa9  7504                   -jne 0x47cfaf
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfaf;
    }
    // 0047cfab  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047cfaf:
    // 0047cfaf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047cfb1  7502                   -jne 0x47cfb5
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfb5;
    }
    // 0047cfb3  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x0047cfb5:
    // 0047cfb5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047cfb9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cfbd  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047cfbf  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047cfc5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cfc7  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047cfce  e84dbdfcff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 0047cfd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cfd5  0f85b1000000           -jne 0x47d08c
    if (!cpu.flags.zf)
    {
        goto L_0x0047d08c;
    }
    // 0047cfdb  833d70aa4c0000         +cmp dword ptr [0x4caa70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024368) /* 0x4caa70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cfe2  7409                   -je 0x47cfed
    if (cpu.flags.zf)
    {
        goto L_0x0047cfed;
    }
    // 0047cfe4  803deca94c0000         +cmp byte ptr [0x4ca9ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024236) /* 0x4ca9ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cfeb  750d                   -jne 0x47cffa
    if (!cpu.flags.zf)
    {
        goto L_0x0047cffa;
    }
L_0x0047cfed:
    // 0047cfed  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047cff1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047cff4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cff5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cff6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cff7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047cffa:
    // 0047cffa  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047cffe  b8eca94c00             -mov eax, 0x4ca9ec
    cpu.eax = 5024236 /*0x4ca9ec*/;
    // 0047d003  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047d005  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d007  e814bdfcff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 0047d00c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d00e  74dd                   -je 0x47cfed
    if (cpu.flags.zf)
    {
        goto L_0x0047cfed;
    }
    // 0047d010  8b1d78aa4c00           -mov ebx, dword ptr [0x4caa78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5024376) /* 0x4caa78 */);
    // 0047d016  8b156caa4c00           -mov edx, dword ptr [0x4caa6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024364) /* 0x4caa6c */);
    // 0047d01c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d01e  e80db8fcff             -call 0x448830
    cpu.esp -= 4;
    sub_448830(app, cpu);
    if (cpu.terminate) return;
    // 0047d023  a378aa4c00             -mov dword ptr [0x4caa78], eax
    app->getMemory<x86::reg32>(x86::reg32(5024376) /* 0x4caa78 */) = cpu.eax;
    // 0047d028  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d02a  751e                   -jne 0x47d04a
    if (!cpu.flags.zf)
    {
        goto L_0x0047d04a;
    }
L_0x0047d02c:
    // 0047d02c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d030  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d032  75b9                   -jne 0x47cfed
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfed;
    }
    // 0047d034  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d036  e805b3fcff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 0047d03b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047d03d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d041  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d044  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d045  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d047  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d04a:
    // 0047d04a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d04e  a16caa4c00             -mov eax, dword ptr [0x4caa6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024364) /* 0x4caa6c */);
    // 0047d053  ff1570aa4c00           -call dword ptr [0x4caa70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024368) /* 0x4caa70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d059  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047d05c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d05e  74cc                   -je 0x47d02c
    if (cpu.flags.zf)
    {
        goto L_0x0047d02c;
    }
    // 0047d060  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d062  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d064  e8b7b4fcff             -call 0x448520
    cpu.esp -= 4;
    sub_448520(app, cpu);
    if (cpu.terminate) return;
    // 0047d069  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d06b  74bf                   -je 0x47d02c
    if (cpu.flags.zf)
    {
        goto L_0x0047d02c;
    }
    // 0047d06d  a174aa4c00             -mov eax, dword ptr [0x4caa74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024372) /* 0x4caa74 */);
    // 0047d072  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047d077  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047d079  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047d07d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047d07f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d083  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d086  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d087  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d088  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d089  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d08c:
    // 0047d08c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047d091  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d093  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047d095  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d097  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d099  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047d09d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d09f  e83cbbfcff             -call 0x448be0
    cpu.esp -= 4;
    sub_448be0(app, cpu);
    if (cpu.terminate) return;
    // 0047d0a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0a6  0f8541ffffff           -jne 0x47cfed
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfed;
    }
    // 0047d0ac  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d0ae  e88db2fcff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 0047d0b3  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0047d0b9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047d0bb  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047d0c1  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0047d0c5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d0c9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d0cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0cf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d0d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d0d4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d0d6  e8adfeffff             -call 0x47cf88
    cpu.esp -= 4;
    sub_47cf88(app, cpu);
    if (cpu.terminate) return;
    // 0047d0db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d0dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d0dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d0de  e8a5feffff             -call 0x47cf88
    cpu.esp -= 4;
    sub_47cf88(app, cpu);
    if (cpu.terminate) return;
    // 0047d0e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d0e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d0e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d0e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d0e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d0e7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d0ea  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047d0ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047d0ee  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047d0f0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d0f2  7504                   -jne 0x47d0f8
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0f8;
    }
    // 0047d0f4  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047d0f8:
    // 0047d0f8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047d0fa  7502                   -jne 0x47d0fe
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0fe;
    }
    // 0047d0fc  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x0047d0fe:
    // 0047d0fe  ba32030000             -mov edx, 0x332
    cpu.edx = 818 /*0x332*/;
    // 0047d103  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047d105  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d107  e814bcfcff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 0047d10c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d10e  751a                   -jne 0x47d12a
    if (!cpu.flags.zf)
    {
        goto L_0x0047d12a;
    }
    // 0047d110  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047d112  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047d116  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0047d118:
    // 0047d118  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d11c  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047d123  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d126  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d127  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d128  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d129  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d12a:
    // 0047d12a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047d12f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d131  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047d133  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047d135  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d137  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047d13b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d13d  e89ebafcff             -call 0x448be0
    cpu.esp -= 4;
    sub_448be0(app, cpu);
    if (cpu.terminate) return;
    // 0047d142  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d144  75d2                   -jne 0x47d118
    if (!cpu.flags.zf)
    {
        goto L_0x0047d118;
    }
    // 0047d146  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047d148  e8f3b1fcff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 0047d14d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d14f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047d155  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047d159  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0047d15f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d163  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047d16a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d16d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d16e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d16f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d170  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d174(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d174  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d175  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d176  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d177  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d17a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047d17e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047d180  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047d182  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047d184  ba05080000             -mov edx, 0x805
    cpu.edx = 2053 /*0x805*/;
    // 0047d189  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d18b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047d18f  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047d193  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d195  7504                   -jne 0x47d19b
    if (!cpu.flags.zf)
    {
        goto L_0x0047d19b;
    }
    // 0047d197  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047d19b:
    // 0047d19b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047d19d  7502                   -jne 0x47d1a1
    if (!cpu.flags.zf)
    {
        goto L_0x0047d1a1;
    }
    // 0047d19f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x0047d1a1:
    // 0047d1a1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d1a5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d1a9  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047d1ab  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047d1b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d1b3  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0047d1ba  e861bbfcff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 0047d1bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1c1  751f                   -jne 0x47d1e2
    if (!cpu.flags.zf)
    {
        goto L_0x0047d1e2;
    }
    // 0047d1c3  833d70aa4c0000         +cmp dword ptr [0x4caa70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024368) /* 0x4caa70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d1ca  7409                   -je 0x47d1d5
    if (cpu.flags.zf)
    {
        goto L_0x0047d1d5;
    }
    // 0047d1cc  803deca94c0000         +cmp byte ptr [0x4ca9ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024236) /* 0x4ca9ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d1d3  7542                   -jne 0x47d217
    if (!cpu.flags.zf)
    {
        goto L_0x0047d217;
    }
L_0x0047d1d5:
    // 0047d1d5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d1d9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d1dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1df  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d1e2:
    // 0047d1e2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d1e4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047d1e6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d1e8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d1ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d1ec  e8efb9fcff             -call 0x448be0
    cpu.esp -= 4;
    sub_448be0(app, cpu);
    if (cpu.terminate) return;
    // 0047d1f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d1f3  740d                   -je 0x47d202
    if (cpu.flags.zf)
    {
        goto L_0x0047d202;
    }
    // 0047d1f5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d1f7  e884b0fcff             -call 0x448280
    cpu.esp -= 4;
    sub_448280(app, cpu);
    if (cpu.terminate) return;
    // 0047d1fc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047d200  ebd3                   -jmp 0x47d1d5
    goto L_0x0047d1d5;
L_0x0047d202:
    // 0047d202  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d204  e837b1fcff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 0047d209  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0047d20f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 0047d215  ebbe                   -jmp 0x47d1d5
    goto L_0x0047d1d5;
L_0x0047d217:
    // 0047d217  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d21b  b8eca94c00             -mov eax, 0x4ca9ec
    cpu.eax = 5024236 /*0x4ca9ec*/;
    // 0047d220  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047d222  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d224  e8f7bafcff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 0047d229  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d22b  74a8                   -je 0x47d1d5
    if (cpu.flags.zf)
    {
        goto L_0x0047d1d5;
    }
    // 0047d22d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d22f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d233  e848b0fcff             -call 0x448280
    cpu.esp -= 4;
    sub_448280(app, cpu);
    if (cpu.terminate) return;
    // 0047d238  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d23a  ff1570aa4c00           -call dword ptr [0x4caa70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024368) /* 0x4caa70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d240  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047d243  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047d245  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047d249  a174aa4c00             -mov eax, dword ptr [0x4caa74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024372) /* 0x4caa74 */);
    // 0047d24e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047d250  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047d252  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d256  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d259  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d25a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d25b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d25c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d260  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d262  e80dffffff             -call 0x47d174
    cpu.esp -= 4;
    sub_47d174(app, cpu);
    if (cpu.terminate) return;
    // 0047d267  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d268(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d268  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d26a  e805ffffff             -call 0x47d174
    cpu.esp -= 4;
    sub_47d174(app, cpu);
    if (cpu.terminate) return;
    // 0047d26f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d270  e9cbb0fcff             -jmp 0x448340
    return sub_448340(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d278(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d278  e9b3b5fcff             -jmp 0x448830
    return sub_448830(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d280  e97bb3fcff             -jmp 0x448600
    return sub_448600(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d288  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d289  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d28b  e890b2fcff             -call 0x448520
    cpu.esp -= 4;
    sub_448520(app, cpu);
    if (cpu.terminate) return;
    // 0047d290  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d292  7502                   -jne 0x47d296
    if (!cpu.flags.zf)
    {
        goto L_0x0047d296;
    }
    // 0047d294  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d295  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d296:
    // 0047d296  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d298  e8d3b1fcff             -call 0x448470
    cpu.esp -= 4;
    sub_448470(app, cpu);
    if (cpu.terminate) return;
    // 0047d29d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d29e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d29f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d29f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d2a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d2a1  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047d2a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d2a6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d2a8  e8a5d30100             -call 0x49a652
    cpu.esp -= 4;
    sub_49a652(app, cpu);
    if (cpu.terminate) return;
    // 0047d2ad  3df4010000             +cmp eax, 0x1f4
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
    // 0047d2b2  7c03                   -jl 0x47d2b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d2b7;
    }
    // 0047d2b4  ff0424                 -inc dword ptr [esp]
    (app->getMemory<x86::reg32>(cpu.esp))++;
L_0x0047d2b7:
    // 0047d2b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d2b9  e8fbd30100             -call 0x49a6b9
    cpu.esp -= 4;
    sub_49a6b9(app, cpu);
    if (cpu.terminate) return;
    // 0047d2be  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d2c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047d2c2  7402                   -je 0x47d2c6
    if (cpu.flags.zf)
    {
        goto L_0x0047d2c6;
    }
    // 0047d2c4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0047d2c6:
    // 0047d2c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d2c8  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047d2cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d2ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d2ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d2cf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d2d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d2d1  2eff1570744b00         -call dword ptr cs:[0x4b7470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945008) /* 0x4b7470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d2d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d2da  7508                   -jne 0x47d2e4
    if (!cpu.flags.zf)
    {
        goto L_0x0047d2e4;
    }
    // 0047d2dc  e821cd0100             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 0047d2e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d2e4:
    // 0047d2e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d2e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d2f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d2f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d2f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d2f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d2f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d2f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d2f6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d2f9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d2fb  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047d2fd  891594aa4c00           -mov dword ptr [0x4caa94], edx
    app->getMemory<x86::reg32>(x86::reg32(5024404) /* 0x4caa94 */) = cpu.edx;
    // 0047d303  891590aa4c00           -mov dword ptr [0x4caa90], edx
    app->getMemory<x86::reg32>(x86::reg32(5024400) /* 0x4caa90 */) = cpu.edx;
    // 0047d309  89158caa4c00           -mov dword ptr [0x4caa8c], edx
    app->getMemory<x86::reg32>(x86::reg32(5024396) /* 0x4caa8c */) = cpu.edx;
    // 0047d30f  891514a44c00           -mov dword ptr [0x4ca414], edx
    app->getMemory<x86::reg32>(x86::reg32(5022740) /* 0x4ca414 */) = cpu.edx;
    // 0047d315  891510a44c00           -mov dword ptr [0x4ca410], edx
    app->getMemory<x86::reg32>(x86::reg32(5022736) /* 0x4ca410 */) = cpu.edx;
    // 0047d31b  89150ca44c00           -mov dword ptr [0x4ca40c], edx
    app->getMemory<x86::reg32>(x86::reg32(5022732) /* 0x4ca40c */) = cpu.edx;
    // 0047d321  891508a44c00           -mov dword ptr [0x4ca408], edx
    app->getMemory<x86::reg32>(x86::reg32(5022728) /* 0x4ca408 */) = cpu.edx;
    // 0047d327  891504a44c00           -mov dword ptr [0x4ca404], edx
    app->getMemory<x86::reg32>(x86::reg32(5022724) /* 0x4ca404 */) = cpu.edx;
    // 0047d32d  891500a44c00           -mov dword ptr [0x4ca400], edx
    app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */) = cpu.edx;
    // 0047d333  8915fca34c00           -mov dword ptr [0x4ca3fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5022716) /* 0x4ca3fc */) = cpu.edx;
    // 0047d339  8915f8a34c00           -mov dword ptr [0x4ca3f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5022712) /* 0x4ca3f8 */) = cpu.edx;
    // 0047d33f  88257caa4c00           -mov byte ptr [0x4caa7c], ah
    app->getMemory<x86::reg8>(x86::reg32(5024380) /* 0x4caa7c */) = cpu.ah;
    // 0047d345  e8fed40100             -call 0x49a848
    cpu.esp -= 4;
    sub_49a848(app, cpu);
    if (cpu.terminate) return;
    // 0047d34a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d34c  0f8461010000           -je 0x47d4b3
    if (cpu.flags.zf)
    {
        goto L_0x0047d4b3;
    }
    // 0047d352  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d354  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0047d359  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d35d  bf7caa4c00             -mov edi, 0x4caa7c
    cpu.edi = 5024380 /*0x4caa7c*/;
    // 0047d362  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047d366  e8fad40100             -call 0x49a865
    cpu.esp -= 4;
    sub_49a865(app, cpu);
    if (cpu.terminate) return;
    // 0047d36b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0047d36d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d370  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d371  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d373  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047d376  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d378  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047d37a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047d37d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047d37f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d380  881d88aa4c00           -mov byte ptr [0x4caa88], bl
    app->getMemory<x86::reg8>(x86::reg32(5024392) /* 0x4caa88 */) = cpu.bl;
    // 0047d386  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047d388  7f0a                   -jg 0x47d394
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d394;
    }
    // 0047d38a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d38d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d38e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d38f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d390  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d391  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d392  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d393  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d394:
    // 0047d394  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047d399  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d39b  e8c5d40100             -call 0x49a865
    cpu.esp -= 4;
    sub_49a865(app, cpu);
    if (cpu.terminate) return;
    // 0047d3a0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d3a3  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047d3a8  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0047d3ab  a38caa4c00             -mov dword ptr [0x4caa8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5024396) /* 0x4caa8c */) = cpu.eax;
    // 0047d3b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d3b3  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 0047d3b8  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047d3bb  a390aa4c00             -mov dword ptr [0x4caa90], eax
    app->getMemory<x86::reg32>(x86::reg32(5024400) /* 0x4caa90 */) = cpu.eax;
    // 0047d3c0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d3c3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047d3c6  8b2d8caa4c00           -mov ebp, dword ptr [0x4caa8c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5024396) /* 0x4caa8c */);
    // 0047d3cc  a394aa4c00             -mov dword ptr [0x4caa94], eax
    app->getMemory<x86::reg32>(x86::reg32(5024404) /* 0x4caa94 */) = cpu.eax;
    // 0047d3d1  83fd05                 +cmp ebp, 5
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
    // 0047d3d4  7c0a                   -jl 0x47d3e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d3e0;
    }
    // 0047d3d6  c705f8a34c0001000000   -mov dword ptr [0x4ca3f8], 1
    app->getMemory<x86::reg32>(x86::reg32(5022712) /* 0x4ca3f8 */) = 1 /*0x1*/;
L_0x0047d3e0:
    // 0047d3e0  833d8caa4c0006         +cmp dword ptr [0x4caa8c], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024396) /* 0x4caa8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d3e7  7c0a                   -jl 0x47d3f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d3f3;
    }
    // 0047d3e9  c705fca34c0001000000   -mov dword ptr [0x4ca3fc], 1
    app->getMemory<x86::reg32>(x86::reg32(5022716) /* 0x4ca3fc */) = 1 /*0x1*/;
L_0x0047d3f3:
    // 0047d3f3  ba00014c00             -mov edx, 0x4c0100
    cpu.edx = 4980992 /*0x4c0100*/;
    // 0047d3f8  b87caa4c00             -mov eax, 0x4caa7c
    cpu.eax = 5024380 /*0x4caa7c*/;
    // 0047d3fd  e8aec0ffff             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 0047d402  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d404  7553                   -jne 0x47d459
    if (!cpu.flags.zf)
    {
        goto L_0x0047d459;
    }
    // 0047d406  c7050ca44c0001000000   -mov dword ptr [0x4ca40c], 1
    app->getMemory<x86::reg32>(x86::reg32(5022732) /* 0x4ca40c */) = 1 /*0x1*/;
L_0x0047d410:
    // 0047d410  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 0047d415  0f847f000000           -je 0x47d49a
    if (cpu.flags.zf)
    {
        goto L_0x0047d49a;
    }
    // 0047d41b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047d420:
    // 0047d420  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d424  a300a44c00             -mov dword ptr [0x4ca400], eax
    app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */) = cpu.eax;
    // 0047d429  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0047d42c  0f846c000000           -je 0x47d49e
    if (cpu.flags.zf)
    {
        goto L_0x0047d49e;
    }
    // 0047d432  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047d437:
    // 0047d437  8a6c2409               -mov ch, byte ptr [esp + 9]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */);
    // 0047d43b  a304a44c00             -mov dword ptr [0x4ca404], eax
    app->getMemory<x86::reg32>(x86::reg32(5022724) /* 0x4ca404 */) = cpu.eax;
    // 0047d440  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 0047d443  745d                   -je 0x47d4a2
    if (cpu.flags.zf)
    {
        goto L_0x0047d4a2;
    }
    // 0047d445  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047d44a  a308a44c00             -mov dword ptr [0x4ca408], eax
    app->getMemory<x86::reg32>(x86::reg32(5022728) /* 0x4ca408 */) = cpu.eax;
    // 0047d44f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d452  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d453  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d454  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d455  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d456  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d457  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d458  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d459:
    // 0047d459  ba10014c00             -mov edx, 0x4c0110
    cpu.edx = 4981008 /*0x4c0110*/;
    // 0047d45e  b87caa4c00             -mov eax, 0x4caa7c
    cpu.eax = 5024380 /*0x4caa7c*/;
    // 0047d463  e848c0ffff             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 0047d468  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d46a  750c                   -jne 0x47d478
    if (!cpu.flags.zf)
    {
        goto L_0x0047d478;
    }
    // 0047d46c  c70514a44c0001000000   -mov dword ptr [0x4ca414], 1
    app->getMemory<x86::reg32>(x86::reg32(5022740) /* 0x4ca414 */) = 1 /*0x1*/;
    // 0047d476  eb98                   -jmp 0x47d410
    goto L_0x0047d410;
L_0x0047d478:
    // 0047d478  ba20014c00             -mov edx, 0x4c0120
    cpu.edx = 4981024 /*0x4c0120*/;
    // 0047d47d  b87caa4c00             -mov eax, 0x4caa7c
    cpu.eax = 5024380 /*0x4caa7c*/;
    // 0047d482  e829c0ffff             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 0047d487  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d489  7585                   -jne 0x47d410
    if (!cpu.flags.zf)
    {
        goto L_0x0047d410;
    }
    // 0047d48b  c70510a44c0001000000   -mov dword ptr [0x4ca410], 1
    app->getMemory<x86::reg32>(x86::reg32(5022736) /* 0x4ca410 */) = 1 /*0x1*/;
    // 0047d495  e976ffffff             -jmp 0x47d410
    goto L_0x0047d410;
L_0x0047d49a:
    // 0047d49a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047d49c  eb82                   -jmp 0x47d420
    goto L_0x0047d420;
L_0x0047d49e:
    // 0047d49e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047d4a0  eb95                   -jmp 0x47d437
    goto L_0x0047d437;
L_0x0047d4a2:
    // 0047d4a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d4a4  a308a44c00             -mov dword ptr [0x4ca408], eax
    app->getMemory<x86::reg32>(x86::reg32(5022728) /* 0x4ca408 */) = cpu.eax;
    // 0047d4a9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d4ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d4b3:
    // 0047d4b3  e8c9d30100             -call 0x49a881
    cpu.esp -= 4;
    sub_49a881(app, cpu);
    if (cpu.terminate) return;
    // 0047d4b8  a310a44c00             -mov dword ptr [0x4ca410], eax
    app->getMemory<x86::reg32>(x86::reg32(5022736) /* 0x4ca410 */) = cpu.eax;
    // 0047d4bd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d4c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d4d0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d4d3  29d0                   +sub eax, edx
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
    // 0047d4d5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047d4d9  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047d4dd  d84c2414               +fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0047d4e1  d9542408               +fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 0047d4e5  dd1c24                 +fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d4e8  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0047d4ea  dc1c24                 +fcomp qword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.esp)));
    cpu.fpu.pop();
    // 0047d4ed  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047d4ef  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047d4f0  770a                   -ja 0x47d4fc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047d4fc;
    }
    // 0047d4f2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0047d4f6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d4f9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d4fc:
    // 0047d4fc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0047d4ff  dc0d30014c00           -fmul qword ptr [0x4c0130]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981040) /* 0x4c0130 */));
    // 0047d505  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d509  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0047d50d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d510  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d514  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d515  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d516  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d517  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047d51a  833d04a44c0000         +cmp dword ptr [0x4ca404], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022724) /* 0x4ca404 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d521  0f8492010000           -je 0x47d6b9
    if (cpu.flags.zf)
    {
        goto L_0x0047d6b9;
    }
L_0x0047d527:
    // 0047d527  833df8a34c0000         +cmp dword ptr [0x4ca3f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022712) /* 0x4ca3f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d52e  0f848f010000           -je 0x47d6c3
    if (cpu.flags.zf)
    {
        goto L_0x0047d6c3;
    }
    // 0047d534  833d9caa4c0000         +cmp dword ptr [0x4caa9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024412) /* 0x4caa9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d53b  0f8582010000           -jne 0x47d6c3
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6c3;
    }
    // 0047d541  e88a010000             -call 0x47d6d0
    cpu.esp -= 4;
    sub_47d6d0(app, cpu);
    if (cpu.terminate) return;
L_0x0047d546:
    // 0047d546  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d548  b940420f00             -mov ecx, 0xf4240
    cpu.ecx = 1000000 /*0xf4240*/;
    // 0047d54d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d54f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d552  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d554  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047d558  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047d55c  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0047d55e  dc0538014c00           +fadd qword ptr [0x4c0138]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4981048) /* 0x4c0138 */));
    // 0047d564  dc0d40014c00           +fmul qword ptr [0x4c0140]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981056) /* 0x4c0140 */));
    // 0047d56a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d56c  e89feaffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d571  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d575  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047d579  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047d57d  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047d581  dc0d48014c00           +fmul qword ptr [0x4c0148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981064) /* 0x4c0148 */));
    // 0047d587  dd0550014c00           +fld qword ptr [0x4c0150]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4981072) /* 0x4c0150 */)));
    // 0047d58d  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047d58f  d8c1                   +fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0047d591  e87aeaffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d596  db5c2410               +fistp dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d59a  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0047d59c  dc0558014c00           +fadd qword ptr [0x4c0158]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4981080) /* 0x4c0158 */));
    // 0047d5a2  dc0d60014c00           +fmul qword ptr [0x4c0160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981088) /* 0x4c0160 */));
    // 0047d5a8  e863eaffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d5ad  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d5b1  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047d5b5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047d5b9  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047d5bd  dc0d68014c00           +fmul qword ptr [0x4c0168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981096) /* 0x4c0168 */));
    // 0047d5c3  dc0570014c00           +fadd qword ptr [0x4c0170]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4981104) /* 0x4c0170 */));
    // 0047d5c9  e842eaffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d5ce  db5c2408               +fistp dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d5d2  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047d5d4  dc0578014c00           +fadd qword ptr [0x4c0178]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4981112) /* 0x4c0178 */));
    // 0047d5da  dc0d80014c00           +fmul qword ptr [0x4c0180]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981120) /* 0x4c0180 */));
    // 0047d5e0  e82beaffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d5e5  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d5e9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047d5ed  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047d5f1  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047d5f5  dc0d88014c00           +fmul qword ptr [0x4c0188]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981128) /* 0x4c0188 */));
    // 0047d5fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d5fd  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047d5ff  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d603  e808eaffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d608  db5c240c               +fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d60c  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047d611  e8bafeffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d616  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d61a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d61e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d620  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 0047d625  e8a6feffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d62a  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d62e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d632  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d634  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 0047d639  e892feffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d63e  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d642  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 0047d647  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047d64b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d64d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d651  e87afeffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d656  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d65a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d65c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d65e  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047d663  e868feffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d668  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    cpu.fpu.pop();
    // 0047d66c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047d66e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047d66f  7604                   -jbe 0x47d675
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047d675;
    }
    // 0047d671  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047d675:
    // 0047d675  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d679  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d67b  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 0047d680  e84bfeffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d685  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d689  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d68b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d68d  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047d692  e839feffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d697  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    cpu.fpu.pop();
    // 0047d69b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047d69d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047d69e  7604                   -jbe 0x47d6a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047d6a4;
    }
    // 0047d6a0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x0047d6a4:
    // 0047d6a4  69db40420f00           -imul ebx, ebx, 0xf4240
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1000000 /*0xf4240*/)));
    // 0047d6aa  891d98aa4c00           -mov dword ptr [0x4caa98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5024408) /* 0x4caa98 */) = cpu.ebx;
    // 0047d6b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d6b2  83c418                 +add esp, 0x18
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
    // 0047d6b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d6b9:
    // 0047d6b9  e832fcffff             -call 0x47d2f0
    cpu.esp -= 4;
    sub_47d2f0(app, cpu);
    if (cpu.terminate) return;
    // 0047d6be  e964feffff             -jmp 0x47d527
    goto L_0x0047d527;
L_0x0047d6c3:
    // 0047d6c3  e888000000             -call 0x47d750
    cpu.esp -= 4;
    sub_47d750(app, cpu);
    if (cpu.terminate) return;
    // 0047d6c8  e979feffff             -jmp 0x47d546
    goto L_0x0047d546;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d6d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d6d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d6d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d6d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d6d6  bd05000000             -mov ebp, 5
    cpu.ebp = 5 /*0x5*/;
    // 0047d6db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d6dd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d6df  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047d6e1:
    // 0047d6e1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047d6e6  e8d5b7ffff             -call 0x478ec0
    cpu.esp -= 4;
    sub_478ec0(app, cpu);
    if (cpu.terminate) return;
    // 0047d6eb  833d04a44c0000         +cmp dword ptr [0x4ca404], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022724) /* 0x4ca404 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d6f2  7402                   -je 0x47d6f6
    if (cpu.flags.zf)
    {
        goto L_0x0047d6f6;
    }
    // 0047d6f4  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x0047d6f6:
    // 0047d6f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047d6f8  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0047d6fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d6ff  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d702  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d704  e8b7b7ffff             -call 0x478ec0
    cpu.esp -= 4;
    sub_478ec0(app, cpu);
    if (cpu.terminate) return;
    // 0047d709  833d04a44c0000         +cmp dword ptr [0x4ca404], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022724) /* 0x4ca404 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d710  7402                   -je 0x47d714
    if (cpu.flags.zf)
    {
        goto L_0x0047d714;
    }
    // 0047d712  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x0047d714:
    // 0047d714  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d716  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047d718  7408                   -je 0x47d722
    if (cpu.flags.zf)
    {
        goto L_0x0047d722;
    }
    // 0047d71a  39d8                   +cmp eax, ebx
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
    // 0047d71c  7d20                   -jge 0x47d73e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d73e;
    }
L_0x0047d71e:
    // 0047d71e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047d720  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0047d722:
    // 0047d722  46                     -inc esi
    (cpu.esi)++;
    // 0047d723  83fe05                 +cmp esi, 5
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
    // 0047d726  7cb9                   -jl 0x47d6e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d6e1;
    }
    // 0047d728  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d72a  7502                   -jne 0x47d72e
    if (!cpu.flags.zf)
    {
        goto L_0x0047d72e;
    }
    // 0047d72c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x0047d72e:
    // 0047d72e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047d735  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d737  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d738  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d739  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d73a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d73b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d73c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d73d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d73e:
    // 0047d73e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d740  74dc                   -je 0x47d71e
    if (cpu.flags.zf)
    {
        goto L_0x0047d71e;
    }
    // 0047d742  39c8                   +cmp eax, ecx
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
    // 0047d744  7d04                   -jge 0x47d74a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d74a;
    }
L_0x0047d746:
    // 0047d746  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d748  ebd8                   -jmp 0x47d722
    goto L_0x0047d722;
L_0x0047d74a:
    // 0047d74a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d74c  74f8                   -je 0x47d746
    if (cpu.flags.zf)
    {
        goto L_0x0047d746;
    }
    // 0047d74e  ebd2                   -jmp 0x47d722
    goto L_0x0047d722;
}

/* align: skip  */
void Application::sub_47d750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d756  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d759  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d75b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d75d  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047d761  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0047d765:
    // 0047d765  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047d76a  e851b7ffff             -call 0x478ec0
    cpu.esp -= 4;
    sub_478ec0(app, cpu);
    if (cpu.terminate) return;
    // 0047d76f  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0047d774  8b3d20a44c00           -mov edi, dword ptr [0x4ca420]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0047d77a  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0047d77d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d77f  8b3564d25100           -mov esi, dword ptr [0x51d264]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
L_0x0047d785:
    // 0047d785  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d787  b8aaaa5555             -mov eax, 0x5555aaaa
    cpu.eax = 1431677610 /*0x5555aaaa*/;
    // 0047d78c  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 0047d791  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d793  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0047d798  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047d79a  41                     -inc ecx
    (cpu.ecx)++;
    // 0047d79b  39f8                   +cmp eax, edi
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
    // 0047d79d  7ce6                   -jl 0x47d785
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d785;
    }
    // 0047d79f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d7a3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047d7a5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d7a7  7414                   -je 0x47d7bd
    if (cpu.flags.zf)
    {
        goto L_0x0047d7bd;
    }
    // 0047d7a9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d7ad  39f1                   +cmp ecx, esi
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
    // 0047d7af  0f8d7c000000           -jge 0x47d831
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d831;
    }
L_0x0047d7b5:
    // 0047d7b5  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d7b9  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x0047d7bd:
    // 0047d7bd  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d7c1  42                     -inc edx
    (cpu.edx)++;
    // 0047d7c2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047d7c6  83fa05                 +cmp edx, 5
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
    // 0047d7c9  7c9a                   -jl 0x47d765
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d765;
    }
    // 0047d7cb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047d7cd  7504                   -jne 0x47d7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0047d7d3;
    }
    // 0047d7cf  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0047d7d3:
    // 0047d7d3  8b1dfca34c00           -mov ebx, dword ptr [0x4ca3fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022716) /* 0x4ca3fc */);
    // 0047d7d9  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047d7dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d7de  7566                   -jne 0x47d846
    if (!cpu.flags.zf)
    {
        goto L_0x0047d846;
    }
    // 0047d7e0  833df8a34c0000         +cmp dword ptr [0x4ca3f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022712) /* 0x4ca3f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d7e7  0f856f000000           -jne 0x47d85c
    if (!cpu.flags.zf)
    {
        goto L_0x0047d85c;
    }
    // 0047d7ed  833d10a44c0000         +cmp dword ptr [0x4ca410], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022736) /* 0x4ca410 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d7f4  0f8478000000           -je 0x47d872
    if (cpu.flags.zf)
    {
        goto L_0x0047d872;
    }
    // 0047d7fa  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047d7fe  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047d802  dc0de0014c00           -fmul qword ptr [0x4c01e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981216) /* 0x4c01e0 */));
    // 0047d808  dc0de8014c00           -fmul qword ptr [0x4c01e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981224) /* 0x4c01e8 */));
L_0x0047d80e:
    // 0047d80e  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047d811  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0047d814  d80d10024c00           -fmul dword ptr [0x4c0210]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4981264) /* 0x4c0210 */));
    // 0047d81a  e8f1e7ffff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0047d81f  db5c240c               -fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047d823  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d827  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d82a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d830  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d831:
    // 0047d831  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047d833  7480                   -je 0x47d7b5
    if (cpu.flags.zf)
    {
        goto L_0x0047d7b5;
    }
    // 0047d835  39e9                   +cmp ecx, ebp
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
    // 0047d837  7d04                   -jge 0x47d83d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d83d;
    }
L_0x0047d839:
    // 0047d839  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0047d83b  eb80                   -jmp 0x47d7bd
    goto L_0x0047d7bd;
L_0x0047d83d:
    // 0047d83d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047d83f  74f8                   -je 0x47d839
    if (cpu.flags.zf)
    {
        goto L_0x0047d839;
    }
    // 0047d841  e977ffffff             -jmp 0x47d7bd
    goto L_0x0047d7bd;
L_0x0047d846:
    // 0047d846  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047d84a  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047d84e  dc0d00024c00           +fmul qword ptr [0x4c0200]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981248) /* 0x4c0200 */));
    // 0047d854  dc0d08024c00           +fmul qword ptr [0x4c0208]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981256) /* 0x4c0208 */));
    // 0047d85a  ebb2                   -jmp 0x47d80e
    goto L_0x0047d80e;
L_0x0047d85c:
    // 0047d85c  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047d860  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047d864  dc0df0014c00           +fmul qword ptr [0x4c01f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981232) /* 0x4c01f0 */));
    // 0047d86a  dc0df8014c00           +fmul qword ptr [0x4c01f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981240) /* 0x4c01f8 */));
    // 0047d870  eb9c                   -jmp 0x47d80e
    goto L_0x0047d80e;
L_0x0047d872:
    // 0047d872  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047d876  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047d87a  dc0dd0014c00           +fmul qword ptr [0x4c01d0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981200) /* 0x4c01d0 */));
    // 0047d880  dc0dd8014c00           +fmul qword ptr [0x4c01d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4981208) /* 0x4c01d8 */));
    // 0047d886  eb86                   -jmp 0x47d80e
    goto L_0x0047d80e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d892  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d893  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d894  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0047d89a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047d89c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047d89e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d8a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047d8a1:
    // 0047d8a1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d8a3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047d8a5  3c00                   +cmp al, 0
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
    // 0047d8a7  7410                   -je 0x47d8b9
    if (cpu.flags.zf)
    {
        goto L_0x0047d8b9;
    }
    // 0047d8a9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047d8ac  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d8af  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047d8b2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d8b5  3c00                   +cmp al, 0
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
    // 0047d8b7  75e8                   -jne 0x47d8a1
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8a1;
    }
L_0x0047d8b9:
    // 0047d8b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8ba  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047d8bc  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d8be  49                     -dec ecx
    (cpu.ecx)--;
    // 0047d8bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047d8c1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047d8c3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047d8c5  49                     -dec ecx
    (cpu.ecx)--;
    // 0047d8c6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d8c8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d8ca  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047d8cc  48                     -dec eax
    (cpu.eax)--;
    // 0047d8cd  39d0                   +cmp eax, edx
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
    // 0047d8cf  7607                   -jbe 0x47d8d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047d8d8;
    }
L_0x0047d8d1:
    // 0047d8d1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047d8d3  80fa2e                 +cmp dl, 0x2e
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
    // 0047d8d6  7545                   -jne 0x47d91d
    if (!cpu.flags.zf)
    {
        goto L_0x0047d91d;
    }
L_0x0047d8d8:
    // 0047d8d8  80382e                 +cmp byte ptr [eax], 0x2e
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
    // 0047d8db  742a                   -je 0x47d907
    if (cpu.flags.zf)
    {
        goto L_0x0047d907;
    }
    // 0047d8dd  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047d8df  8b35a0aa4c00           -mov esi, dword ptr [0x4caaa0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5024416) /* 0x4caaa0 */);
    // 0047d8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d8e6  2bc9                   +sub ecx, ecx
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
    // 0047d8e8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d8e9  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047d8eb  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047d8ed  4f                     -dec edi
    (cpu.edi)--;
L_0x0047d8ee:
    // 0047d8ee  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d8f0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047d8f2  3c00                   +cmp al, 0
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
    // 0047d8f4  7410                   -je 0x47d906
    if (cpu.flags.zf)
    {
        goto L_0x0047d906;
    }
    // 0047d8f6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047d8f9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d8fc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047d8ff  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d902  3c00                   +cmp al, 0
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
    // 0047d904  75e8                   -jne 0x47d8ee
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8ee;
    }
L_0x0047d906:
    // 0047d906  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d907:
    // 0047d907  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d909  e866a70100             -call 0x498074
    cpu.esp -= 4;
    sub_498074(app, cpu);
    if (cpu.terminate) return;
    // 0047d90e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d910  7423                   -je 0x47d935
    if (cpu.flags.zf)
    {
        goto L_0x0047d935;
    }
    // 0047d912  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0047d918  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d919  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d91a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d91b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d91c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d91d:
    // 0047d91d  80fa3a                 +cmp dl, 0x3a
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
    // 0047d920  74b6                   -je 0x47d8d8
    if (cpu.flags.zf)
    {
        goto L_0x0047d8d8;
    }
    // 0047d922  80fa2f                 +cmp dl, 0x2f
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
    // 0047d925  74b1                   -je 0x47d8d8
    if (cpu.flags.zf)
    {
        goto L_0x0047d8d8;
    }
    // 0047d927  80fa5c                 +cmp dl, 0x5c
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
    // 0047d92a  74ac                   -je 0x47d8d8
    if (cpu.flags.zf)
    {
        goto L_0x0047d8d8;
    }
    // 0047d92c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047d92e  48                     -dec eax
    (cpu.eax)--;
    // 0047d92f  39d0                   +cmp eax, edx
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
    // 0047d931  779e                   -ja 0x47d8d1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047d8d1;
    }
    // 0047d933  eba3                   -jmp 0x47d8d8
    goto L_0x0047d8d8;
L_0x0047d935:
    // 0047d935  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d937  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047d939  e85a090100             -call 0x48e298
    cpu.esp -= 4;
    sub_48e298(app, cpu);
    if (cpu.terminate) return;
    // 0047d93e  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0047d944  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d945  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d946  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d947  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d948  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d94c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d94c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d94d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d94f  e83cffffff             -call 0x47d890
    cpu.esp -= 4;
    sub_47d890(app, cpu);
    if (cpu.terminate) return;
    // 0047d954  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d955  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d958  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d959  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047d95e  e82dffffff             -call 0x47d890
    cpu.esp -= 4;
    sub_47d890(app, cpu);
    if (cpu.terminate) return;
    // 0047d963  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d964  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d968(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d968  e823ffffff             -call 0x47d890
    cpu.esp -= 4;
    sub_47d890(app, cpu);
    if (cpu.terminate) return;
    // 0047d96d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d96f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d971  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047d973  7402                   -je 0x47d977
    if (cpu.flags.zf)
    {
        goto L_0x0047d977;
    }
    // 0047d975  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x0047d977:
    // 0047d977  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d978  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d979  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d97b  e8e8ffffff             -call 0x47d968
    cpu.esp -= 4;
    sub_47d968(app, cpu);
    if (cpu.terminate) return;
    // 0047d980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d981  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d984  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d985  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047d98a  e8d9ffffff             -call 0x47d968
    cpu.esp -= 4;
    sub_47d968(app, cpu);
    if (cpu.terminate) return;
    // 0047d98f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d990  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d9a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d9a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d9a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d9a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d9a6  83fb3a                 +cmp ebx, 0x3a
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
    // 0047d9a9  0f8486000000           -je 0x47da35
    if (cpu.flags.zf)
    {
        goto L_0x0047da35;
    }
    // 0047d9af  803da8a74c0000         +cmp byte ptr [0x4ca7a8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023656) /* 0x4ca7a8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d9b6  7426                   -je 0x47d9de
    if (cpu.flags.zf)
    {
        goto L_0x0047d9de;
    }
    // 0047d9b8  b95ca94c00             -mov ecx, 0x4ca95c
    cpu.ecx = 5024092 /*0x4ca95c*/;
L_0x0047d9bd:
    // 0047d9bd  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 0047d9c0  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0047d9c2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d9c7  3d80000000             +cmp eax, 0x80
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
    // 0047d9cc  7c0d                   -jl 0x47d9db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d9db;
    }
    // 0047d9ce  3d90000000             +cmp eax, 0x90
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
    // 0047d9d3  7c03                   -jl 0x47d9d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d9d8;
    }
    // 0047d9d5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x0047d9d8:
    // 0047d9d8  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
L_0x0047d9db:
    // 0047d9db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d9de:
    // 0047d9de  803d8da74c0000         +cmp byte ptr [0x4ca78d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023629) /* 0x4ca78d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d9e5  741e                   -je 0x47da05
    if (cpu.flags.zf)
    {
        goto L_0x0047da05;
    }
    // 0047d9e7  833d68a74c0000         +cmp dword ptr [0x4ca768], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023592) /* 0x4ca768 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d9ee  7405                   -je 0x47d9f5
    if (cpu.flags.zf)
    {
        goto L_0x0047d9f5;
    }
    // 0047d9f0  83fb01                 +cmp ebx, 1
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
    // 0047d9f3  7407                   -je 0x47d9fc
    if (cpu.flags.zf)
    {
        goto L_0x0047d9fc;
    }
L_0x0047d9f5:
    // 0047d9f5  b901a94c00             -mov ecx, 0x4ca901
    cpu.ecx = 5024001 /*0x4ca901*/;
    // 0047d9fa  ebc1                   -jmp 0x47d9bd
    goto L_0x0047d9bd;
L_0x0047d9fc:
    // 0047d9fc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047d9fe  e8a22a0100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 0047da03  ebb8                   -jmp 0x47d9bd
    goto L_0x0047d9bd;
L_0x0047da05:
    // 0047da05  803d9aa74c0000         +cmp byte ptr [0x4ca79a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023642) /* 0x4ca79a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047da0c  7407                   -je 0x47da15
    if (cpu.flags.zf)
    {
        goto L_0x0047da15;
    }
L_0x0047da0e:
    // 0047da0e  b94ba84c00             -mov ecx, 0x4ca84b
    cpu.ecx = 5023819 /*0x4ca84b*/;
    // 0047da13  eba8                   -jmp 0x47d9bd
    goto L_0x0047d9bd;
L_0x0047da15:
    // 0047da15  803da6a74c0000         +cmp byte ptr [0x4ca7a6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023654) /* 0x4ca7a6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047da1c  75f0                   -jne 0x47da0e
    if (!cpu.flags.zf)
    {
        goto L_0x0047da0e;
    }
    // 0047da1e  833d6ca74c0000         +cmp dword ptr [0x4ca76c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023596) /* 0x4ca76c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da25  7407                   -je 0x47da2e
    if (cpu.flags.zf)
    {
        goto L_0x0047da2e;
    }
    // 0047da27  b9a6a84c00             -mov ecx, 0x4ca8a6
    cpu.ecx = 5023910 /*0x4ca8a6*/;
    // 0047da2c  eb8f                   -jmp 0x47d9bd
    goto L_0x0047d9bd;
L_0x0047da2e:
    // 0047da2e  b9f0a74c00             -mov ecx, 0x4ca7f0
    cpu.ecx = 5023728 /*0x4ca7f0*/;
    // 0047da33  eb88                   -jmp 0x47d9bd
    goto L_0x0047d9bd;
L_0x0047da35:
    // 0047da35  833d6ca74c0000         +cmp dword ptr [0x4ca76c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023596) /* 0x4ca76c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da3c  750e                   -jne 0x47da4c
    if (!cpu.flags.zf)
    {
        goto L_0x0047da4c;
    }
    // 0047da3e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047da43  890d6ca74c00           -mov dword ptr [0x4ca76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023596) /* 0x4ca76c */) = cpu.ecx;
    // 0047da49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047da4c:
    // 0047da4c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047da4e  890d6ca74c00           -mov dword ptr [0x4ca76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023596) /* 0x4ca76c */) = cpu.ecx;
    // 0047da54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47da58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047da58  e883a0ffff             -call 0x477ae0
    cpu.esp -= 4;
    sub_477ae0(app, cpu);
    if (cpu.terminate) return;
    // 0047da5d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047da62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47da64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047da64  e877a0ffff             -call 0x477ae0
    cpu.esp -= 4;
    sub_477ae0(app, cpu);
    if (cpu.terminate) return;
    // 0047da69  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0047da6e  e935ce0100             -jmp 0x49a8a8
    return sub_49a8a8(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47da74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047da74  a3a4aa4c00             -mov dword ptr [0x4caaa4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024420) /* 0x4caaa4 */) = cpu.eax;
    // 0047da79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47da7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047da7c  833da4aa4c0000         +cmp dword ptr [0x4caaa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024420) /* 0x4caaa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047da83  7503                   -jne 0x47da88
    if (!cpu.flags.zf)
    {
        goto L_0x0047da88;
    }
    // 0047da85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047da87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047da88:
    // 0047da88  ff15a4aa4c00           -call dword ptr [0x4caaa4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024420) /* 0x4caaa4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047da8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47da90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x0047da90:
    // 0047da90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047da92  e8a9c1ffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0047da97  e8e0ffffff             -call 0x47da7c
    cpu.esp -= 4;
    sub_47da7c(app, cpu);
    if (cpu.terminate) return;
    // 0047da9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047da9e  74f0                   -je 0x47da90
    if (cpu.flags.zf)
    {
        goto L_0x0047da90;
    }
    // 0047daa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47daa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047daa4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047daa5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047daa6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047daa7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047daa9:
    // 0047daa9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047daab  e890c1ffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0047dab0  e8c7ffffff             -call 0x47da7c
    cpu.esp -= 4;
    sub_47da7c(app, cpu);
    if (cpu.terminate) return;
    // 0047dab5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047dab7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047dab9  e8f3b3ffff             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0047dabe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dac0  7508                   -jne 0x47daca
    if (!cpu.flags.zf)
    {
        goto L_0x0047daca;
    }
    // 0047dac2  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047dac4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dac6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dac7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dac8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dac9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047daca:
    // 0047daca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047dacc  74db                   -je 0x47daa9
    if (cpu.flags.zf)
    {
        goto L_0x0047daa9;
    }
    // 0047dace  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047dad0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dad2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dad3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dad4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dad5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47dad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dad8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dad9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dada  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047dadc  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0047dae1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047dae3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047dae5:
    // 0047dae5  e892ffffff             -call 0x47da7c
    cpu.esp -= 4;
    sub_47da7c(app, cpu);
    if (cpu.terminate) return;
    // 0047daea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047daec  7403                   -je 0x47daf1
    if (cpu.flags.zf)
    {
        goto L_0x0047daf1;
    }
    // 0047daee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047daef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047daf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047daf1:
    // 0047daf1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047daf3  e848c1ffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0047daf8  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0047dafd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047daff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047db01  7ce2                   -jl 0x47dae5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dae5;
    }
    // 0047db03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047db05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47db08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047db08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047db09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047db0a  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db11  741d                   -je 0x47db30
    if (cpu.flags.zf)
    {
        goto L_0x0047db30;
    }
L_0x0047db13:
    // 0047db13  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047db18  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 0047db1d  b870a74c00             -mov eax, 0x4ca770
    cpu.eax = 5023600 /*0x4ca770*/;
    // 0047db22  890dd8d05100           -mov dword ptr [0x51d0d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5361880) /* 0x51d0d8 */) = cpu.ecx;
    // 0047db28  e86f310000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0047db2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047db30:
    // 0047db30  e843300000             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 0047db35  a38ca34c00             -mov dword ptr [0x4ca38c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */) = cpu.eax;
    // 0047db3a  ebd7                   -jmp 0x47db13
    goto L_0x0047db13;
}

/* align: skip  */
void Application::sub_47db3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047db3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047db3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047db3f  8915d8d05100           -mov dword ptr [0x51d0d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5361880) /* 0x51d0d8 */) = cpu.edx;
    // 0047db45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47db48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x0047db48:
    // 0047db48  e8939fffff             -call 0x477ae0
    cpu.esp -= 4;
    sub_477ae0(app, cpu);
    if (cpu.terminate) return;
    // 0047db4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047db4f  75f7                   -jne 0x47db48
    if (!cpu.flags.zf)
    {
        goto L_0x0047db48;
    }
    // 0047db51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47db54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047db54  e8d79effff             -call 0x477a30
    cpu.esp -= 4;
    sub_477a30(app, cpu);
    if (cpu.terminate) return;
    // 0047db59  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047db5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47db60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047db60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047db61  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047db65  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047db69  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047db6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047db71  7505                   -jne 0x47db78
    if (!cpu.flags.zf)
    {
        goto L_0x0047db78;
    }
    // 0047db73  bb70d35100             -mov ebx, 0x51d370
    cpu.ebx = 5362544 /*0x51d370*/;
L_0x0047db78:
    // 0047db78  e81bc2ffff             -call 0x479d98
    cpu.esp -= 4;
    sub_479d98(app, cpu);
    if (cpu.terminate) return;
    // 0047db7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047db7f  743a                   -je 0x47dbbb
    if (cpu.flags.zf)
    {
        goto L_0x0047dbbb;
    }
    // 0047db81  833b00                 +cmp dword ptr [ebx], 0
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
    // 0047db84  7407                   -je 0x47db8d
    if (cpu.flags.zf)
    {
        goto L_0x0047db8d;
    }
    // 0047db86  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047db88  e857aa0000             -call 0x4885e4
    cpu.esp -= 4;
    sub_4885e4(app, cpu);
    if (cpu.terminate) return;
L_0x0047db8d:
    // 0047db8d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047db8f  e8189c0000             -call 0x4877ac
    cpu.esp -= 4;
    sub_4877ac(app, cpu);
    if (cpu.terminate) return;
    // 0047db94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047db96  7412                   -je 0x47dbaa
    if (cpu.flags.zf)
    {
        goto L_0x0047dbaa;
    }
    // 0047db98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047db9a  e8e99e0000             -call 0x487a88
    cpu.esp -= 4;
    sub_487a88(app, cpu);
    if (cpu.terminate) return;
    // 0047db9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dba1  7407                   -je 0x47dbaa
    if (cpu.flags.zf)
    {
        goto L_0x0047dbaa;
    }
    // 0047dba3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dba5  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
L_0x0047dbaa:
    // 0047dbaa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dbac  8915b8aa4c00           -mov dword ptr [0x4caab8], edx
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.edx;
    // 0047dbb2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dbb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dbb8  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047dbbb:
    // 0047dbbb  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047dbc1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047dbc3  741a                   -je 0x47dbdf
    if (cpu.flags.zf)
    {
        goto L_0x0047dbdf;
    }
    // 0047dbc5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dbc6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047dbc8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dbc9  2eff1534744b00         -call dword ptr cs:[0x4b7434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944948) /* 0x4b7434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047dbd0  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047dbd6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dbd7  2eff1524744b00         -call dword ptr cs:[0x4b7424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944932) /* 0x4b7424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047dbde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dbdf:
    // 0047dbdf  c705b8aa4c00ffffffff   -mov dword ptr [0x4caab8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = 4294967295 /*0xffffffff*/;
    // 0047dbe9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dbee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dbef  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47dbf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dbf4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dbf5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047dbf9  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047dbfd  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047dc01  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047dc07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047dc09  7505                   -jne 0x47dc10
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc10;
    }
    // 0047dc0b  b970d35100             -mov ecx, 0x51d370
    cpu.ecx = 5362544 /*0x51d370*/;
L_0x0047dc10:
    // 0047dc10  e883c1ffff             -call 0x479d98
    cpu.esp -= 4;
    sub_479d98(app, cpu);
    if (cpu.terminate) return;
    // 0047dc15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc17  7513                   -jne 0x47dc2c
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc2c;
    }
    // 0047dc19  c705b8aa4c00ffffffff   -mov dword ptr [0x4caab8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = 4294967295 /*0xffffffff*/;
    // 0047dc23  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dc28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc29  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047dc2c:
    // 0047dc2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dc2e  e865a00000             -call 0x487c98
    cpu.esp -= 4;
    sub_487c98(app, cpu);
    if (cpu.terminate) return;
    // 0047dc33  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dc35  e8b6a50000             -call 0x4881f0
    cpu.esp -= 4;
    sub_4881f0(app, cpu);
    if (cpu.terminate) return;
    // 0047dc3a  83f8ff                 +cmp eax, -1
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
    // 0047dc3d  7c54                   -jl 0x47dc93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dc93;
    }
    // 0047dc3f  7f24                   -jg 0x47dc65
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047dc65;
    }
    // 0047dc41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dc42  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0047dc47  b81c024c00             -mov eax, 0x4c021c
    cpu.eax = 4981276 /*0x4c021c*/;
    // 0047dc4c  891db8aa4c00           -mov dword ptr [0x4caab8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.ebx;
    // 0047dc52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc54  752f                   -jne 0x47dc85
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc85;
    }
L_0x0047dc56:
    // 0047dc56  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 0047dc5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc5c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dc61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc62  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047dc65:
    // 0047dc65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc67  752a                   -jne 0x47dc93
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc93;
    }
    // 0047dc69  a3b8aa4c00             -mov dword ptr [0x4caab8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.eax;
    // 0047dc6e  b828024c00             -mov eax, 0x4c0228
    cpu.eax = 4981288 /*0x4c0228*/;
    // 0047dc73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc75  7515                   -jne 0x47dc8c
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc8c;
    }
L_0x0047dc77:
    // 0047dc77  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 0047dc7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dc81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc82  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047dc85:
    // 0047dc85  b824024c00             -mov eax, 0x4c0224
    cpu.eax = 4981284 /*0x4c0224*/;
    // 0047dc8a  ebca                   -jmp 0x47dc56
    goto L_0x0047dc56;
L_0x0047dc8c:
    // 0047dc8c  b824024c00             -mov eax, 0x4c0224
    cpu.eax = 4981284 /*0x4c0224*/;
    // 0047dc91  ebe4                   -jmp 0x47dc77
    goto L_0x0047dc77;
L_0x0047dc93:
    // 0047dc93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dc95  e89aa00000             -call 0x487d34
    cpu.esp -= 4;
    sub_487d34(app, cpu);
    if (cpu.terminate) return;
    // 0047dc9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc9c  752b                   -jne 0x47dcc9
    if (!cpu.flags.zf)
    {
        goto L_0x0047dcc9;
    }
    // 0047dc9e  833dbcaa4c0000         +cmp dword ptr [0x4caabc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dca5  7529                   -jne 0x47dcd0
    if (!cpu.flags.zf)
    {
        goto L_0x0047dcd0;
    }
    // 0047dca7  b81c024c00             -mov eax, 0x4c021c
    cpu.eax = 4981276 /*0x4c021c*/;
    // 0047dcac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dcae  752e                   -jne 0x47dcde
    if (!cpu.flags.zf)
    {
        goto L_0x0047dcde;
    }
L_0x0047dcb0:
    // 0047dcb0  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0047dcb5  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 0047dcba  892db8aa4c00           -mov dword ptr [0x4caab8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.ebp;
    // 0047dcc0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dcc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dcc6  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047dcc9:
    // 0047dcc9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047dccb  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
L_0x0047dcd0:
    // 0047dcd0  a3b8aa4c00             -mov dword ptr [0x4caab8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.eax;
    // 0047dcd5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dcda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dcdb  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047dcde:
    // 0047dcde  b824024c00             -mov eax, 0x4c0224
    cpu.eax = 4981284 /*0x4c0224*/;
    // 0047dce3  ebcb                   -jmp 0x47dcb0
    goto L_0x0047dcb0;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47dce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dce8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dce9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dcea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dceb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dcec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dced  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047dcef  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047dcf1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047dcf6  b830024c00             -mov eax, 0x4c0230
    cpu.eax = 4981296 /*0x4c0230*/;
    // 0047dcfb  8915b8aa4c00           -mov dword ptr [0x4caab8], edx
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.edx;
    // 0047dd01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd03  7530                   -jne 0x47dd35
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd35;
    }
L_0x0047dd05:
    // 0047dd05  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 0047dd0a  e80da2ffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047dd0f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047dd11  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047dd13  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dd15  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047dd17  e8749fffff             -call 0x477c90
    cpu.esp -= 4;
    sub_477c90(app, cpu);
    if (cpu.terminate) return;
    // 0047dd1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd1e  740a                   -je 0x47dd2a
    if (cpu.flags.zf)
    {
        goto L_0x0047dd2a;
    }
    // 0047dd20  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047dd22:
    // 0047dd22  3b2db8aa4c00           +cmp ebp, dword ptr [0x4caab8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dd28  7512                   -jne 0x47dd3c
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd3c;
    }
L_0x0047dd2a:
    // 0047dd2a  a1bcaa4c00             -mov eax, dword ptr [0x4caabc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */);
    // 0047dd2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dd35:
    // 0047dd35  b824024c00             -mov eax, 0x4c0224
    cpu.eax = 4981284 /*0x4c0224*/;
    // 0047dd3a  ebc9                   -jmp 0x47dd05
    goto L_0x0047dd05;
L_0x0047dd3c:
    // 0047dd3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dd41  e8d62a0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047dd46  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047dd48  e81b2b0000             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 0047dd4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd4f  7407                   -je 0x47dd58
    if (cpu.flags.zf)
    {
        goto L_0x0047dd58;
    }
    // 0047dd51  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047dd53  e8e8beffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
L_0x0047dd58:
    // 0047dd58  3b2db8aa4c00           +cmp ebp, dword ptr [0x4caab8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dd5e  7ec2                   -jle 0x47dd22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dd22;
    }
    // 0047dd60  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0047dd65  e8b22a0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047dd6a  e829c0ffff             -call 0x479d98
    cpu.esp -= 4;
    sub_479d98(app, cpu);
    if (cpu.terminate) return;
    // 0047dd6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd71  74af                   -je 0x47dd22
    if (cpu.flags.zf)
    {
        goto L_0x0047dd22;
    }
    // 0047dd73  8b15c4d75100           -mov edx, dword ptr [0x51d7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047dd79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dd7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dd7f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047dd81  a3b8aa4c00             -mov dword ptr [0x4caab8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024440) /* 0x4caab8 */) = cpu.eax;
    // 0047dd86  2eff1524744b00         -call dword ptr cs:[0x4b7424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944932) /* 0x4b7424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047dd8d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047dd8f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047dd91  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047dd93  e8f89effff             -call 0x477c90
    cpu.esp -= 4;
    sub_477c90(app, cpu);
    if (cpu.terminate) return;
    // 0047dd98  eb88                   -jmp 0x47dd22
    goto L_0x0047dd22;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47dd9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dd9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dd9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dd9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dd9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dda1  e8c22a0000             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 0047dda6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dda8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ddaa  7527                   -jne 0x47ddd3
    if (!cpu.flags.zf)
    {
        goto L_0x0047ddd3;
    }
    // 0047ddac  8b1538af4c00           -mov edx, dword ptr [0x4caf38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0047ddb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ddb4  740d                   -je 0x47ddc3
    if (cpu.flags.zf)
    {
        goto L_0x0047ddc3;
    }
    // 0047ddb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ddb8  e80b2e0000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0047ddbd  8b1d38af4c00           -mov ebx, dword ptr [0x4caf38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
L_0x0047ddc3:
    // 0047ddc3  8b0dc4d75100           -mov ecx, dword ptr [0x51d7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047ddc9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ddcb  751b                   -jne 0x47dde8
    if (!cpu.flags.zf)
    {
        goto L_0x0047dde8;
    }
    // 0047ddcd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ddcf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddd2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ddd3:
    // 0047ddd3  e844a1ffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047ddd8  8b0dc4d75100           -mov ecx, dword ptr [0x51d7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047ddde  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047dde0  7506                   -jne 0x47dde8
    if (!cpu.flags.zf)
    {
        goto L_0x0047dde8;
    }
    // 0047dde2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047dde4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dde5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dde6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dde7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dde8:
    // 0047dde8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ddea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ddeb  2eff1534744b00         -call dword ptr cs:[0x4b7434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944948) /* 0x4b7434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ddf2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ddf4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ddf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ddf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ddf8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ddf9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ddfa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ddfb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ddfc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ddfd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ddfe  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047de01  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047de03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047de05  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0047de09:
    // 0047de09  80bf5d04000000         +cmp byte ptr [edi + 0x45d], 0
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
    // 0047de10  0f8413010000           -je 0x47df29
    if (cpu.flags.zf)
    {
        goto L_0x0047df29;
    }
    // 0047de16  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047de19  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047de1d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047de21  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0047de24  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0047de27  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047de2a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047de2c  0f8579000000           -jne 0x47deab
    if (!cpu.flags.zf)
    {
        goto L_0x0047deab;
    }
L_0x0047de32:
    // 0047de32  bea0860100             -mov esi, 0x186a0
    cpu.esi = 100000 /*0x186a0*/;
    // 0047de37  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047de3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047de3c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047de3e  7e37                   -jle 0x47de77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047de77;
    }
    // 0047de40  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x0047de43:
    // 0047de43  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de45  8a4812                 -mov cl, byte ptr [eax + 0x12]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0047de48  3b0c24                 +cmp ecx, dword ptr [esp]
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
    // 0047de4b  751f                   -jne 0x47de6c
    if (!cpu.flags.zf)
    {
        goto L_0x0047de6c;
    }
    // 0047de4d  f6400f80               +test byte ptr [eax + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) & 128 /*0x80*/));
    // 0047de51  7519                   -jne 0x47de6c
    if (!cpu.flags.zf)
    {
        goto L_0x0047de6c;
    }
    // 0047de53  3b18                   +cmp ebx, dword ptr [eax]
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
    // 0047de55  7715                   -ja 0x47de6c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047de6c;
    }
    // 0047de57  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047de5b  3b4804                 +cmp ecx, dword ptr [eax + 4]
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
    // 0047de5e  770c                   -ja 0x47de6c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047de6c;
    }
    // 0047de60  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047de62  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047de64  39f1                   +cmp ecx, esi
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
    // 0047de66  7304                   -jae 0x47de6c
    if (!cpu.flags.cf)
    {
        goto L_0x0047de6c;
    }
    // 0047de68  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047de6a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x0047de6c:
    // 0047de6c  42                     -inc edx
    (cpu.edx)++;
    // 0047de6d  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047de70  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047de73  39ca                   +cmp edx, ecx
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
    // 0047de75  7ccc                   -jl 0x47de43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047de43;
    }
L_0x0047de77:
    // 0047de77  3b6f08                 +cmp ebp, dword ptr [edi + 8]
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
    // 0047de7a  7d4f                   -jge 0x47decb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047decb;
    }
    // 0047de7c  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047de81  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047de83  e860feffff             -call 0x47dce8
    cpu.esp -= 4;
    sub_47dce8(app, cpu);
    if (cpu.terminate) return;
    // 0047de88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047de8a  753b                   -jne 0x47dec7
    if (!cpu.flags.zf)
    {
        goto L_0x0047dec7;
    }
    // 0047de8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047de91:
    // 0047de91  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047de95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047de97  750b                   -jne 0x47dea4
    if (!cpu.flags.zf)
    {
        goto L_0x0047dea4;
    }
    // 0047de99  6bed14                 -imul ebp, ebp, 0x14
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 0047de9c  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047de9f  804c280f80             -or byte ptr [eax + ebp + 0xf], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */ + cpu.ebp * 1) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0047dea4:
    // 0047dea4  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0047dea9  7487                   -je 0x47de32
    if (cpu.flags.zf)
    {
        goto L_0x0047de32;
    }
L_0x0047deab:
    // 0047deab  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047deaf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047deb1  7406                   -je 0x47deb9
    if (cpu.flags.zf)
    {
        goto L_0x0047deb9;
    }
    // 0047deb3  0f8450ffffff           -je 0x47de09
    if (cpu.flags.zf)
    {
        goto L_0x0047de09;
    }
L_0x0047deb9:
    // 0047deb9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047debd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047dec0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dec1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dec2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dec3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dec4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dec5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dec6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dec7:
    // 0047dec7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047dec9  ebc6                   -jmp 0x47de91
    goto L_0x0047de91;
L_0x0047decb:
    // 0047decb  81fb40010000           +cmp ebx, 0x140
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
    // 0047ded1  7616                   -jbe 0x47dee9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047dee9;
    }
    // 0047ded3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ded7  81eac8000000           -sub edx, 0xc8
    (cpu.edx) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0047dedd  81ebc8000000           +sub ebx, 0xc8
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
    // 0047dee3  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047dee7  ebbb                   -jmp 0x47dea4
    goto L_0x0047dea4;
L_0x0047dee9:
    // 0047dee9  833c2408               +cmp dword ptr [esp], 8
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
    // 0047deed  7414                   -je 0x47df03
    if (cpu.flags.zf)
    {
        goto L_0x0047df03;
    }
    // 0047deef  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047def2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047def6  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047defb  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0047defe  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047df01  eba1                   -jmp 0x47dea4
    goto L_0x0047dea4;
L_0x0047df03:
    // 0047df03  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047df08  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047df0d  e8d6fdffff             -call 0x47dce8
    cpu.esp -= 4;
    sub_47dce8(app, cpu);
    if (cpu.terminate) return;
    // 0047df12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047df14  750b                   -jne 0x47df21
    if (!cpu.flags.zf)
    {
        goto L_0x0047df21;
    }
    // 0047df16  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047df1b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047df1f  eb8a                   -jmp 0x47deab
    goto L_0x0047deab;
L_0x0047df21:
    // 0047df21  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047df23  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047df27  eb82                   -jmp 0x47deab
    goto L_0x0047deab;
L_0x0047df29:
    // 0047df29  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047df2e  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047df33  e8b0fdffff             -call 0x47dce8
    cpu.esp -= 4;
    sub_47dce8(app, cpu);
    if (cpu.terminate) return;
    // 0047df38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047df3a  750e                   -jne 0x47df4a
    if (!cpu.flags.zf)
    {
        goto L_0x0047df4a;
    }
    // 0047df3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047df41  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047df45  e961ffffff             -jmp 0x47deab
    goto L_0x0047deab;
L_0x0047df4a:
    // 0047df4a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047df4c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047df50  e956ffffff             -jmp 0x47deab
    goto L_0x0047deab;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47df58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047df58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047df59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047df5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047df5b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047df5d  8a25dca34c00           -mov ah, byte ptr [0x4ca3dc]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047df63  8a15cdd75100           -mov dl, byte ptr [0x51d7cd]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 0047df69  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0047df6c  0f8499000000           -je 0x47e00b
    if (cpu.flags.zf)
    {
        goto L_0x0047e00b;
    }
    // 0047df72  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047df74:
    // 0047df74  8a1ddca34c00           -mov bl, byte ptr [0x4ca3dc]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047df7a  a2cdd75100             -mov byte ptr [0x51d7cd], al
    app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */) = cpu.al;
    // 0047df7f  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0047df82  0f848a000000           -je 0x47e012
    if (cpu.flags.zf)
    {
        goto L_0x0047e012;
    }
    // 0047df88  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0047df8a  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0047df8c  b302                   -mov bl, 2
    cpu.bl = 2 /*0x2*/;
    // 0047df8e  880da6d75100           -mov byte ptr [0x51d7a6], cl
    app->getMemory<x86::reg8>(x86::reg32(5363622) /* 0x51d7a6 */) = cpu.cl;
    // 0047df94  880da5d75100           -mov byte ptr [0x51d7a5], cl
    app->getMemory<x86::reg8>(x86::reg32(5363621) /* 0x51d7a5 */) = cpu.cl;
    // 0047df9a  880da4d75100           -mov byte ptr [0x51d7a4], cl
    app->getMemory<x86::reg8>(x86::reg32(5363620) /* 0x51d7a4 */) = cpu.cl;
    // 0047dfa0  8825ced75100           -mov byte ptr [0x51d7ce], ah
    app->getMemory<x86::reg8>(x86::reg32(5363662) /* 0x51d7ce */) = cpu.ah;
    // 0047dfa6  881da7d75100           -mov byte ptr [0x51d7a7], bl
    app->getMemory<x86::reg8>(x86::reg32(5363623) /* 0x51d7a7 */) = cpu.bl;
    // 0047dfac  881dd3d75100           -mov byte ptr [0x51d7d3], bl
    app->getMemory<x86::reg8>(x86::reg32(5363667) /* 0x51d7d3 */) = cpu.bl;
L_0x0047dfb2:
    // 0047dfb2  a13ca44c00             -mov eax, dword ptr [0x4ca43c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 0047dfb7  8b0db0a34c00           -mov ecx, dword ptr [0x4ca3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */);
    // 0047dfbd  a390d35100             -mov dword ptr [0x51d390], eax
    app->getMemory<x86::reg32>(x86::reg32(5362576) /* 0x51d390 */) = cpu.eax;
    // 0047dfc2  83f907                 +cmp ecx, 7
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
    // 0047dfc5  7427                   -je 0x47dfee
    if (cpu.flags.zf)
    {
        goto L_0x0047dfee;
    }
    // 0047dfc7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dfc8  e833950100             -call 0x497500
    cpu.esp -= 4;
    sub_497500(app, cpu);
    if (cpu.terminate) return;
    // 0047dfcd  b850e24700             -mov eax, 0x47e250
    cpu.eax = 4710992 /*0x47e250*/;
    // 0047dfd2  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0047dfd7  be9cdd4700             -mov esi, 0x47dd9c
    cpu.esi = 4709788 /*0x47dd9c*/;
    // 0047dfdc  e8fb260100             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 0047dfe1  891db0a34c00           -mov dword ptr [0x4ca3b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */) = cpu.ebx;
    // 0047dfe7  893558a44c00           -mov dword ptr [0x4ca458], esi
    app->getMemory<x86::reg32>(x86::reg32(5022808) /* 0x4ca458 */) = cpu.esi;
    // 0047dfed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dfee:
    // 0047dfee  e8299fffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047dff3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dff5  a0cdd75100             -mov al, byte ptr [0x51d7cd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 0047dffa  39c2                   +cmp edx, eax
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
    // 0047dffc  0f8485000000           -je 0x47e087
    if (cpu.flags.zf)
    {
        goto L_0x0047e087;
    }
    // 0047e002  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047e007  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e008  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e009  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e00a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e00b:
    // 0047e00b  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047e00d  e962ffffff             -jmp 0x47df74
    goto L_0x0047df74;
L_0x0047e012:
    // 0047e012  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0047e015  7451                   -je 0x47e068
    if (cpu.flags.zf)
    {
        goto L_0x0047e068;
    }
    // 0047e017  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047e019:
    // 0047e019  8a0ddca34c00           -mov cl, byte ptr [0x4ca3dc]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e01f  a2a6d75100             -mov byte ptr [0x51d7a6], al
    app->getMemory<x86::reg8>(x86::reg32(5363622) /* 0x51d7a6 */) = cpu.al;
    // 0047e024  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0047e027  7443                   -je 0x47e06c
    if (cpu.flags.zf)
    {
        goto L_0x0047e06c;
    }
    // 0047e029  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047e02b:
    // 0047e02b  8a2ddca34c00           -mov ch, byte ptr [0x4ca3dc]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e031  a2a5d75100             -mov byte ptr [0x51d7a5], al
    app->getMemory<x86::reg8>(x86::reg32(5363621) /* 0x51d7a5 */) = cpu.al;
    // 0047e036  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0047e039  7435                   -je 0x47e070
    if (cpu.flags.zf)
    {
        goto L_0x0047e070;
    }
    // 0047e03b  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047e03d:
    // 0047e03d  a2a4d75100             -mov byte ptr [0x51d7a4], al
    app->getMemory<x86::reg8>(x86::reg32(5363620) /* 0x51d7a4 */) = cpu.al;
    // 0047e042  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0047e044  a2ced75100             -mov byte ptr [0x51d7ce], al
    app->getMemory<x86::reg8>(x86::reg32(5363662) /* 0x51d7ce */) = cpu.al;
    // 0047e049  a0e0a34c00             -mov al, byte ptr [0x4ca3e0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5022688) /* 0x4ca3e0 */);
    // 0047e04e  a2a7d75100             -mov byte ptr [0x51d7a7], al
    app->getMemory<x86::reg8>(x86::reg32(5363623) /* 0x51d7a7 */) = cpu.al;
    // 0047e053  f605dca34c0040         +test byte ptr [0x4ca3dc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */) & 64 /*0x40*/));
    // 0047e05a  7418                   -je 0x47e074
    if (cpu.flags.zf)
    {
        goto L_0x0047e074;
    }
L_0x0047e05c:
    // 0047e05c  c605d3d7510001         -mov byte ptr [0x51d7d3], 1
    app->getMemory<x86::reg8>(x86::reg32(5363667) /* 0x51d7d3 */) = 1 /*0x1*/;
    // 0047e063  e94affffff             -jmp 0x47dfb2
    goto L_0x0047dfb2;
L_0x0047e068:
    // 0047e068  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047e06a  ebad                   -jmp 0x47e019
    goto L_0x0047e019;
L_0x0047e06c:
    // 0047e06c  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047e06e  ebbb                   -jmp 0x47e02b
    goto L_0x0047e02b;
L_0x0047e070:
    // 0047e070  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047e072  ebc9                   -jmp 0x47e03d
    goto L_0x0047e03d;
L_0x0047e074:
    // 0047e074  803da6d7510000         +cmp byte ptr [0x51d7a6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363622) /* 0x51d7a6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e07b  75df                   -jne 0x47e05c
    if (!cpu.flags.zf)
    {
        goto L_0x0047e05c;
    }
    // 0047e07d  a2d3d75100             -mov byte ptr [0x51d7d3], al
    app->getMemory<x86::reg8>(x86::reg32(5363667) /* 0x51d7d3 */) = cpu.al;
    // 0047e082  e92bffffff             -jmp 0x47dfb2
    goto L_0x0047dfb2;
L_0x0047e087:
    // 0047e087  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e089  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e08a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e08b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e08c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e090  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e091  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e092  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e093  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e095  a0ccd75100             -mov al, byte ptr [0x51d7cc]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363660) /* 0x51d7cc */);
    // 0047e09a  8b15bcd75100           -mov edx, dword ptr [0x51d7bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363644) /* 0x51d7bc */);
    // 0047e0a0  a3d8a34c00             -mov dword ptr [0x4ca3d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */) = cpu.eax;
    // 0047e0a5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e0a7  7405                   -je 0x47e0ae
    if (cpu.flags.zf)
    {
        goto L_0x0047e0ae;
    }
    // 0047e0a9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e0ae:
    // 0047e0ae  833dc0d7510000         +cmp dword ptr [0x51d7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363648) /* 0x51d7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e0b5  7470                   -je 0x47e127
    if (cpu.flags.zf)
    {
        goto L_0x0047e127;
    }
    // 0047e0b7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047e0bc:
    // 0047e0bc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e0be  a184d35100             -mov eax, dword ptr [0x51d384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */);
    // 0047e0c3  a3d0a34c00             -mov dword ptr [0x4ca3d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5022672) /* 0x4ca3d0 */) = cpu.eax;
    // 0047e0c8  a188d35100             -mov eax, dword ptr [0x51d388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */);
    // 0047e0cd  a3d4a34c00             -mov dword ptr [0x4ca3d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5022676) /* 0x4ca3d4 */) = cpu.eax;
    // 0047e0d2  a17cd35100             -mov eax, dword ptr [0x51d37c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362556) /* 0x51d37c */);
    // 0047e0d7  8b1de8a34c00           -mov ebx, dword ptr [0x4ca3e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022696) /* 0x4ca3e8 */);
    // 0047e0dd  a3e4a34c00             -mov dword ptr [0x4ca3e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5022692) /* 0x4ca3e4 */) = cpu.eax;
    // 0047e0e2  a1d0a34c00             -mov eax, dword ptr [0x4ca3d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022672) /* 0x4ca3d0 */);
    // 0047e0e7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e0e9  8b35eca34c00           -mov esi, dword ptr [0x4ca3ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022700) /* 0x4ca3ec */);
    // 0047e0ef  a3f0a34c00             -mov dword ptr [0x4ca3f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5022704) /* 0x4ca3f0 */) = cpu.eax;
    // 0047e0f4  a1d4a34c00             -mov eax, dword ptr [0x4ca3d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022676) /* 0x4ca3d4 */);
    // 0047e0f9  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e0fb  a3f4a34c00             -mov dword ptr [0x4ca3f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5022708) /* 0x4ca3f4 */) = cpu.eax;
    // 0047e100  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e102  a0d3d75100             -mov al, byte ptr [0x51d7d3]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363667) /* 0x51d7d3 */);
    // 0047e107  a3b0aa4c00             -mov dword ptr [0x4caab0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024432) /* 0x4caab0 */) = cpu.eax;
    // 0047e10c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e10e  a0d2d75100             -mov al, byte ptr [0x51d7d2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363666) /* 0x51d7d2 */);
    // 0047e113  8915e0a34c00           -mov dword ptr [0x4ca3e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5022688) /* 0x4ca3e0 */) = cpu.edx;
    // 0047e119  a3b4aa4c00             -mov dword ptr [0x4caab4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024436) /* 0x4caab4 */) = cpu.eax;
    // 0047e11e  e8f99dffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047e123  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e124  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e125  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e126  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e127:
    // 0047e127  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e129  eb91                   -jmp 0x47e0bc
    goto L_0x0047e0bc;
}

/* align: skip 0x90 */
void Application::sub_47e12c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e12c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e12d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e12e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e12f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e130  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e131  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e133  8b1570d35100           -mov edx, dword ptr [0x51d370]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362544) /* 0x51d370 */);
    // 0047e139  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e13b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e13d  0f85c7000000           -jne 0x47e20a
    if (!cpu.flags.zf)
    {
        goto L_0x0047e20a;
    }
    // 0047e143  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047e148:
    // 0047e148  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e14a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e14c  0f84bf000000           -je 0x47e211
    if (cpu.flags.zf)
    {
        goto L_0x0047e211;
    }
L_0x0047e152:
    // 0047e152  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047e157:
    // 0047e157  6860db4700             -push 0x47db60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4709216 /*0x47db60*/;
    cpu.esp -= 4;
    // 0047e15c  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 0047e161  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e163  e8b89bffff             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047e168  68f4db4700             -push 0x47dbf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4709364 /*0x47dbf4*/;
    cpu.esp -= 4;
    // 0047e16d  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 0047e172  e8a99bffff             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047e177  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047e179  742f                   -je 0x47e1aa
    if (cpu.flags.zf)
    {
        goto L_0x0047e1aa;
    }
    // 0047e17b  803dcdd7510000         +cmp byte ptr [0x51d7cd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e182  7426                   -je 0x47e1aa
    if (cpu.flags.zf)
    {
        goto L_0x0047e1aa;
    }
    // 0047e184  833d84d3510000         +cmp dword ptr [0x51d384], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e18b  750a                   -jne 0x47e197
    if (!cpu.flags.zf)
    {
        goto L_0x0047e197;
    }
    // 0047e18d  c70584d3510080020000   -mov dword ptr [0x51d384], 0x280
    app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */) = 640 /*0x280*/;
L_0x0047e197:
    // 0047e197  833d88d3510000         +cmp dword ptr [0x51d388], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e19e  750a                   -jne 0x47e1aa
    if (!cpu.flags.zf)
    {
        goto L_0x0047e1aa;
    }
    // 0047e1a0  c70588d35100e0010000   -mov dword ptr [0x51d388], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */) = 480 /*0x1e0*/;
L_0x0047e1aa:
    // 0047e1aa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e1ac  7438                   -je 0x47e1e6
    if (cpu.flags.zf)
    {
        goto L_0x0047e1e6;
    }
    // 0047e1ae  8b1588d35100           -mov edx, dword ptr [0x51d388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */);
    // 0047e1b4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e1b6  a184d35100             -mov eax, dword ptr [0x51d384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */);
    // 0047e1bb  8a1dcdd75100           -mov bl, byte ptr [0x51d7cd]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 0047e1c1  e86a85ffff             -call 0x476730
    cpu.esp -= 4;
    sub_476730(app, cpu);
    if (cpu.terminate) return;
    // 0047e1c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e1c8  7454                   -je 0x47e21e
    if (cpu.flags.zf)
    {
        goto L_0x0047e21e;
    }
    // 0047e1ca  b864040000             -mov eax, 0x464
    cpu.eax = 1124 /*0x464*/;
    // 0047e1cf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e1d1  e812fbffff             -call 0x47dce8
    cpu.esp -= 4;
    sub_47dce8(app, cpu);
    if (cpu.terminate) return;
    // 0047e1d6  8b0dc4d75100           -mov ecx, dword ptr [0x51d7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047e1dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e1dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e1df  2eff1524744b00         -call dword ptr cs:[0x4b7424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944932) /* 0x4b7424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047e1e6:
    // 0047e1e6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047e1e8  7411                   -je 0x47e1fb
    if (cpu.flags.zf)
    {
        goto L_0x0047e1fb;
    }
    // 0047e1ea  bb50d14c00             -mov ebx, 0x4cd150
    cpu.ebx = 5034320 /*0x4cd150*/;
    // 0047e1ef  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047e1f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e1f6  e85d3b0100             -call 0x491d58
    cpu.esp -= 4;
    sub_491d58(app, cpu);
    if (cpu.terminate) return;
L_0x0047e1fb:
    // 0047e1fb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e1fd  7526                   -jne 0x47e225
    if (!cpu.flags.zf)
    {
        goto L_0x0047e225;
    }
    // 0047e1ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047e204  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e205  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e206  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e208  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e209  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e20a:
    // 0047e20a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e20c  e937ffffff             -jmp 0x47e148
    goto L_0x0047e148;
L_0x0047e211:
    // 0047e211  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e213  0f8539ffffff           -jne 0x47e152
    if (!cpu.flags.zf)
    {
        goto L_0x0047e152;
    }
    // 0047e219  e939ffffff             -jmp 0x47e157
    goto L_0x0047e157;
L_0x0047e21e:
    // 0047e21e  beac024c00             -mov esi, 0x4c02ac
    cpu.esi = 4981420 /*0x4c02ac*/;
    // 0047e223  ebc1                   -jmp 0x47e1e6
    goto L_0x0047e1e6;
L_0x0047e225:
    // 0047e225  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e227  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e228  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e229  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e22a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e22b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e22c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e231  8b157cd35100           -mov edx, dword ptr [0x51d37c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362556) /* 0x51d37c */);
    // 0047e237  e83484ffff             -call 0x476670
    cpu.esp -= 4;
    sub_476670(app, cpu);
    if (cpu.terminate) return;
    // 0047e23c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e23e  e835040000             -call 0x47e678
    cpu.esp -= 4;
    sub_47e678(app, cpu);
    if (cpu.terminate) return;
    // 0047e243  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e244  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e248  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047e24d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e251  e8c69cffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047e256  833dc0ca4c0000         +cmp dword ptr [0x4ccac0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032640) /* 0x4ccac0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e25d  7544                   -jne 0x47e2a3
    if (!cpu.flags.zf)
    {
        goto L_0x0047e2a3;
    }
    // 0047e25f  833dc4d7510000         +cmp dword ptr [0x51d7c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e266  7543                   -jne 0x47e2ab
    if (!cpu.flags.zf)
    {
        goto L_0x0047e2ab;
    }
L_0x0047e268:
    // 0047e268  833db0a34c0007         +cmp dword ptr [0x4ca3b0], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e26f  7530                   -jne 0x47e2a1
    if (!cpu.flags.zf)
    {
        goto L_0x0047e2a1;
    }
    // 0047e271  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e272  8b3538a44c00           -mov esi, dword ptr [0x4ca438]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022776) /* 0x4ca438 */);
    // 0047e278  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e27a  7411                   -je 0x47e28d
    if (cpu.flags.zf)
    {
        goto L_0x0047e28d;
    }
    // 0047e27c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e27d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e27f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047e281  e8caa5ffff             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
    // 0047e286  893d38a44c00           -mov dword ptr [0x4ca438], edi
    app->getMemory<x86::reg32>(x86::reg32(5022776) /* 0x4ca438 */) = cpu.edi;
    // 0047e28c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e28d:
    // 0047e28d  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0047e28f  e8c4920100             -call 0x497558
    cpu.esp -= 4;
    sub_497558(app, cpu);
    if (cpu.terminate) return;
    // 0047e294  892db0a34c00           -mov dword ptr [0x4ca3b0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */) = cpu.ebp;
    // 0047e29a  892d58a44c00           -mov dword ptr [0x4ca458], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022808) /* 0x4ca458 */) = cpu.ebp;
    // 0047e2a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047e2a1:
    // 0047e2a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e2a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e2a3:
    // 0047e2a3  ff15c0ca4c00           -call dword ptr [0x4ccac0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032640) /* 0x4ccac0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047e2a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e2aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e2ab:
    // 0047e2ab  e8c083ffff             -call 0x476670
    cpu.esp -= 4;
    sub_476670(app, cpu);
    if (cpu.terminate) return;
    // 0047e2b0  ebb6                   -jmp 0x47e268
    goto L_0x0047e268;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e2b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e2b4  833d70d3510000         +cmp dword ptr [0x51d370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362544) /* 0x51d370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e2bb  7406                   -je 0x47e2c3
    if (cpu.flags.zf)
    {
        goto L_0x0047e2c3;
    }
    // 0047e2bd  a178d35100             -mov eax, dword ptr [0x51d378]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362552) /* 0x51d378 */);
    // 0047e2c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e2c3:
    // 0047e2c3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047e2c8  e8ab030000             -call 0x47e678
    cpu.esp -= 4;
    sub_47e678(app, cpu);
    if (cpu.terminate) return;
    // 0047e2cd  a178d35100             -mov eax, dword ptr [0x51d378]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362552) /* 0x51d378 */);
    // 0047e2d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47e2d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e2d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e2d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e2d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e2d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e2d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e2da  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047e2dc  833d70d3510000         +cmp dword ptr [0x51d370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362544) /* 0x51d370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e2e3  750a                   -jne 0x47e2ef
    if (!cpu.flags.zf)
    {
        goto L_0x0047e2ef;
    }
    // 0047e2e5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047e2ea  e889030000             -call 0x47e678
    cpu.esp -= 4;
    sub_47e678(app, cpu);
    if (cpu.terminate) return;
L_0x0047e2ef:
    // 0047e2ef  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0047e2f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e2f6  e8a1290000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0047e2fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e2fd  0f8cbe020000           -jl 0x47e5c1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e5c1;
    }
    // 0047e303  3b1d78d35100           +cmp ebx, dword ptr [0x51d378]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362552) /* 0x51d378 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e309  0f8db2020000           -jge 0x47e5c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e5c1;
    }
    // 0047e30f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e310  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e317  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047e31a  a180d35100             -mov eax, dword ptr [0x51d380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e31f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e322  8b3402                 -mov esi, dword ptr [edx + eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 0047e325  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 0047e327  8b740204               -mov esi, dword ptr [edx + eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047e32b  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047e32e  0fb6740213             -movzx esi, byte ptr [edx + eax + 0x13]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 1));
    // 0047e333  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0047e336  8a440212               -mov al, byte ptr [edx + eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */ + cpu.eax * 1);
    // 0047e33a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e33f  e81cc60100             -call 0x49a960
    cpu.esp -= 4;
    sub_49a960(app, cpu);
    if (cpu.terminate) return;
    // 0047e344  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047e347  a180d35100             -mov eax, dword ptr [0x51d380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e34c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e34e  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e351  f6420c08               +test byte ptr [edx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 0047e355  0f841c020000           -je 0x47e577
    if (cpu.flags.zf)
    {
        goto L_0x0047e577;
    }
    // 0047e35b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e360:
    // 0047e360  8020fd                 -and byte ptr [eax], 0xfd
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047e363  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e366  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e368  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047e36a  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e36c  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0047e36e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e375  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e377  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e37d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e380  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e382  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e385  f6420c04               +test byte ptr [edx + 0xc], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 4 /*0x4*/));
    // 0047e389  0f84ef010000           -je 0x47e57e
    if (cpu.flags.zf)
    {
        goto L_0x0047e57e;
    }
    // 0047e38f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e394:
    // 0047e394  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e397  8020fb                 -and byte ptr [eax], 0xfb
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0047e39a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e39d  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e39f  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e3a6  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047e3a9  a180d35100             -mov eax, dword ptr [0x51d380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e3ae  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e3b1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e3b3  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e3b6  f6420c10               +test byte ptr [edx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 0047e3ba  0f84c5010000           -je 0x47e585
    if (cpu.flags.zf)
    {
        goto L_0x0047e585;
    }
    // 0047e3c0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e3c5:
    // 0047e3c5  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e3c8  8020f7                 -and byte ptr [eax], 0xf7
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0047e3cb  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0047e3ce  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e3d0  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e3d7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3d9  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e3df  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e3e2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e3e4  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e3e7  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 0047e3eb  0f849b010000           -je 0x47e58c
    if (cpu.flags.zf)
    {
        goto L_0x0047e58c;
    }
    // 0047e3f1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e3f6:
    // 0047e3f6  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e3f9  8020ef                 -and byte ptr [eax], 0xef
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0047e3fc  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047e3ff  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e401  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e408  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e40a  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e410  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e413  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e415  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e418  f6420d08               +test byte ptr [edx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 0047e41c  0f8471010000           -je 0x47e593
    if (cpu.flags.zf)
    {
        goto L_0x0047e593;
    }
    // 0047e422  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e427:
    // 0047e427  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e42a  806001f7               -and byte ptr [eax + 1], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0047e42e  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 0047e431  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e433  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e436  c1e01d                 -shl eax, 0x1d
    cpu.eax <<= 29 /*0x1d*/ % 32;
    // 0047e439  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 0047e43c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e43e  0f8528010000           -jne 0x47e56c
    if (!cpu.flags.zf)
    {
        goto L_0x0047e56c;
    }
    // 0047e444  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e44b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e44d  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e453  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e456  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e458  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e45b  f6420d04               +test byte ptr [edx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0047e45f  0f8435010000           -je 0x47e59a
    if (cpu.flags.zf)
    {
        goto L_0x0047e59a;
    }
    // 0047e465  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e46a:
    // 0047e46a  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e46d  8020df                 -and byte ptr [eax], 0xdf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0047e470  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047e473  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e475  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e47c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e47e  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e484  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e487  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e489  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e48c  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 0047e490  0f840b010000           -je 0x47e5a1
    if (cpu.flags.zf)
    {
        goto L_0x0047e5a1;
    }
    // 0047e496  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e49b:
    // 0047e49b  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e49e  8020bf                 -and byte ptr [eax], 0xbf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 0047e4a1  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0047e4a4  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e4a6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e4ad  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047e4b0  a180d35100             -mov eax, dword ptr [0x51d380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e4b5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e4b8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e4ba  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e4bd  f6420c80               +test byte ptr [edx + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 0047e4c1  0f84e1000000           -je 0x47e5a8
    if (cpu.flags.zf)
    {
        goto L_0x0047e5a8;
    }
    // 0047e4c7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e4cc:
    // 0047e4cc  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e4cf  80207f                 -and byte ptr [eax], 0x7f
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0047e4d2  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 0047e4d5  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e4d7  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e4de  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047e4e1  a180d35100             -mov eax, dword ptr [0x51d380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e4e6  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e4e9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e4eb  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e4ee  f6420d01               +test byte ptr [edx + 0xd], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 1 /*0x1*/));
    // 0047e4f2  0f84b7000000           -je 0x47e5af
    if (cpu.flags.zf)
    {
        goto L_0x0047e5af;
    }
    // 0047e4f8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e4fd:
    // 0047e4fd  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e500  806001fe               -and byte ptr [eax + 1], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0047e504  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0047e507  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e509  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e510  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e512  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e518  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e51b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e51d  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e520  f6420d02               +test byte ptr [edx + 0xd], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 2 /*0x2*/));
    // 0047e524  0f848c000000           -je 0x47e5b6
    if (cpu.flags.zf)
    {
        goto L_0x0047e5b6;
    }
    // 0047e52a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e52f:
    // 0047e52f  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e532  806001fd               -and byte ptr [eax + 1], 0xfd
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047e536  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0047e539  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e53b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e542  8b1580d35100           -mov edx, dword ptr [0x51d380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
    // 0047e548  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e54a  8a5c820c               -mov bl, byte ptr [edx + eax*4 + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 0047e54e  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047e551  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 0047e554  7467                   -je 0x47e5bd
    if (cpu.flags.zf)
    {
        goto L_0x0047e5bd;
    }
    // 0047e556  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047e55b:
    // 0047e55b  8a7901                 -mov bh, byte ptr [ecx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047e55e  80e7fb                 -and bh, 0xfb
    cpu.bh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0047e561  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e564  887901                 -mov byte ptr [ecx + 1], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bh;
    // 0047e567  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0047e56a  0901                   -or dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047e56c:
    // 0047e56c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047e571  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e572  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e573  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e574  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e575  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e576  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e577:
    // 0047e577  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e579  e9e2fdffff             -jmp 0x47e360
    goto L_0x0047e360;
L_0x0047e57e:
    // 0047e57e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e580  e90ffeffff             -jmp 0x47e394
    goto L_0x0047e394;
L_0x0047e585:
    // 0047e585  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e587  e939feffff             -jmp 0x47e3c5
    goto L_0x0047e3c5;
L_0x0047e58c:
    // 0047e58c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e58e  e963feffff             -jmp 0x47e3f6
    goto L_0x0047e3f6;
L_0x0047e593:
    // 0047e593  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e595  e98dfeffff             -jmp 0x47e427
    goto L_0x0047e427;
L_0x0047e59a:
    // 0047e59a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e59c  e9c9feffff             -jmp 0x47e46a
    goto L_0x0047e46a;
L_0x0047e5a1:
    // 0047e5a1  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e5a3  e9f3feffff             -jmp 0x47e49b
    goto L_0x0047e49b;
L_0x0047e5a8:
    // 0047e5a8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e5aa  e91dffffff             -jmp 0x47e4cc
    goto L_0x0047e4cc;
L_0x0047e5af:
    // 0047e5af  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e5b1  e947ffffff             -jmp 0x47e4fd
    goto L_0x0047e4fd;
L_0x0047e5b6:
    // 0047e5b6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e5b8  e972ffffff             -jmp 0x47e52f
    goto L_0x0047e52f;
L_0x0047e5bd:
    // 0047e5bd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e5bf  eb9a                   -jmp 0x47e55b
    goto L_0x0047e55b;
L_0x0047e5c1:
    // 0047e5c1  83fbff                 +cmp ebx, -1
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
    // 0047e5c4  0f85a7000000           -jne 0x47e671
    if (!cpu.flags.zf)
    {
        goto L_0x0047e671;
    }
    // 0047e5ca  803dcdd7510000         +cmp byte ptr [0x51d7cd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e5d1  0f859a000000           -jne 0x47e671
    if (!cpu.flags.zf)
    {
        goto L_0x0047e671;
    }
    // 0047e5d7  a184d35100             -mov eax, dword ptr [0x51d384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */);
    // 0047e5dc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047e5de  a188d35100             -mov eax, dword ptr [0x51d388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */);
    // 0047e5e3  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e5e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5e8  a0ccd75100             -mov al, byte ptr [0x51d7cc]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363660) /* 0x51d7cc */);
    // 0047e5ed  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047e5f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5f2  a011a74c00             -mov al, byte ptr [0x4ca711]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023505) /* 0x4ca711 */);
    // 0047e5f7  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e5fa  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047e5fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5ff  80e2fd                 -and dl, 0xfd
    cpu.dl &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047e602  a0d2d75100             -mov al, byte ptr [0x51d7d2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363666) /* 0x51d7d2 */);
    // 0047e607  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0047e60a  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e60d  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e610  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e612  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e614  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0047e617  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e619  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e61c  a0cfd75100             -mov al, byte ptr [0x51d7cf]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363663) /* 0x51d7cf */);
    // 0047e621  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0047e624  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e627  887110                 -mov byte ptr [ecx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 0047e62a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e62d  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047e630  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047e633  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e635  8a1dd3d75100           -mov bl, byte ptr [0x51d7d3]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5363667) /* 0x51d7d3 */);
    // 0047e63b  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 0047e63d  80fb01                 +cmp bl, 1
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
    // 0047e640  762b                   -jbe 0x47e66d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047e66d;
    }
    // 0047e642  803dd0d7510000         +cmp byte ptr [0x51d7d0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363664) /* 0x51d7d0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e649  7422                   -je 0x47e66d
    if (cpu.flags.zf)
    {
        goto L_0x0047e66d;
    }
    // 0047e64b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047e650:
    // 0047e650  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047e652  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0047e655  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047e658  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 0047e65a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047e65d  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047e65f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e661  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047e666  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0047e668  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e669  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e66a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e66b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e66c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e66d:
    // 0047e66d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e66f  ebdf                   -jmp 0x47e650
    goto L_0x0047e650;
L_0x0047e671:
    // 0047e671  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e673  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e674  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e675  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e676  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e677  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e678  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e679  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e67b  e8d8f8ffff             -call 0x47df58
    cpu.esp -= 4;
    sub_47df58(app, cpu);
    if (cpu.terminate) return;
    // 0047e680  e8a7faffff             -call 0x47e12c
    cpu.esp -= 4;
    sub_47e12c(app, cpu);
    if (cpu.terminate) return;
    // 0047e685  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e687  7441                   -je 0x47e6ca
    if (cpu.flags.zf)
    {
        goto L_0x0047e6ca;
    }
    // 0047e689  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e68b  7c08                   -jl 0x47e695
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e695;
    }
    // 0047e68d  3b1578d35100           +cmp edx, dword ptr [0x51d378]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362552) /* 0x51d378 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e693  7c05                   -jl 0x47e69a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e69a;
    }
L_0x0047e695:
    // 0047e695  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0047e69a:
    // 0047e69a  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047e69f  e844f6ffff             -call 0x47dce8
    cpu.esp -= 4;
    sub_47dce8(app, cpu);
    if (cpu.terminate) return;
    // 0047e6a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e6a6  751e                   -jne 0x47e6c6
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6c6;
    }
    // 0047e6a8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047e6ad:
    // 0047e6ad  e8def9ffff             -call 0x47e090
    cpu.esp -= 4;
    sub_47e090(app, cpu);
    if (cpu.terminate) return;
    // 0047e6b2  833db0a34c0007         +cmp dword ptr [0x4ca3b0], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e6b9  7514                   -jne 0x47e6cf
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6cf;
    }
    // 0047e6bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e6bd  7410                   -je 0x47e6cf
    if (cpu.flags.zf)
    {
        goto L_0x0047e6cf;
    }
    // 0047e6bf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047e6c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e6c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e6c6:
    // 0047e6c6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e6c8  ebe3                   -jmp 0x47e6ad
    goto L_0x0047e6ad;
L_0x0047e6ca:
    // 0047e6ca  a3b0a34c00             -mov dword ptr [0x4ca3b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */) = cpu.eax;
L_0x0047e6cf:
    // 0047e6cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e6d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e6d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47e6d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e6d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e6d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e6d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e6d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e6d8  8b3ddca34c00           -mov edi, dword ptr [0x4ca3dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e6de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e6e0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047e6e2  8b2dc4ca4c00           -mov ebp, dword ptr [0x4ccac4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5032644) /* 0x4ccac4 */);
    // 0047e6e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e6ea  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047e6ec  7530                   -jne 0x47e71e
    if (!cpu.flags.zf)
    {
        goto L_0x0047e71e;
    }
    // 0047e6ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e6f0  7536                   -jne 0x47e728
    if (!cpu.flags.zf)
    {
        goto L_0x0047e728;
    }
    // 0047e6f2  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x0047e6f7:
    // 0047e6f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e6f9  7539                   -jne 0x47e734
    if (!cpu.flags.zf)
    {
        goto L_0x0047e734;
    }
    // 0047e6fb  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
L_0x0047e700:
    // 0047e700  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e702  753c                   -jne 0x47e740
    if (!cpu.flags.zf)
    {
        goto L_0x0047e740;
    }
L_0x0047e704:
    // 0047e704  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0047e709:
    // 0047e709  893ddca34c00           -mov dword ptr [0x4ca3dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */) = cpu.edi;
    // 0047e70f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e711  7439                   -je 0x47e74c
    if (cpu.flags.zf)
    {
        goto L_0x0047e74c;
    }
L_0x0047e713:
    // 0047e713  8b3ddca34c00           -mov edi, dword ptr [0x4ca3dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e719  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e71a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e71b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e71c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e71d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e71e:
    // 0047e71e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047e720  ff15c4ca4c00           -call dword ptr [0x4ccac4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032644) /* 0x4ccac4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047e726  ebeb                   -jmp 0x47e713
    goto L_0x0047e713;
L_0x0047e728:
    // 0047e728  83f8ff                 +cmp eax, -1
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
    // 0047e72b  75ca                   -jne 0x47e6f7
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6f7;
    }
    // 0047e72d  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 0047e732  ebc3                   -jmp 0x47e6f7
    goto L_0x0047e6f7;
L_0x0047e734:
    // 0047e734  83feff                 +cmp esi, -1
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
    // 0047e737  75c7                   -jne 0x47e700
    if (!cpu.flags.zf)
    {
        goto L_0x0047e700;
    }
    // 0047e739  be00030000             -mov esi, 0x300
    cpu.esi = 768 /*0x300*/;
    // 0047e73e  ebc0                   -jmp 0x47e700
    goto L_0x0047e700;
L_0x0047e740:
    // 0047e740  83fbff                 +cmp ebx, -1
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
    // 0047e743  74bf                   -je 0x47e704
    if (cpu.flags.zf)
    {
        goto L_0x0047e704;
    }
    // 0047e745  83fb0f                 +cmp ebx, 0xf
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
    // 0047e748  75bf                   -jne 0x47e709
    if (!cpu.flags.zf)
    {
        goto L_0x0047e709;
    }
    // 0047e74a  ebb8                   -jmp 0x47e704
    goto L_0x0047e704;
L_0x0047e74c:
    // 0047e74c  e807f8ffff             -call 0x47df58
    cpu.esp -= 4;
    sub_47df58(app, cpu);
    if (cpu.terminate) return;
    // 0047e751  890d84d35100           -mov dword ptr [0x51d384], ecx
    app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */) = cpu.ecx;
    // 0047e757  893588d35100           -mov dword ptr [0x51d388], esi
    app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */) = cpu.esi;
    // 0047e75d  891d8cd35100           -mov dword ptr [0x51d38c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5362572) /* 0x51d38c */) = cpu.ebx;
    // 0047e763  881dccd75100           -mov byte ptr [0x51d7cc], bl
    app->getMemory<x86::reg8>(x86::reg32(5363660) /* 0x51d7cc */) = cpu.bl;
    // 0047e769  e8bef9ffff             -call 0x47e12c
    cpu.esp -= 4;
    sub_47e12c(app, cpu);
    if (cpu.terminate) return;
    // 0047e76e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e770  7511                   -jne 0x47e783
    if (!cpu.flags.zf)
    {
        goto L_0x0047e783;
    }
    // 0047e772  8915b0a34c00           -mov dword ptr [0x4ca3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */) = cpu.edx;
    // 0047e778  8b3ddca34c00           -mov edi, dword ptr [0x4ca3dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e77e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e77f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e780  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e781  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e782  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e783:
    // 0047e783  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 0047e788  e86bf6ffff             -call 0x47ddf8
    cpu.esp -= 4;
    sub_47ddf8(app, cpu);
    if (cpu.terminate) return;
    // 0047e78d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e78f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e791  7527                   -jne 0x47e7ba
    if (!cpu.flags.zf)
    {
        goto L_0x0047e7ba;
    }
    // 0047e793  8b3ddca34c00           -mov edi, dword ptr [0x4ca3dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e799  66f7c78000             +test di, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & 128 /*0x80*/));
    // 0047e79e  750a                   -jne 0x47e7aa
    if (!cpu.flags.zf)
    {
        goto L_0x0047e7aa;
    }
    // 0047e7a0  6681cf8000             +or di, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(128 /*0x80*/))));
    // 0047e7a5  e95fffffff             -jmp 0x47e709
    goto L_0x0047e709;
L_0x0047e7aa:
    // 0047e7aa  a3b0a34c00             -mov dword ptr [0x4ca3b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */) = cpu.eax;
    // 0047e7af  8b3ddca34c00           -mov edi, dword ptr [0x4ca3dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e7b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e7ba:
    // 0047e7ba  e8d1f8ffff             -call 0x47e090
    cpu.esp -= 4;
    sub_47e090(app, cpu);
    if (cpu.terminate) return;
    // 0047e7bf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e7c1  7489                   -je 0x47e74c
    if (cpu.flags.zf)
    {
        goto L_0x0047e74c;
    }
    // 0047e7c3  8b3ddca34c00           -mov edi, dword ptr [0x4ca3dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 0047e7c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e7d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e7d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e7d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e7d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e7d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047e7d7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e7d9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e7db  8b3570d35100           -mov esi, dword ptr [0x51d370]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5362544) /* 0x51d370 */);
    // 0047e7e1  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047e7e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e7e6  7419                   -je 0x47e801
    if (cpu.flags.zf)
    {
        goto L_0x0047e801;
    }
L_0x0047e7e8:
    // 0047e7e8  833db0a34c0000         +cmp dword ptr [0x4ca3b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e7ef  751c                   -jne 0x47e80d
    if (!cpu.flags.zf)
    {
        goto L_0x0047e80d;
    }
L_0x0047e7f1:
    // 0047e7f1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e7f3  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047e7f6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e7f9  83c404                 +add esp, 4
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
    // 0047e7fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e800  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e801:
    // 0047e801  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047e806  e86dfeffff             -call 0x47e678
    cpu.esp -= 4;
    sub_47e678(app, cpu);
    if (cpu.terminate) return;
    // 0047e80b  ebdb                   -jmp 0x47e7e8
    goto L_0x0047e7e8;
L_0x0047e80d:
    // 0047e80d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 0047e812  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e813  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e815  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047e817  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e81b  e88c910000             -call 0x4879ac
    cpu.esp -= 4;
    sub_4879ac(app, cpu);
    if (cpu.terminate) return;
    // 0047e820  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e822  74cd                   -je 0x47e7f1
    if (cpu.flags.zf)
    {
        goto L_0x0047e7f1;
    }
    // 0047e824  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e827  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047e82a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e82b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e82c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e82d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e82e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47e830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e830  a1d4aa4c00             -mov eax, dword ptr [0x4caad4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024468) /* 0x4caad4 */);
    // 0047e835  0305d0aa4c00           +add eax, dword ptr [0x4caad0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024464) /* 0x4caad0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e83b  a3d0aa4c00             -mov dword ptr [0x4caad0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024464) /* 0x4caad0 */) = cpu.eax;
    // 0047e840  1305ccaa4c00           +adc eax, dword ptr [0x4caacc]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024460) /* 0x4caacc */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e846  a3ccaa4c00             -mov dword ptr [0x4caacc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024460) /* 0x4caacc */) = cpu.eax;
    // 0047e84b  1305c8aa4c00           +adc eax, dword ptr [0x4caac8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024456) /* 0x4caac8 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e851  a3c8aa4c00             -mov dword ptr [0x4caac8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024456) /* 0x4caac8 */) = cpu.eax;
    // 0047e856  1305c4aa4c00           +adc eax, dword ptr [0x4caac4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024452) /* 0x4caac4 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e85c  a3c4aa4c00             -mov dword ptr [0x4caac4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024452) /* 0x4caac4 */) = cpu.eax;
    // 0047e861  1305c0aa4c00           +adc eax, dword ptr [0x4caac0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024448) /* 0x4caac0 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e867  ff05d4aa4c00           +inc dword ptr [0x4caad4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024468) /* 0x4caad4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e86d  7521                   -jne 0x47e890
    if (!cpu.flags.zf)
    {
        goto L_0x0047e890;
    }
    // 0047e86f  ff05d0aa4c00           +inc dword ptr [0x4caad0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024464) /* 0x4caad0 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e875  7519                   -jne 0x47e890
    if (!cpu.flags.zf)
    {
        goto L_0x0047e890;
    }
    // 0047e877  ff05ccaa4c00           +inc dword ptr [0x4caacc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024460) /* 0x4caacc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e87d  7511                   -jne 0x47e890
    if (!cpu.flags.zf)
    {
        goto L_0x0047e890;
    }
    // 0047e87f  ff05c8aa4c00           +inc dword ptr [0x4caac8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024456) /* 0x4caac8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e885  7509                   -jne 0x47e890
    if (!cpu.flags.zf)
    {
        goto L_0x0047e890;
    }
    // 0047e887  ff05c4aa4c00           +inc dword ptr [0x4caac4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024452) /* 0x4caac4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047e88d  7501                   -jne 0x47e890
    if (!cpu.flags.zf)
    {
        goto L_0x0047e890;
    }
    // 0047e88f  40                     -inc eax
    (cpu.eax)++;
L_0x0047e890:
    // 0047e890  a3c0aa4c00             -mov dword ptr [0x4caac0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024448) /* 0x4caac0 */) = cpu.eax;
    // 0047e895  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e896(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e896  05560e2df2             -add eax, 0xf22d0e56
    (cpu.eax) += x86::reg32(x86::sreg32(4063039062 /*0xf22d0e56*/));
    // 0047e89b  a3c0aa4c00             -mov dword ptr [0x4caac0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024448) /* 0x4caac0 */) = cpu.eax;
    // 0047e8a0  0593180496             -add eax, 0x96041893
    (cpu.eax) += x86::reg32(x86::sreg32(2516850835 /*0x96041893*/));
    // 0047e8a5  a3c4aa4c00             -mov dword ptr [0x4caac4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024452) /* 0x4caac4 */) = cpu.eax;
    // 0047e8aa  0546b6f33d             -add eax, 0x3df3b646
    (cpu.eax) += x86::reg32(x86::sreg32(1039382086 /*0x3df3b646*/));
    // 0047e8af  a3c8aa4c00             -mov dword ptr [0x4caac8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024456) /* 0x4caac8 */) = cpu.eax;
    // 0047e8b4  056de7dd40             -add eax, 0x40dde76d
    (cpu.eax) += x86::reg32(x86::sreg32(1088284525 /*0x40dde76d*/));
    // 0047e8b9  a3ccaa4c00             -mov dword ptr [0x4caacc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024460) /* 0x4caacc */) = cpu.eax;
    // 0047e8be  05e17a3297             -add eax, 0x97327ae1
    (cpu.eax) += x86::reg32(x86::sreg32(2536667873 /*0x97327ae1*/));
    // 0047e8c3  a3d0aa4c00             -mov dword ptr [0x4caad0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024464) /* 0x4caad0 */) = cpu.eax;
    // 0047e8c8  05e7fba9d1             -add eax, 0xd1a9fbe7
    (cpu.eax) += x86::reg32(x86::sreg32(3517578215 /*0xd1a9fbe7*/));
    // 0047e8cd  a3d4aa4c00             -mov dword ptr [0x4caad4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024468) /* 0x4caad4 */) = cpu.eax;
    // 0047e8d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e8e0  e897bdffff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 0047e8e5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047e8e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e8e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e8ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e8eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e8ec  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e8ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e8f1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047e8f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e8f7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047e8fa  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047e8ff  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0047e902  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e906  83f803                 +cmp eax, 3
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
    // 0047e909  0f8591000000           -jne 0x47e9a0
    if (!cpu.flags.zf)
    {
        return sub_47e9a0(app, cpu);
    }
    // 0047e90f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e911  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
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
    // 0047e914  7f50                   -jg 0x47e966
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_47e966(app, cpu);
    }
    // 0047e916  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e91a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047e91d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e920  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e922  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e924  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e8e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047e8e8;
    // 0047e8e0  e897bdffff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 0047e8e5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0047e8e8:
    // 0047e8e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e8e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e8ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e8eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e8ec  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e8ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e8f1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047e8f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e8f7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047e8fa  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047e8ff  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0047e902  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e906  83f803                 +cmp eax, 3
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
    // 0047e909  0f8591000000           -jne 0x47e9a0
    if (!cpu.flags.zf)
    {
        return sub_47e9a0(app, cpu);
    }
    // 0047e90f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e911  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
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
    // 0047e914  7f50                   -jg 0x47e966
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_47e966(app, cpu);
    }
    // 0047e916  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e91a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047e91d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e920  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e922  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e924  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e91d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047e91d;
    // 0047e8e0  e897bdffff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 0047e8e5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047e8e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e8e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e8ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e8eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e8ec  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e8ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e8f1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047e8f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e8f7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047e8fa  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047e8ff  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0047e902  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e906  83f803                 +cmp eax, 3
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
    // 0047e909  0f8591000000           -jne 0x47e9a0
    if (!cpu.flags.zf)
    {
        return sub_47e9a0(app, cpu);
    }
    // 0047e90f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e911  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
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
    // 0047e914  7f50                   -jg 0x47e966
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_47e966(app, cpu);
    }
    // 0047e916  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e91a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_entry_0x0047e91d:
    // 0047e91d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e920  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e922  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e924  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e928(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e928  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e929  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047e92e  e849bdffff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 0047e933  e8b0ffffff             -call 0x47e8e8
    cpu.esp -= 4;
    sub_47e8e8(app, cpu);
    if (cpu.terminate) return;
    // 0047e938  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e939  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e93c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e93c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e93d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e93f  e838bdffff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 0047e944  e89fffffff             -call 0x47e8e8
    cpu.esp -= 4;
    sub_47e8e8(app, cpu);
    if (cpu.terminate) return;
    // 0047e949  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e94a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47e94c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e94c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e94d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047e952  e891ffffff             -call 0x47e8e8
    cpu.esp -= 4;
    sub_47e8e8(app, cpu);
    if (cpu.terminate) return;
    // 0047e957  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e958  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e95c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e95c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e95d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e95f  e884ffffff             -call 0x47e8e8
    cpu.esp -= 4;
    sub_47e8e8(app, cpu);
    if (cpu.terminate) return;
    // 0047e964  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e965  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e966(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e966  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047e969  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047e96b  e8d46b0100             -call 0x495544
    cpu.esp -= 4;
    sub_495544(app, cpu);
    if (cpu.terminate) return;
    // 0047e970  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e972  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e974  74a7                   -je 0x47e91d
    if (cpu.flags.zf)
    {
        return sub_47e91d(app, cpu);
    }
    // 0047e976  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047e978  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047e97b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047e97d  e87e2c0000             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0047e982  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047e984  e81f6c0100             -call 0x4955a8
    cpu.esp -= 4;
    sub_4955a8(app, cpu);
    if (cpu.terminate) return;
    // 0047e989  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0047e98b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e98e  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047e991  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e995  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047e998  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e99b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e99c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e99d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e99e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e99f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e9a0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e9a2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e9a5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e9a7  bbf0d75100             -mov ebx, 0x51d7f0
    cpu.ebx = 5363696 /*0x51d7f0*/;
    // 0047e9ac  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047e9af  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e9b1  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047e9b6  e855910100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047e9bb  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047e9be  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047e9c0  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047e9c3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e9c5  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047e9c8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047e9ca  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047e9cd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e9cf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e9d3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047e9d5  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e9d7  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e9d9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047e9db  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e9df  21c1                   -and ecx, eax
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e9e1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047e9e3  7c37                   -jl 0x47ea1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ea1c;
    }
L_0x0047e9e5:
    // 0047e9e5  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047e9e7:
    // 0047e9e7  39f9                   +cmp ecx, edi
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
    // 0047e9e9  7f4c                   -jg 0x47ea37
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ea37;
    }
    // 0047e9eb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e9ed  7c48                   -jl 0x47ea37
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ea37;
    }
    // 0047e9ef  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e9f3  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047e9f6  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047e9f9  837b1400               +cmp dword ptr [ebx + 0x14], 0
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
    // 0047e9fd  7407                   -je 0x47ea06
    if (cpu.flags.zf)
    {
        goto L_0x0047ea06;
    }
    // 0047e9ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ea01  e85a910100             -call 0x497b60
    cpu.esp -= 4;
    sub_497b60(app, cpu);
    if (cpu.terminate) return;
L_0x0047ea06:
    // 0047ea06  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ea0b  e808910100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047ea10  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ea14  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ea17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea1c:
    // 0047ea1c  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047ea1e  83fdff                 +cmp ebp, -1
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
    // 0047ea21  74c2                   -je 0x47e9e5
    if (cpu.flags.zf)
    {
        goto L_0x0047e9e5;
    }
    // 0047ea23  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ea28  e8eb900100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047ea2d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ea2f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ea32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea37:
    // 0047ea37  833da4a64c0000         +cmp dword ptr [0x4ca6a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ea3e  740d                   -je 0x47ea4d
    if (cpu.flags.zf)
    {
        goto L_0x0047ea4d;
    }
    // 0047ea40  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047ea43  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 0047ea47  7404                   -je 0x47ea4d
    if (cpu.flags.zf)
    {
        goto L_0x0047ea4d;
    }
    // 0047ea49  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047ea4b  742f                   -je 0x47ea7c
    if (cpu.flags.zf)
    {
        goto L_0x0047ea7c;
    }
L_0x0047ea4d:
    // 0047ea4d  833da4a64c0000         +cmp dword ptr [0x4ca6a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ea54  7406                   -je 0x47ea5c
    if (cpu.flags.zf)
    {
        goto L_0x0047ea5c;
    }
    // 0047ea56  f6461810               +test byte ptr [esi + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 0047ea5a  754d                   -jne 0x47eaa9
    if (!cpu.flags.zf)
    {
        goto L_0x0047eaa9;
    }
L_0x0047ea5c:
    // 0047ea5c  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ea61  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ea65  e8ae900100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047ea6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ea6c  0f8cda000000           -jl 0x47eb4c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eb4c;
    }
    // 0047ea72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ea74  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ea77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea7c:
    // 0047ea7c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ea7e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047ea81  e812920100             -call 0x497c98
    cpu.esp -= 4;
    sub_497c98(app, cpu);
    if (cpu.terminate) return;
    // 0047ea86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ea88  7415                   -je 0x47ea9f
    if (cpu.flags.zf)
    {
        goto L_0x0047ea9f;
    }
    // 0047ea8a  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047ea8d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047ea8f  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047ea92  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ea94  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047ea96  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ea98  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047ea9a  e948ffffff             -jmp 0x47e9e7
    goto L_0x0047e9e7;
L_0x0047ea9f:
    // 0047ea9f  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0047eaa4  e93effffff             -jmp 0x47e9e7
    goto L_0x0047e9e7;
L_0x0047eaa9:
    // 0047eaa9  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047eaac  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047eaae  e8f5920100             -call 0x497da8
    cpu.esp -= 4;
    sub_497da8(app, cpu);
    if (cpu.terminate) return;
    // 0047eab3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047eab5  7415                   -je 0x47eacc
    if (cpu.flags.zf)
    {
        goto L_0x0047eacc;
    }
    // 0047eab7  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047eaba  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047eabc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047eabe  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047eac0  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047eac3  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047eac5  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047eac7  e91bffffff             -jmp 0x47e9e7
    goto L_0x0047e9e7;
L_0x0047eacc:
    // 0047eacc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ead0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ead4  b8b4024c00             -mov eax, 0x4c02b4
    cpu.eax = 4981428 /*0x4c02b4*/;
    // 0047ead9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047eadb  e8c0b7ffff             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 0047eae0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047eae2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047eae4  0f8472ffffff           -je 0x47ea5c
    if (cpu.flags.zf)
    {
        goto L_0x0047ea5c;
    }
    // 0047eaea  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047eaed  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047eaef  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047eaf1  e80a2b0000             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0047eaf6  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047eaf9  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047eafc  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047eaff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047eb01  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047eb04  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047eb07  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0047eb0a  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0047eb0d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047eb10  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0047eb13  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047eb15  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047eb17  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047eb1a  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047eb1d  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0047eb20  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047eb23  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047eb26  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047eb29  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047eb2c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047eb2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047eb31  e8c6bfffff             -call 0x47aafc
    cpu.esp -= 4;
    sub_47aafc(app, cpu);
    if (cpu.terminate) return;
    // 0047eb36  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047eb3b  e8d88f0100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047eb40  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047eb44  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047eb47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047eb4c:
    // 0047eb4c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047eb4e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047eb51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47eb56(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eb56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eb57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eb58  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eb59  2eff1574754b00         -call dword ptr cs:[0x4b7574]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945268) /* 0x4b7574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047eb62  7508                   -jne 0x47eb6c
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb6c;
    }
    // 0047eb64  e899b40100             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 0047eb69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047eb6c:
    // 0047eb6c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047eb6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb70  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
