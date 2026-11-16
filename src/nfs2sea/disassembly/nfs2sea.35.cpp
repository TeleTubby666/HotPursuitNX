#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 */
void Application::sub_4bd4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd4b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd4b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd4b3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bd4b6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bd4b8  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004bd4bb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bd4bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bd4bf  0f848d000000           -je 0x4bd552
    if (cpu.flags.zf)
    {
        goto L_0x004bd552;
    }
    // 004bd4c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd4c6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bd4c8  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bd4cb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd4cd  7e67                   -jle 0x4bd536
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd536;
    }
    // 004bd4cf  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bd4d2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bd4d6  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bd4d9  8d6818                 -lea ebp, [eax + 0x18]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bd4dc  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bd4df  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd4e3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004bd4e7:
    // 004bd4e7  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd4ea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bd4ec  756b                   -jne 0x4bd559
    if (!cpu.flags.zf)
    {
        goto L_0x004bd559;
    }
    // 004bd4ee  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd4f1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bd4f4  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bd4f7  39d0                   +cmp eax, edx
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
    // 004bd4f9  0f8d77000000           -jge 0x4bd576
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd576;
    }
    // 004bd4ff  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bd503  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bd508  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd50a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd50d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd50f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd512  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bd518  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd51a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd51b  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd51e  e8cd4d0000             -call 0x4c22f0
    cpu.esp -= 4;
    sub_4c22f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd523  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd526  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd529  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd52c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd52f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
L_0x004bd532:
    // 004bd532  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd534  7fb1                   -jg 0x4bd4e7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bd4e7;
    }
L_0x004bd536:
    // 004bd536  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bd53d  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd540  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd542  0f8ce5000000           -jl 0x4bd62d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd62d;
    }
    // 004bd548  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd54a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004bd54b:
    // 004bd54b  83c40c                 +add esp, 0xc
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
    // 004bd54e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd54f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd550  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd551  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd552:
    // 004bd552  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bd557  ebf2                   -jmp 0x4bd54b
    goto L_0x004bd54b;
L_0x004bd559:
    // 004bd559  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bd55d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bd561  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bd563  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bd565  e836faffff             -call 0x4bcfa0
    cpu.esp -= 4;
    sub_4bcfa0(app, cpu);
    if (cpu.terminate) return;
    // 004bd56a  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd56d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd56f  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bd571  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004bd574  ebbc                   -jmp 0x4bd532
    goto L_0x004bd532;
L_0x004bd576:
    // 004bd576  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd57a  7445                   -je 0x4bd5c1
    if (cpu.flags.zf)
    {
        goto L_0x004bd5c1;
    }
    // 004bd57c  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bd580  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bd585  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd587  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd58a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd58c  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd58f  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bd595  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd597  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd598  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd59b  e8504d0000             -call 0x4c22f0
    cpu.esp -= 4;
    sub_4c22f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd5a0  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd5a3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bd5a5  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bd5a8  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bd5ab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd5ad  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bd5af  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd5b2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd5b4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd5b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd5ba  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd5bc  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd5be  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004bd5c1:
    // 004bd5c1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bd5c5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bd5c7  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd5cd  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd5d0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bd5d2  7434                   -je 0x4bd608
    if (cpu.flags.zf)
    {
        goto L_0x004bd608;
    }
    // 004bd5d4  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bd5d7  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004bd5db  668b5302               -mov dx, word ptr [ebx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004bd5df  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004bd5e3  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004bd5e7  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 004bd5eb  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004bd5ef  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004bd5f3  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd5f6  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bd5fd  83c008                 +add eax, 8
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
    // 004bd600  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004bd603  e92affffff             -jmp 0x4bd532
    goto L_0x004bd532;
L_0x004bd608:
    // 004bd608  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bd60a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd60c  0f8e20ffffff           -jle 0x4bd532
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd532;
    }
L_0x004bd612:
    // 004bd612  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd615  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 004bd61a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd61d  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bd620  4f                     -dec edi
    (cpu.edi)--;
    // 004bd621  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bd624  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd626  7fea                   -jg 0x4bd612
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bd612;
    }
    // 004bd628  e905ffffff             -jmp 0x4bd532
    goto L_0x004bd532;
L_0x004bd62d:
    // 004bd62d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd630  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd633  668b12                 -mov dx, word ptr [edx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx);
    // 004bd636  6689548624             -mov word ptr [esi + eax*4 + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.dx;
    // 004bd63b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd63e  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd641  668b5202               -mov dx, word ptr [edx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004bd645  6689548626             -mov word ptr [esi + eax*4 + 0x26], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.eax * 4) = cpu.dx;
    // 004bd64a  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd64d  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd650  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd653  43                     -inc ebx
    (cpu.ebx)++;
    // 004bd654  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bd657  47                     -inc edi
    (cpu.edi)++;
    // 004bd658  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004bd65b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd65d  7cce                   -jl 0x4bd62d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd62d;
    }
    // 004bd65f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd661  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd662  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bd665  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd666  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd667  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd668  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bd66c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd66c  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004bd673  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bd67a  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bd681  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bd687  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bd68d  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004bd693  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bd699  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bd69c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bd6a0  c700b0d44b00           -mov dword ptr [eax], 0x4bd4b0
    app->getMemory<x86::reg32>(cpu.eax) = 4969648 /*0x4bd4b0*/;
    // 004bd6a6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bd6aa  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bd6b0  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bd6b5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bd6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd6c0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004bd6c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd6c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd6c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd6c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd6c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd6c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd6c8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bd6ca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bd6cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bd6ce  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004bd6d1  8b7918                 -mov edi, dword ptr [ecx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004bd6d4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bd6d6  39fa                   +cmp edx, edi
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
    // 004bd6d8  7d64                   -jge 0x4bd73e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd73e;
    }
    // 004bd6da  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bd6dc  8b6920                 -mov ebp, dword ptr [ecx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004bd6df  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bd6e2  39ee                   +cmp esi, ebp
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
    // 004bd6e4  7f62                   -jg 0x4bd748
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bd748;
    }
    // 004bd6e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd6e8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd6ea  7e1c                   -jle 0x4bd708
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd708;
    }
    // 004bd6ec  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bd6ee:
    // 004bd6ee  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd6f1  8b7a24                 -mov edi, dword ptr [edx + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004bd6f4  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004bd6f6  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd6f9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd6fc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd6ff  40                     -inc eax
    (cpu.eax)++;
    // 004bd700  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bd703  39f0                   +cmp eax, esi
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
    // 004bd705  7ce7                   -jl 0x4bd6ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd6ee;
    }
    // 004bd707  90                     -nop 
    ;
L_0x004bd708:
    // 004bd708  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bd70b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd70d  39f0                   +cmp eax, esi
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
    // 004bd70f  7d23                   -jge 0x4bd734
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd734;
    }
    // 004bd711  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004bd718  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bd71a  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bd71c:
    // 004bd71c  d94224                 -fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 004bd71f  41                     -inc ecx
    (cpu.ecx)++;
    // 004bd720  40                     -inc eax
    (cpu.eax)++;
    // 004bd721  d95e24                 -fstp dword ptr [esi + 0x24]
    app->getMemory<float>(cpu.esi + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd724  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd727  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bd72a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd72d  39f8                   +cmp eax, edi
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
    // 004bd72f  7ceb                   -jl 0x4bd71c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd71c;
    }
    // 004bd731  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bd734:
    // 004bd734  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd736  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bd739  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd73a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd73b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd73c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd73d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd73e:
    // 004bd73e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bd743  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd744  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd745  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd746  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd747  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd748:
    // 004bd748  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd74a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bd74c  7e1e                   -jle 0x4bd76c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd76c;
    }
    // 004bd74e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bd750:
    // 004bd750  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd753  d94024                 -fld dword ptr [eax + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */)));
    // 004bd756  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd759  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd75b  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd75e  42                     -inc edx
    (cpu.edx)++;
    // 004bd75f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd762  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bd765  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bd768  39fa                   +cmp edx, edi
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
    // 004bd76a  7ce4                   -jl 0x4bd750
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd750;
    }
L_0x004bd76c:
    // 004bd76c  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bd76f  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bd772  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bd775  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd777  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bd779  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd77b  0f8c7e000000           -jl 0x4bd7ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd7ff;
    }
L_0x004bd781:
    // 004bd781  39fe                   +cmp esi, edi
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
    // 004bd783  0f8d7d000000           -jge 0x4bd806
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd806;
    }
    // 004bd789  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004bd78b:
    // 004bd78b  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bd78e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bd795  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bd797  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd799  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd79c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd79e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd7a0  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd7a5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd7a8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd7aa  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004bd7ad  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004bd7af  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd7b1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd7b2  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd7b5  e8c64d0000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bd7ba  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bd7bd  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bd7bf  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bd7c1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bd7c3  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bd7c6  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd7c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd7cb  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bd7ce  39ef                   +cmp edi, ebp
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
    // 004bd7d0  7538                   -jne 0x4bd80a
    if (!cpu.flags.zf)
    {
        goto L_0x004bd80a;
    }
    // 004bd7d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd7d4  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bd7d7  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bd7d9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bd7db  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd7dd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd7df  7e17                   -jle 0x4bd7f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd7f8;
    }
L_0x004bd7e1:
    // 004bd7e1  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd7e4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bd7ea  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd7ed  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd7f0  4e                     -dec esi
    (cpu.esi)--;
    // 004bd7f1  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bd7f4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd7f6  7fe9                   -jg 0x4bd7e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bd7e1;
    }
L_0x004bd7f8:
    // 004bd7f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd7fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd7fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd7fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd7fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd7fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd7ff:
    // 004bd7ff  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bd801  e97bffffff             -jmp 0x4bd781
    goto L_0x004bd781;
L_0x004bd806:
    // 004bd806  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004bd808  eb81                   -jmp 0x4bd78b
    goto L_0x004bd78b;
L_0x004bd80a:
    // 004bd80a  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bd80c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd80e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd810  7c0a                   -jl 0x4bd81c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd81c;
    }
    // 004bd812  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bd815  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd817  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd818  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd819  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd81a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd81b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd81c:
    // 004bd81c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bd81e  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
L_0x004bd825:
    // 004bd825  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd828  46                     -inc esi
    (cpu.esi)++;
    // 004bd829  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bd82c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd82f  41                     -inc ecx
    (cpu.ecx)++;
    // 004bd830  8b6c07fc               -mov ebp, dword ptr [edi + eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004bd834  896a20                 -mov dword ptr [edx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004bd837  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd839  7cea                   -jl 0x4bd825
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd825;
    }
    // 004bd83b  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bd83e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd840  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd841  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd842  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd843  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd844  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bd848(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd848  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bd84f  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bd856  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bd85d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bd864  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bd867  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bd86a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bd86e  c700c4d64b00           -mov dword ptr [eax], 0x4bd6c4
    app->getMemory<x86::reg32>(cpu.eax) = 4970180 /*0x4bd6c4*/;
    // 004bd874  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bd878  c700c0d64b00           -mov dword ptr [eax], 0x4bd6c0
    app->getMemory<x86::reg32>(cpu.eax) = 4970176 /*0x4bd6c0*/;
    // 004bd87e  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bd883  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bd890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd890  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd891  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd892  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd893  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd896  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bd898  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bd89b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004bd89d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bd89f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bd8a1  39d8                   +cmp eax, ebx
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
    // 004bd8a3  7d02                   -jge 0x4bd8a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd8a7;
    }
    // 004bd8a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004bd8a7:
    // 004bd8a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd8a9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd8ab  7e13                   -jle 0x4bd8c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd8c0;
    }
    // 004bd8ad  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004bd8b0:
    // 004bd8b0  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004bd8b2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd8b5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd8b8  40                     -inc eax
    (cpu.eax)++;
    // 004bd8b9  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd8bc  39f0                   +cmp eax, esi
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
    // 004bd8be  7cf0                   -jl 0x4bd8b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd8b0;
    }
L_0x004bd8c0:
    // 004bd8c0  39f8                   +cmp eax, edi
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
    // 004bd8c2  7d1c                   -jge 0x4bd8e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd8e0;
    }
    // 004bd8c4  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bd8c7  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004bd8ce  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bd8d0:
    // 004bd8d0  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004bd8d2  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd8d5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd8d8  40                     -inc eax
    (cpu.eax)++;
    // 004bd8d9  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd8dc  39f8                   +cmp eax, edi
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
    // 004bd8de  7cf0                   -jl 0x4bd8d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd8d0;
    }
L_0x004bd8e0:
    // 004bd8e0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bd8e2  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 004bd8e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd8e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd8e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd8ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd8eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd8ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd8ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd8ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd8ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd8ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd8f0  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bd8f3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bd8f5  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bd8f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bd8f9  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bd8fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd8fe  7e55                   -jle 0x4bd955
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd955;
    }
    // 004bd900  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bd903  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004bd907  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004bd90a:
    // 004bd90a  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bd90d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bd90f  7560                   -jne 0x4bd971
    if (!cpu.flags.zf)
    {
        goto L_0x004bd971;
    }
    // 004bd911  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd914  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bd917  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bd91a  39d8                   +cmp eax, ebx
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
    // 004bd91c  7d6e                   -jge 0x4bd98c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd98c;
    }
    // 004bd91e  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bd922  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd927  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd929  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd92c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd92e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd931  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bd937  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd939  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd93a  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd93d  e83e4c0000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bd942  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd945  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd948  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd94b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd94e  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004bd951:
    // 004bd951  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd953  7fb5                   -jg 0x4bd90a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bd90a;
    }
L_0x004bd955:
    // 004bd955  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bd95c  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd95f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd961  0f8c24010000           -jl 0x4bda8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bda8b;
    }
    // 004bd967  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd969  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bd96c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd96d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd96e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd96f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd970  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd971:
    // 004bd971  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd973  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bd975  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bd977  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004bd97b  e810ffffff             -call 0x4bd890
    cpu.esp -= 4;
    sub_4bd890(app, cpu);
    if (cpu.terminate) return;
    // 004bd980  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bd983  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd985  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bd987  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004bd98a  ebc5                   -jmp 0x4bd951
    goto L_0x004bd951;
L_0x004bd98c:
    // 004bd98c  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd98f  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004bd993  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bd997  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd99c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd99e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd9a1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd9a3  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bd9a9  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd9ac  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bd9af  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd9b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd9b2  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd9b5  e8c64b0000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bd9ba  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd9bd  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd9c0  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bd9c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd9c5  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bd9c8  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bd9cd  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd9cf  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd9d1  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd9d4  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004bd9d7  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004bd9da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd9dc  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd9e1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd9e4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd9e6  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bd9e9  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bd9ec  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd9ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd9f1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd9f4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd9f6  d98608010000           -fld dword ptr [esi + 0x108]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */)));
    // 004bd9fc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd9ff  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bda02  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004bda08  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004bda0b  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bda0e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bda10  746d                   -je 0x4bda7f
    if (cpu.flags.zf)
    {
        goto L_0x004bda7f;
    }
    // 004bda12  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bda15  6bd00f                 -imul edx, eax, 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bda18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bda1a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bda1d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bda1f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bda22  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004bda24  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bda26  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bda28  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bda2b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bda2c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bda2f  e84c4b0000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bda34  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bda37  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bda3a  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bda3d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bda3f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bda42  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bda44  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004bda48  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004bda4d  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004bda51  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bda54  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bda56  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004bda58  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bda5b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bda5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bda5f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bda61  7e1c                   -jle 0x4bda7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bda7f;
    }
    // 004bda63  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
L_0x004bda67:
    // 004bda67  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bda6a  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004bda6c  d95c8e2c               -fstp dword ptr [esi + ecx*4 + 0x2c]
    app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bda70  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bda73  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bda76  41                     -inc ecx
    (cpu.ecx)++;
    // 004bda77  42                     -inc edx
    (cpu.edx)++;
    // 004bda78  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bda7b  39da                   +cmp edx, ebx
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
    // 004bda7d  7ce8                   -jl 0x4bda67
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bda67;
    }
L_0x004bda7f:
    // 004bda7f  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004bda83  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bda86  e9c6feffff             -jmp 0x4bd951
    goto L_0x004bd951;
L_0x004bda8b:
    // 004bda8b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bda8e  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bda91  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bda93  894c862c               -mov dword ptr [esi + eax*4 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 4) = cpu.ecx;
    // 004bda97  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bda9a  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bda9d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdaa0  43                     -inc ebx
    (cpu.ebx)++;
    // 004bdaa1  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bdaa4  47                     -inc edi
    (cpu.edi)++;
    // 004bdaa5  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bdaa8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdaaa  7cdf                   -jl 0x4bda8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bda8b;
    }
    // 004bdaac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdaae  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bdab1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdab2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdab3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdab4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdab5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bdab8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdab8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdab9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdaba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdabb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdabc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bdabf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bdac1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bdac5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bdac7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bdac9  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bdacc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bdace  3b4128                 +cmp eax, dword ptr [ecx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdad1  7f62                   -jg 0x4bdb35
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bdb35;
    }
    // 004bdad3  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bdad7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdad9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdadb  7e1f                   -jle 0x4bdafc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdafc;
    }
    // 004bdadd  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bdae1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bdae3:
    // 004bdae3  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdae6  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004bdae9  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 004bdaeb  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdaee  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdaf1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdaf4  40                     -inc eax
    (cpu.eax)++;
    // 004bdaf5  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004bdaf8  39f8                   +cmp eax, edi
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
    // 004bdafa  7ce7                   -jl 0x4bdae3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdae3;
    }
L_0x004bdafc:
    // 004bdafc  8b6e28                 -mov ebp, dword ptr [esi + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bdaff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bdb01  39e8                   +cmp eax, ebp
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
    // 004bdb03  7d23                   -jge 0x4bdb28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdb28;
    }
    // 004bdb05  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004bdb0c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bdb0e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004bdb10:
    // 004bdb10  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 004bdb13  43                     -inc ebx
    (cpu.ebx)++;
    // 004bdb14  40                     -inc eax
    (cpu.eax)++;
    // 004bdb15  d9592c                 -fstp dword ptr [ecx + 0x2c]
    app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bdb18  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdb1b  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bdb1e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdb21  39f8                   +cmp eax, edi
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
    // 004bdb23  7ceb                   -jl 0x4bdb10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdb10;
    }
    // 004bdb25  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bdb28:
    // 004bdb28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdb2a  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bdb2d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bdb30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdb35:
    // 004bdb35  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004bdb38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdb3a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bdb3c  7e1e                   -jle 0x4bdb5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdb5c;
    }
    // 004bdb3e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bdb40:
    // 004bdb40  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdb43  d9402c                 -fld dword ptr [eax + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */)));
    // 004bdb46  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdb49  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bdb4b  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdb4e  42                     -inc edx
    (cpu.edx)++;
    // 004bdb4f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdb52  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bdb55  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bdb58  39ca                   +cmp edx, ecx
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
    // 004bdb5a  7ce4                   -jl 0x4bdb40
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdb40;
    }
L_0x004bdb5c:
    // 004bdb5c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bdb60  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bdb63  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bdb66  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdb68  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bdb6b  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bdb6d  83e81c                 -sub eax, 0x1c
    (cpu.eax) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bdb70  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bdb74  39d8                   +cmp eax, ebx
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
    // 004bdb76  0f8ec7000000           -jle 0x4bdc43
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdc43;
    }
    // 004bdb7c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
L_0x004bdb7f:
    // 004bdb7f  833c2400               +cmp dword ptr [esp], 0
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
    // 004bdb83  0f8cc2000000           -jl 0x4bdc4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdc4b;
    }
L_0x004bdb89:
    // 004bdb89  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bdb8c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bdb8f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004bdb91  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bdb98  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bdb9a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bdb9c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bdb9f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdba1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bdba3  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bdba8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdbab  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdbad  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bdbb0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdbb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdbb3  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bdbb6  e8c5490000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bdbbb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdbbe  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bdbc1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bdbc4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdbc6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bdbc8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bdbca  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bdbcd  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdbcf  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004bdbd2  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004bdbd4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdbd6  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004bdbdd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bdbdf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bdbe1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdbe3  90                     -nop 
    ;
L_0x004bdbe4:
    // 004bdbe4  7c6f                   -jl 0x4bdc55
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdc55;
    }
    // 004bdbe6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bdbe9  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bdbed  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdbf0  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bdbf3  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdbf5  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdbf7  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bdbfa  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bdbfd  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004bdc01  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdc03  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004bdc06  83f81c                 +cmp eax, 0x1c
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
    // 004bdc09  7d2e                   -jge 0x4bdc39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdc39;
    }
    // 004bdc0b  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004bdc0e  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004bdc14  d99e08010000           -fstp dword ptr [esi + 0x108]
    app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bdc1a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bdc1d  89960c010000           -mov dword ptr [esi + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 004bdc23  c700ecd84b00           -mov dword ptr [eax], 0x4bd8ec
    app->getMemory<x86::reg32>(cpu.eax) = 4970732 /*0x4bd8ec*/;
    // 004bdc29  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bdc2b  7e0c                   -jle 0x4bdc39
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdc39;
    }
    // 004bdc2d  8d5e10                 -lea ebx, [esi + 0x10]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdc30  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bdc32  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdc34  e8b3fcffff             -call 0x4bd8ec
    cpu.esp -= 4;
    sub_4bd8ec(app, cpu);
    if (cpu.terminate) return;
L_0x004bdc39:
    // 004bdc39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdc3b  83c40c                 +add esp, 0xc
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
    // 004bdc3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdc43:
    // 004bdc43  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bdc46  e934ffffff             -jmp 0x4bdb7f
    goto L_0x004bdb7f;
L_0x004bdc4b:
    // 004bdc4b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bdc4d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bdc50  e934ffffff             -jmp 0x4bdb89
    goto L_0x004bdb89;
L_0x004bdc55:
    // 004bdc55  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bdc58  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdc5a  43                     -inc ebx
    (cpu.ebx)++;
    // 004bdc5b  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004bdc5f  41                     -inc ecx
    (cpu.ecx)++;
    // 004bdc60  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bdc64  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdc67  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bdc6a  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004bdc6d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdc70  d95f2c                 -fstp dword ptr [edi + 0x2c]
    app->getMemory<float>(cpu.edi + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bdc73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bdc75  e96affffff             -jmp 0x4bdbe4
    goto L_0x004bdbe4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bdc7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdc7c  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bdc83  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bdc8a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bdc91  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bdc98  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bdc9b  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bdc9e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bdca1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bdca5  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004bdca8  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bdcac  899010010000           -mov dword ptr [eax + 0x110], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004bdcb2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bdcb6  c702b8da4b00           -mov dword ptr [edx], 0x4bdab8
    app->getMemory<x86::reg32>(cpu.edx) = 4971192 /*0x4bdab8*/;
    // 004bdcbc  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bdcc2  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 004bdcc7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bdcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdcd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdcd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdcd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdcd3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bdcd6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bdcd8  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004bdcdb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bdcdd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bdcdf  0f84b4000000           -je 0x4bdd99
    if (cpu.flags.zf)
    {
        goto L_0x004bdd99;
    }
    // 004bdce5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdce6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bdce8  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bdceb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdced  0f8e8a000000           -jle 0x4bdd7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdd7d;
    }
    // 004bdcf3  8d6810                 -lea ebp, [eax + 0x10]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bdcf6  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bdcf9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bdcfd  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bdd00  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bdd03  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bdd07  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004bdd0b:
    // 004bdd0b  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bdd0e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bdd10  0f858f000000           -jne 0x4bdda5
    if (!cpu.flags.zf)
    {
        goto L_0x004bdda5;
    }
    // 004bdd16  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bdd19  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bdd1c  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bdd1f  39d0                   +cmp eax, edx
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
    // 004bdd21  0f8d99000000           -jge 0x4bddc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bddc0;
    }
    // 004bdd27  2b561c                 -sub edx, dword ptr [esi + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004bdd2a  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bdd2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bdd31  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdd34  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdd36  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bdd38  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bdd3b  39df                   +cmp edi, ebx
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
    // 004bdd3d  7d0d                   -jge 0x4bdd4c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdd4c;
    }
    // 004bdd3f  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 004bdd42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bdd44  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdd47  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdd49  6bd81c                 -imul ebx, eax, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
L_0x004bdd4c:
    // 004bdd4c  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bdd50  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bdd55  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bdd57  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdd5a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdd5c  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bdd5f  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004bdd61  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdd63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdd64  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bdd67  e814480000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bdd6c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bdd6f  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bdd71  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bdd73  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdd76  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x004bdd79:
    // 004bdd79  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdd7b  7f8e                   -jg 0x4bdd0b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bdd0b;
    }
L_0x004bdd7d:
    // 004bdd7d  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bdd84  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdd87  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdd89  0f8cd7000000           -jl 0x4bde66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bde66;
    }
    // 004bdd8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdd91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd92  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bdd95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdd99:
    // 004bdd99  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bdd9e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bdda1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdda2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdda3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdda4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdda5:
    // 004bdda5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bdda9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bddab  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bddad  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bddaf  e8dcfaffff             -call 0x4bd890
    cpu.esp -= 4;
    sub_4bd890(app, cpu);
    if (cpu.terminate) return;
    // 004bddb4  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bddb7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bddb9  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bddbb  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bddbe  ebb9                   -jmp 0x4bdd79
    goto L_0x004bdd79;
L_0x004bddc0:
    // 004bddc0  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bddc4  744e                   -je 0x4bde14
    if (cpu.flags.zf)
    {
        goto L_0x004bde14;
    }
    // 004bddc6  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bddc9  7e49                   -jle 0x4bde14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bde14;
    }
    // 004bddcb  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bddcf  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bddd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bddd6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bddd9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdddb  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bddde  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bdde4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdde6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdde7  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bddea  e891470000             -call 0x4c2580
    cpu.esp -= 4;
    sub_4c2580(app, cpu);
    if (cpu.terminate) return;
    // 004bddef  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bddf2  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004bddf7  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bddfa  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bddfd  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bde00  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bde02  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bde05  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bde07  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004bde0a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bde0d  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bde0f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bde11  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x004bde14:
    // 004bde14  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bde18  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bde1c  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bde22  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bde25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bde27  751d                   -jne 0x4bde46
    if (!cpu.flags.zf)
    {
        goto L_0x004bde46;
    }
L_0x004bde29:
    // 004bde29  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bde2b  0f8e48ffffff           -jle 0x4bdd79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdd79;
    }
    // 004bde31  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bde34  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bde3a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bde3d  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bde40  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bde41  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bde44  ebe3                   -jmp 0x4bde29
    goto L_0x004bde29;
L_0x004bde46:
    // 004bde46  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004bde48  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bde4b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bde4e  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 004bde51  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bde58  83c208                 +add edx, 8
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
    // 004bde5b  d95e08                 +fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bde5e  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bde61  e913ffffff             -jmp 0x4bdd79
    goto L_0x004bdd79;
L_0x004bde66:
    // 004bde66  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bde69  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bde6c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bde6e  894c8624               -mov dword ptr [esi + eax*4 + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.ecx;
    // 004bde72  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bde75  8b6e20                 -mov ebp, dword ptr [esi + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bde78  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bde7b  45                     -inc ebp
    (cpu.ebp)++;
    // 004bde7c  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004bde7f  47                     -inc edi
    (cpu.edi)++;
    // 004bde80  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004bde83  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bde85  7cdf                   -jl 0x4bde66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bde66;
    }
    // 004bde87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bde89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde8a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bde8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bde94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bde94  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004bde9b  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bdea2  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bdea9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bdeb0  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bdeb7  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bdeba  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bdebe  c700d0dc4b00           -mov dword ptr [eax], 0x4bdcd0
    app->getMemory<x86::reg32>(cpu.eax) = 4971728 /*0x4bdcd0*/;
    // 004bdec4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bdec8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bdece  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bded3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bdee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdee0  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bdee3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bdee4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdee4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdee5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdee6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdee7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdee8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bdeea  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bdeec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bdeee  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004bdef1  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004bdef4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bdef6  39fa                   +cmp edx, edi
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
    // 004bdef8  0f8d68000000           -jge 0x4bdf66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdf66;
    }
    // 004bdefe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bdf00  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004bdf03  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004bdf06  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bdf08  39c6                   +cmp esi, eax
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
    // 004bdf0a  7f64                   -jg 0x4bdf70
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bdf70;
    }
    // 004bdf0c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bdf0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdf10  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bdf12  7e1c                   -jle 0x4bdf30
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdf30;
    }
    // 004bdf14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bdf16:
    // 004bdf16  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bdf19  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004bdf1c  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004bdf1e  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bdf21  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdf24  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdf27  42                     -inc edx
    (cpu.edx)++;
    // 004bdf28  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004bdf2b  39f2                   +cmp edx, esi
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
    // 004bdf2d  7ce7                   -jl 0x4bdf16
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdf16;
    }
    // 004bdf2f  90                     -nop 
    ;
