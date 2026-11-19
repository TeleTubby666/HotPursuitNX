#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 */
void Application::sub_471430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00471430);
    // 00471430  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471431  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471432  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471435  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00471438  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047143a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047143c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047143f  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471442  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471444  0f8481000000           -je 0x4714cb
    if (cpu.flags.zf)
    {
        goto L_0x004714cb;
    }
    // 0047144a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047144b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047144c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047144e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471450  7e5d                   -jle 0x4714af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004714af;
    }
L_0x00471452:
    // 00471452  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471455  7549                   -jne 0x4714a0
    if (!cpu.flags.zf)
    {
        goto L_0x004714a0;
    }
    // 00471457  3b6a10                 +cmp ebp, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047145a  7544                   -jne 0x4714a0
    if (!cpu.flags.zf)
    {
        goto L_0x004714a0;
    }
    // 0047145c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471460  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00471462  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00471465  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00471468  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047146a  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0047146d  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471470  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00471472:
    // 00471472  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471476  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00471479  48                     -dec eax
    (cpu.eax)--;
    // 0047147a  39c5                   +cmp ebp, eax
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
    // 0047147c  7d31                   -jge 0x4714af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004714af;
    }
    // 0047147e  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00471483  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471485  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00471487  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471488  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047148a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047148d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047148f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471491  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471494  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471496  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471497  45                     -inc ebp
    (cpu.ebp)++;
    // 00471498  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047149b  83c210                 +add edx, 0x10
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
    // 0047149e  ebd2                   -jmp 0x471472
    goto L_0x00471472;
L_0x004714a0:
    // 004714a0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004714a4  43                     -inc ebx
    (cpu.ebx)++;
    // 004714a5  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004714a8  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004714ab  39fb                   +cmp ebx, edi
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
    // 004714ad  7ca3                   -jl 0x471452
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471452;
    }
L_0x004714af:
    // 004714af  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004714b3  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004714b6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004714ba  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004714bd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004714bf  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 004714c6  ff4f04                 -dec dword ptr [edi + 4]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))--;
    // 004714c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004714cb:
    // 004714cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004714ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4714e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004714e0);
    // 004714e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004714e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004714e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004714e3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004714e6  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004714ea  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004714ee  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004714f1  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004714f5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004714f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004714fa  41                     -inc ecx
    (cpu.ecx)++;
    // 004714fb  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004714ff  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00471502  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471504  7e22                   -jle 0x471528
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471528;
    }
    // 00471506  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00471508:
    // 00471508  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047150c  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047150f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00471513  39f8                   +cmp eax, edi
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
    // 00471515  7c39                   -jl 0x471550
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471550;
    }
    // 00471517  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047151b  42                     -inc edx
    (cpu.edx)++;
    // 0047151c  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047151f  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471522  39f2                   +cmp edx, esi
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
    // 00471524  7ce2                   -jl 0x471508
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471508;
    }
    // 00471526  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00471528:
    // 00471528  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047152c  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471530  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00471533  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00471535  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471539  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047153c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471540  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00471543  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00471546  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00471549  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047154c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047154d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047154e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047154f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471550:
    // 00471550  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471554  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00471557  48                     -dec eax
    (cpu.eax)--;
    // 00471558  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047155c  39c2                   +cmp edx, eax
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
    // 0047155e  7dc8                   -jge 0x471528
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471528;
    }
    // 00471560  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00471564  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471568  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047156b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047156e  8d2c03                 -lea ebp, [ebx + eax]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00471571  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471574  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00471576:
    // 00471576  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0047157b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047157d  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047157f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471580  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471582  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471585  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471587  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471589  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047158c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047158e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047158f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00471593  83ed10                 -sub ebp, 0x10
    (cpu.ebp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471596  48                     -dec eax
    (cpu.eax)--;
    // 00471597  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047159a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047159e  39c2                   +cmp edx, eax
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
    // 004715a0  7cd4                   -jl 0x471576
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471576;
    }
    // 004715a2  eb84                   -jmp 0x471528
    goto L_0x00471528;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4715b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004715b0);
    // 004715b0  e947330100             -jmp 0x4848fc
    return sub_4848fc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4715c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004715c0);
    // 004715c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004715c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004715c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004715c3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004715c5  c705d8b14d00d0de4c00   -mov dword ptr [0x4db1d8], 0x4cded0
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = 5037776 /*0x4cded0*/;
    // 004715cf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004715d1  b956000000             -mov ecx, 0x56
    cpu.ecx = 86 /*0x56*/;
    // 004715d6  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004715d9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004715db  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004715de  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 004715e4  e8af2e0100             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004715e9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004715f0  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004715f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004715f4  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004715f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004715f8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004715fa  7e18                   -jle 0x471614
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471614;
    }
L_0x004715fc:
    // 004715fc  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 00471603  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047160a  42                     -inc edx
    (cpu.edx)++;
    // 0047160b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047160d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471610  39f2                   +cmp edx, esi
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
    // 00471612  7ce8                   -jl 0x4715fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004715fc;
    }
L_0x00471614:
    // 00471614  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471616  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471618  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471619  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00471620);
    // 00471620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471622  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00471624  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471626  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00471628  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047162a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047162c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047162f  c1e204                 +shl edx, 4
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
    // 00471632  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00471634  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00471637  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471639  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047163c  c1e210                 +shl edx, 0x10
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
    // 0047163f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00471641  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00471644  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471646  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471649  7c05                   -jl 0x471650
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471650;
    }
    // 0047164b  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00471650:
    // 00471650  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00471657  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00471659  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047165c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047165e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471660  8a820c964d00           -mov al, byte ptr [edx + 0x4d960c]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5084684) /* 0x4d960c */);
    // 00471666  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00471669  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047166d  8b909c954d00           -mov edx, dword ptr [eax + 0x4d959c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5084572) /* 0x4d959c */);
    // 00471673  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00471675  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00471679  8b90d4954d00           -mov edx, dword ptr [eax + 0x4d95d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5084628) /* 0x4d95d4 */);
    // 0047167f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00471681  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471685  8b90b8954d00           -mov edx, dword ptr [eax + 0x4d95b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5084600) /* 0x4d95b8 */);
    // 0047168b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0047168d  833d480f540000         +cmp dword ptr [0x540f48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471694  7525                   -jne 0x4716bb
    if (!cpu.flags.zf)
    {
        goto L_0x004716bb;
    }
    // 00471696  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00471698:
    // 00471698  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0047169d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047169f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004716a2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004716a4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004716a6  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004716a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004716ab  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004716ad  39c8                   +cmp eax, ecx
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
    // 004716af  7512                   -jne 0x4716c3
    if (!cpu.flags.zf)
    {
        goto L_0x004716c3;
    }
    // 004716b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004716b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004716bb:
    // 004716bb  8b88f0954d00           -mov ecx, dword ptr [eax + 0x4d95f0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5084656) /* 0x4d95f0 */);
    // 004716c1  ebd5                   -jmp 0x471698
    goto L_0x00471698;
L_0x004716c3:
    // 004716c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004716c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716c7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4716d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004716d0);
    // 004716d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004716d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004716d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004716d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004716d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004716d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004716d6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004716d9  b406                   -mov ah, 6
    cpu.ah = 6 /*0x6*/;
    // 004716db  be4c2f5100             -mov esi, 0x512f4c
    cpu.esi = 5320524 /*0x512f4c*/;
    // 004716e0  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004716e4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004716e9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004716eb  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004716ee  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 004716f3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004716f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004716f8:
    // 004716f8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004716fa  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004716fc  3c00                   +cmp al, 0
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
    // 004716fe  7410                   -je 0x471710
    if (cpu.flags.zf)
    {
        goto L_0x00471710;
    }
    // 00471700  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00471703  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471706  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00471709  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047170c  3c00                   +cmp al, 0
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
    // 0047170e  75e8                   -jne 0x4716f8
    if (!cpu.flags.zf)
    {
        goto L_0x004716f8;
    }
L_0x00471710:
    // 00471710  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471711  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471713  e85829ffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 00471718  66833d3034510000       +cmp word ptr [0x513430], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5321776) /* 0x513430 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471720  7517                   -jne 0x471739
    if (!cpu.flags.zf)
    {
        goto L_0x00471739;
    }
L_0x00471722:
    // 00471722  e84927ffff             -call 0x463e70
    cpu.esp -= 4;
    sub_463e70(app, cpu);
    if (cpu.terminate) return;
    // 00471727  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471729  0f85a3000000           -jne 0x4717d2
    if (!cpu.flags.zf)
    {
        goto L_0x004717d2;
    }
    // 0047172f  66833d3034510000       +cmp word ptr [0x513430], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5321776) /* 0x513430 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471737  74e9                   -je 0x471722
    if (cpu.flags.zf)
    {
        goto L_0x00471722;
    }
L_0x00471739:
    // 00471739  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047173b  8a155e345100           -mov dl, byte ptr [0x51345e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5321822) /* 0x51345e */);
    // 00471741  66890d30345100         -mov word ptr [0x513430], cx
    app->getMemory<x86::reg16>(x86::reg32(5321776) /* 0x513430 */) = cpu.cx;
    // 00471748  80fa02                 +cmp dl, 2
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047174b  0f8509010000           -jne 0x47185a
    if (!cpu.flags.zf)
    {
        goto L_0x0047185a;
    }
    // 00471751  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471755  8b15080f5400           -mov edx, dword ptr [0x540f08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508872) /* 0x540f08 */);
    // 0047175b  39d0                   +cmp eax, edx
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
    // 0047175d  7e77                   -jle 0x4717d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004717d6;
    }
    // 0047175f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00471764  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00471766  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471768  892d0c225100           -mov dword ptr [0x51220c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */) = cpu.ebp;
L_0x0047176e:
    // 0047176e  66a30c345100           -mov word ptr [0x51340c], ax
    app->getMemory<x86::reg16>(x86::reg32(5321740) /* 0x51340c */) = cpu.ax;
    // 00471774  66893d58345100         -mov word ptr [0x513458], di
    app->getMemory<x86::reg16>(x86::reg32(5321816) /* 0x513458 */) = cpu.di;
L_0x0047177b:
    // 0047177b  be0c0f5400             -mov esi, 0x540f0c
    cpu.esi = 5508876 /*0x540f0c*/;
    // 00471780  bf78335100             -mov edi, 0x513378
    cpu.edi = 5321592 /*0x513378*/;
    // 00471785  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00471786:
    // 00471786  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00471788  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047178a  3c00                   +cmp al, 0
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
    // 0047178c  7410                   -je 0x47179e
    if (cpu.flags.zf)
    {
        goto L_0x0047179e;
    }
    // 0047178e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00471791  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471794  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00471797  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047179a  3c00                   +cmp al, 0
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
    // 0047179c  75e8                   -jne 0x471786
    if (!cpu.flags.zf)
    {
        goto L_0x00471786;
    }
L_0x0047179e:
    // 0047179e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047179f  be4c2f5100             -mov esi, 0x512f4c
    cpu.esi = 5320524 /*0x512f4c*/;
    // 004717a4  bfc1335100             -mov edi, 0x5133c1
    cpu.edi = 5321665 /*0x5133c1*/;
    // 004717a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004717aa:
    // 004717aa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004717ac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004717ae  3c00                   +cmp al, 0
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
    // 004717b0  7410                   -je 0x4717c2
    if (cpu.flags.zf)
    {
        goto L_0x004717c2;
    }
    // 004717b2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004717b5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004717b8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004717bb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004717be  3c00                   +cmp al, 0
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
    // 004717c0  75e8                   -jne 0x4717aa
    if (!cpu.flags.zf)
    {
        goto L_0x004717aa;
    }
L_0x004717c2:
    // 004717c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717c3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004717c8:
    // 004717c8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004717cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004717d2:
    // 004717d2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004717d4  ebf2                   -jmp 0x4717c8
    goto L_0x004717c8;
L_0x004717d6:
    // 004717d6  7d2d                   -jge 0x471805
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471805;
    }
    // 004717d8  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004717dd  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004717e2  66890d58345100         -mov word ptr [0x513458], cx
    app->getMemory<x86::reg16>(x86::reg32(5321816) /* 0x513458 */) = cpu.cx;
    // 004717e9  893d0c225100           -mov dword ptr [0x51220c], edi
    app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */) = cpu.edi;
    // 004717ef  6689350c345100         -mov word ptr [0x51340c], si
    app->getMemory<x86::reg16>(x86::reg32(5321740) /* 0x51340c */) = cpu.si;
    // 004717f6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004717fb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004717fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471800  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471801  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471802  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471803  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471804  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471805:
    // 00471805  ba0c0f5400             -mov edx, 0x540f0c
    cpu.edx = 5508876 /*0x540f0c*/;
    // 0047180a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047180e  e80d1f0100             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 00471813  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471815  7c16                   -jl 0x47182d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047182d;
    }
    // 00471817  7eb9                   -jle 0x4717d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004717d2;
    }
    // 00471819  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047181e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471820  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00471822  891d0c225100           -mov dword ptr [0x51220c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */) = cpu.ebx;
    // 00471828  e941ffffff             -jmp 0x47176e
    goto L_0x0047176e;
L_0x0047182d:
    // 0047182d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00471832  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471837  66890d58345100         -mov word ptr [0x513458], cx
    app->getMemory<x86::reg16>(x86::reg32(5321816) /* 0x513458 */) = cpu.cx;
    // 0047183e  89350c225100           -mov dword ptr [0x51220c], esi
    app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */) = cpu.esi;
    // 00471844  66891d0c345100         -mov word ptr [0x51340c], bx
    app->getMemory<x86::reg16>(x86::reg32(5321740) /* 0x51340c */) = cpu.bx;
    // 0047184b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471850  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00471853  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471854  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471855  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471856  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471857  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471858  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471859  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047185a:
    // 0047185a  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00471862  0f8513ffffff           -jne 0x47177b
    if (!cpu.flags.zf)
    {
        goto L_0x0047177b;
    }
    // 00471868  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047186d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00471870  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471871  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471872  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471873  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471874  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471875  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471876  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00471880);
    // 00471880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471882  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471883  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471884  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471885  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471887  e81426ffff             -call 0x463ea0
    cpu.esp -= 4;
    sub_463ea0(app, cpu);
    if (cpu.terminate) return;
    // 0047188c  e89ffbfaff             -call 0x421430
    cpu.esp -= 4;
    sub_421430(app, cpu);
    if (cpu.terminate) return;
    // 00471891  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00471896  8a255e345100           -mov ah, byte ptr [0x51345e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5321822) /* 0x51345e */);
    // 0047189c  66891d0a345100         -mov word ptr [0x51340a], bx
    app->getMemory<x86::reg16>(x86::reg32(5321738) /* 0x51340a */) = cpu.bx;
    // 004718a3  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004718a6  0f847e000000           -je 0x47192a
    if (cpu.flags.zf)
    {
        goto L_0x0047192a;
    }
    // 004718ac  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004718ae  a3d4305100             -mov dword ptr [0x5130d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5320916) /* 0x5130d4 */) = cpu.eax;
L_0x004718b3:
    // 004718b3  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 004718b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004718bb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004718be  c1e204                 +shl edx, 4
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
    // 004718c1  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004718c3  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004718c6  8a155e345100           -mov dl, byte ptr [0x51345e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5321822) /* 0x51345e */);
    // 004718cc  a3c4305100             -mov dword ptr [0x5130c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5320900) /* 0x5130c4 */) = cpu.eax;
    // 004718d1  80fa01                 +cmp dl, 1
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
    // 004718d4  0f8595000000           -jne 0x47196f
    if (!cpu.flags.zf)
    {
        goto L_0x0047196f;
    }
    // 004718da  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 004718e0  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
L_0x004718e5:
    // 004718e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004718e7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004718ea  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004718ec  a3c8305100             -mov dword ptr [0x5130c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5320904) /* 0x5130c8 */) = cpu.eax;
    // 004718f1  a3cc305100             -mov dword ptr [0x5130cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5320908) /* 0x5130cc */) = cpu.eax;
    // 004718f6  bb09000000             -mov ebx, 9
    cpu.ebx = 9 /*0x9*/;
    // 004718fb  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 00471900  b8a0305100             -mov eax, 0x5130a0
    cpu.eax = 5320864 /*0x5130a0*/;
    // 00471905  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00471907  891ddc305100           -mov dword ptr [0x5130dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5320924) /* 0x5130dc */) = cpu.ebx;
    // 0047190d  8935e0305100           -mov dword ptr [0x5130e0], esi
    app->getMemory<x86::reg32>(x86::reg32(5320928) /* 0x5130e0 */) = cpu.esi;
    // 00471913  8935e4305100           -mov dword ptr [0x5130e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5320932) /* 0x5130e4 */) = cpu.esi;
    // 00471919  892de8305100           -mov dword ptr [0x5130e8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5320936) /* 0x5130e8 */) = cpu.ebp;
    // 0047191f  e8ec26ffff             -call 0x464010
    cpu.esp -= 4;
    sub_464010(app, cpu);
    if (cpu.terminate) return;
    // 00471924  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471925  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471926  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471927  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471928  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471929  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047192a:
    // 0047192a  e84122fbff             -call 0x423b70
    cpu.esp -= 4;
    sub_423b70(app, cpu);
    if (cpu.terminate) return;
    // 0047192f  668b0d58345100         -mov cx, word ptr [0x513458]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5321816) /* 0x513458 */);
    // 00471936  a3d8305100             -mov dword ptr [0x5130d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5320920) /* 0x5130d8 */) = cpu.eax;
    // 0047193b  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0047193e  7413                   -je 0x471953
    if (cpu.flags.zf)
    {
        goto L_0x00471953;
    }
    // 00471940  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00471942  891500315100           -mov dword ptr [0x513100], edx
    app->getMemory<x86::reg32>(x86::reg32(5320960) /* 0x513100 */) = cpu.edx;
    // 00471948  891504315100           -mov dword ptr [0x513104], edx
    app->getMemory<x86::reg32>(x86::reg32(5320964) /* 0x513104 */) = cpu.edx;
    // 0047194e  e960ffffff             -jmp 0x4718b3
    goto L_0x004718b3;
L_0x00471953:
    // 00471953  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471955  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471958  a304315100             -mov dword ptr [0x513104], eax
    app->getMemory<x86::reg32>(x86::reg32(5320964) /* 0x513104 */) = cpu.eax;
    // 0047195d  8b422c                 -mov eax, dword ptr [edx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00471960  05a0000000             +add eax, 0xa0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00471965  a300315100             -mov dword ptr [0x513100], eax
    app->getMemory<x86::reg32>(x86::reg32(5320960) /* 0x513100 */) = cpu.eax;
    // 0047196a  e944ffffff             -jmp 0x4718b3
    goto L_0x004718b3;
L_0x0047196f:
    // 0047196f  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00471975  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0047197a  e966ffffff             -jmp 0x4718e5
    goto L_0x004718e5;
}

/* align: skip 0x00 */
void Application::sub_471980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00471980);
    // 00471980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471983  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00471988  bf040f5400             -mov edi, 0x540f04
    cpu.edi = 5508868 /*0x540f04*/;
    // 0047198d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047198f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00471994  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471995  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471997  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047199a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047199c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047199e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004719a1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004719a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719a4  66891530345100         -mov word ptr [0x513430], dx
    app->getMemory<x86::reg16>(x86::reg32(5321776) /* 0x513430 */) = cpu.dx;
    // 004719ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4719b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004719b0);
    // 004719b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004719b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004719b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004719b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004719b4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004719b6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004719b8  88255f345100           -mov byte ptr [0x51345f], ah
    app->getMemory<x86::reg8>(x86::reg32(5321823) /* 0x51345f */) = cpu.ah;
    // 004719be  a0a92d5100             -mov al, byte ptr [0x512da9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5320105) /* 0x512da9 */);
    // 004719c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004719c5  3c02                   +cmp al, 2
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
    // 004719c7  726c                   -jb 0x471a35
    if (cpu.flags.cf)
    {
        goto L_0x00471a35;
    }
    // 004719c9  775d                   -ja 0x471a28
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00471a28;
    }
    // 004719cb  c6055e34510001         -mov byte ptr [0x51345e], 1
    app->getMemory<x86::reg8>(x86::reg32(5321822) /* 0x51345e */) = 1 /*0x1*/;
L_0x004719d2:
    // 004719d2  ba07030000             -mov edx, 0x307
    cpu.edx = 775 /*0x307*/;
    // 004719d7  b804030000             -mov eax, 0x304
    cpu.eax = 772 /*0x304*/;
    // 004719dc  e8ef09f9ff             -call 0x4023d0
    cpu.esp -= 4;
    sub_4023d0(app, cpu);
    if (cpu.terminate) return;
    // 004719e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004719e3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004719e5  e896feffff             -call 0x471880
    cpu.esp -= 4;
    sub_471880(app, cpu);
    if (cpu.terminate) return;
    // 004719ea  a05e345100             -mov al, byte ptr [0x51345e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5321822) /* 0x51345e */);
    // 004719ef  3c01                   +cmp al, 1
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
    // 004719f1  736a                   -jae 0x471a5d
    if (!cpu.flags.cf)
    {
        goto L_0x00471a5d;
    }
L_0x004719f3:
    // 004719f3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004719f5  0f859e000000           -jne 0x471a99
    if (!cpu.flags.zf)
    {
        goto L_0x00471a99;
    }
L_0x004719fb:
    // 004719fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004719fd  0f8560010000           -jne 0x471b63
    if (!cpu.flags.zf)
    {
        goto L_0x00471b63;
    }
L_0x00471a03:
    // 00471a03  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 00471a08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471a0a  e83109f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 00471a0f  e82c24ffff             -call 0x463e40
    cpu.esp -= 4;
    sub_463e40(app, cpu);
    if (cpu.terminate) return;
    // 00471a14  e8e8190100             -call 0x483401
    cpu.esp -= 4;
    sub_483401(app, cpu);
    if (cpu.terminate) return;
    // 00471a19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471a1b  0f8425010000           -je 0x471b46
    if (cpu.flags.zf)
    {
        goto L_0x00471b46;
    }
L_0x00471a21:
    // 00471a21  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471a23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471a28:
    // 00471a28  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00471a2a  7509                   -jne 0x471a35
    if (!cpu.flags.zf)
    {
        goto L_0x00471a35;
    }
    // 00471a2c  c6055e34510002         -mov byte ptr [0x51345e], 2
    app->getMemory<x86::reg8>(x86::reg32(5321822) /* 0x51345e */) = 2 /*0x2*/;
    // 00471a33  eb9d                   -jmp 0x4719d2
    goto L_0x004719d2;
L_0x00471a35:
    // 00471a35  ba08df4c00             -mov edx, 0x4cdf08
    cpu.edx = 5037832 /*0x4cdf08*/;
    // 00471a3a  b971000000             -mov ecx, 0x71
    cpu.ecx = 113 /*0x71*/;
    // 00471a3f  6828df4c00             -push 0x4cdf28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037864 /*0x4cdf28*/;
    cpu.esp -= 4;
    // 00471a44  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 00471a4a  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 00471a50  e89b260100             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00471a55  83c404                 +add esp, 4
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
    // 00471a58  e975ffffff             -jmp 0x4719d2
    goto L_0x004719d2;
L_0x00471a5d:
    // 00471a5d  761f                   -jbe 0x471a7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00471a7e;
    }
    // 00471a5f  3c02                   +cmp al, 2
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
    // 00471a61  7590                   -jne 0x4719f3
    if (!cpu.flags.zf)
    {
        goto L_0x004719f3;
    }
    // 00471a63  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 00471a68  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00471a6d  b8a0305100             -mov eax, 0x5130a0
    cpu.eax = 5320864 /*0x5130a0*/;
    // 00471a72  e809e20200             -call 0x49fc80
    cpu.esp -= 4;
    sub_49fc80(app, cpu);
    if (cpu.terminate) return;
    // 00471a77  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00471a79  e975ffffff             -jmp 0x4719f3
    goto L_0x004719f3;
L_0x00471a7e:
    // 00471a7e  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 00471a83  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00471a88  b8a0305100             -mov eax, 0x5130a0
    cpu.eax = 5320864 /*0x5130a0*/;
    // 00471a8d  e84ee5faff             -call 0x41ffe0
    cpu.esp -= 4;
    sub_41ffe0(app, cpu);
    if (cpu.terminate) return;
    // 00471a92  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00471a94  e95affffff             -jmp 0x4719f3
    goto L_0x004719f3;
L_0x00471a99:
    // 00471a99  a108774d00             -mov eax, dword ptr [0x4d7708]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076744) /* 0x4d7708 */);
    // 00471a9e  e8a5840100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00471aa3  e828fcffff             -call 0x4716d0
    cpu.esp -= 4;
    sub_4716d0(app, cpu);
    if (cpu.terminate) return;
    // 00471aa8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471aaa  0f8480000000           -je 0x471b30
    if (cpu.flags.zf)
    {
        goto L_0x00471b30;
    }
    // 00471ab0  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00471ab8  7542                   -jne 0x471afc
    if (!cpu.flags.zf)
    {
        goto L_0x00471afc;
    }
    // 00471aba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471abb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00471abd:
    // 00471abd  668b3d24345100         -mov di, word ptr [0x513424]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5321764) /* 0x513424 */);
    // 00471ac4  6639fe                 +cmp si, di
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471ac7  7523                   -jne 0x471aec
    if (!cpu.flags.zf)
    {
        goto L_0x00471aec;
    }
    // 00471ac9  e8a223ffff             -call 0x463e70
    cpu.esp -= 4;
    sub_463e70(app, cpu);
    if (cpu.terminate) return;
    // 00471ace  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ad0  743e                   -je 0x471b10
    if (cpu.flags.zf)
    {
        goto L_0x00471b10;
    }
    // 00471ad2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00471ad7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00471ad9  6689155a345100         -mov word ptr [0x51345a], dx
    app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */) = cpu.dx;
    // 00471ae0  6689155c345100         -mov word ptr [0x51345c], dx
    app->getMemory<x86::reg16>(x86::reg32(5321820) /* 0x51345c */) = cpu.dx;
    // 00471ae7  e8c8870100             -call 0x48a2b4
    cpu.esp -= 4;
    sub_48a2b4(app, cpu);
    if (cpu.terminate) return;
L_0x00471aec:
    // 00471aec  a108774d00             -mov eax, dword ptr [0x4d7708]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076744) /* 0x4d7708 */);
    // 00471af1  e86a840100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00471af6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471af7  e9fffeffff             -jmp 0x4719fb
    goto L_0x004719fb;
L_0x00471afc:
    // 00471afc  a108774d00             -mov eax, dword ptr [0x4d7708]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076744) /* 0x4d7708 */);
    // 00471b01  e85a840100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00471b06  e84521ffff             -call 0x463c50
    cpu.esp -= 4;
    sub_463c50(app, cpu);
    if (cpu.terminate) return;
    // 00471b0b  e9ebfeffff             -jmp 0x4719fb
    goto L_0x004719fb;
L_0x00471b10:
    // 00471b10  663b3d5a345100         +cmp di, word ptr [0x51345a]
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471b17  74a4                   -je 0x471abd
    if (cpu.flags.zf)
    {
        goto L_0x00471abd;
    }
    // 00471b19  e896870100             -call 0x48a2b4
    cpu.esp -= 4;
    sub_48a2b4(app, cpu);
    if (cpu.terminate) return;
    // 00471b1e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00471b20  a108774d00             -mov eax, dword ptr [0x4d7708]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076744) /* 0x4d7708 */);
    // 00471b25  e836840100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00471b2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b2b  e9cbfeffff             -jmp 0x4719fb
    goto L_0x004719fb;
L_0x00471b30:
    // 00471b30  e87f870100             -call 0x48a2b4
    cpu.esp -= 4;
    sub_48a2b4(app, cpu);
    if (cpu.terminate) return;
    // 00471b35  a108774d00             -mov eax, dword ptr [0x4d7708]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076744) /* 0x4d7708 */);
    // 00471b3a  e821840100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00471b3f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00471b41  e9bdfeffff             -jmp 0x471a03
    goto L_0x00471a03;
L_0x00471b46:
    // 00471b46  e8c53df9ff             -call 0x405910
    cpu.esp -= 4;
    sub_405910(app, cpu);
    if (cpu.terminate) return;
    // 00471b4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471b4d  0f85cefeffff           -jne 0x471a21
    if (!cpu.flags.zf)
    {
        goto L_0x00471a21;
    }
    // 00471b53  e8a9180100             -call 0x483401
    cpu.esp -= 4;
    sub_483401(app, cpu);
    if (cpu.terminate) return;
    // 00471b58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471b5a  74ea                   -je 0x471b46
    if (cpu.flags.zf)
    {
        goto L_0x00471b46;
    }
    // 00471b5c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471b5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471b63:
    // 00471b63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471b65  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471b67  e8d407f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 00471b6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471b6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00471b80);
    // 00471b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471b82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471b83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471b84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471b85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471b86  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471b89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471b8b  8b35581e5100           -mov esi, dword ptr [0x511e58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316184) /* 0x511e58 */);
    // 00471b91  e81a230100             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00471b96  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00471b98  8b15581e5100           -mov edx, dword ptr [0x511e58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316184) /* 0x511e58 */);
    // 00471b9e  81c610270000           -add esi, 0x2710
    (cpu.esi) += x86::reg32(x86::sreg32(10000 /*0x2710*/));
    // 00471ba4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00471ba6  0f8e94010000           -jle 0x471d40
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471d40;
    }
L_0x00471bac:
    // 00471bac  a13c2a5100             -mov eax, dword ptr [0x512a3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319228) /* 0x512a3c */);
    // 00471bb1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471bb3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471bb5  a34c0f5400             -mov dword ptr [0x540f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */) = cpu.eax;
    // 00471bba  e8e148fdff             -call 0x4464a0
    cpu.esp -= 4;
    sub_4464a0(app, cpu);
    if (cpu.terminate) return;
    // 00471bbf  e8ec48fdff             -call 0x4464b0
    cpu.esp -= 4;
    sub_4464b0(app, cpu);
    if (cpu.terminate) return;
    // 00471bc4  e8f3080100             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 00471bc9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471bcb  e89004fbff             -call 0x422060
    cpu.esp -= 4;
    sub_422060(app, cpu);
    if (cpu.terminate) return;
    // 00471bd0  833d240f540000         +cmp dword ptr [0x540f24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471bd7  0f854c010000           -jne 0x471d29
    if (!cpu.flags.zf)
    {
        goto L_0x00471d29;
    }
L_0x00471bdd:
    // 00471bdd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471bdf  e8cc220100             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00471be4  a178964d00             -mov eax, dword ptr [0x4d9678]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */);
    // 00471be9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471beb  a3300f5400             -mov dword ptr [0x540f30], eax
    app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */) = cpu.eax;
    // 00471bf0  a1581e5100             -mov eax, dword ptr [0x511e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316184) /* 0x511e58 */);
    // 00471bf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471bf7  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00471bf9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471bfb  8b15300f5400           -mov edx, dword ptr [0x540f30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */);
    // 00471c01  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00471c03  39d6                   +cmp esi, edx
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
    // 00471c05  7e06                   -jle 0x471c0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471c0d;
    }
    // 00471c07  ff05300f5400           -inc dword ptr [0x540f30]
    (app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */))++;
L_0x00471c0d:
    // 00471c0d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00471c0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471c11  8b154c0f5400           -mov edx, dword ptr [0x540f4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */);
    // 00471c17  a33c0f5400             -mov dword ptr [0x540f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5508924) /* 0x540f3c */) = cpu.eax;
    // 00471c1c  a13c2a5100             -mov eax, dword ptr [0x512a3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319228) /* 0x512a3c */);
    // 00471c21  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00471c23  8b0d300f5400           -mov ecx, dword ptr [0x540f30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */);
    // 00471c29  83f810                 +cmp eax, 0x10
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
    // 00471c2c  0f8f1d010000           -jg 0x471d4f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d4f;
    }
L_0x00471c32:
    // 00471c32  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00471c37  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00471c3c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00471c3e:
    // 00471c3e  8b153c2a5100           -mov edx, dword ptr [0x512a3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5319228) /* 0x512a3c */);
    // 00471c44  3b154c0f5400           +cmp edx, dword ptr [0x540f4c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c4a  7c0c                   -jl 0x471c58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471c58;
    }
    // 00471c4c  3b1d240f5400           +cmp ebx, dword ptr [0x540f24]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c52  0f8406010000           -je 0x471d5e
    if (cpu.flags.zf)
    {
        goto L_0x00471d5e;
    }
L_0x00471c58:
    // 00471c58  833d280f540000         +cmp dword ptr [0x540f28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c5f  0f85a6040000           -jne 0x47210b
    if (!cpu.flags.zf)
    {
        goto L_0x0047210b;
    }
    // 00471c65  833d2c0f540000         +cmp dword ptr [0x540f2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c6c  0f8599040000           -jne 0x47210b
    if (!cpu.flags.zf)
    {
        goto L_0x0047210b;
    }
    // 00471c72  833d240f540000         +cmp dword ptr [0x540f24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c79  0f858c040000           -jne 0x47210b
    if (!cpu.flags.zf)
    {
        goto L_0x0047210b;
    }
    // 00471c7f  8b15300f5400           -mov edx, dword ptr [0x540f30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */);
    // 00471c85  3b15340f5400           +cmp edx, dword ptr [0x540f34]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c8b  0f8c98030000           -jl 0x472029
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472029;
    }
L_0x00471c91:
    // 00471c91  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00471c96  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00471c9b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00471c9d:
    // 00471c9d  8b15300f5400           -mov edx, dword ptr [0x540f30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */);
    // 00471ca3  3b15340f5400           +cmp edx, dword ptr [0x540f34]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471ca9  7c0f                   -jl 0x471cba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471cba;
    }
    // 00471cab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471cad  e8be040000             -call 0x472170
    cpu.esp -= 4;
    sub_472170(app, cpu);
    if (cpu.terminate) return;
    // 00471cb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471cb4  0f847e030000           -je 0x472038
    if (cpu.flags.zf)
    {
        goto L_0x00472038;
    }
L_0x00471cba:
    // 00471cba  833d3c0f540000         +cmp dword ptr [0x540f3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508924) /* 0x540f3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471cc1  750a                   -jne 0x471ccd
    if (!cpu.flags.zf)
    {
        goto L_0x00471ccd;
    }
    // 00471cc3  a1280f5400             -mov eax, dword ptr [0x540f28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */);
    // 00471cc8  e8d3daffff             -call 0x46f7a0
    cpu.esp -= 4;
    sub_46f7a0(app, cpu);
    if (cpu.terminate) return;