L_0x004bdf30:
    // 004bdf30  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bdf33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bdf35  39f2                   +cmp edx, esi
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
    // 004bdf37  7d23                   -jge 0x4bdf5c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdf5c;
    }
    // 004bdf39  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 004bdf40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bdf42  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bdf44:
    // 004bdf44  d9462c                 -fld dword ptr [esi + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */)));
    // 004bdf47  41                     -inc ecx
    (cpu.ecx)++;
    // 004bdf48  42                     -inc edx
    (cpu.edx)++;
    // 004bdf49  d9582c                 -fstp dword ptr [eax + 0x2c]
    app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bdf4c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdf4f  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bdf52  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdf55  39fa                   +cmp edx, edi
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
    // 004bdf57  7ceb                   -jl 0x4bdf44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdf44;
    }
    // 004bdf59  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bdf5c:
    // 004bdf5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdf5e  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bdf61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdf66:
    // 004bdf66  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bdf6b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdf70:
    // 004bdf70  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004bdf73  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdf75  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bdf77  7e1f                   -jle 0x4bdf98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdf98;
    }
    // 004bdf79  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bdf7b:
    // 004bdf7b  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bdf7e  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 004bdf81  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdf84  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bdf86  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bdf89  40                     -inc eax
    (cpu.eax)++;
    // 004bdf8a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdf8d  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bdf90  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004bdf93  39f8                   +cmp eax, edi
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
    // 004bdf95  7ce4                   -jl 0x4bdf7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bdf7b;
    }
    // 004bdf97  90                     -nop 
    ;
L_0x004bdf98:
    // 004bdf98  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bdf9b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bdf9d  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bdfa0  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdfa2  2b6b24                 -sub ebp, dword ptr [ebx + 0x24]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 004bdfa5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bdfa7  0f8c7a000000           -jl 0x4be027
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be027;
    }
L_0x004bdfad:
    // 004bdfad  39ee                   +cmp esi, ebp
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
    // 004bdfaf  0f8d76000000           -jge 0x4be02b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be02b;
    }
    // 004bdfb5  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004bdfb7:
    // 004bdfb7  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004bdfba  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdfbc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bdfbe  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004bdfc1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdfc3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bdfc5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bdfca  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdfcd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdfcf  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bdfd2  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004bdfd4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bdfd6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bdfd7  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bdfda  e889460000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004bdfdf  8b5324                 -mov edx, dword ptr [ebx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004bdfe2  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bdfe4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bdfe6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdfe8  895324                 -mov dword ptr [ebx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004bdfeb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdfed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bdff0  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004bdff3  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdff5  7538                   -jne 0x4be02f
    if (!cpu.flags.zf)
    {
        goto L_0x004be02f;
    }
    // 004bdff7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bdff9  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bdffb  2b4320                 -sub eax, dword ptr [ebx + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 004bdffe  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be000  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004be002  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004be004  7e1a                   -jle 0x4be020
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be020;
    }
L_0x004be006:
    // 004be006  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004be009  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004be00f  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004be012  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be015  4e                     -dec esi
    (cpu.esi)--;
    // 004be016  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004be019  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004be01b  7fe9                   -jg 0x4be006
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be006;
    }
    // 004be01d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004be020:
    // 004be020  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be022  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be023  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be025  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be026  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be027:
    // 004be027  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004be029  eb82                   -jmp 0x4bdfad
    goto L_0x004bdfad;
L_0x004be02b:
    // 004be02b  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004be02d  eb88                   -jmp 0x4bdfb7
    goto L_0x004bdfb7;
L_0x004be02f:
    // 004be02f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004be034  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004be036  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004be038  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be03b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be03d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004be03f  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be041  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004be044  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be047  7502                   -jne 0x4be04b
    if (!cpu.flags.zf)
    {
        goto L_0x004be04b;
    }
    // 004be049  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004be04b:
    // 004be04b  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004be04d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be04f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004be051  7c0a                   -jl 0x4be05d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be05d;
    }
    // 004be053  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004be056  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be058  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be059  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be05a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be05b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be05c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be05d:
    // 004be05d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004be05f  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
L_0x004be066:
    // 004be066  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be069  46                     -inc esi
    (cpu.esi)++;
    // 004be06a  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004be06d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be070  41                     -inc ecx
    (cpu.ecx)++;
    // 004be071  8b6c3afc               -mov ebp, dword ptr [edx + edi - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 004be075  896828                 -mov dword ptr [eax + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004be078  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004be07a  7cea                   -jl 0x4be066
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be066;
    }
    // 004be07c  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004be07f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be081  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be082  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be083  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4be088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be088  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004be08f  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004be096  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004be09d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004be0a4  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004be0ab  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004be0b2  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004be0b5  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004be0b8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004be0bc  c700e4de4b00           -mov dword ptr [eax], 0x4bdee4
    app->getMemory<x86::reg32>(cpu.eax) = 4972260 /*0x4bdee4*/;
    // 004be0c2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004be0c6  c700e0de4b00           -mov dword ptr [eax], 0x4bdee0
    app->getMemory<x86::reg32>(cpu.eax) = 4972256 /*0x4bdee0*/;
    // 004be0cc  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 004be0d1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4be0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be0e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be0e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be0e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be0e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be0e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be0e8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004be0eb  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004be0ed  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004be0ef  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004be0f1  39d8                   +cmp eax, ebx
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
    // 004be0f3  7d02                   -jge 0x4be0f7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be0f7;
    }
    // 004be0f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004be0f7:
    // 004be0f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be0f9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be0fb  7e1f                   -jle 0x4be11c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be11c;
    }
    // 004be0fd  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004be100:
    // 004be100  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004be102  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be105  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be108  40                     -inc eax
    (cpu.eax)++;
    // 004be109  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be10c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be10f  8b59fc                 -mov ebx, dword ptr [ecx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004be112  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004be115  39f8                   +cmp eax, edi
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
    // 004be117  7ce7                   -jl 0x4be100
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be100;
    }
    // 004be119  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004be11c:
    // 004be11c  39f0                   +cmp eax, esi
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
    // 004be11e  7d24                   -jge 0x4be144
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be144;
    }
    // 004be120  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004be123  8d1cc500000000         -lea ebx, [eax*8]
    cpu.ebx = x86::reg32(cpu.eax * 8);
    // 004be12a  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004be12c:
    // 004be12c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004be12e  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be131  40                     -inc eax
    (cpu.eax)++;
    // 004be132  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be134  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be137  d943fc                 -fld dword ptr [ebx - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */)));
    // 004be13a  d959fc                 -fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be13d  39f0                   +cmp eax, esi
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
    // 004be13f  7ceb                   -jl 0x4be12c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be12c;
    }
    // 004be141  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004be144:
    // 004be144  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004be146  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 004be149  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be14c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be14d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be14e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be14f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be150  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be151  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be152  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be153  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be154  81ecec000000           -sub esp, 0xec
    (cpu.esp) -= x86::reg32(x86::sreg32(236 /*0xec*/));
    // 004be15a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004be15c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004be15e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be160  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004be163  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be165  7e5c                   -jle 0x4be1c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be1c3;
    }
    // 004be167  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004be16a  899424e4000000         -mov dword ptr [esp + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 004be171  8d6834                 -lea ebp, [eax + 0x34]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
L_0x004be174:
    // 004be174  66837e3000             +cmp word ptr [esi + 0x30], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004be179  756a                   -jne 0x4be1e5
    if (!cpu.flags.zf)
    {
        goto L_0x004be1e5;
    }
    // 004be17b  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be17e  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004be181  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004be184  39c8                   +cmp eax, ecx
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
    // 004be186  0f8d7d000000           -jge 0x4be209
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be209;
    }
    // 004be18c  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004be190  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004be195  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be197  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be19a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be19c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be19f  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004be1a5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be1a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be1a8  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004be1ab  e8b8440000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004be1b0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be1b3  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be1b6  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be1b9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be1bc  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004be1bf:
    // 004be1bf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be1c1  7fb1                   -jg 0x4be174
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be174;
    }
L_0x004be1c3:
    // 004be1c3  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004be1ca  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be1cd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004be1d0:
    // 004be1d0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be1d2  0f8c6c010000           -jl 0x4be344
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be344;
    }
    // 004be1d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be1da  81c4ec000000           -add esp, 0xec
    (cpu.esp) += x86::reg32(x86::sreg32(236 /*0xec*/));
    // 004be1e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be1e5:
    // 004be1e5  8b8c24e4000000         -mov ecx, dword ptr [esp + 0xe4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 004be1ec  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004be1ee  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be1f1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004be1f3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004be1f6  e8e5feffff             -call 0x4be0e0
    cpu.esp -= 4;
    sub_4be0e0(app, cpu);
    if (cpu.terminate) return;
    // 004be1fb  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004be1ff  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be201  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004be203  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004be207  ebb6                   -jmp 0x4be1bf
    goto L_0x004be1bf;
L_0x004be209:
    // 004be209  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004be20d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be210  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004be215  898424e0000000         -mov dword ptr [esp + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 004be21c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be21e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be221  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be223  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004be229  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be22c  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004be22f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be231  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be232  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004be235  e82e440000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004be23a  8346241c               -add dword ptr [esi + 0x24], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be23e  668b5e2c               -mov bx, word ptr [esi + 0x2c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004be242  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be246  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004be24b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be24d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be24f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004be251  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be254  66895630               -mov word ptr [esi + 0x30], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 004be258  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be25a  41                     -inc ecx
    (cpu.ecx)++;
    // 004be25b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be25e  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 004be262  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004be267  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be269  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004be26c  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004be26f  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be272  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be274  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be277  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be279  d986ec010000           -fld dword ptr [esi + 0x1ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */)));
    // 004be27f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be282  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be285  8b86f0010000           -mov eax, dword ptr [esi + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */);
    // 004be28b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004be28e  8b86f4010000           -mov eax, dword ptr [esi + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */);
    // 004be294  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004be297  8b86f8010000           -mov eax, dword ptr [esi + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */);
    // 004be29d  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004be2a0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004be2a2  0f848d000000           -je 0x4be335
    if (cpu.flags.zf)
    {
        goto L_0x004be335;
    }
    // 004be2a8  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004be2aa  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004be2ae  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004be2b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be2b5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be2b8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be2ba  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be2bd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be2bf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004be2c1  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004be2c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be2c5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004be2c8  e89b430000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004be2cd  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be2d0  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be2d3  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be2d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004be2d8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be2db  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be2dd  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004be2e2  898424e8000000         -mov dword ptr [esp + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 004be2e9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be2eb  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004be2ee  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be2f0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004be2f2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004be2f5  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 004be2fc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004be2fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be300  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004be302  7e31                   -jle 0x4be335
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be335;
    }
L_0x004be304:
    // 004be304  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be307  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004be30a  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004be30c  895cce34               -mov dword ptr [esi + ecx*8 + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.ecx * 8) = cpu.ebx;
    // 004be310  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be313  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be316  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004be319  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004be31c  895cce38               -mov dword ptr [esi + ecx*8 + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.ecx * 8) = cpu.ebx;
    // 004be320  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004be324  42                     -inc edx
    (cpu.edx)++;
    // 004be325  43                     -inc ebx
    (cpu.ebx)++;
    // 004be326  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 004be32d  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004be331  39ca                   +cmp edx, ecx
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
    // 004be333  7ccf                   -jl 0x4be304
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be304;
    }
L_0x004be335:
    // 004be335  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 004be33c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004be33f  e97bfeffff             -jmp 0x4be1bf
    goto L_0x004be1bf;
L_0x004be344:
    // 004be344  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be347  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be34a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004be34d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004be34f  894cd634               -mov dword ptr [esi + edx*8 + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.edx * 8) = cpu.ecx;
    // 004be353  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be356  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be359  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004be35c  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004be35f  894cc638               -mov dword ptr [esi + eax*8 + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.eax * 8) = cpu.ecx;
    // 004be363  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be366  668b4e30               -mov cx, word ptr [esi + 0x30]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004be36a  83c208                 +add edx, 8
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
    // 004be36d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be36e  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004be371  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be372  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 004be376  e955feffff             -jmp 0x4be1d0
    goto L_0x004be1d0;
}

/* align: skip 0x90 */
void Application::sub_4be37c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be37c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be37d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be37e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be37f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be380  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be383  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004be386  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004be388  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004be38b  8b502e                 -mov edx, dword ptr [eax + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004be38e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004be391  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004be394  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be396  39ca                   +cmp edx, ecx
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
    // 004be398  7d34                   -jge 0x4be3ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be3ce;
    }
    // 004be39a  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004be39f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004be3a1:
    // 004be3a1  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be3a4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004be3a7  39d3                   +cmp ebx, edx
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
    // 004be3a9  0f8d8a000000           -jge 0x4be439
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be439;
    }
    // 004be3af  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be3b2  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004be3b5  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004be3b7  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be3ba  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004be3bd  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004be3c0  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be3c3  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be3c6  01fd                   +add ebp, edi
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
    // 004be3c8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be3c9  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004be3cc  ebd3                   -jmp 0x4be3a1
    goto L_0x004be3a1;
L_0x004be3ce:
    // 004be3ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be3d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004be3d2  7e28                   -jle 0x4be3fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be3fc;
    }
    // 004be3d4  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x004be3d7:
    // 004be3d7  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be3da  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004be3dd  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004be3df  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be3e2  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004be3e5  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004be3e8  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be3eb  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be3ee  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be3f1  43                     -inc ebx
    (cpu.ebx)++;
    // 004be3f2  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004be3f5  39eb                   +cmp ebx, ebp
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
    // 004be3f7  7cde                   -jl 0x4be3d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be3d7;
    }
    // 004be3f9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004be3fc:
    // 004be3fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004be3fe  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 004be405  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004be407  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004be409:
    // 004be409  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004be40c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004be40f  39cb                   +cmp ebx, ecx
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
    // 004be411  7d16                   -jge 0x4be429
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be429;
    }
    // 004be413  d94234                 -fld dword ptr [edx + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(52) /* 0x34 */)));
    // 004be416  47                     -inc edi
    (cpu.edi)++;
    // 004be417  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be41a  43                     -inc ebx
    (cpu.ebx)++;
    // 004be41b  d95834                 -fstp dword ptr [eax + 0x34]
    app->getMemory<float>(cpu.eax + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be41e  83c008                 +add eax, 8
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
    // 004be421  8b4a30                 -mov ecx, dword ptr [edx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004be424  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004be427  ebe0                   -jmp 0x4be409
    goto L_0x004be409;
L_0x004be429:
    // 004be429  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be42b  66897e30               -mov word ptr [esi + 0x30], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 004be42f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be431  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be434  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be435  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be436  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be437  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be438  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be439:
    // 004be439  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be43c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be43f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004be442  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be444  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be446  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be449  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004be44c  39ef                   +cmp edi, ebp
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
    // 004be44e  7e02                   -jle 0x4be452
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be452;
    }
    // 004be450  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004be452:
    // 004be452  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be454  0f8cc8000000           -jl 0x4be522
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be522;
    }
L_0x004be45a:
    // 004be45a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be45d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be45f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be461  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004be464  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be466  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be468  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004be46d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be470  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be472  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be475  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004be477  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be479  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be47a  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004be47d  e8e6410000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004be482  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be485  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be488  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004be48a  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be48c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be48e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004be490  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004be493  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be495  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004be497  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004be49a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004be49e  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004be4a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be4a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004be4a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004be4ab  90                     -nop 
    ;
L_0x004be4ac:
    // 004be4ac  0f8c77000000           -jl 0x4be529
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be529;
    }
    // 004be4b2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004be4b5  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be4b8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004be4ba  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be4bc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004be4bf  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be4c2  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be4c5  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004be4c9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be4cb  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004be4ce  83f81c                 +cmp eax, 0x1c
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
    // 004be4d1  7d43                   -jge 0x4be516
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be516;
    }
    // 004be4d3  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004be4d6  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004be4d9  8b86fc010000           -mov eax, dword ptr [esi + 0x1fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(508) /* 0x1fc */);
    // 004be4df  d99eec010000           -fstp dword ptr [esi + 0x1ec]
    app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4e5  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004be4e8  8996f0010000           -mov dword ptr [esi + 0x1f0], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */) = cpu.edx;
    // 004be4ee  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004be4f1  8996f4010000           -mov dword ptr [esi + 0x1f4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */) = cpu.edx;
    // 004be4f7  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004be4fa  8996f8010000           -mov dword ptr [esi + 0x1f8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */) = cpu.edx;
    // 004be500  c70050e14b00           -mov dword ptr [eax], 0x4be150
    app->getMemory<x86::reg32>(cpu.eax) = 4972880 /*0x4be150*/;
    // 004be506  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004be508  7e0c                   -jle 0x4be516
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be516;
    }
    // 004be50a  8d5e18                 -lea ebx, [esi + 0x18]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be50d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be50f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004be511  e83afcffff             -call 0x4be150
    cpu.esp -= 4;
    sub_4be150(app, cpu);
    if (cpu.terminate) return;
L_0x004be516:
    // 004be516  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be518  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be51a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be51d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be51e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be51f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be520  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be521  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be522:
    // 004be522  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004be524  e931ffffff             -jmp 0x4be45a
    goto L_0x004be45a;
L_0x004be529:
    // 004be529  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be52c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be52e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004be532  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004be536  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004be539  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004be53c  d95934                 -fstp dword ptr [ecx + 0x34]
    app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be53f  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be542  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be544  43                     -inc ebx
    (cpu.ebx)++;
    // 004be545  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be548  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004be54b  d95938                 -fstp dword ptr [ecx + 0x38]
    app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be54e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004be552  41                     -inc ecx
    (cpu.ecx)++;
    // 004be553  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be556  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004be55a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004be55c  e94bffffff             -jmp 0x4be4ac
    goto L_0x004be4ac;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4be564(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be564  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004be56b  66c740300000           -mov word ptr [eax + 0x30], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004be571  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004be578  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004be57f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004be586  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004be58d  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004be590  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004be593  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004be596  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004be59a  89502c                 -mov dword ptr [eax + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004be59d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004be5a1  8990fc010000           -mov dword ptr [eax + 0x1fc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(508) /* 0x1fc */) = cpu.edx;
    // 004be5a7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004be5ab  c7027ce34b00           -mov dword ptr [edx], 0x4be37c
    app->getMemory<x86::reg32>(cpu.edx) = 4973436 /*0x4be37c*/;
    // 004be5b1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004be5b7  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 004be5bc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4be5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be5c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be5c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be5c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be5c3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be5c6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004be5c8  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004be5cb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be5cd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004be5cf  0f848d000000           -je 0x4be662
    if (cpu.flags.zf)
    {
        goto L_0x004be662;
    }
    // 004be5d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be5d6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004be5d8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004be5db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be5dd  7e67                   -jle 0x4be646
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be646;
    }
    // 004be5df  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004be5e2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004be5e6  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004be5e9  8d6820                 -lea ebp, [eax + 0x20]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004be5ec  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be5ef  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004be5f3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004be5f7:
    // 004be5f7  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be5fa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004be5fc  756b                   -jne 0x4be669
    if (!cpu.flags.zf)
    {
        goto L_0x004be669;
    }
    // 004be5fe  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be601  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004be604  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004be607  39d0                   +cmp eax, edx
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
    // 004be609  0f8d77000000           -jge 0x4be686
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be686;
    }
    // 004be60f  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004be613  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004be618  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be61a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be61d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be61f  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be622  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004be628  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be62a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be62b  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004be62e  e835400000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004be633  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be636  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be639  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004be63c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be63f  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x004be642:
    // 004be642  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be644  7fb1                   -jg 0x4be5f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be5f7;
    }
L_0x004be646:
    // 004be646  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004be64d  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be650  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be652  0f8ce0000000           -jl 0x4be738
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be738;
    }
    // 004be658  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be65a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004be65b:
    // 004be65b  83c40c                 +add esp, 0xc
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
    // 004be65e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be65f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be661  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be662:
    // 004be662  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004be667  ebf2                   -jmp 0x4be65b
    goto L_0x004be65b;
L_0x004be669:
    // 004be669  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004be66d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004be671  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004be673  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004be675  e866faffff             -call 0x4be0e0
    cpu.esp -= 4;
    sub_4be0e0(app, cpu);
    if (cpu.terminate) return;
    // 004be67a  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be67d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be67f  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004be681  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004be684  ebbc                   -jmp 0x4be642
    goto L_0x004be642;
L_0x004be686:
    // 004be686  837e1c01               +cmp dword ptr [esi + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be68a  7445                   -je 0x4be6d1
    if (cpu.flags.zf)
    {
        goto L_0x004be6d1;
    }
    // 004be68c  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004be690  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004be695  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be697  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be69a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be69c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be69f  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004be6a5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be6a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be6a8  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004be6ab  e8b83f0000             -call 0x4c2668
    cpu.esp -= 4;
    sub_4c2668(app, cpu);
    if (cpu.terminate) return;
    // 004be6b0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004be6b3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004be6b5  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004be6b8  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004be6bb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be6bd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004be6bf  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be6c2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be6c4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004be6c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be6ca  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be6cc  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be6ce  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004be6d1:
    // 004be6d1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004be6d5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004be6d7  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004be6dd  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be6e0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004be6e2  742e                   -je 0x4be712
    if (cpu.flags.zf)
    {
        goto L_0x004be712;
    }
    // 004be6e4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004be6e6  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004be6e8  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be6eb  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 004be6ee  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be6f1  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004be6f4  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be6f7  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 004be6fa  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004be6fd  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004be704  83c008                 +add eax, 8
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
    // 004be707  d95e10                 +fstp dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be70a  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004be70d  e930ffffff             -jmp 0x4be642
    goto L_0x004be642;
L_0x004be712:
    // 004be712  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be714  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be716  0f8e26ffffff           -jle 0x4be642
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be642;
    }
L_0x004be71c:
    // 004be71c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be71f  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004be725  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be728  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be72b  4f                     -dec edi
    (cpu.edi)--;
    // 004be72c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004be72f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be731  7fe9                   -jg 0x4be71c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be71c;
    }
    // 004be733  e90affffff             -jmp 0x4be642
    goto L_0x004be642;
L_0x004be738:
    // 004be738  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be73b  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be73e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004be740  894cc62c               -mov dword ptr [esi + eax*8 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.ecx;
    // 004be744  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be747  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be74a  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004be74d  894cd630               -mov dword ptr [esi + edx*8 + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */ + cpu.edx * 8) = cpu.ecx;
    // 004be751  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004be754  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004be757  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be75a  43                     -inc ebx
    (cpu.ebx)++;
    // 004be75b  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004be75e  47                     -inc edi
    (cpu.edi)++;
    // 004be75f  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004be762  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be764  7cd2                   -jl 0x4be738
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be738;
    }
    // 004be766  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be768  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be769  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be76c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be76d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be76e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be76f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be770  c7401c01000000         -mov dword ptr [eax + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004be777  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004be77e  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004be785  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004be78c  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004be793  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004be79a  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004be7a1  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004be7a4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004be7a8  c700c0e54b00           -mov dword ptr [eax], 0x4be5c0
    app->getMemory<x86::reg32>(cpu.eax) = 4974016 /*0x4be5c0*/;
    // 004be7ae  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004be7b2  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004be7b8  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 004be7bd  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4be7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be7c0  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004be7c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4be7c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be7c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be7c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be7ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be7cb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004be7cd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004be7cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be7d1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be7d3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004be7d5  7e34                   -jle 0x4be80b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be80b;
    }
    // 004be7d7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004be7d9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004be7db:
    // 004be7db  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004be7dd  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 004be7e2  3dff7f0000             +cmp eax, 0x7fff
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
    // 004be7e7  7613                   -jbe 0x4be7fc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004be7fc;
    }
    // 004be7e9  3d00800100             +cmp eax, 0x18000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98304 /*0x18000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be7ee  730c                   -jae 0x4be7fc
    if (!cpu.flags.cf)
    {
        goto L_0x004be7fc;
    }
    // 004be7f0  3d00000100             +cmp eax, 0x10000
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
    // 004be7f5  7318                   -jae 0x4be80f
    if (!cpu.flags.cf)
    {
        goto L_0x004be80f;
    }
    // 004be7f7  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
L_0x004be7fc:
    // 004be7fc  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004be7ff  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be802  41                     -inc ecx
    (cpu.ecx)++;
    // 004be803  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004be807  39f1                   +cmp ecx, esi
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
    // 004be809  7cd0                   -jl 0x4be7db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be7db;
    }
L_0x004be80b:
    // 004be80b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be80c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be80d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be80e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be80f:
    // 004be80f  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 004be814  ebe6                   -jmp 0x4be7fc
    goto L_0x004be7fc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4be818(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be818  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be819  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be81a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be81b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be81e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004be820  8b884c0d0000           -mov ecx, dword ptr [eax + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004be826  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004be82c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004be82e  39d1                   +cmp ecx, edx
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
    // 004be830  0f83eb000000           -jae 0x4be921
    if (!cpu.flags.cf)
    {
        goto L_0x004be921;
    }
    // 004be836  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be837  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004be839  8b984c0d0000           -mov ebx, dword ptr [eax + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004be83f  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004be841  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004be847  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004be849  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be84b  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004be851  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004be855  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004be857  0f8ed0000000           -jle 0x4be92d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be92d;
    }
    // 004be85d  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004be85f:
    // 004be85f  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004be865  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be867  7d02                   -jge 0x4be86b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be86b;
    }
    // 004be869  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004be86b:
    // 004be86b  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004be870  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004be876  8d9f84060000           -lea ebx, [edi + 0x684]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 004be87c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be87e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004be882  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004be885  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be887  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004be889  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004be88b  e838ffffff             -call 0x4be7c8
    cpu.esp -= 4;
    sub_4be7c8(app, cpu);
    if (cpu.terminate) return;
    // 004be890  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004be893  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be895  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004be89b  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004be89d  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004be89f  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004be8a5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004be8a7  7e5f                   -jle 0x4be908
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be908;
    }
    // 004be8a9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004be8ad  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004be8b1:
    // 004be8b1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004be8b6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004be8b8  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004be8bd  e83e4b0000             -call 0x4c3400
    cpu.esp -= 4;
    sub_4c3400(app, cpu);
    if (cpu.terminate) return;
    // 004be8c2  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 004be8cc  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be8ce  7d02                   -jge 0x4be8d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be8d2;
    }
    // 004be8d0  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004be8d2:
    // 004be8d2  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004be8d7  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 004be8dd  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004be8e1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004be8e4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be8e6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004be8e8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004be8ea  e8d9feffff             -call 0x4be7c8
    cpu.esp -= 4;
    sub_4be7c8(app, cpu);
    if (cpu.terminate) return;
    // 004be8ef  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004be8f2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be8f4  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004be8fa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004be8fc  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004be8fe  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004be904  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004be906  7fa9                   -jg 0x4be8b1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be8b1;
    }
L_0x004be908:
    // 004be908  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be90a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004be90b:
    // 004be90b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004be90e  39d0                   +cmp eax, edx
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
    // 004be910  7d26                   -jge 0x4be938
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be938;
    }
    // 004be912  83c102                 +add ecx, 2
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
    // 004be915  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004be918  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004be91c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004be91f  ebea                   -jmp 0x4be90b
    goto L_0x004be90b;
L_0x004be921:
    // 004be921  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004be926  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be929  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be92a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be92b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be92c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be92d:
    // 004be92d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004be92f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004be933  e927ffffff             -jmp 0x4be85f
    goto L_0x004be85f;
L_0x004be938:
    // 004be938  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be93a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be93d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be93e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be93f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be940  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4be944(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be944  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be945  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be947  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be949  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004be94b  e8c4490000             -call 0x4c3314
    cpu.esp -= 4;
    sub_4c3314(app, cpu);
    if (cpu.terminate) return;
    // 004be950  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004be95a  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004be964  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004be968  899e440d0000           -mov dword ptr [esi + 0xd44], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ebx;
    // 004be96e  c70018e84b00           -mov dword ptr [eax], 0x4be818
    app->getMemory<x86::reg32>(cpu.eax) = 4974616 /*0x4be818*/;
    // 004be974  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004be978  c700c0e74b00           -mov dword ptr [eax], 0x4be7c0
    app->getMemory<x86::reg32>(cpu.eax) = 4974528 /*0x4be7c0*/;
    // 004be97e  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 004be983  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be984  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4be990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be991  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be992  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be993  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be994  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004be997  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004be999  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004be99f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004be9a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004be9a3  0f84b5000000           -je 0x4bea5e
    if (cpu.flags.zf)
    {
        goto L_0x004bea5e;
    }
    // 004be9a9  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004be9ab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004be9ad  0f8ea1000000           -jle 0x4bea54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bea54;
    }
    // 004be9b3  8d9884060000           -lea ebx, [eax + 0x684]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1668) /* 0x684 */);
    // 004be9b9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004be9bd  8d98480d0000           -lea ebx, [eax + 0xd48]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(3400) /* 0xd48 */);
    // 004be9c3  05440d0000             -add eax, 0xd44
    (cpu.eax) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 004be9c8  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004be9cc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004be9cf:
    // 004be9cf  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 004be9d5  3b81480d0000           +cmp eax, dword ptr [ecx + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be9db  0f8d8a000000           -jge 0x4bea6b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bea6b;
    }
L_0x004be9e1:
    // 004be9e1  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be9e8  0f8e0f010000           -jle 0x4beafd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004beafd;
    }
L_0x004be9ee:
    // 004be9ee  8bb1480d0000           -mov esi, dword ptr [ecx + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 004be9f4  2bb14c0d0000           -sub esi, dword ptr [ecx + 0xd4c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */)));
    // 004be9fa  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be9fc  7d02                   -jge 0x4bea00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bea00;
    }
    // 004be9fe  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004bea00:
    // 004bea00  8b91500d0000           -mov edx, dword ptr [ecx + 0xd50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 004bea06  39d6                   +cmp esi, edx
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
    // 004bea08  7e02                   -jle 0x4bea0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bea0c;
    }
    // 004bea0a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004bea0c:
    // 004bea0c  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bea11  2b81500d0000           -sub eax, dword ptr [ecx + 0xd50]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */)));
    // 004bea17  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bea1b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bea1e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bea20  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bea22  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bea24  e89ffdffff             -call 0x4be7c8
    cpu.esp -= 4;
    sub_4be7c8(app, cpu);
    if (cpu.terminate) return;
    // 004bea29  8b994c0d0000           -mov ebx, dword ptr [ecx + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 004bea2f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bea31  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004bea34  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bea36  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 004bea3c  89994c0d0000           -mov dword ptr [ecx + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004bea42  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bea44  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bea46  8981500d0000           -mov dword ptr [ecx + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 004bea4c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bea4e  0f8f7bffffff           -jg 0x4be9cf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be9cf;
    }
L_0x004bea54:
    // 004bea54  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bea56  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bea59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bea5e:
    // 004bea5e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bea63  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bea66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bea6b:
    // 004bea6b  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bea6f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bea72  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bea78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bea7a  752b                   -jne 0x4beaa7
    if (!cpu.flags.zf)
    {
        goto L_0x004beaa7;
    }
    // 004bea7c  8b99440d0000           -mov ebx, dword ptr [ecx + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 004bea82  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bea84  7421                   -je 0x4beaa7
    if (cpu.flags.zf)
    {
        goto L_0x004beaa7;
    }
    // 004bea86  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bea88  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bea8a  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004bea8c  7443                   -je 0x4bead1
    if (cpu.flags.zf)
    {
        goto L_0x004bead1;
    }
    // 004bea8e  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bea91  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bea93  e87c480000             -call 0x4c3314
    cpu.esp -= 4;
    sub_4c3314(app, cpu);
    if (cpu.terminate) return;
    // 004bea98  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004beaa2  e93affffff             -jmp 0x4be9e1
    goto L_0x004be9e1;
L_0x004beaa7:
    // 004beaa7  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004beaaa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004beaac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004beaae  e87c3bfdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004beab3  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004beabd  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004beac7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004beac9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004beacc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beacd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beace  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beacf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bead0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bead1:
    // 004bead1  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bead4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bead9  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004beadc  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 004beae2  c7410808000000         -mov dword ptr [ecx + 8], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004beae9  83c002                 +add eax, 2
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
    // 004beaec  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004beaee  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004beaf8  e9e4feffff             -jmp 0x4be9e1
    goto L_0x004be9e1;
L_0x004beafd:
    // 004beafd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004beb02  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004beb04  e8f7480000             -call 0x4c3400
    cpu.esp -= 4;
    sub_4c3400(app, cpu);
    if (cpu.terminate) return;
    // 004beb09  c781500d0000b0010000   -mov dword ptr [ecx + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 004beb13  e9d6feffff             -jmp 0x4be9ee
    goto L_0x004be9ee;
}

/* align: skip  */
void Application::sub_4beb18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb18  c780440d000001000000   -mov dword ptr [eax + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 004beb22  c780480d000000000000   -mov dword ptr [eax + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004beb2c  c7804c0d000000000000   -mov dword ptr [eax + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004beb36  c780500d000000000000   -mov dword ptr [eax + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 004beb40  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004beb44  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004beb4a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004beb4e  c70090e94b00           -mov dword ptr [eax], 0x4be990
    app->getMemory<x86::reg32>(cpu.eax) = 4974992 /*0x4be990*/;
    // 004beb54  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 004beb59  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4beb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb60  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004beb66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4beb68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004beb69  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004beb6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004beb6d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004beb6f  7e13                   -jle 0x4beb84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004beb84;
    }
L_0x004beb71:
    // 004beb71  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004beb73  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004beb76  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004beb79  40                     -inc eax
    (cpu.eax)++;
    // 004beb7a  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004beb7d  39d8                   +cmp eax, ebx
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
    // 004beb7f  7cf0                   -jl 0x4beb71
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004beb71;
    }
    // 004beb81  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004beb84:
    // 004beb84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4beb88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004beb89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004beb8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beb8b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004beb8e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004beb90  8b884c0d0000           -mov ecx, dword ptr [eax + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004beb96  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004beb9c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004beb9e  39d1                   +cmp ecx, edx
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
    // 004beba0  0f83f2000000           -jae 0x4bec98
    if (!cpu.flags.cf)
    {
        goto L_0x004bec98;
    }
    // 004beba6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004beba7  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004beba9  8b984c0d0000           -mov ebx, dword ptr [eax + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bebaf  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bebb1  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bebb7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bebb9  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bebbb  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004bebc1  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004bebc5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bebc7  0f8ed7000000           -jle 0x4beca4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004beca4;
    }
    // 004bebcd  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bebcf:
    // 004bebcf  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bebd5  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bebd7  7d02                   -jge 0x4bebdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bebdb;
    }
    // 004bebd9  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004bebdb:
    // 004bebdb  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bebe0  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bebe6  8d9f84060000           -lea ebx, [edi + 0x684]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 004bebec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bebee  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bebf2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bebf5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bebf7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bebf9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bebfb  e868ffffff             -call 0x4beb68
    cpu.esp -= 4;
    sub_4beb68(app, cpu);
    if (cpu.terminate) return;
    // 004bec00  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004bec07  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bec09  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bec0f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bec11  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bec13  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004bec19  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bec1b  7e60                   -jle 0x4bec7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bec7d;
    }
    // 004bec1d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bec21  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004bec25:
    // 004bec25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bec27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bec29  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004bec2e  e8cd470000             -call 0x4c3400
    cpu.esp -= 4;
    sub_4c3400(app, cpu);
    if (cpu.terminate) return;
    // 004bec33  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 004bec3d  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bec3f  7d02                   -jge 0x4bec43
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bec43;
    }
    // 004bec41  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004bec43:
    // 004bec43  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bec48  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 004bec4e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bec52  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bec55  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bec57  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bec59  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bec5b  e808ffffff             -call 0x4beb68
    cpu.esp -= 4;
    sub_4beb68(app, cpu);
    if (cpu.terminate) return;
    // 004bec60  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004bec67  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bec69  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bec6f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bec71  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bec73  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004bec79  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bec7b  7fa8                   -jg 0x4bec25
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bec25;
    }
L_0x004bec7d:
    // 004bec7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004bec7e:
    // 004bec7e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bec82  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bec84  7e29                   -jle 0x4becaf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004becaf;
    }
    // 004bec86  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004bec89  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004bec8f  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bec92  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bec96  ebe6                   -jmp 0x4bec7e
    goto L_0x004bec7e;
L_0x004bec98:
    // 004bec98  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bec9d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004beca0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beca2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beca3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004beca4:
    // 004beca4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004beca6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004becaa  e920ffffff             -jmp 0x4bebcf
    goto L_0x004bebcf;
L_0x004becaf:
    // 004becaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004becb1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004becb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4becb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004becb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004becb9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004becbb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004becbd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004becbf  e850460000             -call 0x4c3314
    cpu.esp -= 4;
    sub_4c3314(app, cpu);
    if (cpu.terminate) return;
    // 004becc4  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004becce  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004becd8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004becdc  899e440d0000           -mov dword ptr [esi + 0xd44], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ebx;
    // 004bece2  c70088eb4b00           -mov dword ptr [eax], 0x4beb88
    app->getMemory<x86::reg32>(cpu.eax) = 4975496 /*0x4beb88*/;
    // 004bece8  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004becec  c70060eb4b00           -mov dword ptr [eax], 0x4beb60
    app->getMemory<x86::reg32>(cpu.eax) = 4975456 /*0x4beb60*/;
    // 004becf2  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 004becf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becf8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bed00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bed00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bed01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bed02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bed03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bed04  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bed07  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bed09  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bed0d  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bed13  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bed15  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bed17  0f84e2000000           -je 0x4bedff
    if (cpu.flags.zf)
    {
        goto L_0x004bedff;
    }
    // 004bed1d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bed1f  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bed23  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bed26  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bed28  0f8ec7000000           -jle 0x4bedf5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bedf5;
    }
    // 004bed2e  8d8684060000           -lea eax, [esi + 0x684]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 004bed34  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bed38  8d86480d0000           -lea eax, [esi + 0xd48]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3400) /* 0xd48 */);
    // 004bed3e  81c6440d0000           -add esi, 0xd44
    (cpu.esi) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 004bed44  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bed48  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004bed4c:
    // 004bed4c  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004bed52  3b85480d0000           +cmp eax, dword ptr [ebp + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bed58  0f8dae000000           -jge 0x4bee0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bee0c;
    }
L_0x004bed5e:
    // 004bed5e  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bed65  0f8e3a010000           -jle 0x4beea5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004beea5;
    }
L_0x004bed6b:
    // 004bed6b  8b95480d0000           -mov edx, dword ptr [ebp + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 004bed71  8bbd4c0d0000           -mov edi, dword ptr [ebp + 0xd4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004bed77  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bed7b  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bed7d  39c2                   +cmp edx, eax
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
    // 004bed7f  7e02                   -jle 0x4bed83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bed83;
    }
    // 004bed81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004bed83:
    // 004bed83  8b8d500d0000           -mov ecx, dword ptr [ebp + 0xd50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004bed89  39ca                   +cmp edx, ecx
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
    // 004bed8b  7e02                   -jle 0x4bed8f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bed8f;
    }
    // 004bed8d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bed8f:
    // 004bed8f  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004bed94  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bed98  8bbd500d0000           -mov edi, dword ptr [ebp + 0xd50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004bed9e  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 004beda5  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004beda7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004beda9  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004bedac  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004bedaf  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bedb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bedb2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bedb4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bedb7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bedb9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bedbb  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bedbe  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bedc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bedc1  8b8d4c0d0000           -mov ecx, dword ptr [ebp + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004bedc7  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 004bedca  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004bedd0  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bedd4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004bedd7  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bedd9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004beddb  898d4c0d0000           -mov dword ptr [ebp + 0xd4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = cpu.ecx;
    // 004bede1  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bede3  8985500d0000           -mov dword ptr [ebp + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 004bede9  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004beded  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bedef  0f8f57ffffff           -jg 0x4bed4c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bed4c;
    }
L_0x004bedf5:
    // 004bedf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bedf7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bedfa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bedfb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bedfc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bedfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bedfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bedff:
    // 004bedff  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bee04  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bee07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bee0c:
    // 004bee0c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bee10  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bee14  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bee1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bee1c  752b                   -jne 0x4bee49
    if (!cpu.flags.zf)
    {
        goto L_0x004bee49;
    }
    // 004bee1e  8b9d440d0000           -mov ebx, dword ptr [ebp + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 004bee24  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bee26  7421                   -je 0x4bee49
    if (cpu.flags.zf)
    {
        goto L_0x004bee49;
    }
    // 004bee28  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bee2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bee2c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004bee2e  7448                   -je 0x4bee78
    if (cpu.flags.zf)
    {
        goto L_0x004bee78;
    }
    // 004bee30  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bee33  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bee35  e8da440000             -call 0x4c3314
    cpu.esp -= 4;
    sub_4c3314(app, cpu);
    if (cpu.terminate) return;
    // 004bee3a  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bee44  e915ffffff             -jmp 0x4bed5e
    goto L_0x004bed5e;
L_0x004bee49:
    // 004bee49  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bee4d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bee50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bee52  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004bee55  e8d537fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004bee5a  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bee64  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bee6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bee70  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bee73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee74  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bee77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bee78:
    // 004bee78  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bee7b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bee80  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bee83  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 004bee89  c7450808000000         -mov dword ptr [ebp + 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004bee90  83c002                 +add eax, 2
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
    // 004bee93  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004bee96  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004beea0  e9b9feffff             -jmp 0x4bed5e
    goto L_0x004bed5e;
L_0x004beea5:
    // 004beea5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004beea7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004beea9  e852450000             -call 0x4c3400
    cpu.esp -= 4;
    sub_4c3400(app, cpu);
    if (cpu.terminate) return;
    // 004beeae  c785500d0000b0010000   -mov dword ptr [ebp + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 004beeb8  e9aefeffff             -jmp 0x4bed6b
    goto L_0x004bed6b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4beec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beec0  c780440d000001000000   -mov dword ptr [eax + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 004beeca  c780480d000000000000   -mov dword ptr [eax + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004beed4  c7804c0d000000000000   -mov dword ptr [eax + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004beede  c780500d000000000000   -mov dword ptr [eax + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 004beee8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004beeec  c70000ed4b00           -mov dword ptr [eax], 0x4bed00
    app->getMemory<x86::reg32>(cpu.eax) = 4975872 /*0x4bed00*/;
    // 004beef2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004beef6  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004beefc  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 004bef01  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4bef04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bef04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bef05  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004bef08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bef0a  e8b476feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004bef0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bef11  7407                   -je 0x4bef1a
    if (cpu.flags.zf)
    {
        goto L_0x004bef1a;
    }
    // 004bef13  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bef15  e81537fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
L_0x004bef1a:
    // 004bef1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bef1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bef1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bef1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bef1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bef1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bef1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bef21  e8e395ffff             -call 0x4b8509
    cpu.esp -= 4;
    sub_4b8509(app, cpu);
    if (cpu.terminate) return;
    // 004bef26  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bef28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bef2a  7410                   -je 0x4bef3c
    if (cpu.flags.zf)
    {
        goto L_0x004bef3c;
    }
    // 004bef2c  8b1554ed4d00           -mov edx, dword ptr [0x4ded54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004bef32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bef33  2eff15b4654c00         -call dword ptr cs:[0x4c65b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006772) /* 0x4c65b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bef3a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004bef3c:
    // 004bef3c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bef3e  750f                   -jne 0x4bef4f
    if (!cpu.flags.zf)
    {
        goto L_0x004bef4f;
    }
    // 004bef40  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bef45  b8741d4d00             -mov eax, 0x4d1d74
    cpu.eax = 5053812 /*0x4d1d74*/;
    // 004bef4a  e8b2c8ffff             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
L_0x004bef4f:
    // 004bef4f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bef51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bef52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bef53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bef54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bef55(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bef55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bef56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bef57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bef58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bef59  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bef5a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bef5b  ff1584ed4d00           -call dword ptr [0x4ded84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107076) /* 0x4ded84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bef61  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bef68  8b1de4a85b00           -mov ebx, dword ptr [0x5ba8e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */);
    // 004bef6e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bef70  eb07                   -jmp 0x4bef79
    goto L_0x004bef79;
L_0x004bef72:
    // 004bef72  3b6b04                 +cmp ebp, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bef75  7406                   -je 0x4bef7d
    if (cpu.flags.zf)
    {
        goto L_0x004bef7d;
    }
    // 004bef77  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
L_0x004bef79:
    // 004bef79  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bef7b  75f5                   -jne 0x4bef72
    if (!cpu.flags.zf)
    {
        goto L_0x004bef72;
    }
L_0x004bef7d:
    // 004bef7d  837b0c00               +cmp dword ptr [ebx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bef81  7425                   -je 0x4befa8
    if (cpu.flags.zf)
    {
        goto L_0x004befa8;
    }
    // 004bef83  8b1550094e00           -mov edx, dword ptr [0x4e0950]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004bef89  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004bef8c  e85a19ffff             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004bef91  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bef93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bef95  755e                   -jne 0x4beff5
    if (!cpu.flags.zf)
    {
        goto L_0x004beff5;
    }
    // 004bef97  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bef9c  b8991d4d00             -mov eax, 0x4d1d99
    cpu.eax = 5053849 /*0x4d1d99*/;
    // 004befa1  e85bc8ffff             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
    // 004befa6  eb4d                   -jmp 0x4beff5
    goto L_0x004beff5;
L_0x004befa8:
    // 004befa8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004befad  8b1550094e00           -mov edx, dword ptr [0x4e0950]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004befb3  e84cffffff             -call 0x4bef04
    cpu.esp -= 4;
    sub_4bef04(app, cpu);
    if (cpu.terminate) return;
    // 004befb8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004befba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004befbc  750f                   -jne 0x4befcd
    if (!cpu.flags.zf)
    {
        goto L_0x004befcd;
    }
    // 004befbe  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004befc3  b8c11d4d00             -mov eax, 0x4d1dc1
    cpu.eax = 5053889 /*0x4d1dc1*/;
    // 004befc8  e834c8ffff             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
L_0x004befcd:
    // 004befcd  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004befd0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004befd2  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 004befd8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004befd9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004befdb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004befdd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004befde  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004befe0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004befe3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004befe5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004befe7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004befea  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004befec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004befed  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004befee  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004beff5:
    // 004beff5  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004beff8  a150094e00             -mov eax, dword ptr [0x4e0950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004beffd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beffe  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004bf002  8b3554ed4d00           -mov esi, dword ptr [0x4ded54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
    // 004bf008  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 004bf00c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf00d  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004bf013  2eff15b8654c00         -call dword ptr cs:[0x4c65b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006776) /* 0x4c65b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf01a  ff1588ed4d00           -call dword ptr [0x4ded88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107080) /* 0x4ded88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf020  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bf022  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf023  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf025  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf026  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf027  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf029(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf029  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf02a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf02b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf02c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf02e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bf030  ff1584ed4d00           -call dword ptr [0x4ded84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107076) /* 0x4ded84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf036  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004bf03b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004bf040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bf042  e8bdfeffff             -call 0x4bef04
    cpu.esp -= 4;
    sub_4bef04(app, cpu);
    if (cpu.terminate) return;
    // 004bf047  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bf049  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf04b  742f                   -je 0x4bf07c
    if (cpu.flags.zf)
    {
        goto L_0x004bf07c;
    }
    // 004bf04d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf04f  e84d470000             -call 0x4c37a1
    cpu.esp -= 4;
    sub_4c37a1(app, cpu);
    if (cpu.terminate) return;
    // 004bf054  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf056  7409                   -je 0x4bf061
    if (cpu.flags.zf)
    {
        goto L_0x004bf061;
    }
    // 004bf058  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf05a  e899c4feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf05f  eb1b                   -jmp 0x4bf07c
    goto L_0x004bf07c;
L_0x004bf061:
    // 004bf061  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bf064  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004bf067  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 004bf06a  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bf06d  a1e4a85b00             -mov eax, dword ptr [0x5ba8e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */);
    // 004bf072  8915e4a85b00           -mov dword ptr [0x5ba8e4], edx
    app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */) = cpu.edx;
    // 004bf078  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004bf07a  eb02                   -jmp 0x4bf07e
    goto L_0x004bf07e;
L_0x004bf07c:
    // 004bf07c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bf07e:
    // 004bf07e  ff1588ed4d00           -call dword ptr [0x4ded88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107080) /* 0x4ded88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf084  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bf086  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf087  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf088  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf089  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf08a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf08a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf08b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf08c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf08d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf08f  ff1584ed4d00           -call dword ptr [0x4ded84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107076) /* 0x4ded84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf095  bbe4a85b00             -mov ebx, 0x5ba8e4
    cpu.ebx = 6007012 /*0x5ba8e4*/;
    // 004bf09a  8b15e4a85b00           -mov edx, dword ptr [0x5ba8e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */);
    // 004bf0a0  eb24                   -jmp 0x4bf0c6
    goto L_0x004bf0c6;
L_0x004bf0a2:
    // 004bf0a2  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf0a5  751b                   -jne 0x4bf0c2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf0c2;
    }
    // 004bf0a7  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 004bf0ab  7408                   -je 0x4bf0b5
    if (cpu.flags.zf)
    {
        goto L_0x004bf0b5;
    }
    // 004bf0ad  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004bf0b0  e843c4feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004bf0b5:
    // 004bf0b5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bf0b7  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bf0b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf0bb  e838c4feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf0c0  eb08                   -jmp 0x4bf0ca
    goto L_0x004bf0ca;
L_0x004bf0c2:
    // 004bf0c2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bf0c4  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004bf0c6:
    // 004bf0c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bf0c8  75d8                   -jne 0x4bf0a2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf0a2;
    }
L_0x004bf0ca:
    // 004bf0ca  ff1588ed4d00           -call dword ptr [0x4ded88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107080) /* 0x4ded88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf0d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bf0d0;
    // 004bf08a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf08b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf08c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf08d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf08f  ff1584ed4d00           -call dword ptr [0x4ded84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107076) /* 0x4ded84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf095  bbe4a85b00             -mov ebx, 0x5ba8e4
    cpu.ebx = 6007012 /*0x5ba8e4*/;
    // 004bf09a  8b15e4a85b00           -mov edx, dword ptr [0x5ba8e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */);
    // 004bf0a0  eb24                   -jmp 0x4bf0c6
    goto L_0x004bf0c6;
L_0x004bf0a2:
    // 004bf0a2  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf0a5  751b                   -jne 0x4bf0c2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf0c2;
    }
    // 004bf0a7  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 004bf0ab  7408                   -je 0x4bf0b5
    if (cpu.flags.zf)
    {
        goto L_0x004bf0b5;
    }
    // 004bf0ad  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004bf0b0  e843c4feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004bf0b5:
    // 004bf0b5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bf0b7  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bf0b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf0bb  e838c4feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf0c0  eb08                   -jmp 0x4bf0ca
    goto L_0x004bf0ca;
L_0x004bf0c2:
    // 004bf0c2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bf0c4  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004bf0c6:
    // 004bf0c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bf0c8  75d8                   -jne 0x4bf0a2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf0a2;
    }
L_0x004bf0ca:
    // 004bf0ca  ff1588ed4d00           -call dword ptr [0x4ded88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107080) /* 0x4ded88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004bf0d0:
    // 004bf0d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf0d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf0d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf0d5  ff1584ed4d00           -call dword ptr [0x4ded84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107076) /* 0x4ded84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf0db  a1e4a85b00             -mov eax, dword ptr [0x5ba8e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */);
L_0x004bf0e0:
    // 004bf0e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf0e2  740b                   -je 0x4bf0ef
    if (cpu.flags.zf)
    {
        goto L_0x004bf0ef;
    }
    // 004bf0e4  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bf0e7  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 004bf0eb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bf0ed  ebf1                   -jmp 0x4bf0e0
    goto L_0x004bf0e0;
L_0x004bf0ef:
    // 004bf0ef  ff1588ed4d00           -call dword ptr [0x4ded88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107080) /* 0x4ded88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf0f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf0f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf0f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf0f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf0f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf0f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf0fa  8b15e4a85b00           -mov edx, dword ptr [0x5ba8e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6007012) /* 0x5ba8e4 */);
L_0x004bf100:
    // 004bf100  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bf102  74cc                   -je 0x4bf0d0
    if (cpu.flags.zf)
    {
        return sub_4bf0d0(app, cpu);
    }
    // 004bf104  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004bf107  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bf109  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bf10b  7408                   -je 0x4bf115
    if (cpu.flags.zf)
    {
        goto L_0x004bf115;
    }
    // 004bf10d  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004bf110  e8e3c3feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004bf115:
    // 004bf115  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf117  e8dcc3feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf11c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bf11e  ebe0                   -jmp 0x4bf100
    goto L_0x004bf100;
}

/* align: skip  */
void Application::sub_4bf120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf123  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf125  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf127  741b                   -je 0x4bf144
    if (cpu.flags.zf)
    {
        goto L_0x004bf144;
    }
    // 004bf129  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bf12b  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004bf132  e82597ffff             -call 0x4b885c
    cpu.esp -= 4;
    sub_4b885c(app, cpu);
    if (cpu.terminate) return;
    // 004bf137  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf13e  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x004bf144:
    // 004bf144  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf145  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf146  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf147  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf148(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf148  e9aaffffff             -jmp 0x4bf0f7
    return sub_4bf0f7(app, cpu);
}

/* align: skip  */
void Application::sub_4bf14d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf14d  66833801               +cmp word ptr [eax], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bf151  751c                   -jne 0x4bf16f
    if (!cpu.flags.zf)
    {
        goto L_0x004bf16f;
    }
    // 004bf153  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004bf157  7416                   -je 0x4bf16f
    if (cpu.flags.zf)
    {
        goto L_0x004bf16f;
    }
    // 004bf159  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 004bf15d  663d1000               +cmp ax, 0x10
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bf161  7206                   -jb 0x4bf169
    if (cpu.flags.cf)
    {
        goto L_0x004bf169;
    }
    // 004bf163  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bf167  7606                   -jbe 0x4bf16f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bf16f;
    }
L_0x004bf169:
    // 004bf169  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf16e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf16f:
    // 004bf16f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf171  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf172(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf172  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf173  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf174  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf176  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf17c  833df4094e00ff         +cmp dword ptr [0x4e09f4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114356) /* 0x4e09f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf183  7523                   -jne 0x4bf1a8
    if (!cpu.flags.zf)
    {
        goto L_0x004bf1a8;
    }
    // 004bf185  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf187  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 004bf18c  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004bf18e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf190  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bf192  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 004bf197  68ec1d4d00             -push 0x4d1dec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5053932 /*0x4d1dec*/;
    cpu.esp -= 4;
    // 004bf19c  2eff155c644c00         -call dword ptr cs:[0x4c645c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006428) /* 0x4c645c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf1a3  a3f4094e00             -mov dword ptr [0x4e09f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5114356) /* 0x4e09f4 */) = cpu.eax;
L_0x004bf1a8:
    // 004bf1a8  833df8094e00ff         +cmp dword ptr [0x4e09f8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114360) /* 0x4e09f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf1af  7523                   -jne 0x4bf1d4
    if (!cpu.flags.zf)
    {
        goto L_0x004bf1d4;
    }
    // 004bf1b1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf1b3  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 004bf1b8  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004bf1ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf1bc  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004bf1be  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 004bf1c3  68f31d4d00             -push 0x4d1df3
    app->getMemory<x86::reg32>(cpu.esp-4) = 5053939 /*0x4d1df3*/;
    cpu.esp -= 4;
    // 004bf1c8  2eff155c644c00         -call dword ptr cs:[0x4c645c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006428) /* 0x4c645c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf1cf  a3f8094e00             -mov dword ptr [0x4e09f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5114360) /* 0x4e09f8 */) = cpu.eax;
L_0x004bf1d4:
    // 004bf1d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf1d6  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf1dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf1dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf1de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf1df(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf1df  e88effffff             -call 0x4bf172
    cpu.esp -= 4;
    sub_4bf172(app, cpu);
    if (cpu.terminate) return;
    // 004bf1e4  a1f4094e00             -mov eax, dword ptr [0x4e09f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114356) /* 0x4e09f4 */);
    // 004bf1e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf1ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf1ea  e883ffffff             -call 0x4bf172
    cpu.esp -= 4;
    sub_4bf172(app, cpu);
    if (cpu.terminate) return;
    // 004bf1ef  a1f8094e00             -mov eax, dword ptr [0x4e09f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114360) /* 0x4e09f8 */);
    // 004bf1f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf1f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf1f5  dbe2                   -fnclex 
    /*nothing*/;
    // 004bf1f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf1f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf1f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf1f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf1fa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf1fc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bf1fe  83f807                 +cmp eax, 7
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
    // 004bf201  7405                   -je 0x4bf208
    if (cpu.flags.zf)
    {
        goto L_0x004bf208;
    }
    // 004bf203  83f804                 +cmp eax, 4
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
    // 004bf206  7513                   -jne 0x4bf21b
    if (!cpu.flags.zf)
    {
        goto L_0x004bf21b;
    }