L_0x00471ccd:
    // 00471ccd  833d0822510004         +cmp dword ptr [0x512208], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471cd4  7517                   -jne 0x471ced
    if (!cpu.flags.zf)
    {
        goto L_0x00471ced;
    }
    // 00471cd6  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471cdd  7f0e                   -jg 0x471ced
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471ced;
    }
    // 00471cdf  833d0c22510000         +cmp dword ptr [0x51220c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471ce6  7505                   -jne 0x471ced
    if (!cpu.flags.zf)
    {
        goto L_0x00471ced;
    }
    // 00471ce8  e883c80000             -call 0x47e570
    cpu.esp -= 4;
    sub_47e570(app, cpu);
    if (cpu.terminate) return;
L_0x00471ced:
    // 00471ced  e8fe9bfeff             -call 0x45b8f0
    cpu.esp -= 4;
    sub_45b8f0(app, cpu);
    if (cpu.terminate) return;
    // 00471cf2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471cf4  0f841b040000           -je 0x472115
    if (cpu.flags.zf)
    {
        goto L_0x00472115;
    }
L_0x00471cfa:
    // 00471cfa  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d01  7f11                   -jg 0x471d14
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d14;
    }
    // 00471d03  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471d08  891d80964d00           -mov dword ptr [0x4d9680], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.ebx;
    // 00471d0e  891d7c964d00           -mov dword ptr [0x4d967c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ebx;
L_0x00471d14:
    // 00471d14  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471d19  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00471d1e  e8cd2b0000             -call 0x4748f0
    cpu.esp -= 4;
    sub_4748f0(app, cpu);
    if (cpu.terminate) return;
    // 00471d23  893d240f5400           -mov dword ptr [0x540f24], edi
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.edi;
L_0x00471d29:
    // 00471d29  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d30  0f8e18040000           -jle 0x47214e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047214e;
    }
    // 00471d36  83c404                 +add esp, 4
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
    // 00471d39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d3f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471d40:
    // 00471d40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471d45  e8eeaa0200             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
    // 00471d4a  e95dfeffff             -jmp 0x471bac
    goto L_0x00471bac;
L_0x00471d4f:
    // 00471d4f  a13c2a5100             -mov eax, dword ptr [0x512a3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319228) /* 0x512a3c */);
    // 00471d54  a34c0f5400             -mov dword ptr [0x540f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */) = cpu.eax;
    // 00471d59  e9d4feffff             -jmp 0x471c32
    goto L_0x00471c32;
L_0x00471d5e:
    // 00471d5e  3b2d08225100           +cmp ebp, dword ptr [0x512208]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d64  7e05                   -jle 0x471d6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471d6b;
    }
    // 00471d66  e8f5d9ffff             -call 0x46f760
    cpu.esp -= 4;
    sub_46f760(app, cpu);
    if (cpu.terminate) return;
L_0x00471d6b:
    // 00471d6b  3b2d940d5400           +cmp ebp, dword ptr [0x540d94]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508500) /* 0x540d94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d71  7547                   -jne 0x471dba
    if (!cpu.flags.zf)
    {
        goto L_0x00471dba;
    }
    // 00471d73  8b15280f5400           -mov edx, dword ptr [0x540f28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */);
    // 00471d79  39d3                   +cmp ebx, edx
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
    // 00471d7b  753d                   -jne 0x471dba
    if (!cpu.flags.zf)
    {
        goto L_0x00471dba;
    }
    // 00471d7d  e88ee3ffff             -call 0x470110
    cpu.esp -= 4;
    sub_470110(app, cpu);
    if (cpu.terminate) return;
    // 00471d82  833da427520004         +cmp dword ptr [0x5227a4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5384100) /* 0x5227a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d89  752f                   -jne 0x471dba
    if (!cpu.flags.zf)
    {
        goto L_0x00471dba;
    }
    // 00471d8b  a198275200             -mov eax, dword ptr [0x522798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384088) /* 0x522798 */);
    // 00471d90  8915a4275200           -mov dword ptr [0x5227a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5384100) /* 0x5227a4 */) = cpu.edx;
    // 00471d96  a3240f5400             -mov dword ptr [0x540f24], eax
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.eax;
    // 00471d9b  39c2                   +cmp edx, eax
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
    // 00471d9d  0f84b8010000           -je 0x471f5b
    if (cpu.flags.zf)
    {
        goto L_0x00471f5b;
    }
    // 00471da3  3b152c0f5400           +cmp edx, dword ptr [0x540f2c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471da9  0f84ac010000           -je 0x471f5b
    if (cpu.flags.zf)
    {
        goto L_0x00471f5b;
    }
    // 00471daf  89152c0f5400           -mov dword ptr [0x540f2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */) = cpu.edx;
    // 00471db5  e8f603fdff             -call 0x4421b0
    cpu.esp -= 4;
    sub_4421b0(app, cpu);
    if (cpu.terminate) return;
L_0x00471dba:
    // 00471dba  8b15240f5400           -mov edx, dword ptr [0x540f24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */);
    // 00471dc0  39d3                   +cmp ebx, edx
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
    // 00471dc2  7511                   -jne 0x471dd5
    if (!cpu.flags.zf)
    {
        goto L_0x00471dd5;
    }
    // 00471dc4  3b15280f5400           +cmp edx, dword ptr [0x540f28]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471dca  0f84c0010000           -je 0x471f90
    if (cpu.flags.zf)
    {
        goto L_0x00471f90;
    }
    // 00471dd0  e84b040000             -call 0x472220
    cpu.esp -= 4;
    sub_472220(app, cpu);
    if (cpu.terminate) return;
L_0x00471dd5:
    // 00471dd5  3b1d280f5400           +cmp ebx, dword ptr [0x540f28]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471ddb  0f85d4010000           -jne 0x471fb5
    if (!cpu.flags.zf)
    {
        goto L_0x00471fb5;
    }
    // 00471de1  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00471de6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471de8  e8939bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471ded  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471def  7405                   -je 0x471df6
    if (cpu.flags.zf)
    {
        goto L_0x00471df6;
    }
    // 00471df1  e88a85fbff             -call 0x42a380
    cpu.esp -= 4;
    sub_42a380(app, cpu);
    if (cpu.terminate) return;
L_0x00471df6:
    // 00471df6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00471dfb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471dfd  e87e9bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e04  7405                   -je 0x471e0b
    if (cpu.flags.zf)
    {
        goto L_0x00471e0b;
    }
    // 00471e06  e89585fbff             -call 0x42a3a0
    cpu.esp -= 4;
    sub_42a3a0(app, cpu);
    if (cpu.terminate) return;
L_0x00471e0b:
    // 00471e0b  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00471e10  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e12  e8699bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e19  7405                   -je 0x471e20
    if (cpu.flags.zf)
    {
        goto L_0x00471e20;
    }
    // 00471e1b  e87047fdff             -call 0x446590
    cpu.esp -= 4;
    sub_446590(app, cpu);
    if (cpu.terminate) return;
L_0x00471e20:
    // 00471e20  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00471e25  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e27  e8549bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e2e  7405                   -je 0x471e35
    if (cpu.flags.zf)
    {
        goto L_0x00471e35;
    }
    // 00471e30  e81bc8fbff             -call 0x42e650
    cpu.esp -= 4;
    sub_42e650(app, cpu);
    if (cpu.terminate) return;
L_0x00471e35:
    // 00471e35  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00471e3a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e3c  e83f9bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e43  7407                   -je 0x471e4c
    if (cpu.flags.zf)
    {
        goto L_0x00471e4c;
    }
    // 00471e45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471e47  e83476feff             -call 0x459480
    cpu.esp -= 4;
    sub_459480(app, cpu);
    if (cpu.terminate) return;
L_0x00471e4c:
    // 00471e4c  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00471e51  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e53  e8289bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e5a  7407                   -je 0x471e63
    if (cpu.flags.zf)
    {
        goto L_0x00471e63;
    }
    // 00471e5c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471e5e  e81d76feff             -call 0x459480
    cpu.esp -= 4;
    sub_459480(app, cpu);
    if (cpu.terminate) return;
L_0x00471e63:
    // 00471e63  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00471e68  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e6a  e8119bfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e71  7405                   -je 0x471e78
    if (cpu.flags.zf)
    {
        goto L_0x00471e78;
    }
    // 00471e73  e8c875feff             -call 0x459440
    cpu.esp -= 4;
    sub_459440(app, cpu);
    if (cpu.terminate) return;
L_0x00471e78:
    // 00471e78  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 00471e7d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e7f  e8fc9afeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e86  7405                   -je 0x471e8d
    if (cpu.flags.zf)
    {
        goto L_0x00471e8d;
    }
    // 00471e88  e8c301fdff             -call 0x442050
    cpu.esp -= 4;
    sub_442050(app, cpu);
    if (cpu.terminate) return;
L_0x00471e8d:
    // 00471e8d  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 00471e92  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471e94  e8e79afeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471e99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e9b  7405                   -je 0x471ea2
    if (cpu.flags.zf)
    {
        goto L_0x00471ea2;
    }
    // 00471e9d  e86e01fdff             -call 0x442010
    cpu.esp -= 4;
    sub_442010(app, cpu);
    if (cpu.terminate) return;
L_0x00471ea2:
    // 00471ea2  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00471ea7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471ea9  e8d29afeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471eae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471eb0  7419                   -je 0x471ecb
    if (cpu.flags.zf)
    {
        goto L_0x00471ecb;
    }
    // 00471eb2  b836000000             -mov eax, 0x36
    cpu.eax = 54 /*0x36*/;
    // 00471eb7  e894460100             -call 0x486550
    cpu.esp -= 4;
    sub_486550(app, cpu);
    if (cpu.terminate) return;
    // 00471ebc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ebe  0f84d8000000           -je 0x471f9c
    if (cpu.flags.zf)
    {
        goto L_0x00471f9c;
    }
L_0x00471ec4:
    // 00471ec4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00471ec6:
    // 00471ec6  e8456afbff             -call 0x428910
    cpu.esp -= 4;
    sub_428910(app, cpu);
    if (cpu.terminate) return;
L_0x00471ecb:
    // 00471ecb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471ecd  e86e5d0000             -call 0x477c40
    cpu.esp -= 4;
    sub_477c40(app, cpu);
    if (cpu.terminate) return;
    // 00471ed2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ed4  740f                   -je 0x471ee5
    if (cpu.flags.zf)
    {
        goto L_0x00471ee5;
    }
    // 00471ed6  3b2d940d5400           +cmp ebp, dword ptr [0x540d94]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508500) /* 0x540d94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471edc  7e07                   -jle 0x471ee5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471ee5;
    }
    // 00471ede  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471ee0  e8fb93fdff             -call 0x44b2e0
    cpu.esp -= 4;
    sub_44b2e0(app, cpu);
    if (cpu.terminate) return;
L_0x00471ee5:
    // 00471ee5  a108225100             -mov eax, dword ptr [0x512208]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 00471eea  39c7                   +cmp edi, eax
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
    // 00471eec  7518                   -jne 0x471f06
    if (!cpu.flags.zf)
    {
        goto L_0x00471f06;
    }
    // 00471eee  e84d5d0000             -call 0x477c40
    cpu.esp -= 4;
    sub_477c40(app, cpu);
    if (cpu.terminate) return;
    // 00471ef3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ef5  740f                   -je 0x471f06
    if (cpu.flags.zf)
    {
        goto L_0x00471f06;
    }
    // 00471ef7  3b2d940d5400           +cmp ebp, dword ptr [0x540d94]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508500) /* 0x540d94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471efd  7e07                   -jle 0x471f06
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471f06;
    }
    // 00471eff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471f01  e8da93fdff             -call 0x44b2e0
    cpu.esp -= 4;
    sub_44b2e0(app, cpu);
    if (cpu.terminate) return;
L_0x00471f06:
    // 00471f06  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 00471f0b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00471f0d  e86e9afeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471f12  a3c8285100             -mov dword ptr [0x5128c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5318856) /* 0x5128c8 */) = cpu.eax;
    // 00471f17  3b3d08225100           +cmp edi, dword ptr [0x512208]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471f1d  7511                   -jne 0x471f30
    if (!cpu.flags.zf)
    {
        goto L_0x00471f30;
    }
    // 00471f1f  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 00471f24  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00471f26  e8559afeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471f2b  a3cc285100             -mov dword ptr [0x5128cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5318860) /* 0x5128cc */) = cpu.eax;
L_0x00471f30:
    // 00471f30  3b2d08225100           +cmp ebp, dword ptr [0x512208]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471f36  0f8ec6000000           -jle 0x472002
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472002;
    }
L_0x00471f3c:
    // 00471f3c  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00471f41  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471f43  e8389afeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471f48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471f4a  0f85c9000000           -jne 0x472019
    if (!cpu.flags.zf)
    {
        goto L_0x00472019;
    }
    // 00471f50  ff054c0f5400           +inc dword ptr [0x540f4c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00471f56  e9e3fcffff             -jmp 0x471c3e
    goto L_0x00471c3e;
L_0x00471f5b:
    // 00471f5b  8b1590275200           -mov edx, dword ptr [0x522790]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5384080) /* 0x522790 */);
    // 00471f61  3b152c0f5400           +cmp edx, dword ptr [0x540f2c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471f67  0f844dfeffff           -je 0x471dba
    if (cpu.flags.zf)
    {
        goto L_0x00471dba;
    }
    // 00471f6d  89152c0f5400           -mov dword ptr [0x540f2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */) = cpu.edx;
    // 00471f73  39d3                   +cmp ebx, edx
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
    // 00471f75  740f                   -je 0x471f86
    if (cpu.flags.zf)
    {
        goto L_0x00471f86;
    }
    // 00471f77  e888abfdff             -call 0x44cb04
    cpu.esp -= 4;
    sub_44cb04(app, cpu);
    if (cpu.terminate) return;
    // 00471f7c  e8bf02fdff             -call 0x442240
    cpu.esp -= 4;
    sub_442240(app, cpu);
    if (cpu.terminate) return;
    // 00471f81  e934feffff             -jmp 0x471dba
    goto L_0x00471dba;
L_0x00471f86:
    // 00471f86  e89502fdff             -call 0x442220
    cpu.esp -= 4;
    sub_442220(app, cpu);
    if (cpu.terminate) return;
    // 00471f8b  e92afeffff             -jmp 0x471dba
    goto L_0x00471dba;
L_0x00471f90:
    // 00471f90  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471f92  e8d9010000             -call 0x472170
    cpu.esp -= 4;
    sub_472170(app, cpu);
    if (cpu.terminate) return;
    // 00471f97  e939feffff             -jmp 0x471dd5
    goto L_0x00471dd5;
L_0x00471f9c:
    // 00471f9c  b82a000000             -mov eax, 0x2a
    cpu.eax = 42 /*0x2a*/;
    // 00471fa1  e8aa450100             -call 0x486550
    cpu.esp -= 4;
    sub_486550(app, cpu);
    if (cpu.terminate) return;
    // 00471fa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471fa8  0f8516ffffff           -jne 0x471ec4
    if (!cpu.flags.zf)
    {
        goto L_0x00471ec4;
    }
    // 00471fae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471fb0  e911ffffff             -jmp 0x471ec6
    goto L_0x00471ec6;
L_0x00471fb5:
    // 00471fb5  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00471fba  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471fbc  e8bf99feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00471fc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471fc3  7415                   -je 0x471fda
    if (cpu.flags.zf)
    {
        goto L_0x00471fda;
    }
    // 00471fc5  b836000000             -mov eax, 0x36
    cpu.eax = 54 /*0x36*/;
    // 00471fca  e881450100             -call 0x486550
    cpu.esp -= 4;
    sub_486550(app, cpu);
    if (cpu.terminate) return;
    // 00471fcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471fd1  741d                   -je 0x471ff0
    if (cpu.flags.zf)
    {
        goto L_0x00471ff0;
    }
L_0x00471fd3:
    // 00471fd3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00471fd5:
    // 00471fd5  e83669fbff             -call 0x428910
    cpu.esp -= 4;
    sub_428910(app, cpu);
    if (cpu.terminate) return;
L_0x00471fda:
    // 00471fda  3b3d08225100           +cmp edi, dword ptr [0x512208]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471fe0  0f8c4affffff           -jl 0x471f30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471f30;
    }
    // 00471fe6  e865030000             -call 0x472350
    cpu.esp -= 4;
    sub_472350(app, cpu);
    if (cpu.terminate) return;
    // 00471feb  e940ffffff             -jmp 0x471f30
    goto L_0x00471f30;
L_0x00471ff0:
    // 00471ff0  b82a000000             -mov eax, 0x2a
    cpu.eax = 42 /*0x2a*/;
    // 00471ff5  e856450100             -call 0x486550
    cpu.esp -= 4;
    sub_486550(app, cpu);
    if (cpu.terminate) return;
    // 00471ffa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ffc  75d5                   -jne 0x471fd3
    if (!cpu.flags.zf)
    {
        goto L_0x00471fd3;
    }
    // 00471ffe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00472000  ebd3                   -jmp 0x471fd5
    goto L_0x00471fd5;
L_0x00472002:
    // 00472002  3b3d14225100           +cmp edi, dword ptr [0x512214]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472008  0f8c2effffff           -jl 0x471f3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471f3c;
    }
    // 0047200e  ff054c0f5400           +inc dword ptr [0x540f4c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00472014  e925fcffff             -jmp 0x471c3e
    goto L_0x00471c3e;
L_0x00472019:
    // 00472019  e822080000             -call 0x472840
    cpu.esp -= 4;
    sub_472840(app, cpu);
    if (cpu.terminate) return;
    // 0047201e  ff054c0f5400           +inc dword ptr [0x540f4c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00472024  e915fcffff             -jmp 0x471c3e
    goto L_0x00471c3e;
L_0x00472029:
    // 00472029  c7053c0f540001000000   -mov dword ptr [0x540f3c], 1
    app->getMemory<x86::reg32>(x86::reg32(5508924) /* 0x540f3c */) = 1 /*0x1*/;
    // 00472033  e959fcffff             -jmp 0x471c91
    goto L_0x00471c91;
L_0x00472038:
    // 00472038  a1340f5400             -mov eax, dword ptr [0x540f34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
    // 0047203d  85c5                   +test ebp, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.eax));
    // 0047203f  7507                   -jne 0x472048
    if (!cpu.flags.zf)
    {
        goto L_0x00472048;
    }
    // 00472041  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00472043  e8e8170000             -call 0x473830
    cpu.esp -= 4;
    sub_473830(app, cpu);
    if (cpu.terminate) return;
L_0x00472048:
    // 00472048  8b15940d5400           -mov edx, dword ptr [0x540d94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508500) /* 0x540d94 */);
    // 0047204e  891d5c964d00           -mov dword ptr [0x4d965c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084764) /* 0x4d965c */) = cpu.ebx;
    // 00472054  39d7                   +cmp edi, edx
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
    // 00472056  0f857d000000           -jne 0x4720d9
    if (!cpu.flags.zf)
    {
        goto L_0x004720d9;
    }
    // 0047205c  3b1d94275200           +cmp ebx, dword ptr [0x522794]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472062  752d                   -jne 0x472091
    if (!cpu.flags.zf)
    {
        goto L_0x00472091;
    }
    // 00472064  a1340f5400             -mov eax, dword ptr [0x540f34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
    // 00472069  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047206b  c7042404000000         -mov dword ptr [esp], 4
    app->getMemory<x86::reg32>(cpu.esp) = 4 /*0x4*/;
    // 00472072  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472075  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472078  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047207a  7515                   -jne 0x472091
    if (!cpu.flags.zf)
    {
        goto L_0x00472091;
    }
L_0x0047207c:
    // 0047207c  a1340f5400             -mov eax, dword ptr [0x540f34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
    // 00472081  e8fa030000             -call 0x472480
    cpu.esp -= 4;
    sub_472480(app, cpu);
    if (cpu.terminate) return;
    // 00472086  ff05340f5400           +inc dword ptr [0x540f34]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047208c  e90cfcffff             -jmp 0x471c9d
    goto L_0x00471c9d;
L_0x00472091:
    // 00472091  3b2d94275200           +cmp ebp, dword ptr [0x522794]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472097  7510                   -jne 0x4720a9
    if (!cpu.flags.zf)
    {
        goto L_0x004720a9;
    }
    // 00472099  a1340f5400             -mov eax, dword ptr [0x540f34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
    // 0047209e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004720a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004720a3  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004720a5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004720a7  74d3                   -je 0x47207c
    if (cpu.flags.zf)
    {
        goto L_0x0047207c;
    }
L_0x004720a9:
    // 004720a9  a194275200             -mov eax, dword ptr [0x522794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */);
    // 004720ae  39c7                   +cmp edi, eax
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
    // 004720b0  74ca                   -je 0x47207c
    if (cpu.flags.zf)
    {
        goto L_0x0047207c;
    }
    // 004720b2  83f803                 +cmp eax, 3
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
    // 004720b5  750c                   -jne 0x4720c3
    if (!cpu.flags.zf)
    {
        goto L_0x004720c3;
    }
    // 004720b7  a1340f5400             -mov eax, dword ptr [0x540f34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
    // 004720bc  e8bf030000             -call 0x472480
    cpu.esp -= 4;
    sub_472480(app, cpu);
    if (cpu.terminate) return;
    // 004720c1  ebb9                   -jmp 0x47207c
    goto L_0x0047207c;
L_0x004720c3:
    // 004720c3  892d5c964d00           -mov dword ptr [0x4d965c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5084764) /* 0x4d965c */) = cpu.ebp;
    // 004720c9  e836aafdff             -call 0x44cb04
    cpu.esp -= 4;
    sub_44cb04(app, cpu);
    if (cpu.terminate) return;
    // 004720ce  ff05340f5400           +inc dword ptr [0x540f34]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004720d4  e9c4fbffff             -jmp 0x471c9d
    goto L_0x00471c9d;
L_0x004720d9:
    // 004720d9  83fa04                 +cmp edx, 4
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
    // 004720dc  759e                   -jne 0x47207c
    if (!cpu.flags.zf)
    {
        goto L_0x0047207c;
    }
    // 004720de  e89dfffcff             -call 0x442080
    cpu.esp -= 4;
    sub_442080(app, cpu);
    if (cpu.terminate) return;
    // 004720e3  e82817ffff             -call 0x463810
    cpu.esp -= 4;
    sub_463810(app, cpu);
    if (cpu.terminate) return;
    // 004720e8  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004720ed  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004720f2  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004720f4  8915940d5400           -mov dword ptr [0x540d94], edx
    app->getMemory<x86::reg32>(x86::reg32(5508500) /* 0x540d94 */) = cpu.edx;
    // 004720fa  891d3c0f5400           -mov dword ptr [0x540f3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5508924) /* 0x540f3c */) = cpu.ebx;
    // 00472100  893d78964d00           -mov dword ptr [0x4d9678], edi
    app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */) = cpu.edi;
    // 00472106  e9c2fbffff             -jmp 0x471ccd
    goto L_0x00471ccd;
L_0x0047210b:
    // 0047210b  e8f4a9fdff             -call 0x44cb04
    cpu.esp -= 4;
    sub_44cb04(app, cpu);
    if (cpu.terminate) return;
    // 00472110  e9a5fbffff             -jmp 0x471cba
    goto L_0x00471cba;
L_0x00472115:
    // 00472115  66833d5a34510000       +cmp word ptr [0x51345a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047211d  0f85d7fbffff           -jne 0x471cfa
    if (!cpu.flags.zf)
    {
        goto L_0x00471cfa;
    }
    // 00472123  833d940d540003         +cmp dword ptr [0x540d94], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508500) /* 0x540d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047212a  7510                   -jne 0x47213c
    if (!cpu.flags.zf)
    {
        goto L_0x0047213c;
    }
    // 0047212c  813d480f540040020000   +cmp dword ptr [0x540f48], 0x240
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(576 /*0x240*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472136  0f8fbefbffff           -jg 0x471cfa
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471cfa;
    }
L_0x0047213c:
    // 0047213c  833d240f540000         +cmp dword ptr [0x540f24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472143  0f8494faffff           -je 0x471bdd
    if (cpu.flags.zf)
    {
        goto L_0x00471bdd;
    }
    // 00472149  e9dbfbffff             -jmp 0x471d29
    goto L_0x00471d29;
L_0x0047214e:
    // 0047214e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00472153  a380964d00             -mov dword ptr [0x4d9680], eax
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.eax;
    // 00472158  a37c964d00             -mov dword ptr [0x4d967c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.eax;
    // 0047215d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472160  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472165  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472170);
    // 00472170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472172  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472173  833d200f540000         +cmp dword ptr [0x540f20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508896) /* 0x540f20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047217a  754f                   -jne 0x4721cb
    if (!cpu.flags.zf)
    {
        goto L_0x004721cb;
    }
    // 0047217c  8b0d480f5400           -mov ecx, dword ptr [0x540f48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00472182  83f920                 +cmp ecx, 0x20
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
    // 00472185  7c44                   -jl 0x4721cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004721cb;
    }
    // 00472187  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047218d  7d09                   -jge 0x472198
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472198;
    }
    // 0047218f  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472196  7e33                   -jle 0x4721cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004721cb;
    }
L_0x00472198:
    // 00472198  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047219a  7422                   -je 0x4721be
    if (cpu.flags.zf)
    {
        goto L_0x004721be;
    }
    // 0047219c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004721a1  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004721a6  e8d597feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 004721ab  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004721b0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004721b2  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004721b7  e8c497feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 004721bc  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004721be:
    // 004721be  e89d100000             -call 0x473260
    cpu.esp -= 4;
    sub_473260(app, cpu);
    if (cpu.terminate) return;
    // 004721c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004721c5  750a                   -jne 0x4721d1
    if (!cpu.flags.zf)
    {
        goto L_0x004721d1;
    }
    // 004721c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004721cb:
    // 004721cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004721cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004721d1:
    // 004721d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004721d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004721d5  e85666fbff             -call 0x428830
    cpu.esp -= 4;
    sub_428830(app, cpu);
    if (cpu.terminate) return;
    // 004721da  833d0822510002         +cmp dword ptr [0x512208], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004721e1  7c2e                   -jl 0x472211
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472211;
    }
    // 004721e3  a15c1e5100             -mov eax, dword ptr [0x511e5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316188) /* 0x511e5c */);
    // 004721e8  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004721eb:
    // 004721eb  a3400f5400             -mov dword ptr [0x540f40], eax
    app->getMemory<x86::reg32>(x86::reg32(5508928) /* 0x540f40 */) = cpu.eax;
    // 004721f0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004721f5  e84600fdff             -call 0x442240
    cpu.esp -= 4;
    sub_442240(app, cpu);
    if (cpu.terminate) return;
    // 004721fa  892d7c964d00           -mov dword ptr [0x4d967c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ebp;
    // 00472200  892d280f5400           -mov dword ptr [0x540f28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */) = cpu.ebp;
    // 00472206  e895700000             -call 0x4792a0
    cpu.esp -= 4;
    sub_4792a0(app, cpu);
    if (cpu.terminate) return;
    // 0047220b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047220d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047220e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047220f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472210  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472211:
    // 00472211  a15c1e5100             -mov eax, dword ptr [0x511e5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316188) /* 0x511e5c */);
    // 00472216  83c010                 +add eax, 0x10
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
    // 00472219  ebd0                   -jmp 0x4721eb
    goto L_0x004721eb;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472220);
    // 00472220  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472221  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472222  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472223  8b155c1e5100           -mov edx, dword ptr [0x511e5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316188) /* 0x511e5c */);
    // 00472229  3b15400f5400           +cmp edx, dword ptr [0x540f40]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508928) /* 0x540f40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047222f  7c0a                   -jl 0x47223b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047223b;
    }
    // 00472231  8b0d6c964d00           -mov ecx, dword ptr [0x4d966c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084780) /* 0x4d966c */);
    // 00472237  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472239  7404                   -je 0x47223f
    if (cpu.flags.zf)
    {
        goto L_0x0047223f;
    }
L_0x0047223b:
    // 0047223b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047223c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047223d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047223e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047223f:
    // 0047223f  e83cd8feff             -call 0x45fa80
    cpu.esp -= 4;
    sub_45fa80(app, cpu);
    if (cpu.terminate) return;
    // 00472244  e8970c0000             -call 0x472ee0
    cpu.esp -= 4;
    sub_472ee0(app, cpu);
    if (cpu.terminate) return;
    // 00472249  83f801                 +cmp eax, 1
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
    // 0047224c  7466                   -je 0x4722b4
    if (cpu.flags.zf)
    {
        goto L_0x004722b4;
    }
    // 0047224e  83f802                 +cmp eax, 2
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
    // 00472251  0f848e000000           -je 0x4722e5
    if (cpu.flags.zf)
    {
        goto L_0x004722e5;
    }
    // 00472257  83f803                 +cmp eax, 3
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
    // 0047225a  0f84b2000000           -je 0x472312
    if (cpu.flags.zf)
    {
        goto L_0x00472312;
    }
    // 00472260  83f804                 +cmp eax, 4
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
    // 00472263  75d6                   -jne 0x47223b
    if (!cpu.flags.zf)
    {
        goto L_0x0047223b;
    }
    // 00472265  e846fffcff             -call 0x4421b0
    cpu.esp -= 4;
    sub_4421b0(app, cpu);
    if (cpu.terminate) return;
    // 0047226a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047226c  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472272  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472274  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00472276  ff1574375600           -call dword ptr [0x563774]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650292) /* 0x563774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047227c  ff1578375600           -call dword ptr [0x563778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650296) /* 0x563778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472282  ff154c375600           -call dword ptr [0x56374c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650252) /* 0x56374c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472288  e8d36f0000             -call 0x479260
    cpu.esp -= 4;
    sub_479260(app, cpu);
    if (cpu.terminate) return;
    // 0047228d  e87e40fdff             -call 0x446310
    cpu.esp -= 4;
    sub_446310(app, cpu);
    if (cpu.terminate) return;
    // 00472292  e849400000             -call 0x4762e0
    cpu.esp -= 4;
    sub_4762e0(app, cpu);
    if (cpu.terminate) return;
    // 00472297  e83413ffff             -call 0x4635d0
    cpu.esp -= 4;
    sub_4635d0(app, cpu);
    if (cpu.terminate) return;
    // 0047229c  e87b330100             -call 0x48561c
    cpu.esp -= 4;
    sub_48561c(app, cpu);
    if (cpu.terminate) return;
    // 004722a1  e8ea15ffff             -call 0x463890
    cpu.esp -= 4;
    sub_463890(app, cpu);
    if (cpu.terminate) return;
    // 004722a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004722ab  e888a50200             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
    // 004722b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004722b4:
    // 004722b4  e83765fbff             -call 0x4287f0
    cpu.esp -= 4;
    sub_4287f0(app, cpu);
    if (cpu.terminate) return;
    // 004722b9  e83272feff             -call 0x4594f0
    cpu.esp -= 4;
    sub_4594f0(app, cpu);
    if (cpu.terminate) return;
    // 004722be  833d2c0f540000         +cmp dword ptr [0x540f2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004722c5  7505                   -jne 0x4722cc
    if (!cpu.flags.zf)
    {
        goto L_0x004722cc;
    }
    // 004722c7  e854fffcff             -call 0x442220
    cpu.esp -= 4;
    sub_442220(app, cpu);
    if (cpu.terminate) return;
L_0x004722cc:
    // 004722cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004722cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004722cf  891d7c964d00           -mov dword ptr [0x4d967c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ebx;
    // 004722d5  891d280f5400           -mov dword ptr [0x540f28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */) = cpu.ebx;
    // 004722db  e8a06f0000             -call 0x479280
    cpu.esp -= 4;
    sub_479280(app, cpu);
    if (cpu.terminate) return;
    // 004722e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004722e5:
    // 004722e5  e80665fbff             -call 0x4287f0
    cpu.esp -= 4;
    sub_4287f0(app, cpu);
    if (cpu.terminate) return;
    // 004722ea  e80172feff             -call 0x4594f0
    cpu.esp -= 4;
    sub_4594f0(app, cpu);
    if (cpu.terminate) return;
    // 004722ef  e86cfefcff             -call 0x442160
    cpu.esp -= 4;
    sub_442160(app, cpu);
    if (cpu.terminate) return;
    // 004722f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004722f9  890d280f5400           -mov dword ptr [0x540f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */) = cpu.ecx;
    // 004722ff  a3240f5400             -mov dword ptr [0x540f24], eax
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.eax;
    // 00472304  a3200f5400             -mov dword ptr [0x540f20], eax
    app->getMemory<x86::reg32>(x86::reg32(5508896) /* 0x540f20 */) = cpu.eax;
    // 00472309  e8526f0000             -call 0x479260
    cpu.esp -= 4;
    sub_479260(app, cpu);
    if (cpu.terminate) return;
    // 0047230e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047230f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472310  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472311  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472312:
    // 00472312  e8d964fbff             -call 0x4287f0
    cpu.esp -= 4;
    sub_4287f0(app, cpu);
    if (cpu.terminate) return;
    // 00472317  e8d471feff             -call 0x4594f0
    cpu.esp -= 4;
    sub_4594f0(app, cpu);
    if (cpu.terminate) return;
    // 0047231c  e88ffefcff             -call 0x4421b0
    cpu.esp -= 4;
    sub_4421b0(app, cpu);
    if (cpu.terminate) return;
    // 00472321  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00472326  890d280f5400           -mov dword ptr [0x540f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */) = cpu.ecx;
    // 0047232c  890d200f5400           -mov dword ptr [0x540f20], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508896) /* 0x540f20 */) = cpu.ecx;
    // 00472332  8935240f5400           -mov dword ptr [0x540f24], esi
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.esi;
    // 00472338  e8236f0000             -call 0x479260
    cpu.esp -= 4;
    sub_479260(app, cpu);
    if (cpu.terminate) return;
    // 0047233d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047233f  e8ac250000             -call 0x4748f0
    cpu.esp -= 4;
    sub_4748f0(app, cpu);
    if (cpu.terminate) return;
    // 00472344  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472345  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472346  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472347  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472350);
    // 00472350  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472351  833d6c964d0000         +cmp dword ptr [0x4d966c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084780) /* 0x4d966c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472358  0f8594000000           -jne 0x4723f2
    if (!cpu.flags.zf)
    {
        goto L_0x004723f2;
    }
L_0x0047235e:
    // 0047235e  833d6c964d0000         +cmp dword ptr [0x4d966c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084780) /* 0x4d966c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472365  752a                   -jne 0x472391
    if (!cpu.flags.zf)
    {
        goto L_0x00472391;
    }
    // 00472367  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047236c  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00472371  e80a96feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00472376  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472378  7417                   -je 0x472391
    if (cpu.flags.zf)
    {
        goto L_0x00472391;
    }
    // 0047237a  833d6c964d0000         +cmp dword ptr [0x4d966c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084780) /* 0x4d966c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472381  0f85a4000000           -jne 0x47242b
    if (!cpu.flags.zf)
    {
        goto L_0x0047242b;
    }
L_0x00472387:
    // 00472387  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047238c:
    // 0047238c  a36c964d00             -mov dword ptr [0x4d966c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084780) /* 0x4d966c */) = cpu.eax;
L_0x00472391:
    // 00472391  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472396  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0047239b  e8e095feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 004723a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004723a2  7429                   -je 0x4723cd
    if (cpu.flags.zf)
    {
        goto L_0x004723cd;
    }
    // 004723a4  833dac5e4d0000         +cmp dword ptr [0x4d5eac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5070508) /* 0x4d5eac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004723ab  0f8581000000           -jne 0x472432
    if (!cpu.flags.zf)
    {
        goto L_0x00472432;
    }
    // 004723b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004723b6:
    // 004723b6  a3ac5e4d00             -mov dword ptr [0x4d5eac], eax
    app->getMemory<x86::reg32>(x86::reg32(5070508) /* 0x4d5eac */) = cpu.eax;
    // 004723bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004723bd  0f8473000000           -je 0x472436
    if (cpu.flags.zf)
    {
        goto L_0x00472436;
    }
    // 004723c3  a1b05e4d00             -mov eax, dword ptr [0x4d5eb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5070512) /* 0x4d5eb0 */);
    // 004723c8  a3380f5400             -mov dword ptr [0x540f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5508920) /* 0x540f38 */) = cpu.eax;
L_0x004723cd:
    // 004723cd  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004723d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004723d4  e8a795feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 004723d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004723db  7465                   -je 0x472442
    if (cpu.flags.zf)
    {
        goto L_0x00472442;
    }
    // 004723dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004723de  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004723e3  891d380f5400           -mov dword ptr [0x540f38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5508920) /* 0x540f38 */) = cpu.ebx;
    // 004723e9  891db05e4d00           -mov dword ptr [0x4d5eb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5070512) /* 0x4d5eb0 */) = cpu.ebx;
    // 004723ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004723f0:
    // 004723f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004723f2:
    // 004723f2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004723f7  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004723fc  e87f95feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00472401  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472403  740e                   -je 0x472413
    if (cpu.flags.zf)
    {
        goto L_0x00472413;
    }
L_0x00472405:
    // 00472405  833d6c964d0000         +cmp dword ptr [0x4d966c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084780) /* 0x4d966c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047240c  751d                   -jne 0x47242b
    if (!cpu.flags.zf)
    {
        goto L_0x0047242b;
    }
    // 0047240e  e974ffffff             -jmp 0x472387
    goto L_0x00472387;
L_0x00472413:
    // 00472413  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472418  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0047241d  e85e95feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00472422  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472424  75df                   -jne 0x472405
    if (!cpu.flags.zf)
    {
        goto L_0x00472405;
    }
    // 00472426  e933ffffff             -jmp 0x47235e
    goto L_0x0047235e;
L_0x0047242b:
    // 0047242b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047242d  e95affffff             -jmp 0x47238c
    goto L_0x0047238c;
L_0x00472432:
    // 00472432  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00472434  eb80                   -jmp 0x4723b6
    goto L_0x004723b6;
L_0x00472436:
    // 00472436  a1380f5400             -mov eax, dword ptr [0x540f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508920) /* 0x540f38 */);
    // 0047243b  a3b05e4d00             -mov dword ptr [0x4d5eb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5070512) /* 0x4d5eb0 */) = cpu.eax;
    // 00472440  eb8b                   -jmp 0x4723cd
    goto L_0x004723cd;
L_0x00472442:
    // 00472442  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00472447  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472449  e83295feff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 0047244e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472450  7510                   -jne 0x472462
    if (!cpu.flags.zf)
    {
        goto L_0x00472462;
    }
    // 00472452  833dac5e4d0000         +cmp dword ptr [0x4d5eac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5070508) /* 0x4d5eac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472459  7495                   -je 0x4723f0
    if (cpu.flags.zf)
    {
        goto L_0x004723f0;
    }
    // 0047245b  a3b05e4d00             -mov dword ptr [0x4d5eb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5070512) /* 0x4d5eb0 */) = cpu.eax;
    // 00472460  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472461  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472462:
    // 00472462  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472467  8915380f5400           -mov dword ptr [0x540f38], edx
    app->getMemory<x86::reg32>(x86::reg32(5508920) /* 0x540f38 */) = cpu.edx;
    // 0047246d  8915b05e4d00           -mov dword ptr [0x4d5eb0], edx
    app->getMemory<x86::reg32>(x86::reg32(5070512) /* 0x4d5eb0 */) = cpu.edx;
    // 00472473  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472474  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472480);
    // 00472480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472485  833d440f540000         +cmp dword ptr [0x540f44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508932) /* 0x540f44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047248c  7550                   -jne 0x4724de
    if (!cpu.flags.zf)
    {
        goto L_0x004724de;
    }
    // 0047248e  8b0d480f5400           -mov ecx, dword ptr [0x540f48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00472494  81f900020000           +cmp ecx, 0x200
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047249a  0f8c96000000           -jl 0x472536
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472536;
    }
    // 004724a0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004724a5  8a2d0c5a4d00           -mov ch, byte ptr [0x4d5a0c]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */);
    // 004724ab  8935440f5400           -mov dword ptr [0x540f44], esi
    app->getMemory<x86::reg32>(x86::reg32(5508932) /* 0x540f44 */) = cpu.esi;
    // 004724b1  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004724b3  7429                   -je 0x4724de
    if (cpu.flags.zf)
    {
        goto L_0x004724de;
    }
    // 004724b5  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004724ba  8b3db0964d00           -mov edi, dword ptr [0x4d96b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
    // 004724c0  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004724c2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004724c4  7469                   -je 0x47252f
    if (cpu.flags.zf)
    {
        goto L_0x0047252f;
    }
    // 004724c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004724c8:
    // 004724c8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004724cd  a134b45000             -mov eax, dword ptr [0x50b434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5289012) /* 0x50b434 */);
    // 004724d2  e8a9fdfcff             -call 0x442280
    cpu.esp -= 4;
    sub_442280(app, cpu);
    if (cpu.terminate) return;
    // 004724d7  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004724d9  a20c5a4d00             -mov byte ptr [0x4d5a0c], al
    app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */) = cpu.al;
L_0x004724de:
    // 004724de  e83d1afeff             -call 0x453f20
    cpu.esp -= 4;
    sub_453f20(app, cpu);
    if (cpu.terminate) return;
    // 004724e3  e8b8290000             -call 0x474ea0
    cpu.esp -= 4;
    sub_474ea0(app, cpu);
    if (cpu.terminate) return;
    // 004724e8  f605480f540001         +test byte ptr [0x540f48], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5508936) /* 0x540f48 */) & 1 /*0x1*/));
    // 004724ef  7516                   -jne 0x472507
    if (!cpu.flags.zf)
    {
        goto L_0x00472507;
    }
    // 004724f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004724f3  e8b8190100             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 004724f8  a1540f5400             -mov eax, dword ptr [0x540f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508948) /* 0x540f54 */);
    // 004724fd  e8eeeeffff             -call 0x4713f0
    cpu.esp -= 4;
    sub_4713f0(app, cpu);
    if (cpu.terminate) return;
    // 00472502  e819230000             -call 0x474820
    cpu.esp -= 4;
    sub_474820(app, cpu);
    if (cpu.terminate) return;
L_0x00472507:
    // 00472507  a1500f5400             -mov eax, dword ptr [0x540f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508944) /* 0x540f50 */);
    // 0047250c  e8dfeeffff             -call 0x4713f0
    cpu.esp -= 4;
    sub_4713f0(app, cpu);
    if (cpu.terminate) return;
    // 00472511  ff05480f5400           -inc dword ptr [0x540f48]
    (app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */))++;
    // 00472517  f605480f540001         +test byte ptr [0x540f48], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5508936) /* 0x540f48 */) & 1 /*0x1*/));
    // 0047251e  0f84ec000000           -je 0x472610
    if (cpu.flags.zf)
    {
        goto L_0x00472610;
    }
    // 00472524  e8b7290000             -call 0x474ee0
    cpu.esp -= 4;
    sub_474ee0(app, cpu);
    if (cpu.terminate) return;
    // 00472529  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047252a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047252b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047252c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047252d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047252e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047252f:
    // 0047252f  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00472534  eb92                   -jmp 0x4724c8
    goto L_0x004724c8;
L_0x00472536:
    // 00472536  81f9c0010000           +cmp ecx, 0x1c0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(448 /*0x1c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047253c  7c3e                   -jl 0x47257c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047257c;
    }
    // 0047253e  803d0c5a4d0001         +cmp byte ptr [0x4d5a0c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00472545  7497                   -je 0x4724de
    if (cpu.flags.zf)
    {
        goto L_0x004724de;
    }
    // 00472547  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0047254c  8b1db0964d00           -mov ebx, dword ptr [0x4d96b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
    // 00472552  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00472554  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00472556  741d                   -je 0x472575
    if (cpu.flags.zf)
    {
        goto L_0x00472575;
    }
    // 00472558  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0047255a:
    // 0047255a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0047255f  a134b45000             -mov eax, dword ptr [0x50b434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5289012) /* 0x50b434 */);
    // 00472564  e817fdfcff             -call 0x442280
    cpu.esp -= 4;
    sub_442280(app, cpu);
    if (cpu.terminate) return;
    // 00472569  c6050c5a4d0001         -mov byte ptr [0x4d5a0c], 1
    app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */) = 1 /*0x1*/;
    // 00472570  e969ffffff             -jmp 0x4724de
    goto L_0x004724de;
L_0x00472575:
    // 00472575  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0047257a  ebde                   -jmp 0x47255a
    goto L_0x0047255a;
L_0x0047257c:
    // 0047257c  81f980010000           +cmp ecx, 0x180
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472582  7c42                   -jl 0x4725c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004725c6;
    }
    // 00472584  803d0c5a4d0002         +cmp byte ptr [0x4d5a0c], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047258b  0f844dffffff           -je 0x4724de
    if (cpu.flags.zf)
    {
        goto L_0x004724de;
    }
    // 00472591  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00472596  8b15b0964d00           -mov edx, dword ptr [0x4d96b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
    // 0047259c  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0047259e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004725a0  741d                   -je 0x4725bf
    if (cpu.flags.zf)
    {
        goto L_0x004725bf;
    }
    // 004725a2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x004725a4:
    // 004725a4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004725a9  a134b45000             -mov eax, dword ptr [0x50b434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5289012) /* 0x50b434 */);
    // 004725ae  e8cdfcfcff             -call 0x442280
    cpu.esp -= 4;
    sub_442280(app, cpu);
    if (cpu.terminate) return;
    // 004725b3  c6050c5a4d0002         -mov byte ptr [0x4d5a0c], 2
    app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */) = 2 /*0x2*/;
    // 004725ba  e91fffffff             -jmp 0x4724de
    goto L_0x004724de;
L_0x004725bf:
    // 004725bf  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 004725c4  ebde                   -jmp 0x4725a4
    goto L_0x004725a4;
L_0x004725c6:
    // 004725c6  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004725cc  0f8c0cffffff           -jl 0x4724de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004724de;
    }
    // 004725d2  803d0c5a4d0003         +cmp byte ptr [0x4d5a0c], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004725d9  0f84fffeffff           -je 0x4724de
    if (cpu.flags.zf)
    {
        goto L_0x004724de;
    }
    // 004725df  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004725e4  a1b0964d00             -mov eax, dword ptr [0x4d96b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
    // 004725e9  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004725eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004725ed  741a                   -je 0x472609
    if (cpu.flags.zf)
    {
        goto L_0x00472609;
    }
    // 004725ef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004725f1:
    // 004725f1  a134b45000             -mov eax, dword ptr [0x50b434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5289012) /* 0x50b434 */);
    // 004725f6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004725f8  e883fcfcff             -call 0x442280
    cpu.esp -= 4;
    sub_442280(app, cpu);
    if (cpu.terminate) return;
    // 004725fd  c6050c5a4d0003         -mov byte ptr [0x4d5a0c], 3
    app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */) = 3 /*0x3*/;
    // 00472604  e9d5feffff             -jmp 0x4724de
    goto L_0x004724de;
L_0x00472609:
    // 00472609  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0047260e  ebe1                   -jmp 0x4725f1
    goto L_0x004725f1;
L_0x00472610:
    // 00472610  e8bbf7fcff             -call 0x441dd0
    cpu.esp -= 4;
    sub_441dd0(app, cpu);
    if (cpu.terminate) return;
    // 00472615  e8c6280000             -call 0x474ee0
    cpu.esp -= 4;
    sub_474ee0(app, cpu);
    if (cpu.terminate) return;
    // 0047261a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047261b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047261c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047261d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047261e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047261f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_472620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472620);
    // 00472620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472621  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472622  e8f96b0000             -call 0x479220
    cpu.esp -= 4;
    sub_479220(app, cpu);
    if (cpu.terminate) return;
    // 00472627  e824150000             -call 0x473b50
    cpu.esp -= 4;
    sub_473b50(app, cpu);
    if (cpu.terminate) return;
    // 0047262c  ba04cb4400             -mov edx, 0x44cb04
    cpu.edx = 4508420 /*0x44cb04*/;
    // 00472631  a1500f5400             -mov eax, dword ptr [0x540f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508944) /* 0x540f50 */);
    // 00472636  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472638  e8f3edffff             -call 0x471430
    cpu.esp -= 4;
    sub_471430(app, cpu);
    if (cpu.terminate) return;
    // 0047263d  e8fea4fcff             -call 0x43cb40
    cpu.esp -= 4;
    sub_43cb40(app, cpu);
    if (cpu.terminate) return;
    // 00472642  e899cefdff             -call 0x44f4e0
    cpu.esp -= 4;
    sub_44f4e0(app, cpu);
    if (cpu.terminate) return;
    // 00472647  e824baffff             -call 0x46e070
    cpu.esp -= 4;
    sub_46e070(app, cpu);
    if (cpu.terminate) return;
    // 0047264c  e87f160000             -call 0x473cd0
    cpu.esp -= 4;
    sub_473cd0(app, cpu);
    if (cpu.terminate) return;
    // 00472651  e89a480000             -call 0x476ef0
    cpu.esp -= 4;
    sub_476ef0(app, cpu);
    if (cpu.terminate) return;
    // 00472656  e8f5a4fcff             -call 0x43cb50
    cpu.esp -= 4;
    sub_43cb50(app, cpu);
    if (cpu.terminate) return;
    // 0047265b  e8008dfeff             -call 0x45b360
    cpu.esp -= 4;
    sub_45b360(app, cpu);
    if (cpu.terminate) return;
    // 00472660  a1540f5400             -mov eax, dword ptr [0x540f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508948) /* 0x540f54 */);
    // 00472665  e846efffff             -call 0x4715b0
    cpu.esp -= 4;
    sub_4715b0(app, cpu);
    if (cpu.terminate) return;
    // 0047266a  a1500f5400             -mov eax, dword ptr [0x540f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508944) /* 0x540f50 */);
    // 0047266f  e83cefffff             -call 0x4715b0
    cpu.esp -= 4;
    sub_4715b0(app, cpu);
    if (cpu.terminate) return;
    // 00472674  e8876efeff             -call 0x459500
    cpu.esp -= 4;
    sub_459500(app, cpu);
    if (cpu.terminate) return;
    // 00472679  e812000000             -call 0x472690
    cpu.esp -= 4;
    sub_472690(app, cpu);
    if (cpu.terminate) return;
    // 0047267e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047267f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472680  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472690);
    // 00472690  e8db7cfbff             -call 0x42a370
    cpu.esp -= 4;
    sub_42a370(app, cpu);
    if (cpu.terminate) return;
    // 00472695  a340225100             -mov dword ptr [0x512240], eax
    app->getMemory<x86::reg32>(x86::reg32(5317184) /* 0x512240 */) = cpu.eax;
    // 0047269a  a2ce2e5100             -mov byte ptr [0x512ece], al
    app->getMemory<x86::reg8>(x86::reg32(5320398) /* 0x512ece */) = cpu.al;
    // 0047269f  e8ec7cfbff             -call 0x42a390
    cpu.esp -= 4;
    sub_42a390(app, cpu);
    if (cpu.terminate) return;
    // 004726a4  a344225100             -mov dword ptr [0x512244], eax
    app->getMemory<x86::reg32>(x86::reg32(5317188) /* 0x512244 */) = cpu.eax;
    // 004726a9  a2cf2e5100             -mov byte ptr [0x512ecf], al
    app->getMemory<x86::reg8>(x86::reg32(5320399) /* 0x512ecf */) = cpu.al;
    // 004726ae  a048225100             -mov al, byte ptr [0x512248]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5317192) /* 0x512248 */);
    // 004726b3  a2d12e5100             -mov byte ptr [0x512ed1], al
    app->getMemory<x86::reg8>(x86::reg32(5320401) /* 0x512ed1 */) = cpu.al;
    // 004726b8  e8e33ffdff             -call 0x4466a0
    cpu.esp -= 4;
    sub_4466a0(app, cpu);
    if (cpu.terminate) return;
    // 004726bd  a34c225100             -mov dword ptr [0x51224c], eax
    app->getMemory<x86::reg32>(x86::reg32(5317196) /* 0x51224c */) = cpu.eax;
    // 004726c2  a2d02e5100             -mov byte ptr [0x512ed0], al
    app->getMemory<x86::reg8>(x86::reg32(5320400) /* 0x512ed0 */) = cpu.al;
    // 004726c7  a1e8eb4e00             -mov eax, dword ptr [0x4eebe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5172200) /* 0x4eebe8 */);
    // 004726cc  a350225100             -mov dword ptr [0x512250], eax
    app->getMemory<x86::reg32>(x86::reg32(5317200) /* 0x512250 */) = cpu.eax;
    // 004726d1  a2d22e5100             -mov byte ptr [0x512ed2], al
    app->getMemory<x86::reg8>(x86::reg32(5320402) /* 0x512ed2 */) = cpu.al;
    // 004726d6  e91565f9ff             -jmp 0x408bf0
    return sub_408bf0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4726e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004726e0);
    // 004726e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004726e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004726e3  a124225100             -mov eax, dword ptr [0x512224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317156) /* 0x512224 */);
    // 004726e8  8915240f5400           -mov dword ptr [0x540f24], edx
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.edx;
    // 004726ee  8915280f5400           -mov dword ptr [0x540f28], edx
    app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */) = cpu.edx;
    // 004726f4  89152c0f5400           -mov dword ptr [0x540f2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */) = cpu.edx;
    // 004726fa  8915300f5400           -mov dword ptr [0x540f30], edx
    app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */) = cpu.edx;
    // 00472700  8915340f5400           -mov dword ptr [0x540f34], edx
    app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */) = cpu.edx;
    // 00472706  8915440f5400           -mov dword ptr [0x540f44], edx
    app->getMemory<x86::reg32>(x86::reg32(5508932) /* 0x540f44 */) = cpu.edx;
    // 0047270c  8915480f5400           -mov dword ptr [0x540f48], edx
    app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */) = cpu.edx;
    // 00472712  e8c98bfeff             -call 0x45b2e0
    cpu.esp -= 4;
    sub_45b2e0(app, cpu);
    if (cpu.terminate) return;
    // 00472717  e874a3fcff             -call 0x43ca90
    cpu.esp -= 4;
    sub_43ca90(app, cpu);
    if (cpu.terminate) return;
    // 0047271c  e8dfb9ffff             -call 0x46e100
    cpu.esp -= 4;
    sub_46e100(app, cpu);
    if (cpu.terminate) return;
    // 00472721  e81ad5fdff             -call 0x44fc40
    cpu.esp -= 4;
    sub_44fc40(app, cpu);
    if (cpu.terminate) return;
    // 00472726  e825170000             -call 0x473e50
    cpu.esp -= 4;
    sub_473e50(app, cpu);
    if (cpu.terminate) return;
    // 0047272b  e800a2fcff             -call 0x43c930
    cpu.esp -= 4;
    sub_43c930(app, cpu);
    if (cpu.terminate) return;
    // 00472730  e8abcfffff             -call 0x46f6e0
    cpu.esp -= 4;
    sub_46f6e0(app, cpu);
    if (cpu.terminate) return;
    // 00472735  e8066b0000             -call 0x479240
    cpu.esp -= 4;
    sub_479240(app, cpu);
    if (cpu.terminate) return;
    // 0047273a  a13c2a5100             -mov eax, dword ptr [0x512a3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319228) /* 0x512a3c */);
    // 0047273f  a34c0f5400             -mov dword ptr [0x540f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5508940) /* 0x540f4c */) = cpu.eax;
    // 00472744  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472745  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472750);
    // 00472750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472753  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472758  b8fce04c00             -mov eax, 0x4ce0fc
    cpu.eax = 5038332 /*0x4ce0fc*/;
    // 0047275d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047275f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472761  8915200f5400           -mov dword ptr [0x540f20], edx
    app->getMemory<x86::reg32>(x86::reg32(5508896) /* 0x540f20 */) = cpu.edx;
    // 00472767  890d240f5400           -mov dword ptr [0x540f24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.ecx;
    // 0047276d  890d280f5400           -mov dword ptr [0x540f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508904) /* 0x540f28 */) = cpu.ecx;
    // 00472773  890d2c0f5400           -mov dword ptr [0x540f2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508908) /* 0x540f2c */) = cpu.ecx;
    // 00472779  890d300f5400           -mov dword ptr [0x540f30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508912) /* 0x540f30 */) = cpu.ecx;
    // 0047277f  890d340f5400           -mov dword ptr [0x540f34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508916) /* 0x540f34 */) = cpu.ecx;
    // 00472785  890d440f5400           -mov dword ptr [0x540f44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508932) /* 0x540f44 */) = cpu.ecx;
    // 0047278b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 00472790  890d480f5400           -mov dword ptr [0x540f48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */) = cpu.ecx;
    // 00472796  e825eeffff             -call 0x4715c0
    cpu.esp -= 4;
    sub_4715c0(app, cpu);
    if (cpu.terminate) return;
    // 0047279b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 004727a0  a3540f5400             -mov dword ptr [0x540f54], eax
    app->getMemory<x86::reg32>(x86::reg32(5508948) /* 0x540f54 */) = cpu.eax;
    // 004727a5  b804e14c00             -mov eax, 0x4ce104
    cpu.eax = 5038340 /*0x4ce104*/;
    // 004727aa  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004727af  e80ceeffff             -call 0x4715c0
    cpu.esp -= 4;
    sub_4715c0(app, cpu);
    if (cpu.terminate) return;
    // 004727b4  bae0f14400             -mov edx, 0x44f1e0
    cpu.edx = 4518368 /*0x44f1e0*/;
    // 004727b9  a3500f5400             -mov dword ptr [0x540f50], eax
    app->getMemory<x86::reg32>(x86::reg32(5508944) /* 0x540f50 */) = cpu.eax;
    // 004727be  a1540f5400             -mov eax, dword ptr [0x540f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508948) /* 0x540f54 */);
    // 004727c3  e818edffff             -call 0x4714e0
    cpu.esp -= 4;
    sub_4714e0(app, cpu);
    if (cpu.terminate) return;
    // 004727c8  a124225100             -mov eax, dword ptr [0x512224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317156) /* 0x512224 */);
    // 004727cd  e80e8bfeff             -call 0x45b2e0
    cpu.esp -= 4;
    sub_45b2e0(app, cpu);
    if (cpu.terminate) return;
    // 004727d2  e8c9a2fcff             -call 0x43caa0
    cpu.esp -= 4;
    sub_43caa0(app, cpu);
    if (cpu.terminate) return;
    // 004727d7  e8f4b8ffff             -call 0x46e0d0
    cpu.esp -= 4;
    sub_46e0d0(app, cpu);
    if (cpu.terminate) return;
    // 004727dc  e82f470000             -call 0x476f10
    cpu.esp -= 4;
    sub_476f10(app, cpu);
    if (cpu.terminate) return;
    // 004727e1  e8eacefdff             -call 0x44f6d0
    cpu.esp -= 4;
    sub_44f6d0(app, cpu);
    if (cpu.terminate) return;
    // 004727e6  e8f5680000             -call 0x4790e0
    cpu.esp -= 4;
    sub_4790e0(app, cpu);
    if (cpu.terminate) return;
    // 004727eb  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004727f0  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004727f5  e8c6ac0000             -call 0x47d4c0
    cpu.esp -= 4;
    sub_47d4c0(app, cpu);
    if (cpu.terminate) return;
    // 004727fa  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004727ff  ba04cb4400             -mov edx, 0x44cb04
    cpu.edx = 4508420 /*0x44cb04*/;
    // 00472804  e8b7ac0000             -call 0x47d4c0
    cpu.esp -= 4;
    sub_47d4c0(app, cpu);
    if (cpu.terminate) return;
    // 00472809  e862a2fcff             -call 0x43ca70
    cpu.esp -= 4;
    sub_43ca70(app, cpu);
    if (cpu.terminate) return;
    // 0047280e  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00472813  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472815  e8a6ac0000             -call 0x47d4c0
    cpu.esp -= 4;
    sub_47d4c0(app, cpu);
    if (cpu.terminate) return;
    // 0047281a  e8713bfdff             -call 0x446390
    cpu.esp -= 4;
    sub_446390(app, cpu);
    if (cpu.terminate) return;
    // 0047281f  a1500f5400             -mov eax, dword ptr [0x540f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508944) /* 0x540f50 */);
    // 00472824  e8b7ecffff             -call 0x4714e0
    cpu.esp -= 4;
    sub_4714e0(app, cpu);
    if (cpu.terminate) return;
    // 00472829  e842cefdff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 0047282e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047282f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472830  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472831  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472840);
    // 00472840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472842  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472843  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472844  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472845  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472846  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0047284c  8b1508225100           -mov edx, dword ptr [0x512208]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 00472852  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472854  83fa02                 +cmp edx, 2
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
    // 00472857  7c0d                   -jl 0x472866
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472866;
    }
L_0x00472859:
    // 00472859  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0047285f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472862  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472863  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472864  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472865  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472866:
    // 00472866  8b0d68964d00           -mov ecx, dword ptr [0x4d9668]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084776) /* 0x4d9668 */);
    // 0047286c  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00472871  41                     -inc ecx
    (cpu.ecx)++;
    // 00472872  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00472874  890d68964d00           -mov dword ptr [0x4d9668], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084776) /* 0x4d9668 */) = cpu.ecx;
    // 0047287a  e8d1defbff             -call 0x430750
    cpu.esp -= 4;
    sub_430750(app, cpu);
    if (cpu.terminate) return;
    // 0047287f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472881  74d6                   -je 0x472859
    if (cpu.flags.zf)
    {
        goto L_0x00472859;
    }
    // 00472883  8b3568964d00           -mov esi, dword ptr [0x4d9668]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084776) /* 0x4d9668 */);
    // 00472889  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047288a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047288e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047288f  68c0e04c00             -push 0x4ce0c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038272 /*0x4ce0c0*/;
    cpu.esp -= 4;
    // 00472894  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047289b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047289c  e8603c0100             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004728a1  8b3d244d4d00           -mov edi, dword ptr [0x4d4d24]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */);
    // 004728a7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004728aa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004728ac  0f8594000000           -jne 0x472946
    if (!cpu.flags.zf)
    {
        goto L_0x00472946;
    }
    // 004728b2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004728b7  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004728bc  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 004728c1  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 004728c6  e855ff0100             -call 0x492820
    cpu.esp -= 4;
    sub_492820(app, cpu);
    if (cpu.terminate) return;
    // 004728cb  a3244d4d00             -mov dword ptr [0x4d4d24], eax
    app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */) = cpu.eax;
    // 004728d0  e8d3fc0000             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 004728d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004728d7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004728dc  e85ffe0000             -call 0x482740
    cpu.esp -= 4;
    sub_482740(app, cpu);
    if (cpu.terminate) return;
L_0x004728e1:
    // 004728e1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004728e3  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004728e9  a1244d4d00             -mov eax, dword ptr [0x4d4d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */);
    // 004728ee  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004728f1  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004728f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004728f5  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 004728fa  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 004728ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472901  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472903  ff15f8365600           -call dword ptr [0x5636f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650168) /* 0x5636f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472909  8d842400020000         -lea eax, [esp + 0x200]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00472910  e8234c0100             -call 0x487538
    cpu.esp -= 4;
    sub_487538(app, cpu);
    if (cpu.terminate) return;
    // 00472915  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00472917  0f843cffffff           -je 0x472859
    if (cpu.flags.zf)
    {
        goto L_0x00472859;
    }
    // 0047291d  8b2d244d4d00           -mov ebp, dword ptr [0x4d4d24]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */);
    // 00472923  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472925  0f842effffff           -je 0x472859
    if (cpu.flags.zf)
    {
        goto L_0x00472859;
    }
    // 0047292b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047292d  e86e040100             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
    // 00472932  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472934  a3244d4d00             -mov dword ptr [0x4d4d24], eax
    app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */) = cpu.eax;
    // 00472939  81c400030000           +add esp, 0x300
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047293f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472940  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472941  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472942  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472943  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472944  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472945  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472946:
    // 00472946  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472948  e85bfc0000             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 0047294d  eb92                   -jmp 0x4728e1
    goto L_0x004728e1;
}

/* align: skip 0x00 */
void Application::sub_472950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472950);
    // 00472950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472951  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472953  833d70964d0000         +cmp dword ptr [0x4d9670], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084784) /* 0x4d9670 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047295a  743c                   -je 0x472998
    if (cpu.flags.zf)
    {
        goto L_0x00472998;
    }
    // 0047295c  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472964  7534                   -jne 0x47299a
    if (!cpu.flags.zf)
    {
        goto L_0x0047299a;
    }
    // 00472966  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 0047296d  752b                   -jne 0x47299a
    if (!cpu.flags.zf)
    {
        goto L_0x0047299a;
    }
    // 0047296f  8b0d64225100           -mov ecx, dword ptr [0x512264]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 00472975  49                     -dec ecx
    (cpu.ecx)--;
    // 00472976  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472978  7c1e                   -jl 0x472998
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472998;
    }
    // 0047297a  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00472981  42                     -inc edx
    (cpu.edx)++;
    // 00472982  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00472984:
    // 00472984  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00472986  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472988  e887100000             -call 0x473a14
    cpu.esp -= 4;
    sub_473a14(app, cpu);
    if (cpu.terminate) return;
    // 0047298d  49                     -dec ecx
    (cpu.ecx)--;
    // 0047298e  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472991  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472993  7def                   -jge 0x472984
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472984;
    }
    // 00472995  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00472998:
    // 00472998  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472999  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047299a:
    // 0047299a  0fbe4201               -movsx eax, byte ptr [edx + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */)));
    // 0047299e  e8ad0c0000             -call 0x473650
    cpu.esp -= 4;
    sub_473650(app, cpu);
    if (cpu.terminate) return;
    // 004729a3  8a1d5f345100           -mov bl, byte ptr [0x51345f]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5321823) /* 0x51345f */);
    // 004729a9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004729ac  80fb01                 +cmp bl, 1
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
    // 004729af  7415                   -je 0x4729c6
    if (cpu.flags.zf)
    {
        goto L_0x004729c6;
    }
    // 004729b1  833d0c22510000         +cmp dword ptr [0x51220c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004729b8  752f                   -jne 0x4729e9
    if (!cpu.flags.zf)
    {
        goto L_0x004729e9;
    }
    // 004729ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004729bf  e850100000             -call 0x473a14
    cpu.esp -= 4;
    sub_473a14(app, cpu);
    if (cpu.terminate) return;
    // 004729c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004729c6:
    // 004729c6  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 004729cb  e878750100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004729d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004729d2  e82914ffff             -call 0x463e00
    cpu.esp -= 4;
    sub_463e00(app, cpu);
    if (cpu.terminate) return;
    // 004729d7  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004729d8  e8030f0000             -call 0x4738e0
    cpu.esp -= 4;
    sub_4738e0(app, cpu);
    if (cpu.terminate) return;
    // 004729dd  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 004729e2  e879750100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004729e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004729e9:
    // 004729e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004729eb  e824100000             -call 0x473a14
    cpu.esp -= 4;
    sub_473a14(app, cpu);
    if (cpu.terminate) return;
    // 004729f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472a00);
    // 00472a00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472a01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472a02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472a03  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00472a06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472a08  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 00472a0f  755d                   -jne 0x472a6e
    if (!cpu.flags.zf)
    {
        goto L_0x00472a6e;
    }
    // 00472a11  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472a19  7453                   -je 0x472a6e
    if (cpu.flags.zf)
    {
        goto L_0x00472a6e;
    }
    // 00472a1b  b305                   -mov bl, 5
    cpu.bl = 5 /*0x5*/;
    // 00472a1d  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 00472a22  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00472a24  881c24                 -mov byte ptr [esp], bl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.bl;
    // 00472a27  e81c750100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00472a2c  a10c225100             -mov eax, dword ptr [0x51220c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 00472a31  e8de0f0000             -call 0x473a14
    cpu.esp -= 4;
    sub_473a14(app, cpu);
    if (cpu.terminate) return;
    // 00472a36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472a38  7511                   -jne 0x472a4b
    if (!cpu.flags.zf)
    {
        goto L_0x00472a4b;
    }
    // 00472a3a  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 00472a3f  e81c750100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x00472a44:
    // 00472a44  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00472a47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472a4b:
    // 00472a4b  8d442401               -lea eax, [esp + 1]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00472a4f  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 00472a54  e8870c0000             -call 0x4736e0
    cpu.esp -= 4;
    sub_4736e0(app, cpu);
    if (cpu.terminate) return;
    // 00472a59  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 00472a5e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00472a60  e8fb740100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00472a65  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00472a67  e80416ffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 00472a6c  ebd6                   -jmp 0x472a44
    goto L_0x00472a44;