L_0x004bf208:
    // 004bf208  8b14ddfc094e00         -mov edx, dword ptr [ebx*8 + 0x4e09fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114364) /* 0x4e09fc */ + cpu.ebx * 8);
    // 004bf20f  890cddfc094e00         -mov dword ptr [ebx*8 + 0x4e09fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114364) /* 0x4e09fc */ + cpu.ebx * 8) = cpu.ecx;
    // 004bf216  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf218  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf219  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf21a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf21b:
    // 004bf21b  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf221  8b54d858               -mov edx, dword ptr [eax + ebx*8 + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8);
    // 004bf225  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf22b  894cd858               -mov dword ptr [eax + ebx*8 + 0x58], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8) = cpu.ecx;
    // 004bf22f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf231  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf232  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf234  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf235  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bf237  83f807                 +cmp eax, 7
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
    // 004bf23a  7405                   -je 0x4bf241
    if (cpu.flags.zf)
    {
        goto L_0x004bf241;
    }
    // 004bf23c  83f804                 +cmp eax, 4
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
    // 004bf23f  7509                   -jne 0x4bf24a
    if (!cpu.flags.zf)
    {
        goto L_0x004bf24a;
    }
L_0x004bf241:
    // 004bf241  8b04d5fc094e00         -mov eax, dword ptr [edx*8 + 0x4e09fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114364) /* 0x4e09fc */ + cpu.edx * 8);
    // 004bf248  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf249  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf24a:
    // 004bf24a  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf250  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 004bf254  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf255  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf256(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf256  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf257  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bf259  83f807                 +cmp eax, 7
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
    // 004bf25c  7405                   -je 0x4bf263
    if (cpu.flags.zf)
    {
        goto L_0x004bf263;
    }
    // 004bf25e  83f804                 +cmp eax, 4
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
    // 004bf261  7509                   -jne 0x4bf26c
    if (!cpu.flags.zf)
    {
        goto L_0x004bf26c;
    }
L_0x004bf263:
    // 004bf263  8b04d5000a4e00         -mov eax, dword ptr [edx*8 + 0x4e0a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114368) /* 0x4e0a00 */ + cpu.edx * 8);
    // 004bf26a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf26b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf26c:
    // 004bf26c  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf272  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 004bf276  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf277  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf278(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf278  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf279  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf27b  e8d6ffffff             -call 0x4bf256
    cpu.esp -= 4;
    sub_4bf256(app, cpu);
    if (cpu.terminate) return;
    // 004bf280  39c2                   +cmp edx, eax
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
    // 004bf282  7509                   -jne 0x4bf28d
    if (!cpu.flags.zf)
    {
        goto L_0x004bf28d;
    }
    // 004bf284  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf286  e8a9ffffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf28b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf28c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf28d:
    // 004bf28d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf28f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf290  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf291(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf291  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bf295  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf297  760a                   -jbe 0x4bf2a3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bf2a3;
    }
    // 004bf299  83f801                 +cmp eax, 1
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
    // 004bf29c  7424                   -je 0x4bf2c2
    if (cpu.flags.zf)
    {
        goto L_0x004bf2c2;
    }
    // 004bf29e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf2a0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004bf2a3:
    // 004bf2a3  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004bf2a8  e887ffffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf2ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bf2af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf2b1  7503                   -jne 0x4bf2b6
    if (!cpu.flags.zf)
    {
        goto L_0x004bf2b6;
    }
    // 004bf2b3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004bf2b6:
    // 004bf2b6  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004bf2bb:
    // 004bf2bb  e8d5000000             -call 0x4bf395
    cpu.esp -= 4;
    sub_4bf395(app, cpu);
    if (cpu.terminate) return;
    // 004bf2c0  eb1f                   -jmp 0x4bf2e1
    goto L_0x004bf2e1;
L_0x004bf2c2:
    // 004bf2c2  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004bf2c7  e868ffffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf2cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bf2ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf2d0  7503                   -jne 0x4bf2d5
    if (!cpu.flags.zf)
    {
        goto L_0x004bf2d5;
    }
    // 004bf2d2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004bf2d5:
    // 004bf2d5  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004bf2da  ebdf                   -jmp 0x4bf2bb
    goto L_0x004bf2bb;
L_0x004bf2dc:
    // 004bf2dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf2de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004bf2e1:
    // 004bf2e1  83fa02                 +cmp edx, 2
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
    // 004bf2e4  74f6                   -je 0x4bf2dc
    if (cpu.flags.zf)
    {
        goto L_0x004bf2dc;
    }
    // 004bf2e6  83fa03                 +cmp edx, 3
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
    // 004bf2e9  74f1                   -je 0x4bf2dc
    if (cpu.flags.zf)
    {
        goto L_0x004bf2dc;
    }
    // 004bf2eb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf2f0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4bf2f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf2f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf2f4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004bf2f9  e836ffffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf2fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bf300  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004bf305  e82affffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf30a  83fa02                 +cmp edx, 2
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
    // 004bf30d  7405                   -je 0x4bf314
    if (cpu.flags.zf)
    {
        goto L_0x004bf314;
    }
    // 004bf30f  83fa03                 +cmp edx, 3
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
    // 004bf312  750a                   -jne 0x4bf31e
    if (!cpu.flags.zf)
    {
        goto L_0x004bf31e;
    }
L_0x004bf314:
    // 004bf314  83f802                 +cmp eax, 2
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
    // 004bf317  740c                   -je 0x4bf325
    if (cpu.flags.zf)
    {
        goto L_0x004bf325;
    }
    // 004bf319  83f803                 +cmp eax, 3
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
    // 004bf31c  7407                   -je 0x4bf325
    if (cpu.flags.zf)
    {
        goto L_0x004bf325;
    }
L_0x004bf31e:
    // 004bf31e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf323  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf324  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf325:
    // 004bf325  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf327  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf328  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf329(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf329  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf32a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf32b  803d640a4e0000         +cmp byte ptr [0x4e0a64], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5114468) /* 0x4e0a64 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bf332  7519                   -jne 0x4bf34d
    if (!cpu.flags.zf)
    {
        goto L_0x004bf34d;
    }
    // 004bf334  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bf336  6891f24b00             -push 0x4bf291
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977297 /*0x4bf291*/;
    cpu.esp -= 4;
    // 004bf33b  2eff1570654c00         -call dword ptr cs:[0x4c6570]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006704) /* 0x4c6570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf342  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf344  7407                   -je 0x4bf34d
    if (cpu.flags.zf)
    {
        goto L_0x004bf34d;
    }
    // 004bf346  c605640a4e0001         -mov byte ptr [0x4e0a64], 1
    app->getMemory<x86::reg8>(x86::reg32(5114468) /* 0x4e0a64 */) = 1 /*0x1*/;
L_0x004bf34d:
    // 004bf34d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf34f  a0640a4e00             -mov al, byte ptr [0x4e0a64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5114468) /* 0x4e0a64 */);
    // 004bf354  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf356  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf357(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf357  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf358  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf359  803d640a4e0000         +cmp byte ptr [0x4e0a64], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5114468) /* 0x4e0a64 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bf360  741a                   -je 0x4bf37c
    if (cpu.flags.zf)
    {
        goto L_0x004bf37c;
    }
    // 004bf362  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf364  6891f24b00             -push 0x4bf291
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977297 /*0x4bf291*/;
    cpu.esp -= 4;
    // 004bf369  2eff1570654c00         -call dword ptr cs:[0x4c6570]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006704) /* 0x4c6570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf370  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf372  7408                   -je 0x4bf37c
    if (cpu.flags.zf)
    {
        goto L_0x004bf37c;
    }
    // 004bf374  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004bf376  8815640a4e00           -mov byte ptr [0x4e0a64], dl
    app->getMemory<x86::reg8>(x86::reg32(5114468) /* 0x4e0a64 */) = cpu.dl;
L_0x004bf37c:
    // 004bf37c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf37e  a0640a4e00             -mov al, byte ptr [0x4e0a64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5114468) /* 0x4e0a64 */);
    // 004bf383  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf385  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004bf388  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bf38d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf38e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf38f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf390  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf395  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf396  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf397  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf398  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf39a  e895feffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf39f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf3a1  83fb02                 +cmp ebx, 2
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
    // 004bf3a4  0f82db000000           -jb 0x4bf485
    if (cpu.flags.cf)
    {
        return sub_4bf485(app, cpu);
    }
    // 004bf3aa  0f86df000000           -jbe 0x4bf48f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4bf48f(app, cpu);
    }
    // 004bf3b0  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf3b3  0f86ec000000           -jbe 0x4bf4a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4bf4a5(app, cpu);
    }
    // 004bf3b9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bf3be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf3b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bf3b9;
    // 004bf390  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf395  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf396  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf397  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf398  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf39a  e895feffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf39f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf3a1  83fb02                 +cmp ebx, 2
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
    // 004bf3a4  0f82db000000           -jb 0x4bf485
    if (cpu.flags.cf)
    {
        return sub_4bf485(app, cpu);
    }
    // 004bf3aa  0f86df000000           -jbe 0x4bf48f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4bf48f(app, cpu);
    }
    // 004bf3b0  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf3b3  0f86ec000000           -jbe 0x4bf4a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4bf4a5(app, cpu);
    }
L_entry_0x004bf3b9:
    // 004bf3b9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bf3be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf395(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bf395;
    // 004bf390  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_entry_0x004bf395:
    // 004bf395  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf396  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf397  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf398  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf39a  e895feffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf39f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf3a1  83fb02                 +cmp ebx, 2
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
    // 004bf3a4  0f82db000000           -jb 0x4bf485
    if (cpu.flags.cf)
    {
        return sub_4bf485(app, cpu);
    }
    // 004bf3aa  0f86df000000           -jbe 0x4bf48f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4bf48f(app, cpu);
    }
    // 004bf3b0  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf3b3  0f86ec000000           -jbe 0x4bf4a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4bf4a5(app, cpu);
    }
    // 004bf3b9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bf3be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf3c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf3c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf3c3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf3c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf3c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf3c7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004bf3cc  e863feffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf3d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf3d3  83f801                 +cmp eax, 1
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
    // 004bf3d6  7425                   -je 0x4bf3fd
    if (cpu.flags.zf)
    {
        goto L_0x004bf3fd;
    }
    // 004bf3d8  83f802                 +cmp eax, 2
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
    // 004bf3db  7420                   -je 0x4bf3fd
    if (cpu.flags.zf)
    {
        goto L_0x004bf3fd;
    }
    // 004bf3dd  83f803                 +cmp eax, 3
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
    // 004bf3e0  741b                   -je 0x4bf3fd
    if (cpu.flags.zf)
    {
        goto L_0x004bf3fd;
    }
    // 004bf3e2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bf3e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bf3e9  e80afeffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf3ee  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004bf3f3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bf3f5  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf3f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf3f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf3fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf3fd:
    // 004bf3fd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bf402  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf403  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf404  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf405  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf406(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf406  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf407  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf408  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf409  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf40b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bf40d  83f801                 +cmp eax, 1
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
    // 004bf410  7c05                   -jl 0x4bf417
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bf417;
    }
    // 004bf412  83f80c                 +cmp eax, 0xc
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
    // 004bf415  7e13                   -jle 0x4bf42a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bf42a;
    }
L_0x004bf417:
    // 004bf417  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004bf41c  e88f72feff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004bf421  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004bf426  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf427  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf428  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf42a:
    // 004bf42a  c7059c014e0090f34b00   -mov dword ptr [0x4e019c], 0x4bf390
    app->getMemory<x86::reg32>(x86::reg32(5112220) /* 0x4e019c */) = 4977552 /*0x4bf390*/;
    // 004bf434  83f902                 +cmp ecx, 2
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
    // 004bf437  741f                   -je 0x4bf458
    if (cpu.flags.zf)
    {
        goto L_0x004bf458;
    }
    // 004bf439  83f903                 +cmp ecx, 3
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
    // 004bf43c  741a                   -je 0x4bf458
    if (cpu.flags.zf)
    {
        goto L_0x004bf458;
    }
    // 004bf43e  e813feffff             -call 0x4bf256
    cpu.esp -= 4;
    sub_4bf256(app, cpu);
    if (cpu.terminate) return;
    // 004bf443  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf445  7411                   -je 0x4bf458
    if (cpu.flags.zf)
    {
        goto L_0x004bf458;
    }
    // 004bf447  83fb02                 +cmp ebx, 2
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
    // 004bf44a  750c                   -jne 0x4bf458
    if (!cpu.flags.zf)
    {
        goto L_0x004bf458;
    }
    // 004bf44c  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 004bf451  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf453  e88f430000             -call 0x4c37e7
    cpu.esp -= 4;
    sub_4c37e7(app, cpu);
    if (cpu.terminate) return;
L_0x004bf458:
    // 004bf458  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf45a  e8d5fdffff             -call 0x4bf234
    cpu.esp -= 4;
    sub_4bf234(app, cpu);
    if (cpu.terminate) return;
    // 004bf45f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bf461  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf463  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf465  e88efdffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf46a  e884feffff             -call 0x4bf2f3
    cpu.esp -= 4;
    sub_4bf2f3(app, cpu);
    if (cpu.terminate) return;
    // 004bf46f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf471  7407                   -je 0x4bf47a
    if (cpu.flags.zf)
    {
        goto L_0x004bf47a;
    }
    // 004bf473  e8b1feffff             -call 0x4bf329
    cpu.esp -= 4;
    sub_4bf329(app, cpu);
    if (cpu.terminate) return;
    // 004bf478  eb05                   -jmp 0x4bf47f
    goto L_0x004bf47f;
L_0x004bf47a:
    // 004bf47a  e8d8feffff             -call 0x4bf357
    cpu.esp -= 4;
    sub_4bf357(app, cpu);
    if (cpu.terminate) return;
L_0x004bf47f:
    // 004bf47f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bf481  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf482  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf483  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf484  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf485(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf485  83fb01                 +cmp ebx, 1
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
    // 004bf488  7411                   -je 0x4bf49b
    if (cpu.flags.zf)
    {
        goto L_0x004bf49b;
    }
    // 004bf48a  e92affffff             -jmp 0x4bf3b9
    return sub_4bf3b9(app, cpu);
    // 004bf48f  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 004bf494  e829ffffff             -call 0x4bf3c2
    cpu.esp -= 4;
    sub_4bf3c2(app, cpu);
    if (cpu.terminate) return;
    // 004bf499  eb37                   -jmp 0x4bf4d2
    goto L_0x004bf4d2;
L_0x004bf49b:
    // 004bf49b  83f802                 +cmp eax, 2
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
    // 004bf49e  7505                   -jne 0x4bf4a5
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4a5;
    }
    // 004bf4a0  e8d138ffff             -call 0x4b2d76
    cpu.esp -= 4;
    sub_4b2d76(app, cpu);
    if (cpu.terminate) return;
L_0x004bf4a5:
    // 004bf4a5  83f901                 +cmp ecx, 1
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
    // 004bf4a8  741a                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4aa  83f902                 +cmp ecx, 2
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
    // 004bf4ad  7415                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4af  83f903                 +cmp ecx, 3
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
    // 004bf4b2  7410                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4b4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bf4b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf4bb  e838fdffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf4c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf4c2  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf4c4:
    // 004bf4c4  e82afeffff             -call 0x4bf2f3
    cpu.esp -= 4;
    sub_4bf2f3(app, cpu);
    if (cpu.terminate) return;
    // 004bf4c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf4cb  7505                   -jne 0x4bf4d2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4d2;
    }
    // 004bf4cd  e885feffff             -call 0x4bf357
    cpu.esp -= 4;
    sub_4bf357(app, cpu);
    if (cpu.terminate) return;
L_0x004bf4d2:
    // 004bf4d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf4d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf4a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bf4a5;
    // 004bf485  83fb01                 +cmp ebx, 1
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
    // 004bf488  7411                   -je 0x4bf49b
    if (cpu.flags.zf)
    {
        goto L_0x004bf49b;
    }
    // 004bf48a  e92affffff             -jmp 0x4bf3b9
    return sub_4bf3b9(app, cpu);
    // 004bf48f  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 004bf494  e829ffffff             -call 0x4bf3c2
    cpu.esp -= 4;
    sub_4bf3c2(app, cpu);
    if (cpu.terminate) return;
    // 004bf499  eb37                   -jmp 0x4bf4d2
    goto L_0x004bf4d2;
L_0x004bf49b:
    // 004bf49b  83f802                 +cmp eax, 2
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
    // 004bf49e  7505                   -jne 0x4bf4a5
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4a5;
    }
    // 004bf4a0  e8d138ffff             -call 0x4b2d76
    cpu.esp -= 4;
    sub_4b2d76(app, cpu);
    if (cpu.terminate) return;
L_0x004bf4a5:
L_entry_0x004bf4a5:
    // 004bf4a5  83f901                 +cmp ecx, 1
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
    // 004bf4a8  741a                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4aa  83f902                 +cmp ecx, 2
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
    // 004bf4ad  7415                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4af  83f903                 +cmp ecx, 3
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
    // 004bf4b2  7410                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4b4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bf4b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf4bb  e838fdffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf4c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf4c2  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf4c4:
    // 004bf4c4  e82afeffff             -call 0x4bf2f3
    cpu.esp -= 4;
    sub_4bf2f3(app, cpu);
    if (cpu.terminate) return;
    // 004bf4c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf4cb  7505                   -jne 0x4bf4d2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4d2;
    }
    // 004bf4cd  e885feffff             -call 0x4bf357
    cpu.esp -= 4;
    sub_4bf357(app, cpu);
    if (cpu.terminate) return;
L_0x004bf4d2:
    // 004bf4d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf4d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf48f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bf48f;
    // 004bf485  83fb01                 +cmp ebx, 1
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
    // 004bf488  7411                   -je 0x4bf49b
    if (cpu.flags.zf)
    {
        goto L_0x004bf49b;
    }
    // 004bf48a  e92affffff             -jmp 0x4bf3b9
    return sub_4bf3b9(app, cpu);
L_entry_0x004bf48f:
    // 004bf48f  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 004bf494  e829ffffff             -call 0x4bf3c2
    cpu.esp -= 4;
    sub_4bf3c2(app, cpu);
    if (cpu.terminate) return;
    // 004bf499  eb37                   -jmp 0x4bf4d2
    goto L_0x004bf4d2;
L_0x004bf49b:
    // 004bf49b  83f802                 +cmp eax, 2
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
    // 004bf49e  7505                   -jne 0x4bf4a5
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4a5;
    }
    // 004bf4a0  e8d138ffff             -call 0x4b2d76
    cpu.esp -= 4;
    sub_4b2d76(app, cpu);
    if (cpu.terminate) return;
L_0x004bf4a5:
    // 004bf4a5  83f901                 +cmp ecx, 1
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
    // 004bf4a8  741a                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4aa  83f902                 +cmp ecx, 2
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
    // 004bf4ad  7415                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4af  83f903                 +cmp ecx, 3
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
    // 004bf4b2  7410                   -je 0x4bf4c4
    if (cpu.flags.zf)
    {
        goto L_0x004bf4c4;
    }
    // 004bf4b4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bf4b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf4bb  e838fdffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf4c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf4c2  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf4c4:
    // 004bf4c4  e82afeffff             -call 0x4bf2f3
    cpu.esp -= 4;
    sub_4bf2f3(app, cpu);
    if (cpu.terminate) return;
    // 004bf4c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf4cb  7505                   -jne 0x4bf4d2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4d2;
    }
    // 004bf4cd  e885feffff             -call 0x4bf357
    cpu.esp -= 4;
    sub_4bf357(app, cpu);
    if (cpu.terminate) return;
L_0x004bf4d2:
    // 004bf4d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf4d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf4d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf4d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf4d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf4d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf4da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf4db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bf4dc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bf4dd  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x004bf4e2:
    // 004bf4e2  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf4e8  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004bf4eb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bf4ed  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bf4ef  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004bf4f2  8db2fc094e00           -lea esi, [edx + 0x4e09fc]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(5114364) /* 0x4e09fc */);
    // 004bf4f8  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bf4fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bf4fc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bf4fd  83fa68                 +cmp edx, 0x68
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf500  75e0                   -jne 0x4bf4e2
    if (!cpu.flags.zf)
    {
        goto L_0x004bf4e2;
    }
    // 004bf502  ba78f24b00             -mov edx, 0x4bf278
    cpu.edx = 4977272 /*0x4bf278*/;
    // 004bf507  bb95f34b00             -mov ebx, 0x4bf395
    cpu.ebx = 4977557 /*0x4bf395*/;
    // 004bf50c  891520074e00           -mov dword ptr [0x4e0720], edx
    app->getMemory<x86::reg32>(x86::reg32(5113632) /* 0x4e0720 */) = cpu.edx;
    // 004bf512  891d24074e00           -mov dword ptr [0x4e0724], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113636) /* 0x4e0724 */) = cpu.ebx;
    // 004bf518  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bf519  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf51a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf51b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf51c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf51d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf51e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf51e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf51f  e8cffdffff             -call 0x4bf2f3
    cpu.esp -= 4;
    sub_4bf2f3(app, cpu);
    if (cpu.terminate) return;
    // 004bf524  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf526  7423                   -je 0x4bf54b
    if (cpu.flags.zf)
    {
        goto L_0x004bf54b;
    }
    // 004bf528  e82afeffff             -call 0x4bf357
    cpu.esp -= 4;
    sub_4bf357(app, cpu);
    if (cpu.terminate) return;
    // 004bf52d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bf532  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004bf537  e8bcfcffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
    // 004bf53c  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bf541  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004bf546  e8adfcffff             -call 0x4bf1f8
    cpu.esp -= 4;
    sub_4bf1f8(app, cpu);
    if (cpu.terminate) return;
L_0x004bf54b:
    // 004bf54b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf54c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf54d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf54d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf54e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf54f  bad8f44b00             -mov edx, 0x4bf4d8
    cpu.edx = 4977880 /*0x4bf4d8*/;
    // 004bf554  bb1ef54b00             -mov ebx, 0x4bf51e
    cpu.ebx = 4977950 /*0x4bf51e*/;
    // 004bf559  891598ed4d00           -mov dword ptr [0x4ded98], edx
    app->getMemory<x86::reg32>(x86::reg32(5107096) /* 0x4ded98 */) = cpu.edx;
    // 004bf55f  891d9ced4d00           -mov dword ptr [0x4ded9c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5107100) /* 0x4ded9c */) = cpu.ebx;
    // 004bf565  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf566  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf567  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf568(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf568  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf569  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf56a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf56b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf56c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004bf56f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf571  a1680a4e00             -mov eax, dword ptr [0x4e0a68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114472) /* 0x4e0a68 */);
    // 004bf576  83f801                 +cmp eax, 1
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
    // 004bf579  725e                   -jb 0x4bf5d9
    if (cpu.flags.cf)
    {
        goto L_0x004bf5d9;
    }
    // 004bf57b  7607                   -jbe 0x4bf584
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bf584;
    }
    // 004bf57d  83f802                 +cmp eax, 2
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
    // 004bf580  7439                   -je 0x4bf5bb
    if (cpu.flags.zf)
    {
        goto L_0x004bf5bb;
    }
    // 004bf582  eb55                   -jmp 0x4bf5d9
    goto L_0x004bf5d9;
L_0x004bf584:
    // 004bf584  8b1df0a85b00           -mov ebx, dword ptr [0x5ba8f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6007024) /* 0x5ba8f0 */);
    // 004bf58a  4b                     -dec ebx
    (cpu.ebx)--;
    // 004bf58b  8b0deca85b00           -mov ecx, dword ptr [0x5ba8ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6007020) /* 0x5ba8ec */);
    // 004bf591  891df0a85b00           -mov dword ptr [0x5ba8f0], ebx
    app->getMemory<x86::reg32>(x86::reg32(6007024) /* 0x5ba8f0 */) = cpu.ebx;
    // 004bf597  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bf599  740c                   -je 0x4bf5a7
    if (cpu.flags.zf)
    {
        goto L_0x004bf5a7;
    }
    // 004bf59b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bf59d  7512                   -jne 0x4bf5b1
    if (!cpu.flags.zf)
    {
        goto L_0x004bf5b1;
    }
    // 004bf59f  891d680a4e00           -mov dword ptr [0x4e0a68], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114472) /* 0x4e0a68 */) = cpu.ebx;
    // 004bf5a5  eb0a                   -jmp 0x4bf5b1
    goto L_0x004bf5b1;
L_0x004bf5a7:
    // 004bf5a7  c705680a4e0002000000   -mov dword ptr [0x4e0a68], 2
    app->getMemory<x86::reg32>(x86::reg32(5114472) /* 0x4e0a68 */) = 2 /*0x2*/;
L_0x004bf5b1:
    // 004bf5b1  a1eca85b00             -mov eax, dword ptr [0x5ba8ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6007020) /* 0x5ba8ec */);
    // 004bf5b6  e9b2000000             -jmp 0x4bf66d
    goto L_0x004bf66d;
L_0x004bf5bb:
    // 004bf5bb  833df0a85b0000         +cmp dword ptr [0x5ba8f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6007024) /* 0x5ba8f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf5c2  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004bf5c5  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004bf5ca  a3680a4e00             -mov dword ptr [0x4e0a68], eax
    app->getMemory<x86::reg32>(x86::reg32(5114472) /* 0x4e0a68 */) = cpu.eax;
    // 004bf5cf  a1e8a85b00             -mov eax, dword ptr [0x5ba8e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6007016) /* 0x5ba8e8 */);
    // 004bf5d4  e994000000             -jmp 0x4bf66d
    goto L_0x004bf66d;
L_0x004bf5d9:
    // 004bf5d9  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004bf5dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf5de  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bf5e0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bf5e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf5e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf5e6  2eff155c654c00         -call dword ptr cs:[0x4c655c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006684) /* 0x4c655c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf5ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf5ef  0f8473000000           -je 0x4bf668
    if (cpu.flags.zf)
    {
        goto L_0x004bf668;
    }
    // 004bf5f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bf5f7  e851fbffff             -call 0x4bf14d
    cpu.esp -= 4;
    sub_4bf14d(app, cpu);
    if (cpu.terminate) return;
    // 004bf5fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf5fe  74d9                   -je 0x4bf5d9
    if (cpu.flags.zf)
    {
        goto L_0x004bf5d9;
    }
    // 004bf600  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf602  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bf607  48                     -dec eax
    (cpu.eax)--;
    // 004bf608  a3f0a85b00             -mov dword ptr [0x5ba8f0], eax
    app->getMemory<x86::reg32>(x86::reg32(6007024) /* 0x5ba8f0 */) = cpu.eax;
    // 004bf60d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf60f  8a44240e               -mov al, byte ptr [esp + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 004bf613  a3eca85b00             -mov dword ptr [0x5ba8ec], eax
    app->getMemory<x86::reg32>(x86::reg32(6007020) /* 0x5ba8ec */) = cpu.eax;
    // 004bf618  f644241101             +test byte ptr [esp + 0x11], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */) & 1 /*0x1*/));
    // 004bf61d  7509                   -jne 0x4bf628
    if (!cpu.flags.zf)
    {
        goto L_0x004bf628;
    }
    // 004bf61f  833deca85b0000         +cmp dword ptr [0x5ba8ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6007020) /* 0x5ba8ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf626  7524                   -jne 0x4bf64c
    if (!cpu.flags.zf)
    {
        goto L_0x004bf64c;
    }
L_0x004bf628:
    // 004bf628  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 004bf62d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf62f  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bf631  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bf636  890deca85b00           -mov dword ptr [0x5ba8ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(6007020) /* 0x5ba8ec */) = cpu.ecx;
    // 004bf63c  8935680a4e00           -mov dword ptr [0x4e0a68], esi
    app->getMemory<x86::reg32>(x86::reg32(5114472) /* 0x4e0a68 */) = cpu.esi;
    // 004bf642  a3e8a85b00             -mov dword ptr [0x5ba8e8], eax
    app->getMemory<x86::reg32>(x86::reg32(6007016) /* 0x5ba8e8 */) = cpu.eax;
    // 004bf647  e965ffffff             -jmp 0x4bf5b1
    goto L_0x004bf5b1;
L_0x004bf64c:
    // 004bf64c  833df0a85b0000         +cmp dword ptr [0x5ba8f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6007024) /* 0x5ba8f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf653  0f8458ffffff           -je 0x4bf5b1
    if (cpu.flags.zf)
    {
        goto L_0x004bf5b1;
    }
    // 004bf659  c705680a4e0001000000   -mov dword ptr [0x4e0a68], 1
    app->getMemory<x86::reg32>(x86::reg32(5114472) /* 0x4e0a68 */) = 1 /*0x1*/;
    // 004bf663  e949ffffff             -jmp 0x4bf5b1
    goto L_0x004bf5b1;
L_0x004bf668:
    // 004bf668  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004bf66d:
    // 004bf66d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004bf670  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf671  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf672  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf673  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf674  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf675(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf675  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf676  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf677  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf678  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf679  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bf67c  a1f4da4d00             -mov eax, dword ptr [0x4ddaf4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102324) /* 0x4ddaf4 */);
    // 004bf681  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf683  740a                   -je 0x4bf68f
    if (cpu.flags.zf)
    {
        goto L_0x004bf68f;
    }
    // 004bf685  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004bf687  8935f4da4d00           -mov dword ptr [0x4ddaf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5102324) /* 0x4ddaf4 */) = cpu.esi;
    // 004bf68d  eb5a                   -jmp 0x4bf6e9
    goto L_0x004bf6e9;
L_0x004bf68f:
    // 004bf68f  833dd8ed4d0000         +cmp dword ptr [0x4dedd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107160) /* 0x4dedd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf696  7410                   -je 0x4bf6a8
    if (cpu.flags.zf)
    {
        goto L_0x004bf6a8;
    }
    // 004bf698  ff15a4ed4d00           -call dword ptr [0x4deda4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf69e  ff15d8ed4d00           -call dword ptr [0x4dedd8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107160) /* 0x4dedd8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf6a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf6a6  eb3f                   -jmp 0x4bf6e7
    goto L_0x004bf6e7;
L_0x004bf6a8:
    // 004bf6a8  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf6ae  e82cfbffff             -call 0x4bf1df
    cpu.esp -= 4;
    sub_4bf1df(app, cpu);
    if (cpu.terminate) return;
    // 004bf6b3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf6b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bf6b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf6b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf6b9  2eff15bc644c00         -call dword ptr cs:[0x4c64bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006524) /* 0x4c64bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf6c0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf6c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf6c3  2eff1574654c00         -call dword ptr cs:[0x4c6574]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006708) /* 0x4c6574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf6ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf6cc  e897feffff             -call 0x4bf568
    cpu.esp -= 4;
    sub_4bf568(app, cpu);
    if (cpu.terminate) return;
    // 004bf6d1  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bf6d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf6d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf6d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf6d8  2eff1574654c00         -call dword ptr cs:[0x4c6574]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006708) /* 0x4c6574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf6df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bf6e1  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf6e7:
    // 004bf6e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004bf6e9:
    // 004bf6e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bf6ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf6ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf6ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf6ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf6f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf6f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf6f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf6f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf6f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf6f4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bf6f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bf6f9  8b15e0ed4d00           -mov edx, dword ptr [0x4dede0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5107168) /* 0x4dede0 */);
    // 004bf6ff  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 004bf703  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bf705  7415                   -je 0x4bf71c
    if (cpu.flags.zf)
    {
        goto L_0x004bf71c;
    }
    // 004bf707  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf70c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bf70e  ff15a4ed4d00           -call dword ptr [0x4deda4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf714  ff15e0ed4d00           -call dword ptr [0x4dede0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107168) /* 0x4dede0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf71a  eb30                   -jmp 0x4bf74c
    goto L_0x004bf74c;
L_0x004bf71c:
    // 004bf71c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf721  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf727  e8befaffff             -call 0x4bf1ea
    cpu.esp -= 4;
    sub_4bf1ea(app, cpu);
    if (cpu.terminate) return;
    // 004bf72c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf72d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bf731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf732  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bf734  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bf738  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf739  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf73a  2eff15e0654c00         -call dword ptr cs:[0x4c65e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006816) /* 0x4c65e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf741  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf746  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf74c:
    // 004bf74c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bf74e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bf751  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf752  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf753  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf754  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf755(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf755  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf756  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf757  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bf758  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf759  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bf75a  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bf75d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf75f  83f8ff                 +cmp eax, -1
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
    // 004bf762  750e                   -jne 0x4bf772
    if (!cpu.flags.zf)
    {
        goto L_0x004bf772;
    }
    // 004bf764  2eff15a0644c00         -call dword ptr cs:[0x4c64a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006496) /* 0x4c64a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf76b:
    // 004bf76b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf76d  e98e000000             -jmp 0x4bf800
    goto L_0x004bf800;
L_0x004bf772:
    // 004bf772  83f8fe                 +cmp eax, -2
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
    // 004bf775  7509                   -jne 0x4bf780
    if (!cpu.flags.zf)
    {
        goto L_0x004bf780;
    }
    // 004bf777  2eff150c654c00         -call dword ptr cs:[0x4c650c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006604) /* 0x4c650c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf77e  ebeb                   -jmp 0x4bf76b
    goto L_0x004bf76b;
L_0x004bf780:
    // 004bf780  83f8fd                 +cmp eax, -3
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
    // 004bf783  7526                   -jne 0x4bf7ab
    if (!cpu.flags.zf)
    {
        goto L_0x004bf7ab;
    }
    // 004bf785  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 004bf78a  b8d4a35b00             -mov eax, 0x5ba3d4
    cpu.eax = 6005716 /*0x5ba3d4*/;
    // 004bf78f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bf791  e8992efdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004bf796  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bf798  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bf79a  8915d0a35b00           -mov dword ptr [0x5ba3d0], edx
    app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */) = cpu.edx;
    // 004bf7a0  89156c0a4e00           -mov dword ptr [0x4e0a6c], edx
    app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */) = cpu.edx;
    // 004bf7a6  e9ed000000             -jmp 0x4bf898
    goto L_0x004bf898;
L_0x004bf7ab:
    // 004bf7ab  83f8fc                 +cmp eax, -4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf7ae  7550                   -jne 0x4bf800
    if (!cpu.flags.zf)
    {
        goto L_0x004bf800;
    }
    // 004bf7b0  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 004bf7b5  b8d4a35b00             -mov eax, 0x5ba3d4
    cpu.eax = 6005716 /*0x5ba3d4*/;
    // 004bf7ba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bf7bc  e86e2efdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004bf7c1  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 004bf7c6  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x004bf7c8:
    // 004bf7c8  40                     -inc eax
    (cpu.eax)++;
    // 004bf7c9  8890d4a35b00           -mov byte ptr [eax + 0x5ba3d4], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005716) /* 0x5ba3d4 */) = cpu.dl;
    // 004bf7cf  3d9f000000             +cmp eax, 0x9f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(159 /*0x9f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf7d4  7ef2                   -jle 0x4bf7c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bf7c8;
    }
    // 004bf7d6  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 004bf7db  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x004bf7dd:
    // 004bf7dd  40                     -inc eax
    (cpu.eax)++;
    // 004bf7de  88b0d4a35b00           -mov byte ptr [eax + 0x5ba3d4], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005716) /* 0x5ba3d4 */) = cpu.dh;
    // 004bf7e4  3dfc000000             +cmp eax, 0xfc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf7e9  7ef2                   -jle 0x4bf7dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bf7dd;
    }
    // 004bf7eb  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004bf7f0  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 004bf7f5  892dd0a35b00           -mov dword ptr [0x5ba3d0], ebp
    app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */) = cpu.ebp;
    // 004bf7fb  e989000000             -jmp 0x4bf889
    goto L_0x004bf889;
L_0x004bf800:
    // 004bf800  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bf802  7505                   -jne 0x4bf809
    if (!cpu.flags.zf)
    {
        goto L_0x004bf809;
    }
    // 004bf804  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004bf809:
    // 004bf809  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bf80b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf80c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf80d  2eff15a4644c00         -call dword ptr cs:[0x4c64a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006500) /* 0x4c64a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bf814  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bf816  750a                   -jne 0x4bf822
    if (!cpu.flags.zf)
    {
        goto L_0x004bf822;
    }
    // 004bf818  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf81d  e976000000             -jmp 0x4bf898
    goto L_0x004bf898;
L_0x004bf822:
    // 004bf822  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 004bf827  b8d4a35b00             -mov eax, 0x5ba3d4
    cpu.eax = 6005716 /*0x5ba3d4*/;
    // 004bf82c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bf82e  e8fc2dfdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004bf833  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bf835  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004bf839  890dd0a35b00           -mov dword ptr [0x5ba3d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */) = cpu.ecx;
    // 004bf83f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004bf841  740a                   -je 0x4bf84d
    if (cpu.flags.zf)
    {
        goto L_0x004bf84d;
    }
    // 004bf843  c705d0a35b0001000000   -mov dword ptr [0x5ba3d0], 1
    app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */) = 1 /*0x1*/;
L_0x004bf84d:
    // 004bf84d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bf84f  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004bf851  eb1c                   -jmp 0x4bf86f
    goto L_0x004bf86f;
L_0x004bf853:
    // 004bf853  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bf855  8a441406               -mov al, byte ptr [esp + edx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.edx * 1);
    // 004bf859  eb07                   -jmp 0x4bf862
    goto L_0x004bf862;
L_0x004bf85b:
    // 004bf85b  40                     -inc eax
    (cpu.eax)++;
    // 004bf85c  8888d4a35b00           -mov byte ptr [eax + 0x5ba3d4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005716) /* 0x5ba3d4 */) = cpu.cl;
L_0x004bf862:
    // 004bf862  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bf864  8a5c1407               -mov bl, byte ptr [esp + edx + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.edx * 1);
    // 004bf868  39d8                   +cmp eax, ebx
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
    // 004bf86a  7eef                   -jle 0x4bf85b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bf85b;
    }
    // 004bf86c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004bf86f:
    // 004bf86f  807c140600             +cmp byte ptr [esp + edx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bf874  75dd                   -jne 0x4bf853
    if (!cpu.flags.zf)
    {
        goto L_0x004bf853;
    }
    // 004bf876  807c140700             +cmp byte ptr [esp + edx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bf87b  75d6                   -jne 0x4bf853
    if (!cpu.flags.zf)
    {
        goto L_0x004bf853;
    }
    // 004bf87d  83fe01                 +cmp esi, 1
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
    // 004bf880  750e                   -jne 0x4bf890
    if (!cpu.flags.zf)
    {
        goto L_0x004bf890;
    }
    // 004bf882  2eff150c654c00         -call dword ptr cs:[0x4c650c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006604) /* 0x4c650c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bf889:
    // 004bf889  a36c0a4e00             -mov dword ptr [0x4e0a6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */) = cpu.eax;
    // 004bf88e  eb06                   -jmp 0x4bf896
    goto L_0x004bf896;
L_0x004bf890:
    // 004bf890  89356c0a4e00           -mov dword ptr [0x4e0a6c], esi
    app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */) = cpu.esi;
L_0x004bf896:
    // 004bf896  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bf898:
    // 004bf898  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bf89b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf89c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf89d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf89e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf89f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf8a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf8a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf8a1  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf8a8  741c                   -je 0x4bf8c6
    if (cpu.flags.zf)
    {
        goto L_0x004bf8c6;
    }
    // 004bf8aa  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004bf8ac  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bf8b1  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004bf8b7  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004bf8b9  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004bf8be  7406                   -je 0x4bf8c6
    if (cpu.flags.zf)
    {
        goto L_0x004bf8c6;
    }
    // 004bf8c0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004bf8c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bf8c6:
    // 004bf8c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bf8cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf8cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf8cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bf8cd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bf8cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf8d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf8d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf8d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bf8d3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bf8d6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bf8d8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bf8da  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf8e0  7c05                   -jl 0x4bf8e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bf8e7;
    }
    // 004bf8e2  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x004bf8e7:
    // 004bf8e7  b9700a4e00             -mov ecx, 0x4e0a70
    cpu.ecx = 5114480 /*0x4e0a70*/;
    // 004bf8ec  eb2e                   -jmp 0x4bf91c
    goto L_0x004bf91c;
L_0x004bf8ee:
    // 004bf8ee  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 004bf8f3  7422                   -je 0x4bf917
    if (cpu.flags.zf)
    {
        goto L_0x004bf917;
    }
    // 004bf8f5  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004bf8f9  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 004bf8fd  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004bf900  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004bf903  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bf906  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bf908  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bf90a  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004bf90d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bf90f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bf911  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bf913  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bf915  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bf917:
    // 004bf917  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 004bf919  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x004bf91c:
    // 004bf91c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bf91e  7fce                   -jg 0x4bf8ee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bf8ee;
    }
    // 004bf920  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bf923  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf924  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf925  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf926  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf927  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf928  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bf920;
    // 004bf8cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bf8cd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bf8cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf8d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf8d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf8d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bf8d3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bf8d6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bf8d8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bf8da  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf8e0  7c05                   -jl 0x4bf8e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bf8e7;
    }
    // 004bf8e2  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x004bf8e7:
    // 004bf8e7  b9700a4e00             -mov ecx, 0x4e0a70
    cpu.ecx = 5114480 /*0x4e0a70*/;
    // 004bf8ec  eb2e                   -jmp 0x4bf91c
    goto L_0x004bf91c;
L_0x004bf8ee:
    // 004bf8ee  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 004bf8f3  7422                   -je 0x4bf917
    if (cpu.flags.zf)
    {
        goto L_0x004bf917;
    }
    // 004bf8f5  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004bf8f9  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 004bf8fd  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004bf900  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004bf903  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bf906  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bf908  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bf90a  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004bf90d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bf90f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bf911  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bf913  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bf915  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bf917:
    // 004bf917  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 004bf919  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x004bf91c:
    // 004bf91c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bf91e  7fce                   -jg 0x4bf8ee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bf8ee;
    }
L_entry_0x004bf920:
    // 004bf920  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bf923  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf924  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf925  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf926  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf927  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf928  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bf929(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf929  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bf92a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bf92c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf92d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf92e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bf92f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bf930  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bf933  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf935  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bf937  74e7                   -je 0x4bf920
    if (cpu.flags.zf)
    {
        return sub_4bf920(app, cpu);
    }
    // 004bf939  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bf93b  9b                     -wait 
    /*nothing*/;
    // 004bf93c  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bf93f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf940  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bf942  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004bf945  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004bf94a  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 004bf94f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf950  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bf953  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf954  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bf956  66895dec               -mov word ptr [ebp - 0x14], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 004bf95a  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 004bf95f  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 004bf962  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004bf965  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bf967  7d1b                   -jge 0x4bf984
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bf984;
    }
    // 004bf969  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bf96c  f7da                   +neg edx
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
    // 004bf96e  e859ffffff             -call 0x4bf8cc
    cpu.esp -= 4;
    sub_4bf8cc(app, cpu);
    if (cpu.terminate) return;
    // 004bf973  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bf975  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bf978  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bf97a  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bf97c  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bf97e  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bf980  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bf982  eb17                   -jmp 0x4bf99b
    goto L_0x004bf99b;
L_0x004bf984:
    // 004bf984  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bf987  e840ffffff             -call 0x4bf8cc
    cpu.esp -= 4;
    sub_4bf8cc(app, cpu);
    if (cpu.terminate) return;
    // 004bf98c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bf98e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bf991  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bf993  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bf995  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bf997  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bf999  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bf99b:
    // 004bf99b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bf99d  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 004bf9a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bf9a1  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bf9a4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf9a5  e976ffffff             -jmp 0x4bf920
    return sub_4bf920(app, cpu);
}

/* align: skip  */
void Application::sub_4bf9aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bf9aa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bf9ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bf9ac  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bf9ae  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bf9b0  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf9b6  7e12                   -jle 0x4bf9ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bf9ca;
    }
    // 004bf9b8  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 004bf9bd  e867ffffff             -call 0x4bf929
    cpu.esp -= 4;
    sub_4bf929(app, cpu);
    if (cpu.terminate) return;
    // 004bf9c2  81eb00100000           +sub ebx, 0x1000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bf9c8  eb18                   -jmp 0x4bf9e2
    goto L_0x004bf9e2;
L_0x004bf9ca:
    // 004bf9ca  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bf9d0  7d10                   -jge 0x4bf9e2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bf9e2;
    }
    // 004bf9d2  ba00f0ffff             -mov edx, 0xfffff000
    cpu.edx = 4294963200 /*0xfffff000*/;
    // 004bf9d7  e84dffffff             -call 0x4bf929
    cpu.esp -= 4;
    sub_4bf929(app, cpu);
    if (cpu.terminate) return;
    // 004bf9dc  81c300100000           -add ebx, 0x1000
    (cpu.ebx) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
L_0x004bf9e2:
    // 004bf9e2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bf9e4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bf9e6  e83effffff             -call 0x4bf929
    cpu.esp -= 4;
    sub_4bf929(app, cpu);
    if (cpu.terminate) return;
    // 004bf9eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf9ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bf9ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bfa04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004bfa04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bfa05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bfa07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bfa08  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bfa09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bfa0a  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004bfa10  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bfa12  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bfa14  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004bfa17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bfa19  9b                     -wait 
    /*nothing*/;
    // 004bfa1a  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bfa1d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfa1e  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004bfa21  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004bfa24  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004bfa29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfa2a  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfa2d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfa2e  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004bfa35  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004bfa39  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 004bfa3d  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004bfa40  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004bfa43  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004bfa45  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004bfa48  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 004bfa4c  7407                   -je 0x4bfa55
    if (cpu.flags.zf)
    {
        goto L_0x004bfa55;
    }
    // 004bfa4e  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x004bfa55:
    // 004bfa55  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004bfa59  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bfa60  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bfa67  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bfa6e  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfa71  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bfa78  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bfa7a  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bfa81  e8ad3d0000             -call 0x4c3833
    cpu.esp -= 4;
    sub_4c3833(app, cpu);
    if (cpu.terminate) return;
    // 004bfa86  83f804                 +cmp eax, 4
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
    // 004bfa89  0f8749010000           -ja 0x4bfbd8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bfbd8;
    }
    // 004bfa8f  2eff2485f0f94b00       -jmp dword ptr cs:[eax*4 + 0x4bf9f0]
    cpu.ip = app->getMemory<x86::reg32>(4979184 + cpu.eax * 4); goto dynamic_jump;
  case 0x004bfa97:
    // 004bfa97  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004bfa9e:
    // 004bfa9e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bfaa0  e933010000             -jmp 0x4bfbd8
    goto L_0x004bfbd8;
  case 0x004bfaa5:
    // 004bfaa5  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfaa8  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 004bfaab  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 004bfaaf  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x004bfab3:
    // 004bfab3  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004bfab7  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 004bfabe  e970030000             -jmp 0x4bfe33
    return sub_4bfe33(app, cpu);
  case 0x004bfac3:
    // 004bfac3  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfac6  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 004bfac9  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 004bfacd  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 004bfad1  ebe0                   -jmp 0x4bfab3
    goto L_0x004bfab3;
  case 0x004bfad3:
    // 004bfad3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfad5  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bfad9  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 004bfadf  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 004bfae5  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 004bfaea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bfaec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bfaef  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bfaf1  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004bfaf4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bfaf6  0f84dc000000           -je 0x4bfbd8
    if (cpu.flags.zf)
    {
        goto L_0x004bfbd8;
    }
    // 004bfafc  7d0f                   -jge 0x4bfb0d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfb0d;
    }
    // 004bfafe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004bfb00  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004bfb03  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004bfb06  f7d9                   +neg ecx
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
    // 004bfb08  e9bf000000             -jmp 0x4bfbcc
    goto L_0x004bfbcc;
L_0x004bfb0d:
    // 004bfb0d  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bfb10  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bfb15  7287                   -jb 0x4bfa9e
    if (cpu.flags.cf)
    {
        goto L_0x004bfa9e;
    }
    // 004bfb17  750d                   -jne 0x4bfb26
    if (!cpu.flags.zf)
    {
        goto L_0x004bfb26;
    }
    // 004bfb19  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfb20  0f8278ffffff           -jb 0x4bfa9e
    if (cpu.flags.cf)
    {
        goto L_0x004bfa9e;
    }
L_0x004bfb26:
    // 004bfb26  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bfb29  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bfb2d  7220                   -jb 0x4bfb4f
    if (cpu.flags.cf)
    {
        goto L_0x004bfb4f;
    }
    // 004bfb2f  0f8594000000           -jne 0x4bfbc9
    if (!cpu.flags.zf)
    {
        goto L_0x004bfbc9;
    }
    // 004bfb35  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bfb38  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfb3e  720f                   -jb 0x4bfb4f
    if (cpu.flags.cf)
    {
        goto L_0x004bfb4f;
    }
    // 004bfb40  0f8583000000           -jne 0x4bfbc9
    if (!cpu.flags.zf)
    {
        goto L_0x004bfbc9;
    }
    // 004bfb46  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfb4d  737a                   -jae 0x4bfbc9
    if (!cpu.flags.cf)
    {
        goto L_0x004bfbc9;
    }
L_0x004bfb4f:
    // 004bfb4f  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 004bfb54  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfb57  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfb5a  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 004bfb5e  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004bfb63  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfb65  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 004bfb68  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfb6b  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 004bfb6e  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfb70  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfb72  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfb74  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfb76  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfb79  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfb7c  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfb7f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfb81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb83  9b                     -wait 
    /*nothing*/;
    // 004bfb84  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bfb87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb89  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 004bfb8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb8d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfb90  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb91  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bfb95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfb98  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb99  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bfb9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb9d  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004bfba0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfba1  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfba3  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfba6  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfba9  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfbab  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfbad  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfbaf  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfbb1  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfbb4  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfbb7  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfbba  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004bfbbf  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfbc1  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfbc3  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfbc5  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfbc7  eb0f                   -jmp 0x4bfbd8
    goto L_0x004bfbd8;
L_0x004bfbc9:
    // 004bfbc9  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x004bfbcc:
    // 004bfbcc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bfbce  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfbd1  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004bfbd3  e8d2fdffff             -call 0x4bf9aa
    cpu.esp -= 4;
    sub_4bf9aa(app, cpu);
    if (cpu.terminate) return;
L_0x004bfbd8:
    // 004bfbd8  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 004bfbdc  7416                   -je 0x4bfbf4
    if (cpu.flags.zf)
    {
        goto L_0x004bfbf4;
    }
    // 004bfbde  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bfbe0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfbe2  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004bfbe5  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004bfbe8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004bfbeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bfbed  7e0d                   -jle 0x4bfbfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfbfc;
    }
    // 004bfbef  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bfbf2  eb08                   -jmp 0x4bfbfc
    goto L_0x004bfbfc;
L_0x004bfbf4:
    // 004bfbf4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bfbf6  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004bfbf9  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004bfbfc:
    // 004bfbfc  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bfbff  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004bfc04  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004bfc07  7405                   -je 0x4bfc0e
    if (cpu.flags.zf)
    {
        goto L_0x004bfc0e;
    }
    // 004bfc09  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x004bfc0e:
    // 004bfc0e  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004bfc12  7402                   -je 0x4bfc16
    if (cpu.flags.zf)
    {
        goto L_0x004bfc16;
    }
    // 004bfc14  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004bfc16:
    // 004bfc16  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfc19  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bfc1c  39d8                   +cmp eax, ebx
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
    // 004bfc1e  7d03                   -jge 0x4bfc23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfc23;
    }
    // 004bfc20  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004bfc23:
    // 004bfc23  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 004bfc2a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004bfc2c  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 004bfc32  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004bfc38  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004bfc3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bfc3d  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004bfc40  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfc43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bfc45  0f8ee8000000           -jle 0x4bfd33
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4bfd33(app, cpu);
    }
    // 004bfc4b  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004bfc4e  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004bfc51  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfc53  7572                   -jne 0x4bfcc7
    if (!cpu.flags.zf)
    {
        goto L_0x004bfcc7;
    }
    // 004bfc55  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 004bfc5b  0f84d2000000           -je 0x4bfd33
    if (cpu.flags.zf)
    {
        return sub_4bfd33(app, cpu);
    }
    // 004bfc61  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfc64  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfc66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc68  9b                     -wait 
    /*nothing*/;
    // 004bfc69  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bfc6c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc6e  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 004bfc71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc72  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfc75  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc76  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bfc7a  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfc7d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc7e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc7f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bfc81  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bfc83  7e42                   -jle 0x4bfcc7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfcc7;
    }
    // 004bfc85  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bfc88  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfc8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc8c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004bfc8f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc90  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfc92  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bfc95  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfc98  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfc9a  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfc9c  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfc9e  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfca0  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 004bfca5  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004bfcaa  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bfcad  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 004bfcb1  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 004bfcb4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bfcb6  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfcb9  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004bfcbc  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfcbf  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfcc1  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfcc3  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfcc5  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bfcc7:
    // 004bfcc7  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bfcca  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bfccc  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004bfccf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bfcd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfcd1  e802000000             -call 0x4bfcd8
    cpu.esp -= 4;
    sub_4bfcd8(app, cpu);
    if (cpu.terminate) return;
    // 004bfcd6  eb45                   -jmp 0x4bfd1d
    return sub_4bfd1d(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4bfc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x004bfc40;
    // 004bfa04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bfa05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bfa07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bfa08  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bfa09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bfa0a  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004bfa10  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bfa12  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bfa14  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004bfa17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bfa19  9b                     -wait 
    /*nothing*/;
    // 004bfa1a  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bfa1d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfa1e  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004bfa21  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004bfa24  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004bfa29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfa2a  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfa2d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfa2e  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004bfa35  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004bfa39  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 004bfa3d  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004bfa40  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004bfa43  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004bfa45  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004bfa48  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 004bfa4c  7407                   -je 0x4bfa55
    if (cpu.flags.zf)
    {
        goto L_0x004bfa55;
    }
    // 004bfa4e  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x004bfa55:
    // 004bfa55  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004bfa59  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bfa60  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bfa67  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bfa6e  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfa71  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bfa78  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bfa7a  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bfa81  e8ad3d0000             -call 0x4c3833
    cpu.esp -= 4;
    sub_4c3833(app, cpu);
    if (cpu.terminate) return;
    // 004bfa86  83f804                 +cmp eax, 4
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
    // 004bfa89  0f8749010000           -ja 0x4bfbd8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bfbd8;
    }
    // 004bfa8f  2eff2485f0f94b00       -jmp dword ptr cs:[eax*4 + 0x4bf9f0]
    cpu.ip = app->getMemory<x86::reg32>(4979184 + cpu.eax * 4); goto dynamic_jump;
  case 0x004bfa97:
    // 004bfa97  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004bfa9e:
    // 004bfa9e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bfaa0  e933010000             -jmp 0x4bfbd8
    goto L_0x004bfbd8;
  case 0x004bfaa5:
    // 004bfaa5  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfaa8  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 004bfaab  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 004bfaaf  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x004bfab3:
    // 004bfab3  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004bfab7  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 004bfabe  e970030000             -jmp 0x4bfe33
    return sub_4bfe33(app, cpu);
  case 0x004bfac3:
    // 004bfac3  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfac6  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 004bfac9  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 004bfacd  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 004bfad1  ebe0                   -jmp 0x4bfab3
    goto L_0x004bfab3;
  case 0x004bfad3:
    // 004bfad3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfad5  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bfad9  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 004bfadf  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 004bfae5  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 004bfaea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bfaec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bfaef  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bfaf1  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004bfaf4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bfaf6  0f84dc000000           -je 0x4bfbd8
    if (cpu.flags.zf)
    {
        goto L_0x004bfbd8;
    }
    // 004bfafc  7d0f                   -jge 0x4bfb0d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfb0d;
    }
    // 004bfafe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004bfb00  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004bfb03  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004bfb06  f7d9                   +neg ecx
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
    // 004bfb08  e9bf000000             -jmp 0x4bfbcc
    goto L_0x004bfbcc;
L_0x004bfb0d:
    // 004bfb0d  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bfb10  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bfb15  7287                   -jb 0x4bfa9e
    if (cpu.flags.cf)
    {
        goto L_0x004bfa9e;
    }
    // 004bfb17  750d                   -jne 0x4bfb26
    if (!cpu.flags.zf)
    {
        goto L_0x004bfb26;
    }
    // 004bfb19  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfb20  0f8278ffffff           -jb 0x4bfa9e
    if (cpu.flags.cf)
    {
        goto L_0x004bfa9e;
    }
L_0x004bfb26:
    // 004bfb26  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bfb29  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bfb2d  7220                   -jb 0x4bfb4f
    if (cpu.flags.cf)
    {
        goto L_0x004bfb4f;
    }
    // 004bfb2f  0f8594000000           -jne 0x4bfbc9
    if (!cpu.flags.zf)
    {
        goto L_0x004bfbc9;
    }
    // 004bfb35  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bfb38  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfb3e  720f                   -jb 0x4bfb4f
    if (cpu.flags.cf)
    {
        goto L_0x004bfb4f;
    }
    // 004bfb40  0f8583000000           -jne 0x4bfbc9
    if (!cpu.flags.zf)
    {
        goto L_0x004bfbc9;
    }
    // 004bfb46  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfb4d  737a                   -jae 0x4bfbc9
    if (!cpu.flags.cf)
    {
        goto L_0x004bfbc9;
    }