L_0x00472a6e:
    // 00472a6e  e8fd0b0000             -call 0x473670
    cpu.esp -= 4;
    sub_473670(app, cpu);
    if (cpu.terminate) return;
    // 00472a73  8a155f345100           -mov dl, byte ptr [0x51345f]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5321823) /* 0x51345f */);
    // 00472a79  a2790f5400             -mov byte ptr [0x540f79], al
    app->getMemory<x86::reg8>(x86::reg32(5508985) /* 0x540f79 */) = cpu.al;
    // 00472a7e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00472a80  7510                   -jne 0x472a92
    if (!cpu.flags.zf)
    {
        goto L_0x00472a92;
    }
    // 00472a82  a10c225100             -mov eax, dword ptr [0x51220c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 00472a87  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00472a89  e8860f0000             -call 0x473a14
    cpu.esp -= 4;
    sub_473a14(app, cpu);
    if (cpu.terminate) return;
    // 00472a8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472a90  74b2                   -je 0x472a44
    if (cpu.flags.zf)
    {
        goto L_0x00472a44;
    }
L_0x00472a92:
    // 00472a92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472a93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472a94  b605                   -mov dh, 5
    cpu.dh = 5 /*0x5*/;
    // 00472a96  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00472a9b  bf7a0f5400             -mov edi, 0x540f7a
    cpu.edi = 5508986 /*0x540f7a*/;
    // 00472aa0  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00472aa5  8835780f5400           -mov byte ptr [0x540f78], dh
    app->getMemory<x86::reg8>(x86::reg32(5508984) /* 0x540f78 */) = cpu.dh;
    // 00472aab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472aac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472aae  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472ab1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472ab3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472ab5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472ab8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472aba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472abb  ba780f5400             -mov edx, 0x540f78
    cpu.edx = 5508984 /*0x540f78*/;
    // 00472ac0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472ac2  e8a915ffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 00472ac7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472ac8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472ac9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00472acc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472acd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472ace  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472acf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_472ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472ad0);
    // 00472ad0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472ad1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472ad2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472ad3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00472ad5  8b3d5c0f5400           -mov edi, dword ptr [0x540f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5508956) /* 0x540f5c */);
    // 00472adb  8b0d580f5400           -mov ecx, dword ptr [0x540f58]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5508952) /* 0x540f58 */);
    // 00472ae1  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00472ae4  46                     -inc esi
    (cpu.esi)++;
    // 00472ae5  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00472ae7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00472ae9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472aea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472aec  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472aef  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472af1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472af3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472af6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472af8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472af9  0115580f5400           -add dword ptr [0x540f58], edx
    (app->getMemory<x86::reg32>(x86::reg32(5508952) /* 0x540f58 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472aff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472b10);
    // 00472b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472b15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472b16  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 00472b1c  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 00472b21  be34225100             -mov esi, 0x512234
    cpu.esi = 5317172 /*0x512234*/;
    // 00472b26  8d7c2464               -lea edi, [esp + 0x64]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00472b2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472b2b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472b2d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472b30  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472b32  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472b34  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472b37  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472b39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472b3c  b9f8215100             -mov ecx, 0x5121f8
    cpu.ecx = 5317112 /*0x5121f8*/;
    // 00472b41  b8002d0000             -mov eax, 0x2d00
    cpu.eax = 11520 /*0x2d00*/;
    // 00472b46  8915580f5400           -mov dword ptr [0x540f58], edx
    app->getMemory<x86::reg32>(x86::reg32(5508952) /* 0x540f58 */) = cpu.edx;
    // 00472b4c  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00472b51  890d5c0f5400           -mov dword ptr [0x540f5c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508956) /* 0x540f5c */) = cpu.ecx;
    // 00472b57  e8d40dffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 00472b5c  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472b64  0f84e0000000           -je 0x472c4a
    if (cpu.flags.zf)
    {
        goto L_0x00472c4a;
    }
    // 00472b6a  8b1dbc764d00           -mov ebx, dword ptr [0x4d76bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5076668) /* 0x4d76bc */);
    // 00472b70  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00472b72  741c                   -je 0x472b90
    if (cpu.flags.zf)
    {
        goto L_0x00472b90;
    }
    // 00472b74  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00472b79  bf04275100             -mov edi, 0x512704
    cpu.edi = 5318404 /*0x512704*/;
    // 00472b7e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00472b80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472b81  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472b83  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472b86  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472b88  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472b8a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472b8d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472b8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00472b90:
    // 00472b90  8b35b8764d00           -mov esi, dword ptr [0x4d76b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076664) /* 0x4d76b8 */);
    // 00472b96  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00472b98  0f8587000000           -jne 0x472c25
    if (!cpu.flags.zf)
    {
        goto L_0x00472c25;
    }
L_0x00472b9e:
    // 00472b9e  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 00472ba3  be842e5100             -mov esi, 0x512e84
    cpu.esi = 5320324 /*0x512e84*/;
    // 00472ba8  bf16275100             -mov edi, 0x512716
    cpu.edi = 5318422 /*0x512716*/;
    // 00472bad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472bae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472bb0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472bb3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472bb5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472bb7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472bba  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472bbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472bbd  b404                   -mov ah, 4
    cpu.ah = 4 /*0x4*/;
    // 00472bbf  bfb0050000             -mov edi, 0x5b0
    cpu.edi = 1456 /*0x5b0*/;
    // 00472bc4  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00472bc7  89bc2490000000         -mov dword ptr [esp + 0x90], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edi;
L_0x00472bce:
    // 00472bce  bd62000000             -mov ebp, 0x62
    cpu.ebp = 98 /*0x62*/;
L_0x00472bd3:
    // 00472bd3  8d7c2401               -lea edi, [esp + 1]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00472bd7  8b355c0f5400           -mov esi, dword ptr [0x540f5c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5508956) /* 0x540f5c */);
    // 00472bdd  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00472bdf  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00472be1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472be2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472be4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472be7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472be9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472beb  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472bee  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472bf0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472bf1  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00472bf4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472bf6  e87514ffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 00472bfb  a15c0f5400             -mov eax, dword ptr [0x540f5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508956) /* 0x540f5c */);
    // 00472c00  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00472c07  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00472c09  83ea62                 -sub edx, 0x62
    (cpu.edx) -= x86::reg32(x86::sreg32(98 /*0x62*/));
    // 00472c0c  a35c0f5400             -mov dword ptr [0x540f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5508956) /* 0x540f5c */) = cpu.eax;
    // 00472c11  89942490000000         -mov dword ptr [esp + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 00472c18  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00472c1a  7e2e                   -jle 0x472c4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472c4a;
    }
    // 00472c1c  83fa62                 +cmp edx, 0x62
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98 /*0x62*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472c1f  7dad                   -jge 0x472bce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472bce;
    }
    // 00472c21  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00472c23  ebae                   -jmp 0x472bd3
    goto L_0x00472bd3;
L_0x00472c25:
    // 00472c25  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00472c2a  bff4265100             -mov edi, 0x5126f4
    cpu.edi = 5318388 /*0x5126f4*/;
    // 00472c2f  81c6b0020000           -add esi, 0x2b0
    (cpu.esi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 00472c35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472c36  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472c38  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472c3b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472c3d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472c3f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472c42  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472c44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c45  e954ffffff             -jmp 0x472b9e
    goto L_0x00472b9e;
L_0x00472c4a:
    // 00472c4a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00472c4f  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 00472c54  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 00472c59  e8d20cffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 00472c5e  8b150a345100           -mov edx, dword ptr [0x51340a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321738) /* 0x51340a */);
    // 00472c64  8d742464               -lea esi, [esp + 0x64]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00472c68  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00472c6b  bf34225100             -mov edi, 0x512234
    cpu.edi = 5317172 /*0x512234*/;
    // 00472c70  89150c225100           -mov dword ptr [0x51220c], edx
    app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */) = cpu.edx;
    // 00472c76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472c77  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472c79  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472c7c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472c7e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472c80  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472c83  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472c85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c86  8b35bc764d00           -mov esi, dword ptr [0x4d76bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076668) /* 0x4d76bc */);
    // 00472c8c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00472c8e  741c                   -je 0x472cac
    if (cpu.flags.zf)
    {
        goto L_0x00472cac;
    }
    // 00472c90  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00472c95  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00472c97  be04275100             -mov esi, 0x512704
    cpu.esi = 5318404 /*0x512704*/;
    // 00472c9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472c9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472c9f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472ca2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472ca4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472ca6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472ca9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472cab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00472cac:
    // 00472cac  8b3db8764d00           -mov edi, dword ptr [0x4d76b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5076664) /* 0x4d76b8 */);
    // 00472cb2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00472cb4  752c                   -jne 0x472ce2
    if (!cpu.flags.zf)
    {
        goto L_0x00472ce2;
    }
L_0x00472cb6:
    // 00472cb6  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 00472cbb  be16275100             -mov esi, 0x512716
    cpu.esi = 5318422 /*0x512716*/;
    // 00472cc0  bf842e5100             -mov edi, 0x512e84
    cpu.edi = 5320324 /*0x512e84*/;
    // 00472cc5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472cc6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472cc8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472ccb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472ccd  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472ccf  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472cd2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472cd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472cd5  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 00472cdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472cdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472cdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472cde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472cdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472ce0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472ce1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472ce2:
    // 00472ce2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00472ce7  bef4265100             -mov esi, 0x5126f4
    cpu.esi = 5318388 /*0x5126f4*/;
    // 00472cec  81c7b0020000           -add edi, 0x2b0
    (cpu.edi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 00472cf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472cf3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472cf5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00472cf8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472cfa  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00472cfc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00472cff  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00472d01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d02  ebb2                   -jmp 0x472cb6
    goto L_0x00472cb6;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472d10);
    // 00472d10  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00472d13  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472d1a  7e04                   -jle 0x472d20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472d20;
    }
    // 00472d1c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00472d1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472d20:
    // 00472d20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472d21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472d23  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472d24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472d25  e85661fbff             -call 0x428e80
    cpu.esp -= 4;
    sub_428e80(app, cpu);
    if (cpu.terminate) return;
    // 00472d2a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00472d2c  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472d32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472d34  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00472d36  ff1574375600           -call dword ptr [0x563774]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650292) /* 0x563774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472d3c  ff1578375600           -call dword ptr [0x563778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650296) /* 0x563778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472d42  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00472d47  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00472d4b  e8206cfeff             -call 0x459970
    cpu.esp -= 4;
    sub_459970(app, cpu);
    if (cpu.terminate) return;
    // 00472d50  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472d52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00472d53:
    // 00472d53  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00472d55  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00472d57  3c00                   +cmp al, 0
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
    // 00472d59  7410                   -je 0x472d6b
    if (cpu.flags.zf)
    {
        goto L_0x00472d6b;
    }
    // 00472d5b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00472d5e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00472d61  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00472d64  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00472d67  3c00                   +cmp al, 0
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
    // 00472d69  75e8                   -jne 0x472d53
    if (!cpu.flags.zf)
    {
        goto L_0x00472d53;
    }
L_0x00472d6b:
    // 00472d6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d6c  be0ce14c00             -mov esi, 0x4ce10c
    cpu.esi = 5038348 /*0x4ce10c*/;
    // 00472d71  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00472d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472d76  2bc9                   +sub ecx, ecx
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
    // 00472d78  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00472d79  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00472d7b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00472d7d  4f                     -dec edi
    (cpu.edi)--;
L_0x00472d7e:
    // 00472d7e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00472d80  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00472d82  3c00                   +cmp al, 0
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
    // 00472d84  7410                   -je 0x472d96
    if (cpu.flags.zf)
    {
        goto L_0x00472d96;
    }
    // 00472d86  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00472d89  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00472d8c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00472d8f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00472d92  3c00                   +cmp al, 0
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
    // 00472d94  75e8                   -jne 0x472d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00472d7e;
    }
L_0x00472d96:
    // 00472d96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d97  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00472d9b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472d9d  49                     -dec ecx
    (cpu.ecx)--;
    // 00472d9e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00472da0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00472da2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00472da4  49                     -dec ecx
    (cpu.ecx)--;
    // 00472da5  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00472da7  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00472dae  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00472db0  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00472db5  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472db7  bbe6000000             -mov ebx, 0xe6
    cpu.ebx = 230 /*0xe6*/;
    // 00472dbc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00472dbe  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00472dc2  e8f98f0000             -call 0x47bdc0
    cpu.esp -= 4;
    sub_47bdc0(app, cpu);
    if (cpu.terminate) return;
    // 00472dc7  ff155c375600           -call dword ptr [0x56375c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650268) /* 0x56375c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472dcd  ff154c375600           -call dword ptr [0x56374c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650252) /* 0x56374c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472dd3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00472dd5  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472ddb  ff1578375600           -call dword ptr [0x563778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650296) /* 0x563778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472de1  e83a61fbff             -call 0x428f20
    cpu.esp -= 4;
    sub_428f20(app, cpu);
    if (cpu.terminate) return;
    // 00472de6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472de7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472de8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472de9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472dea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472deb  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00472dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_472e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472e00);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00472e00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472e01  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472e03  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00472e06  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00472e08  771d                   -ja 0x472e27
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00472e27;
    }
    // 00472e0a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00472e0f  ff2485f02d4700         -jmp dword ptr [eax*4 + 0x472df0]
    cpu.ip = app->getMemory<x86::reg32>(4664816 + cpu.eax * 4); goto dynamic_jump;
  case 0x00472e16:
    // 00472e16  833d0c22510000         +cmp dword ptr [0x51220c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e1d  740a                   -je 0x472e29
    if (cpu.flags.zf)
    {
        goto L_0x00472e29;
    }
    // 00472e1f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00472e22  a3640f5400             -mov dword ptr [0x540f64], eax
    app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */) = cpu.eax;
L_0x00472e27:
    // 00472e27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472e28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472e29:
    // 00472e29  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 00472e2e  e815710100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00472e33  833d640f540000         +cmp dword ptr [0x540f64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e3a  7519                   -jne 0x472e55
    if (!cpu.flags.zf)
    {
        goto L_0x00472e55;
    }
    // 00472e3c  e88f080000             -call 0x4736d0
    cpu.esp -= 4;
    sub_4736d0(app, cpu);
    if (cpu.terminate) return;
    // 00472e41  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00472e46  a3640f5400             -mov dword ptr [0x540f64], eax
    app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */) = cpu.eax;
    // 00472e4b  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472e4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472e50  e81b12ffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
L_0x00472e55:
    // 00472e55  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 00472e5a  e801710100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00472e5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472e60  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472e61:
    // 00472e61  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472e69  740c                   -je 0x472e77
    if (cpu.flags.zf)
    {
        goto L_0x00472e77;
    }
    // 00472e6b  c705600f540001000000   -mov dword ptr [0x540f60], 1
    app->getMemory<x86::reg32>(x86::reg32(5508960) /* 0x540f60 */) = 1 /*0x1*/;
    // 00472e75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472e76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472e77:
    // 00472e77  66c7052a3451001200     -mov word ptr [0x51342a], 0x12
    app->getMemory<x86::reg16>(x86::reg32(5321770) /* 0x51342a */) = 18 /*0x12*/;
    // 00472e80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472e81  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472e82:
    // 00472e82  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472e8a  759b                   -jne 0x472e27
    if (!cpu.flags.zf)
    {
        goto L_0x00472e27;
    }
    // 00472e8c  66c7052a3451001500     -mov word ptr [0x51342a], 0x15
    app->getMemory<x86::reg16>(x86::reg32(5321770) /* 0x51342a */) = 21 /*0x15*/;
    // 00472e95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472e96  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472e97:
    // 00472e97  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472e9f  750b                   -jne 0x472eac
    if (!cpu.flags.zf)
    {
        goto L_0x00472eac;
    }
    // 00472ea1  66c7052a3451001600     -mov word ptr [0x51342a], 0x16
    app->getMemory<x86::reg16>(x86::reg32(5321770) /* 0x51342a */) = 22 /*0x16*/;
    // 00472eaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472eac:
    // 00472eac  a10c774d00             -mov eax, dword ptr [0x4d770c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076748) /* 0x4d770c */);
    // 00472eb1  e892700100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00472eb6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472eb8  e8430fffff             -call 0x463e00
    cpu.esp -= 4;
    sub_463e00(app, cpu);
    if (cpu.terminate) return;
    // 00472ebd  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00472ebe  66c70445383451001600   -mov word ptr [eax*2 + 0x513438], 0x16
    app->getMemory<x86::reg16>(x86::reg32(5321784) /* 0x513438 */ + cpu.eax * 2) = 22 /*0x16*/;
    // 00472ec8  a10c774d00             -mov eax, dword ptr [0x4d770c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076748) /* 0x4d770c */);
    // 00472ecd  e88e700100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00472ed2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472ed3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472ee0);
    // 00472ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472ee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472ee4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472ee5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472ee6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472ee9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00472eeb  8b1508225100           -mov edx, dword ptr [0x512208]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 00472ef1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00472ef3  740e                   -je 0x472f03
    if (cpu.flags.zf)
    {
        goto L_0x00472f03;
    }
    // 00472ef5  83fa01                 +cmp edx, 1
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
    // 00472ef8  7409                   -je 0x472f03
    if (cpu.flags.zf)
    {
        goto L_0x00472f03;
    }
    // 00472efa  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f01  7e0e                   -jle 0x472f11
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472f11;
    }
L_0x00472f03:
    // 00472f03  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00472f05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472f07  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472f0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472f0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472f0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472f0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472f10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472f11:
    // 00472f11  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00472f16  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472f18  e813f10000             -call 0x482030
    cpu.esp -= 4;
    sub_482030(app, cpu);
    if (cpu.terminate) return;
    // 00472f1d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472f1f  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00472f25  81f9ff000000           +cmp ecx, 0xff
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
    // 00472f2b  7d09                   -jge 0x472f36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472f36;
    }
    // 00472f2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472f2f  e8ee350100             -call 0x486522
    cpu.esp -= 4;
    sub_486522(app, cpu);
    if (cpu.terminate) return;
    // 00472f34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00472f36:
    // 00472f36  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472f38  0f84ae000000           -je 0x472fec
    if (cpu.flags.zf)
    {
        goto L_0x00472fec;
    }
    // 00472f3e  3b0d740f5400           +cmp ecx, dword ptr [0x540f74]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508980) /* 0x540f74 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f44  0f8496000000           -je 0x472fe0
    if (cpu.flags.zf)
    {
        goto L_0x00472fe0;
    }
L_0x00472f4a:
    // 00472f4a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472f4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472f51  e87ae0faff             -call 0x420fd0
    cpu.esp -= 4;
    sub_420fd0(app, cpu);
    if (cpu.terminate) return;
    // 00472f56  3b0d740f5400           +cmp ecx, dword ptr [0x540f74]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508980) /* 0x540f74 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f5c  0f849c000000           -je 0x472ffe
    if (cpu.flags.zf)
    {
        goto L_0x00472ffe;
    }
    // 00472f62  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x00472f65:
    // 00472f65  8935700f5400           -mov dword ptr [0x540f70], esi
    app->getMemory<x86::reg32>(x86::reg32(5508976) /* 0x540f70 */) = cpu.esi;
    // 00472f6b  890d740f5400           -mov dword ptr [0x540f74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508980) /* 0x540f74 */) = cpu.ecx;
L_0x00472f71:
    // 00472f71  66833d5834510000       +cmp word ptr [0x513458], 0
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
    // 00472f79  0f84a3010000           -je 0x473122
    if (cpu.flags.zf)
    {
        goto L_0x00473122;
    }
    // 00472f7f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00472f84  3b0d64225100           +cmp ecx, dword ptr [0x512264]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f8a  0f8dd1000000           -jge 0x473061
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473061;
    }
    // 00472f90  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x00472f95:
    // 00472f95  833d600f540000         +cmp dword ptr [0x540f60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508960) /* 0x540f60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f9c  7468                   -je 0x473006
    if (cpu.flags.zf)
    {
        goto L_0x00473006;
    }
L_0x00472f9e:
    // 00472f9e  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00472fa3  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 00472fa8  e88309ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 00472fad  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00472faf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472fb4  893d80964d00           -mov dword ptr [0x4d9680], edi
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.edi;
    // 00472fba  893d600f5400           -mov dword ptr [0x540f60], edi
    app->getMemory<x86::reg32>(x86::reg32(5508960) /* 0x540f60 */) = cpu.edi;
    // 00472fc0  e8fbdffaff             -call 0x420fc0
    cpu.esp -= 4;
    sub_420fc0(app, cpu);
    if (cpu.terminate) return;
    // 00472fc5  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 00472fca  e86109ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 00472fcf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472fd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472fd6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472fd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472fda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472fdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472fdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472fdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472fde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472fdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472fe0:
    // 00472fe0  3b35700f5400           +cmp esi, dword ptr [0x540f70]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508976) /* 0x540f70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472fe6  0f8f5effffff           -jg 0x472f4a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00472f4a;
    }
L_0x00472fec:
    // 00472fec  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00472fee  890d740f5400           -mov dword ptr [0x540f74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508980) /* 0x540f74 */) = cpu.ecx;
    // 00472ff4  a3700f5400             -mov dword ptr [0x540f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5508976) /* 0x540f70 */) = cpu.eax;
    // 00472ff9  e973ffffff             -jmp 0x472f71
    goto L_0x00472f71;
L_0x00472ffe:
    // 00472ffe  83c605                 +add esi, 5
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00473001  e95fffffff             -jmp 0x472f65
    goto L_0x00472f65;
L_0x00473006:
    // 00473006  668b8238345100         -mov ax, word ptr [edx + 0x513438]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5321784) /* 0x513438 */);
    // 0047300d  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00473010  763d                   -jbe 0x47304f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047304f;
    }
    // 00473012  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00473016  756c                   -jne 0x473084
    if (!cpu.flags.zf)
    {
        goto L_0x00473084;
    }
    // 00473018  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 0047301f  755c                   -jne 0x47307d
    if (!cpu.flags.zf)
    {
        goto L_0x0047307d;
    }
    // 00473021  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473023  e848b40000             -call 0x47e470
    cpu.esp -= 4;
    sub_47e470(app, cpu);
    if (cpu.terminate) return;
L_0x00473028:
    // 00473028  a10c774d00             -mov eax, dword ptr [0x4d770c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076748) /* 0x4d770c */);
    // 0047302d  e8166f0100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00473032  6683ba3834510016       +cmp word ptr [edx + 0x513438], 0x16
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5321784) /* 0x513438 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047303a  7509                   -jne 0x473045
    if (!cpu.flags.zf)
    {
        goto L_0x00473045;
    }
    // 0047303c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047303e  6689ba38345100         -mov word ptr [edx + 0x513438], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5321784) /* 0x513438 */) = cpu.di;
L_0x00473045:
    // 00473045  a10c774d00             -mov eax, dword ptr [0x4d770c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076748) /* 0x4d770c */);
    // 0047304a  e8116f0100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x0047304f:
    // 0047304f  8b2d64225100           -mov ebp, dword ptr [0x512264]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 00473055  41                     -inc ecx
    (cpu.ecx)++;
    // 00473056  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00473059  39e9                   +cmp ecx, ebp
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
    // 0047305b  0f8c34ffffff           -jl 0x472f95
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472f95;
    }
L_0x00473061:
    // 00473061  83fb02                 +cmp ebx, 2
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
    // 00473064  733d                   -jae 0x4730a3
    if (!cpu.flags.cf)
    {
        goto L_0x004730a3;
    }
    // 00473066  83fb01                 +cmp ebx, 1
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
    // 00473069  0f842fffffff           -je 0x472f9e
    if (cpu.flags.zf)
    {
        goto L_0x00472f9e;
    }
L_0x0047306f:
    // 0047306f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473071  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473073  83c410                 +add esp, 0x10
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
    // 00473076  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473077  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473078  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473079  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047307a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047307b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047307c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047307d:
    // 0047307d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00473082  eba4                   -jmp 0x473028
    goto L_0x00473028;
L_0x00473084:
    // 00473084  a10c774d00             -mov eax, dword ptr [0x4d770c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076748) /* 0x4d770c */);
    // 00473089  e8ba6e0100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0047308e  6683ba3834510016       +cmp word ptr [edx + 0x513438], 0x16
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5321784) /* 0x513438 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00473096  74ad                   -je 0x473045
    if (cpu.flags.zf)
    {
        goto L_0x00473045;
    }
    // 00473098  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047309a  6689b238345100         -mov word ptr [edx + 0x513438], si
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5321784) /* 0x513438 */) = cpu.si;
    // 004730a1  eba2                   -jmp 0x473045
    goto L_0x00473045;
L_0x004730a3:
    // 004730a3  7658                   -jbe 0x4730fd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004730fd;
    }
    // 004730a5  83fb03                 +cmp ebx, 3
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
    // 004730a8  75c5                   -jne 0x47306f
    if (!cpu.flags.zf)
    {
        goto L_0x0047306f;
    }
    // 004730aa  8b15401e5100           -mov edx, dword ptr [0x511e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 004730b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004730b2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004730b4  7e22                   -jle 0x4730d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004730d8;
    }
    // 004730b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004730b8:
    // 004730b8  8b8a081d5100           -mov ecx, dword ptr [edx + 0x511d08]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315848) /* 0x511d08 */);
    // 004730be  40                     -inc eax
    (cpu.eax)++;
    // 004730bf  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 004730c9  8b0d401e5100           -mov ecx, dword ptr [0x511e40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 004730cf  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004730d2  39c8                   +cmp eax, ecx
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
    // 004730d4  7ce2                   -jl 0x4730b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004730b8;
    }
    // 004730d6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004730d8:
    // 004730d8  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 004730dd  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004730e2  e84908ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 004730e7  e8d4defaff             -call 0x420fc0
    cpu.esp -= 4;
    sub_420fc0(app, cpu);
    if (cpu.terminate) return;
    // 004730ec  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004730f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004730f3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004730f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004730f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004730f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004730f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004730fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004730fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004730fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004730fd:
    // 004730fd  ba15000000             -mov edx, 0x15
    cpu.edx = 21 /*0x15*/;
    // 00473102  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 00473107  e82408ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 0047310c  e8afdefaff             -call 0x420fc0
    cpu.esp -= 4;
    sub_420fc0(app, cpu);
    if (cpu.terminate) return;
    // 00473111  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00473116  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473118  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047311b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047311c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047311d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047311e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047311f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473120  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473121  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473122:
    // 00473122  66a12a345100           -mov ax, word ptr [0x51342a]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5321770) /* 0x51342a */);
    // 00473128  663d1500               +cmp ax, 0x15
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21 /*0x15*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047312c  733d                   -jae 0x47316b
    if (!cpu.flags.cf)
    {
        goto L_0x0047316b;
    }
    // 0047312e  663d1200               +cmp ax, 0x12
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
    // 00473132  0f848d000000           -je 0x4731c5
    if (cpu.flags.zf)
    {
        goto L_0x004731c5;
    }
L_0x00473138:
    // 00473138  83fb01                 +cmp ebx, 1
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
    // 0047313b  0f85c0000000           -jne 0x473201
    if (!cpu.flags.zf)
    {
        goto L_0x00473201;
    }
    // 00473141  b307                   -mov bl, 7
    cpu.bl = 7 /*0x7*/;
    // 00473143  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473147  885c2408               -mov byte ptr [esp + 8], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 0047314b  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
    // 0047314d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047314f  887c2409               -mov byte ptr [esp + 9], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) = cpu.bh;
    // 00473153  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00473158  e8130fffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
L_0x0047315d:
    // 0047315d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047315f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473161  83c410                 +add esp, 0x10
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
    // 00473164  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473165  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473166  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473167  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473168  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473169  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047316a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047316b:
    // 0047316b  7690                   -jbe 0x4730fd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004730fd;
    }
    // 0047316d  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00473171  75c5                   -jne 0x473138
    if (!cpu.flags.zf)
    {
        goto L_0x00473138;
    }
    // 00473173  8b0d401e5100           -mov ecx, dword ptr [0x511e40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00473179  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047317b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047317d  7e21                   -jle 0x4731a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004731a0;
    }
    // 0047317f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00473181:
    // 00473181  8b3d401e5100           -mov edi, dword ptr [0x511e40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00473187  8b8a081d5100           -mov ecx, dword ptr [edx + 0x511d08]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315848) /* 0x511d08 */);
    // 0047318d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473190  40                     -inc eax
    (cpu.eax)++;
    // 00473191  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 0047319b  39f8                   +cmp eax, edi
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
    // 0047319d  7ce2                   -jl 0x473181
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473181;
    }
    // 0047319f  90                     -nop 
    ;
L_0x004731a0:
    // 004731a0  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 004731a5  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004731aa  e88107ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 004731af  e80cdefaff             -call 0x420fc0
    cpu.esp -= 4;
    sub_420fc0(app, cpu);
    if (cpu.terminate) return;
    // 004731b4  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004731b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004731bb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004731be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004731c5:
    // 004731c5  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004731ca  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004731cf  e85c07ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 004731d4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004731d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004731db  891d80964d00           -mov dword ptr [0x4d9680], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.ebx;
    // 004731e1  e8daddfaff             -call 0x420fc0
    cpu.esp -= 4;
    sub_420fc0(app, cpu);
    if (cpu.terminate) return;
    // 004731e6  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004731eb  e84007ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 004731f0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004731f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004731f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004731fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004731ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473201:
    // 00473201  83fb03                 +cmp ebx, 3
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
    // 00473204  0f8553ffffff           -jne 0x47315d
    if (!cpu.flags.zf)
    {
        goto L_0x0047315d;
    }
    // 0047320a  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 0047320c  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 0047320e  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00473213  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00473216  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0047321a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047321c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047321e  e84d0effff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 00473223  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 0047322a  0f852dffffff           -jne 0x47315d
    if (!cpu.flags.zf)
    {
        goto L_0x0047315d;
    }
    // 00473230  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473235  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047323a  66891d5c345100         -mov word ptr [0x51345c], bx
    app->getMemory<x86::reg16>(x86::reg32(5321820) /* 0x51345c */) = cpu.bx;
    // 00473241  66891d5a345100         -mov word ptr [0x51345a], bx
    app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */) = cpu.bx;
    // 00473248  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047324a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047324d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047324e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047324f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473250  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473252  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473253  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473260);
    // 00473260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473261  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473262  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473263  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473264  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473267  8b1508225100           -mov edx, dword ptr [0x512208]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 0047326d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047326f  0f8477000000           -je 0x4732ec
    if (cpu.flags.zf)
    {
        goto L_0x004732ec;
    }
    // 00473275  83fa01                 +cmp edx, 1
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
    // 00473278  0f846e000000           -je 0x4732ec
    if (cpu.flags.zf)
    {
        goto L_0x004732ec;
    }
    // 0047327e  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473285  7f65                   -jg 0x4732ec
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004732ec;
    }
    // 00473287  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473289  7456                   -je 0x4732e1
    if (cpu.flags.zf)
    {
        goto L_0x004732e1;
    }
    // 0047328b  8b35640f5400           -mov esi, dword ptr [0x540f64]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */);
    // 00473291  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00473293  754c                   -jne 0x4732e1
    if (!cpu.flags.zf)
    {
        goto L_0x004732e1;
    }
    // 00473295  833d74964d0000         +cmp dword ptr [0x4d9674], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084788) /* 0x4d9674 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047329c  7543                   -jne 0x4732e1
    if (!cpu.flags.zf)
    {
        goto L_0x004732e1;
    }
    // 0047329e  8b15680f5400           -mov edx, dword ptr [0x540f68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508968) /* 0x540f68 */);
    // 004732a4  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004732a7  e814040000             -call 0x4736c0
    cpu.esp -= 4;
    sub_4736c0(app, cpu);
    if (cpu.terminate) return;
    // 004732ac  39c2                   +cmp edx, eax
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
    // 004732ae  7d31                   -jge 0x4732e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004732e1;
    }
    // 004732b0  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 004732b2  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004732b4  8b2d0c225100           -mov ebp, dword ptr [0x51220c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 004732ba  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004732be  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004732c1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004732c3  742f                   -je 0x4732f4
    if (cpu.flags.zf)
    {
        goto L_0x004732f4;
    }
    // 004732c5  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004732ca  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004732cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004732ce  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004732d2  e8990dffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 004732d7  c70574964d0001000000   -mov dword ptr [0x4d9674], 1
    app->getMemory<x86::reg32>(x86::reg32(5084788) /* 0x4d9674 */) = 1 /*0x1*/;
L_0x004732e1:
    // 004732e1  833d640f540000         +cmp dword ptr [0x540f64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004732e8  753c                   -jne 0x473326
    if (!cpu.flags.zf)
    {
        goto L_0x00473326;
    }
L_0x004732ea:
    // 004732ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004732ec:
    // 004732ec  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004732ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004732f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004732f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004732f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004732f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004732f4:
    // 004732f4  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004732f9  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 004732fe  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00473300  e8436c0100             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00473305  e8c6030000             -call 0x4736d0
    cpu.esp -= 4;
    sub_4736d0(app, cpu);
    if (cpu.terminate) return;
    // 0047330a  a3640f5400             -mov dword ptr [0x540f64], eax
    app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */) = cpu.eax;
    // 0047330f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00473313  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00473315  e8560dffff             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 0047331a  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 0047331f  e83c6c0100             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00473324  ebbb                   -jmp 0x4732e1
    goto L_0x004732e1;
L_0x00473326:
    // 00473326  e895030000             -call 0x4736c0
    cpu.esp -= 4;
    sub_4736c0(app, cpu);
    if (cpu.terminate) return;
    // 0047332b  3b05640f5400           +cmp eax, dword ptr [0x540f64]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473331  75b7                   -jne 0x4732ea
    if (!cpu.flags.zf)
    {
        goto L_0x004732ea;
    }
    // 00473333  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473334  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00473339  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 0047333e  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 00473343  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00473345  89357c964d00           -mov dword ptr [0x4d967c], esi
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.esi;
    // 0047334b  e8e005ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 00473350  a1640f5400             -mov eax, dword ptr [0x540f64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */);
    // 00473355  893d74964d00           -mov dword ptr [0x4d9674], edi
    app->getMemory<x86::reg32>(x86::reg32(5084788) /* 0x4d9674 */) = cpu.edi;
    // 0047335b  893d600f5400           -mov dword ptr [0x540f60], edi
    app->getMemory<x86::reg32>(x86::reg32(5508960) /* 0x540f60 */) = cpu.edi;
    // 00473361  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473363  a3680f5400             -mov dword ptr [0x540f68], eax
    app->getMemory<x86::reg32>(x86::reg32(5508968) /* 0x540f68 */) = cpu.eax;
    // 00473368  893d640f5400           -mov dword ptr [0x540f64], edi
    app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */) = cpu.edi;
    // 0047336e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047336f:
    // 0047336f  e8e83a0100             -call 0x486e5c
    cpu.esp -= 4;
    sub_486e5c(app, cpu);
    if (cpu.terminate) return;
    // 00473374  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473376  7409                   -je 0x473381
    if (cpu.flags.zf)
    {
        goto L_0x00473381;
    }
    // 00473378  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047337a  e8310b0100             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 0047337f  ebee                   -jmp 0x47336f
    goto L_0x0047336f;
L_0x00473381:
    // 00473381  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473386  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473389  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047338a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047338b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047338c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047338d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_473390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473390);
    // 00473390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473391  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00473396  b8003c0000             -mov eax, 0x3c00
    cpu.eax = 15360 /*0x3c00*/;
    // 0047339b  e89005ffff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 004733a0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004733a2  a16c0f5400             -mov eax, dword ptr [0x540f6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */);
    // 004733a7  891570964d00           -mov dword ptr [0x4d9670], edx
    app->getMemory<x86::reg32>(x86::reg32(5084784) /* 0x4d9670 */) = cpu.edx;
    // 004733ad  e8c26b0100             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 004733b2  66833d5a34510000       +cmp word ptr [0x51345a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004733ba  7502                   -jne 0x4733be
    if (!cpu.flags.zf)
    {
        goto L_0x004733be;
    }
    // 004733bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004733be:
    // 004733be  e8f16e0100             -call 0x48a2b4
    cpu.esp -= 4;
    sub_48a2b4(app, cpu);
    if (cpu.terminate) return;
    // 004733c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4733d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004733d0);
    // 004733d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004733d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004733d2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004733d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004733d9  890d680f5400           -mov dword ptr [0x540f68], ecx
    app->getMemory<x86::reg32>(x86::reg32(5508968) /* 0x540f68 */) = cpu.ecx;
    // 004733df  8915640f5400           -mov dword ptr [0x540f64], edx
    app->getMemory<x86::reg32>(x86::reg32(5508964) /* 0x540f64 */) = cpu.edx;
    // 004733e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4733f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004733f0);
    // 004733f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004733f1  e8026b0100             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004733f6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004733fb  a36c0f5400             -mov dword ptr [0x540f6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5508972) /* 0x540f6c */) = cpu.eax;
    // 00473400  891570964d00           -mov dword ptr [0x4d9670], edx
    app->getMemory<x86::reg32>(x86::reg32(5084784) /* 0x4d9670 */) = cpu.edx;
    // 00473406  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473407  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473424(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473424);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00473424  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473425  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473426  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473427  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473428  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473429  8b1508225100           -mov edx, dword ptr [0x512208]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 0047342f  83fa04                 +cmp edx, 4
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
    // 00473432  0f8719010000           -ja 0x473551
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00473551;
    }
    // 00473438  ff249510344700         -jmp dword ptr [edx*4 + 0x473410]
    cpu.ip = app->getMemory<x86::reg32>(4666384 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047343f:
L_0x0047343f:
    // 0047343f  8b2dcc235400           -mov ebp, dword ptr [0x5423cc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */);
    // 00473445  a1a4235400             -mov eax, dword ptr [0x5423a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */);
    // 0047344a  8b15a8235400           -mov edx, dword ptr [0x5423a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 00473450  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00473452  39d0                   +cmp eax, edx
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
    // 00473454  0f8fef000000           -jg 0x473549
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00473549;
    }
L_0x0047345a:
    // 0047345a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047345f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473460  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473461  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473462  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473463  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473464  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473465:
    // 00473465  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 0047346c  755a                   -jne 0x4734c8
    if (!cpu.flags.zf)
    {
        goto L_0x004734c8;
    }
    // 0047346e  833d0c22510000         +cmp dword ptr [0x51220c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473475  7537                   -jne 0x4734ae
    if (!cpu.flags.zf)
    {
        goto L_0x004734ae;
    }
    // 00473477  833d80964d0000         +cmp dword ptr [0x4d9680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047347e  7404                   -je 0x473484
    if (cpu.flags.zf)
    {
        goto L_0x00473484;
    }
    // 00473480  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473482  75d6                   -jne 0x47345a
    if (!cpu.flags.zf)
    {
        goto L_0x0047345a;
    }
L_0x00473484:
    // 00473484  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473486  750f                   -jne 0x473497
    if (!cpu.flags.zf)
    {
        goto L_0x00473497;
    }
    // 00473488  8b1dc8235400           -mov ebx, dword ptr [0x5423c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */);
    // 0047348e  a0d0235400             -mov al, byte ptr [0x5423d0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */);
    // 00473493  39d8                   +cmp eax, ebx
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
    // 00473495  7f1f                   -jg 0x4734b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004734b6;
    }
L_0x00473497:
    // 00473497  8b35cc235400           -mov esi, dword ptr [0x5423cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */);
    // 0047349d  a1a4235400             -mov eax, dword ptr [0x5423a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */);
    // 004734a2  8b3da8235400           -mov edi, dword ptr [0x5423a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 004734a8  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004734aa  39f8                   +cmp eax, edi
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
    // 004734ac  7eac                   -jle 0x47345a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047345a;
    }
L_0x004734ae:
    // 004734ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004734b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004734b6:
    // 004734b6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004734b8  a2d0235400             -mov byte ptr [0x5423d0], al
    app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */) = cpu.al;
    // 004734bd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004734c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004734c8:
    // 004734c8  8b1d0c225100           -mov ebx, dword ptr [0x51220c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 004734ce  39d8                   +cmp eax, ebx
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
    // 004734d0  75dc                   -jne 0x4734ae
    if (!cpu.flags.zf)
    {
        goto L_0x004734ae;
    }
    // 004734d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004734d4  8a15d0235400           -mov dl, byte ptr [0x5423d0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */);
    // 004734da  83fa08                 +cmp edx, 8
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
    // 004734dd  7f4f                   -jg 0x47352e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047352e;
    }
    // 004734df  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004734e6  a1a4235400             -mov eax, dword ptr [0x5423a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */);
    // 004734eb  8b35c8235400           -mov esi, dword ptr [0x5423c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */);
    // 004734f1  8bbaa8235400           -mov edi, dword ptr [edx + 0x5423a8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */);
    // 004734f7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004734f9  39f8                   +cmp eax, edi
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
    // 004734fb  0f8e59ffffff           -jle 0x47345a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047345a;
    }
    // 00473501  a1ac235400             -mov eax, dword ptr [0x5423ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514156) /* 0x5423ac */);
    // 00473506  8b15a8235400           -mov edx, dword ptr [0x5423a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 0047350c  39c2                   +cmp edx, eax
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
    // 0047350e  7e02                   -jle 0x473512
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473512;
    }
    // 00473510  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00473512:
    // 00473512  8b2dcc235400           -mov ebp, dword ptr [0x5423cc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */);
    // 00473518  a1a4235400             -mov eax, dword ptr [0x5423a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */);
    // 0047351d  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047351f  39c2                   +cmp edx, eax
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
    // 00473521  7c8b                   -jl 0x4734ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004734ae;
    }
    // 00473523  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473528  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473529  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047352e:
    // 0047352e  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00473530  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473535  8835d0235400           -mov byte ptr [0x5423d0], dh
    app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */) = cpu.dh;
    // 0047353b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047353c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047353d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047353e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047353f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473540  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473541:
    // 00473541  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473543  0f84f6feffff           -je 0x47343f
    if (cpu.flags.zf)
    {
        goto L_0x0047343f;
    }
L_0x00473549:
    // 00473549  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047354b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047354c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047354d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047354e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047354f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473550  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473551:
    // 00473551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473552  ba1ce14c00             -mov edx, 0x4ce11c
    cpu.edx = 5038364 /*0x4ce11c*/;
    // 00473557  b9ae030000             -mov ecx, 0x3ae
    cpu.ecx = 942 /*0x3ae*/;
    // 0047355c  6840e14c00             -push 0x4ce140
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038400 /*0x4ce140*/;
    cpu.esp -= 4;
    // 00473561  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 00473567  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 0047356d  e87e0b0100             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00473572  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473575  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473577  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473578  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473579  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047357a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047357b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047357c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047357d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_473594(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473594);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00473594  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473595  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473596  8b15cc235400           -mov edx, dword ptr [0x5423cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */);
    // 0047359c  8b0dc8235400           -mov ecx, dword ptr [0x5423c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */);
    // 004735a2  a108225100             -mov eax, dword ptr [0x512208]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 004735a7  83f804                 +cmp eax, 4
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
    // 004735aa  770c                   -ja 0x4735b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004735b8;
    }
    // 004735ac  ff248580354700         -jmp dword ptr [eax*4 + 0x473580]
    cpu.ip = app->getMemory<x86::reg32>(4666752 + cpu.eax * 4); goto dynamic_jump;
  case 0x004735b3:
    // 004735b3  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x004735b8:
    // 004735b8  890dc8235400           -mov dword ptr [0x5423c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */) = cpu.ecx;
    // 004735be  8915cc235400           -mov dword ptr [0x5423cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */) = cpu.edx;
    // 004735c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735c6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004735c7:
    // 004735c7  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 004735ce  7526                   -jne 0x4735f6
    if (!cpu.flags.zf)
    {
        goto L_0x004735f6;
    }
    // 004735d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004735d1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004735d6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004735db  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004735e0  891da00f5400           -mov dword ptr [0x540fa0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5509024) /* 0x540fa0 */) = cpu.ebx;
    // 004735e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735e7  890dc8235400           -mov dword ptr [0x5423c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */) = cpu.ecx;
    // 004735ed  8915cc235400           -mov dword ptr [0x5423cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */) = cpu.edx;
    // 004735f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004735f6:
    // 004735f6  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004735fb  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00473600  8915a00f5400           -mov dword ptr [0x540fa0], edx
    app->getMemory<x86::reg32>(x86::reg32(5509024) /* 0x540fa0 */) = cpu.edx;
    // 00473606  890dc8235400           -mov dword ptr [0x5423c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */) = cpu.ecx;
    // 0047360c  8915cc235400           -mov dword ptr [0x5423cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */) = cpu.edx;
    // 00473612  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473613  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473614  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473615:
    // 00473615  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0047361a  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047361f  890dc8235400           -mov dword ptr [0x5423c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */) = cpu.ecx;
    // 00473625  8915cc235400           -mov dword ptr [0x5423cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */) = cpu.edx;
    // 0047362b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047362c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047362d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047362e:
    // 0047362e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00473633  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00473635  890dc8235400           -mov dword ptr [0x5423c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5514184) /* 0x5423c8 */) = cpu.ecx;
    // 0047363b  8915cc235400           -mov dword ptr [0x5423cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5514188) /* 0x5423cc */) = cpu.edx;
    // 00473641  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473642  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473643  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473650);
    // 00473650  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473651  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473653  8a15d0235400           -mov dl, byte ptr [0x5423d0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */);
    // 00473659  39d0                   +cmp eax, edx
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
    // 0047365b  7e07                   -jle 0x473664
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473664;
    }
    // 0047365d  a2d0235400             -mov byte ptr [0x5423d0], al
    app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */) = cpu.al;
    // 00473662  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473663  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473664:
    // 00473664  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473666  a2d0235400             -mov byte ptr [0x5423d0], al
    app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */) = cpu.al;
    // 0047366b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047366c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_473670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473670);
    // 00473670  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473671  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 00473678  7424                   -je 0x47369e
    if (cpu.flags.zf)
    {
        goto L_0x0047369e;
    }
    // 0047367a  833d0c22510000         +cmp dword ptr [0x51220c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473681  752c                   -jne 0x4736af
    if (!cpu.flags.zf)
    {
        goto L_0x004736af;
    }
    // 00473683  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00473688:
    // 00473688  8b150c225100           -mov edx, dword ptr [0x51220c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 0047368e  8a0485a8235400         -mov al, byte ptr [eax*4 + 0x5423a8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5514152) /* 0x5423a8 */ + cpu.eax * 4);
    // 00473695  2a0495a8235400         -sub al, byte ptr [edx*4 + 0x5423a8]
    (cpu.al) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5514152) /* 0x5423a8 */ + cpu.edx * 4)));
    // 0047369c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047369d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047369e:
    // 0047369e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047369f  8a3da4235400           -mov bh, byte ptr [0x5423a4]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5514148) /* 0x5423a4 */);
    // 004736a5  a0a8235400             -mov al, byte ptr [0x5423a8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5514152) /* 0x5423a8 */);
    // 004736aa  28f8                   -sub al, bh
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.bh));
    // 004736ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004736af:
    // 004736af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004736b1  ebd5                   -jmp 0x473688
    goto L_0x00473688;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4736c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004736c0);
    // 004736c0  a1a4235400             -mov eax, dword ptr [0x5423a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */);
    // 004736c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4736d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004736d0);
    // 004736d0  a1a8235400             -mov eax, dword ptr [0x5423a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 004736d5  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004736d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4736e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004736e0);
    // 004736e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004736e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004736e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004736e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004736e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004736e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004736e6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004736e9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004736eb  a1a8235400             -mov eax, dword ptr [0x5423a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 004736f0  48                     -dec eax
    (cpu.eax)--;
    // 004736f1  8b1564225100           -mov edx, dword ptr [0x512264]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 004736f7  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004736fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004736fc  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00473700  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473702  0f8ecf000000           -jle 0x4737d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004737d7;
    }
    // 00473708  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047370c  4a                     -dec edx
    (cpu.edx)--;
    // 0047370d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473710  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00473713  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473717  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047371b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047371f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473721  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00473723  81c2a40f5400           -add edx, 0x540fa4
    (cpu.edx) += x86::reg32(x86::sreg32(5509028 /*0x540fa4*/));
L_0x00473729:
    // 00473729  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047372d  80b8a41f540000         +cmp byte ptr [eax + 0x541fa4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5513124) /* 0x541fa4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00473734  7556                   -jne 0x47378c
    if (!cpu.flags.zf)
    {
        goto L_0x0047378c;
    }
    // 00473736  ff049da8235400         -inc dword ptr [ebx*4 + 0x5423a8]
    (app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */ + cpu.ebx * 4))++;
    // 0047373d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473741  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00473743  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473747  88a8a41f5400           -mov byte ptr [eax + 0x541fa4], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5513124) /* 0x541fa4 */) = cpu.ch;
    // 0047374d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00473752  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00473754  0f848d000000           -je 0x4737e7
    if (cpu.flags.zf)
    {
        goto L_0x004737e7;
    }
    // 0047375a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x0047375d:
    // 0047375d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00473760  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00473767  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473769  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0047376c  05a40f5400             -add eax, 0x540fa4
    (cpu.eax) += x86::reg32(x86::sreg32(5509028 /*0x540fa4*/));
    // 00473771  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00473773  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473775  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473776  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473778  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047377b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047377d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047377f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00473782  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00473784  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473785  80a5a70f5400bc         -and byte ptr [ebp + 0x540fa7], 0xbc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5509031) /* 0x540fa7 */) &= x86::reg8(x86::sreg8(188 /*0xbc*/));
L_0x0047378c:
    // 0047378c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00473791  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473795  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00473797  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473798  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047379a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047379d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047379f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004737a1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004737a4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004737a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737a7  81c500020000           -add ebp, 0x200
    (cpu.ebp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004737ad  43                     -inc ebx
    (cpu.ebx)++;
    // 004737ae  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004737b2  8d7704                 -lea esi, [edi + 4]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004737b5  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004737bb  8b3d64225100           -mov edi, dword ptr [0x512264]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 004737c1  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004737c7  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004737cb  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004737cf  39fb                   +cmp ebx, edi
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
    // 004737d1  0f8c52ffffff           -jl 0x473729
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473729;
    }
L_0x004737d7:
    // 004737d7  ff0578964d00           -inc dword ptr [0x4d9678]
    (app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */))++;
    // 004737dd  83c410                 +add esp, 0x10
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
    // 004737e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004737e7:
    // 004737e7  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 004737ec  e96cffffff             -jmp 0x47375d
    goto L_0x0047375d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473800);
    // 00473800  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473803  be800f5400             -mov esi, 0x540f80
    cpu.esi = 5508992 /*0x540f80*/;
    // 00473808  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0047380d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473810  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00473812  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473814  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473815  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473817  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047381a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047381c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047381e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00473821  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00473823  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473824  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473825  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473826  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473827  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473830);
    // 00473830  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473831  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473832  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473835  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00473838  8b1514225100           -mov edx, dword ptr [0x512214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
    // 0047383e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00473841  83fa01                 +cmp edx, 1
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
    // 00473844  0f8f88000000           -jg 0x4738d2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004738d2;
    }
    // 0047384a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047384b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047384c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047384d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047384e  8b0d64225100           -mov ecx, dword ptr [0x512264]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 00473854  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00473856  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473858  7e42                   -jle 0x47389c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047389c;
    }
    // 0047385a  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00473861  bb800f5400             -mov ebx, 0x540f80
    cpu.ebx = 5508992 /*0x540f80*/;
    // 00473866  81c2a40f5400           -add edx, 0x540fa4
    (cpu.edx) += x86::reg32(x86::sreg32(5509028 /*0x540fa4*/));
L_0x0047386c:
    // 0047386c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00473871  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00473873  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00473875  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473876  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473878  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047387b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047387d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047387f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00473882  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00473884  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473885  45                     -inc ebp
    (cpu.ebp)++;
    // 00473886  8b3564225100           -mov esi, dword ptr [0x512264]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 0047388c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047388f  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00473895  39f5                   +cmp ebp, esi
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
    // 00473897  7cd3                   -jl 0x47386c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047386c;
    }
    // 00473899  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0047389c:
    // 0047389c  8b3d64225100           -mov edi, dword ptr [0x512264]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
    // 004738a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004738a4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004738a6  7e20                   -jle 0x4738c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004738c8;
    }
    // 004738a8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004738ac  8b2d64225100           -mov ebp, dword ptr [0x512264]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5317220) /* 0x512264 */);
L_0x004738b2:
    // 004738b2  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004738b8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004738ba  43                     -inc ebx
    (cpu.ebx)++;
    // 004738bb  88a2241f5400           -mov byte ptr [edx + 0x541f24], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5512996) /* 0x541f24 */) = cpu.ah;
    // 004738c1  39eb                   +cmp ebx, ebp
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
    // 004738c3  7ced                   -jl 0x4738b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004738b2;
    }
    // 004738c5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004738c8:
    // 004738c8  ff05a4235400           -inc dword ptr [0x5423a4]
    (app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */))++;
    // 004738ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004738d2:
    // 004738d2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004738d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4738e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004738e0);
    // 004738e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004738e1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004738e4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004738e7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004738eb  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004738f2  8baaa8235400           -mov ebp, dword ptr [edx + 0x5423a8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */);
    // 004738f8  e827fbffff             -call 0x473424
    cpu.esp -= 4;
    sub_473424(app, cpu);
    if (cpu.terminate) return;
    // 004738fd  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00473900  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473902  0f85e5000000           -jne 0x4739ed
    if (!cpu.flags.zf)
    {
        goto L_0x004739ed;
    }
    // 00473908  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047390b  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0047390e  8a8428a41f5400         -mov al, byte ptr [eax + ebp + 0x541fa4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5513124) /* 0x541fa4 */ + cpu.ebp * 1);
    // 00473915  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00473917  0f85d0000000           -jne 0x4739ed
    if (!cpu.flags.zf)
    {
        goto L_0x004739ed;
    }
    // 0047391d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047391e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047391f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473921  8b1da00f5400           -mov ebx, dword ptr [0x540fa0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5509024) /* 0x540fa0 */);
    // 00473927  8b0da8235400           -mov ecx, dword ptr [0x5423a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 0047392d  8bb2a8235400           -mov esi, dword ptr [edx + 0x5423a8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */);
    // 00473933  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00473935  39f1                   +cmp ecx, esi
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
    // 00473937  7d68                   -jge 0x4739a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004739a1;
    }
    // 00473939  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047393d  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00473940  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00473942  89baa8235400           -mov dword ptr [edx + 0x5423a8], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */) = cpu.edi;
    // 00473948  c1e309                 -shl ebx, 9
    cpu.ebx <<= 9 /*0x9*/ % 32;
    // 0047394b  8b0da8235400           -mov ecx, dword ptr [0x5423a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 00473951  81c3a40f5400           -add ebx, 0x540fa4
    (cpu.ebx) += x86::reg32(x86::sreg32(5509028 /*0x540fa4*/));
    // 00473957  39f9                   +cmp ecx, edi
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
    // 00473959  7d3d                   -jge 0x473998
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473998;
    }
L_0x0047395b:
    // 0047395b  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047395e  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00473961  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00473963  8d3c8d00000000         -lea edi, [ecx*4]
    cpu.edi = x86::reg32(cpu.ecx * 4);
    // 0047396a  83e67f                 -and esi, 0x7f
    cpu.esi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047396d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00473972  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00473975  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00473977  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00473979  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047397a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047397c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047397f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473981  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00473983  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00473986  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00473988  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473989  8bb5a8235400           -mov esi, dword ptr [ebp + 0x5423a8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5514152) /* 0x5423a8 */);
    // 0047398f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00473991  39f2                   +cmp edx, esi
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
    // 00473993  7cc6                   -jl 0x47395b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047395b;
    }
    // 00473995  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00473998:
    // 00473998  8bada8235400           -mov ebp, dword ptr [ebp + 0x5423a8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5514152) /* 0x5423a8 */);
    // 0047399e  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x004739a1:
    // 004739a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004739a5  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004739aa  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 004739ad  8d3cad00000000         -lea edi, [ebp*4]
    cpu.edi = x86::reg32(cpu.ebp * 4);
    // 004739b4  05a40f5400             -add eax, 0x540fa4
    (cpu.eax) += x86::reg32(x86::sreg32(5509028 /*0x540fa4*/));
    // 004739b9  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004739bd  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004739bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004739c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004739c2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004739c5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004739c7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004739c9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004739cc  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004739ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004739cf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004739d3  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004739d6  c68428a41f540001       -mov byte ptr [eax + ebp + 0x541fa4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5513124) /* 0x541fa4 */ + cpu.ebp * 1) = 1 /*0x1*/;
    // 004739de  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004739e2  ff0485a8235400         -inc dword ptr [eax*4 + 0x5423a8]
    (app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */ + cpu.eax * 4))++;
    // 004739e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004739ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004739eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004739ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004739ed:
    // 004739ed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004739f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004739f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473a14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473a14);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00473a14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473a15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473a16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473a17  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473a18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473a19  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00473a1b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00473a1d  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00473a24  8bbaa8235400           -mov edi, dword ptr [edx + 0x5423a8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */);
    // 00473a2a  668b0d5a345100         -mov cx, word ptr [0x51345a]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */);
    // 00473a31  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00473a34  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00473a37  7414                   -je 0x473a4d
    if (cpu.flags.zf)
    {
        goto L_0x00473a4d;
    }
    // 00473a39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473a3e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473a40  a37c964d00             -mov dword ptr [0x4d967c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.eax;
    // 00473a45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473a47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473a4d:
    // 00473a4d  e8d2f9ffff             -call 0x473424
    cpu.esp -= 4;
    sub_473424(app, cpu);
    if (cpu.terminate) return;
    // 00473a52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473a54  752c                   -jne 0x473a82
    if (!cpu.flags.zf)
    {
        goto L_0x00473a82;
    }
    // 00473a56  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00473a58  c1e507                 -shl ebp, 7
    cpu.ebp <<= 7 /*0x7*/ % 32;
    // 00473a5b  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00473a5d  80bda41f540000         +cmp byte ptr [ebp + 0x541fa4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5513124) /* 0x541fa4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00473a64  7426                   -je 0x473a8c
    if (cpu.flags.zf)
    {
        goto L_0x00473a8c;
    }
    // 00473a66  833d0822510001         +cmp dword ptr [0x512208], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473a6d  7e13                   -jle 0x473a82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473a82;
    }
    // 00473a6f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00473a74  6689355c345100         -mov word ptr [0x51345c], si
    app->getMemory<x86::reg16>(x86::reg32(5321820) /* 0x51345c */) = cpu.si;
    // 00473a7b  6689355a345100         -mov word ptr [0x51345a], si
    app->getMemory<x86::reg16>(x86::reg32(5321818) /* 0x51345a */) = cpu.si;
L_0x00473a82:
    // 00473a82  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473a84  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473a86  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473a8c:
    // 00473a8c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473a8e  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 00473a91  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00473a94  05a40f5400             -add eax, 0x540fa4
    (cpu.eax) += x86::reg32(x86::sreg32(5509028 /*0x540fa4*/));
    // 00473a99  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00473a9e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473aa0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473aa1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473aa3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00473aa6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473aa8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00473aaa  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00473aad  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00473aaf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ab0  c685a41f540001         -mov byte ptr [ebp + 0x541fa4], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5513124) /* 0x541fa4 */) = 1 /*0x1*/;
    // 00473ab7  8b8aa8235400           -mov ecx, dword ptr [edx + 0x5423a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */);
    // 00473abd  41                     -inc ecx
    (cpu.ecx)++;
    // 00473abe  a108225100             -mov eax, dword ptr [0x512208]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 00473ac3  898aa8235400           -mov dword ptr [edx + 0x5423a8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514152) /* 0x5423a8 */) = cpu.ecx;
    // 00473ac9  83f804                 +cmp eax, 4
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
    // 00473acc  770d                   -ja 0x473adb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00473adb;
    }
    // 00473ace  ff2485003a4700         -jmp dword ptr [eax*4 + 0x473a00]
    cpu.ip = app->getMemory<x86::reg32>(4667904 + cpu.eax * 4); goto dynamic_jump;
  case 0x00473ad5:
    // 00473ad5  ff0578964d00           -inc dword ptr [0x4d9678]
    (app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */))++;
L_0x00473adb:
    // 00473adb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473ae0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473ae2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ae3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ae4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ae5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ae6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ae7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473ae8:
    // 00473ae8  803d5f34510001         +cmp byte ptr [0x51345f], 1
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
    // 00473aef  7520                   -jne 0x473b11
    if (!cpu.flags.zf)
    {
        goto L_0x00473b11;
    }
    // 00473af1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00473af3  75e6                   -jne 0x473adb
    if (!cpu.flags.zf)
    {
        goto L_0x00473adb;
    }
    // 00473af5  833d0c22510000         +cmp dword ptr [0x51220c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473afc  74dd                   -je 0x473adb
    if (cpu.flags.zf)
    {
        goto L_0x00473adb;
    }
    // 00473afe  ff0578964d00           -inc dword ptr [0x4d9678]
    (app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */))++;
    // 00473b04  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473b09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473b0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473b11:
    // 00473b11  8b15ac235400           -mov edx, dword ptr [0x5423ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514156) /* 0x5423ac */);
    // 00473b17  a1a8235400             -mov eax, dword ptr [0x5423a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5514152) /* 0x5423a8 */);
    // 00473b1c  39d0                   +cmp eax, edx
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
    // 00473b1e  7d02                   -jge 0x473b22
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473b22;
    }
    // 00473b20  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00473b22:
    // 00473b22  4a                     -dec edx
    (cpu.edx)--;
    // 00473b23  891578964d00           -mov dword ptr [0x4d9678], edx
    app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */) = cpu.edx;
    // 00473b29  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473b2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473b30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b35  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473b36:
    // 00473b36  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00473b38  74a1                   -je 0x473adb
    if (cpu.flags.zf)
    {
        goto L_0x00473adb;
    }
    // 00473b3a  ff0578964d00           -inc dword ptr [0x4d9678]
    (app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */))++;
    // 00473b40  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473b45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473b47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b4c  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_473b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473b50);
    // 00473b50  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473b57  7e01                   -jle 0x473b5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473b5a;
    }
    // 00473b59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473b5a:
    // 00473b5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473b5b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00473b60  890d7c964d00           -mov dword ptr [0x4d967c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ecx;
    // 00473b66  890d80964d00           -mov dword ptr [0x4d9680], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.ecx;
    // 00473b6c  e81ff8ffff             -call 0x473390
    cpu.esp -= 4;
    sub_473390(app, cpu);
    if (cpu.terminate) return;
    // 00473b71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473b80);
    // 00473b80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473b81  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473b84  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473b8b  0f8f7b000000           -jg 0x473c0c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00473c0c;
    }
    // 00473b91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473b92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473b93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473b94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473b95  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473b96  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00473b9b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00473b9d  890d80964d00           -mov dword ptr [0x4d9680], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.ecx;
    // 00473ba3  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00473ba7  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00473bab  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00473baf  890d7c964d00           -mov dword ptr [0x4d967c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ecx;
    // 00473bb5  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
L_0x00473bb7:
    // 00473bb7  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00473bbb  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00473bbf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473bc1  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00473bc3  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x00473bc5:
    // 00473bc5  8d043a                 -lea eax, [edx + edi]
    cpu.eax = x86::reg32(cpu.edx + cpu.edi * 1);
    // 00473bc8  88b8a41f5400           -mov byte ptr [eax + 0x541fa4], bh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5513124) /* 0x541fa4 */) = cpu.bh;
    // 00473bce  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00473bd5  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00473bd7  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x00473bda:
    // 00473bda  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473bdd  8898a10f5400           -mov byte ptr [eax + 0x540fa1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5509025) /* 0x540fa1 */) = cpu.bl;
    // 00473be3  8898a20f5400           -mov byte ptr [eax + 0x540fa2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5509026) /* 0x540fa2 */) = cpu.bl;
    // 00473be9  41                     -inc ecx
    (cpu.ecx)++;
    // 00473bea  8898a30f5400           -mov byte ptr [eax + 0x540fa3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5509027) /* 0x540fa3 */) = cpu.bl;
    // 00473bf0  42                     -inc edx
    (cpu.edx)++;
    // 00473bf1  8898a00f5400           -mov byte ptr [eax + 0x540fa0], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5509024) /* 0x540fa0 */) = cpu.bl;
    // 00473bf7  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473bfd  7d19                   -jge 0x473c18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473c18;
    }
    // 00473bff  83fa04                 +cmp edx, 4
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
    // 00473c02  7cc1                   -jl 0x473bc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473bc5;
    }
    // 00473c04  8899a41f5400           -mov byte ptr [ecx + 0x541fa4], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5513124) /* 0x541fa4 */) = cpu.bl;
    // 00473c0a  ebce                   -jmp 0x473bda
    goto L_0x00473bda;
L_0x00473c0c:
    // 00473c0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473c0e  a378964d00             -mov dword ptr [0x4d9678], eax
    app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */) = cpu.eax;
    // 00473c13  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473c16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473c18:
    // 00473c18  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00473c1c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00473c20  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473c24  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00473c29  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00473c2f  81c600020000           -add esi, 0x200
    (cpu.esi) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00473c35  8d3c10                 -lea edi, [eax + edx]
    cpu.edi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00473c38  8990a8235400           -mov dword ptr [eax + 0x5423a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5514152) /* 0x5423a8 */) = cpu.edx;
    // 00473c3e  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00473c42  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00473c46  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00473c4a  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473c4d  0f8564ffffff           -jne 0x473bb7
    if (!cpu.flags.zf)
    {
        goto L_0x00473bb7;
    }
    // 00473c53  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00473c58  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473c5a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473c5c  a3a4235400             -mov dword ptr [0x5423a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5514148) /* 0x5423a4 */) = cpu.eax;
    // 00473c61  891578964d00           -mov dword ptr [0x4d9678], edx
    app->getMemory<x86::reg32>(x86::reg32(5084792) /* 0x4d9678 */) = cpu.edx;
    // 00473c67  e864f7ffff             -call 0x4733d0
    cpu.esp -= 4;
    sub_4733d0(app, cpu);
    if (cpu.terminate) return;
    // 00473c6c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00473c6e  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00473c73  8825d0235400           -mov byte ptr [0x5423d0], ah
    app->getMemory<x86::reg8>(x86::reg32(5514192) /* 0x5423d0 */) = cpu.ah;
    // 00473c79  b8001e0000             -mov eax, 0x1e00
    cpu.eax = 7680 /*0x1e00*/;
    // 00473c7e  890d80964d00           -mov dword ptr [0x4d9680], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.ecx;
    // 00473c84  e8a7fcfeff             -call 0x463930
    cpu.esp -= 4;
    sub_463930(app, cpu);
    if (cpu.terminate) return;
    // 00473c89  890d7c964d00           -mov dword ptr [0x4d967c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ecx;
    // 00473c8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c94  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473c97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473ca0);
    // 00473ca0  833d1422510001         +cmp dword ptr [0x512214], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473ca7  7e01                   -jle 0x473caa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473caa;
    }
    // 00473ca9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473caa:
    // 00473caa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473cab  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00473cb0  890d7c964d00           -mov dword ptr [0x4d967c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084796) /* 0x4d967c */) = cpu.ecx;
    // 00473cb6  890d80964d00           -mov dword ptr [0x4d9680], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084800) /* 0x4d9680 */) = cpu.ecx;
    // 00473cbc  e82ff7ffff             -call 0x4733f0
    cpu.esp -= 4;
    sub_4733f0(app, cpu);
    if (cpu.terminate) return;
    // 00473cc1  e8cef8ffff             -call 0x473594
    cpu.esp -= 4;
    sub_473594(app, cpu);
    if (cpu.terminate) return;
    // 00473cc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473cc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473cd0);
    // 00473cd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473ce0);
    // 00473ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473ce2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473ce3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473ce4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473ce5  b824e24c00             -mov eax, 0x4ce224
    cpu.eax = 5038628 /*0x4ce224*/;
    // 00473cea  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473cef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473cf1  e82a010000             -call 0x473e20
    cpu.esp -= 4;
    sub_473e20(app, cpu);
    if (cpu.terminate) return;
    // 00473cf6  e885220000             -call 0x475f80
    cpu.esp -= 4;
    sub_475f80(app, cpu);
    if (cpu.terminate) return;
    // 00473cfb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473cfd  e8fe210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d02  8b0df0265100           -mov ecx, dword ptr [0x5126f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5318384) /* 0x5126f0 */);
    // 00473d08  39c8                   +cmp eax, ecx
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
    // 00473d0a  7e02                   -jle 0x473d0e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473d0e;
    }
    // 00473d0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00473d0e:
    // 00473d0e  a3f0265100             -mov dword ptr [0x5126f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5318384) /* 0x5126f0 */) = cpu.eax;
    // 00473d13  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473d15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473d17  7e77                   -jle 0x473d90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473d90;
    }
    // 00473d19  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00473d1e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00473d20:
    // 00473d20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d22  e8d9210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d27  8981f0235400           -mov dword ptr [ecx + 0x5423f0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514224) /* 0x5423f0 */) = cpu.eax;
    // 00473d2d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00473d2f  89b1f4235400           -mov dword ptr [ecx + 0x5423f4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514228) /* 0x5423f4 */) = cpu.esi;
    // 00473d35  89b9f8235400           -mov dword ptr [ecx + 0x5423f8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514232) /* 0x5423f8 */) = cpu.edi;
    // 00473d3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d3d  89b9fc235400           -mov dword ptr [ecx + 0x5423fc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514236) /* 0x5423fc */) = cpu.edi;
    // 00473d43  e8b8210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d48  898130245400           -mov dword ptr [ecx + 0x542430], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514288) /* 0x542430 */) = cpu.eax;
    // 00473d4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d50  e8ab210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d55  898134245400           -mov dword ptr [ecx + 0x542434], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514292) /* 0x542434 */) = cpu.eax;
    // 00473d5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d5d  e89e210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d62  898138245400           -mov dword ptr [ecx + 0x542438], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514296) /* 0x542438 */) = cpu.eax;
    // 00473d68  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d6a  e891210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d6f  89813c245400           -mov dword ptr [ecx + 0x54243c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514300) /* 0x54243c */) = cpu.eax;
    // 00473d75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d77  43                     -inc ebx
    (cpu.ebx)++;
    // 00473d78  e883210000             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 00473d7d  898140245400           -mov dword ptr [ecx + 0x542440], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5514304) /* 0x542440 */) = cpu.eax;
    // 00473d83  a1f0265100             -mov eax, dword ptr [0x5126f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5318384) /* 0x5126f0 */);
    // 00473d88  83c154                 -add ecx, 0x54
    (cpu.ecx) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00473d8b  39c3                   +cmp ebx, eax
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
    // 00473d8d  7c91                   -jl 0x473d20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473d20;
    }
    // 00473d8f  90                     -nop 
    ;