L_0x004bfb4f:
    // 004bfb4f  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 004bfb54  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfb57  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfb5a  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 004bfb5e  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004bfb63  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfb65  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 004bfb68  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfb6b  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 004bfb6e  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfb70  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfb72  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfb74  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfb76  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfb79  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfb7c  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfb7f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfb81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb83  9b                     -wait 
    /*nothing*/;
    // 004bfb84  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bfb87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb89  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 004bfb8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb8d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfb90  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb91  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bfb95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfb98  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb99  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfb9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bfb9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfb9d  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004bfba0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfba1  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfba3  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfba6  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004bfba9  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfbab  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfbad  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfbaf  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfbb1  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfbb4  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004bfbb7  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfbba  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004bfbbf  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfbc1  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfbc3  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfbc5  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfbc7  eb0f                   -jmp 0x4bfbd8
    goto L_0x004bfbd8;
L_0x004bfbc9:
    // 004bfbc9  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x004bfbcc:
    // 004bfbcc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bfbce  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfbd1  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004bfbd3  e8d2fdffff             -call 0x4bf9aa
    cpu.esp -= 4;
    sub_4bf9aa(app, cpu);
    if (cpu.terminate) return;
L_0x004bfbd8:
    // 004bfbd8  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 004bfbdc  7416                   -je 0x4bfbf4
    if (cpu.flags.zf)
    {
        goto L_0x004bfbf4;
    }
    // 004bfbde  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bfbe0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfbe2  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004bfbe5  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004bfbe8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004bfbeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bfbed  7e0d                   -jle 0x4bfbfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfbfc;
    }
    // 004bfbef  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bfbf2  eb08                   -jmp 0x4bfbfc
    goto L_0x004bfbfc;
L_0x004bfbf4:
    // 004bfbf4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bfbf6  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004bfbf9  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004bfbfc:
    // 004bfbfc  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bfbff  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004bfc04  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004bfc07  7405                   -je 0x4bfc0e
    if (cpu.flags.zf)
    {
        goto L_0x004bfc0e;
    }
    // 004bfc09  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x004bfc0e:
    // 004bfc0e  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004bfc12  7402                   -je 0x4bfc16
    if (cpu.flags.zf)
    {
        goto L_0x004bfc16;
    }
    // 004bfc14  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004bfc16:
    // 004bfc16  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfc19  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bfc1c  39d8                   +cmp eax, ebx
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
    // 004bfc1e  7d03                   -jge 0x4bfc23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfc23;
    }
    // 004bfc20  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004bfc23:
    // 004bfc23  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 004bfc2a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004bfc2c  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 004bfc32  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004bfc38  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004bfc3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bfc3d  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_entry_0x004bfc40:
    // 004bfc40  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfc43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bfc45  0f8ee8000000           -jle 0x4bfd33
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4bfd33(app, cpu);
    }
    // 004bfc4b  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004bfc4e  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004bfc51  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfc53  7572                   -jne 0x4bfcc7
    if (!cpu.flags.zf)
    {
        goto L_0x004bfcc7;
    }
    // 004bfc55  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 004bfc5b  0f84d2000000           -je 0x4bfd33
    if (cpu.flags.zf)
    {
        return sub_4bfd33(app, cpu);
    }
    // 004bfc61  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfc64  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfc66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc68  9b                     -wait 
    /*nothing*/;
    // 004bfc69  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004bfc6c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc6e  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 004bfc71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc72  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfc75  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc76  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bfc7a  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfc7d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc7e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc7f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bfc81  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bfc83  7e42                   -jle 0x4bfcc7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfcc7;
    }
    // 004bfc85  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bfc88  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfc8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfc8c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004bfc8f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfc90  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfc92  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bfc95  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfc98  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfc9a  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfc9c  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfc9e  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bfca0  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 004bfca5  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004bfcaa  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bfcad  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 004bfcb1  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 004bfcb4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bfcb6  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfcb9  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004bfcbc  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bfcbf  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004bfcc1  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004bfcc3  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bfcc5  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bfcc7:
    // 004bfcc7  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bfcca  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bfccc  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004bfccf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bfcd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfcd1  e802000000             -call 0x4bfcd8
    cpu.esp -= 4;
    sub_4bfcd8(app, cpu);
    if (cpu.terminate) return;
    // 004bfcd6  eb45                   -jmp 0x4bfd1d
    return sub_4bfd1d(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4bfcd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bfcd8  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 004bfcdd  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfcdf  39c8                   +cmp eax, ecx
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
    // 004bfce1  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfce2  7203                   -jb 0x4bfce7
    if (cpu.flags.cf)
    {
        goto L_0x004bfce7;
    }
    // 004bfce4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfce5  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004bfce7:
    // 004bfce7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfce8  e801000000             -call 0x4bfcee
    cpu.esp -= 4;
    sub_4bfcee(app, cpu);
    if (cpu.terminate) return;
    // 004bfced  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfcee  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004bfcf3  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfcf5  39c8                   +cmp eax, ecx
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
    // 004bfcf7  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfcf8  7204                   -jb 0x4bfcfe
    if (cpu.flags.cf)
    {
        goto L_0x004bfcfe;
    }
    // 004bfcfa  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfcfb  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004bfcfe:
    // 004bfcfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfcff  e801000000             -call 0x4bfd05
    cpu.esp -= 4;
    sub_4bfd05(app, cpu);
    if (cpu.terminate) return;
    // 004bfd04  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfd05  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004bfd07  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfd09  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004bfd0b  7204                   -jb 0x4bfd11
    if (cpu.flags.cf)
    {
        goto L_0x004bfd11;
    }
    // 004bfd0d  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004bfd0f  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x004bfd11:
    // 004bfd11  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004bfd14  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004bfd16  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004bfd18  43                     -inc ebx
    (cpu.ebx)++;
    // 004bfd19  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 004bfd1b  43                     -inc ebx
    (cpu.ebx)++;
    // 004bfd1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bfd05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bfd05;
    // 004bfcd8  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 004bfcdd  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfcdf  39c8                   +cmp eax, ecx
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
    // 004bfce1  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfce2  7203                   -jb 0x4bfce7
    if (cpu.flags.cf)
    {
        goto L_0x004bfce7;
    }
    // 004bfce4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfce5  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004bfce7:
    // 004bfce7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfce8  e801000000             -call 0x4bfcee
    cpu.esp -= 4;
    sub_4bfcee(app, cpu);
    if (cpu.terminate) return;
    // 004bfced  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfcee  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004bfcf3  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfcf5  39c8                   +cmp eax, ecx
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
    // 004bfcf7  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfcf8  7204                   -jb 0x4bfcfe
    if (cpu.flags.cf)
    {
        goto L_0x004bfcfe;
    }
    // 004bfcfa  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfcfb  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004bfcfe:
    // 004bfcfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfcff  e801000000             -call 0x4bfd05
    cpu.esp -= 4;
    sub_4bfd05(app, cpu);
    if (cpu.terminate) return;
    // 004bfd04  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004bfd05:
    // 004bfd05  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004bfd07  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfd09  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004bfd0b  7204                   -jb 0x4bfd11
    if (cpu.flags.cf)
    {
        goto L_0x004bfd11;
    }
    // 004bfd0d  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004bfd0f  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x004bfd11:
    // 004bfd11  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004bfd14  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004bfd16  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004bfd18  43                     -inc ebx
    (cpu.ebx)++;
    // 004bfd19  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 004bfd1b  43                     -inc ebx
    (cpu.ebx)++;
    // 004bfd1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bfcee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bfcee;
    // 004bfcd8  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 004bfcdd  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfcdf  39c8                   +cmp eax, ecx
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
    // 004bfce1  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfce2  7203                   -jb 0x4bfce7
    if (cpu.flags.cf)
    {
        goto L_0x004bfce7;
    }
    // 004bfce4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfce5  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004bfce7:
    // 004bfce7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfce8  e801000000             -call 0x4bfcee
    cpu.esp -= 4;
    sub_4bfcee(app, cpu);
    if (cpu.terminate) return;
    // 004bfced  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004bfcee:
    // 004bfcee  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004bfcf3  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfcf5  39c8                   +cmp eax, ecx
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
    // 004bfcf7  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfcf8  7204                   -jb 0x4bfcfe
    if (cpu.flags.cf)
    {
        goto L_0x004bfcfe;
    }
    // 004bfcfa  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bfcfb  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004bfcfe:
    // 004bfcfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfcff  e801000000             -call 0x4bfd05
    cpu.esp -= 4;
    sub_4bfd05(app, cpu);
    if (cpu.terminate) return;
    // 004bfd04  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfd05  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004bfd07  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfd09  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004bfd0b  7204                   -jb 0x4bfd11
    if (cpu.flags.cf)
    {
        goto L_0x004bfd11;
    }
    // 004bfd0d  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004bfd0f  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x004bfd11:
    // 004bfd11  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004bfd14  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004bfd16  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004bfd18  43                     -inc ebx
    (cpu.ebx)++;
    // 004bfd19  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 004bfd1b  43                     -inc ebx
    (cpu.ebx)++;
    // 004bfd1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bfd1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bfd1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfd1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfd1f  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004bfd21  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004bfd23  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 004bfd26  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bfd29  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bfd2b  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004bfd2e  e90dffffff             -jmp 0x4bfc40
    return sub_4bfc40(app, cpu);
}

/* align: skip  */
void Application::sub_4bfd33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bfd33  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004bfd36  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004bfd3c  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004bfd3f:
    // 004bfd3f  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfd42  7505                   -jne 0x4bfd49
    if (!cpu.flags.zf)
    {
        goto L_0x004bfd49;
    }
    // 004bfd44  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bfd45  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bfd46  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bfd47  ebf6                   -jmp 0x4bfd3f
    goto L_0x004bfd3f;
L_0x004bfd49:
    // 004bfd49  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bfd4c  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004bfd4e  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004bfd51  740a                   -je 0x4bfd5d
    if (cpu.flags.zf)
    {
        goto L_0x004bfd5d;
    }
    // 004bfd53  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004bfd56  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004bfd59  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bfd5b  eb15                   -jmp 0x4bfd72
    goto L_0x004bfd72;
L_0x004bfd5d:
    // 004bfd5d  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004bfd60  7410                   -je 0x4bfd72
    if (cpu.flags.zf)
    {
        goto L_0x004bfd72;
    }
    // 004bfd62  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004bfd65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bfd67  7e03                   -jle 0x4bfd6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfd6c;
    }
    // 004bfd69  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bfd6a  eb02                   -jmp 0x4bfd6e
    goto L_0x004bfd6e;
L_0x004bfd6c:
    // 004bfd6c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bfd6e:
    // 004bfd6e  41                     -inc ecx
    (cpu.ecx)++;
    // 004bfd6f  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x004bfd72:
    // 004bfd72  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfd74  0f8c65000000           -jl 0x4bfddf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bfddf;
    }
    // 004bfd7a  39c7                   +cmp edi, eax
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
    // 004bfd7c  7e02                   -jle 0x4bfd80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfd80;
    }
    // 004bfd7e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004bfd80:
    // 004bfd80  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 004bfd85  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 004bfd89  7405                   -je 0x4bfd90
    if (cpu.flags.zf)
    {
        goto L_0x004bfd90;
    }
    // 004bfd8b  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x004bfd90:
    // 004bfd90  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004bfd94  7402                   -je 0x4bfd98
    if (cpu.flags.zf)
    {
        goto L_0x004bfd98;
    }
    // 004bfd96  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bfd98:
    // 004bfd98  39df                   +cmp edi, ebx
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
    // 004bfd9a  7e03                   -jle 0x4bfd9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfd9f;
    }
    // 004bfd9c  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x004bfd9f:
    // 004bfd9f  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 004bfda3  39f8                   +cmp eax, edi
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
    // 004bfda5  7e0a                   -jle 0x4bfdb1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfdb1;
    }
    // 004bfda7  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfdab  7204                   -jb 0x4bfdb1
    if (cpu.flags.cf)
    {
        goto L_0x004bfdb1;
    }
    // 004bfdad  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x004bfdb1:
    // 004bfdb1  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 004bfdb4  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x004bfdb7:
    // 004bfdb7  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bfdba  4b                     -dec ebx
    (cpu.ebx)--;
    // 004bfdbb  48                     -dec eax
    (cpu.eax)--;
    // 004bfdbc  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 004bfdbf  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004bfdc1  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfdc4  38fb                   +cmp bl, bh
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
    // 004bfdc6  7503                   -jne 0x4bfdcb
    if (!cpu.flags.zf)
    {
        goto L_0x004bfdcb;
    }
    // 004bfdc8  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bfdc9  ebec                   -jmp 0x4bfdb7
    goto L_0x004bfdb7;
L_0x004bfdcb:
    // 004bfdcb  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfdce  7506                   -jne 0x4bfdd6
    if (!cpu.flags.zf)
    {
        goto L_0x004bfdd6;
    }
    // 004bfdd0  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004bfdd2  fec7                   -inc bh
    (cpu.bh)++;
    // 004bfdd4  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x004bfdd6:
    // 004bfdd6  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfdda  7d03                   -jge 0x4bfddf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfddf;
    }
    // 004bfddc  4a                     -dec edx
    (cpu.edx)--;
    // 004bfddd  47                     -inc edi
    (cpu.edi)++;
    // 004bfdde  41                     -inc ecx
    (cpu.ecx)++;
L_0x004bfddf:
    // 004bfddf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfde1  7f18                   -jg 0x4bfdfb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bfdfb;
    }
    // 004bfde3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004bfde8  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 004bfdea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfdec  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 004bfdf2  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 004bfdf8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004bfdfb:
    // 004bfdfb  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bfdfe  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004bfe01  7514                   -jne 0x4bfe17
    if (!cpu.flags.zf)
    {
        goto L_0x004bfe17;
    }
    // 004bfe03  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004bfe06  741e                   -je 0x4bfe26
    if (cpu.flags.zf)
    {
        goto L_0x004bfe26;
    }
    // 004bfe08  83f9fc                 +cmp ecx, -4
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
    // 004bfe0b  7c04                   -jl 0x4bfe11
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bfe11;
    }
    // 004bfe0d  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 004bfe0f  7c06                   -jl 0x4bfe17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bfe17;
    }
L_0x004bfe11:
    // 004bfe11  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004bfe15  740f                   -je 0x4bfe26
    if (cpu.flags.zf)
    {
        goto L_0x004bfe26;
    }
L_0x004bfe17:
    // 004bfe17  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfe1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bfe1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bfe1d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bfe1f  e822000000             -call 0x4bfe46
    cpu.esp -= 4;
    sub_4bfe46(app, cpu);
    if (cpu.terminate) return;
    // 004bfe24  eb0d                   -jmp 0x4bfe33
    goto L_0x004bfe33;
L_0x004bfe26:
    // 004bfe26  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfe29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfe2a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bfe2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bfe2e  e831020000             -call 0x4c0064
    cpu.esp -= 4;
    sub_4c0064(app, cpu);
    if (cpu.terminate) return;
L_0x004bfe33:
    // 004bfe33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bfe35  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bfe39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfe3a  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfe3d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe3e  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfe41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bfe33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bfe33;
    // 004bfd33  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004bfd36  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004bfd3c  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004bfd3f:
    // 004bfd3f  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfd42  7505                   -jne 0x4bfd49
    if (!cpu.flags.zf)
    {
        goto L_0x004bfd49;
    }
    // 004bfd44  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bfd45  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bfd46  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bfd47  ebf6                   -jmp 0x4bfd3f
    goto L_0x004bfd3f;
L_0x004bfd49:
    // 004bfd49  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bfd4c  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004bfd4e  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004bfd51  740a                   -je 0x4bfd5d
    if (cpu.flags.zf)
    {
        goto L_0x004bfd5d;
    }
    // 004bfd53  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004bfd56  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004bfd59  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bfd5b  eb15                   -jmp 0x4bfd72
    goto L_0x004bfd72;
L_0x004bfd5d:
    // 004bfd5d  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004bfd60  7410                   -je 0x4bfd72
    if (cpu.flags.zf)
    {
        goto L_0x004bfd72;
    }
    // 004bfd62  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004bfd65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bfd67  7e03                   -jle 0x4bfd6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfd6c;
    }
    // 004bfd69  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bfd6a  eb02                   -jmp 0x4bfd6e
    goto L_0x004bfd6e;
L_0x004bfd6c:
    // 004bfd6c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bfd6e:
    // 004bfd6e  41                     -inc ecx
    (cpu.ecx)++;
    // 004bfd6f  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x004bfd72:
    // 004bfd72  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfd74  0f8c65000000           -jl 0x4bfddf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bfddf;
    }
    // 004bfd7a  39c7                   +cmp edi, eax
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
    // 004bfd7c  7e02                   -jle 0x4bfd80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfd80;
    }
    // 004bfd7e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004bfd80:
    // 004bfd80  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 004bfd85  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 004bfd89  7405                   -je 0x4bfd90
    if (cpu.flags.zf)
    {
        goto L_0x004bfd90;
    }
    // 004bfd8b  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x004bfd90:
    // 004bfd90  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004bfd94  7402                   -je 0x4bfd98
    if (cpu.flags.zf)
    {
        goto L_0x004bfd98;
    }
    // 004bfd96  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bfd98:
    // 004bfd98  39df                   +cmp edi, ebx
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
    // 004bfd9a  7e03                   -jle 0x4bfd9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfd9f;
    }
    // 004bfd9c  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x004bfd9f:
    // 004bfd9f  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 004bfda3  39f8                   +cmp eax, edi
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
    // 004bfda5  7e0a                   -jle 0x4bfdb1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfdb1;
    }
    // 004bfda7  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfdab  7204                   -jb 0x4bfdb1
    if (cpu.flags.cf)
    {
        goto L_0x004bfdb1;
    }
    // 004bfdad  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x004bfdb1:
    // 004bfdb1  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 004bfdb4  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x004bfdb7:
    // 004bfdb7  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004bfdba  4b                     -dec ebx
    (cpu.ebx)--;
    // 004bfdbb  48                     -dec eax
    (cpu.eax)--;
    // 004bfdbc  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 004bfdbf  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004bfdc1  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfdc4  38fb                   +cmp bl, bh
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
    // 004bfdc6  7503                   -jne 0x4bfdcb
    if (!cpu.flags.zf)
    {
        goto L_0x004bfdcb;
    }
    // 004bfdc8  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bfdc9  ebec                   -jmp 0x4bfdb7
    goto L_0x004bfdb7;
L_0x004bfdcb:
    // 004bfdcb  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfdce  7506                   -jne 0x4bfdd6
    if (!cpu.flags.zf)
    {
        goto L_0x004bfdd6;
    }
    // 004bfdd0  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004bfdd2  fec7                   -inc bh
    (cpu.bh)++;
    // 004bfdd4  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x004bfdd6:
    // 004bfdd6  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfdda  7d03                   -jge 0x4bfddf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfddf;
    }
    // 004bfddc  4a                     -dec edx
    (cpu.edx)--;
    // 004bfddd  47                     -inc edi
    (cpu.edi)++;
    // 004bfdde  41                     -inc ecx
    (cpu.ecx)++;
L_0x004bfddf:
    // 004bfddf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfde1  7f18                   -jg 0x4bfdfb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bfdfb;
    }
    // 004bfde3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004bfde8  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 004bfdea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfdec  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 004bfdf2  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 004bfdf8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004bfdfb:
    // 004bfdfb  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bfdfe  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004bfe01  7514                   -jne 0x4bfe17
    if (!cpu.flags.zf)
    {
        goto L_0x004bfe17;
    }
    // 004bfe03  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004bfe06  741e                   -je 0x4bfe26
    if (cpu.flags.zf)
    {
        goto L_0x004bfe26;
    }
    // 004bfe08  83f9fc                 +cmp ecx, -4
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
    // 004bfe0b  7c04                   -jl 0x4bfe11
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bfe11;
    }
    // 004bfe0d  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 004bfe0f  7c06                   -jl 0x4bfe17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bfe17;
    }
L_0x004bfe11:
    // 004bfe11  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004bfe15  740f                   -je 0x4bfe26
    if (cpu.flags.zf)
    {
        goto L_0x004bfe26;
    }
L_0x004bfe17:
    // 004bfe17  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfe1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bfe1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bfe1d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bfe1f  e822000000             -call 0x4bfe46
    cpu.esp -= 4;
    sub_4bfe46(app, cpu);
    if (cpu.terminate) return;
    // 004bfe24  eb0d                   -jmp 0x4bfe33
    goto L_0x004bfe33;
L_0x004bfe26:
    // 004bfe26  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bfe29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfe2a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bfe2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bfe2e  e831020000             -call 0x4c0064
    cpu.esp -= 4;
    sub_4c0064(app, cpu);
    if (cpu.terminate) return;
L_0x004bfe33:
L_entry_0x004bfe33:
    // 004bfe33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bfe35  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bfe39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfe3a  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004bfe3d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe3e  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfe41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bfe45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bfe46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bfe46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bfe47  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bfe49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bfe4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bfe4b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bfe4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfe4f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfe50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bfe51  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bfe53  41                     -inc ecx
    (cpu.ecx)++;
    // 004bfe54  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004bfe57  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004bfe5a  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bfe5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfe5f  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004bfe62  7425                   -je 0x4bfe89
    if (cpu.flags.zf)
    {
        goto L_0x004bfe89;
    }
    // 004bfe64  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfe67  7d0c                   -jge 0x4bfe75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfe75;
    }
    // 004bfe69  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfe6c  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004bfe70  7503                   -jne 0x4bfe75
    if (!cpu.flags.zf)
    {
        goto L_0x004bfe75;
    }
    // 004bfe72  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x004bfe75:
    // 004bfe75  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfe78  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfe7b  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bfe7d  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004bfe80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfe82  7d05                   -jge 0x4bfe89
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfe89;
    }
    // 004bfe84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfe86  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x004bfe89:
    // 004bfe89  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfe8c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bfe8e  0f8fa4000000           -jg 0x4bff38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bff38;
    }
    // 004bfe94  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfe97  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004bfe9b  7526                   -jne 0x4bfec3
    if (!cpu.flags.zf)
    {
        goto L_0x004bfec3;
    }
    // 004bfe9d  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bfea0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bfea2  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bfea4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfea7  42                     -inc edx
    (cpu.edx)++;
    // 004bfea8  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 004bfeab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bfead  7f09                   -jg 0x4bfeb8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bfeb8;
    }
    // 004bfeaf  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfeb2  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004bfeb6  740b                   -je 0x4bfec3
    if (cpu.flags.zf)
    {
        goto L_0x004bfec3;
    }
L_0x004bfeb8:
    // 004bfeb8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bfebb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bfebd  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfebf  42                     -inc edx
    (cpu.edx)++;
    // 004bfec0  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x004bfec3:
    // 004bfec3  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfec6  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bfec9  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfecc  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfecf  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004bfed1  39fe                   +cmp esi, edi
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
    // 004bfed3  7e0a                   -jle 0x4bfedf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfedf;
    }
    // 004bfed5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bfed7  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 004bfeda  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004bfedc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004bfedf:
    // 004bfedf  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfee2  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfee5  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004bfee8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bfeea  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004bfeed  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004bfeef  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bfef2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfef5  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bfef7  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004bfefa  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfefc  7e02                   -jle 0x4bff00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bff00;
    }
    // 004bfefe  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004bff00:
    // 004bff00  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bff03  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bff06  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bff08  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bff0a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bff0b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bff0d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bff0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bff10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bff12  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bff15  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bff17  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bff19  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bff1c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bff1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bff1f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bff20  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff23  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004bff26  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bff29  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bff2b  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bff2d  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff30  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004bff33  e90d010000             -jmp 0x4c0045
    goto L_0x004c0045;
L_0x004bff38:
    // 004bff38  39f3                   +cmp ebx, esi
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
    // 004bff3a  7d70                   -jge 0x4bffac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bffac;
    }
    // 004bff3c  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bff3f  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bff42  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bff44  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bff45  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bff47  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bff49  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bff4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bff4c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bff4f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bff51  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bff53  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bff56  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bff58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bff59  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bff5a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff5d  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004bff60  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bff63  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bff65  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bff67  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff6a  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004bff6d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff70  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bff73  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bff76  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bff79  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004bff7c  7520                   -jne 0x4bff9e
    if (!cpu.flags.zf)
    {
        goto L_0x004bff9e;
    }
    // 004bff7e  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bff82  7f05                   -jg 0x4bff89
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bff89;
    }
    // 004bff84  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 004bff87  7415                   -je 0x4bff9e
    if (cpu.flags.zf)
    {
        goto L_0x004bff9e;
    }
L_0x004bff89:
    // 004bff89  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bff8c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bff8e  01cb                   +add ebx, ecx
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
    // 004bff90  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 004bff93  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff96  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bff97  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x004bff9e:
    // 004bff9e  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bffa1  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bffa4  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bffa7  e999000000             -jmp 0x4c0045
    goto L_0x004c0045;
L_0x004bffac:
    // 004bffac  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bffaf  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bffb1  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bffb4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bffb5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bffb7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bffb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bffba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bffbc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bffbf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bffc1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bffc3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bffc6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bffc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bffc9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bffca  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bffcd  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bffd0  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004bffd3  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bffd5  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bffd7  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004bffda  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004bffdd  7518                   -jne 0x4bfff7
    if (!cpu.flags.zf)
    {
        goto L_0x004bfff7;
    }
    // 004bffdf  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bffe3  7f05                   -jg 0x4bffea
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bffea;
    }
    // 004bffe5  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004bffe8  741c                   -je 0x4c0006
    if (cpu.flags.zf)
    {
        goto L_0x004c0006;
    }
L_0x004bffea:
    // 004bffea  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bffed  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bffef  01c7                   +add edi, eax
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
    // 004bfff1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bfff2  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 004bfff5  eb0f                   -jmp 0x4c0006
    goto L_0x004c0006;
L_0x004bfff7:
    // 004bfff7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bfffa  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfffd  7507                   -jne 0x4c0006
    if (!cpu.flags.zf)
    {
        goto L_0x004c0006;
    }
    // 004bffff  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x004c0006:
    // 004c0006  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0009  39cb                   +cmp ebx, ecx
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
    // 004c000b  7e02                   -jle 0x4c000f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c000f;
    }
    // 004c000d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004c000f:
    // 004c000f  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c0012  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004c0015  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0018  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004c001a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c001c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c001d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c001f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c0021  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0022  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0024  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c0027  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c0029  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c002b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c002e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c0030  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0031  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c0032  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0035  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c0037  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004c003a  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c003d  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c003f  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0042  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x004c0045:
    // 004c0045  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004c0048  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004c004b  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004c004e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c004f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0050  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0051  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c004b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c004b;
    // 004bfe46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bfe47  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bfe49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bfe4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bfe4b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bfe4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bfe4f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bfe50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bfe51  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bfe53  41                     -inc ecx
    (cpu.ecx)++;
    // 004bfe54  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004bfe57  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004bfe5a  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bfe5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bfe5f  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004bfe62  7425                   -je 0x4bfe89
    if (cpu.flags.zf)
    {
        goto L_0x004bfe89;
    }
    // 004bfe64  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfe67  7d0c                   -jge 0x4bfe75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfe75;
    }
    // 004bfe69  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfe6c  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004bfe70  7503                   -jne 0x4bfe75
    if (!cpu.flags.zf)
    {
        goto L_0x004bfe75;
    }
    // 004bfe72  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x004bfe75:
    // 004bfe75  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfe78  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfe7b  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bfe7d  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004bfe80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bfe82  7d05                   -jge 0x4bfe89
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bfe89;
    }
    // 004bfe84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfe86  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x004bfe89:
    // 004bfe89  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfe8c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bfe8e  0f8fa4000000           -jg 0x4bff38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bff38;
    }
    // 004bfe94  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfe97  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004bfe9b  7526                   -jne 0x4bfec3
    if (!cpu.flags.zf)
    {
        goto L_0x004bfec3;
    }
    // 004bfe9d  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bfea0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bfea2  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bfea4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfea7  42                     -inc edx
    (cpu.edx)++;
    // 004bfea8  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 004bfeab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bfead  7f09                   -jg 0x4bfeb8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bfeb8;
    }
    // 004bfeaf  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfeb2  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004bfeb6  740b                   -je 0x4bfec3
    if (cpu.flags.zf)
    {
        goto L_0x004bfec3;
    }