L_0x00473d90:
    // 00473d90  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d92  e8b9210000             -call 0x475f50
    cpu.esp -= 4;
    sub_475f50(app, cpu);
    if (cpu.terminate) return;
    // 00473d97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_473da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473da0);
    // 00473da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473da1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473da2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473da4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00473da6  8b1560225100           -mov edx, dword ptr [0x512260]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317216) /* 0x512260 */);
    // 00473dac  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00473daf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473db1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473db3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473db6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473db8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473dbb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473dbd  8b148530245400         -mov edx, dword ptr [eax*4 + 0x542430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514288) /* 0x542430 */ + cpu.eax * 4);
    // 00473dc4  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00473dc7  8b148534245400         -mov edx, dword ptr [eax*4 + 0x542434]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514292) /* 0x542434 */ + cpu.eax * 4);
    // 00473dce  89919c000000           -mov dword ptr [ecx + 0x9c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.edx;
    // 00473dd4  8b148538245400         -mov edx, dword ptr [eax*4 + 0x542438]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514296) /* 0x542438 */ + cpu.eax * 4);
    // 00473ddb  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 00473de1  8b14853c245400         -mov edx, dword ptr [eax*4 + 0x54243c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514300) /* 0x54243c */ + cpu.eax * 4);
    // 00473de8  c6818c00000001         -mov byte ptr [ecx + 0x8c], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 1 /*0x1*/;
    // 00473def  8991a4000000           -mov dword ptr [ecx + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 00473df5  8b148540245400         -mov edx, dword ptr [eax*4 + 0x542440]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5514304) /* 0x542440 */ + cpu.eax * 4);
    // 00473dfc  8d81c4000000           -lea eax, [ecx + 0xc4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00473e02  e879a90200             -call 0x49e780
    cpu.esp -= 4;
    sub_49e780(app, cpu);
    if (cpu.terminate) return;
    // 00473e07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473e09  e8a2eafeff             -call 0x4628b0
    cpu.esp -= 4;
    sub_4628b0(app, cpu);
    if (cpu.terminate) return;
    // 00473e0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473e20);
    // 00473e20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473e21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473e23  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 00473e29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e2a  8b0d88345100           -mov ecx, dword ptr [0x513488]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5321864) /* 0x513488 */);
    // 00473e30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473e31  6818e24c00             -push 0x4ce218
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038616 /*0x4ce218*/;
    cpu.esp -= 4;
    // 00473e36  6894255400             -push 0x542594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5514644 /*0x542594*/;
    cpu.esp -= 4;
    // 00473e3b  e8c1260100             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00473e40  b894255400             -mov eax, 0x542594
    cpu.eax = 5514644 /*0x542594*/;
    // 00473e45  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00473e48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473e50);
    // 00473e50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473e60);
    // 00473e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473e64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473e66  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00473e6d  756c                   -jne 0x473edb
    if (!cpu.flags.zf)
    {
        goto L_0x00473edb;
    }
    // 00473e6f  6683b94c01000000       +cmp word ptr [ecx + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00473e77  7667                   -jbe 0x473ee0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00473ee0;
    }
    // 00473e79  81b95c01000000800000   +cmp dword ptr [ecx + 0x15c], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473e83  0f8c0e010000           -jl 0x473f97
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473f97;
    }
L_0x00473e89:
    // 00473e89  8b1504225100           -mov edx, dword ptr [0x512204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
    // 00473e8f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00473e96  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473e98  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473e9b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473e9d  8b9160010000           -mov edx, dword ptr [ecx + 0x160]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */);
    // 00473ea3  3b1485481d5100         +cmp edx, dword ptr [eax*4 + 0x511d48]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5315912) /* 0x511d48 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473eaa  0f8fbe010000           -jg 0x47406e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047406e;
    }
    // 00473eb0  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473eb7  7e15                   -jle 0x473ece
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473ece;
    }
L_0x00473eb9:
    // 00473eb9  8ba978050000           -mov ebp, dword ptr [ecx + 0x578]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
    // 00473ebf  4d                     -dec ebp
    (cpu.ebp)--;
    // 00473ec0  89a978050000           -mov dword ptr [ecx + 0x578], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = cpu.ebp;
    // 00473ec6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00473ec8  0f8eb6010000           -jle 0x474084
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474084;
    }
L_0x00473ece:
    // 00473ece  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473ed5  0f8eba010000           -jle 0x474095
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474095;
    }
L_0x00473edb:
    // 00473edb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473edc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473edd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ede  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473edf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473ee0:
    // 00473ee0  8b99a8000000           -mov ebx, dword ptr [ecx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00473ee6  69d3e6000000           -imul edx, ebx, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00473eec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473eee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473ef1  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473ef4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473ef6  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473ef9  6991ac000000e6000000   -imul edx, dword ptr [ecx + 0xac], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00473f03  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 00473f09  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473f0b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473f0e  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473f11  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473f13  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473f16  6991b0000000e6000000   -imul edx, dword ptr [ecx + 0xb0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00473f20  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 00473f26  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473f28  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473f2b  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473f2e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473f30  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473f33  6991e8000000e6000000   -imul edx, dword ptr [ecx + 0xe8], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00473f3d  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 00473f43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473f45  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473f48  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473f4b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473f4d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473f50  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00473f56  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 00473f5c  69d0e6000000           -imul edx, eax, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00473f62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473f64  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473f67  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473f6a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473f6c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473f6f  6991f0000000e6000000   -imul edx, dword ptr [ecx + 0xf0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00473f79  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 00473f7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473f81  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473f84  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473f87  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473f89  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00473f8c  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00473f92  e9f2feffff             -jmp 0x473e89
    goto L_0x00473e89;
L_0x00473f97:
    // 00473f97  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00473f9d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473fa0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473fa2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00473fa5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473fa7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473fa9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473fac  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473faf  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473fb1  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473fb4  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 00473fba  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00473fc0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473fc3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473fc5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00473fc8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473fca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473fcc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473fcf  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473fd2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473fd4  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473fd7  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 00473fdd  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00473fe3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473fe6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473fe8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00473feb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473fed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473fef  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473ff2  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473ff5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473ff7  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00473ffa  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 00474000  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 00474006  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00474009  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047400b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047400e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474010  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474012  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474015  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00474018  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047401a  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0047401d  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00474023  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 00474029  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047402c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047402e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00474031  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474033  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474035  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474038  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047403b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047403d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00474040  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 00474046  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0047404c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047404f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474051  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00474054  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474056  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474058  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047405b  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047405e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474060  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00474063  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00474069  e91bfeffff             -jmp 0x473e89
    goto L_0x00473e89;
L_0x0047406e:
    // 0047406e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474070  e82b00feff             -call 0x4540a0
    cpu.esp -= 4;
    sub_4540a0(app, cpu);
    if (cpu.terminate) return;
    // 00474075  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 0047407f  e935feffff             -jmp 0x473eb9
    goto L_0x00473eb9;
L_0x00474084:
    // 00474084  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474086  e835010000             -call 0x4741c0
    cpu.esp -= 4;
    sub_4741c0(app, cpu);
    if (cpu.terminate) return;
    // 0047408b  c7817805000000000000   -mov dword ptr [ecx + 0x578], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 0 /*0x0*/;
L_0x00474095:
    // 00474095  8b9984010000           -mov ebx, dword ptr [ecx + 0x184]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(388) /* 0x184 */);
    // 0047409b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047409d  7412                   -je 0x4740b1
    if (cpu.flags.zf)
    {
        goto L_0x004740b1;
    }
    // 0047409f  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004740a2  740d                   -je 0x4740b1
    if (cpu.flags.zf)
    {
        goto L_0x004740b1;
    }
    // 004740a4  83b97c01000000         +cmp dword ptr [ecx + 0x17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(380) /* 0x17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004740ab  0f842afeffff           -je 0x473edb
    if (cpu.flags.zf)
    {
        goto L_0x00473edb;
    }
L_0x004740b1:
    // 004740b1  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 004740bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4740c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004740c0);
    // 004740c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004740c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004740c3  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004740ca  7402                   -je 0x4740ce
    if (cpu.flags.zf)
    {
        goto L_0x004740ce;
    }
    // 004740cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004740ce:
    // 004740ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004740cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004740d0  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 004740d6  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 004740dc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004740de  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004740e1  c1e810                 +shr eax, 0x10
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
    // 004740e4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004740e6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004740e8  8b91c8000000           -mov edx, dword ptr [ecx + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 004740ee  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004740f4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004740f6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004740f9  c1e810                 +shr eax, 0x10
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
    // 004740fc  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004740fe  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 00474104  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474106  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0047410c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047410e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474111  c1e810                 +shr eax, 0x10
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
    // 00474114  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474116  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0047411c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047411e  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00474124  8999b0020000           -mov dword ptr [ecx + 0x2b0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(688) /* 0x2b0 */) = cpu.ebx;
    // 0047412a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047412c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047412f  c1e810                 +shr eax, 0x10
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
    // 00474132  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474134  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00474136  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0047413c  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00474142  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474144  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474147  c1e810                 +shr eax, 0x10
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
    // 0047414a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047414c  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00474152  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474154  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0047415a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047415c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047415f  c1e810                 +shr eax, 0x10
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
    // 00474162  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474164  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0047416a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047416c  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00474172  8999b4020000           -mov dword ptr [ecx + 0x2b4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */) = cpu.ebx;
    // 00474178  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047417a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047417d  c1e810                 +shr eax, 0x10
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
    // 00474180  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474182  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00474184  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0047418a  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00474190  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474192  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474195  c1e810                 +shr eax, 0x10
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
    // 00474198  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047419a  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 004741a0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004741a2  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 004741a8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004741aa  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004741ad  c1e810                 +shr eax, 0x10
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
    // 004741b0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004741b2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004741b4  8999b8020000           -mov dword ptr [ecx + 0x2b8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.ebx;
    // 004741ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4741c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004741c0);
    // 004741c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004741c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004741c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004741c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004741c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004741c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004741c7  c780a800000000000000   -mov dword ptr [eax + 0xa8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 0 /*0x0*/;
    // 004741d1  c780ac00000000000000   -mov dword ptr [eax + 0xac], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 004741db  c780b000000000000000   -mov dword ptr [eax + 0xb0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = 0 /*0x0*/;
    // 004741e5  8db83c010000           -lea edi, [eax + 0x13c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(316) /* 0x13c */);
    // 004741eb  c780e800000000000000   -mov dword ptr [eax + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 004741f5  8db024010000           -lea esi, [eax + 0x124]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 004741fb  c780ec00000000000000   -mov dword ptr [eax + 0xec], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 00474205  059c000000             -add eax, 0x9c
    (cpu.eax) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 0047420a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047420c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047420e  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00474215  e8d6ecfeff             -call 0x462ef0
    cpu.esp -= 4;
    sub_462ef0(app, cpu);
    if (cpu.terminate) return;
    // 0047421a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047421c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047421e  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00474224  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474226  e845eafeff             -call 0x462c70
    cpu.esp -= 4;
    sub_462c70(app, cpu);
    if (cpu.terminate) return;
    // 0047422b  89815c010000           -mov dword ptr [ecx + 0x15c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = cpu.eax;
    // 00474231  8b91a0000000           -mov edx, dword ptr [ecx + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00474237  c7815c01000000000000   -mov dword ptr [ecx + 0x15c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 00474241  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474243  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 00474249  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047424a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047424b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047424c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047424d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047424e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_474250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474250);
    // 00474250  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474260);
    // 00474260  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474261  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474266  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474268  a3fc505400             -mov dword ptr [0x5450fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5525756) /* 0x5450fc */) = cpu.eax;
    // 0047426d  8915f4505400           -mov dword ptr [0x5450f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5525748) /* 0x5450f4 */) = cpu.edx;
    // 00474273  8915f8505400           -mov dword ptr [0x5450f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */) = cpu.edx;
    // 00474279  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047427a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474280);
    // 00474280  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474281  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474286  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474288  a3fc505400             -mov dword ptr [0x5450fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5525756) /* 0x5450fc */) = cpu.eax;
    // 0047428d  8915f4505400           -mov dword ptr [0x5450f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5525748) /* 0x5450f4 */) = cpu.edx;
    // 00474293  8915f8505400           -mov dword ptr [0x5450f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */) = cpu.edx;
    // 00474299  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047429a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4742a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004742a0);
    // 004742a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004742a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004742a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004742a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004742a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004742a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004742a6  81ece0030000           -sub esp, 0x3e0
    (cpu.esp) -= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004742ac  898424d4030000         -mov dword ptr [esp + 0x3d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */) = cpu.eax;
    // 004742b3  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004742b8  a1f8505400             -mov eax, dword ptr [0x5450f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 004742bd  e83e8afbff             -call 0x42cd00
    cpu.esp -= 4;
    sub_42cd00(app, cpu);
    if (cpu.terminate) return;
    // 004742c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004742c4  8b1df8505400           -mov ebx, dword ptr [0x5450f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 004742ca  899424d8030000         -mov dword ptr [esp + 0x3d8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(984) /* 0x3d8 */) = cpu.edx;
    // 004742d1  899424d0030000         -mov dword ptr [esp + 0x3d0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */) = cpu.edx;
    // 004742d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004742da  7e5e                   -jle 0x47433a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047433a;
    }
    // 004742dc  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 004742e3  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004742e6  898424c0030000         -mov dword ptr [esp + 0x3c0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(960) /* 0x3c0 */) = cpu.eax;
    // 004742ed  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 004742f4  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004742f7  898424c8030000         -mov dword ptr [esp + 0x3c8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(968) /* 0x3c8 */) = cpu.eax;
    // 004742fe  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 00474305  bfd4255400             -mov edi, 0x5425d4
    cpu.edi = 5514708 /*0x5425d4*/;
    // 0047430a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047430d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047430f  898424cc030000         -mov dword ptr [esp + 0x3cc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(972) /* 0x3cc */) = cpu.eax;
L_0x00474316:
    // 00474316  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 00474318  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047431a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047431c  754c                   -jne 0x47436a
    if (!cpu.flags.zf)
    {
        goto L_0x0047436a;
    }
L_0x0047431e:
    // 0047431e  8bb424d8030000         -mov esi, dword ptr [esp + 0x3d8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(984) /* 0x3d8 */);
    // 00474325  8b15f8505400           -mov edx, dword ptr [0x5450f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 0047432b  46                     -inc esi
    (cpu.esi)++;
    // 0047432c  83c75c                 -add edi, 0x5c
    (cpu.edi) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0047432f  89b424d8030000         -mov dword ptr [esp + 0x3d8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(984) /* 0x3d8 */) = cpu.esi;
    // 00474336  39d6                   +cmp esi, edx
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
    // 00474338  7cdc                   -jl 0x474316
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474316;
    }
L_0x0047433a:
    // 0047433a  8b8c24d0030000         -mov ecx, dword ptr [esp + 0x3d0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */);
    // 00474341  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474343  7418                   -je 0x47435d
    if (cpu.flags.zf)
    {
        goto L_0x0047435d;
    }
    // 00474345  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474347  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00474349  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047434c  83f901                 +cmp ecx, 1
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
    // 0047434f  0f8f97000000           -jg 0x4743ec
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004743ec;
    }
L_0x00474355:
    // 00474355  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00474357  0f8529010000           -jne 0x474486
    if (!cpu.flags.zf)
    {
        goto L_0x00474486;
    }
L_0x0047435d:
    // 0047435d  81c4e0030000           -add esp, 0x3e0
    (cpu.esp) += x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00474363  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474364  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474365  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474366  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474367  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474368  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474369  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047436a:
    // 0047436a  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 0047436f  8d4f10                 -lea ecx, [edi + 0x10]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00474372  8b9424cc030000         -mov edx, dword ptr [esp + 0x3cc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(972) /* 0x3cc */);
    // 00474379  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047437b  e8f0caffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00474380  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474382  749a                   -je 0x47431e
    if (cpu.flags.zf)
    {
        goto L_0x0047431e;
    }
    // 00474384  8d4728                 -lea eax, [edi + 0x28]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00474387  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047438c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047438d  8b9424c4030000         -mov edx, dword ptr [esp + 0x3c4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(964) /* 0x3c4 */);
    // 00474394  8b8424cc030000         -mov eax, dword ptr [esp + 0x3cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(972) /* 0x3cc */);
    // 0047439b  e8a0c10000             -call 0x480540
    cpu.esp -= 4;
    sub_480540(app, cpu);
    if (cpu.terminate) return;
    // 004743a0  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 004743a2  80fa04                 +cmp dl, 4
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
    // 004743a5  7429                   -je 0x4743d0
    if (cpu.flags.zf)
    {
        goto L_0x004743d0;
    }
    // 004743a7  80fa05                 +cmp dl, 5
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004743aa  7424                   -je 0x4743d0
    if (cpu.flags.zf)
    {
        goto L_0x004743d0;
    }
    // 004743ac  817f3000000100         +cmp dword ptr [edi + 0x30], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004743b3  7c2e                   -jl 0x4743e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004743e3;
    }
L_0x004743b5:
    // 004743b5  8b9424d0030000         -mov edx, dword ptr [esp + 0x3d0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */);
    // 004743bc  83c508                 +add ebp, 8
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004743bf  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004743c0  89742cfc               -mov dword ptr [esp + ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ebp * 1) = cpu.esi;
    // 004743c4  899424d0030000         -mov dword ptr [esp + 0x3d0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */) = cpu.edx;
    // 004743cb  e94effffff             -jmp 0x47431e
    goto L_0x0047431e;
L_0x004743d0:
    // 004743d0  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 004743d7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004743d9  e836f8fbff             -call 0x433c14
    cpu.esp -= 4;
    sub_433c14(app, cpu);
    if (cpu.terminate) return;
    // 004743de  e93bffffff             -jmp 0x47431e
    goto L_0x0047431e;
L_0x004743e3:
    // 004743e3  c7473000000100         -mov dword ptr [edi + 0x30], 0x10000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = 65536 /*0x10000*/;
    // 004743ea  ebc9                   -jmp 0x4743b5
    goto L_0x004743b5;
L_0x004743ec:
    // 004743ec  8d4708                 -lea eax, [edi + 8]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004743ef  898424dc030000         -mov dword ptr [esp + 0x3dc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */) = cpu.eax;
    // 004743f6  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004743fd  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 00474402  898424c4030000         -mov dword ptr [esp + 0x3c4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(964) /* 0x3c4 */) = cpu.eax;
L_0x00474409:
    // 00474409  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047440c  8b542c04               -mov edx, dword ptr [esp + ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00474410  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00474413  3b4230                 +cmp eax, dword ptr [edx + 0x30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474416  7e2f                   -jle 0x474447
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474447;
    }
    // 00474418  893c2c                 -mov dword ptr [esp + ebp], edi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebp * 1) = cpu.edi;
    // 0047441b  8bbc24dc030000         -mov edi, dword ptr [esp + 0x3dc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */);
L_0x00474422:
    // 00474422  8b8c24dc030000         -mov ecx, dword ptr [esp + 0x3dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */);
    // 00474429  8b9c24c4030000         -mov ebx, dword ptr [esp + 0x3c4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(964) /* 0x3c4 */);
    // 00474430  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00474433  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00474436  898c24dc030000         -mov dword ptr [esp + 0x3dc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */) = cpu.ecx;
    // 0047443d  39dd                   +cmp ebp, ebx
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
    // 0047443f  0f8d10ffffff           -jge 0x474355
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474355;
    }
    // 00474445  ebc2                   -jmp 0x474409
    goto L_0x00474409;
L_0x00474447:
    // 00474447  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047444a  742a                   -je 0x474476
    if (cpu.flags.zf)
    {
        goto L_0x00474476;
    }
    // 0047444c  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0047444e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00474450:
    // 00474450  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00474452  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00474455  8b5c3404               -mov ebx, dword ptr [esp + esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00474459  8b4930                 -mov ecx, dword ptr [ecx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0047445c  3b4b30                 +cmp ecx, dword ptr [ebx + 0x30]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047445f  7d08                   -jge 0x474469
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474469;
    }
    // 00474461  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00474463  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474465  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474467  75e7                   -jne 0x474450
    if (!cpu.flags.zf)
    {
        goto L_0x00474450;
    }
L_0x00474469:
    // 00474469  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047446b  89042c                 -mov dword ptr [esp + ebp], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebp * 1) = cpu.eax;
    // 0047446e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474470  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00474472  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00474474  ebac                   -jmp 0x474422
    goto L_0x00474422;
L_0x00474476:
    // 00474476  8b8424dc030000         -mov eax, dword ptr [esp + 0x3dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */);
    // 0047447d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047447f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00474481  89142c                 -mov dword ptr [esp + ebp], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebp * 1) = cpu.edx;
    // 00474484  eb9c                   -jmp 0x474422
    goto L_0x00474422;
L_0x00474486:
    // 00474486  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 0047448d  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00474490  e87ff7fbff             -call 0x433c14
    cpu.esp -= 4;
    sub_433c14(app, cpu);
    if (cpu.terminate) return;
    // 00474495  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00474497  e9b9feffff             -jmp 0x474355
    goto L_0x00474355;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4744a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004744a0);
    // 004744a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004744a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004744a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004744a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004744a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004744a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004744a6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004744a9  8b2df8505400           -mov ebp, dword ptr [0x5450f8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 004744af  8b15fc505400           -mov edx, dword ptr [0x5450fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525756) /* 0x5450fc */);
    // 004744b5  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 004744ba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004744bc  83f803                 +cmp eax, 3
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
    // 004744bf  0f8ea4000000           -jle 0x474569
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474569;
    }
    // 004744c5  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 004744ca  a3fc505400             -mov dword ptr [0x5450fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5525756) /* 0x5450fc */) = cpu.eax;
    // 004744cf  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004744d1  0f85a2000000           -jne 0x474579
    if (!cpu.flags.zf)
    {
        goto L_0x00474579;
    }
L_0x004744d7:
    // 004744d7  8b2df8505400           -mov ebp, dword ptr [0x5450f8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 004744dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004744df  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004744e1  7e6b                   -jle 0x47454e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047454e;
    }
    // 004744e3  bad4255400             -mov edx, 0x5425d4
    cpu.edx = 5514708 /*0x5425d4*/;
L_0x004744e8:
    // 004744e8  8a6202                 -mov ah, byte ptr [edx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004744eb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004744ed  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004744ef  0f840a010000           -je 0x4745ff
    if (cpu.flags.zf)
    {
        goto L_0x004745ff;
    }
    // 004744f5  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004744f8  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004744fb  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004744fe  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00474500  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474502  897210                 -mov dword ptr [edx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00474505  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474509  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047450c  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0047450f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00474511  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474513  897214                 -mov dword ptr [edx + 0x14], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00474516  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047451a  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0047451d  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00474520  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
L_0x00474522:
    // 00474522  01c6                   +add esi, eax
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
    // 00474524  892df8505400           -mov dword ptr [0x5450f8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */) = cpu.ebp;
    // 0047452a  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047452d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047452f  e84c020000             -call 0x474780
    cpu.esp -= 4;
    sub_474780(app, cpu);
    if (cpu.terminate) return;
    // 00474534  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00474537  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474538  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047453b  7503                   -jne 0x474540
    if (!cpu.flags.zf)
    {
        goto L_0x00474540;
    }
    // 0047453d  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00474540:
    // 00474540  8b2df8505400           -mov ebp, dword ptr [0x5450f8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 00474546  43                     -inc ebx
    (cpu.ebx)++;
    // 00474547  83c25c                 -add edx, 0x5c
    (cpu.edx) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0047454a  39eb                   +cmp ebx, ebp
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
    // 0047454c  7c9a                   -jl 0x4744e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004744e8;
    }
L_0x0047454e:
    // 0047454e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474550  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00474552  7e15                   -jle 0x474569
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474569;
    }
L_0x00474554:
    // 00474554  6bf05c                 -imul esi, eax, 0x5c
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(92 /*0x5c*/)));
    // 00474557  80bed425540000         +cmp byte ptr [esi + 0x5425d4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5514708) /* 0x5425d4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047455e  0f84bc000000           -je 0x474620
    if (cpu.flags.zf)
    {
        goto L_0x00474620;
    }
L_0x00474564:
    // 00474564  40                     -inc eax
    (cpu.eax)++;
    // 00474565  39e8                   +cmp eax, ebp
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
    // 00474567  7ceb                   -jl 0x474554
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474554;
    }
L_0x00474569:
    // 00474569  892df8505400           -mov dword ptr [0x5450f8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */) = cpu.ebp;
    // 0047456f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474572  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474573  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474574  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474575  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474576  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474577  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474578  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474579:
    // 00474579  8b0df4505400           -mov ecx, dword ptr [0x5450f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5525748) /* 0x5450f4 */);
    // 0047457f  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474582  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474584  890df4505400           -mov dword ptr [0x5450f4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525748) /* 0x5450f4 */) = cpu.ecx;
    // 0047458a  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00474590  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00474593  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474595  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00474597  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00474599  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047459b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004745a0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004745a2  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004745a9  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004745ab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004745ad  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 004745b2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004745b4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004745b7  c1e810                 +shr eax, 0x10
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
    // 004745ba  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004745bc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004745bf  a1f4505400             -mov eax, dword ptr [0x5450f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525748) /* 0x5450f4 */);
    // 004745c4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004745c6  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004745c9  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004745cb  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004745cd  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004745cf  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004745d1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004745d6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004745d8  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004745df  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004745e1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004745e3  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 004745e8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004745ec  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004745ee  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004745f1  c1e810                 +shr eax, 0x10
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
    // 004745f4  11d0                   +adc eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004745f6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004745fa  e9d8feffff             -jmp 0x4744d7
    goto L_0x004744d7;
L_0x004745ff:
    // 004745ff  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00474602  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00474605  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474607  897210                 -mov dword ptr [edx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0047460a  8b7a14                 -mov edi, dword ptr [edx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0047460d  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00474610  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00474613  01c7                   +add edi, eax
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
    // 00474615  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00474618  897a14                 -mov dword ptr [edx + 0x14], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0047461b  e902ffffff             -jmp 0x474522
    goto L_0x00474522;
L_0x00474620:
    // 00474620  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00474623  6bda5c                 +imul ebx, edx, 0x5c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(92 /*0x5c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00474626  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0047462b  8dbed4255400           -lea edi, [esi + 0x5425d4]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(5514708) /* 0x5425d4 */);
    // 00474631  8db3d4255400           -lea esi, [ebx + 0x5425d4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(5514708) /* 0x5425d4 */);
    // 00474637  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474638  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047463a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047463c  e923ffffff             -jmp 0x474564
    goto L_0x00474564;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474674);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00474674  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474675  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474676  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474677  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474678  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047467b  8b2df8505400           -mov ebp, dword ptr [0x5450f8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 00474681  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00474683  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00474687  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047468b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047468d  83fd78                 +cmp ebp, 0x78
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474690  0f85b3000000           -jne 0x474749
    if (!cpu.flags.zf)
    {
        goto L_0x00474749;
    }
    // 00474696  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047469b  8b0dd8255400           -mov ecx, dword ptr [0x5425d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5514712) /* 0x5425d8 */);
    // 004746a1  39c5                   +cmp ebp, eax
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
    // 004746a3  7e1b                   -jle 0x4746c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004746c0;
    }
    // 004746a5  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
L_0x004746aa:
    // 004746aa  8bbad8255400           -mov edi, dword ptr [edx + 0x5425d8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5514712) /* 0x5425d8 */);
    // 004746b0  39f9                   +cmp ecx, edi
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
    // 004746b2  7e04                   -jle 0x4746b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004746b8;
    }
    // 004746b4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004746b6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004746b8:
    // 004746b8  40                     -inc eax
    (cpu.eax)++;
    // 004746b9  83c25c                 -add edx, 0x5c
    (cpu.edx) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004746bc  39e8                   +cmp eax, ebp
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
    // 004746be  7cea                   -jl 0x4746aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004746aa;
    }
L_0x004746c0:
    // 004746c0  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004746c7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004746c9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004746cc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004746ce  bad4255400             -mov edx, 0x5425d4
    cpu.edx = 5514708 /*0x5425d4*/;
    // 004746d3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004746d6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004746d8  8d7a10                 -lea edi, [edx + 0x10]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004746db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004746dc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004746dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004746de  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004746e2  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004746e9  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004746eb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004746ef  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004746f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004746f4  7513                   -jne 0x474709
    if (!cpu.flags.zf)
    {
        goto L_0x00474709;
    }
    // 004746f6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004746f8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004746fa  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004746fe  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00474701  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00474705  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x00474709:
    // 00474709  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047470d  48                     -dec eax
    (cpu.eax)--;
    // 0047470e  892df8505400           -mov dword ptr [0x5450f8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */) = cpu.ebp;
    // 00474714  83f808                 +cmp eax, 8
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
    // 00474717  7719                   -ja 0x474732
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00474732;
    }
    // 00474719  ff248550464700         -jmp dword ptr [eax*4 + 0x474650]
    cpu.ip = app->getMemory<x86::reg32>(4671056 + cpu.eax * 4); goto dynamic_jump;
  case 0x00474720:
    // 00474720  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474722  e8b9000000             -call 0x4747e0
    cpu.esp -= 4;
    sub_4747e0(app, cpu);
    if (cpu.terminate) return;
    // 00474727  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474729  c6420201               -mov byte ptr [edx + 2], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 1 /*0x1*/;
L_0x0047472d:
    // 0047472d  e88e000000             -call 0x4747c0
    cpu.esp -= 4;
    sub_4747c0(app, cpu);
    if (cpu.terminate) return;
L_0x00474732:
    // 00474732  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474734  e86bf4fbff             -call 0x433ba4
    cpu.esp -= 4;
    sub_433ba4(app, cpu);
    if (cpu.terminate) return;
    // 00474739  8b2df8505400           -mov ebp, dword ptr [0x5450f8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5525752) /* 0x5450f8 */);
    // 0047473f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474741  83c414                 +add esp, 0x14
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
    // 00474744  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474745  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474746  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474747  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474749:
    // 00474749  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047474b  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047474c  e96fffffff             -jmp 0x4746c0
    goto L_0x004746c0;
  case 0x00474751:
    // 00474751  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00474755  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00474757  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047475a  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047475d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00474761  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00474764  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00474767  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047476a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047476e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00474771  c1f805                 +sar eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00474774  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00474777  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474779  c6420200               -mov byte ptr [edx + 2], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0047477d  ebae                   -jmp 0x47472d
    goto L_0x0047472d;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_474780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474780);
    // 00474780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474782  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474783  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00474786  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 00474789  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047478c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047478f  83fbfd                 +cmp ebx, -3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474792  7c09                   -jl 0x47479d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047479d;
    }
    // 00474794  83fb03                 +cmp ebx, 3
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
    // 00474797  7f0e                   -jg 0x4747a7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004747a7;
    }
    // 00474799  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047479a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047479b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047479c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047479d:
    // 0047479d  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004747a0  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004747a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004747a7:
    // 004747a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004747a8  8d7bff                 -lea edi, [ebx - 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004747ab  89780c                 -mov dword ptr [eax + 0xc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004747ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4747c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004747c0);
    // 004747c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004747c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004747c3  e8ac380100             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004747c8  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004747cb  e8a4380100             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004747d0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004747d3  83e83f                 -sub eax, 0x3f
    (cpu.eax) -= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004747d6  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004747d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4747e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004747e0);
    // 004747e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004747e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004747e3  e88c380100             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004747e8  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004747ed  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004747f0  e87f380100             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004747f5  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004747fa  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004747fd  e872380100             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 00474802  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 00474807  05ff070000             -add eax, 0x7ff
    (cpu.eax) += x86::reg32(x86::sreg32(2047 /*0x7ff*/));
    // 0047480c  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047480f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474810  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474820);
    // 00474820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474823  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474824  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474825  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474826  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474829  8b15240f5400           -mov edx, dword ptr [0x540f24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */);
    // 0047482f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474831  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474833  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00474835  0f8565000000           -jne 0x4748a0
    if (!cpu.flags.zf)
    {
        goto L_0x004748a0;
    }
    // 0047483b  833d401e510000         +cmp dword ptr [0x511e40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474842  7e4d                   -jle 0x474891
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474891;
    }
    // 00474844  8b15401e5100           -mov edx, dword ptr [0x511e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 0047484a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047484c  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047484e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474850  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00474853:
    // 00474853  8b91081d5100           -mov edx, dword ptr [ecx + 0x511d08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474859  8bba1c020000           -mov edi, dword ptr [edx + 0x21c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(540) /* 0x21c */);
    // 0047485f  833f24                 +cmp dword ptr [edi], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474862  745b                   -je 0x4748bf
    if (cpu.flags.zf)
    {
        goto L_0x004748bf;
    }
    // 00474864  83ba8002000002         +cmp dword ptr [edx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047486b  753d                   -jne 0x4748aa
    if (!cpu.flags.zf)
    {
        goto L_0x004748aa;
    }
    // 0047486d  8b9224020000           -mov edx, dword ptr [edx + 0x224]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */);
    // 00474873  8b2d480f5400           -mov ebp, dword ptr [0x540f48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474879  81c240010000           -add edx, 0x140
    (cpu.edx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047487f  39ea                   +cmp edx, ebp
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
    // 00474881  7d27                   -jge 0x4748aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004748aa;
    }
L_0x00474883:
    // 00474883  43                     -inc ebx
    (cpu.ebx)++;
L_0x00474884:
    // 00474884  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00474887  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047488a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047488d  39f8                   +cmp eax, edi
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
    // 0047488f  7cc2                   -jl 0x474853
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474853;
    }
L_0x00474891:
    // 00474891  a1401e5100             -mov eax, dword ptr [0x511e40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00474896  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00474898  39c3                   +cmp ebx, eax
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
    // 0047489a  7504                   -jne 0x4748a0
    if (!cpu.flags.zf)
    {
        goto L_0x004748a0;
    }
    // 0047489c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047489e  7f22                   -jg 0x4748c2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004748c2;
    }
L_0x004748a0:
    // 004748a0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004748a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004748aa:
    // 004748aa  833d0822510004         +cmp dword ptr [0x512208], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004748b1  75d1                   -jne 0x474884
    if (!cpu.flags.zf)
    {
        goto L_0x00474884;
    }
    // 004748b3  6683b84834510000       +cmp word ptr [eax + 0x513448], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5321800) /* 0x513448 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004748bb  75c6                   -jne 0x474883
    if (!cpu.flags.zf)
    {
        goto L_0x00474883;
    }
    // 004748bd  ebc5                   -jmp 0x474884
    goto L_0x00474884;
L_0x004748bf:
    // 004748bf  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004748c0  ebc2                   -jmp 0x474884
    goto L_0x00474884;
L_0x004748c2:
    // 004748c2  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004748c7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004748cc  892d240f5400           -mov dword ptr [0x540f24], ebp
    app->getMemory<x86::reg32>(x86::reg32(5508900) /* 0x540f24 */) = cpu.ebp;
    // 004748d2  e819000000             -call 0x4748f0
    cpu.esp -= 4;
    sub_4748f0(app, cpu);
    if (cpu.terminate) return;
    // 004748d7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004748da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4748f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004748f0);
    // 004748f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004748f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004748f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004748f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004748f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004748f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004748f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004748f9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004748fb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00474900  8b0d401e5100           -mov ecx, dword ptr [0x511e40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00474906  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474908  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047490b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047490d  0f8e7b000000           -jle 0x47498e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047498e;
    }
    // 00474913  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00474915:
    // 00474915  8b15a0185100           -mov edx, dword ptr [0x5118a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0047491b  0faf15fc215100         -imul edx, dword ptr [0x5121fc]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317116) /* 0x5121fc */))));
    // 00474922  8b99081d5100           -mov ebx, dword ptr [ecx + 0x511d08]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474928  8b831c020000           -mov eax, dword ptr [ebx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(540) /* 0x21c */);
    // 0047492e  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474931  0f85ec000000           -jne 0x474a23
    if (!cpu.flags.zf)
    {
        goto L_0x00474a23;
    }
    // 00474937  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0047493d  39ea                   +cmp edx, ebp
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
    // 0047493f  7e16                   -jle 0x474957
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474957;
    }
    // 00474941  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00474943  0f85c0000000           -jne 0x474a09
    if (!cpu.flags.zf)
    {
        goto L_0x00474a09;
    }
    // 00474949  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047494b:
    // 0047494b  8b91081d5100           -mov edx, dword ptr [ecx + 0x511d08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474951  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
L_0x00474957:
    // 00474957  8b81081d5100           -mov eax, dword ptr [ecx + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 0047495d  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00474963:
    // 00474963  83ff01                 +cmp edi, 1
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
    // 00474966  7518                   -jne 0x474980
    if (!cpu.flags.zf)
    {
        goto L_0x00474980;
    }
    // 00474968  3b3df8215100           +cmp edi, dword ptr [0x5121f8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317112) /* 0x5121f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047496e  0f8418010000           -je 0x474a8c
    if (cpu.flags.zf)
    {
        goto L_0x00474a8c;
    }
    // 00474974  8b81081d5100           -mov eax, dword ptr [ecx + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
L_0x0047497a:
    // 0047497a  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00474980:
    // 00474980  8b1d401e5100           -mov ebx, dword ptr [0x511e40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00474986  46                     -inc esi
    (cpu.esi)++;
    // 00474987  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047498a  39de                   +cmp esi, ebx
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
    // 0047498c  7c87                   -jl 0x474915
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474915;
    }
L_0x0047498e:
    // 0047498e  8b2d301e5100           -mov ebp, dword ptr [0x511e30]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5316144) /* 0x511e30 */);
    // 00474994  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474996  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00474998  7e65                   -jle 0x4749ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004749ff;
    }
    // 0047499a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047499c:
    // 0047499c  8b99481c5100           -mov ebx, dword ptr [ecx + 0x511c48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315656) /* 0x511c48 */);
    // 004749a2  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004749a9  7435                   -je 0x4749e0
    if (cpu.flags.zf)
    {
        goto L_0x004749e0;
    }
    // 004749ab  83bb2002000000         +cmp dword ptr [ebx + 0x220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004749b2  0f85f8000000           -jne 0x474ab0
    if (!cpu.flags.zf)
    {
        goto L_0x00474ab0;
    }
    // 004749b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004749ba:
    // 004749ba  8b91481c5100           -mov edx, dword ptr [ecx + 0x511c48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315656) /* 0x511c48 */);
    // 004749c0  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 004749c6  833c2400               +cmp dword ptr [esp], 0
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
    // 004749ca  0f840d010000           -je 0x474add
    if (cpu.flags.zf)
    {
        goto L_0x00474add;
    }
    // 004749d0  8b81481c5100           -mov eax, dword ptr [ecx + 0x511c48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315656) /* 0x511c48 */);
    // 004749d6  c7808002000002000000   -mov dword ptr [eax + 0x280], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
L_0x004749e0:
    // 004749e0  83ff01                 +cmp edi, 1
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
    // 004749e3  750c                   -jne 0x4749f1
    if (!cpu.flags.zf)
    {
        goto L_0x004749f1;
    }
    // 004749e5  8b81481c5100           -mov eax, dword ptr [ecx + 0x511c48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315656) /* 0x511c48 */);
    // 004749eb  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x004749f1:
    // 004749f1  8b2d301e5100           -mov ebp, dword ptr [0x511e30]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5316144) /* 0x511e30 */);
    // 004749f7  46                     -inc esi
    (cpu.esi)++;
    // 004749f8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004749fb  39ee                   +cmp esi, ebp
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
    // 004749fd  7c9d                   -jl 0x47499c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047499c;
    }
L_0x004749ff:
    // 004749ff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474a02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474a09:
    // 00474a09  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00474a0f  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00474a14  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00474a17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474a19  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474a1c  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474a1e  e928ffffff             -jmp 0x47494b
    goto L_0x0047494b;
L_0x00474a23:
    // 00474a23  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a2a  0f8433ffffff           -je 0x474963
    if (cpu.flags.zf)
    {
        goto L_0x00474963;
    }
    // 00474a30  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00474a36  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00474a38  7531                   -jne 0x474a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00474a6b;
    }
    // 00474a3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474a3c:
    // 00474a3c  8b91081d5100           -mov edx, dword ptr [ecx + 0x511d08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474a42  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 00474a48  833df821510001         +cmp dword ptr [0x5121f8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317112) /* 0x5121f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a4f  7431                   -je 0x474a82
    if (cpu.flags.zf)
    {
        goto L_0x00474a82;
    }
L_0x00474a51:
    // 00474a51  8b81081d5100           -mov eax, dword ptr [ecx + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474a57  c7808002000001000000   -mov dword ptr [eax + 0x280], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
L_0x00474a61:
    // 00474a61  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00474a63  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00474a66  e9f8feffff             -jmp 0x474963
    goto L_0x00474963;
L_0x00474a6b:
    // 00474a6b  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00474a71  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00474a76  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00474a79  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474a7b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474a7e  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474a80  ebba                   -jmp 0x474a3c
    goto L_0x00474a3c;
L_0x00474a82:
    // 00474a82  3b350c225100           +cmp esi, dword ptr [0x51220c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a88  75d7                   -jne 0x474a61
    if (!cpu.flags.zf)
    {
        goto L_0x00474a61;
    }
    // 00474a8a  ebc5                   -jmp 0x474a51
    goto L_0x00474a51;
L_0x00474a8c:
    // 00474a8c  8b81081d5100           -mov eax, dword ptr [ecx + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474a92  83b88002000002         +cmp dword ptr [eax + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a99  0f84e1feffff           -je 0x474980
    if (cpu.flags.zf)
    {
        goto L_0x00474980;
    }
    // 00474a9f  3b350c225100           +cmp esi, dword ptr [0x51220c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474aa5  0f85d5feffff           -jne 0x474980
    if (!cpu.flags.zf)
    {
        goto L_0x00474980;
    }
    // 00474aab  e9cafeffff             -jmp 0x47497a
    goto L_0x0047497a;
L_0x00474ab0:
    // 00474ab0  8b15a0185100           -mov edx, dword ptr [0x5118a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 00474ab6  0faf15fc215100         -imul edx, dword ptr [0x5121fc]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317116) /* 0x5121fc */))));
    // 00474abd  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00474ac3  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00474ac8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00474acb  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00474ad1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474ad3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474ad6  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474ad8  e9ddfeffff             -jmp 0x4749ba
    goto L_0x004749ba;
L_0x00474add:
    // 00474add  8b81481c5100           -mov eax, dword ptr [ecx + 0x511c48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5315656) /* 0x511c48 */);
    // 00474ae3  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
    // 00474ae9  e9f2feffff             -jmp 0x4749e0
    goto L_0x004749e0;
}

/* align: skip 0x00 0x00 */
void Application::sub_474af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474af0);
    // 00474af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474af1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474af2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474af3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474af4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474af5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474af6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00474af9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00474afb  8b9030020000           -mov edx, dword ptr [eax + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 00474b01  83fa08                 +cmp edx, 8
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
    // 00474b04  7d73                   -jge 0x474b79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474b79;
    }
    // 00474b06  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00474b0d  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00474b10  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00474b16  3b8258020000           +cmp eax, dword ptr [edx + 0x258]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474b1c  7e5b                   -jle 0x474b79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474b79;
    }
    // 00474b1e  f685f401000008         +test byte ptr [ebp + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 00474b25  0f8494020000           -je 0x474dbf
    if (cpu.flags.zf)
    {
        goto L_0x00474dbf;
    }
    // 00474b2b  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00474b31  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00474b33  83fb0f                 +cmp ebx, 0xf
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
    // 00474b36  0f8d83020000           -jge 0x474dbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474dbf;
    }
    // 00474b3c  833d0822510002         +cmp dword ptr [0x512208], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474b43  0f8c2c020000           -jl 0x474d75
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474d75;
    }
    // 00474b49  6985e801000099190000   -imul eax, dword ptr [ebp + 0x1e8], 0x1999
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */))) * x86::sreg64(x86::sreg32(6553 /*0x1999*/)));
    // 00474b53  8b149d745f4d00         -mov edx, dword ptr [ebx*4 + 0x4d5f74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5070708) /* 0x4d5f74 */ + cpu.ebx * 4);
    // 00474b5a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474b5c  8b9db8020000           -mov ebx, dword ptr [ebp + 0x2b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00474b62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474b64  39da                   +cmp edx, ebx
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
    // 00474b66  0f8d02020000           -jge 0x474d6e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474d6e;
    }
L_0x00474b6c:
    // 00474b6c  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00474b72  89849558020000         -mov dword ptr [ebp + edx*4 + 0x258], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(600) /* 0x258 */ + cpu.edx * 4) = cpu.eax;
L_0x00474b79:
    // 00474b79  8bb5f8010000           -mov esi, dword ptr [ebp + 0x1f8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 00474b7f  3bb530020000           +cmp esi, dword ptr [ebp + 0x230]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474b85  0f8491000000           -je 0x474c1c
    if (cpu.flags.zf)
    {
        goto L_0x00474c1c;
    }
    // 00474b8b  83bd8002000002         +cmp dword ptr [ebp + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474b92  0f8484000000           -je 0x474c1c
    if (cpu.flags.zf)
    {
        goto L_0x00474c1c;
    }
    // 00474b98  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474b9d  8b9534020000           -mov edx, dword ptr [ebp + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 00474ba3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474ba5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474ba7  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00474bad  89948538020000         -mov dword ptr [ebp + eax*4 + 0x238], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(568) /* 0x238 */ + cpu.eax * 4) = cpu.edx;
    // 00474bb4  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474bb9  898534020000           -mov dword ptr [ebp + 0x234], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 00474bbf  8b85f8010000           -mov eax, dword ptr [ebp + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 00474bc5  8b0dfc215100           -mov ecx, dword ptr [0x5121fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317116) /* 0x5121fc */);
    // 00474bcb  898530020000           -mov dword ptr [ebp + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 00474bd1  39c8                   +cmp eax, ecx
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
    // 00474bd3  7547                   -jne 0x474c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00474c1c;
    }
    // 00474bd5  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00474bdb  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474bde  743c                   -je 0x474c1c
    if (cpu.flags.zf)
    {
        goto L_0x00474c1c;
    }
    // 00474be0  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00474be6  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474beb  42                     -inc edx
    (cpu.edx)++;
    // 00474bec  898524020000           -mov dword ptr [ebp + 0x224], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 00474bf2  a1a0185100             -mov eax, dword ptr [0x5118a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 00474bf7  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00474bfa  8bb534020000           -mov esi, dword ptr [ebp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 00474c00  c7858002000002000000   -mov dword ptr [ebp + 0x280], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
    // 00474c0a  81ee00020000           -sub esi, 0x200
    (cpu.esi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00474c10  89b534020000           -mov dword ptr [ebp + 0x234], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.esi;
    // 00474c16  899520020000           -mov dword ptr [ebp + 0x220], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.edx;
L_0x00474c1c:
    // 00474c1c  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00474c1f  3bbd28020000           +cmp edi, dword ptr [ebp + 0x228]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c25  7455                   -je 0x474c7c
    if (cpu.flags.zf)
    {
        goto L_0x00474c7c;
    }
    // 00474c27  8b8580020000           -mov eax, dword ptr [ebp + 0x280]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
    // 00474c2d  89bd28020000           -mov dword ptr [ebp + 0x228], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */) = cpu.edi;
    // 00474c33  83f802                 +cmp eax, 2
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
    // 00474c36  7444                   -je 0x474c7c
    if (cpu.flags.zf)
    {
        goto L_0x00474c7c;
    }
    // 00474c38  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00474c3d  8b1528225100           -mov edx, dword ptr [0x512228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00474c43  898524020000           -mov dword ptr [ebp + 0x224], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 00474c49  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00474c4b  0f848b010000           -je 0x474ddc
    if (cpu.flags.zf)
    {
        goto L_0x00474ddc;
    }
    // 00474c51  8b15a0185100           -mov edx, dword ptr [0x5118a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 00474c57  2b9528020000           -sub edx, dword ptr [ebp + 0x228]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
L_0x00474c5d:
    // 00474c5d  8b9dfc010000           -mov ebx, dword ptr [ebp + 0x1fc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(508) /* 0x1fc */);
    // 00474c63  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00474c69  8b35a0185100           -mov esi, dword ptr [0x5118a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 00474c6f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474c71  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00474c74  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00474c76  898520020000           -mov dword ptr [ebp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x00474c7c:
    // 00474c7c  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00474c82  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c85  0f84d9000000           -je 0x474d64
    if (cpu.flags.zf)
    {
        goto L_0x00474d64;
    }
    // 00474c8b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474c8d  8b15441e5100           -mov edx, dword ptr [0x511e44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00474c93  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00474c97  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00474c99  0f8ec5000000           -jle 0x474d64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474d64;
    }
    // 00474c9f  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00474ca2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00474ca5:
    // 00474ca5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474ca9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00474cac  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 00474cb2  8bb004515400           -mov esi, dword ptr [eax + 0x545104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525764) /* 0x545104 */);
    // 00474cb8  39f2                   +cmp edx, esi
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
    // 00474cba  0f8e27010000           -jle 0x474de7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474de7;
    }
L_0x00474cc0:
    // 00474cc0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474cc3  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474cc7  39d8                   +cmp eax, ebx
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
    // 00474cc9  7c3f                   -jl 0x474d0a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474d0a;
    }
    // 00474ccb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00474ccd  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00474cd0  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
L_0x00474cd3:
    // 00474cd3  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474cd6  8bb010515400           -mov esi, dword ptr [eax + 0x545110]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525776) /* 0x545110 */);
    // 00474cdc  8b9014515400           -mov edx, dword ptr [eax + 0x545114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525780) /* 0x545114 */);
    // 00474ce2  89b020515400           -mov dword ptr [eax + 0x545120], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525792) /* 0x545120 */) = cpu.esi;
    // 00474ce8  899024515400           -mov dword ptr [eax + 0x545124], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525796) /* 0x545124 */) = cpu.edx;
    // 00474cee  8b9818515400           -mov ebx, dword ptr [eax + 0x545118]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525784) /* 0x545118 */);
    // 00474cf4  8b881c515400           -mov ecx, dword ptr [eax + 0x54511c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525788) /* 0x54511c */);
    // 00474cfa  899828515400           -mov dword ptr [eax + 0x545128], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525800) /* 0x545128 */) = cpu.ebx;
    // 00474d00  89882c515400           -mov dword ptr [eax + 0x54512c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525804) /* 0x54512c */) = cpu.ecx;
    // 00474d06  39f8                   +cmp eax, edi
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
    // 00474d08  7dc9                   -jge 0x474cd3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474cd3;
    }
L_0x00474d0a:
    // 00474d0a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474d0e  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 00474d14  8b8d24020000           -mov ecx, dword ptr [ebp + 0x224]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */);
    // 00474d1a  8bb5e8010000           -mov esi, dword ptr [ebp + 0x1e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */);
    // 00474d20  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00474d23  8b9df4010000           -mov ebx, dword ptr [ebp + 0x1f4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(500) /* 0x1f4 */);
    // 00474d29  89b000515400           -mov dword ptr [eax + 0x545100], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525760) /* 0x545100 */) = cpu.esi;
    // 00474d2f  899004515400           -mov dword ptr [eax + 0x545104], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525764) /* 0x545104 */) = cpu.edx;
    // 00474d35  83e304                 -and ebx, 4
    cpu.ebx &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474d38  898808515400           -mov dword ptr [eax + 0x545108], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525768) /* 0x545108 */) = cpu.ecx;
    // 00474d3e  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 00474d43  89980c515400           -mov dword ptr [eax + 0x54510c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525772) /* 0x54510c */) = cpu.ebx;
    // 00474d49  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00474d4d:
    // 00474d4d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474d51  41                     -inc ecx
    (cpu.ecx)++;
    // 00474d52  8b1d441e5100           -mov ebx, dword ptr [0x511e44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00474d58  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00474d5c  39d9                   +cmp ecx, ebx
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
    // 00474d5e  0f8c41ffffff           -jl 0x474ca5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474ca5;
    }
L_0x00474d64:
    // 00474d64  83c408                 +add esp, 8
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
    // 00474d67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474d6e:
    // 00474d6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00474d70  e9f7fdffff             -jmp 0x474b6c
    goto L_0x00474b6c;
L_0x00474d75:
    // 00474d75  e835a10200             -call 0x49eeaf
    cpu.esp -= 4;
    sub_49eeaf(app, cpu);
    if (cpu.terminate) return;
    // 00474d7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474d7c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00474d7f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474d81  8b149d745f4d00         -mov edx, dword ptr [ebx*4 + 0x4d5f74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5070708) /* 0x4d5f74 */ + cpu.ebx * 4);
    // 00474d88  8bbdb8020000           -mov edi, dword ptr [ebp + 0x2b8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00474d8e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474d90  39fa                   +cmp edx, edi
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
    // 00474d92  7d24                   -jge 0x474db8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474db8;
    }
    // 00474d94  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00474d9a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00474d9c  e80ea10200             -call 0x49eeaf
    cpu.esp -= 4;
    sub_49eeaf(app, cpu);
    if (cpu.terminate) return;
    // 00474da1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474da3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00474da6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474da8  8b148d745f4d00         -mov edx, dword ptr [ecx*4 + 0x4d5f74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5070708) /* 0x4d5f74 */ + cpu.ecx * 4);
    // 00474daf  29c2                   +sub edx, eax
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
    // 00474db1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474db3  e9b4fdffff             -jmp 0x474b6c
    goto L_0x00474b6c;
L_0x00474db8:
    // 00474db8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00474dba  e9adfdffff             -jmp 0x474b6c
    goto L_0x00474b6c;
L_0x00474dbf:
    // 00474dbf  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00474dc5  c1e002                 +shl eax, 2
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
    // 00474dc8  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00474dcb  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00474dd1  898258020000           -mov dword ptr [edx + 0x258], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */) = cpu.eax;
    // 00474dd7  e99dfdffff             -jmp 0x474b79
    goto L_0x00474b79;
L_0x00474ddc:
    // 00474ddc  8b9528020000           -mov edx, dword ptr [ebp + 0x228]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */);
    // 00474de2  e976feffff             -jmp 0x474c5d
    goto L_0x00474c5d;
L_0x00474de7:
    // 00474de7  0f8560ffffff           -jne 0x474d4d
    if (!cpu.flags.zf)
    {
        goto L_0x00474d4d;
    }
    // 00474ded  8b8808515400           -mov ecx, dword ptr [eax + 0x545108]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525768) /* 0x545108 */);
    // 00474df3  3b8d24020000           +cmp ecx, dword ptr [ebp + 0x224]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474df9  0f8fc1feffff           -jg 0x474cc0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00474cc0;
    }
    // 00474dff  e949ffffff             -jmp 0x474d4d
    goto L_0x00474d4d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474e10);
    // 00474e10  83f801                 +cmp eax, 1
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
    // 00474e13  7e11                   -jle 0x474e26
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474e26;
    }
    // 00474e15  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00474e18  8b80e0505400           -mov eax, dword ptr [eax + 0x5450e0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525728) /* 0x5450e0 */);
    // 00474e1e  8b0485481b5100         -mov eax, dword ptr [eax*4 + 0x511b48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315400) /* 0x511b48 */ + cpu.eax * 4);
    // 00474e25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474e26:
    // 00474e26  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474e28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474e30);
    // 00474e30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474e31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474e32  8b0d441e5100           -mov ecx, dword ptr [0x511e44]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00474e38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474e3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474e3c  7e16                   -jle 0x474e54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474e54;
    }
    // 00474e3e  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00474e41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474e43:
    // 00474e43  83b800515400ff         +cmp dword ptr [eax + 0x545100], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525760) /* 0x545100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474e4a  7401                   -je 0x474e4d
    if (cpu.flags.zf)
    {
        goto L_0x00474e4d;
    }
    // 00474e4c  42                     -inc edx
    (cpu.edx)++;
L_0x00474e4d:
    // 00474e4d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474e50  39c8                   +cmp eax, ecx
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
    // 00474e52  7cef                   -jl 0x474e43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474e43;
    }
L_0x00474e54:
    // 00474e54  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474e56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474e60);
    // 00474e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474e63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474e64  8b35441e5100           -mov esi, dword ptr [0x511e44]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00474e6a  8b98e8010000           -mov ebx, dword ptr [eax + 0x1e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 00474e70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474e72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474e74  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00474e76  7e15                   -jle 0x474e8d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474e8d;
    }
    // 00474e78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00474e7a:
    // 00474e7a  3b9a00515400           +cmp ebx, dword ptr [edx + 0x545100]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525760) /* 0x545100 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474e80  7503                   -jne 0x474e85
    if (!cpu.flags.zf)
    {
        goto L_0x00474e85;
    }
    // 00474e82  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00474e85:
    // 00474e85  40                     -inc eax
    (cpu.eax)++;
    // 00474e86  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474e89  39f0                   +cmp eax, esi
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
    // 00474e8b  7ced                   -jl 0x474e7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474e7a;
    }
L_0x00474e8d:
    // 00474e8d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474e8f  8935441e5100           -mov dword ptr [0x511e44], esi
    app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */) = cpu.esi;
    // 00474e95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474ea0);
    // 00474ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474ea3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00474ea8  b96179feff             -mov ecx, 0xfffe7961
    cpu.ecx = 4294867297 /*0xfffe7961*/;
    // 00474ead  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474eaf:
    // 00474eaf  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474eb2  8988f4505400           -mov dword ptr [eax + 0x5450f4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525748) /* 0x5450f4 */) = cpu.ecx;
    // 00474eb8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474eba  8990f0505400           -mov dword ptr [eax + 0x5450f0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525744) /* 0x5450f0 */) = cpu.edx;
    // 00474ec0  8998f8505400           -mov dword ptr [eax + 0x5450f8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525752) /* 0x5450f8 */) = cpu.ebx;
    // 00474ec6  8998fc505400           -mov dword ptr [eax + 0x5450fc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5525756) /* 0x5450fc */) = cpu.ebx;
    // 00474ecc  3dc0000000             +cmp eax, 0xc0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474ed1  75dc                   -jne 0x474eaf
    if (!cpu.flags.zf)
    {
        goto L_0x00474eaf;
    }
    // 00474ed3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474ed4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474ed5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474ed6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474ee0);
    // 00474ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474ee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474ee4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474ee5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474ee6  8b2d401e5100           -mov ebp, dword ptr [0x511e40]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00474eec  bf63000000             -mov edi, 0x63
    cpu.edi = 99 /*0x63*/;
    // 00474ef1  8b0d441e5100           -mov ecx, dword ptr [0x511e44]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00474ef7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474ef9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474efb  7e54                   -jle 0x474f51
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474f51;
    }
    // 00474efd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474eff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00474f01:
    // 00474f01  8b83c81c5100           -mov eax, dword ptr [ebx + 0x511cc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5315784) /* 0x511cc8 */);
    // 00474f07  e854ffffff             -call 0x474e60
    cpu.esp -= 4;
    sub_474e60(app, cpu);
    if (cpu.terminate) return;
    // 00474f0c  8bb3c81c5100           -mov esi, dword ptr [ebx + 0x511cc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5315784) /* 0x511cc8 */);
    // 00474f12  898678020000           -mov dword ptr [esi + 0x278], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(632) /* 0x278 */) = cpu.eax;
    // 00474f18  83b90c51540000         +cmp dword ptr [ecx + 0x54510c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5525772) /* 0x54510c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f1f  741f                   -je 0x474f40
    if (cpu.flags.zf)
    {
        goto L_0x00474f40;
    }
    // 00474f21  83ff63                 +cmp edi, 0x63
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f24  751a                   -jne 0x474f40
    if (!cpu.flags.zf)
    {
        goto L_0x00474f40;
    }
    // 00474f26  8b8100515400           -mov eax, dword ptr [ecx + 0x545100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5525760) /* 0x545100 */);
    // 00474f2c  8b0485c81c5100         -mov eax, dword ptr [eax*4 + 0x511cc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315784) /* 0x511cc8 */ + cpu.eax * 4);
    // 00474f33  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 00474f39  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f3c  7402                   -je 0x474f40
    if (cpu.flags.zf)
    {
        goto L_0x00474f40;
    }
    // 00474f3e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x00474f40:
    // 00474f40  8b35441e5100           -mov esi, dword ptr [0x511e44]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00474f46  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474f49  42                     -inc edx
    (cpu.edx)++;
    // 00474f4a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474f4d  39f2                   +cmp edx, esi
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
    // 00474f4f  7cb0                   -jl 0x474f01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474f01;
    }
L_0x00474f51:
    // 00474f51  a110225100             -mov eax, dword ptr [0x512210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317136) /* 0x512210 */);
    // 00474f56  8b2d401e5100           -mov ebp, dword ptr [0x511e40]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00474f5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474f5e  744b                   -je 0x474fab
    if (cpu.flags.zf)
    {
        goto L_0x00474fab;
    }
    // 00474f60  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474f62  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00474f64  7e45                   -jle 0x474fab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474fab;
    }
    // 00474f66  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00474f69  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00474f6b:
    // 00474f6b  8b83081d5100           -mov eax, dword ptr [ebx + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5315848) /* 0x511d08 */);
    // 00474f71  8b901c020000           -mov edx, dword ptr [eax + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 00474f77  833a24                 +cmp dword ptr [edx], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f7a  741d                   -je 0x474f99
    if (cpu.flags.zf)
    {
        goto L_0x00474f99;
    }
    // 00474f7c  8b9020020000           -mov edx, dword ptr [eax + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00474f82  8b8f04515400           -mov ecx, dword ptr [edi + 0x545104]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5525764) /* 0x545104 */);
    // 00474f88  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474f8a  6b150422510074         -imul edx, dword ptr [0x512204], 0x74
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */))) * x86::sreg64(x86::sreg32(116 /*0x74*/)));
    // 00474f91  3b8a9c1d5100           +cmp ecx, dword ptr [edx + 0x511d9c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315996) /* 0x511d9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f97  7d1f                   -jge 0x474fb8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474fb8;
    }
L_0x00474f99:
    // 00474f99  c7801802000000000100   -mov dword ptr [eax + 0x218], 0x10000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = 65536 /*0x10000*/;
L_0x00474fa3:
    // 00474fa3  46                     -inc esi
    (cpu.esi)++;
    // 00474fa4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474fa7  39ee                   +cmp esi, ebp
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
    // 00474fa9  7cc0                   -jl 0x474f6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474f6b;
    }
L_0x00474fab:
    // 00474fab  892d401e5100           -mov dword ptr [0x511e40], ebp
    app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */) = cpu.ebp;
    // 00474fb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474fb2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474fb3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474fb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474fb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474fb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474fb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474fb8:
    // 00474fb8  3b8aa01d5100           +cmp ecx, dword ptr [edx + 0x511da0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316000) /* 0x511da0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474fbe  7d0e                   -jge 0x474fce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474fce;
    }
    // 00474fc0  8b92ac1d5100           -mov edx, dword ptr [edx + 0x511dac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316012) /* 0x511dac */);
    // 00474fc6  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00474fcc  ebd5                   -jmp 0x474fa3
    goto L_0x00474fa3;
L_0x00474fce:
    // 00474fce  3b8aa41d5100           +cmp ecx, dword ptr [edx + 0x511da4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316004) /* 0x511da4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474fd4  7d0e                   -jge 0x474fe4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474fe4;
    }
    // 00474fd6  8b92b01d5100           -mov edx, dword ptr [edx + 0x511db0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316016) /* 0x511db0 */);
    // 00474fdc  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00474fe2  ebbf                   -jmp 0x474fa3
    goto L_0x00474fa3;
L_0x00474fe4:
    // 00474fe4  3b8aa81d5100           +cmp ecx, dword ptr [edx + 0x511da8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316008) /* 0x511da8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474fea  7d0e                   -jge 0x474ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474ffa;
    }
    // 00474fec  8b92b41d5100           -mov edx, dword ptr [edx + 0x511db4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316020) /* 0x511db4 */);
    // 00474ff2  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00474ff8  eba9                   -jmp 0x474fa3
    goto L_0x00474fa3;
L_0x00474ffa:
    // 00474ffa  8b92b81d5100           -mov edx, dword ptr [edx + 0x511db8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5316024) /* 0x511db8 */);
    // 00475000  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00475006  eb9b                   -jmp 0x474fa3
    goto L_0x00474fa3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 04000000080000000a0000000c00000010000000400000001800000000000000 */
void Application::sub_475030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475030);
    // 00475030  030520504700           -add eax, dword ptr [0x475020]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4673568) /* 0x475020 */)));
    // 00475036  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475040);
    // 00475040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475043  8b0d1c504700           -mov ecx, dword ptr [0x47501c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4673564) /* 0x47501c */);
    // 00475049  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047504b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047504d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047504f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475052  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475054  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475056  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 0047505a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047505b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047505c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047505d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_475060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475060);
    // 00475060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475062  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475063  8b0d18504700           -mov ecx, dword ptr [0x475018]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4673560) /* 0x475018 */);
    // 00475069  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047506b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047506d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047506f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475072  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475074  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475076  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 0047507a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047507b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047507c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047507d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_475080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475080);
    // 00475080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475082  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475083  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475084  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475085  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475088  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047508a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047508c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047508e  a114504700             -mov eax, dword ptr [0x475014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4673556) /* 0x475014 */);
    // 00475093  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00475096  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475098  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047509b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047509d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047509f  0fbf3c46               -movsx edi, word ptr [esi + eax*2]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004750a3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004750a5  7427                   -je 0x4750ce
    if (cpu.flags.zf)
    {
        goto L_0x004750ce;
    }
    // 004750a7  a124504700             -mov eax, dword ptr [0x475024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4673572) /* 0x475024 */);
    // 004750ac  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004750ae  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004750b0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004750b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004750b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004750b6  7e16                   -jle 0x4750ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004750ce;
    }
L_0x004750b8:
    // 004750b8  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004750ba  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004750bc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004750be  668b5904               -mov bx, word ptr [ecx + 4]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004750c2  39eb                   +cmp ebx, ebp
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
    // 004750c4  7414                   -je 0x4750da
    if (cpu.flags.zf)
    {
        goto L_0x004750da;
    }
    // 004750c6  40                     -inc eax
    (cpu.eax)++;
    // 004750c7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004750ca  39f8                   +cmp eax, edi
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
    // 004750cc  7cea                   -jl 0x4750b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004750b8;
    }