L_0x004bfeb8:
    // 004bfeb8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bfebb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bfebd  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bfebf  42                     -inc edx
    (cpu.edx)++;
    // 004bfec0  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x004bfec3:
    // 004bfec3  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfec6  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bfec9  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfecc  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfecf  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004bfed1  39fe                   +cmp esi, edi
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
    // 004bfed3  7e0a                   -jle 0x4bfedf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bfedf;
    }
    // 004bfed5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bfed7  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 004bfeda  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004bfedc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004bfedf:
    // 004bfedf  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bfee2  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bfee5  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004bfee8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bfeea  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004bfeed  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004bfeef  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bfef2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bfef5  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bfef7  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004bfefa  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bfefc  7e02                   -jle 0x4bff00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bff00;
    }
    // 004bfefe  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004bff00:
    // 004bff00  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bff03  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bff06  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bff08  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bff0a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bff0b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bff0d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bff0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bff10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bff12  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bff15  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bff17  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bff19  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bff1c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bff1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bff1f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bff20  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff23  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004bff26  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bff29  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bff2b  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bff2d  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff30  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004bff33  e90d010000             -jmp 0x4c0045
    goto L_0x004c0045;
L_0x004bff38:
    // 004bff38  39f3                   +cmp ebx, esi
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
    // 004bff3a  7d70                   -jge 0x4bffac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bffac;
    }
    // 004bff3c  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bff3f  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bff42  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bff44  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bff45  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bff47  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bff49  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bff4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bff4c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bff4f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bff51  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bff53  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bff56  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bff58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bff59  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bff5a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff5d  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004bff60  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bff63  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bff65  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bff67  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff6a  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004bff6d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff70  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bff73  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bff76  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bff79  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004bff7c  7520                   -jne 0x4bff9e
    if (!cpu.flags.zf)
    {
        goto L_0x004bff9e;
    }
    // 004bff7e  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bff82  7f05                   -jg 0x4bff89
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bff89;
    }
    // 004bff84  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 004bff87  7415                   -je 0x4bff9e
    if (cpu.flags.zf)
    {
        goto L_0x004bff9e;
    }
L_0x004bff89:
    // 004bff89  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bff8c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bff8e  01cb                   +add ebx, ecx
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
    // 004bff90  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 004bff93  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bff96  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bff97  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x004bff9e:
    // 004bff9e  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bffa1  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bffa4  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bffa7  e999000000             -jmp 0x4c0045
    goto L_0x004c0045;
L_0x004bffac:
    // 004bffac  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bffaf  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bffb1  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004bffb4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bffb5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bffb7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bffb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bffba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bffbc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bffbf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bffc1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bffc3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bffc6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bffc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bffc9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bffca  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bffcd  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bffd0  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004bffd3  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bffd5  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bffd7  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004bffda  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004bffdd  7518                   -jne 0x4bfff7
    if (!cpu.flags.zf)
    {
        goto L_0x004bfff7;
    }
    // 004bffdf  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bffe3  7f05                   -jg 0x4bffea
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bffea;
    }
    // 004bffe5  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004bffe8  741c                   -je 0x4c0006
    if (cpu.flags.zf)
    {
        goto L_0x004c0006;
    }
L_0x004bffea:
    // 004bffea  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bffed  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bffef  01c7                   +add edi, eax
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
    // 004bfff1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bfff2  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 004bfff5  eb0f                   -jmp 0x4c0006
    goto L_0x004c0006;
L_0x004bfff7:
    // 004bfff7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bfffa  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bfffd  7507                   -jne 0x4c0006
    if (!cpu.flags.zf)
    {
        goto L_0x004c0006;
    }
    // 004bffff  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x004c0006:
    // 004c0006  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0009  39cb                   +cmp ebx, ecx
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
    // 004c000b  7e02                   -jle 0x4c000f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c000f;
    }
    // 004c000d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004c000f:
    // 004c000f  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c0012  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004c0015  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0018  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004c001a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c001c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c001d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c001f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c0021  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0022  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0024  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c0027  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c0029  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c002b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c002e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c0030  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0031  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c0032  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0035  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c0037  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004c003a  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c003d  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c003f  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0042  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x004c0045:
    // 004c0045  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004c0048  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_entry_0x004c004b:
    // 004c004b  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004c004e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c004f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0050  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0051  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c0064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004c0064  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c0065  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c0067  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0068  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0069  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c006c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c006d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c006e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c006f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0070  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004c0072  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004c0075  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c0078  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c007b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c007d  7f05                   -jg 0x4c0084
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c0084;
    }
    // 004c007f  0155ec                 +add dword ptr [ebp - 0x14], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0082  eb0e                   -jmp 0x4c0092
    goto L_0x004c0092;
L_0x004c0084:
    // 004c0084  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c0087  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0089  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004c008c  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004c008f  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
L_0x004c0092:
    // 004c0092  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c0095  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c0097  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c009a  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004c009d  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004c00a0  741b                   -je 0x4c00bd
    if (cpu.flags.zf)
    {
        goto L_0x004c00bd;
    }
    // 004c00a2  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004c00a5  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c00a8  7d03                   -jge 0x4c00ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c00ad;
    }
    // 004c00aa  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x004c00ad:
    // 004c00ad  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c00b0  4b                     -dec ebx
    (cpu.ebx)--;
    // 004c00b1  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004c00b4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c00b6  7d05                   -jge 0x4c00bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c00bd;
    }
    // 004c00b8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004c00ba  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
L_0x004c00bd:
    // 004c00bd  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c00c0  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c00c3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c00c5  7f16                   -jg 0x4c00dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c00dd;
    }
    // 004c00c7  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c00ca  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c00cd  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c00d0  01d8                   +add eax, ebx
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
    // 004c00d2  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004c00d5  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 004c00d8  e97c000000             -jmp 0x4c0159
    goto L_0x004c0159;
L_0x004c00dd:
    // 004c00dd  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004c00e0  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004c00e3  39d7                   +cmp edi, edx
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
    // 004c00e5  7e03                   -jle 0x4c00ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c00ea;
    }
    // 004c00e7  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x004c00ea:
    // 004c00ea  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c00ed  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c00f0  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c00f3  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004c00f6  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c00f8  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c00fb  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c00fc  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c00fe  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c0100  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0101  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0103  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c0106  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c0108  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c010a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c010d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c010f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0110  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c0111  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0114  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004c0117  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004c011a  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004c011d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c011f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0121  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004c0124  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 004c0127  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004c012a  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 004c012d  39d8                   +cmp eax, ebx
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
    // 004c012f  7d28                   -jge 0x4c0159
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c0159;
    }
    // 004c0131  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0134  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c0136  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0139  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c013b  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004c0140  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c0143  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0146  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0149  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c014b  e8df24fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c0150  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0153  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004c0156  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x004c0159:
    // 004c0159  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c015c  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c015f  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004c0162  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004c0166  7520                   -jne 0x4c0188
    if (!cpu.flags.zf)
    {
        goto L_0x004c0188;
    }
    // 004c0168  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c016c  7f09                   -jg 0x4c0177
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c0177;
    }
    // 004c016e  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c0171  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004c0175  7411                   -je 0x4c0188
    if (cpu.flags.zf)
    {
        goto L_0x004c0188;
    }
L_0x004c0177:
    // 004c0177  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c017a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c017d  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c0180  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c0182  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004c0185  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x004c0188:
    // 004c0188  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c018b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c018e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c0190  7d25                   -jge 0x4c01b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c01b7;
    }
    // 004c0192  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0195  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0198  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c019a  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004c019d  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004c01a2  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004c01a4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c01a6  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004c01a9  e88124fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c01ae  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c01b1  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004c01b4  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x004c01b7:
    // 004c01b7  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c01ba  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c01bc  7e49                   -jle 0x4c0207
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0207;
    }
    // 004c01be  3b7de0                 +cmp edi, dword ptr [ebp - 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c01c1  7d03                   -jge 0x4c01c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c01c6;
    }
    // 004c01c3  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
L_0x004c01c6:
    // 004c01c6  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004c01c9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c01cb  7426                   -je 0x4c01f3
    if (cpu.flags.zf)
    {
        goto L_0x004c01f3;
    }
    // 004c01cd  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c01d0  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c01d3  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004c01d6  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c01d8  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004c01da  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c01db  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c01dd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c01df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c01e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c01e2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c01e5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c01e7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c01e9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c01ec  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c01ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c01ef  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c01f0  015df4                 -add dword ptr [ebp - 0xc], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004c01f3:
    // 004c01f3  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c01f6  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c01f9  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004c01fc  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004c01ff  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c0202  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004c0204  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004c0207:
    // 004c0207  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c020a  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 004c020e  7416                   -je 0x4c0226
    if (cpu.flags.zf)
    {
        goto L_0x004c0226;
    }
    // 004c0210  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0213  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0216  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c0219  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c021c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c021e  8a520c                 -mov dl, byte ptr [edx + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004c0221  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004c0224  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004c0226:
    // 004c0226  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0229  8b75dc                 -mov esi, dword ptr [ebp - 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c022c  40                     -inc eax
    (cpu.eax)++;
    // 004c022d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c022f  7c0f                   -jl 0x4c0240
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0240;
    }
    // 004c0231  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0234  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004c0237  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c023a  c604022b               -mov byte ptr [edx + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 43 /*0x2b*/;
    // 004c023e  eb14                   -jmp 0x4c0254
    goto L_0x004c0254;
L_0x004c0240:
    // 004c0240  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0243  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c0245  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004c0248  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004c024a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c024d  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004c0250  c604022d               -mov byte ptr [edx + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 45 /*0x2d*/;
L_0x004c0254:
    // 004c0254  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c0257  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c025a  83fb03                 +cmp ebx, 3
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
    // 004c025d  773e                   -ja 0x4c029d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c029d;
    }
    // 004c025f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c0261  2eff248554004c00       -jmp dword ptr cs:[eax*4 + 0x4c0054]
    cpu.ip = app->getMemory<x86::reg32>(4980820 + cpu.eax * 4); goto dynamic_jump;
  case 0x004c0269:
    // 004c0269  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0270  7d26                   -jge 0x4c0298
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c0298;
    }
    // 004c0272  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004c0277  eb24                   -jmp 0x4c029d
    goto L_0x004c029d;
  case 0x004c0279:
    // 004c0279  837ddc0a               +cmp dword ptr [ebp - 0x24], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c027d  7c05                   -jl 0x4c0284
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0284;
    }
    // 004c027f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
  [[fallthrough]];
  case 0x004c0284:
L_0x004c0284:
    // 004c0284  837ddc64               +cmp dword ptr [ebp - 0x24], 0x64
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0288  7c05                   -jl 0x4c028f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c028f;
    }
    // 004c028a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
  [[fallthrough]];
  case 0x004c028f:
L_0x004c028f:
    // 004c028f  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0296  7c05                   -jl 0x4c029d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c029d;
    }
L_0x004c0298:
    // 004c0298  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x004c029d:
    // 004c029d  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c02a0  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004c02a3  83fb04                 +cmp ebx, 4
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
    // 004c02a6  7c4b                   -jl 0x4c02f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c02f3;
    }
    // 004c02a8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c02aa  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c02ad  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004c02b0  3de8030000             +cmp eax, 0x3e8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c02b5  7c26                   -jl 0x4c02dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c02dd;
    }
    // 004c02b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c02b9  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 004c02be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c02c1  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004c02c3  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c02c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c02c8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004c02cb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c02cd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c02d0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c02d2  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c02d5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004c02d8  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c02da  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x004c02dd:
    // 004c02dd  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c02e0  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c02e3  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c02e6  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c02e9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c02eb  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004c02ee  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004c02f1  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004c02f3:
    // 004c02f3  83fb03                 +cmp ebx, 3
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
    // 004c02f6  7c49                   -jl 0x4c0341
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0341;
    }
    // 004c02f8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c02fa  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c02fd  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004c0300  83f864                 +cmp eax, 0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0303  7c26                   -jl 0x4c032b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c032b;
    }
    // 004c0305  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0307  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 004c030c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c030f  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004c0311  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c0314  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0316  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c0319  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c031b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004c031e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c0320  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c0323  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c0326  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0328  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x004c032b:
    // 004c032b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c032e  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0331  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c0334  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0337  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c0339  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004c033c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004c033f  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004c0341:
    // 004c0341  83fb02                 +cmp ebx, 2
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
    // 004c0344  7c43                   -jl 0x4c0389
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0389;
    }
    // 004c0346  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c0348  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c034b  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004c034e  83f80a                 +cmp eax, 0xa
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
    // 004c0351  7c20                   -jl 0x4c0373
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0373;
    }
    // 004c0353  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0355  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004c035a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c035d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004c035f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c0362  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0364  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c0367  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c0369  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c036c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c036e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0370  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x004c0373:
    // 004c0373  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0376  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0379  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c037c  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c037f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0381  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004c0384  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004c0387  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004c0389:
    // 004c0389  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c038c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c038f  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c0392  8a55dc                 -mov dl, byte ptr [ebp - 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c0395  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c0397  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004c039a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c039c  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c039f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c03a1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004c03a4  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c03a6  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c03a9  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004c03ac  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 004c03af  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004c03b2  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004c03b5  e991fcffff             -jmp 0x4c004b
    return sub_4c004b(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4c03ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c03ba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c03bb  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c03bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c03be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c03bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c03c0  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004c03c3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c03c5  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004c03c8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004c03cb:
    // 004c03cb  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c03cd  80fa20                 +cmp dl, 0x20
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
    // 004c03d0  740a                   -je 0x4c03dc
    if (cpu.flags.zf)
    {
        goto L_0x004c03dc;
    }
    // 004c03d2  80fa09                 +cmp dl, 9
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
    // 004c03d5  7208                   -jb 0x4c03df
    if (cpu.flags.cf)
    {
        goto L_0x004c03df;
    }
    // 004c03d7  80fa0d                 +cmp dl, 0xd
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c03da  7703                   -ja 0x4c03df
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c03df;
    }
L_0x004c03dc:
    // 004c03dc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c03dd  ebec                   -jmp 0x4c03cb
    goto L_0x004c03cb;
L_0x004c03df:
    // 004c03df  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c03e2  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004c03e4  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c03e7  7407                   -je 0x4c03f0
    if (cpu.flags.zf)
    {
        goto L_0x004c03f0;
    }
    // 004c03e9  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c03ec  7504                   -jne 0x4c03f2
    if (!cpu.flags.zf)
    {
        goto L_0x004c03f2;
    }
    // 004c03ee  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004c03f0:
    // 004c03f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004c03f2:
    // 004c03f2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c03f4  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 004c03f6  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x004c03f9:
    // 004c03f9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c03fb  40                     -inc eax
    (cpu.eax)++;
    // 004c03fc  80fa2e                 +cmp dl, 0x2e
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
    // 004c03ff  750a                   -jne 0x4c040b
    if (!cpu.flags.zf)
    {
        goto L_0x004c040b;
    }
    // 004c0401  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004c0404  752d                   -jne 0x4c0433
    if (!cpu.flags.zf)
    {
        goto L_0x004c0433;
    }
    // 004c0406  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004c0409  ebee                   -jmp 0x4c03f9
    goto L_0x004c03f9;
L_0x004c040b:
    // 004c040b  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c040e  7223                   -jb 0x4c0433
    if (cpu.flags.cf)
    {
        goto L_0x004c0433;
    }
    // 004c0410  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c0413  771e                   -ja 0x4c0433
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c0433;
    }
    // 004c0415  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004c0418  7403                   -je 0x4c041d
    if (cpu.flags.zf)
    {
        goto L_0x004c041d;
    }
    // 004c041a  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x004c041d:
    // 004c041d  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004c041f  80fe30                 +cmp dh, 0x30
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c0422  740a                   -je 0x4c042e
    if (cpu.flags.zf)
    {
        goto L_0x004c042e;
    }
    // 004c0424  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0427  7d04                   -jge 0x4c042d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c042d;
    }
    // 004c0429  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x004c042d:
    // 004c042d  43                     -inc ebx
    (cpu.ebx)++;
L_0x004c042e:
    // 004c042e  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004c0431  ebc6                   -jmp 0x4c03f9
    goto L_0x004c03f9;
L_0x004c0433:
    // 004c0433  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004c0435  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004c0438  0f8465000000           -je 0x4c04a3
    if (cpu.flags.zf)
    {
        goto L_0x004c04a3;
    }
    // 004c043e  80fa65                 +cmp dl, 0x65
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c0441  7405                   -je 0x4c0448
    if (cpu.flags.zf)
    {
        goto L_0x004c0448;
    }
    // 004c0443  80fa45                 +cmp dl, 0x45
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c0446  7557                   -jne 0x4c049f
    if (!cpu.flags.zf)
    {
        goto L_0x004c049f;
    }
L_0x004c0448:
    // 004c0448  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004c044b  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004c044d  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004c0450  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c0453  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c0456  7408                   -je 0x4c0460
    if (cpu.flags.zf)
    {
        goto L_0x004c0460;
    }
    // 004c0458  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c045b  7505                   -jne 0x4c0462
    if (!cpu.flags.zf)
    {
        goto L_0x004c0462;
    }
    // 004c045d  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004c0460:
    // 004c0460  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c0462:
    // 004c0462  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x004c0465:
    // 004c0465  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c0467  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c046a  7222                   -jb 0x4c048e
    if (cpu.flags.cf)
    {
        goto L_0x004c048e;
    }
    // 004c046c  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c046f  771d                   -ja 0x4c048e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c048e;
    }
    // 004c0471  81fee8030000           +cmp esi, 0x3e8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0477  7d0f                   -jge 0x4c0488
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c0488;
    }
    // 004c0479  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004c047c  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 004c047f  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 004c0482  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004c0485  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x004c0488:
    // 004c0488  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004c048b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c048c  ebd7                   -jmp 0x4c0465
    goto L_0x004c0465;
L_0x004c048e:
    // 004c048e  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004c0491  7402                   -je 0x4c0495
    if (cpu.flags.zf)
    {
        goto L_0x004c0495;
    }
    // 004c0493  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x004c0495:
    // 004c0495  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004c0498  7506                   -jne 0x4c04a0
    if (!cpu.flags.zf)
    {
        goto L_0x004c04a0;
    }
    // 004c049a  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c049d  eb01                   -jmp 0x4c04a0
    goto L_0x004c04a0;
L_0x004c049f:
    // 004c049f  48                     -dec eax
    (cpu.eax)--;
L_0x004c04a0:
    // 004c04a0  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004c04a3:
    // 004c04a3  837de800               +cmp dword ptr [ebp - 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c04a7  7408                   -je 0x4c04b1
    if (cpu.flags.zf)
    {
        goto L_0x004c04b1;
    }
    // 004c04a9  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c04ac  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004c04af  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004c04b1:
    // 004c04b1  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004c04b4  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c04b7  7e0a                   -jle 0x4c04c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c04c3;
    }
    // 004c04b9  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 004c04bc  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c04be  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x004c04c3:
    // 004c04c3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c04c5  7e0b                   -jle 0x4c04d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c04d2;
    }
    // 004c04c7  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-65) /* -0x41 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c04cc  7504                   -jne 0x4c04d2
    if (!cpu.flags.zf)
    {
        goto L_0x004c04d2;
    }
    // 004c04ce  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c04cf  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004c04d0  ebf1                   -jmp 0x4c04c3
    goto L_0x004c04c3;
L_0x004c04d2:
    // 004c04d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c04d4  7511                   -jne 0x4c04e7
    if (!cpu.flags.zf)
    {
        goto L_0x004c04e7;
    }
    // 004c04d6  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004c04dc  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004c04df  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c04e1  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004c04e3  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004c04e5  eb5f                   -jmp 0x4c0546
    goto L_0x004c0546;
L_0x004c04e7:
    // 004c04e7  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c04e9  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004c04ec  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 004c04f0  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004c04f3  e88c330000             -call 0x4c3884
    cpu.esp -= 4;
    sub_4c3884(app, cpu);
    if (cpu.terminate) return;
    // 004c04f8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c04fa  740a                   -je 0x4c0506
    if (cpu.flags.zf)
    {
        goto L_0x004c0506;
    }
    // 004c04fc  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004c04ff  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c0501  e8a4f4ffff             -call 0x4bf9aa
    cpu.esp -= 4;
    sub_4bf9aa(app, cpu);
    if (cpu.terminate) return;
L_0x004c0506:
    // 004c0506  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004c0509  7404                   -je 0x4c050f
    if (cpu.flags.zf)
    {
        goto L_0x004c050f;
    }
    // 004c050b  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004c050f:
    // 004c050f  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004c0512  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004c0516  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004c0519  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c051c  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004c051f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004c0521  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 004c0525  3d34010000             +cmp eax, 0x134
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(308 /*0x134*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c052a  7e07                   -jle 0x4c0533
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0533;
    }
    // 004c052c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004c0531  eb13                   -jmp 0x4c0546
    goto L_0x004c0546;
L_0x004c0533:
    // 004c0533  3dccfeffff             +cmp eax, 0xfffffecc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966988 /*0xfffffecc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0538  7d07                   -jge 0x4c0541
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c0541;
    }
    // 004c053a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004c053f  eb05                   -jmp 0x4c0546
    goto L_0x004c0546;
L_0x004c0541:
    // 004c0541  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004c0546:
    // 004c0546  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c0549  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c054a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c054b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c054c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c054d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c054e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c054e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c054f  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c0551  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0552  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004c0555  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c0557  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c055a  e85bfeffff             -call 0x4c03ba
    cpu.esp -= 4;
    sub_4c03ba(app, cpu);
    if (cpu.terminate) return;
    // 004c055f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0561  7508                   -jne 0x4c056b
    if (!cpu.flags.zf)
    {
        goto L_0x004c056b;
    }
    // 004c0563  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004c0566:
    // 004c0566  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004c0569  eb59                   -jmp 0x4c05c4
    goto L_0x004c05c4;
L_0x004c056b:
    // 004c056b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c056e  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004c0571  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004c0576  3dff430000             +cmp eax, 0x43ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17407 /*0x43ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c057b  7c27                   -jl 0x4c05a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c05a4;
    }
    // 004c057d  e84361feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
    // 004c0582  f645f180               +test byte ptr [ebp - 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) & 128 /*0x80*/));
    // 004c0586  740d                   -je 0x4c0595
    if (cpu.flags.zf)
    {
        goto L_0x004c0595;
    }
    // 004c0588  dd05e01f4d00           +fld qword ptr [0x4d1fe0]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5054432) /* 0x4d1fe0 */)));
    // 004c058e  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004c0590  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c0593  eb2f                   -jmp 0x4c05c4
    goto L_0x004c05c4;
L_0x004c0595:
    // 004c0595  a1e01f4d00             -mov eax, dword ptr [0x4d1fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054432) /* 0x4d1fe0 */);
    // 004c059a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004c059d  a1e41f4d00             -mov eax, dword ptr [0x4d1fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054436) /* 0x4d1fe4 */);
    // 004c05a2  ebc2                   -jmp 0x4c0566
    goto L_0x004c0566;
L_0x004c05a4:
    // 004c05a4  3dcd3b0000             +cmp eax, 0x3bcd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15309 /*0x3bcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c05a9  7d0f                   -jge 0x4c05ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c05ba;
    }
    // 004c05ab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c05ad  e81361feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
    // 004c05b2  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004c05b5  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004c05b8  eb0a                   -jmp 0x4c05c4
    goto L_0x004c05c4;
L_0x004c05ba:
    // 004c05ba  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004c05bd  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004c05c0  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004c05c2  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004c05c4:
    // 004c05c4  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004c05c7  8d65fc                 -lea esp, [ebp - 4]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004c05ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c05cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c05cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c05cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c05cd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c05ce  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c05d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c05d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c05d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c05d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c05d4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c05d7  8a5510                 -mov dl, byte ptr [ebp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004c05da  80fa01                 +cmp dl, 1
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
    // 004c05dd  7231                   -jb 0x4c0610
    if (cpu.flags.cf)
    {
        goto L_0x004c0610;
    }
    // 004c05df  80fa03                 +cmp dl, 3
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c05e2  7607                   -jbe 0x4c05eb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c05eb;
    }
    // 004c05e4  80fa04                 +cmp dl, 4
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
    // 004c05e7  7413                   -je 0x4c05fc
    if (cpu.flags.zf)
    {
        goto L_0x004c05fc;
    }
    // 004c05e9  eb25                   -jmp 0x4c0610
    goto L_0x004c0610;
L_0x004c05eb:
    // 004c05eb  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004c05ed  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004c05ef  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c05f4  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c05f7  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004c05fa  eb36                   -jmp 0x4c0632
    goto L_0x004c0632;
L_0x004c05fc:
    // 004c05fc  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004c05fe  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004c0601  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004c0603  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004c0604  760a                   -jbe 0x4c0610
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c0610;
    }
    // 004c0606  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c0608  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004c060b  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004c060e  eb2a                   -jmp 0x4c063a
    goto L_0x004c063a;
L_0x004c0610:
    // 004c0610  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0612  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004c0614  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004c0616  80cf81                 -or bh, 0x81
    cpu.bh |= x86::reg8(x86::sreg8(129 /*0x81*/));
    // 004c0619  80fa06                 +cmp dl, 6
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c061c  750f                   -jne 0x4c062d
    if (!cpu.flags.zf)
    {
        goto L_0x004c062d;
    }
    // 004c061e  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004c0620  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004c0623  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004c0625  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004c0626  7605                   -jbe 0x4c062d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c062d;
    }
    // 004c0628  80cd11                 -or ch, 0x11
    cpu.ch |= x86::reg8(x86::sreg8(17 /*0x11*/));
    // 004c062b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004c062d:
    // 004c062d  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c0630  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004c0632:
    // 004c0632  e8f0320000             -call 0x4c3927
    cpu.esp -= 4;
    sub_4c3927(app, cpu);
    if (cpu.terminate) return;
    // 004c0637  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004c063a:
    // 004c063a  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004c063d  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0640  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0641  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0642  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0643  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0644  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0645  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c0648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0648  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0649  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c064a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c064d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c064f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c0651  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0653  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c0655  e8b2330000             -call 0x4c3a0c
    cpu.esp -= 4;
    sub_4c3a0c(app, cpu);
    if (cpu.terminate) return;
    // 004c065a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c065c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c065e  e83ef2ffff             -call 0x4bf8a1
    cpu.esp -= 4;
    sub_4bf8a1(app, cpu);
    if (cpu.terminate) return;
    // 004c0663  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004c0666  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c066a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c066c  e89b330000             -call 0x4c3a0c
    cpu.esp -= 4;
    sub_4c3a0c(app, cpu);
    if (cpu.terminate) return;
    // 004c0671  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0673  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004c0675  e827f2ffff             -call 0x4bf8a1
    cpu.esp -= 4;
    sub_4bf8a1(app, cpu);
    if (cpu.terminate) return;
    // 004c067a  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 004c067e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c0680  e8b8330000             -call 0x4c3a3d
    cpu.esp -= 4;
    sub_4c3a3d(app, cpu);
    if (cpu.terminate) return;
    // 004c0685  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0689  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c068d  e8ab330000             -call 0x4c3a3d
    cpu.esp -= 4;
    sub_4c3a3d(app, cpu);
    if (cpu.terminate) return;
    // 004c0692  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c0694  e8f3330000             -call 0x4c3a8c
    cpu.esp -= 4;
    sub_4c3a8c(app, cpu);
    if (cpu.terminate) return;
    // 004c0699  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c069c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c069d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c069e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c069f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c069f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c06a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c06a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c06a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c06a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c06a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c06a5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c06a8  b8fc1d4d00             -mov eax, 0x4d1dfc
    cpu.eax = 5053948 /*0x4d1dfc*/;
    // 004c06ad  e81bfdfeff             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 004c06b2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c06b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c06b6  0f84f9000000           -je 0x4c07b5
    if (cpu.flags.zf)
    {
        goto L_0x004c07b5;
    }
L_0x004c06bc:
    // 004c06bc  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c06bf  0f84e6000000           -je 0x4c07ab
    if (cpu.flags.zf)
    {
        goto L_0x004c07ab;
    }
    // 004c06c5  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 004c06c7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004c06c9:
    // 004c06c9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c06cb  3ac2                   +cmp al, dl
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
    // 004c06cd  7412                   -je 0x4c06e1
    if (cpu.flags.zf)
    {
        goto L_0x004c06e1;
    }
    // 004c06cf  3c00                   +cmp al, 0
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
    // 004c06d1  740c                   -je 0x4c06df
    if (cpu.flags.zf)
    {
        goto L_0x004c06df;
    }
    // 004c06d3  46                     -inc esi
    (cpu.esi)++;
    // 004c06d4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c06d6  3ac2                   +cmp al, dl
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
    // 004c06d8  7407                   -je 0x4c06e1
    if (cpu.flags.zf)
    {
        goto L_0x004c06e1;
    }
    // 004c06da  46                     -inc esi
    (cpu.esi)++;
    // 004c06db  3c00                   +cmp al, 0
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
    // 004c06dd  75ea                   -jne 0x4c06c9
    if (!cpu.flags.zf)
    {
        goto L_0x004c06c9;
    }