L_0x004750ce:
    // 004750ce  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004750d1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004750d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004750da:
    // 004750da  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004750dd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004750e0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004750e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4750f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004750f0);
    // 004750f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004750f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004750f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004750f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004750f6  668b480a               -mov cx, word ptr [eax + 0xa]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 004750fa  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00475101  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475103  8b0d28504700           -mov ecx, dword ptr [0x475028]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4673576) /* 0x475028 */);
    // 00475109  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047510b  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047510d  668b5204               -mov dx, word ptr [edx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00475111  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475113  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00475119  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00475120  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475122  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475124  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475126  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475127  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475128  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475130);
    // 00475130  030528504700           -add eax, dword ptr [0x475028]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4673576) /* 0x475028 */)));
    // 00475136  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475140);
    // 00475140  030524504700           -add eax, dword ptr [0x475024]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4673572) /* 0x475024 */)));
    // 00475146  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475150);
    // 00475150  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475151  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475153  3b05dc515400           +cmp eax, dword ptr [0x5451dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5525980) /* 0x5451dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475159  730b                   -jae 0x475166
    if (!cpu.flags.cf)
    {
        goto L_0x00475166;
    }
    // 0047515b  a18c964d00             -mov eax, dword ptr [0x4d968c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084812) /* 0x4d968c */);
    // 00475160  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 00475164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475165  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475166:
    // 00475166  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475167  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475168  bb08010000             -mov ebx, 0x108
    cpu.ebx = 264 /*0x108*/;
    // 0047516d  ba2ce24c00             -mov edx, 0x4ce22c
    cpu.edx = 5038636 /*0x4ce22c*/;
    // 00475172  b88ce24c00             -mov eax, 0x4ce28c
    cpu.eax = 5038732 /*0x4ce28c*/;
    // 00475177  e8679d0200             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
    // 0047517c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047517d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047517e  a18c964d00             -mov eax, dword ptr [0x4d968c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084812) /* 0x4d968c */);
    // 00475183  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 00475187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475188  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475190);
    // 00475190  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475191  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475192  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475194  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00475196  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475198  668b4104               -mov ax, word ptr [ecx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047519c  39c2                   +cmp edx, eax
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
    // 0047519e  7d0b                   -jge 0x4751ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004751ab;
    }
    // 004751a0  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004751a3  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004751a6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004751a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004751ab:
    // 004751ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004751ac  bbf7000000             -mov ebx, 0xf7
    cpu.ebx = 247 /*0xf7*/;
    // 004751b1  ba2ce24c00             -mov edx, 0x4ce22c
    cpu.edx = 5038636 /*0x4ce22c*/;
    // 004751b6  b868e24c00             -mov eax, 0x4ce268
    cpu.eax = 5038696 /*0x4ce268*/;
    // 004751bb  e8239d0200             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
    // 004751c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751c1  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004751c4  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 004751c7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004751c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4751d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004751d0);
    // 004751d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004751d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004751d3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004751d6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004751d8  8b1588964d00           -mov edx, dword ptr [0x4d9688]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084808) /* 0x4d9688 */);
    // 004751de  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004751e1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004751e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4751f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004751f0);
    // 004751f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004751f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004751f2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004751f9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004751fb  8b3588964d00           -mov esi, dword ptr [0x4d9688]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084808) /* 0x4d9688 */);
    // 00475201  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00475204  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00475206  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475208  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475209  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047520a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047520b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047520c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047520d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_475210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475210);
    // 00475210  3b05e0515400           +cmp eax, dword ptr [0x5451e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5525984) /* 0x5451e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475216  7506                   -jne 0x47521e
    if (!cpu.flags.zf)
    {
        goto L_0x0047521e;
    }
    // 00475218  a1cc515400             -mov eax, dword ptr [0x5451cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525964) /* 0x5451cc */);
    // 0047521d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047521e:
    // 0047521e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047521f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475220  bb94000000             -mov ebx, 0x94
    cpu.ebx = 148 /*0x94*/;
    // 00475225  ba2ce24c00             -mov edx, 0x4ce22c
    cpu.edx = 5038636 /*0x4ce22c*/;
    // 0047522a  b84ce24c00             -mov eax, 0x4ce24c
    cpu.eax = 5038668 /*0x4ce24c*/;
    // 0047522f  e8af9c0200             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
    // 00475234  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475235  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475236  a1cc515400             -mov eax, dword ptr [0x5451cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525964) /* 0x5451cc */);
    // 0047523b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_475240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475240);
    // 00475240  3b05e0515400           +cmp eax, dword ptr [0x5451e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5525984) /* 0x5451e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475246  7506                   -jne 0x47524e
    if (!cpu.flags.zf)
    {
        goto L_0x0047524e;
    }
    // 00475248  a1c8515400             -mov eax, dword ptr [0x5451c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525960) /* 0x5451c8 */);
    // 0047524d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047524e:
    // 0047524e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047524f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475250  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00475255  ba2ce24c00             -mov edx, 0x4ce22c
    cpu.edx = 5038636 /*0x4ce22c*/;
    // 0047525a  b84ce24c00             -mov eax, 0x4ce24c
    cpu.eax = 5038668 /*0x4ce24c*/;
    // 0047525f  e87f9c0200             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
    // 00475264  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475265  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475266  a1c8515400             -mov eax, dword ptr [0x5451c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525960) /* 0x5451c8 */);
    // 0047526b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_475270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475270);
    // 00475270  3b05e0515400           +cmp eax, dword ptr [0x5451e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5525984) /* 0x5451e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475276  7506                   -jne 0x47527e
    if (!cpu.flags.zf)
    {
        goto L_0x0047527e;
    }
    // 00475278  a1d8515400             -mov eax, dword ptr [0x5451d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525976) /* 0x5451d8 */);
    // 0047527d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047527e:
    // 0047527e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047527f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475280  bb76000000             -mov ebx, 0x76
    cpu.ebx = 118 /*0x76*/;
    // 00475285  ba2ce24c00             -mov edx, 0x4ce22c
    cpu.edx = 5038636 /*0x4ce22c*/;
    // 0047528a  b84ce24c00             -mov eax, 0x4ce24c
    cpu.eax = 5038668 /*0x4ce24c*/;
    // 0047528f  e84f9c0200             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
    // 00475294  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475295  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475296  a1d8515400             -mov eax, dword ptr [0x5451d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525976) /* 0x5451d8 */);
    // 0047529b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4752a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004752a0);
    // 004752a0  3b05e0515400           +cmp eax, dword ptr [0x5451e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5525984) /* 0x5451e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004752a6  7506                   -jne 0x4752ae
    if (!cpu.flags.zf)
    {
        goto L_0x004752ae;
    }
    // 004752a8  a1dc515400             -mov eax, dword ptr [0x5451dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525980) /* 0x5451dc */);
    // 004752ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004752ae:
    // 004752ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004752af  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004752b0  bb67000000             -mov ebx, 0x67
    cpu.ebx = 103 /*0x67*/;
    // 004752b5  ba2ce24c00             -mov edx, 0x4ce22c
    cpu.edx = 5038636 /*0x4ce22c*/;
    // 004752ba  b84ce24c00             -mov eax, 0x4ce24c
    cpu.eax = 5038668 /*0x4ce24c*/;
    // 004752bf  e81f9c0200             -call 0x49eee3
    cpu.esp -= 4;
    sub_49eee3(app, cpu);
    if (cpu.terminate) return;
    // 004752c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752c6  a1dc515400             -mov eax, dword ptr [0x5451dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525980) /* 0x5451dc */);
    // 004752cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4752d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004752d0);
    // 004752d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004752d1  8b15e0515400           -mov edx, dword ptr [0x5451e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525984) /* 0x5451e0 */);
    // 004752d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004752d9  7502                   -jne 0x4752dd
    if (!cpu.flags.zf)
    {
        goto L_0x004752dd;
    }
    // 004752db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004752dd:
    // 004752dd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004752df  e86ca70000             -call 0x47fa50
    cpu.esp -= 4;
    sub_47fa50(app, cpu);
    if (cpu.terminate) return;
    // 004752e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4752f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004752f0);
    // 004752f0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004752f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475300);
    // 00475300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475302  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475303  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475304  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475305  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475308  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047530a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047530c:
    // 0047530c  8b9a30525400           -mov ebx, dword ptr [edx + 0x545230]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5526064) /* 0x545230 */);
    // 00475312  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475313  8bb22c525400           -mov esi, dword ptr [edx + 0x54522c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5526060) /* 0x54522c */);
    // 00475319  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047531a  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047531d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047531e  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00475320  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475321  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475325  e876aaffff             -call 0x46fda0
    cpu.esp -= 4;
    sub_46fda0(app, cpu);
    if (cpu.terminate) return;
    // 0047532a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047532c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047532e  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475331  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475332  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475333  81fa00010000           +cmp edx, 0x100
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
    // 00475339  75d1                   -jne 0x47530c
    if (!cpu.flags.zf)
    {
        goto L_0x0047530c;
    }
    // 0047533b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047533e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047533f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475340  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475341  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475342  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475343  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475350);
    // 00475350  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475351  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475352  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475353  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475356  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00475358:
    // 00475358  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047535a  e8f1aaffff             -call 0x46fe50
    cpu.esp -= 4;
    sub_46fe50(app, cpu);
    if (cpu.terminate) return;
    // 0047535f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475361  8dba2c525400           -lea edi, [edx + 0x54522c]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(5526060) /* 0x54522c */);
    // 00475367  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047536a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047536b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047536c  81fa00010000           +cmp edx, 0x100
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
    // 00475372  75e4                   -jne 0x475358
    if (!cpu.flags.zf)
    {
        goto L_0x00475358;
    }
    // 00475374  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475377  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475378  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475379  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047537a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475380);
    // 00475380  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475381  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475382  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475383  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475384  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00475387  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00475389  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047538b  895c2464               -mov dword ptr [esp + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 0047538f  83b8bc00000000         +cmp dword ptr [eax + 0xbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475396  0f85b4000000           -jne 0x475450
    if (!cpu.flags.zf)
    {
        goto L_0x00475450;
    }
L_0x0047539c:
    // 0047539c  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047539f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004753a1  747b                   -je 0x47541e
    if (cpu.flags.zf)
    {
        goto L_0x0047541e;
    }
    // 004753a3  8d5e50                 -lea ebx, [esi + 0x50]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004753a6  8d5150                 -lea edx, [ecx + 0x50]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 004753a9  8d4620                 -lea eax, [esi + 0x20]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004753ac  e88f940200             -call 0x49e840
    cpu.esp -= 4;
    sub_49e840(app, cpu);
    if (cpu.terminate) return;
    // 004753b1  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004753b4  8b9e80000000           -mov ebx, dword ptr [esi + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004753ba  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004753bc  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004753c0  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004753c3  8bae84000000           -mov ebp, dword ptr [esi + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004753c9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004753cb  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004753cf  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004753d2  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004753d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004753da  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004753de  8d5c2430               -lea ebx, [esp + 0x30]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004753e2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004753e5  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004753e9  83c250                 -add edx, 0x50
    (cpu.edx) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004753ec  e82fb30000             -call 0x480720
    cpu.esp -= 4;
    sub_480720(app, cpu);
    if (cpu.terminate) return;
    // 004753f1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004753f4  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004753f8  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004753fb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004753fd  895674                 -mov dword ptr [esi + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00475400  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00475403  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00475407  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 0047540a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047540c  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0047540f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00475412  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00475416  8b407c                 -mov eax, dword ptr [eax + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    // 00475419  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047541b  89567c                 -mov dword ptr [esi + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.edx;
L_0x0047541e:
    // 0047541e  833e01                 +cmp dword ptr [esi], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475421  7544                   -jne 0x475467
    if (!cpu.flags.zf)
    {
        goto L_0x00475467;
    }
    // 00475423  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00475426  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00475428  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047542a  7e1c                   -jle 0x475448
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475448;
    }
    // 0047542c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0047542e:
    // 0047542e  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00475432  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00475434  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00475437  e844ffffff             -call 0x475380
    cpu.esp -= 4;
    sub_475380(app, cpu);
    if (cpu.terminate) return;
    // 0047543c  45                     -inc ebp
    (cpu.ebp)++;
    // 0047543d  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00475440  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475443  39c5                   +cmp ebp, eax
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
    // 00475445  7ce7                   -jl 0x47542e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047542e;
    }
    // 00475447  90                     -nop 
    ;
L_0x00475448:
    // 00475448  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047544b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047544c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047544d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047544e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047544f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475450:
    // 00475450  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00475456  8b80c0000000           -mov eax, dword ptr [eax + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 0047545c  ff96bc000000           -call dword ptr [esi + 0xbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475462  e935ffffff             -jmp 0x47539c
    goto L_0x0047539c;
L_0x00475467:
    // 00475467  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0047546d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047546f  74d7                   -je 0x475448
    if (cpu.flags.zf)
    {
        goto L_0x00475448;
    }
    // 00475471  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00475473  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 00475477  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475479  7ecd                   -jle 0x475448
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475448;
    }
    // 0047547b  8d4650                 -lea eax, [esi + 0x50]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0047547e  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00475482  8d4744                 -lea eax, [edi + 0x44]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 00475485  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00475487  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0047548b:
    // 0047548b  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00475491  833800                 +cmp dword ptr [eax], 0
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
    // 00475494  740f                   -je 0x4754a5
    if (cpu.flags.zf)
    {
        goto L_0x004754a5;
    }
    // 00475496  833d88924d0000         +cmp dword ptr [0x4d9288], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083784) /* 0x4d9288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047549d  741e                   -je 0x4754bd
    if (cpu.flags.zf)
    {
        goto L_0x004754bd;
    }
    // 0047549f  80782000               +cmp byte ptr [eax + 0x20], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004754a3  7518                   -jne 0x4754bd
    if (!cpu.flags.zf)
    {
        goto L_0x004754bd;
    }
L_0x004754a5:
    // 004754a5  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004754a9  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004754ac  41                     -inc ecx
    (cpu.ecx)++;
    // 004754ad  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004754b3  894c246c               -mov dword ptr [esp + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 004754b7  39d9                   +cmp ecx, ebx
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
    // 004754b9  7d8d                   -jge 0x475448
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475448;
    }
    // 004754bb  ebce                   -jmp 0x47548b
    goto L_0x0047548b;
L_0x004754bd:
    // 004754bd  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 004754c3  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004754c6  81fb00000200           +cmp ebx, 0x20000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004754cc  0f85af000000           -jne 0x475581
    if (!cpu.flags.zf)
    {
        goto L_0x00475581;
    }
L_0x004754d2:
    // 004754d2  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 004754d5  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004754d8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004754da  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004754de  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004754e1  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004754e4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004754e6  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004754ea  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 004754ed  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004754f0  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004754f4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004754f6  8d5c2454               -lea ebx, [esp + 0x54]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004754fa  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004754fe  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00475502  e819b20000             -call 0x480720
    cpu.esp -= 4;
    sub_480720(app, cpu);
    if (cpu.terminate) return;
    // 00475507  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00475509  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047550d  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00475511  e82a930200             -call 0x49e840
    cpu.esp -= 4;
    sub_49e840(app, cpu);
    if (cpu.terminate) return;
    // 00475516  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 0047551c  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047551f  8b1580924d00           -mov edx, dword ptr [0x4d9280]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083776) /* 0x4d9280 */);
    // 00475525  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475528  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047552a  740c                   -je 0x475538
    if (cpu.flags.zf)
    {
        goto L_0x00475538;
    }
    // 0047552c  83f805                 +cmp eax, 5
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
    // 0047552f  7d07                   -jge 0x475538
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475538;
    }
    // 00475531  8b048508365100         -mov eax, dword ptr [eax*4 + 0x513608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322248) /* 0x513608 */ + cpu.eax * 4);
L_0x00475538:
    // 00475538  8b5674                 -mov edx, dword ptr [esi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 0047553b  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047553e  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475540  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00475544  8b5678                 -mov edx, dword ptr [esi + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00475547  2b570c                 -sub edx, dword ptr [edi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 0047554a  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0047554e  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00475552  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475553  8b567c                 -mov edx, dword ptr [esi + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00475556  8b4f10                 -mov ecx, dword ptr [edi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00475559  8b5c246c               -mov ebx, dword ptr [esp + 0x6c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0047555d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047555e  29ca                   +sub edx, ecx
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
    // 00475560  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00475564  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00475568  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0047556c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047556d  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475571  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00475577  e854a70000             -call 0x47fcd0
    cpu.esp -= 4;
    sub_47fcd0(app, cpu);
    if (cpu.terminate) return;
    // 0047557c  e924ffffff             -jmp 0x4754a5
    goto L_0x004754a5;
L_0x00475581:
    // 00475581  8b1524525400           -mov edx, dword ptr [0x545224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5526052) /* 0x545224 */);
    // 00475587  39da                   +cmp edx, ebx
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
    // 00475589  0f8e43ffffff           -jle 0x4754d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004754d2;
    }
    // 0047558f  3b5028                 +cmp edx, dword ptr [eax + 0x28]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475592  0f8d3affffff           -jge 0x4754d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004754d2;
    }
    // 00475598  8b1528525400           -mov edx, dword ptr [0x545228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5526056) /* 0x545228 */);
    // 0047559e  3b502c                 +cmp edx, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004755a1  0f8e2bffffff           -jle 0x4754d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004754d2;
    }
    // 004755a7  3b5030                 +cmp edx, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004755aa  0f8cf5feffff           -jl 0x4754a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004754a5;
    }
    // 004755b0  e91dffffff             -jmp 0x4754d2
    goto L_0x004754d2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4755c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004755c0);
    // 004755c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004755c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004755c2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004755c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004755c7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004755c9  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 004755ce  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004755d0  e8cba8ffff             -call 0x46fea0
    cpu.esp -= 4;
    sub_46fea0(app, cpu);
    if (cpu.terminate) return;
    // 004755d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004755d7  7508                   -jne 0x4755e1
    if (!cpu.flags.zf)
    {
        goto L_0x004755e1;
    }
L_0x004755d9:
    // 004755d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004755db  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004755de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004755df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004755e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004755e1:
    // 004755e1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004755e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004755e5  8d5138                 -lea edx, [ecx + 0x38]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004755e8  8d4144                 -lea eax, [ecx + 0x44]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 004755eb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004755ed  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004755f2  e899000000             -call 0x475690
    cpu.esp -= 4;
    sub_475690(app, cpu);
    if (cpu.terminate) return;
    // 004755f7  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 004755fc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475600  e89ba8ffff             -call 0x46fea0
    cpu.esp -= 4;
    sub_46fea0(app, cpu);
    if (cpu.terminate) return;
    // 00475605  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475607  74d0                   -je 0x4755d9
    if (cpu.flags.zf)
    {
        goto L_0x004755d9;
    }
    // 00475609  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047560d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00475613  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475617  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 0047561e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475622  8b15400f5000           -mov edx, dword ptr [0x500f40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246784) /* 0x500f40 */);
    // 00475628  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047562b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047562f  c74020ffffff8f         -mov dword ptr [eax + 0x20], 0x8fffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2415919103 /*0x8fffffff*/;
    // 00475636  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047563a  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 00475640  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475644  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0047564a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047564e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475651  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00475654  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475658  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047565b  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047565e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475661  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475665  0590000000             -add eax, 0x90
    (cpu.eax) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 0047566a  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047566d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475670  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475674  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475677  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047567a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047567e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475682  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475690);
    // 00475690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475692  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475693  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00475696  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047569a  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047569e  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004756a2  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004756a6  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004756a9  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004756ad  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004756b1:
    // 004756b1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004756b5  4a                     -dec edx
    (cpu.edx)--;
    // 004756b6  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004756ba  83faff                 +cmp edx, -1
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
    // 004756bd  7509                   -jne 0x4756c8
    if (!cpu.flags.zf)
    {
        goto L_0x004756c8;
    }
    // 004756bf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004756c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756c5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004756c8:
    // 004756c8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004756ca  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004756ce  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004756d2  e8f1930200             -call 0x49eac8
    cpu.esp -= 4;
    sub_49eac8(app, cpu);
    if (cpu.terminate) return;
    // 004756d7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004756db  81c300200000           -add ebx, 0x2000
    (cpu.ebx) += x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 004756e1  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004756e5  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004756e9  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004756ec  0330                   -add esi, dword ptr [eax]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 004756ee  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004756f2  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004756f5  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004756f8  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004756fb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004756ff  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00475703  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475707  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047570a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047570c  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00475710  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 00475713  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475717  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047571a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047571e  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00475724  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00475727  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047572b  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047572f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475731  7508                   -jne 0x47573b
    if (!cpu.flags.zf)
    {
        goto L_0x0047573b;
    }
    // 00475733  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0047573b:
    // 0047573b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047573f  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00475743  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475747  db442428               -fild dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 0047574b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047574f  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00475753  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00475755  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00475757  c1eb0f                 -shr ebx, 0xf
    cpu.ebx >>= 15 /*0xf*/ % 32;
    // 0047575a  81e1000080ff           -and ecx, 0xff800000
    cpu.ecx &= x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
    // 00475760  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00475766  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 00475768  8b1c9de4194f00         -mov ebx, dword ptr [ebx*4 + 0x4f19e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5183972) /* 0x4f19e4 */ + cpu.ebx * 4);
    // 0047576f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475771  891d141e4f00           -mov dword ptr [0x4f1e14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5185044) /* 0x4f1e14 */) = cpu.ebx;
    // 00475777  d80d141e4f00           -fmul dword ptr [0x4f1e14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5185044) /* 0x4f1e14 */));
    // 0047577d  d82dac524d00           -fsubr dword ptr [0x4d52ac]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5067436) /* 0x4d52ac */)) - cpu.fpu.st(0);
    // 00475783  d80d141e4f00           -fmul dword ptr [0x4f1e14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5185044) /* 0x4f1e14 */));
    // 00475789  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0047578b  d808                   -fmul dword ptr [eax]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax));
    // 0047578d  d82dac524d00           -fsubr dword ptr [0x4d52ac]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5067436) /* 0x4d52ac */)) - cpu.fpu.st(0);
    // 00475793  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00475795  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00475797  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047579b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047579d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047579f  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004757a2  d90594524d00           -fld dword ptr [0x4d5294]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5067412) /* 0x4d5294 */)));
    // 004757a8  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 004757aa  d90598524d00           -fld dword ptr [0x4d5298]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5067416) /* 0x4d5298 */)));
    // 004757b0  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 004757b2  d905b0524d00           -fld dword ptr [0x4d52b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5067440) /* 0x4d52b0 */)));
    // 004757b8  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 004757ba  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004757bd  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 004757bf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004757c1  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004757c3  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004757c5  d905a0524d00           -fld dword ptr [0x4d52a0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5067424) /* 0x4d52a0 */)));
    // 004757cb  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004757cd  d9059c524d00           -fld dword ptr [0x4d529c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5067420) /* 0x4d529c */)));
    // 004757d3  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004757d5  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004757d8  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004757db  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004757dd  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004757e0  8b0d041e4f00           -mov ecx, dword ptr [0x4f1e04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5185028) /* 0x4f1e04 */);
    // 004757e6  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004757eb  7558                   -jne 0x475845
    if (!cpu.flags.zf)
    {
        goto L_0x00475845;
    }
    // 004757ed  39c8                   +cmp eax, ecx
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
    // 004757ef  7d54                   -jge 0x475845
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475845;
    }
    // 004757f1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004757f4  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004757f9  8b0d101e4f00           -mov ecx, dword ptr [0x4f1e10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5185040) /* 0x4f1e10 */);
    // 004757ff  8b150c1e4f00           -mov edx, dword ptr [0x4f1e0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5185036) /* 0x4f1e0c */);
    // 00475805  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047580a  750d                   -jne 0x475819
    if (!cpu.flags.zf)
    {
        goto L_0x00475819;
    }
    // 0047580c  39c8                   +cmp eax, ecx
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
    // 0047580e  7c09                   -jl 0x475819
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475819;
    }
    // 00475810  39d0                   +cmp eax, edx
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
    // 00475812  7e09                   -jle 0x47581d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047581d;
    }
    // 00475814  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 00475817  eb04                   -jmp 0x47581d
    goto L_0x0047581d;
L_0x00475819:
    // 00475819  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047581c  90                     -nop 
    ;
L_0x0047581d:
    // 0047581d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047581f  90                     -nop 
    ;
    // 00475820  8b0d081e4f00           -mov ecx, dword ptr [0x4f1e08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5185032) /* 0x4f1e08 */);
    // 00475826  8b15181e4f00           -mov edx, dword ptr [0x4f1e18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5185048) /* 0x4f1e18 */);
    // 0047582c  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 00475831  750d                   -jne 0x475840
    if (!cpu.flags.zf)
    {
        goto L_0x00475840;
    }
    // 00475833  39c8                   +cmp eax, ecx
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
    // 00475835  7c09                   -jl 0x475840
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475840;
    }
    // 00475837  39d0                   +cmp eax, edx
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
    // 00475839  7e0f                   -jle 0x47584a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047584a;
    }
    // 0047583b  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0047583e  eb0a                   -jmp 0x47584a
    goto L_0x0047584a;
L_0x00475840:
    // 00475840  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 00475843  eb05                   -jmp 0x47584a
    goto L_0x0047584a;
L_0x00475845:
    // 00475845  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0047584a:
    // 0047584a  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0047584c  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00475851  7c24                   -jl 0x475877
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475877;
    }
    // 00475853  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00475855:
    // 00475855  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475859  6689450e               -mov word ptr [ebp + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0047585d  83c530                 -add ebp, 0x30
    (cpu.ebp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00475860  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475864  83c730                 -add edi, 0x30
    (cpu.edi) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00475867  83c00c                 +add eax, 0xc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047586a  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047586e  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00475872  e93afeffff             -jmp 0x4756b1
    goto L_0x004756b1;
L_0x00475877:
    // 00475877  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047587c  ebd7                   -jmp 0x475855
    goto L_0x00475855;
}

/* align: skip 0x00 0x00 */
void Application::sub_475880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475880);
    // 00475880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475881  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475882  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475885  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00475887  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0047588c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047588e  e80da6ffff             -call 0x46fea0
    cpu.esp -= 4;
    sub_46fea0(app, cpu);
    if (cpu.terminate) return;
    // 00475893  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475895  7506                   -jne 0x47589d
    if (!cpu.flags.zf)
    {
        goto L_0x0047589d;
    }
    // 00475897  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047589a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047589b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047589c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047589d:
    // 0047589d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004758a0  c740041a000000         -mov dword ptr [eax + 4], 0x1a
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 26 /*0x1a*/;
    // 004758a7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004758aa  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004758b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004758b3  885808                 -mov byte ptr [eax + 8], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 004758b6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004758b9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004758bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4758c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004758c0);
    // 004758c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004758c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004758c3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004758c8  e893000000             -call 0x475960
    cpu.esp -= 4;
    sub_475960(app, cpu);
    if (cpu.terminate) return;
    // 004758cd  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004758d0  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 004758d6  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 004758dc  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 004758e2  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004758e5  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 004758e9  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 004758ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4758f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004758f0);
    // 004758f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004758f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004758f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004758f8  e863000000             -call 0x475960
    cpu.esp -= 4;
    sub_475960(app, cpu);
    if (cpu.terminate) return;
    // 004758fd  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00475900  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 00475906  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 0047590c  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 00475912  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00475915  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 00475919  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 0047591c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047591d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_475920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475920);
    // 00475920  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475921  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475922  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475924  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00475926  8b808c000000           -mov eax, dword ptr [eax + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0047592c  89948190000000         -mov dword ptr [ecx + eax*4 + 0x90], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */ + cpu.eax * 4) = cpu.edx;
    // 00475933  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00475935  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00475937  e80489ffff             -call 0x46e240
    cpu.esp -= 4;
    sub_46e240(app, cpu);
    if (cpu.terminate) return;
    // 0047593c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047593f  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00475942  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00475945  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00475948  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047594b  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0047594e  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00475950  884620                 -mov byte ptr [esi + 0x20], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.al;
    // 00475953  ff818c000000           -inc dword ptr [ecx + 0x8c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */))++;
    // 00475959  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047595a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047595b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_475960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475960);
    // 00475960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475961  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475963  b8e0e24c00             -mov eax, 0x4ce2e0
    cpu.eax = 5038816 /*0x4ce2e0*/;
    // 00475968  e813000000             -call 0x475980
    cpu.esp -= 4;
    sub_475980(app, cpu);
    if (cpu.terminate) return;
    // 0047596d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00475974  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00475976  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475977  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475980);
    // 00475980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475981  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475982  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 00475987  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475989  e8f2000000             -call 0x475a80
    cpu.esp -= 4;
    sub_475a80(app, cpu);
    if (cpu.terminate) return;
    // 0047598e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475990  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00475993  c740e400000000         -mov dword ptr [eax - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 0047599a  c740e800000000         -mov dword ptr [eax - 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-24) /* -0x18 */) = 0 /*0x0*/;
    // 004759a1  c7406c00000000         -mov dword ptr [eax + 0x6c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 0 /*0x0*/;
    // 004759a8  c7809c00000000000000   -mov dword ptr [eax + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 004759b2  c780a000000000000000   -mov dword ptr [eax + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 004759bc  c780a400000000000000   -mov dword ptr [eax + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 004759c6  e83593feff             -call 0x45ed00
    cpu.esp -= 4;
    sub_45ed00(app, cpu);
    if (cpu.terminate) return;
    // 004759cb  8d4250                 -lea eax, [edx + 0x50]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004759ce  e82d93feff             -call 0x45ed00
    cpu.esp -= 4;
    sub_45ed00(app, cpu);
    if (cpu.terminate) return;
    // 004759d3  c7424400000000         -mov dword ptr [edx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004759da  c7424800000000         -mov dword ptr [edx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004759e1  c7424c00000000         -mov dword ptr [edx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004759e8  c7828000000000000000   -mov dword ptr [edx + 0x80], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 004759f2  c7828400000000000000   -mov dword ptr [edx + 0x84], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 004759fc  c7828800000000000000   -mov dword ptr [edx + 0x88], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 00475a06  c7427400000000         -mov dword ptr [edx + 0x74], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 00475a0d  c7427800000000         -mov dword ptr [edx + 0x78], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00475a14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475a16  c7427c00000000         -mov dword ptr [edx + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 00475a1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_475a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475a20);
    // 00475a20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475a21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475a22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475a23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475a24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475a25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475a26  8b1590964d00           -mov edx, dword ptr [0x4d9690]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084816) /* 0x4d9690 */);
    // 00475a2c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475a2e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475a30  7e22                   -jle 0x475a54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475a54;
    }
    // 00475a32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00475a34:
    // 00475a34  8bbae4515400           -mov edi, dword ptr [edx + 0x5451e4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525988) /* 0x5451e4 */);
    // 00475a3a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00475a3c  752b                   -jne 0x475a69
    if (!cpu.flags.zf)
    {
        goto L_0x00475a69;
    }
L_0x00475a3e:
    // 00475a3e  8b3590964d00           -mov esi, dword ptr [0x4d9690]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084816) /* 0x4d9690 */);
    // 00475a44  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475a47  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475a49  41                     -inc ecx
    (cpu.ecx)++;
    // 00475a4a  899ae0515400           -mov dword ptr [edx + 0x5451e0], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525984) /* 0x5451e0 */) = cpu.ebx;
    // 00475a50  39f1                   +cmp ecx, esi
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
    // 00475a52  7ce0                   -jl 0x475a34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475a34;
    }
L_0x00475a54:
    // 00475a54  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00475a56  892d90964d00           -mov dword ptr [0x4d9690], ebp
    app->getMemory<x86::reg32>(x86::reg32(5084816) /* 0x4d9690 */) = cpu.ebp;
    // 00475a5c  892d94964d00           -mov dword ptr [0x4d9694], ebp
    app->getMemory<x86::reg32>(x86::reg32(5084820) /* 0x4d9694 */) = cpu.ebp;
    // 00475a62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475a69:
    // 00475a69  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475a6b  e88cee0000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00475a70  ebcc                   -jmp 0x475a3e
    goto L_0x00475a3e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475a80);
    // 00475a80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475a81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475a82  8b0d94964d00           -mov ecx, dword ptr [0x4d9694]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084820) /* 0x4d9694 */);
    // 00475a88  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475a8a  7442                   -je 0x475ace
    if (cpu.flags.zf)
    {
        goto L_0x00475ace;
    }
    // 00475a8c  a190964d00             -mov eax, dword ptr [0x4d9690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084816) /* 0x4d9690 */);
    // 00475a91  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00475a98  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00475a9f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475aa1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00475aa4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475aa6  8b93e0515400           -mov edx, dword ptr [ebx + 0x5451e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5525984) /* 0x5451e0 */);
    // 00475aac  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00475aaf  41                     -inc ecx
    (cpu.ecx)++;
    // 00475ab0  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00475ab3  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00475ab8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00475aba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475abc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475abf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00475ac1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00475ac3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00475ac5  890d94964d00           -mov dword ptr [0x4d9694], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084820) /* 0x4d9694 */) = cpu.ecx;
    // 00475acb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475acc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475acd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475ace:
    // 00475ace  bab4e24c00             -mov edx, 0x4ce2b4
    cpu.edx = 5038772 /*0x4ce2b4*/;
    // 00475ad3  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00475ad8  b8d8e24c00             -mov eax, 0x4ce2d8
    cpu.eax = 5038808 /*0x4ce2d8*/;
    // 00475add  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 00475ae3  891ddcb14d00           -mov dword ptr [0x4db1dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebx;
    // 00475ae9  bad0070000             -mov edx, 0x7d0
    cpu.edx = 2000 /*0x7d0*/;
    // 00475aee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475af0  e8a3e90000             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00475af5  8b1590964d00           -mov edx, dword ptr [0x4d9690]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084816) /* 0x4d9690 */);
    // 00475afb  8b0d94964d00           -mov ecx, dword ptr [0x4d9694]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084820) /* 0x4d9694 */);
    // 00475b01  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00475b04  41                     -inc ecx
    (cpu.ecx)++;
    // 00475b05  890495e4515400         -mov dword ptr [edx*4 + 0x5451e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5525988) /* 0x5451e4 */ + cpu.edx * 4) = cpu.eax;
    // 00475b0c  893590964d00           -mov dword ptr [0x4d9690], esi
    app->getMemory<x86::reg32>(x86::reg32(5084816) /* 0x4d9690 */) = cpu.esi;
    // 00475b12  8b04b5e0515400         -mov eax, dword ptr [esi*4 + 0x5451e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525984) /* 0x5451e0 */ + cpu.esi * 4);
    // 00475b19  890d94964d00           -mov dword ptr [0x4d9694], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084820) /* 0x4d9694 */) = cpu.ecx;
    // 00475b1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475b30);
    // 00475b30  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