L_0x004c06df:
    // 004c06df  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004c06e1:
    // 004c06e1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c06e3  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004c06e5  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c06e7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c06e9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c06eb  e8ec5dfcff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 004c06f0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004c06f5  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c06f7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c06f9  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 004c06fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c06fe  e82a350000             -call 0x4c3c2d
    cpu.esp -= 4;
    sub_4c3c2d(app, cpu);
    if (cpu.terminate) return;
    // 004c0703  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004c0706  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 004c0708  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c070a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004c070c:
    // 004c070c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c070e  3ac2                   +cmp al, dl
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
    // 004c0710  7412                   -je 0x4c0724
    if (cpu.flags.zf)
    {
        goto L_0x004c0724;
    }
    // 004c0712  3c00                   +cmp al, 0
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
    // 004c0714  740c                   -je 0x4c0722
    if (cpu.flags.zf)
    {
        goto L_0x004c0722;
    }
    // 004c0716  46                     -inc esi
    (cpu.esi)++;
    // 004c0717  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c0719  3ac2                   +cmp al, dl
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
    // 004c071b  7407                   -je 0x4c0724
    if (cpu.flags.zf)
    {
        goto L_0x004c0724;
    }
    // 004c071d  46                     -inc esi
    (cpu.esi)++;
    // 004c071e  3c00                   +cmp al, 0
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
    // 004c0720  75ea                   -jne 0x4c070c
    if (!cpu.flags.zf)
    {
        goto L_0x004c070c;
    }
L_0x004c0722:
    // 004c0722  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004c0724:
    // 004c0724  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c0726  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004c0728  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c072a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c072c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c072e  e8a95dfcff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 004c0733  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004c0738  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004c073a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c073c  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 004c073f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0741  e8e7340000             -call 0x4c3c2d
    cpu.esp -= 4;
    sub_4c3c2d(app, cpu);
    if (cpu.terminate) return;
    // 004c0746  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004c0749  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 004c074b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c074f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004c0751:
    // 004c0751  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c0753  3ac2                   +cmp al, dl
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
    // 004c0755  7412                   -je 0x4c0769
    if (cpu.flags.zf)
    {
        goto L_0x004c0769;
    }
    // 004c0757  3c00                   +cmp al, 0
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
    // 004c0759  740c                   -je 0x4c0767
    if (cpu.flags.zf)
    {
        goto L_0x004c0767;
    }
    // 004c075b  46                     -inc esi
    (cpu.esi)++;
    // 004c075c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c075e  3ac2                   +cmp al, dl
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
    // 004c0760  7407                   -je 0x4c0769
    if (cpu.flags.zf)
    {
        goto L_0x004c0769;
    }
    // 004c0762  46                     -inc esi
    (cpu.esi)++;
    // 004c0763  3c00                   +cmp al, 0
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
    // 004c0765  75ea                   -jne 0x4c0751
    if (!cpu.flags.zf)
    {
        goto L_0x004c0751;
    }
L_0x004c0767:
    // 004c0767  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004c0769:
    // 004c0769  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c076b  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004c076d  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c076f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0771  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c0773  e8645dfcff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 004c0778  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c077a  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004c077c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c077e  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 004c0781  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004c0786  e8a2340000             -call 0x4c3c2d
    cpu.esp -= 4;
    sub_4c3c2d(app, cpu);
    if (cpu.terminate) return;
    // 004c078b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c078d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004c078f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c0793  e8d677ffff             -call 0x4b7f6e
    cpu.esp -= 4;
    sub_4b7f6e(app, cpu);
    if (cpu.terminate) return;
    // 004c0798  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c079a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c079c  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004c079f  e8297affff             -call 0x4b81cd
    cpu.esp -= 4;
    sub_4b81cd(app, cpu);
    if (cpu.terminate) return;
    // 004c07a4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c07a6  e911ffffff             -jmp 0x4c06bc
    goto L_0x004c06bc;
L_0x004c07ab:
    // 004c07ab  b8081e4d00             -mov eax, 0x4d1e08
    cpu.eax = 5053960 /*0x4d1e08*/;
    // 004c07b0  e8d1340000             -call 0x4c3c86
    cpu.esp -= 4;
    sub_4c3c86(app, cpu);
    if (cpu.terminate) return;
L_0x004c07b5:
    // 004c07b5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c07b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c07bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c07bf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c07c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c07c1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c07c3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x004c07c5:
    // 004c07c5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c07c7  7505                   -jne 0x4c07ce
    if (!cpu.flags.zf)
    {
        goto L_0x004c07ce;
    }
L_0x004c07c9:
    // 004c07c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c07cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c07cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c07ce:
    // 004c07ce  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004c07d1  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004c07d4  f6c4ff                 +test ah, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 255 /*0xff*/));
    // 004c07d7  7525                   -jne 0x4c07fe
    if (!cpu.flags.zf)
    {
        goto L_0x004c07fe;
    }
    // 004c07d9  f6c6ff                 +test dh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 255 /*0xff*/));
    // 004c07dc  7520                   -jne 0x4c07fe
    if (!cpu.flags.zf)
    {
        goto L_0x004c07fe;
    }
    // 004c07de  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c07e2  720b                   -jb 0x4c07ef
    if (cpu.flags.cf)
    {
        goto L_0x004c07ef;
    }
    // 004c07e4  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c07e8  7705                   -ja 0x4c07ef
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c07ef;
    }
    // 004c07ea  0520000000             -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004c07ef:
    // 004c07ef  6683fa41               +cmp dx, 0x41
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c07f3  7209                   -jb 0x4c07fe
    if (cpu.flags.cf)
    {
        goto L_0x004c07fe;
    }
    // 004c07f5  6683fa5a               +cmp dx, 0x5a
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c07f9  7703                   -ja 0x4c07fe
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c07fe;
    }
    // 004c07fb  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004c07fe:
    // 004c07fe  6639d0                 +cmp ax, dx
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.dx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0801  740b                   -je 0x4c080e
    if (cpu.flags.zf)
    {
        goto L_0x004c080e;
    }
    // 004c0803  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 004c0806  0fb7da                 -movzx ebx, dx
    cpu.ebx = x86::reg32(cpu.dx);
    // 004c0809  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c080b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c080c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c080d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c080e:
    // 004c080e  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004c0811  74b6                   -je 0x4c07c9
    if (cpu.flags.zf)
    {
        goto L_0x004c07c9;
    }
    // 004c0813  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c0814  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c0815  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c0816  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c0817  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004c0818  ebab                   -jmp 0x4c07c5
    goto L_0x004c07c5;
}

/* align: skip  */
void Application::sub_4c081a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c081a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c081b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c081c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c081d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c081e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c081f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c0820  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c0823  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0825  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c082a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c082e  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c0831  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004c0836  e8ee370000             -call 0x4c4029
    cpu.esp -= 4;
    sub_4c4029(app, cpu);
    if (cpu.terminate) return;
    // 004c083b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c083d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c083f  7458                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c0841  39c8                   +cmp eax, ecx
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
    // 004c0843  7454                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c0845  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c0847  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0849  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004c084b  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004c084d  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004c0850  e86e5dfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c0855  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c0857  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c085b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c085d  743a                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c085f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004c0861  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0863  e815a8ffff             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004c0868  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004c086b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c086d  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 004c0873  e83ca7ffff             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004c0878  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c087a  743d                   -je 0x4c08b9
    if (cpu.flags.zf)
    {
        goto L_0x004c08b9;
    }
    // 004c087c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c087e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c0882  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c0885  e8395dfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c088a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c088c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c088e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0890  7511                   -jne 0x4c08a3
    if (!cpu.flags.zf)
    {
        goto L_0x004c08a3;
    }
L_0x004c0892:
    // 004c0892  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0894  e85facfeff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004c0899:
    // 004c0899  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c089e  e998000000             -jmp 0x4c093b
    goto L_0x004c093b;
L_0x004c08a3:
    // 004c08a3  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c08a7  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c08ab  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c08ad  e8cba7ffff             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004c08b2  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 004c08b7  eb02                   -jmp 0x4c08bb
    goto L_0x004c08bb;
L_0x004c08b9:
    // 004c08b9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c08bb:
    // 004c08bb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c08bf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c08c1  e8d8a5ffff             -call 0x4bae9e
    cpu.esp -= 4;
    sub_4bae9e(app, cpu);
    if (cpu.terminate) return;
    // 004c08c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c08c8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c08cc  e827acfeff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c08d1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c08d3  e820acfeff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c08d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c08da  74bd                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c08dc  833d38945b0000         +cmp dword ptr [0x5b9438], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c08e3  7505                   -jne 0x4c08ea
    if (!cpu.flags.zf)
    {
        goto L_0x004c08ea;
    }
    // 004c08e5  e87aa6ffff             -call 0x4baf64
    cpu.esp -= 4;
    sub_4baf64(app, cpu);
    if (cpu.terminate) return;
L_0x004c08ea:
    // 004c08ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c08ec  e854000000             -call 0x4c0945
    cpu.esp -= 4;
    sub_4c0945(app, cpu);
    if (cpu.terminate) return;
    // 004c08f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c08f3  75a4                   -jne 0x4c0899
    if (!cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c08f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c08f7  e8b8a6ffff             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004c08fc  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c08ff  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0903  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004c0906  e8b85cfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c090b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c090d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c090f  750f                   -jne 0x4c0920
    if (!cpu.flags.zf)
    {
        goto L_0x004c0920;
    }
    // 004c0911  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004c0916  e8465cfeff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004c091b  e979ffffff             -jmp 0x4c0899
    goto L_0x004c0899;
L_0x004c0920:
    // 004c0920  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004c0924  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0926  e89ca6ffff             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004c092b  83f8ff                 +cmp eax, -1
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
    // 004c092e  0f845effffff           -je 0x4c0892
    if (cpu.flags.zf)
    {
        goto L_0x004c0892;
    }
    // 004c0934  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0936  e8a3340000             -call 0x4c3dde
    cpu.esp -= 4;
    sub_4c3dde(app, cpu);
    if (cpu.terminate) return;
L_0x004c093b:
    // 004c093b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c093e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c093f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0940  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0941  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0944  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c093e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c093e;
    // 004c081a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c081b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c081c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c081d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c081e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c081f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c0820  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c0823  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0825  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c082a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c082e  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c0831  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004c0836  e8ee370000             -call 0x4c4029
    cpu.esp -= 4;
    sub_4c4029(app, cpu);
    if (cpu.terminate) return;
    // 004c083b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c083d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c083f  7458                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c0841  39c8                   +cmp eax, ecx
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
    // 004c0843  7454                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c0845  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c0847  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0849  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004c084b  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004c084d  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004c0850  e86e5dfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c0855  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c0857  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c085b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c085d  743a                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c085f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004c0861  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0863  e815a8ffff             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004c0868  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004c086b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c086d  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 004c0873  e83ca7ffff             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004c0878  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c087a  743d                   -je 0x4c08b9
    if (cpu.flags.zf)
    {
        goto L_0x004c08b9;
    }
    // 004c087c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c087e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c0882  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c0885  e8395dfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c088a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c088c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c088e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0890  7511                   -jne 0x4c08a3
    if (!cpu.flags.zf)
    {
        goto L_0x004c08a3;
    }
L_0x004c0892:
    // 004c0892  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0894  e85facfeff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004c0899:
    // 004c0899  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c089e  e998000000             -jmp 0x4c093b
    goto L_0x004c093b;
L_0x004c08a3:
    // 004c08a3  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c08a7  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c08ab  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c08ad  e8cba7ffff             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004c08b2  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 004c08b7  eb02                   -jmp 0x4c08bb
    goto L_0x004c08bb;
L_0x004c08b9:
    // 004c08b9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c08bb:
    // 004c08bb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c08bf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c08c1  e8d8a5ffff             -call 0x4bae9e
    cpu.esp -= 4;
    sub_4bae9e(app, cpu);
    if (cpu.terminate) return;
    // 004c08c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c08c8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c08cc  e827acfeff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c08d1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c08d3  e820acfeff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c08d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c08da  74bd                   -je 0x4c0899
    if (cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c08dc  833d38945b0000         +cmp dword ptr [0x5b9438], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c08e3  7505                   -jne 0x4c08ea
    if (!cpu.flags.zf)
    {
        goto L_0x004c08ea;
    }
    // 004c08e5  e87aa6ffff             -call 0x4baf64
    cpu.esp -= 4;
    sub_4baf64(app, cpu);
    if (cpu.terminate) return;
L_0x004c08ea:
    // 004c08ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c08ec  e854000000             -call 0x4c0945
    cpu.esp -= 4;
    sub_4c0945(app, cpu);
    if (cpu.terminate) return;
    // 004c08f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c08f3  75a4                   -jne 0x4c0899
    if (!cpu.flags.zf)
    {
        goto L_0x004c0899;
    }
    // 004c08f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c08f7  e8b8a6ffff             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004c08fc  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c08ff  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0903  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004c0906  e8b85cfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c090b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c090d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c090f  750f                   -jne 0x4c0920
    if (!cpu.flags.zf)
    {
        goto L_0x004c0920;
    }
    // 004c0911  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004c0916  e8465cfeff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004c091b  e979ffffff             -jmp 0x4c0899
    goto L_0x004c0899;
L_0x004c0920:
    // 004c0920  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004c0924  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0926  e89ca6ffff             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004c092b  83f8ff                 +cmp eax, -1
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
    // 004c092e  0f845effffff           -je 0x4c0892
    if (cpu.flags.zf)
    {
        goto L_0x004c0892;
    }
    // 004c0934  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0936  e8a3340000             -call 0x4c3dde
    cpu.esp -= 4;
    sub_4c3dde(app, cpu);
    if (cpu.terminate) return;
L_0x004c093b:
    // 004c093b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_entry_0x004c093e:
    // 004c093e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c093f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0940  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0941  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0944  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c0945(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0945  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0946  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0947  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c0948  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0949  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c094a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c094b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c094e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c0950  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0952  750a                   -jne 0x4c095e
    if (!cpu.flags.zf)
    {
        goto L_0x004c095e;
    }
L_0x004c0954:
    // 004c0954  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c0959  e92b010000             -jmp 0x4c0a89
    goto L_0x004c0a89;
L_0x004c095e:
    // 004c095e  66833800               +cmp word ptr [eax], 0
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
    // 004c0962  7416                   -je 0x4c097a
    if (cpu.flags.zf)
    {
        goto L_0x004c097a;
    }
    // 004c0964  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004c0967  eb09                   -jmp 0x4c0972
    goto L_0x004c0972;
L_0x004c0969:
    // 004c0969  6683f93d               +cmp cx, 0x3d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c096d  740b                   -je 0x4c097a
    if (cpu.flags.zf)
    {
        goto L_0x004c097a;
    }
    // 004c096f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004c0972:
    // 004c0972  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004c0975  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004c0978  75ef                   -jne 0x4c0969
    if (!cpu.flags.zf)
    {
        goto L_0x004c0969;
    }
L_0x004c097a:
    // 004c097a  66833a00               +cmp word ptr [edx], 0
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
    // 004c097e  74d4                   -je 0x4c0954
    if (cpu.flags.zf)
    {
        goto L_0x004c0954;
    }
    // 004c0980  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0985  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004c0988  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c098a  8b0d38945b00           -mov ecx, dword ptr [0x5b9438]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004c0990  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004c0992  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c0994  7531                   -jne 0x4c09c7
    if (!cpu.flags.zf)
    {
        goto L_0x004c09c7;
    }
    // 004c0996  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c0998  0f85e9000000           -jne 0x4c0a87
    if (!cpu.flags.zf)
    {
        goto L_0x004c0a87;
    }
    // 004c099e  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004c09a3  e81b5cfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c09a8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c09aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c09ac  74a6                   -je 0x4c0954
    if (cpu.flags.zf)
    {
        goto L_0x004c0954;
    }
    // 004c09ae  a338945b00             -mov dword ptr [0x5b9438], eax
    app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */) = cpu.eax;
    // 004c09b3  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004c09b5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c09b8  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004c09ba  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004c09bd  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 004c09c2  e9b2000000             -jmp 0x4c0a79
    goto L_0x004c0a79;
L_0x004c09c7:
    // 004c09c7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c09c9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c09cb  e8c1000000             -call 0x4c0a91
    cpu.esp -= 4;
    sub_4c0a91(app, cpu);
    if (cpu.terminate) return;
    // 004c09d0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c09d2  0f85af000000           -jne 0x4c0a87
    if (!cpu.flags.zf)
    {
        goto L_0x004c0a87;
    }
    // 004c09d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c09da  0f8f96000000           -jg 0x4c0a76
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c0a76;
    }
    // 004c09e0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004c09e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c09e4  8b2d30945b00           -mov ebp, dword ptr [0x5b9430]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c09ea  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c09ec  40                     -inc eax
    (cpu.eax)++;
    // 004c09ed  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004c09f0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c09f4  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004c09f7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c09fb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004c09fe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c0a00  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c0a02  7533                   -jne 0x4c0a37
    if (!cpu.flags.zf)
    {
        goto L_0x004c0a37;
    }
    // 004c0a04  e8ba5bfeff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c0a09  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c0a0b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0a0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0a0f  0f843fffffff           -je 0x4c0954
    if (cpu.flags.zf)
    {
        goto L_0x004c0954;
    }
    // 004c0a15  8b1538945b00           -mov edx, dword ptr [0x5b9438]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004c0a1b  e85da6ffff             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004c0a20  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c0a23  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0a27  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004c0a29  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c0a2b  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 004c0a30  e8fa1bfdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c0a35  eb2d                   -jmp 0x4c0a64
    goto L_0x004c0a64;
L_0x004c0a37:
    // 004c0a37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0a39  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0a3b  e8abfefeff             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004c0a40  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0a42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0a44  0f840affffff           -je 0x4c0954
    if (cpu.flags.zf)
    {
        goto L_0x004c0954;
    }
    // 004c0a4a  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004c0a4d  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c0a53  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0a55  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c0a57  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c0a59  e807fffeff             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 004c0a5e  892d30945b00           -mov dword ptr [0x5b9430], ebp
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ebp;
L_0x004c0a64:
    // 004c0a64  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0a66  890d38945b00           -mov dword ptr [0x5b9438], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */) = cpu.ecx;
    // 004c0a6c  c744810400000000       -mov dword ptr [ecx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004c0a74  eb03                   -jmp 0x4c0a79
    goto L_0x004c0a79;
L_0x004c0a76:
    // 004c0a76  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004c0a79:
    // 004c0a79  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0a7b  893c81                 -mov dword ptr [ecx + eax*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = cpu.edi;
    // 004c0a7e  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c0a83  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x004c0a87:
    // 004c0a87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c0a89:
    // 004c0a89  83c408                 +add esp, 8
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
    // 004c0a8c  e9adfeffff             -jmp 0x4c093e
    return sub_4c093e(app, cpu);
}

/* align: skip  */
void Application::sub_4c0a91(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0a91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0a92  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0a93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0a94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0a95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c0a96  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c0a98  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c0a9a  8b3538945b00           -mov esi, dword ptr [0x5b9438]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004c0aa0  e9bb000000             -jmp 0x4c0b60
    goto L_0x004c0b60;
L_0x004c0aa5:
    // 004c0aa5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004c0aa7  e9a7000000             -jmp 0x4c0b53
    goto L_0x004c0b53;
L_0x004c0aac:
    // 004c0aac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0aae  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004c0ab1  e804a6ffff             -call 0x4bb0ba
    cpu.esp -= 4;
    sub_4bb0ba(app, cpu);
    if (cpu.terminate) return;
    // 004c0ab6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0ab8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0aba  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004c0abd  e8f8a5ffff             -call 0x4bb0ba
    cpu.esp -= 4;
    sub_4bb0ba(app, cpu);
    if (cpu.terminate) return;
    // 004c0ac2  6639c1                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0ac5  0f8592000000           -jne 0x4c0b5d
    if (!cpu.flags.zf)
    {
        goto L_0x004c0b5d;
    }
    // 004c0acb  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0acf  0f8578000000           -jne 0x4c0b4d
    if (!cpu.flags.zf)
    {
        goto L_0x004c0b4d;
    }
    // 004c0ad5  8b1538945b00           -mov edx, dword ptr [0x5b9438]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004c0adb  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c0add  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0adf  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004c0ae2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c0ae4  7462                   -je 0x4c0b48
    if (cpu.flags.zf)
    {
        goto L_0x004c0b48;
    }
    // 004c0ae6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c0ae8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c0aea  eb08                   -jmp 0x4c0af4
    goto L_0x004c0af4;
L_0x004c0aec:
    // 004c0aec  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004c0aef  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004c0af1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004c0af4:
    // 004c0af4  833900                 +cmp dword ptr [ecx], 0
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
    // 004c0af7  75f3                   -jne 0x4c0aec
    if (!cpu.flags.zf)
    {
        goto L_0x004c0aec;
    }
    // 004c0af9  8b3530945b00           -mov esi, dword ptr [0x5b9430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c0aff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c0b01  7441                   -je 0x4c0b44
    if (cpu.flags.zf)
    {
        goto L_0x004c0b44;
    }
    // 004c0b03  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0b05  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c0b09  7407                   -je 0x4c0b12
    if (cpu.flags.zf)
    {
        goto L_0x004c0b12;
    }
    // 004c0b0b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c0b0d  e8e6a9feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004c0b12:
    // 004c0b12  8b2d38945b00           -mov ebp, dword ptr [0x5b9438]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004c0b18  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c0b1a  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c0b1c  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c0b22  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004c0b25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0b27  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c0b29  e837fefeff             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 004c0b2e  890d30945b00           -mov dword ptr [0x5b9430], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ecx;
    // 004c0b34  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004c0b37  eb07                   -jmp 0x4c0b40
    goto L_0x004c0b40;
L_0x004c0b39:
    // 004c0b39  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c0b3c  47                     -inc edi
    (cpu.edi)++;
    // 004c0b3d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c0b3f  40                     -inc eax
    (cpu.eax)++;
L_0x004c0b40:
    // 004c0b40  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0b42  7cf5                   -jl 0x4c0b39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0b39;
    }
L_0x004c0b44:
    // 004c0b44  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c0b46  eb2c                   -jmp 0x4c0b74
    goto L_0x004c0b74;
L_0x004c0b48:
    // 004c0b48  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c0b4b  eb27                   -jmp 0x4c0b74
    goto L_0x004c0b74;
L_0x004c0b4d:
    // 004c0b4d  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c0b50  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004c0b53:
    // 004c0b53  66833b00               +cmp word ptr [ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0b57  0f854fffffff           -jne 0x4c0aac
    if (!cpu.flags.zf)
    {
        goto L_0x004c0aac;
    }
L_0x004c0b5d:
    // 004c0b5d  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004c0b60:
    // 004c0b60  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c0b62  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c0b64  0f853bffffff           -jne 0x4c0aa5
    if (!cpu.flags.zf)
    {
        goto L_0x004c0aa5;
    }
    // 004c0b6a  a138945b00             -mov eax, dword ptr [0x5b9438]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004c0b6f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c0b71  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004c0b74:
    // 004c0b74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0b75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0b76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0b77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0b78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0b79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c0b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0b80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0b81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0b82  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c0b86  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c0b88  7c3b                   -jl 0x4c0bc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0bc5;
    }
L_0x004c0b8a:
    // 004c0b8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c0b8c  7c3b                   -jl 0x4c0bc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0bc9;
    }
L_0x004c0b8e:
    // 004c0b8e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c0b91  39f2                   +cmp edx, esi
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
    // 004c0b93  7e02                   -jle 0x4c0b97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0b97;
    }
    // 004c0b95  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004c0b97:
    // 004c0b97  39f1                   +cmp ecx, esi
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
    // 004c0b99  7e02                   -jle 0x4c0b9d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0b9d;
    }
    // 004c0b9b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004c0b9d:
    // 004c0b9d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c0b9f  7c2c                   -jl 0x4c0bcd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0bcd;
    }
L_0x004c0ba1:
    // 004c0ba1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c0ba3  7c2c                   -jl 0x4c0bd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c0bd1;
    }
L_0x004c0ba5:
    // 004c0ba5  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c0ba8  39f3                   +cmp ebx, esi
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
    // 004c0baa  7e02                   -jle 0x4c0bae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0bae;
    }
    // 004c0bac  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004c0bae:
    // 004c0bae  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0bb0  7e02                   -jle 0x4c0bb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0bb4;
    }
    // 004c0bb2  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004c0bb4:
    // 004c0bb4  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004c0bb7  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004c0bba  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004c0bbd  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004c0bc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0bc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0bc2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004c0bc5:
    // 004c0bc5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c0bc7  ebc1                   -jmp 0x4c0b8a
    goto L_0x004c0b8a;
L_0x004c0bc9:
    // 004c0bc9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c0bcb  ebc1                   -jmp 0x4c0b8e
    goto L_0x004c0b8e;
L_0x004c0bcd:
    // 004c0bcd  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004c0bcf  ebd0                   -jmp 0x4c0ba1
    goto L_0x004c0ba1;
L_0x004c0bd1:
    // 004c0bd1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004c0bd3  ebd0                   -jmp 0x4c0ba5
    goto L_0x004c0ba5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c0be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0be0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0be1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0be2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c0be3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c0be6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c0be8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c0bea  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004c0bee  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004c0bf0  39d8                   +cmp eax, ebx
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
    // 004c0bf2  0f8f84000000           -jg 0x4c0c7c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c0c7c;
    }
L_0x004c0bf8:
    // 004c0bf8  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0bfa  7d06                   -jge 0x4c0c02
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c0c02;
    }
    // 004c0bfc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c0bfe  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004c0c00  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004c0c02:
    // 004c0c02  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c0c06  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c0c08  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c0c0c  40                     -inc eax
    (cpu.eax)++;
    // 004c0c0d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004c0c0f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004c0c12  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c0c14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0c15  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004c0c17  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004c0c1c  48                     -dec eax
    (cpu.eax)--;
    // 004c0c1d  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0c21  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c0c25  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0c27  47                     -inc edi
    (cpu.edi)++;
    // 004c0c28  e8f379fcff             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 004c0c2d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c0c31  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0c35  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c0c39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0c3a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004c0c3c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c0c41  e8da79fcff             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 004c0c46  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c0c4a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c0c4e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c0c53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c0c54  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004c0c56  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0c58  e8c379fcff             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 004c0c5d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c0c61  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004c0c66  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c0c69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c0c6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0c6c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c0c6e  e8ad79fcff             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 004c0c73  83c40c                 +add esp, 0xc
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
    // 004c0c76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0c77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0c78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0c79  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004c0c7c:
    // 004c0c7c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004c0c7e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c0c82  e971ffffff             -jmp 0x4c0bf8
    goto L_0x004c0bf8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c0c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0c91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c0c92  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004c0c98  8d842418010000         -lea eax, [esp + 0x118]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004c0c9f  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004c0ca6  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004c0cad  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 004c0cb4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c0cb6  e8c933feff             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 004c0cbb  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004c0cc2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c0cc4  e813000000             -call 0x4c0cdc
    cpu.esp -= 4;
    sub_4c0cdc(app, cpu);
    if (cpu.terminate) return;
    // 004c0cc9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0ccb  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 004c0cd2  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004c0cd8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0cd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0cda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4c0cdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0cdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0cdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0cde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0cdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0ce0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0ce2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c0ce4  e83b17fcff             -call 0x482424
    cpu.esp -= 4;
    sub_482424(app, cpu);
    if (cpu.terminate) return;
    // 004c0ce9  8b157cab4d00           -mov edx, dword ptr [0x4dab7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004c0cef  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0cf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c0cf3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c0cf6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0cf8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004c0cfa  8b3decd64d00           -mov edi, dword ptr [0x4dd6ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */);
    // 004c0d00  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c0d02  8b35f0d64d00           -mov esi, dword ptr [0x4dd6f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */);
    // 004c0d08  e8eb64fcff             -call 0x4871f8
    cpu.esp -= 4;
    sub_4871f8(app, cpu);
    if (cpu.terminate) return;
    // 004c0d0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0d0f  e8c45afcff             -call 0x4867d8
    cpu.esp -= 4;
    sub_4867d8(app, cpu);
    if (cpu.terminate) return;
    // 004c0d14  893decd64d00           -mov dword ptr [0x4dd6ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */) = cpu.edi;
    // 004c0d1a  8935f0d64d00           -mov dword ptr [0x4dd6f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */) = cpu.esi;
    // 004c0d20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d24  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
