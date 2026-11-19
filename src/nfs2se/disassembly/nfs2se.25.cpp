#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x90 */
void Application::sub_495098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495098  c1e302                 +shl ebx, 2
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
    // 0049509b  e90ce20000             -jmp 0x4a32ac
    return sub_4a32ac(app, cpu);
}

/* align: skip  */
void Application::sub_4950a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004950a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004950a1  b9d4c94c00             -mov ecx, 0x4cc9d4
    cpu.ecx = 5032404 /*0x4cc9d4*/;
    // 004950a6  e831200000             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004950ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004950ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4950b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004950b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004950b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004950b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004950b3  b9d4c94c00             -mov ecx, 0x4cc9d4
    cpu.ecx = 5032404 /*0x4cc9d4*/;
    // 004950b8  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004950bb  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004950be  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004950c1  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004950c4  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004950c7  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004950ca  e80d200000             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004950cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004950d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004950d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004950d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4950d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004950d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004950d5  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004950d8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004950db  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004950dd  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004950e0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004950e3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004950e5  b9d4c94c00             -mov ecx, 0x4cc9d4
    cpu.ecx = 5032404 /*0x4cc9d4*/;
    // 004950ea  e8ed1f0000             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004950ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004950f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4950f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004950f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004950f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004950f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004950f4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004950f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004950f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004950f9  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004950fb  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004950fe  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495104  f6410c01               +test byte ptr [ecx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 00495108  7523                   -jne 0x49512d
    if (!cpu.flags.zf)
    {
        goto L_0x0049512d;
    }
    // 0049510a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049510f  e8ec4f0000             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 00495114  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00495117  80ce20                 -or dh, 0x20
    cpu.dh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049511a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049511d  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 00495120  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495126  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00495128  e9c2010000             -jmp 0x4952ef
    goto L_0x004952ef;
L_0x0049512d:
    // 0049512d  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00495130  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00495132  7510                   -jne 0x495144
    if (!cpu.flags.zf)
    {
        goto L_0x00495144;
    }
    // 00495134  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00495137  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049513d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049513f  e9ab010000             -jmp 0x4952ef
    goto L_0x004952ef;
L_0x00495144:
    // 00495144  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00495147  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0049514b  7507                   -jne 0x495154
    if (!cpu.flags.zf)
    {
        goto L_0x00495154;
    }
    // 0049514d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049514f  e827df0000             -call 0x4a307b
    cpu.esp -= 4;
    sub_4a307b(app, cpu);
    if (cpu.terminate) return;
L_0x00495154:
    // 00495154  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00495156  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00495159  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049515d  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00495160  0f8401010000           -je 0x495267
    if (cpu.flags.zf)
    {
        goto L_0x00495267;
    }
    // 00495166  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x0049516a:
    // 0049516a  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049516d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049516f  7454                   -je 0x4951c5
    if (cpu.flags.zf)
    {
        goto L_0x004951c5;
    }
    // 00495171  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495175  39da                   +cmp edx, ebx
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
    // 00495177  7602                   -jbe 0x49517b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049517b;
    }
    // 00495179  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0049517b:
    // 0049517b  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049517f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00495181  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 00495184  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495188  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495189  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049518b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049518d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049518e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495190  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00495193  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00495195  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00495197  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049519a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049519c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049519d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049519e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004951a2  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004951a5  8d3417                 -lea esi, [edi + edx]
    cpu.esi = x86::reg32(cpu.edi + cpu.edx * 1);
    // 004951a8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004951aa  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004951ae  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004951b2  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004951b5  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004951b7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004951b9  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004951bb  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004951be  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004951c2  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
L_0x004951c5:
    // 004951c5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004951c9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004951cb  0f840a010000           -je 0x4952db
    if (cpu.flags.zf)
    {
        goto L_0x004952db;
    }
    // 004951d1  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004951d4  730a                   -jae 0x4951e0
    if (!cpu.flags.cf)
    {
        goto L_0x004951e0;
    }
    // 004951d6  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004951da  0f8473000000           -je 0x495253
    if (cpu.flags.zf)
    {
        goto L_0x00495253;
    }
L_0x004951e0:
    // 004951e0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004951e3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004951e6  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004951ed  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004951f1  8a4d0d                 -mov cl, byte ptr [ebp + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004951f4  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004951f7  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004951fa  750d                   -jne 0x495209
    if (!cpu.flags.zf)
    {
        goto L_0x00495209;
    }
    // 004951fc  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495202  7605                   -jbe 0x495209
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495209;
    }
    // 00495204  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00495206  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00495209:
    // 00495209  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049520d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00495210  e84c0a0100             -call 0x4a5c61
    cpu.esp -= 4;
    sub_4a5c61(app, cpu);
    if (cpu.terminate) return;
    // 00495215  83f8ff                 +cmp eax, -1
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
    // 00495218  7509                   -jne 0x495223
    if (!cpu.flags.zf)
    {
        goto L_0x00495223;
    }
    // 0049521a  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049521e  e9b8000000             -jmp 0x4952db
    goto L_0x004952db;
L_0x00495223:
    // 00495223  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495225  7509                   -jne 0x495230
    if (!cpu.flags.zf)
    {
        goto L_0x00495230;
    }
L_0x00495227:
    // 00495227  804d0c10               +or byte ptr [ebp + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049522b  e9ab000000             -jmp 0x4952db
    goto L_0x004952db;
L_0x00495230:
    // 00495230  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00495234  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495238  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049523c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049523e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00495240  01c1                   +add ecx, eax
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
    // 00495242  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00495246  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049524a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049524e  e917ffffff             -jmp 0x49516a
    goto L_0x0049516a;
L_0x00495253:
    // 00495253  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495255  e80a8a0000             -call 0x49dc64
    cpu.esp -= 4;
    sub_49dc64(app, cpu);
    if (cpu.terminate) return;
    // 0049525a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049525c  0f8479000000           -je 0x4952db
    if (cpu.flags.zf)
    {
        goto L_0x004952db;
    }
    // 00495262  e903ffffff             -jmp 0x49516a
    goto L_0x0049516a;
L_0x00495267:
    // 00495267  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049526b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049526d:
    // 0049526d  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495271  750b                   -jne 0x49527e
    if (!cpu.flags.zf)
    {
        goto L_0x0049527e;
    }
    // 00495273  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495275  e8ea890000             -call 0x49dc64
    cpu.esp -= 4;
    sub_49dc64(app, cpu);
    if (cpu.terminate) return;
    // 0049527a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049527c  745d                   -je 0x4952db
    if (cpu.flags.zf)
    {
        goto L_0x004952db;
    }
L_0x0049527e:
    // 0049527e  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00495281  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00495284  49                     -dec ecx
    (cpu.ecx)--;
    // 00495285  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495288  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049528b  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 0049528e  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00495290  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495295  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495298  7528                   -jne 0x4952c2
    if (!cpu.flags.zf)
    {
        goto L_0x004952c2;
    }
    // 0049529a  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049529e  750b                   -jne 0x4952ab
    if (!cpu.flags.zf)
    {
        goto L_0x004952ab;
    }
    // 004952a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004952a2  e8bd890000             -call 0x49dc64
    cpu.esp -= 4;
    sub_49dc64(app, cpu);
    if (cpu.terminate) return;
    // 004952a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004952a9  7430                   -je 0x4952db
    if (cpu.flags.zf)
    {
        goto L_0x004952db;
    }
L_0x004952ab:
    // 004952ab  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004952ae  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004952b1  4f                     -dec edi
    (cpu.edi)--;
    // 004952b2  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004952b5  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004952b8  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 004952bb  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004952bd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004952c2:
    // 004952c2  83f81a                 +cmp eax, 0x1a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004952c5  0f845cffffff           -je 0x495227
    if (cpu.flags.zf)
    {
        goto L_0x00495227;
    }
    // 004952cb  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004952cd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004952d1  40                     -inc eax
    (cpu.eax)++;
    // 004952d2  42                     -inc edx
    (cpu.edx)++;
    // 004952d3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004952d7  39da                   +cmp edx, ebx
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
    // 004952d9  7592                   -jne 0x49526d
    if (!cpu.flags.zf)
    {
        goto L_0x0049526d;
    }
L_0x004952db:
    // 004952db  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004952de  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004952e1  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004952e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004952e9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004952ed  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004952ef:
    // 004952ef  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004952f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004952f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004952f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004952f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495301  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495302  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495303  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495306  8b3500ca4c00           -mov esi, dword ptr [0x4cca00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */);
    // 0049530c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049530e  833d04ca4c0000         +cmp dword ptr [0x4cca04], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032452) /* 0x4cca04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495315  0f8466000000           -je 0x495381
    if (cpu.flags.zf)
    {
        goto L_0x00495381;
    }
L_0x0049531b:
    // 0049531b  8b3d04ca4c00           -mov edi, dword ptr [0x4cca04]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032452) /* 0x4cca04 */);
    // 00495321  8b3500ca4c00           -mov esi, dword ptr [0x4cca00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */);
    // 00495327  39fa                   +cmp edx, edi
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
    // 00495329  7e02                   -jle 0x49532d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049532d;
    }
    // 0049532b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0049532d:
    // 0049532d  39f2                   +cmp edx, esi
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
    // 0049532f  7c43                   -jl 0x495374
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495374;
    }
    // 00495331  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 00495334  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00495337  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00495339  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049533a  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0049533c  21fb                   -and ebx, edi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.edi));
    // 0049533e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495340  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495342  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00495344  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495346  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495348  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049534b  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049534d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049534f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00495352  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495354  7e1e                   -jle 0x495374
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495374;
    }
L_0x00495356:
    // 00495356  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495358  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049535a  39cb                   +cmp ebx, ecx
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
    // 0049535c  720c                   -jb 0x49536a
    if (cpu.flags.cf)
    {
        goto L_0x0049536a;
    }
L_0x0049535e:
    // 0049535e  40                     -inc eax
    (cpu.eax)++;
    // 0049535f  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00495361  83f820                 +cmp eax, 0x20
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
    // 00495364  7d04                   -jge 0x49536a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049536a;
    }
    // 00495366  39ca                   +cmp edx, ecx
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
    // 00495368  73f4                   -jae 0x49535e
    if (!cpu.flags.cf)
    {
        goto L_0x0049535e;
    }
L_0x0049536a:
    // 0049536a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049536d  47                     -inc edi
    (cpu.edi)++;
    // 0049536e  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495370  39c7                   +cmp edi, eax
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
    // 00495372  7ce2                   -jl 0x495356
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495356;
    }
L_0x00495374:
    // 00495374  893500ca4c00           -mov dword ptr [0x4cca00], esi
    app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */) = cpu.esi;
    // 0049537a  83c404                 +add esp, 4
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
    // 0049537d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049537e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049537f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495380  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495381:
    // 00495381  e89e2e0000             -call 0x498224
    cpu.esp -= 4;
    sub_498224(app, cpu);
    if (cpu.terminate) return;
    // 00495386  a304ca4c00             -mov dword ptr [0x4cca04], eax
    app->getMemory<x86::reg32>(x86::reg32(5032452) /* 0x4cca04 */) = cpu.eax;
    // 0049538b  eb8e                   -jmp 0x49531b
    goto L_0x0049531b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495391  8b1598a64c00           -mov edx, dword ptr [0x4ca698]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 00495397  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495399  7502                   -jne 0x49539d
    if (!cpu.flags.zf)
    {
        goto L_0x0049539d;
    }
    // 0049539b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049539c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049539d:
    // 0049539d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049539e  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004953a3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004953a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004953a6  2eff15c4754b00         -call dword ptr cs:[0x4b75c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945348) /* 0x4b75c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004953ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004953af  890d98a64c00           -mov dword ptr [0x4ca698], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */) = cpu.ecx;
    // 004953b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004953b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4953b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004953b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004953b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004953ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004953bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004953bc  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004953bf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004953c1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004953c3  e828270000             -call 0x497af0
    cpu.esp -= 4;
    sub_497af0(app, cpu);
    if (cpu.terminate) return;
    // 004953c8  a370d95100             -mov dword ptr [0x51d970], eax
    app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */) = cpu.eax;
    // 004953cd  e83e270000             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 004953d2  833d00ca4c0000         +cmp dword ptr [0x4cca00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953d9  0f84db000000           -je 0x4954ba
    if (cpu.flags.zf)
    {
        goto L_0x004954ba;
    }
L_0x004953df:
    // 004953df  e81c2e0000             -call 0x498200
    cpu.esp -= 4;
    sub_498200(app, cpu);
    if (cpu.terminate) return;
    // 004953e4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004953e6  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004953e8  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004953ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004953ee  0f85de000000           -jne 0x4954d2
    if (!cpu.flags.zf)
    {
        goto L_0x004954d2;
    }
L_0x004953f4:
    // 004953f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004953f6  891d98a64c00           -mov dword ptr [0x4ca698], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */) = cpu.ebx;
    // 004953fc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004953fe:
    // 004953fe  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00495402  e83d010000             -call 0x495544
    cpu.esp -= 4;
    sub_495544(app, cpu);
    if (cpu.terminate) return;
    // 00495407  a398a64c00             -mov dword ptr [0x4ca698], eax
    app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */) = cpu.eax;
    // 0049540c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049540e  751a                   -jne 0x49542a
    if (!cpu.flags.zf)
    {
        goto L_0x0049542a;
    }
    // 00495410  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00495414  81fe00000800           +cmp esi, 0x80000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049541a  0f8c92000000           -jl 0x4954b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004954b2;
    }
    // 00495420  8dae0000f8ff           -lea ebp, [esi - 0x80000]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-524288) /* -0x80000 */);
    // 00495426  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
L_0x0049542a:
    // 0049542a  a198a64c00             -mov eax, dword ptr [0x4ca698]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 0049542f  39c1                   +cmp ecx, eax
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
    // 00495431  74cb                   -je 0x4953fe
    if (cpu.flags.zf)
    {
        goto L_0x004953fe;
    }
    // 00495433  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495435  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00495439  8d2cbd00000000         -lea ebp, [edi*4]
    cpu.ebp = x86::reg32(cpu.edi * 4);
    // 00495440  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00495442  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00495444  a394a64c00             -mov dword ptr [0x4ca694], eax
    app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */) = cpu.eax;
    // 00495449  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049544b  e88056feff             -call 0x47aad0
    cpu.esp -= 4;
    sub_47aad0(app, cpu);
    if (cpu.terminate) return;
    // 00495450  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00495452  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495454  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00495456  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 00495459  b890114c00             -mov eax, 0x4c1190
    cpu.eax = 4985232 /*0x4c1190*/;
    // 0049545e  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00495460  8b0d94a64c00           -mov ecx, dword ptr [0x4ca694]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */);
    // 00495466  8b1d98a64c00           -mov ebx, dword ptr [0x4ca698]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 0049546c  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0049546e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495470  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495472  e8a54cfeff             -call 0x47a11c
    cpu.esp -= 4;
    sub_47a11c(app, cpu);
    if (cpu.terminate) return;
    // 00495477  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00495479  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049547b  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00495480  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 00495485  b898114c00             -mov eax, 0x4c1198
    cpu.eax = 4985240 /*0x4c1198*/;
    // 0049548a  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0049548f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495491  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495493  e8844cfeff             -call 0x47a11c
    cpu.esp -= 4;
    sub_47a11c(app, cpu);
    if (cpu.terminate) return;
    // 00495498  8b0d94a64c00           -mov ecx, dword ptr [0x4ca694]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */);
    // 0049549e  8b1598a64c00           -mov edx, dword ptr [0x4ca698]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 004954a4  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 004954a9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004954ab  e868260000             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 004954b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004954b2:
    // 004954b2  83c428                 +add esp, 0x28
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
    // 004954b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004954b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004954ba:
    // 004954ba  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004954bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004954bd  2eff1518754b00         -call dword ptr cs:[0x4b7518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945176) /* 0x4b7518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004954c4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004954c8  a300ca4c00             -mov dword ptr [0x4cca00], eax
    app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */) = cpu.eax;
    // 004954cd  e90dffffff             -jmp 0x4953df
    goto L_0x004953df;
L_0x004954d2:
    // 004954d2  39c6                   +cmp esi, eax
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
    // 004954d4  0f8d1affffff           -jge 0x4953f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004953f4;
    }
    // 004954da  6683e6f0               +and si, 0xfff0
    cpu.clear_co();
    cpu.set_szp((cpu.si &= x86::reg16(x86::sreg16(65520 /*0xfff0*/))));
    // 004954de  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004954e2  e90dffffff             -jmp 0x4953f4
    goto L_0x004953f4;
}

/* align: skip 0x90 */
void Application::sub_4954e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004954e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004954e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004954ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004954eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004954ec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004954ee  e8792d0000             -call 0x49826c
    cpu.esp -= 4;
    sub_49826c(app, cpu);
    if (cpu.terminate) return;
    // 004954f3  8b1df8c94c00           -mov ebx, dword ptr [0x4cc9f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032440) /* 0x4cc9f8 */);
    // 004954f9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004954fb  39d8                   +cmp eax, ebx
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
    // 004954fd  771a                   -ja 0x495519
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00495519;
    }
    // 004954ff  8b35fcc94c00           -mov esi, dword ptr [0x4cc9fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032444) /* 0x4cc9fc */);
    // 00495505  39f0                   +cmp eax, esi
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
    // 00495507  7302                   -jae 0x49550b
    if (!cpu.flags.cf)
    {
        goto L_0x0049550b;
    }
    // 00495509  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0049550b:
    // 0049550b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049550d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049550f  e8a4feffff             -call 0x4953b8
    cpu.esp -= 4;
    sub_4953b8(app, cpu);
    if (cpu.terminate) return;
    // 00495514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495515  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495516  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495517  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495518  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495519:
    // 00495519  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049551b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049551d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049551f  e894feffff             -call 0x4953b8
    cpu.esp -= 4;
    sub_4953b8(app, cpu);
    if (cpu.terminate) return;
    // 00495524  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495525  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495526  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495527  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495528  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49552c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049552c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049552d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049552f  e884feffff             -call 0x4953b8
    cpu.esp -= 4;
    sub_4953b8(app, cpu);
    if (cpu.terminate) return;
    // 00495534  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495535  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495538  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495539  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049553b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049553d  e876feffff             -call 0x4953b8
    cpu.esp -= 4;
    sub_4953b8(app, cpu);
    if (cpu.terminate) return;
    // 00495542  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495543  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495544(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495545  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495546  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495547  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495548  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495549  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049554c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049554e  8b1500ca4c00           -mov edx, dword ptr [0x4cca00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */);
    // 00495554  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00495556  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00495558  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049555a  7435                   -je 0x495591
    if (cpu.flags.zf)
    {
        goto L_0x00495591;
    }
L_0x0049555c:
    // 0049555c  8b0d00ca4c00           -mov ecx, dword ptr [0x4cca00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */);
    // 00495562  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00495564  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495566  4a                     -dec edx
    (cpu.edx)--;
    // 00495567  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495569  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049556c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049556e  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00495571  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00495573  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 00495578  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049557a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049557c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049557d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049557f  2eff15c0754b00         -call dword ptr cs:[0x4b75c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945344) /* 0x4b75c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495586  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495588  83c424                 +add esp, 0x24
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049558b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049558c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049558d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049558e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049558f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495590  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495591:
    // 00495591  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00495593  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495594  2eff1518754b00         -call dword ptr cs:[0x4b7518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945176) /* 0x4b7518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049559b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049559f  a300ca4c00             -mov dword ptr [0x4cca00], eax
    app->getMemory<x86::reg32>(x86::reg32(5032448) /* 0x4cca00 */) = cpu.eax;
    // 004955a4  ebb6                   -jmp 0x49555c
    goto L_0x0049555c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4955a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004955a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004955a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004955aa  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004955af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004955b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004955b2  2eff15c4754b00         -call dword ptr cs:[0x4b75c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945348) /* 0x4b75c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004955b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4955c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004955c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004955c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004955c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004955c4  e83fb1feff             -call 0x480708
    cpu.esp -= 4;
    sub_480708(app, cpu);
    if (cpu.terminate) return;
    // 004955c9  833d98a64c0000         +cmp dword ptr [0x4ca698], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004955d0  742b                   -je 0x4955fd
    if (cpu.flags.zf)
    {
        goto L_0x004955fd;
    }
L_0x004955d2:
    // 004955d2  833db0a34c0000         +cmp dword ptr [0x4ca3b0], 0
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
    // 004955d9  7516                   -jne 0x4955f1
    if (!cpu.flags.zf)
    {
        goto L_0x004955f1;
    }
    // 004955db  8b1dd8a34c00           -mov ebx, dword ptr [0x4ca3d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 004955e1  8b15d4a34c00           -mov edx, dword ptr [0x4ca3d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022676) /* 0x4ca3d4 */);
    // 004955e7  a1d0a34c00             -mov eax, dword ptr [0x4ca3d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022672) /* 0x4ca3d0 */);
    // 004955ec  e8e390feff             -call 0x47e6d4
    cpu.esp -= 4;
    sub_47e6d4(app, cpu);
    if (cpu.terminate) return;
L_0x004955f1:
    // 004955f1  833db0a34c0000         +cmp dword ptr [0x4ca3b0], 0
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
    // 004955f8  750f                   -jne 0x495609
    if (!cpu.flags.zf)
    {
        goto L_0x00495609;
    }
    // 004955fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004955fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004955fd:
    // 004955fd  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 00495602  e8e1feffff             -call 0x4954e8
    cpu.esp -= 4;
    sub_4954e8(app, cpu);
    if (cpu.terminate) return;
    // 00495607  ebc9                   -jmp 0x4955d2
    goto L_0x004955d2;
L_0x00495609:
    // 00495609  bb50d14c00             -mov ebx, 0x4cd150
    cpu.ebx = 5034320 /*0x4cd150*/;
    // 0049560e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00495613  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495615  e83ec7ffff             -call 0x491d58
    cpu.esp -= 4;
    sub_491d58(app, cpu);
    if (cpu.terminate) return;
    // 0049561a  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0049561f  e88443feff             -call 0x4799a8
    cpu.esp -= 4;
    sub_4799a8(app, cpu);
    if (cpu.terminate) return;
    // 00495624  e8c77cfeff             -call 0x47d2f0
    cpu.esp -= 4;
    sub_47d2f0(app, cpu);
    if (cpu.terminate) return;
    // 00495629  e8e67efeff             -call 0x47d514
    cpu.esp -= 4;
    sub_47d514(app, cpu);
    if (cpu.terminate) return;
    // 0049562e  e8cd060100             -call 0x4a5d00
    cpu.esp -= 4;
    sub_4a5d00(app, cpu);
    if (cpu.terminate) return;
    // 00495633  b8d8ec4c00             -mov eax, 0x4cecd8
    cpu.eax = 5041368 /*0x4cecd8*/;
    // 00495638  e84373feff             -call 0x47c980
    cpu.esp -= 4;
    sub_47c980(app, cpu);
    if (cpu.terminate) return;
    // 0049563d  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00495642  e8d52afeff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00495647  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495649  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049564e  e8c92afeff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00495653  e8e869feff             -call 0x47c040
    cpu.esp -= 4;
    sub_47c040(app, cpu);
    if (cpu.terminate) return;
    // 00495658  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049565f  7505                   -jne 0x495666
    if (!cpu.flags.zf)
    {
        goto L_0x00495666;
    }
    // 00495661  e8fadef8ff             -call 0x423560
    cpu.esp -= 4;
    sub_423560(app, cpu);
    if (cpu.terminate) return;
L_0x00495666:
    // 00495666  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495667  e894090000             -call 0x496000
    cpu.esp -= 4;
    sub_496000(app, cpu);
    if (cpu.terminate) return;
    // 0049566c  e89784feff             -call 0x47db08
    cpu.esp -= 4;
    sub_47db08(app, cpu);
    if (cpu.terminate) return;
    // 00495671  e8ea060100             -call 0x4a5d60
    cpu.esp -= 4;
    sub_4a5d60(app, cpu);
    if (cpu.terminate) return;
    // 00495676  b890604900             -mov eax, 0x496090
    cpu.eax = 4808848 /*0x496090*/;
    // 0049567b  e8100a0000             -call 0x496090
    cpu.esp -= 4;
    sub_496090(app, cpu);
    if (cpu.terminate) return;
    // 00495680  b864da4700             -mov eax, 0x47da64
    cpu.eax = 4708964 /*0x47da64*/;
    // 00495685  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0049568a  e8e583feff             -call 0x47da74
    cpu.esp -= 4;
    sub_47da74(app, cpu);
    if (cpu.terminate) return;
    // 0049568f  e81c070100             -call 0x4a5db0
    cpu.esp -= 4;
    sub_4a5db0(app, cpu);
    if (cpu.terminate) return;
    // 00495694  e873080100             -call 0x4a5f0c
    cpu.esp -= 4;
    sub_4a5f0c(app, cpu);
    if (cpu.terminate) return;
    // 00495699  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 0049569e  8b0dd4a34c00           -mov ecx, dword ptr [0x4ca3d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022676) /* 0x4ca3d4 */);
    // 004956a4  8b1dd0a34c00           -mov ebx, dword ptr [0x4ca3d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022672) /* 0x4ca3d0 */);
    // 004956aa  e8e5c9ffff             -call 0x492094
    cpu.esp -= 4;
    sub_492094(app, cpu);
    if (cpu.terminate) return;
    // 004956af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004956b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004956b3  e878c8ffff             -call 0x491f30
    cpu.esp -= 4;
    sub_491f30(app, cpu);
    if (cpu.terminate) return;
    // 004956b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4956c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004956c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004956c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004956c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004956c3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004956c5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004956c7  e8043efbff             -call 0x4494d0
    cpu.esp -= 4;
    sub_4494d0(app, cpu);
    if (cpu.terminate) return;
    // 004956cc  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004956ce  49                     -dec ecx
    (cpu.ecx)--;
    // 004956cf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004956d1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004956d3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004956d5  49                     -dec ecx
    (cpu.ecx)--;
    // 004956d6  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004956d8  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004956da  4b                     -dec ebx
    (cpu.ebx)--;
    // 004956db  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004956dd  49                     -dec ecx
    (cpu.ecx)--;
    // 004956de  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004956e0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004956e2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004956e4  49                     -dec ecx
    (cpu.ecx)--;
    // 004956e5  39d9                   +cmp ecx, ebx
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
    // 004956e7  7606                   -jbe 0x4956ef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004956ef;
    }
    // 004956e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004956eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004956ef:
    // 004956ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004956f0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004956f2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004956f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004956f5  2bc9                   +sub ecx, ecx
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
    // 004956f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004956f8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004956fa  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004956fc  4f                     -dec edi
    (cpu.edi)--;
L_0x004956fd:
    // 004956fd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004956ff  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00495701  3c00                   +cmp al, 0
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
    // 00495703  7410                   -je 0x495715
    if (cpu.flags.zf)
    {
        goto L_0x00495715;
    }
    // 00495705  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00495708  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049570b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049570e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00495711  3c00                   +cmp al, 0
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
    // 00495713  75e8                   -jne 0x4956fd
    if (!cpu.flags.zf)
    {
        goto L_0x004956fd;
    }
L_0x00495715:
    // 00495715  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495716  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049571b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049571c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049571d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049571e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049571f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495720  8078013a               +cmp byte ptr [eax + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495724  7406                   -je 0x49572c
    if (cpu.flags.zf)
    {
        goto L_0x0049572c;
    }
    // 00495726  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049572b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049572c:
    // 0049572c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049572d  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049572f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495734  8d509f                 -lea edx, [eax - 0x61]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-97) /* -0x61 */);
    // 00495737  83fa1a                 +cmp edx, 0x1a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049573a  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049573c  83e220                 -and edx, 0x20
    cpu.edx &= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049573f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00495741  83e841                 -sub eax, 0x41
    (cpu.eax) -= x86::reg32(x86::sreg32(65 /*0x41*/));
    // 00495744  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495745  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495748(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495748  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495749  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049574a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049574b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049574c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049574f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495751  bea0114c00             -mov esi, 0x4c11a0
    cpu.esi = 4985248 /*0x4c11a0*/;
    // 00495756  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00495758  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00495759:
    // 00495759  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049575b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049575d  3c00                   +cmp al, 0
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
    // 0049575f  7410                   -je 0x495771
    if (cpu.flags.zf)
    {
        goto L_0x00495771;
    }
    // 00495761  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00495764  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00495767  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049576a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049576d  3c00                   +cmp al, 0
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
    // 0049576f  75e8                   -jne 0x495759
    if (!cpu.flags.zf)
    {
        goto L_0x00495759;
    }
L_0x00495771:
    // 00495771  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495772  001424                 -add byte ptr [esp], dl
    (app->getMemory<x86::reg8>(cpu.esp)) += x86::reg8(x86::sreg8(cpu.dl));
    // 00495775  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00495777  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495778  2eff15d4744b00         -call dword ptr cs:[0x4b74d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945108) /* 0x4b74d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049577f  83f805                 +cmp eax, 5
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
    // 00495782  750d                   -jne 0x495791
    if (!cpu.flags.zf)
    {
        goto L_0x00495791;
    }
    // 00495784  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495789  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049578c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049578d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049578e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049578f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495790  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495791:
    // 00495791  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495793  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495796  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495797  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495798  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495799  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049579a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49579c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049579c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049579e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004957a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4957a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004957a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004957a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004957a3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004957a4  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004957a6  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004957a8  c8080000               -enter 8, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 8;
    }
    // 004957ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004957ae  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004957b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004957b2  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004957b5  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004957b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004957ba  744f                   -je 0x49580b
    if (cpu.flags.zf)
    {
        goto L_0x0049580b;
    }
    // 004957bc  48                     -dec eax
    (cpu.eax)--;
    // 004957bd  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004957c0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004957c2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004957c4  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x004957c7:
    // 004957c7  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004957ca  732c                   -jae 0x4957f8
    if (!cpu.flags.cf)
    {
        goto L_0x004957f8;
    }
    // 004957cc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004957cf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004957d1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004957d3  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004957d5  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004957d7  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004957da  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004957dd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004957df  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004957e1  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004957e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004957e6  7504                   -jne 0x4957ec
    if (!cpu.flags.zf)
    {
        goto L_0x004957ec;
    }
    // 004957e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004957ea  eb1f                   -jmp 0x49580b
    goto L_0x0049580b;
L_0x004957ec:
    // 004957ec  7d05                   -jge 0x4957f3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004957f3;
    }
    // 004957ee  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004957f1  ebd4                   -jmp 0x4957c7
    goto L_0x004957c7;
L_0x004957f3:
    // 004957f3  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 004957f6  ebcf                   -jmp 0x4957c7
    goto L_0x004957c7;
L_0x004957f8:
    // 004957f8  750f                   -jne 0x495809
    if (!cpu.flags.zf)
    {
        goto L_0x00495809;
    }
    // 004957fa  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004957fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004957fe  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495801  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495803  7504                   -jne 0x495809
    if (!cpu.flags.zf)
    {
        goto L_0x00495809;
    }
    // 00495805  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495807  eb02                   -jmp 0x49580b
    goto L_0x0049580b;
L_0x00495809:
    // 00495809  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049580b:
    // 0049580b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049580c  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049580e  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495810  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495811  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495812  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495813  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_495816(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495816  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495817  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495818  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495819  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049581b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049581d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049581f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00495821  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495823  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495825  7e1c                   -jle 0x495843
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495843;
    }
    // 00495827  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495829  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049582b  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049582d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049582f  7e0e                   -jle 0x49583f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049583f;
    }
    // 00495831  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495833  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495835  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495837  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495839  7f1c                   -jg 0x495857
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495857;
    }
L_0x0049583b:
    // 0049583b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049583d  eb1a                   -jmp 0x495859
    goto L_0x00495859;
L_0x0049583f:
    // 0049583f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495841  eb16                   -jmp 0x495859
    goto L_0x00495859;
L_0x00495843:
    // 00495843  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495845  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495847  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495849  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049584b  7df2                   -jge 0x49583f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049583f;
    }
    // 0049584d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049584f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495851  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495853  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495855  7fe4                   -jg 0x49583b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049583b;
    }
L_0x00495857:
    // 00495857  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495859:
    // 00495859  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049585b  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049585d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049585e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049585f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495859(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495859;
    // 00495816  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495817  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495818  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495819  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049581b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049581d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049581f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00495821  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495823  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495825  7e1c                   -jle 0x495843
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495843;
    }
    // 00495827  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495829  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049582b  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049582d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049582f  7e0e                   -jle 0x49583f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049583f;
    }
    // 00495831  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495833  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495835  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495837  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495839  7f1c                   -jg 0x495857
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495857;
    }
L_0x0049583b:
    // 0049583b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049583d  eb1a                   -jmp 0x495859
    goto L_0x00495859;
L_0x0049583f:
    // 0049583f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495841  eb16                   -jmp 0x495859
    goto L_0x00495859;
L_0x00495843:
    // 00495843  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495845  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495847  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495849  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049584b  7df2                   -jge 0x49583f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049583f;
    }
    // 0049584d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049584f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495851  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495853  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495855  7fe4                   -jg 0x49583b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049583b;
    }
L_0x00495857:
    // 00495857  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495859:
L_entry_0x00495859:
    // 00495859  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049585b  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049585d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049585e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049585f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495861(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495861  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495862  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00495863  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495864  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 00495867  c1e902                 +shr ecx, 2
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
    // 0049586a  740b                   -je 0x495877
    if (cpu.flags.zf)
    {
        goto L_0x00495877;
    }
L_0x0049586c:
    // 0049586c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049586e  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 00495870  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00495871  83c604                 +add esi, 4
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
    // 00495874  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495875  75f5                   -jne 0x49586c
    if (!cpu.flags.zf)
    {
        goto L_0x0049586c;
    }
L_0x00495877:
    // 00495877  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049587a  7409                   -je 0x495885
    if (cpu.flags.zf)
    {
        goto L_0x00495885;
    }
L_0x0049587c:
    // 0049587c  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049587e  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 00495880  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00495881  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00495882  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495883  75f7                   -jne 0x49587c
    if (!cpu.flags.zf)
    {
        goto L_0x0049587c;
    }
L_0x00495885:
    // 00495885  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495886  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495887(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495887  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495888  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495889  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049588a  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049588c  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049588e  c84c0100               -enter 0x14c, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 332;
    }
    // 00495892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495893  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495894  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00495897  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495899  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0049589c  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0049589e  7407                   -je 0x4958a7
    if (cpu.flags.zf)
    {
        goto L_0x004958a7;
    }
    // 004958a0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004958a5  eb09                   -jmp 0x4958b0
    goto L_0x004958b0;
L_0x004958a7:
    // 004958a7  83fb04                 +cmp ebx, 4
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
    // 004958aa  0f97c0                 -seta al
    cpu.al = (!cpu.flags.cf && !cpu.flags.zf);
    // 004958ad  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
L_0x004958b0:
    // 004958b0  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004958b3  6b85acfeffff03         -imul eax, dword ptr [ebp - 0x154], 3
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 004958ba  8945c4                 -mov dword ptr [ebp - 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.eax;
    // 004958bd  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004958c3  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004958c5  c745e400000000         -mov dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 004958cc  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
L_0x004958cf:
    // 004958cf  83bdb0feffff01         +cmp dword ptr [ebp - 0x150], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958d6  0f8688000000           -jbe 0x495964
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495964;
    }
    // 004958dc  83bdb0feffff10         +cmp dword ptr [ebp - 0x150], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958e3  0f83a7000000           -jae 0x495990
    if (!cpu.flags.cf)
    {
        goto L_0x00495990;
    }
    // 004958e9  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004958ec  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004958ef  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004958f5  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004958fc  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004958ff  01c2                   +add edx, eax
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
    // 00495901  8955c0                 -mov dword ptr [ebp - 0x40], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edx;
    // 00495904  eb58                   -jmp 0x49595e
    goto L_0x0049595e;
L_0x00495906:
    // 00495906  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495909  0345e0                 +add eax, dword ptr [ebp - 0x20]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049590c  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0049590f  eb3f                   -jmp 0x495950
    goto L_0x00495950;
L_0x00495911:
    // 00495911  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495913  eb20                   -jmp 0x495935
    goto L_0x00495935;
L_0x00495915:
    // 00495915  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495919  740f                   -je 0x49592a
    if (cpu.flags.zf)
    {
        goto L_0x0049592a;
    }
    // 0049591b  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495921  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495923  e839ffffff             -call 0x495861
    cpu.esp -= 4;
    sub_495861(app, cpu);
    if (cpu.terminate) return;
    // 00495928  eb08                   -jmp 0x495932
    goto L_0x00495932;
L_0x0049592a:
    // 0049592a  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049592c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049592e  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00495930  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00495932:
    // 00495932  2b5de0                 -sub ebx, dword ptr [ebp - 0x20]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
L_0x00495935:
    // 00495935  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495938  7610                   -jbe 0x49594a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049594a;
    }
    // 0049593a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049593c  2b7de0                 -sub edi, dword ptr [ebp - 0x20]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 0049593f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495941  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495943  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495946  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495948  7fcb                   -jg 0x495915
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495915;
    }
L_0x0049594a:
    // 0049594a  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049594d  0145d4                 -add dword ptr [ebp - 0x2c], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00495950:
    // 00495950  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00495953  3b45c0                 +cmp eax, dword ptr [ebp - 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495956  72b9                   -jb 0x495911
    if (cpu.flags.cf)
    {
        goto L_0x00495911;
    }
    // 00495958  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049595b  2945e0                 -sub dword ptr [ebp - 0x20], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049595e:
    // 0049595e  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495962  7fa2                   -jg 0x495906
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495906;
    }
L_0x00495964:
    // 00495964  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00495968  0f843e030000           -je 0x495cac
    if (cpu.flags.zf)
    {
        goto L_0x00495cac;
    }
    // 0049596e  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495971  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00495974  8b9485b4feffff         -mov edx, dword ptr [ebp + eax*4 - 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-332) /* -0x14c */ + cpu.eax * 4);
    // 0049597b  8b848534ffffff         -mov eax, dword ptr [ebp + eax*4 - 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-204) /* -0xcc */ + cpu.eax * 4);
    // 00495982  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00495985  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 0049598b  e93fffffff             -jmp 0x4958cf
    goto L_0x004958cf;
L_0x00495990:
    // 00495990  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 00495996  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 00495998  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049599f  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004959a2  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004959a4  83bdb0feffff1d         +cmp dword ptr [ebp - 0x150], 0x1d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004959ab  0f8693000000           -jbe 0x495a44
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495a44;
    }
    // 004959b1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004959b4  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 004959b7  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004959bd  48                     -dec eax
    (cpu.eax)--;
    // 004959be  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004959c5  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004959c8  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004959ca  83bdb0feffff2a         +cmp dword ptr [ebp - 0x150], 0x2a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004959d1  7660                   -jbe 0x495a33
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495a33;
    }
    // 004959d3  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004959d9  8b95acfeffff           -mov edx, dword ptr [ebp - 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004959df  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004959e2  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004959e5  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004959e8  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 004959eb  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004959ee  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004959f1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004959f4  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004959f7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004959f9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004959fc  0355d8                 -add edx, dword ptr [ebp - 0x28]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004959ff  e812feffff             -call 0x495816
    cpu.esp -= 4;
    sub_495816(app, cpu);
    if (cpu.terminate) return;
    // 00495a04  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00495a07  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00495a0a  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 00495a0d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00495a0f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495a11  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495a13  2b45d8                 -sub eax, dword ptr [ebp - 0x28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 00495a16  e8fbfdffff             -call 0x495816
    cpu.esp -= 4;
    sub_495816(app, cpu);
    if (cpu.terminate) return;
    // 00495a1b  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00495a1e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00495a20  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495a22  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00495a24  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495a26  2b55d8                 -sub edx, dword ptr [ebp - 0x28]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 00495a29  2b45b8                 -sub eax, dword ptr [ebp - 0x48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */)));
    // 00495a2c  e8e5fdffff             -call 0x495816
    cpu.esp -= 4;
    sub_495816(app, cpu);
    if (cpu.terminate) return;
    // 00495a31  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00495a33:
    // 00495a33  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00495a36  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00495a39  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00495a3b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00495a3d  e8d4fdffff             -call 0x495816
    cpu.esp -= 4;
    sub_495816(app, cpu);
    if (cpu.terminate) return;
    // 00495a42  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00495a44:
    // 00495a44  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495a48  7424                   -je 0x495a6e
    if (cpu.flags.zf)
    {
        goto L_0x00495a6e;
    }
    // 00495a4a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495a4d  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00495a50  740f                   -je 0x495a61
    if (cpu.flags.zf)
    {
        goto L_0x00495a61;
    }
    // 00495a52  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495a58  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495a5a  e802feffff             -call 0x495861
    cpu.esp -= 4;
    sub_495861(app, cpu);
    if (cpu.terminate) return;
    // 00495a5f  eb18                   -jmp 0x495a79
    goto L_0x00495a79;
L_0x00495a61:
    // 00495a61  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495a64  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495a66  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00495a68  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00495a6a  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00495a6c  eb0b                   -jmp 0x495a79
    goto L_0x00495a79;
L_0x00495a6e:
    // 00495a6e  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00495a71  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00495a74  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00495a76  8945b4                 -mov dword ptr [ebp - 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.eax;
L_0x00495a79:
    // 00495a79  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 00495a7f  48                     -dec eax
    (cpu.eax)--;
    // 00495a80  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 00495a87  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495a8a  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00495a8d  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00495a90  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 00495a96  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00495a99  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00495a9c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00495a9f:
    // 00495a9f  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00495aa3  7448                   -je 0x495aed
    if (cpu.flags.zf)
    {
        goto L_0x00495aed;
    }
    // 00495aa5  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00495aa8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495aaa  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495aad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495aaf  7f3c                   -jg 0x495aed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495aed;
    }
    // 00495ab1  752f                   -jne 0x495ae2
    if (!cpu.flags.zf)
    {
        goto L_0x00495ae2;
    }
    // 00495ab3  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495ab7  7412                   -je 0x495acb
    if (cpu.flags.zf)
    {
        goto L_0x00495acb;
    }
    // 00495ab9  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495abf  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00495ac2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495ac4  e898fdffff             -call 0x495861
    cpu.esp -= 4;
    sub_495861(app, cpu);
    if (cpu.terminate) return;
    // 00495ac9  eb0e                   -jmp 0x495ad9
    goto L_0x00495ad9;
L_0x00495acb:
    // 00495acb  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00495ace  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00495ad1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00495ad3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00495ad5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00495ad7  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00495ad9:
    // 00495ad9  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495adf  0145ec                 -add dword ptr [ebp - 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00495ae2:
    // 00495ae2  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00495ae5  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495aeb  ebb2                   -jmp 0x495a9f
    goto L_0x00495a9f;
L_0x00495aed:
    // 00495aed  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00495af1  7453                   -je 0x495b46
    if (cpu.flags.zf)
    {
        goto L_0x00495b46;
    }
    // 00495af3  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00495af6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495af9  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495afc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495afe  7c46                   -jl 0x495b46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495b46;
    }
    // 00495b00  7536                   -jne 0x495b38
    if (!cpu.flags.zf)
    {
        goto L_0x00495b38;
    }
    // 00495b02  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b06  7413                   -je 0x495b1b
    if (cpu.flags.zf)
    {
        goto L_0x00495b1b;
    }
    // 00495b08  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495b0e  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00495b11  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495b14  e848fdffff             -call 0x495861
    cpu.esp -= 4;
    sub_495861(app, cpu);
    if (cpu.terminate) return;
    // 00495b19  eb14                   -jmp 0x495b2f
    goto L_0x00495b2f;
L_0x00495b1b:
    // 00495b1b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00495b1e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495b21  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495b24  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00495b26  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00495b28  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00495b2a  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00495b2d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00495b2f:
    // 00495b2f  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495b35  2945f0                 -sub dword ptr [ebp - 0x10], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00495b38:
    // 00495b38  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495b3e  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00495b41  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495b44  eba7                   -jmp 0x495aed
    goto L_0x00495aed;
L_0x00495b46:
    // 00495b46  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00495b4a  7442                   -je 0x495b8e
    if (cpu.flags.zf)
    {
        goto L_0x00495b8e;
    }
    // 00495b4c  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b50  7412                   -je 0x495b64
    if (cpu.flags.zf)
    {
        goto L_0x00495b64;
    }
    // 00495b52  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495b58  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495b5b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495b5d  e8fffcffff             -call 0x495861
    cpu.esp -= 4;
    sub_495861(app, cpu);
    if (cpu.terminate) return;
    // 00495b62  eb0e                   -jmp 0x495b72
    goto L_0x00495b72;
L_0x00495b64:
    // 00495b64  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495b67  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00495b69  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00495b6b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00495b6d  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00495b70  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00495b72:
    // 00495b72  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495b78  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495b7b  7411                   -je 0x495b8e
    if (cpu.flags.zf)
    {
        goto L_0x00495b8e;
    }
    // 00495b7d  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00495b83  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00495b86  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495b89  e911ffffff             -jmp 0x495a9f
    goto L_0x00495a9f;
L_0x00495b8e:
    // 00495b8e  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 00495b94  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 00495b9b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495b9e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00495ba0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495ba2  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00495ba5  2b4dec                 -sub ecx, dword ptr [ebp - 0x14]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00495ba8  2b45fc                 -sub eax, dword ptr [ebp - 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00495bab  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 00495bae  39c8                   +cmp eax, ecx
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
    // 00495bb0  7d02                   -jge 0x495bb4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495bb4;
    }
    // 00495bb2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00495bb4:
    // 00495bb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00495bb6  762c                   -jbe 0x495be4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495be4;
    }
    // 00495bb8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495bba  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495bbd  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495bbf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495bc0  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00495bc1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495bc2  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 00495bc5  c1e902                 +shr ecx, 2
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
    // 00495bc8  740b                   -je 0x495bd5
    if (cpu.flags.zf)
    {
        goto L_0x00495bd5;
    }
L_0x00495bca:
    // 00495bca  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00495bcc  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 00495bce  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00495bcf  83c604                 +add esi, 4
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
    // 00495bd2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495bd3  75f5                   -jne 0x495bca
    if (!cpu.flags.zf)
    {
        goto L_0x00495bca;
    }
L_0x00495bd5:
    // 00495bd5  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00495bd8  7409                   -je 0x495be3
    if (cpu.flags.zf)
    {
        goto L_0x00495be3;
    }
L_0x00495bda:
    // 00495bda  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00495bdc  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 00495bde  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00495bdf  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00495be0  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495be1  75f7                   -jne 0x495bda
    if (!cpu.flags.zf)
    {
        goto L_0x00495bda;
    }
L_0x00495be3:
    // 00495be3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00495be4:
    // 00495be4  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00495be7  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00495bea  2b45f0                 -sub eax, dword ptr [ebp - 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00495bed  2b4df8                 -sub ecx, dword ptr [ebp - 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00495bf0  2b85acfeffff           -sub eax, dword ptr [ebp - 0x154]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
    // 00495bf6  39c1                   +cmp ecx, eax
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
    // 00495bf8  7202                   -jb 0x495bfc
    if (cpu.flags.cf)
    {
        goto L_0x00495bfc;
    }
    // 00495bfa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00495bfc:
    // 00495bfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00495bfe  762c                   -jbe 0x495c2c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495c2c;
    }
    // 00495c00  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00495c03  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495c05  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495c07  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495c08  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00495c09  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495c0a  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 00495c0d  c1e902                 +shr ecx, 2
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
    // 00495c10  740b                   -je 0x495c1d
    if (cpu.flags.zf)
    {
        goto L_0x00495c1d;
    }
L_0x00495c12:
    // 00495c12  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00495c14  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 00495c16  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00495c17  83c604                 +add esi, 4
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
    // 00495c1a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495c1b  75f5                   -jne 0x495c12
    if (!cpu.flags.zf)
    {
        goto L_0x00495c12;
    }
L_0x00495c1d:
    // 00495c1d  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00495c20  7409                   -je 0x495c2b
    if (cpu.flags.zf)
    {
        goto L_0x00495c2b;
    }
L_0x00495c22:
    // 00495c22  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00495c24  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 00495c26  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00495c27  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00495c28  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495c29  75f7                   -jne 0x495c22
    if (!cpu.flags.zf)
    {
        goto L_0x00495c22;
    }
L_0x00495c2b:
    // 00495c2b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00495c2c:
    // 00495c2c  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00495c2f  8b4dcc                 -mov ecx, dword ptr [ebp - 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00495c32  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495c34  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00495c37  2b75ec                 -sub esi, dword ptr [ebp - 0x14]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00495c3a  2b7df8                 -sub edi, dword ptr [ebp - 8]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00495c3d  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00495c40  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00495c42  39f7                   +cmp edi, esi
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
    // 00495c44  7224                   -jb 0x495c6a
    if (cpu.flags.cf)
    {
        goto L_0x00495c6a;
    }
    // 00495c46  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495c48  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495c4a  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00495c50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495c52  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 00495c59  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495c5b  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00495c61  898c2bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.ecx;
    // 00495c68  eb34                   -jmp 0x495c9e
    goto L_0x00495c9e;
L_0x00495c6a:
    // 00495c6a  3bb5acfeffff           +cmp esi, dword ptr [ebp - 0x154]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495c70  0f86eefcffff           -jbe 0x495964
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495964;
    }
    // 00495c76  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00495c79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495c7b  89842bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.eax;
    // 00495c82  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495c84  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00495c8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495c8c  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 00495c93  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495c95  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00495c9b  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00495c9e:
    // 00495c9e  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 00495ca4  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00495ca7  e923fcffff             -jmp 0x4958cf
    goto L_0x004958cf;
L_0x00495cac:
    // 00495cac  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cad  e9a7fbffff             -jmp 0x495859
    return sub_495859(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495cc0  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495cc5  a3b8a34c00             -mov dword ptr [0x4ca3b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5022648) /* 0x4ca3b8 */) = cpu.eax;
    // 00495cca  a1489f5200             -mov eax, dword ptr [0x529f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495ccf  a3bca34c00             -mov dword ptr [0x4ca3bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5022652) /* 0x4ca3bc */) = cpu.eax;
    // 00495cd4  a1649f5200             -mov eax, dword ptr [0x529f64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495cd9  a3c0a34c00             -mov dword ptr [0x4ca3c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5022656) /* 0x4ca3c0 */) = cpu.eax;
    // 00495cde  a1c0a34c00             -mov eax, dword ptr [0x4ca3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022656) /* 0x4ca3c0 */);
    // 00495ce3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495ce4  ff05589f5200           -inc dword ptr [0x529f58]
    (app->getMemory<x86::reg32>(x86::reg32(5414744) /* 0x529f58 */))++;
    // 00495cea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495cec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495cec  ff0d589f5200           -dec dword ptr [0x529f58]
    (app->getMemory<x86::reg32>(x86::reg32(5414744) /* 0x529f58 */))--;
    // 00495cf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495cf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495cf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495cf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495cf7  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00495cfc  bfec5c4900             -mov edi, 0x495cec
    cpu.edi = 4807916 /*0x495cec*/;
    // 00495d01  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495d03  a1d0a34c00             -mov eax, dword ptr [0x4ca3d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022672) /* 0x4ca3d0 */);
    // 00495d08  89155c9f5200           -mov dword ptr [0x529f5c], edx
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.edx;
    // 00495d0e  a3549f5200             -mov dword ptr [0x529f54], eax
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.eax;
    // 00495d13  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d19  8915589f5200           -mov dword ptr [0x529f58], edx
    app->getMemory<x86::reg32>(x86::reg32(5414744) /* 0x529f58 */) = cpu.edx;
    // 00495d1f  8935b4a34c00           -mov dword ptr [0x4ca3b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */) = cpu.esi;
    // 00495d25  893d90a44c00           -mov dword ptr [0x4ca490], edi
    app->getMemory<x86::reg32>(x86::reg32(5022864) /* 0x4ca490 */) = cpu.edi;
    // 00495d2b  893d94a44c00           -mov dword ptr [0x4ca494], edi
    app->getMemory<x86::reg32>(x86::reg32(5022868) /* 0x4ca494 */) = cpu.edi;
    // 00495d31  a1d4a34c00             -mov eax, dword ptr [0x4ca3d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022676) /* 0x4ca3d4 */);
    // 00495d36  bac05c4900             -mov edx, 0x495cc0
    cpu.edx = 4807872 /*0x495cc0*/;
    // 00495d3b  a3509f5200             -mov dword ptr [0x529f50], eax
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.eax;
    // 00495d40  b8e45c4900             -mov eax, 0x495ce4
    cpu.eax = 4807908 /*0x495ce4*/;
    // 00495d45  89159ca44c00           -mov dword ptr [0x4ca49c], edx
    app->getMemory<x86::reg32>(x86::reg32(5022876) /* 0x4ca49c */) = cpu.edx;
    // 00495d4b  a398a44c00             -mov dword ptr [0x4ca498], eax
    app->getMemory<x86::reg32>(x86::reg32(5022872) /* 0x4ca498 */) = cpu.eax;
    // 00495d50  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495d52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495de6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495de6;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_entry_0x00495de6:
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495dd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495dd4;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
L_entry_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e43(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495e43;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
L_entry_0x00495e43:
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495dbb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495dbb;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_entry_0x00495dbb:
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e37(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495e37;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
L_entry_0x00495e37:
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495e2b;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
L_entry_0x00495e2b:
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495e1d;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
L_entry_0x00495e1d:
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495d84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495d84;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00495d84:
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e03(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495e03;
    // 00495d58  a35c9f5200             -mov dword ptr [0x529f5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */) = cpu.eax;
    // 00495d5d  8915609f5200           -mov dword ptr [0x529f60], edx
    app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */) = cpu.edx;
    // 00495d63  891d549f5200           -mov dword ptr [0x529f54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */) = cpu.ebx;
    // 00495d69  890d509f5200           -mov dword ptr [0x529f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */) = cpu.ecx;
    // 00495d6f  8b1d649f5200           -mov ebx, dword ptr [0x529f64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495d75  8b15489f5200           -mov edx, dword ptr [0x529f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495d7b  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495d80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d82  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00495d84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495d85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495d86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495d87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495d8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495d8c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495d8e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00495d91  833db4a34c0000         +cmp dword ptr [0x4ca3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022644) /* 0x4ca3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d98  0f84c3000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495d9e  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00495da5  0f84b6000000           -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495dab  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495db1  39f8                   +cmp eax, edi
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
    // 00495db3  0f8ede010000           -jle 0x495f97
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f97(app, cpu);
    }
    // 00495db9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dbb  a1549f5200             -mov eax, dword ptr [0x529f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495dc0  39c1                   +cmp ecx, eax
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
    // 00495dc2  7d10                   -jge 0x495dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495dd4;
    }
    // 00495dc4  8b0d5c9f5200           -mov ecx, dword ptr [0x529f5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495dca  39ce                   +cmp esi, ecx
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
    // 00495dcc  0f8ecc010000           -jle 0x495f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495f9e(app, cpu);
    }
    // 00495dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00495dd4:
    // 00495dd4  8b1d609f5200           -mov ebx, dword ptr [0x529f60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495dda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ddc  39da                   +cmp edx, ebx
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
    // 00495dde  0f8ec1010000           -jle 0x495fa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fa5(app, cpu);
    }
    // 00495de4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495de6  8b3d509f5200           -mov edi, dword ptr [0x529f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495dec  39f8                   +cmp eax, edi
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
    // 00495dee  0f8dbf010000           -jge 0x495fb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_495fb3(app, cpu);
    }
    // 00495df4  a1609f5200             -mov eax, dword ptr [0x529f60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495df9  39c2                   +cmp edx, eax
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
    // 00495dfb  0f8eab010000           -jle 0x495fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_495fac(app, cpu);
    }
    // 00495e01  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_entry_0x00495e03:
    // 00495e03  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00495e0a  e8b9adfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00495e0f  892d649f5200           -mov dword ptr [0x529f64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */) = cpu.ebp;
    // 00495e15  39f1                   +cmp ecx, esi
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
    // 00495e17  0f849d010000           -je 0x495fba
    if (cpu.flags.zf)
    {
        return sub_495fba(app, cpu);
    }
    // 00495e1d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495e22  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495e24  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495e26  e8d51dfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495e2b  3b0d4c9f5200           +cmp ecx, dword ptr [0x529f4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e31  0f8490010000           -je 0x495fc7
    if (cpu.flags.zf)
    {
        return sub_495fc7(app, cpu);
    }
    // 00495e37  890d4c9f5200           -mov dword ptr [0x529f4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.ecx;
    // 00495e3d  893d489f5200           -mov dword ptr [0x529f48], edi
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.edi;
    // 00495e43  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00495e48  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00495e4b  e890adfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495e50  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495e52  740d                   -je 0x495e61
    if (cpu.flags.zf)
    {
        goto L_0x00495e61;
    }
    // 00495e54  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e5b  0f8577010000           -jne 0x495fd8
    if (!cpu.flags.zf)
    {
        return sub_495fd8(app, cpu);
    }
L_0x00495e61:
    // 00495e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495e64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495e6a  7510                   -jne 0x495e7c
    if (!cpu.flags.zf)
    {
        goto L_0x00495e7c;
    }
L_0x00495e6c:
    // 00495e6c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495e6e  7407                   -je 0x495e77
    if (cpu.flags.zf)
    {
        goto L_0x00495e77;
    }
    // 00495e70  a14c9f5200             -mov eax, dword ptr [0x529f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */);
    // 00495e75  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00495e77:
    // 00495e77  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00495e79  750d                   -jne 0x495e88
    if (!cpu.flags.zf)
    {
        goto L_0x00495e88;
    }
    // 00495e7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495e7c:
    // 00495e7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495e7d  8b0d649f5200           -mov ecx, dword ptr [0x529f64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5414756) /* 0x529f64 */);
    // 00495e83  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00495e85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e86  ebe4                   -jmp 0x495e6c
    goto L_0x00495e6c;
L_0x00495e88:
    // 00495e88  a1489f5200             -mov eax, dword ptr [0x529f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */);
    // 00495e8d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00495e8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e90  ff159ca44c00           -call dword ptr [0x4ca49c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022876) /* 0x4ca49c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495e96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495e98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495e99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495e9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495e9b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495e9c  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00495e9f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495ea1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495ea3  e8c0a9feff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00495ea8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495eaa  0f85a4000000           -jne 0x495f54
    if (!cpu.flags.zf)
    {
        goto L_0x00495f54;
    }
    // 00495eb0  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00495eb5  e80eadfeff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
L_0x00495eba:
    // 00495eba  8b1d5c9f5200           -mov ebx, dword ptr [0x529f5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495ec0  39d9                   +cmp ecx, ebx
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
    // 00495ec2  0f8e9d000000           -jle 0x495f65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495f65;
    }
    // 00495ec8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00495eca:
    // 00495eca  8b35549f5200           -mov esi, dword ptr [0x529f54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5414740) /* 0x529f54 */);
    // 00495ed0  39f0                   +cmp eax, esi
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
    // 00495ed2  0f8d9b000000           -jge 0x495f73
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495f73;
    }
    // 00495ed8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495ed9  8b3d5c9f5200           -mov edi, dword ptr [0x529f5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5414748) /* 0x529f5c */);
    // 00495edf  39f9                   +cmp ecx, edi
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
    // 00495ee1  0f8e85000000           -jle 0x495f6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495f6c;
    }
L_0x00495ee7:
    // 00495ee7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00495ee8:
    // 00495ee8  8b2d609f5200           -mov ebp, dword ptr [0x529f60]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495eee  39ea                   +cmp edx, ebp
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
    // 00495ef0  0f8e84000000           -jle 0x495f7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495f7a;
    }
    // 00495ef6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00495ef8:
    // 00495ef8  8b1d509f5200           -mov ebx, dword ptr [0x529f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5414736) /* 0x529f50 */);
    // 00495efe  39d8                   +cmp eax, ebx
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
    // 00495f00  7d0c                   -jge 0x495f0e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495f0e;
    }
    // 00495f02  8b35609f5200           -mov esi, dword ptr [0x529f60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5414752) /* 0x529f60 */);
    // 00495f08  39f2                   +cmp edx, esi
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
    // 00495f0a  7e75                   -jle 0x495f81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495f81;
    }
L_0x00495f0c:
    // 00495f0c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00495f0e:
    // 00495f0e  890db8a34c00           -mov dword ptr [0x4ca3b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022648) /* 0x4ca3b8 */) = cpu.ecx;
    // 00495f14  a1b8a34c00             -mov eax, dword ptr [0x4ca3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022648) /* 0x4ca3b8 */);
    // 00495f19  a34c9f5200             -mov dword ptr [0x529f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5414732) /* 0x529f4c */) = cpu.eax;
    // 00495f1e  891dbca34c00           -mov dword ptr [0x4ca3bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022652) /* 0x4ca3bc */) = cpu.ebx;
    // 00495f24  a1bca34c00             -mov eax, dword ptr [0x4ca3bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022652) /* 0x4ca3bc */);
    // 00495f29  a3489f5200             -mov dword ptr [0x529f48], eax
    app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */) = cpu.eax;
    // 00495f2e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495f30  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00495f35  e8c61cfeff             -call 0x477c00
    cpu.esp -= 4;
    sub_477c00(app, cpu);
    if (cpu.terminate) return;
    // 00495f3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495f3c  e827a9feff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00495f41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495f43  7440                   -je 0x495f85
    if (cpu.flags.zf)
    {
        goto L_0x00495f85;
    }
    // 00495f45  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00495f47  e8381b0000             -call 0x497a84
    cpu.esp -= 4;
    sub_497a84(app, cpu);
    if (cpu.terminate) return;
    // 00495f4c  83c470                 +add esp, 0x70
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
    // 00495f4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495f54:
    // 00495f54  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00495f56  e8051b0000             -call 0x497a60
    cpu.esp -= 4;
    sub_497a60(app, cpu);
    if (cpu.terminate) return;
    // 00495f5b  e8bc1ffeff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00495f60  e955ffffff             -jmp 0x495eba
    goto L_0x00495eba;
L_0x00495f65:
    // 00495f65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495f67  e95effffff             -jmp 0x495eca
    goto L_0x00495eca;
L_0x00495f6c:
    // 00495f6c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00495f6e  e974ffffff             -jmp 0x495ee7
    goto L_0x00495ee7;
L_0x00495f73:
    // 00495f73  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00495f75  e96effffff             -jmp 0x495ee8
    goto L_0x00495ee8;
L_0x00495f7a:
    // 00495f7a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495f7c  e977ffffff             -jmp 0x495ef8
    goto L_0x00495ef8;
L_0x00495f81:
    // 00495f81  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495f83  eb87                   -jmp 0x495f0c
    goto L_0x00495f0c;
L_0x00495f85:
    // 00495f85  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00495f8a  e851acfeff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00495f8f  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00495f92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495f97(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495f97  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00495f99  e91dfeffff             -jmp 0x495dbb
    return sub_495dbb(app, cpu);
}

/* align: skip  */
void Application::sub_495f9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495f9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495fa0  e92ffeffff             -jmp 0x495dd4
    return sub_495dd4(app, cpu);
}

/* align: skip  */
void Application::sub_495fa5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fa5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495fa7  e93afeffff             -jmp 0x495de6
    return sub_495de6(app, cpu);
}

/* align: skip  */
void Application::sub_495fac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fac  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495fae  e950feffff             -jmp 0x495e03
    return sub_495e03(app, cpu);
}

/* align: skip  */
void Application::sub_495fb3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fb3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00495fb5  e949feffff             -jmp 0x495e03
    return sub_495e03(app, cpu);
}

/* align: skip  */
void Application::sub_495fba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fba  39d3                   +cmp ebx, edx
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
    // 00495fbc  0f855bfeffff           -jne 0x495e1d
    if (!cpu.flags.zf)
    {
        return sub_495e1d(app, cpu);
    }
    // 00495fc2  e964feffff             -jmp 0x495e2b
    return sub_495e2b(app, cpu);
}

/* align: skip  */
void Application::sub_495fc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fc7  3b3d489f5200           +cmp edi, dword ptr [0x529f48]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5414728) /* 0x529f48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495fcd  0f8564feffff           -jne 0x495e37
    if (!cpu.flags.zf)
    {
        return sub_495e37(app, cpu);
    }
    // 00495fd3  e96bfeffff             -jmp 0x495e43
    return sub_495e43(app, cpu);
}

/* align: skip  */
void Application::sub_495fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fd8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00495fda  ff15a0a44c00           -call dword ptr [0x4ca4a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495fe0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495fe3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fe6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495ff0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495ff1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00495ff6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495ff8  e813000000             -call 0x496010
    cpu.esp -= 4;
    sub_496010(app, cpu);
    if (cpu.terminate) return;
    // 00495ffd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496000  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496001  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496006  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496008  e803000000             -call 0x496010
    cpu.esp -= 4;
    sub_496010(app, cpu);
    if (cpu.terminate) return;
    // 0049600d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049600e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496011  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496012  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496013  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496014  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496015  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496018  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049601b  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00496020  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00496022  83f801                 +cmp eax, 1
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
    // 00496025  7328                   -jae 0x49604f
    if (!cpu.flags.cf)
    {
        goto L_0x0049604f;
    }
    // 00496027  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496029  751b                   -jne 0x496046
    if (!cpu.flags.zf)
    {
        goto L_0x00496046;
    }
    // 0049602b  b014                   -mov al, 0x14
    cpu.al = 20 /*0x14*/;
    // 0049602d  b33a                   -mov bl, 0x3a
    cpu.bl = 58 /*0x3a*/;
L_0x0049602f:
    // 0049602f  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 00496032  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496033  2eff15e8734b00         -call dword ptr cs:[0x4b73e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944872) /* 0x4b73e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049603a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049603c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049603e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496041  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00496042  39d0                   +cmp eax, edx
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
    // 00496044  7525                   -jne 0x49606b
    if (!cpu.flags.zf)
    {
        goto L_0x0049606b;
    }
L_0x00496046:
    // 00496046  83c404                 +add esp, 4
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
    // 00496049  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049604a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049604b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049604c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049604d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049604e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049604f:
    // 0049604f  7710                   -ja 0x496061
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00496061;
    }
    // 00496051  b090                   -mov al, 0x90
    cpu.al = 144 /*0x90*/;
    // 00496053  b345                   -mov bl, 0x45
    cpu.bl = 69 /*0x45*/;
    // 00496055  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049605a  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 0049605f  ebce                   -jmp 0x49602f
    goto L_0x0049602f;
L_0x00496061:
    // 00496061  39e8                   +cmp eax, ebp
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
    // 00496063  75e1                   -jne 0x496046
    if (!cpu.flags.zf)
    {
        goto L_0x00496046;
    }
    // 00496065  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 00496067  b346                   -mov bl, 0x46
    cpu.bl = 70 /*0x46*/;
    // 00496069  ebc4                   -jmp 0x49602f
    goto L_0x0049602f;
L_0x0049606b:
    // 0049606b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049606d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049606e  0fb6fb                 -movzx edi, bl
    cpu.edi = x86::reg32(cpu.bl);
    // 00496071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496072  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496073  2eff1544744b00         -call dword ptr cs:[0x4b7444]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944964) /* 0x4b7444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049607a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049607c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049607d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049607e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049607f  2eff1544744b00         -call dword ptr cs:[0x4b7444]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944964) /* 0x4b7444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496086  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496089  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_496090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496090  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496092  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4960a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004960a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004960a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004960a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004960a3  8a15d8a64c00           -mov dl, byte ptr [0x4ca6d8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 004960a9  80fa0f                 +cmp dl, 0xf
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
    // 004960ac  0f8288000000           -jb 0x49613a
    if (cpu.flags.cf)
    {
        goto L_0x0049613a;
    }
    // 004960b2  7737                   -ja 0x4960eb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004960eb;
    }
    // 004960b4  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 004960b7  0f8475000000           -je 0x496132
    if (cpu.flags.zf)
    {
        goto L_0x00496132;
    }
    // 004960bd  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x004960c2:
    // 004960c2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004960c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004960c6  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 004960c9  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 004960cc  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 004960cf  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004960d2  83e31f                 -and ebx, 0x1f
    cpu.ebx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004960d5  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004960d8  c1e313                 -shl ebx, 0x13
    cpu.ebx <<= 19 /*0x13*/ % 32;
    // 004960db  c1e10b                 -shl ecx, 0xb
    cpu.ecx <<= 11 /*0xb*/ % 32;
    // 004960de  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004960e0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004960e3  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004960e5  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x004960e7:
    // 004960e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004960eb:
    // 004960eb  80fa18                 +cmp dl, 0x18
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004960ee  7337                   -jae 0x496127
    if (!cpu.flags.cf)
    {
        goto L_0x00496127;
    }
    // 004960f0  80fa10                 +cmp dl, 0x10
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
    // 004960f3  7545                   -jne 0x49613a
    if (!cpu.flags.zf)
    {
        goto L_0x0049613a;
    }
    // 004960f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004960f7  743d                   -je 0x496136
    if (cpu.flags.zf)
    {
        goto L_0x00496136;
    }
    // 004960f9  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x004960fe:
    // 004960fe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496100  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496102  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00496105  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 00496108  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 0049610b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049610e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496111  83e33f                 -and ebx, 0x3f
    cpu.ebx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00496114  c1e113                 -shl ecx, 0x13
    cpu.ecx <<= 19 /*0x13*/ % 32;
    // 00496117  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0049611a  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049611c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049611f  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496121  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00496123  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496124  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496125  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496126  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496127:
    // 00496127  76be                   -jbe 0x4960e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004960e7;
    }
    // 00496129  80fa20                 +cmp dl, 0x20
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
    // 0049612c  750c                   -jne 0x49613a
    if (!cpu.flags.zf)
    {
        goto L_0x0049613a;
    }
    // 0049612e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049612f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496130  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496131  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496132:
    // 00496132  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00496134  eb8c                   -jmp 0x4960c2
    goto L_0x004960c2;
L_0x00496136:
    // 00496136  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00496138  ebc4                   -jmp 0x4960fe
    goto L_0x004960fe;
L_0x0049613a:
    // 0049613a  8b0485709f5200         -mov eax, dword ptr [eax*4 + 0x529f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5414768) /* 0x529f70 */ + cpu.eax * 4);
    // 00496141  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496142  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496143  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496144  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_496150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496150  43                     -inc ebx
    (cpu.ebx)++;
    // 00496151  d1fb                   +sar ebx, 1
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
    // 00496153  90                     -nop 
    ;
    // 00496154  e9a7b4feff             -jmp 0x481600
    return sub_481600(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49615c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049615c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049615d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049615e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049615f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496161  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00496163  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00496165  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496167  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496169  7e2d                   -jle 0x496198
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496198;
    }
    // 0049616b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0049616d:
    // 0049616d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049616f  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00496171  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00496173  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00496175  7425                   -je 0x49619c
    if (cpu.flags.zf)
    {
        goto L_0x0049619c;
    }
    // 00496177  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00496179  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049617b  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0049617e  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00496180  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496182  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00496184  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x00496187:
    // 00496187  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496189  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 0049618b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049618d  42                     -inc edx
    (cpu.edx)++;
    // 0049618e  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00496190  40                     -inc eax
    (cpu.eax)++;
    // 00496191  881c31                 -mov byte ptr [ecx + esi], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.bl;
    // 00496194  39f8                   +cmp eax, edi
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
    // 00496196  7cd5                   -jl 0x49616d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049616d;
    }
L_0x00496198:
    // 00496198  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496199  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049619a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049619b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049619c:
    // 0049619c  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049619e  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004961a1  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004961a3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004961a9  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004961ac  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004961b2  ebd3                   -jmp 0x496187
    goto L_0x00496187;
}

/* align: skip  */
void Application::sub_4961b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004961b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004961b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004961b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004961b7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004961b9  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004961bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004961bd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004961bf  7e1e                   -jle 0x4961df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004961df;
    }
L_0x004961c1:
    // 004961c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004961c3  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004961c5  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004961c7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004961c9  7418                   -je 0x4961e3
    if (cpu.flags.zf)
    {
        goto L_0x004961e3;
    }
    // 004961cb  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004961cd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004961d3  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004961d6  42                     -inc edx
    (cpu.edx)++;
    // 004961d7  40                     -inc eax
    (cpu.eax)++;
    // 004961d8  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004961db  39f0                   +cmp eax, esi
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
    // 004961dd  7ce2                   -jl 0x4961c1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004961c1;
    }
L_0x004961df:
    // 004961df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004961e3:
    // 004961e3  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004961e5  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004961e8  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004961ee  42                     -inc edx
    (cpu.edx)++;
    // 004961ef  40                     -inc eax
    (cpu.eax)++;
    // 004961f0  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004961f3  39f0                   +cmp eax, esi
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
    // 004961f5  7cca                   -jl 0x4961c1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004961c1;
    }
    // 004961f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4961fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004961fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004961fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004961fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004961ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496200  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496203  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496205  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00496207  8b1db4a44c00           -mov ebx, dword ptr [0x4ca4b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */);
    // 0049620d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049620f  7563                   -jne 0x496274
    if (!cpu.flags.zf)
    {
        goto L_0x00496274;
    }
    // 00496211  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496213  7e57                   -jle 0x49626c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049626c;
    }
L_0x00496215:
    // 00496215  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00496218  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049621d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049621f  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00496222  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496225  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00496229  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049622b  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 0049622e  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00496231  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496234  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00496238  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049623c  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496240  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00496243  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00496246  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049624c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049624f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496251  42                     -inc edx
    (cpu.edx)++;
    // 00496252  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00496254  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00496257  e8c01efeff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 0049625c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00496260  43                     -inc ebx
    (cpu.ebx)++;
    // 00496261  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496265  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00496268  39f3                   +cmp ebx, esi
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
    // 0049626a  7ca9                   -jl 0x496215
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496215;
    }
L_0x0049626c:
    // 0049626c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049626f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496270  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496271  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496272  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496273  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496274:
    // 00496274  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496276  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496278  7ef2                   -jle 0x49626c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049626c;
    }
L_0x0049627a:
    // 0049627a  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049627d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00496282  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496284  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00496287  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049628a  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049628d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049628f  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00496292  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496295  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00496298  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049629c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049629f  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004962a1  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004962a4  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 004962a7  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004962a9  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004962ad  8b3db4a44c00           -mov edi, dword ptr [0x4ca4b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */);
    // 004962b3  42                     -inc edx
    (cpu.edx)++;
    // 004962b4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004962b7  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 004962ba  43                     -inc ebx
    (cpu.ebx)++;
    // 004962bb  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004962be  39f3                   +cmp ebx, esi
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
    // 004962c0  7cb8                   -jl 0x49627a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049627a;
    }
    // 004962c2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004962c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4962cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004962cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004962cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004962ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004962cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004962d0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004962d2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004962d4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004962d6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004962d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004962da  7e1b                   -jle 0x4962f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004962f7;
    }
L_0x004962dc:
    // 004962dc  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004962de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004962e0  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004962e6  7314                   -jae 0x4962fc
    if (!cpu.flags.cf)
    {
        goto L_0x004962fc;
    }
L_0x004962e8:
    // 004962e8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004962eb  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004962ee  47                     -inc edi
    (cpu.edi)++;
    // 004962ef  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004962f3  39ef                   +cmp edi, ebp
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
    // 004962f5  7ce5                   -jl 0x4962dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004962dc;
    }
L_0x004962f7:
    // 004962f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004962fc:
    // 004962fc  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004962fe  7425                   -je 0x496325
    if (cpu.flags.zf)
    {
        goto L_0x00496325;
    }
    // 00496300  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496302  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00496308  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0049630b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049630d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00496310  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00496316  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00496319  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049631c  01c3                   +add ebx, eax
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
    // 0049631e  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00496325:
    // 00496325  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496327  ebbf                   -jmp 0x4962e8
    goto L_0x004962e8;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49632c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049632c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049632d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049632e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049632f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496330  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496332  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00496334  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00496336  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00496338  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049633a  7e3c                   -jle 0x496378
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496378;
    }
L_0x0049633c:
    // 0049633c  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049633e  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00496340  7425                   -je 0x496367
    if (cpu.flags.zf)
    {
        goto L_0x00496367;
    }
    // 00496342  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496344  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0049634a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0049634d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049634f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00496352  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00496358  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0049635b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049635e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496360  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00496367:
    // 00496367  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049636a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049636d  47                     -inc edi
    (cpu.edi)++;
    // 0049636e  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00496372  39ef                   +cmp edi, ebp
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
    // 00496374  7cc6                   -jl 0x49633c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049633c;
    }
    // 00496376  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00496378:
    // 00496378  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496379  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049637a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049637b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049637c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_496380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496380  01db                   +add ebx, ebx
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
    // 00496382  e979b2feff             -jmp 0x481600
    return sub_481600(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_496388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496388  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496389  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049638a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049638c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049638e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496390  7e12                   -jle 0x4963a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004963a4;
    }
L_0x00496392:
    // 00496392  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00496395  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00496398  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049639b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049639c  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004963a0  39f1                   +cmp ecx, esi
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
    // 004963a2  7cee                   -jl 0x496392
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496392;
    }
L_0x004963a4:
    // 004963a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4963a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004963a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004963a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004963aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004963ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004963ac  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004963ae  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004963b0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004963b2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004963b4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004963b6  7e1b                   -jle 0x4963d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004963d3;
    }
L_0x004963b8:
    // 004963b8  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004963ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004963bc  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004963c2  7314                   -jae 0x4963d8
    if (!cpu.flags.cf)
    {
        goto L_0x004963d8;
    }
L_0x004963c4:
    // 004963c4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004963c7  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004963ca  47                     -inc edi
    (cpu.edi)++;
    // 004963cb  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004963cf  39ef                   +cmp edi, ebp
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
    // 004963d1  7ce5                   -jl 0x4963b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004963b8;
    }
L_0x004963d3:
    // 004963d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004963d8:
    // 004963d8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004963da  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004963e0  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004963e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004963e5  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004963e8  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004963ee  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004963f1  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004963f4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004963f6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004963f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004963fa  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004963fd  75c5                   -jne 0x4963c4
    if (!cpu.flags.zf)
    {
        goto L_0x004963c4;
    }
    // 004963ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496404  ebbe                   -jmp 0x4963c4
    goto L_0x004963c4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496408(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496408  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496409  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049640a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049640b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049640c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049640e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00496410  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00496412  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00496414  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496416  7e34                   -jle 0x49644c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049644c;
    }
L_0x00496418:
    // 00496418  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049641a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049641c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00496422  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00496425  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496427  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0049642a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00496430  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00496433  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496436  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496438  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049643a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049643d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496440  47                     -inc edi
    (cpu.edi)++;
    // 00496441  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00496445  39ef                   +cmp edi, ebp
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
    // 00496447  7ccf                   -jl 0x496418
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496418;
    }
    // 00496449  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049644c:
    // 0049644c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049644d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049644e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049644f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496450  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_496454(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496454  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496455  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496456  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496457  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049645a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049645e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496460  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496462  7e4c                   -jle 0x4964b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004964b0;
    }
L_0x00496464:
    // 00496464  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00496468  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 0049646c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049646e  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00496471  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00496474  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00496477  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0049647a  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049647e  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 00496481  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00496484  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00496487  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00496489  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049648d  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00496490  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00496493  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00496496  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00496498  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049649b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049649e  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004964a0  41                     -inc ecx
    (cpu.ecx)++;
    // 004964a1  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 004964a4  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004964a8  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004964ab  39f1                   +cmp ecx, esi
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
    // 004964ad  7cb5                   -jl 0x496464
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496464;
    }
    // 004964af  90                     -nop 
    ;
L_0x004964b0:
    // 004964b0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004964b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4964b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004964b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004964b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004964ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004964bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004964bc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004964bf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004964c1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004964c3  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004964c6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004964c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004964ca  7e3c                   -jle 0x496508
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496508;
    }
L_0x004964cc:
    // 004964cc  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004964ce  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004964d1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004964d3  81e1000000ff           -and ecx, 0xff000000
    cpu.ecx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004964d9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004964db  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004964e1  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004964e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004964e6  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004964e9  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004964ef  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004964f2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004964f5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004964f7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004964f9  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004964fb  45                     -inc ebp
    (cpu.ebp)++;
    // 004964fc  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004964fe  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496501  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496504  39cd                   +cmp ebp, ecx
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
    // 00496506  7cc4                   -jl 0x4964cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004964cc;
    }
L_0x00496508:
    // 00496508  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049650b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049650c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049650d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049650e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049650f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496510  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496511  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496512  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496513  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496514  8b2d60cb4c00           -mov ebp, dword ptr [0x4ccb60]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */);
    // 0049651a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049651c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049651e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00496520  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496522  7e28                   -jle 0x49654c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049654c;
    }
L_0x00496524:
    // 00496524  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496526  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00496528  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0049652f  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 00496532  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00496535  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00496538  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049653b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049653c  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049653f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00496542  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00496544  46                     -inc esi
    (cpu.esi)++;
    // 00496545  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00496548  39fe                   +cmp esi, edi
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
    // 0049654a  7cd8                   -jl 0x496524
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496524;
    }
L_0x0049654c:
    // 0049654c  892d60cb4c00           -mov dword ptr [0x4ccb60], ebp
    app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */) = cpu.ebp;
    // 00496552  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496553  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496554  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496555  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496558(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496558  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496559  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049655a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049655b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049655e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496560  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00496562  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496564  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00496566  7e50                   -jle 0x4965b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004965b8;
    }
L_0x00496568:
    // 00496568  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049656b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00496570  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496572  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 00496575  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496578  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0049657b  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049657e  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00496581  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496583  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496586  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00496589  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049658c  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049658f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00496593  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00496596  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049659a  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049659e  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 004965a1  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004965a5  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004965a8  8842fe                 -mov byte ptr [edx - 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 004965ab  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004965ae  43                     -inc ebx
    (cpu.ebx)++;
    // 004965af  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004965b2  39fb                   +cmp ebx, edi
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
    // 004965b4  7cb2                   -jl 0x496568
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496568;
    }
    // 004965b6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004965b8:
    // 004965b8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004965bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4965c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004965c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004965c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004965c3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004965ca  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004965cc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004965ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004965d0  e82bb0feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004965d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4965d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004965d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004965d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004965da  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004965dd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004965df  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004965e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004965e3  7e3b                   -jle 0x496620
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496620;
    }
L_0x004965e5:
    // 004965e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004965e7  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004965ea  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004965ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004965ef  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004965f2  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004965f6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004965f8  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004965fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004965fe  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00496601  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496605  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 00496608  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049660c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049660f  885afe                 -mov byte ptr [edx - 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 00496612  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00496615  41                     -inc ecx
    (cpu.ecx)++;
    // 00496616  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00496619  39f1                   +cmp ecx, esi
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
    // 0049661b  7cc8                   -jl 0x4965e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004965e5;
    }
    // 0049661d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00496620:
    // 00496620  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00496623  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496624  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496628(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496628  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496629  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049662a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049662b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049662c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049662f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496631  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00496634  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00496637  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496639  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049663b  7e48                   -jle 0x496685
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496685;
    }
L_0x0049663d:
    // 0049663d  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00496640  8b2d58cb4c00           -mov ebp, dword ptr [0x4ccb58]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5032792) /* 0x4ccb58 */);
    // 00496646  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049664b  39e8                   +cmp eax, ebp
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
    // 0049664d  743e                   -je 0x49668d
    if (cpu.flags.zf)
    {
        goto L_0x0049668d;
    }
    // 0049664f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496651  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496653  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 00496656  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00496659  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049665c  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049665f  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00496662  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00496665  c1e60b                 -shl esi, 0xb
    cpu.esi <<= 11 /*0xb*/ % 32;
    // 00496668  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049666e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496671  09fe                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
    // 00496673  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00496675  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x00496677:
    // 00496677  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049667a  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049667d  43                     -inc ebx
    (cpu.ebx)++;
    // 0049667e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496681  39fb                   +cmp ebx, edi
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
    // 00496683  7cb8                   -jl 0x49663d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049663d;
    }
L_0x00496685:
    // 00496685  83c404                 +add esp, 4
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
    // 00496688  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496689  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049668a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049668b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049668c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049668d:
    // 0049668d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00496693  ebe2                   -jmp 0x496677
    goto L_0x00496677;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_496698(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496698  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496699  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049669a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049669b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049669c  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049669f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004966a1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004966a5  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004966a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004966ab  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004966ad  7e50                   -jle 0x4966ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004966ff;
    }
L_0x004966af:
    // 004966af  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004966b2  8b2d58cb4c00           -mov ebp, dword ptr [0x4ccb58]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5032792) /* 0x4ccb58 */);
    // 004966b8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004966bd  39e8                   +cmp eax, ebp
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
    // 004966bf  7446                   -je 0x496707
    if (cpu.flags.zf)
    {
        goto L_0x00496707;
    }
    // 004966c1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004966c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004966c5  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 004966c8  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004966cb  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 004966ce  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004966d1  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004966d4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004966d7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004966d9  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004966dc  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 004966df  c1e60a                 -shl esi, 0xa
    cpu.esi <<= 10 /*0xa*/ % 32;
    // 004966e2  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004966e7  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004966e9  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004966ec  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004966ee  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x004966f0:
    // 004966f0  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004966f4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004966f7  43                     -inc ebx
    (cpu.ebx)++;
    // 004966f8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004966fb  39fb                   +cmp ebx, edi
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
    // 004966fd  7cb0                   -jl 0x4966af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004966af;
    }
L_0x004966ff:
    // 004966ff  83c408                 +add esp, 8
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
    // 00496702  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496703  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496704  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496705  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496706  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496707:
    // 00496707  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0049670d  ebe1                   -jmp 0x4966f0
    goto L_0x004966f0;
}

/* align: skip 0x90 */
void Application::sub_496710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496710  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496711  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496712  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496713  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496714  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496717  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496719  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049671b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049671e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496720  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00496724  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496726  7e68                   -jle 0x496790
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496790;
    }
L_0x00496728:
    // 00496728  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0049672b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00496730  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496732  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 00496735  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00496738  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049673a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049673c  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 0049673f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00496742  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00496745  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00496747  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00496749  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0049674c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049674f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00496751  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496753  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496756  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 00496759  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0049675c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049675f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00496762  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00496764  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00496767  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 0049676a  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049676c  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049676e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00496770  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00496773  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 00496776  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496778  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049677a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049677c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496780  8956fc                 -mov dword ptr [esi - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00496783  40                     -inc eax
    (cpu.eax)++;
    // 00496784  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496787  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049678b  39d0                   +cmp eax, edx
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
    // 0049678d  7c99                   -jl 0x496728
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496728;
    }
    // 0049678f  90                     -nop 
    ;
L_0x00496790:
    // 00496790  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496793  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496794  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496795  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496796  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496797  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496798(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496798  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496799  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049679a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049679b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049679e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004967a0  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004967a4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004967a8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004967aa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004967ac  7e56                   -jle 0x496804
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496804;
    }
L_0x004967ae:
    // 004967ae  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004967b1  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 004967b5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004967bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004967bd  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 004967c0  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004967c3  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004967c6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004967c8  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 004967cb  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004967ce  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004967d1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004967d5  8d34d500000000         -lea esi, [edx*8]
    cpu.esi = x86::reg32(cpu.edx * 8);
    // 004967dc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004967df  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 004967e2  c1e213                 -shl edx, 0x13
    cpu.edx <<= 19 /*0x13*/ % 32;
    // 004967e5  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004967e7  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004967eb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004967ee  c1e70a                 -shl edi, 0xa
    cpu.edi <<= 10 /*0xa*/ % 32;
    // 004967f1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004967f4  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004967f6  43                     -inc ebx
    (cpu.ebx)++;
    // 004967f7  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004967f9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004967fd  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00496800  39f3                   +cmp ebx, esi
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
    // 00496802  7caa                   -jl 0x4967ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004967ae;
    }
L_0x00496804:
    // 00496804  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00496807  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496808  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496809  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049680a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49680c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049680c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049680d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049680e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049680f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496810  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496813  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00496816  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496818  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049681a  7e34                   -jle 0x496850
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496850;
    }
L_0x0049681c:
    // 0049681c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049681e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496821  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00496824  0fb67001               -movzx esi, byte ptr [eax + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00496828  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049682a  0fb628                 -movzx ebp, byte ptr [eax]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 0049682d  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 00496830  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496832  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00496838  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049683b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049683e  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00496840  41                     -inc ecx
    (cpu.ecx)++;
    // 00496841  09eb                   -or ebx, ebp
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496843  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00496846  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00496849  39f1                   +cmp ecx, esi
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
    // 0049684b  7ccf                   -jl 0x49681c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049681c;
    }
    // 0049684d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00496850:
    // 00496850  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496853  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496854  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496855  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496856  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496857  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496858(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496858  c1e302                 +shl ebx, 2
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
    // 0049685b  e9a0adfeff             -jmp 0x481600
    return sub_481600(app, cpu);
}

/* align: skip  */
void Application::sub_496860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496860  83f80f                 +cmp eax, 0xf
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
    // 00496863  7312                   -jae 0x496877
    if (!cpu.flags.cf)
    {
        goto L_0x00496877;
    }
    // 00496865  83f804                 +cmp eax, 4
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
    // 00496868  722c                   -jb 0x496896
    if (cpu.flags.cf)
    {
        goto L_0x00496896;
    }
    // 0049686a  762a                   -jbe 0x496896
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 0049686c  83f808                 +cmp eax, 8
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
    // 0049686f  7525                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496871  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496876  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496877:
    // 00496877  7620                   -jbe 0x496899
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496899;
    }
    // 00496879  83f818                 +cmp eax, 0x18
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
    // 0049687c  730b                   -jae 0x496889
    if (!cpu.flags.cf)
    {
        goto L_0x00496889;
    }
    // 0049687e  83f810                 +cmp eax, 0x10
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
    // 00496881  7513                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496883  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00496888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496889:
    // 00496889  7614                   -jbe 0x49689f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049689f;
    }
    // 0049688b  83f820                 +cmp eax, 0x20
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
    // 0049688e  7506                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496890  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00496895  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496896:
    // 00496896  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496899:
    // 00496899  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049689e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049689f:
    // 0049689f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004968a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496899(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00496899;
    // 00496860  83f80f                 +cmp eax, 0xf
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
    // 00496863  7312                   -jae 0x496877
    if (!cpu.flags.cf)
    {
        goto L_0x00496877;
    }
    // 00496865  83f804                 +cmp eax, 4
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
    // 00496868  722c                   -jb 0x496896
    if (cpu.flags.cf)
    {
        goto L_0x00496896;
    }
    // 0049686a  762a                   -jbe 0x496896
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 0049686c  83f808                 +cmp eax, 8
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
    // 0049686f  7525                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496871  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496876  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496877:
    // 00496877  7620                   -jbe 0x496899
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496899;
    }
    // 00496879  83f818                 +cmp eax, 0x18
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
    // 0049687c  730b                   -jae 0x496889
    if (!cpu.flags.cf)
    {
        goto L_0x00496889;
    }
    // 0049687e  83f810                 +cmp eax, 0x10
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
    // 00496881  7513                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496883  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00496888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496889:
    // 00496889  7614                   -jbe 0x49689f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049689f;
    }
    // 0049688b  83f820                 +cmp eax, 0x20
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
    // 0049688e  7506                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496890  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00496895  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496896:
    // 00496896  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496899:
L_entry_0x00496899:
    // 00496899  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049689e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049689f:
    // 0049689f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004968a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00496890;
    // 00496860  83f80f                 +cmp eax, 0xf
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
    // 00496863  7312                   -jae 0x496877
    if (!cpu.flags.cf)
    {
        goto L_0x00496877;
    }
    // 00496865  83f804                 +cmp eax, 4
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
    // 00496868  722c                   -jb 0x496896
    if (cpu.flags.cf)
    {
        goto L_0x00496896;
    }
    // 0049686a  762a                   -jbe 0x496896
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 0049686c  83f808                 +cmp eax, 8
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
    // 0049686f  7525                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496871  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496876  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496877:
    // 00496877  7620                   -jbe 0x496899
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496899;
    }
    // 00496879  83f818                 +cmp eax, 0x18
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
    // 0049687c  730b                   -jae 0x496889
    if (!cpu.flags.cf)
    {
        goto L_0x00496889;
    }
    // 0049687e  83f810                 +cmp eax, 0x10
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
    // 00496881  7513                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496883  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00496888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496889:
    // 00496889  7614                   -jbe 0x49689f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049689f;
    }
    // 0049688b  83f820                 +cmp eax, 0x20
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
    // 0049688e  7506                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
L_entry_0x00496890:
    // 00496890  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00496895  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496896:
    // 00496896  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496899:
    // 00496899  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049689e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049689f:
    // 0049689f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004968a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496883(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00496883;
    // 00496860  83f80f                 +cmp eax, 0xf
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
    // 00496863  7312                   -jae 0x496877
    if (!cpu.flags.cf)
    {
        goto L_0x00496877;
    }
    // 00496865  83f804                 +cmp eax, 4
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
    // 00496868  722c                   -jb 0x496896
    if (cpu.flags.cf)
    {
        goto L_0x00496896;
    }
    // 0049686a  762a                   -jbe 0x496896
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 0049686c  83f808                 +cmp eax, 8
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
    // 0049686f  7525                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496871  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496876  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496877:
    // 00496877  7620                   -jbe 0x496899
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496899;
    }
    // 00496879  83f818                 +cmp eax, 0x18
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
    // 0049687c  730b                   -jae 0x496889
    if (!cpu.flags.cf)
    {
        goto L_0x00496889;
    }
    // 0049687e  83f810                 +cmp eax, 0x10
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
    // 00496881  7513                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
L_entry_0x00496883:
    // 00496883  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00496888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496889:
    // 00496889  7614                   -jbe 0x49689f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049689f;
    }
    // 0049688b  83f820                 +cmp eax, 0x20
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
    // 0049688e  7506                   -jne 0x496896
    if (!cpu.flags.zf)
    {
        goto L_0x00496896;
    }
    // 00496890  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00496895  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496896:
    // 00496896  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496899:
    // 00496899  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049689e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049689f:
    // 0049689f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004968a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4968a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004968a8  83f878                 +cmp eax, 0x78
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
    // 004968ab  730f                   -jae 0x4968bc
    if (!cpu.flags.cf)
    {
        goto L_0x004968bc;
    }
    // 004968ad  83f842                 +cmp eax, 0x42
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(66 /*0x42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004968b0  7335                   -jae 0x4968e7
    if (!cpu.flags.cf)
    {
        goto L_0x004968e7;
    }
    // 004968b2  83f840                 +cmp eax, 0x40
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
    // 004968b5  7248                   -jb 0x4968ff
    if (cpu.flags.cf)
    {
        goto L_0x004968ff;
    }
    // 004968b7  7716                   -ja 0x4968cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004968cf;
    }
L_0x004968b9:
    // 004968b9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004968bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004968bc:
    // 004968bc  76c5                   -jbe 0x496883
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_496883(app, cpu);
    }
    // 004968be  83f87d                 +cmp eax, 0x7d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004968c1  7312                   -jae 0x4968d5
    if (!cpu.flags.cf)
    {
        goto L_0x004968d5;
    }
    // 004968c3  83f87a                 +cmp eax, 0x7a
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
    // 004968c6  7237                   -jb 0x4968ff
    if (cpu.flags.cf)
    {
        goto L_0x004968ff;
    }
    // 004968c8  76ef                   -jbe 0x4968b9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004968b9;
    }
    // 004968ca  83f87b                 +cmp eax, 0x7b
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
    // 004968cd  7530                   -jne 0x4968ff
    if (!cpu.flags.zf)
    {
        goto L_0x004968ff;
    }
L_0x004968cf:
    // 004968cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004968d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004968d5:
    // 004968d5  76b9                   -jbe 0x496890
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_496890(app, cpu);
    }
    // 004968d7  83f87e                 +cmp eax, 0x7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004968da  76bd                   -jbe 0x496899
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_496899(app, cpu);
    }
    // 004968dc  83f87f                 +cmp eax, 0x7f
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
    // 004968df  751e                   -jne 0x4968ff
    if (!cpu.flags.zf)
    {
        goto L_0x004968ff;
    }
L_0x004968e1:
    // 004968e1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004968e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004968e7:
    // 004968e7  7610                   -jbe 0x4968f9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004968f9;
    }
    // 004968e9  83f843                 +cmp eax, 0x43
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004968ec  76f3                   -jbe 0x4968e1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004968e1;
    }
    // 004968ee  83f86d                 +cmp eax, 0x6d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004968f1  750c                   -jne 0x4968ff
    if (!cpu.flags.zf)
    {
        goto L_0x004968ff;
    }
    // 004968f3  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004968f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004968f9:
    // 004968f9  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004968fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004968ff:
    // 004968ff  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496904  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_496908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496908  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496909  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049690a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049690b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049690c  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00496912  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00496914  e877a3ffff             -call 0x490c90
    cpu.esp -= 4;
    sub_490c90(app, cpu);
    if (cpu.terminate) return;
    // 00496919  bf709f5200             -mov edi, 0x529f70
    cpu.edi = 5414768 /*0x529f70*/;
    // 0049691e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496920  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496922  7448                   -je 0x49696c
    if (cpu.flags.zf)
    {
        goto L_0x0049696c;
    }
    // 00496924  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00496926  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049692c  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049692f  83fe2a                 +cmp esi, 0x2a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496932  7445                   -je 0x496979
    if (cpu.flags.zf)
    {
        goto L_0x00496979;
    }
    // 00496934  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00496937  c781fc03000000000000   -mov dword ptr [ecx + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00496941  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00496943  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00496945  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049694b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0049694e  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496951  742a                   -je 0x49697d
    if (cpu.flags.zf)
    {
        goto L_0x0049697d;
    }
    // 00496953  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496956  7432                   -je 0x49698a
    if (cpu.flags.zf)
    {
        goto L_0x0049698a;
    }
    // 00496958  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049695b  7438                   -je 0x496995
    if (cpu.flags.zf)
    {
        goto L_0x00496995;
    }
    // 0049695d  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496960  743e                   -je 0x4969a0
    if (cpu.flags.zf)
    {
        goto L_0x004969a0;
    }
    // 00496962  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496965  7444                   -je 0x4969ab
    if (cpu.flags.zf)
    {
        goto L_0x004969ab;
    }
    // 00496967  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049696a  744c                   -je 0x4969b8
    if (cpu.flags.zf)
    {
        goto L_0x004969b8;
    }
L_0x0049696c:
    // 0049696c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049696e  81c400020000           +add esp, 0x200
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496974  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496975  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496976  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496977  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496978  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496979:
    // 00496979  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049697b  ebef                   -jmp 0x49696c
    goto L_0x0049696c;
L_0x0049697d:
    // 0049697d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049697f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496981  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496983  e86cc20000             -call 0x4a2bf4
    cpu.esp -= 4;
    sub_4a2bf4(app, cpu);
    if (cpu.terminate) return;
    // 00496988  ebe2                   -jmp 0x49696c
    goto L_0x0049696c;
L_0x0049698a:
    // 0049698a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049698c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049698e  e805fdffff             -call 0x496698
    cpu.esp -= 4;
    sub_496698(app, cpu);
    if (cpu.terminate) return;
    // 00496993  ebd7                   -jmp 0x49696c
    goto L_0x0049696c;
L_0x00496995:
    // 00496995  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496997  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496999  e88afcffff             -call 0x496628
    cpu.esp -= 4;
    sub_496628(app, cpu);
    if (cpu.terminate) return;
    // 0049699e  ebcc                   -jmp 0x49696c
    goto L_0x0049696c;
L_0x004969a0:
    // 004969a0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004969a2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004969a4  e8effdffff             -call 0x496798
    cpu.esp -= 4;
    sub_496798(app, cpu);
    if (cpu.terminate) return;
    // 004969a9  ebc1                   -jmp 0x49696c
    goto L_0x0049696c;
L_0x004969ab:
    // 004969ab  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004969ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004969af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004969b1  e84ac10000             -call 0x4a2b00
    cpu.esp -= 4;
    sub_4a2b00(app, cpu);
    if (cpu.terminate) return;
    // 004969b6  ebb4                   -jmp 0x49696c
    goto L_0x0049696c;
L_0x004969b8:
    // 004969b8  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 004969bd  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004969bf  e8703b0000             -call 0x49a534
    cpu.esp -= 4;
    sub_49a534(app, cpu);
    if (cpu.terminate) return;
    // 004969c4  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 004969c9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004969cb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004969cd  e856fcffff             -call 0x496628
    cpu.esp -= 4;
    sub_496628(app, cpu);
    if (cpu.terminate) return;
    // 004969d2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004969d4  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004969da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004969de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4969e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004969e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004969e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004969e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004969e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004969e4  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004969ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004969ec  e89fa2ffff             -call 0x490c90
    cpu.esp -= 4;
    sub_490c90(app, cpu);
    if (cpu.terminate) return;
    // 004969f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004969f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004969f5  0f84b4000000           -je 0x496aaf
    if (cpu.flags.zf)
    {
        goto L_0x00496aaf;
    }
    // 004969fb  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004969fd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496a03  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496a06  83fb29                 +cmp ebx, 0x29
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a09  7444                   -je 0x496a4f
    if (cpu.flags.zf)
    {
        goto L_0x00496a4f;
    }
    // 00496a0b  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00496a0e  66c781fe0100000000     -mov word ptr [ecx + 0x1fe], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(510) /* 0x1fe */) = 0 /*0x0*/;
    // 00496a17  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00496a19  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00496a1b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496a21  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00496a24  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a27  742a                   -je 0x496a53
    if (cpu.flags.zf)
    {
        goto L_0x00496a53;
    }
    // 00496a29  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a2c  743d                   -je 0x496a6b
    if (cpu.flags.zf)
    {
        goto L_0x00496a6b;
    }
    // 00496a2e  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a31  7443                   -je 0x496a76
    if (cpu.flags.zf)
    {
        goto L_0x00496a76;
    }
    // 00496a33  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a36  7428                   -je 0x496a60
    if (cpu.flags.zf)
    {
        goto L_0x00496a60;
    }
    // 00496a38  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a3b  7444                   -je 0x496a81
    if (cpu.flags.zf)
    {
        goto L_0x00496a81;
    }
    // 00496a3d  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a40  7457                   -je 0x496a99
    if (cpu.flags.zf)
    {
        goto L_0x00496a99;
    }
L_0x00496a42:
    // 00496a42  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496a44  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496a4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496a4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496a4f:
    // 00496a4f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496a51  ebef                   -jmp 0x496a42
    goto L_0x00496a42;
L_0x00496a53:
    // 00496a53  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00496a55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496a57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496a59  e896c10000             -call 0x4a2bf4
    cpu.esp -= 4;
    sub_4a2bf4(app, cpu);
    if (cpu.terminate) return;
    // 00496a5e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00496a60:
    // 00496a60  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496a62  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496a64  e83ff9ffff             -call 0x4963a8
    cpu.esp -= 4;
    sub_4963a8(app, cpu);
    if (cpu.terminate) return;
    // 00496a69  ebd7                   -jmp 0x496a42
    goto L_0x00496a42;
L_0x00496a6b:
    // 00496a6b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496a6d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496a6f  e814f9ffff             -call 0x496388
    cpu.esp -= 4;
    sub_496388(app, cpu);
    if (cpu.terminate) return;
    // 00496a74  ebcc                   -jmp 0x496a42
    goto L_0x00496a42;
L_0x00496a76:
    // 00496a76  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496a78  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496a7a  e8a9fbffff             -call 0x496628
    cpu.esp -= 4;
    sub_496628(app, cpu);
    if (cpu.terminate) return;
    // 00496a7f  ebc1                   -jmp 0x496a42
    goto L_0x00496a42;
L_0x00496a81:
    // 00496a81  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00496a83  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496a85  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496a87  e874c00000             -call 0x4a2b00
    cpu.esp -= 4;
    sub_4a2b00(app, cpu);
    if (cpu.terminate) return;
    // 00496a8c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496a8e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496a90  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496a92  e811f9ffff             -call 0x4963a8
    cpu.esp -= 4;
    sub_4963a8(app, cpu);
    if (cpu.terminate) return;
    // 00496a97  eba9                   -jmp 0x496a42
    goto L_0x00496a42;
L_0x00496a99:
    // 00496a99  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00496a9b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496a9d  e8923a0000             -call 0x49a534
    cpu.esp -= 4;
    sub_49a534(app, cpu);
    if (cpu.terminate) return;
    // 00496aa2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496aa4  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00496aaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496aab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496aac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496aad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496aae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496aaf:
    // 00496aaf  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00496ab4  b8709f5200             -mov eax, 0x529f70
    cpu.eax = 5414768 /*0x529f70*/;
    // 00496ab9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496abb  e8e8f8ffff             -call 0x4963a8
    cpu.esp -= 4;
    sub_4963a8(app, cpu);
    if (cpu.terminate) return;
    // 00496ac0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00496ac2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496ac4  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00496aca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496acb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496acc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496acd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496ace  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496ad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496ad3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496ad4  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00496ada  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00496adc  e8afa1ffff             -call 0x490c90
    cpu.esp -= 4;
    sub_490c90(app, cpu);
    if (cpu.terminate) return;
    // 00496ae1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496ae3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496ae5  0f84e1000000           -je 0x496bcc
    if (cpu.flags.zf)
    {
        goto L_0x00496bcc;
    }
    // 00496aeb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00496aed  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496af3  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496af6  83f92c                 +cmp ecx, 0x2c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496af9  7445                   -je 0x496b40
    if (cpu.flags.zf)
    {
        goto L_0x00496b40;
    }
    // 00496afb  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00496afe  c786fc03000000000000   -mov dword ptr [esi + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00496b08  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00496b0a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00496b0c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496b12  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00496b15  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b18  742a                   -je 0x496b44
    if (cpu.flags.zf)
    {
        goto L_0x00496b44;
    }
    // 00496b1a  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b1d  743d                   -je 0x496b5c
    if (cpu.flags.zf)
    {
        goto L_0x00496b5c;
    }
    // 00496b1f  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b22  744e                   -je 0x496b72
    if (cpu.flags.zf)
    {
        goto L_0x00496b72;
    }
    // 00496b24  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b27  7454                   -je 0x496b7d
    if (cpu.flags.zf)
    {
        goto L_0x00496b7d;
    }
    // 00496b29  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b2c  745a                   -je 0x496b88
    if (cpu.flags.zf)
    {
        goto L_0x00496b88;
    }
    // 00496b2e  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b31  746d                   -je 0x496ba0
    if (cpu.flags.zf)
    {
        goto L_0x00496ba0;
    }
L_0x00496b33:
    // 00496b33  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496b35  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496b3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496b3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496b3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496b3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496b3f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496b40:
    // 00496b40  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496b42  ebef                   -jmp 0x496b33
    goto L_0x00496b33;
L_0x00496b44:
    // 00496b44  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00496b46  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496b48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496b4a  e8a5c00000             -call 0x4a2bf4
    cpu.esp -= 4;
    sub_4a2bf4(app, cpu);
    if (cpu.terminate) return;
    // 00496b4f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496b51  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496b53  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496b55  e85ef9ffff             -call 0x4964b8
    cpu.esp -= 4;
    sub_4964b8(app, cpu);
    if (cpu.terminate) return;
    // 00496b5a  ebd7                   -jmp 0x496b33
    goto L_0x00496b33;
L_0x00496b5c:
    // 00496b5c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00496b5e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496b60  e833fbffff             -call 0x496698
    cpu.esp -= 4;
    sub_496698(app, cpu);
    if (cpu.terminate) return;
    // 00496b65  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496b67  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496b69  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496b6b  e848f9ffff             -call 0x4964b8
    cpu.esp -= 4;
    sub_4964b8(app, cpu);
    if (cpu.terminate) return;
    // 00496b70  ebc1                   -jmp 0x496b33
    goto L_0x00496b33;
L_0x00496b72:
    // 00496b72  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00496b74  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496b76  e8adfaffff             -call 0x496628
    cpu.esp -= 4;
    sub_496628(app, cpu);
    if (cpu.terminate) return;
    // 00496b7b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00496b7d:
    // 00496b7d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496b7f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496b81  e832f9ffff             -call 0x4964b8
    cpu.esp -= 4;
    sub_4964b8(app, cpu);
    if (cpu.terminate) return;
    // 00496b86  ebab                   -jmp 0x496b33
    goto L_0x00496b33;
L_0x00496b88:
    // 00496b88  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00496b8a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496b8c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496b8e  e86dbf0000             -call 0x4a2b00
    cpu.esp -= 4;
    sub_4a2b00(app, cpu);
    if (cpu.terminate) return;
    // 00496b93  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496b95  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496b97  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496b99  e81af9ffff             -call 0x4964b8
    cpu.esp -= 4;
    sub_4964b8(app, cpu);
    if (cpu.terminate) return;
    // 00496b9e  eb93                   -jmp 0x496b33
    goto L_0x00496b33;
L_0x00496ba0:
    // 00496ba0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496ba2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496ba4  e88b390000             -call 0x49a534
    cpu.esp -= 4;
    sub_49a534(app, cpu);
    if (cpu.terminate) return;
    // 00496ba9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00496bab  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496bad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496baf  e8e4faffff             -call 0x496698
    cpu.esp -= 4;
    sub_496698(app, cpu);
    if (cpu.terminate) return;
    // 00496bb4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496bb6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00496bb8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496bba  e8f9f8ffff             -call 0x4964b8
    cpu.esp -= 4;
    sub_4964b8(app, cpu);
    if (cpu.terminate) return;
    // 00496bbf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496bc1  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00496bc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496bc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496bc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496bca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496bcb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496bcc:
    // 00496bcc  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00496bd1  b8709f5200             -mov eax, 0x529f70
    cpu.eax = 5414768 /*0x529f70*/;
    // 00496bd6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496bd8  e8dbf8ffff             -call 0x4964b8
    cpu.esp -= 4;
    sub_4964b8(app, cpu);
    if (cpu.terminate) return;
    // 00496bdd  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00496bdf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496be1  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00496be7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496be8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496be9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496bea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496beb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496bec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496bec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496bed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496bee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496bef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496bf0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496bf3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496bf5  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00496bf9  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00496bfb  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496c01  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496c03  e8a0fcffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496c08  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00496c0f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496c11  e892fcffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496c16  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496c18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496c1a  8a8164cd4c00           -mov al, byte ptr [ecx + 0x4ccd64]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5033316) /* 0x4ccd64 */);
    // 00496c20  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496c22  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00496c25  39c2                   +cmp edx, eax
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
    // 00496c27  754d                   -jne 0x496c76
    if (!cpu.flags.zf)
    {
        goto L_0x00496c76;
    }
    // 00496c29  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00496c2e  7550                   -jne 0x496c80
    if (!cpu.flags.zf)
    {
        goto L_0x00496c80;
    }
    // 00496c30  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496c32  e871fcffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496c37  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00496c3e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496c40  e863fcffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496c45  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496c47  8b2c8564cc4c00         -mov ebp, dword ptr [eax*4 + 0x4ccc64]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5033060) /* 0x4ccc64 */ + cpu.eax * 4);
L_0x00496c4e:
    // 00496c4e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496c50  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496c52  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00496c55  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00496c5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496c5d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496c5f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496c61  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00496c64  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00496c6a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496c6c  83f908                 +cmp ecx, 8
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
    // 00496c6f  7f05                   -jg 0x496c76
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00496c76;
    }
    // 00496c71  83f808                 +cmp eax, 8
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
    // 00496c74  7f2a                   -jg 0x496ca0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00496ca0;
    }
L_0x00496c76:
    // 00496c76  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496c78  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496c7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496c80:
    // 00496c80  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496c82  e821fcffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496c87  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00496c8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496c90  e813fcffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496c95  01c8                   +add eax, ecx
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
    // 00496c97  8b2c8564cb4c00         -mov ebp, dword ptr [eax*4 + 0x4ccb64]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5032804) /* 0x4ccb64 */ + cpu.eax * 4);
    // 00496c9e  ebae                   -jmp 0x496c4e
    goto L_0x00496c4e;
L_0x00496ca0:
    // 00496ca0  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00496ca5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496ca7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00496cac  e857fcffff             -call 0x496908
    cpu.esp -= 4;
    sub_496908(app, cpu);
    if (cpu.terminate) return;
    // 00496cb1  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496cb5  a360cb4c00             -mov dword ptr [0x4ccb60], eax
    app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */) = cpu.eax;
    // 00496cba  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00496cbc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00496cbe  7432                   -je 0x496cf2
    if (cpu.flags.zf)
    {
        goto L_0x00496cf2;
    }
    // 00496cc0  83fe0f                 +cmp esi, 0xf
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
    // 00496cc3  7419                   -je 0x496cde
    if (cpu.flags.zf)
    {
        goto L_0x00496cde;
    }
    // 00496cc5  83fe10                 +cmp esi, 0x10
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
    // 00496cc8  75ac                   -jne 0x496c76
    if (!cpu.flags.zf)
    {
        goto L_0x00496c76;
    }
    // 00496cca  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00496ccf  e8d4f6ffff             -call 0x4963a8
    cpu.esp -= 4;
    sub_4963a8(app, cpu);
    if (cpu.terminate) return;
    // 00496cd4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496cd6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496cd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cdd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496cde:
    // 00496cde  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00496ce3  e8e4f5ffff             -call 0x4962cc
    cpu.esp -= 4;
    sub_4962cc(app, cpu);
    if (cpu.terminate) return;
    // 00496ce8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496cea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496ced  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496cf1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496cf2:
    // 00496cf2  83fe0f                 +cmp esi, 0xf
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
    // 00496cf5  741d                   -je 0x496d14
    if (cpu.flags.zf)
    {
        goto L_0x00496d14;
    }
    // 00496cf7  83fe10                 +cmp esi, 0x10
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
    // 00496cfa  0f8576ffffff           -jne 0x496c76
    if (!cpu.flags.zf)
    {
        goto L_0x00496c76;
    }
    // 00496d00  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00496d05  e8fef6ffff             -call 0x496408
    cpu.esp -= 4;
    sub_496408(app, cpu);
    if (cpu.terminate) return;
    // 00496d0a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496d0c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496d0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496d14:
    // 00496d14  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00496d19  e80ef6ffff             -call 0x49632c
    cpu.esp -= 4;
    sub_49632c(app, cpu);
    if (cpu.terminate) return;
    // 00496d1e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496d20  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496d23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496d27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496d28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496d28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496d29  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496d2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496d2b  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00496d2e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496d30  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00496d34  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00496d38  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00496d3c  e84f9fffff             -call 0x490c90
    cpu.esp -= 4;
    sub_490c90(app, cpu);
    if (cpu.terminate) return;
    // 00496d41  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00496d46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496d48  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00496d4c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00496d50  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
L_0x00496d54:
    // 00496d54  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496d59  0f8580020000           -jne 0x496fdf
    if (!cpu.flags.zf)
    {
        goto L_0x00496fdf;
    }
    // 00496d5f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00496d61  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496d66  e83dfbffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496d6b  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00496d72  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496d76  e82dfbffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496d7b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496d7d  8b048564cc4c00         -mov eax, dword ptr [eax*4 + 0x4ccc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033060) /* 0x4ccc64 */ + cpu.eax * 4);
L_0x00496d84:
    // 00496d84  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00496d88  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00496d8a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496d8f  e814fbffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496d94  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00496d9b  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496d9f  e804fbffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496da4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496da6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496da8  8a8264cd4c00           -mov al, byte ptr [edx + 0x4ccd64]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5033316) /* 0x4ccd64 */);
    // 00496dae  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00496db2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496db4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496db6  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00496db9  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00496dbf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496dc1  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00496dc5  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496dc9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496dcb  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00496dce  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00496dd4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496dd6  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00496dda  40                     -inc eax
    (cpu.eax)++;
    // 00496ddb  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00496ddd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496ddf  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00496de2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496de5  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00496de9  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00496dec  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496def  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00496df3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496df5  e8163c0000             -call 0x49aa10
    cpu.esp -= 4;
    sub_49aa10(app, cpu);
    if (cpu.terminate) return;
    // 00496dfa  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00496dfe  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00496e02  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00496e05  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00496e08  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00496e0a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00496e0c  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 00496e0f  83f908                 +cmp ecx, 8
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
    // 00496e12  0f8f73000000           -jg 0x496e8b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00496e8b;
    }
    // 00496e18  83fb08                 +cmp ebx, 8
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
    // 00496e1b  7e6e                   -jle 0x496e8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496e8b;
    }
    // 00496e1d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00496e22  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496e26  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00496e28  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496e2a  0f84d9010000           -je 0x497009
    if (cpu.flags.zf)
    {
        goto L_0x00497009;
    }
    // 00496e30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496e32  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496e34  7e1e                   -jle 0x496e54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496e54;
    }
    // 00496e36  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00496e38:
    // 00496e38  0fb6b03cc74c00         -movzx esi, byte ptr [eax + 0x4cc73c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */));
    // 00496e3f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496e42  8b34b5709f5200         -mov esi, dword ptr [esi*4 + 0x529f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5414768) /* 0x529f70 */ + cpu.esi * 4);
    // 00496e49  40                     -inc eax
    (cpu.eax)++;
    // 00496e4a  89b16ca35200           -mov dword ptr [ecx + 0x52a36c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5415788) /* 0x52a36c */) = cpu.esi;
    // 00496e50  39d8                   +cmp eax, ebx
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
    // 00496e52  7ce4                   -jl 0x496e38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496e38;
    }
L_0x00496e54:
    // 00496e54  c70560cb4c0070a35200   -mov dword ptr [0x4ccb60], 0x52a370
    app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */) = 5415792 /*0x52a370*/;
L_0x00496e5e:
    // 00496e5e  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496e63  0f84d5010000           -je 0x49703e
    if (cpu.flags.zf)
    {
        goto L_0x0049703e;
    }
    // 00496e69  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496e6d  83f80f                 +cmp eax, 0xf
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
    // 00496e70  0f85ab010000           -jne 0x497021
    if (!cpu.flags.zf)
    {
        goto L_0x00497021;
    }
    // 00496e76  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00496e7b  a160cb4c00             -mov eax, dword ptr [0x4ccb60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */);
    // 00496e80  e847f4ffff             -call 0x4962cc
    cpu.esp -= 4;
    sub_4962cc(app, cpu);
    if (cpu.terminate) return;
L_0x00496e85:
    // 00496e85  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496e87  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
L_0x00496e8b:
    // 00496e8b  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496e8f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496e90  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496e94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496e95  689c124c00             -push 0x4c129c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4985500 /*0x4c129c*/;
    cpu.esp -= 4;
    // 00496e9a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496e9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496e9f  e83d51feff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00496ea4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496ea7  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00496eab  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00496eae  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496eb0  8b1d3ca44c00           -mov ebx, dword ptr [0x4ca43c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 00496eb6  8d5614                 -lea edx, [esi + 0x14]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00496eb9  e86a33feff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00496ebe  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00496ec3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496ec5  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00496ec9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00496ecb  ba50485343             -mov edx, 0x43534850
    cpu.edx = 1129531472 /*0x43534850*/;
    // 00496ed0  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496ed3  e8fcbdfeff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00496ed8  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496edc  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00496edf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496ee4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00496ee6  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00496ee8  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00496eec  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00496eee  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00496ef0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496ef6  66894104               -mov word ptr [ecx + 4], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00496efa  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00496efe  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00496f00  66894106               -mov word ptr [ecx + 6], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00496f04  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00496f08  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00496f0c  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00496f10  668b510c               -mov dx, word ptr [ecx + 0xc]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00496f14  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00496f18  81e200f0ffff           -and edx, 0xfffff000
    cpu.edx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00496f1e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00496f21  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 00496f25  25ff0f0000             -and eax, 0xfff
    cpu.eax &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00496f2a  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00496f2d  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496f30  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00496f32  8971fc                 -mov dword ptr [ecx - 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00496f35  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00496f39  8d7710                 -lea esi, [edi + 0x10]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00496f3c  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00496f42  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00496f45  668959fe               -mov word ptr [ecx - 2], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00496f49  250000ff0f             -and eax, 0xfff0000
    cpu.eax &= x86::reg32(x86::sreg32(268369920 /*0xfff0000*/));
    // 00496f4e  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00496f51  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00496f53  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00496f55  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00496f59  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00496f5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496f5e  7e1d                   -jle 0x496f7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496f7d;
    }
L_0x00496f60:
    // 00496f60  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00496f64  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00496f66  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496f68  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f6c  47                     -inc edi
    (cpu.edi)++;
    // 00496f6d  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496f71  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00496f75  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00496f77  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496f79  39d7                   +cmp edi, edx
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
    // 00496f7b  7ce3                   -jl 0x496f60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496f60;
    }
L_0x00496f7d:
    // 00496f7d  0faf6c2454             -imul ebp, dword ptr [esp + 0x54]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 00496f82  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496f86  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00496f88  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00496f8d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496f90  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496f94  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496f96  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00496f98  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00496f9a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00496fa1  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00496fa3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496fa5  7407                   -je 0x496fae
    if (cpu.flags.zf)
    {
        goto L_0x00496fae;
    }
    // 00496fa7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496fa9  e8de36feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x00496fae:
    // 00496fae  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496fb2  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00496fb6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00496fb8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496fba  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496fbe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496fc3  39f0                   +cmp eax, esi
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
    // 00496fc5  740f                   -je 0x496fd6
    if (cpu.flags.zf)
    {
        goto L_0x00496fd6;
    }
    // 00496fc7  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496fcb  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00496fcc  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 00496fd0  0f857efdffff           -jne 0x496d54
    if (!cpu.flags.zf)
    {
        goto L_0x00496d54;
    }
L_0x00496fd6:
    // 00496fd6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496fd8  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00496fdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496fdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496fdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496fde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496fdf:
    // 00496fdf  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00496fe1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496fe6  e8bdf8ffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496feb  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00496ff2  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496ff6  e8adf8ffff             -call 0x4968a8
    cpu.esp -= 4;
    sub_4968a8(app, cpu);
    if (cpu.terminate) return;
    // 00496ffb  01d0                   +add eax, edx
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
    // 00496ffd  8b048564cb4c00         -mov eax, dword ptr [eax*4 + 0x4ccb64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032804) /* 0x4ccb64 */ + cpu.eax * 4);
    // 00497004  e97bfdffff             -jmp 0x496d84
    goto L_0x00496d84;
L_0x00497009:
    // 00497009  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 0049700e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497012  e8f1f8ffff             -call 0x496908
    cpu.esp -= 4;
    sub_496908(app, cpu);
    if (cpu.terminate) return;
    // 00497017  a360cb4c00             -mov dword ptr [0x4ccb60], eax
    app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */) = cpu.eax;
    // 0049701c  e93dfeffff             -jmp 0x496e5e
    goto L_0x00496e5e;
L_0x00497021:
    // 00497021  83f810                 +cmp eax, 0x10
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
    // 00497024  0f855bfeffff           -jne 0x496e85
    if (!cpu.flags.zf)
    {
        goto L_0x00496e85;
    }
    // 0049702a  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 0049702f  a160cb4c00             -mov eax, dword ptr [0x4ccb60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */);
    // 00497034  e86ff3ffff             -call 0x4963a8
    cpu.esp -= 4;
    sub_4963a8(app, cpu);
    if (cpu.terminate) return;
    // 00497039  e947feffff             -jmp 0x496e85
    goto L_0x00496e85;
L_0x0049703e:
    // 0049703e  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00497042  83f90f                 +cmp ecx, 0xf
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
    // 00497045  741d                   -je 0x497064
    if (cpu.flags.zf)
    {
        goto L_0x00497064;
    }
    // 00497047  83f910                 +cmp ecx, 0x10
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
    // 0049704a  0f8535feffff           -jne 0x496e85
    if (!cpu.flags.zf)
    {
        goto L_0x00496e85;
    }
    // 00497050  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00497055  a160cb4c00             -mov eax, dword ptr [0x4ccb60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */);
    // 0049705a  e8a9f3ffff             -call 0x496408
    cpu.esp -= 4;
    sub_496408(app, cpu);
    if (cpu.terminate) return;
    // 0049705f  e921feffff             -jmp 0x496e85
    goto L_0x00496e85;
L_0x00497064:
    // 00497064  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 00497069  a160cb4c00             -mov eax, dword ptr [0x4ccb60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032800) /* 0x4ccb60 */);
    // 0049706e  e8b9f2ffff             -call 0x49632c
    cpu.esp -= 4;
    sub_49632c(app, cpu);
    if (cpu.terminate) return;
    // 00497073  e90dfeffff             -jmp 0x496e85
    goto L_0x00496e85;
}

/* align: skip  */
void Application::sub_497078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497078  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497079  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049707a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049707f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497081  e8a2fcffff             -call 0x496d28
    cpu.esp -= 4;
    sub_496d28(app, cpu);
    if (cpu.terminate) return;
    // 00497086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49708c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049708c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049708d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049708e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049708f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00497091  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497093  e8c8380000             -call 0x49a960
    cpu.esp -= 4;
    sub_49a960(app, cpu);
    if (cpu.terminate) return;
    // 00497098  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049709d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049709f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004970a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004970a3  e880fcffff             -call 0x496d28
    cpu.esp -= 4;
    sub_496d28(app, cpu);
    if (cpu.terminate) return;
    // 004970a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004970a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004970aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004970ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4970b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004970b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004970b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004970b2  81ec00140000           -sub esp, 0x1400
    (cpu.esp) -= x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 004970b8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004970ba  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004970bc  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004970be  ff1574a75200           -call dword ptr [0x52a774]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5416820) /* 0x52a774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004970c4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004970c6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004970c8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004970ca  ff1570a75200           -call dword ptr [0x52a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5416816) /* 0x52a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004970d0  81c400140000           -add esp, 0x1400
    (cpu.esp) += x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 004970d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004970d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004970d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4970dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004970dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004970dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004970de  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004970df  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004970e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004970e4  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004970e8  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004970ec  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004970ee  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004970f0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004970f3  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 004970f9  0fb62dd9a64c00         -movzx ebp, byte ptr [0x4ca6d9]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */));
    // 00497100  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00497103  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497105  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00497108  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049710c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00497110  891574a75200           -mov dword ptr [0x52a774], edx
    app->getMemory<x86::reg32>(x86::reg32(5416820) /* 0x52a774 */) = cpu.edx;
    // 00497116  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00497118  7402                   -je 0x49711c
    if (cpu.flags.zf)
    {
        goto L_0x0049711c;
    }
    // 0049711a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0049711c:
    // 0049711c  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497121  7540                   -jne 0x497163
    if (!cpu.flags.zf)
    {
        goto L_0x00497163;
    }
    // 00497123  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00497125  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049712a  39e8                   +cmp eax, ebp
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
    // 0049712c  7435                   -je 0x497163
    if (cpu.flags.zf)
    {
        goto L_0x00497163;
    }
    // 0049712e  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497132  0f8464020000           -je 0x49739c
    if (cpu.flags.zf)
    {
        goto L_0x0049739c;
    }
    // 00497138  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0049713d:
    // 0049713d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049713f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497141  e8a6faffff             -call 0x496bec
    cpu.esp -= 4;
    sub_496bec(app, cpu);
    if (cpu.terminate) return;
    // 00497146  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049714a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049714c  0f8451020000           -je 0x4973a3
    if (cpu.flags.zf)
    {
        goto L_0x004973a3;
    }
    // 00497152  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497156  740b                   -je 0x497163
    if (cpu.flags.zf)
    {
        goto L_0x00497163;
    }
    // 00497158  a374a75200             -mov dword ptr [0x52a774], eax
    app->getMemory<x86::reg32>(x86::reg32(5416820) /* 0x52a774 */) = cpu.eax;
    // 0049715d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049715f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00497163:
    // 00497163  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00497166  8b6e02                 -mov ebp, dword ptr [esi + 2]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00497169  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049716b  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049716e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00497170  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00497173  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00497179  40                     -inc eax
    (cpu.eax)++;
    // 0049717a  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049717c  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 0049717f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497181  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00497183  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00497186  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00497189  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049718d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049718f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497193  e878380000             -call 0x49aa10
    cpu.esp -= 4;
    sub_49aa10(app, cpu);
    if (cpu.terminate) return;
    // 00497198  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049719a  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049719e  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004971a2  a1cca64c00             -mov eax, dword ptr [0x4ca6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 004971a7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004971a9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004971ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004971ae  7e15                   -jle 0x4971c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004971c5;
    }
    // 004971b0  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004971b4  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004971b7  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004971b9  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004971bd  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004971bf  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004971c1  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x004971c5:
    // 004971c5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004971c9  8b35d4a64c00           -mov esi, dword ptr [0x4ca6d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004971cf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004971d1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004971d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004971d5  7e02                   -jle 0x4971d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004971d9;
    }
    // 004971d7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004971d9:
    // 004971d9  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004971dd  a1c8a64c00             -mov eax, dword ptr [0x4ca6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 004971e2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004971e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004971e6  7e20                   -jle 0x497208
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497208;
    }
    // 004971e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004971ea  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004971ed  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 004971f0  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004971f3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004971f5  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004971f9  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004971fb  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004971fd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00497200  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00497204  01442420               -add dword ptr [esp + 0x20], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00497208:
    // 00497208  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049720c  8b35d0a64c00           -mov esi, dword ptr [0x4ca6d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 00497212  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00497214  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00497216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497218  7e0e                   -jle 0x497228
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497228;
    }
    // 0049721a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049721c  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049721f  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 00497222  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00497224  01742420               -add dword ptr [esp + 0x20], esi
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00497228:
    // 00497228  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049722a  0f8e59010000           -jle 0x497389
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497389;
    }
    // 00497230  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497232  0f8e51010000           -jle 0x497389
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497389;
    }
    // 00497238  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049723b  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00497240  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00497244  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497246  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0049724b  40                     -inc eax
    (cpu.eax)++;
    // 0049724c  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049724e  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00497251  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 00497254  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00497257  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049725b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049725f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497263  8b1de8a64c00           -mov ebx, dword ptr [0x4ca6e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00497269  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049726c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049726e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00497272  8b35eca64c00           -mov esi, dword ptr [0x4ca6ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00497278  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049727b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049727d  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049727f  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00497281  a1e4a64c00             -mov eax, dword ptr [0x4ca6e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 00497286  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00497288  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049728c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049728e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00497292  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00497296  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049729a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049729c  0f8542010000           -jne 0x4973e4
    if (!cpu.flags.zf)
    {
        goto L_0x004973e4;
    }
    // 004972a2  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 004972a7  3c0f                   +cmp al, 0xf
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
    // 004972a9  0f833e010000           -jae 0x4973ed
    if (!cpu.flags.cf)
    {
        goto L_0x004973ed;
    }
    // 004972af  3c04                   +cmp al, 4
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
    // 004972b1  0f837e010000           -jae 0x497435
    if (!cpu.flags.cf)
    {
        goto L_0x00497435;
    }
L_0x004972b7:
    // 004972b7  833d74a7520000         +cmp dword ptr [0x52a774], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5416820) /* 0x52a774 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004972be  0f8592010000           -jne 0x497456
    if (!cpu.flags.zf)
    {
        goto L_0x00497456;
    }
L_0x004972c4:
    // 004972c4  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004972c8  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004972cc  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004972d0  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004972d4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004972d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004972da  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004972de:
    // 004972de  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004972e2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004972e4  745a                   -je 0x497340
    if (cpu.flags.zf)
    {
        goto L_0x00497340;
    }
    // 004972e6  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004972ea  a1f0a64c00             -mov eax, dword ptr [0x4ca6f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023472) /* 0x4ca6f0 */);
    // 004972ef  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004972f1  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004972f3  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004972f5  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004972f9  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004972fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004972ff  0f8480010000           -je 0x497485
    if (cpu.flags.zf)
    {
        goto L_0x00497485;
    }
    // 00497305  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497307  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
L_0x0049730b:
    // 0049730b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049730f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00497311  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497313  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00497315  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497319  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049731d  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00497321  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00497325  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00497327  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497329  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049732b  8b1d34a44c00           -mov ebx, dword ptr [0x4ca434]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022772) /* 0x4ca434 */);
    // 00497331  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00497335  39da                   +cmp edx, ebx
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
    // 00497337  0f8f30010000           -jg 0x49746d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049746d;
    }
L_0x0049733d:
    // 0049733d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049733e  75cb                   -jne 0x49730b
    if (!cpu.flags.zf)
    {
        goto L_0x0049730b;
    }
L_0x00497340:
    // 00497340  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497344  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497346  7436                   -je 0x49737e
    if (cpu.flags.zf)
    {
        goto L_0x0049737e;
    }
    // 00497348  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049734b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049734d  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00497351  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00497355  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00497357  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00497359  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049735d  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497361  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00497365  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00497369  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049736d  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049736f  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497373  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497375  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00497377  47                     -inc edi
    (cpu.edi)++;
    // 00497378  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049737a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
L_0x0049737e:
    // 0049737e  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497383  0f8f55ffffff           -jg 0x4972de
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004972de;
    }
L_0x00497389:
    // 00497389  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049738d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049738f  0f8550010000           -jne 0x4974e5
    if (!cpu.flags.zf)
    {
        goto L_0x004974e5;
    }
L_0x00497395:
    // 00497395  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00497398  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497399  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049739a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049739b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049739c:
    // 0049739c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049739e  e99afdffff             -jmp 0x49713d
    goto L_0x0049713d;
L_0x004973a3:
    // 004973a3  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004973a7  7421                   -je 0x4973ca
    if (cpu.flags.zf)
    {
        goto L_0x004973ca;
    }
    // 004973a9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004973ae:
    // 004973ae  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004973b1  83fb01                 +cmp ebx, 1
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
    // 004973b4  7518                   -jne 0x4973ce
    if (!cpu.flags.zf)
    {
        goto L_0x004973ce;
    }
    // 004973b6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004973b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004973ba  e869f9ffff             -call 0x496d28
    cpu.esp -= 4;
    sub_496d28(app, cpu);
    if (cpu.terminate) return;
    // 004973bf  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004973c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004973c5  e999fdffff             -jmp 0x497163
    goto L_0x00497163;
L_0x004973ca:
    // 004973ca  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004973cc  ebe0                   -jmp 0x4973ae
    goto L_0x004973ae;
L_0x004973ce:
    // 004973ce  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004973d0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004973d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004973d4  e84ff9ffff             -call 0x496d28
    cpu.esp -= 4;
    sub_496d28(app, cpu);
    if (cpu.terminate) return;
    // 004973d9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004973dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004973df  e97ffdffff             -jmp 0x497163
    goto L_0x00497163;
L_0x004973e4:
    // 004973e4  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004973e8  e9d7feffff             -jmp 0x4972c4
    goto L_0x004972c4;
L_0x004973ed:
    // 004973ed  770c                   -ja 0x4973fb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004973fb;
    }
    // 004973ef  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004973f2  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004973f6  e9bcfeffff             -jmp 0x4972b7
    goto L_0x004972b7;
L_0x004973fb:
    // 004973fb  3c18                   +cmp al, 0x18
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
    // 004973fd  7314                   -jae 0x497413
    if (!cpu.flags.cf)
    {
        goto L_0x00497413;
    }
    // 004973ff  3c10                   +cmp al, 0x10
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
    // 00497401  0f85b0feffff           -jne 0x4972b7
    if (!cpu.flags.zf)
    {
        goto L_0x004972b7;
    }
    // 00497407  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049740a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049740e  e9a4feffff             -jmp 0x4972b7
    goto L_0x004972b7;
L_0x00497413:
    // 00497413  770c                   -ja 0x497421
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00497421;
    }
    // 00497415  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00497418  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049741c  e996feffff             -jmp 0x4972b7
    goto L_0x004972b7;
L_0x00497421:
    // 00497421  3c20                   +cmp al, 0x20
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
    // 00497423  0f858efeffff           -jne 0x4972b7
    if (!cpu.flags.zf)
    {
        goto L_0x004972b7;
    }
    // 00497429  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0049742c  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00497430  e982feffff             -jmp 0x4972b7
    goto L_0x004972b7;
L_0x00497435:
    // 00497435  770b                   -ja 0x497442
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00497442;
    }
    // 00497437  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00497439  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049743d  e975feffff             -jmp 0x4972b7
    goto L_0x004972b7;
L_0x00497442:
    // 00497442  3c08                   +cmp al, 8
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
    // 00497444  0f856dfeffff           -jne 0x4972b7
    if (!cpu.flags.zf)
    {
        goto L_0x004972b7;
    }
    // 0049744a  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049744d  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00497451  e961feffff             -jmp 0x4972b7
    goto L_0x004972b7;
L_0x00497456:
    // 00497456  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049745a  bbb0704900             -mov ebx, 0x4970b0
    cpu.ebx = 4812976 /*0x4970b0*/;
    // 0049745f  a370a75200             -mov dword ptr [0x52a770], eax
    app->getMemory<x86::reg32>(x86::reg32(5416816) /* 0x52a770 */) = cpu.eax;
    // 00497464  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00497468  e957feffff             -jmp 0x4972c4
    goto L_0x004972c4;
L_0x0049746d:
    // 0049746d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049746f  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00497473  e8e028feff             -call 0x479d58
    cpu.esp -= 4;
    sub_479d58(app, cpu);
    if (cpu.terminate) return;
    // 00497478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049747a  0f8415ffffff           -je 0x497395
    if (cpu.flags.zf)
    {
        goto L_0x00497395;
    }
    // 00497480  e9b8feffff             -jmp 0x49733d
    goto L_0x0049733d;
L_0x00497485:
    // 00497485  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 0049748a  7422                   -je 0x4974ae
    if (cpu.flags.zf)
    {
        goto L_0x004974ae;
    }
L_0x0049748c:
    // 0049748c  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00497490  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00497492  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497494  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00497496  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049749a  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049749e  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004974a2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004974a4  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004974a6  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004974a7  75e3                   -jne 0x49748c
    if (!cpu.flags.zf)
    {
        goto L_0x0049748c;
    }
    // 004974a9  e992feffff             -jmp 0x497340
    goto L_0x00497340;
L_0x004974ae:
    // 004974ae  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 004974b3  75d7                   -jne 0x49748c
    if (!cpu.flags.zf)
    {
        goto L_0x0049748c;
    }
    // 004974b5  817c2438b0704900       +cmp dword ptr [esp + 0x38], 0x4970b0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4812976 /*0x4970b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004974bd  74cd                   -je 0x49748c
    if (cpu.flags.zf)
    {
        goto L_0x0049748c;
    }
    // 004974bf  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004974c1  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004974c4  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004974c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004974ca  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004974cc  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004974d0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004974d4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004974d7  0faf7c2418             -imul edi, dword ptr [esp + 0x18]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004974dc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004974de  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004974e0  e95bfeffff             -jmp 0x497340
    goto L_0x00497340;
L_0x004974e5:
    // 004974e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004974e7  e8a031feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004974ec  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004974ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497501  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497502  833da8cd4c0000         +cmp dword ptr [0x4ccda8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497509  742c                   -je 0x497537
    if (cpu.flags.zf)
    {
        goto L_0x00497537;
    }
L_0x0049750b:
    // 0049750b  8b15a4cd4c00           -mov edx, dword ptr [0x4ccda4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033380) /* 0x4ccda4 */);
    // 00497511  a1a8cd4c00             -mov eax, dword ptr [0x4ccda8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */);
    // 00497516  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00497519  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049751c  8b15a4cd4c00           -mov edx, dword ptr [0x4ccda4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033380) /* 0x4ccda4 */);
    // 00497522  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00497529  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049752c  891d78a75200           -mov dword ptr [0x52a778], ebx
    app->getMemory<x86::reg32>(x86::reg32(5416824) /* 0x52a778 */) = cpu.ebx;
    // 00497532  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00497534  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497535  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497537:
    // 00497537  b844134c00             -mov eax, 0x4c1344
    cpu.eax = 4985668 /*0x4c1344*/;
    // 0049753c  8b15a4cd4c00           -mov edx, dword ptr [0x4ccda4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033380) /* 0x4ccda4 */);
    // 00497542  8b1d3ca44c00           -mov ebx, dword ptr [0x4ca43c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 00497548  c1e202                 +shl edx, 2
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
    // 0049754b  e8d82cfeff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00497550  a3a8cd4c00             -mov dword ptr [0x4ccda8], eax
    app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */) = cpu.eax;
    // 00497555  ebb4                   -jmp 0x49750b
    goto L_0x0049750b;
}

/* align: skip 0x90 */
void Application::sub_497558(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497558  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497559  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049755a  8b15a8cd4c00           -mov edx, dword ptr [0x4ccda8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */);
    // 00497560  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497562  750b                   -jne 0x49756f
    if (!cpu.flags.zf)
    {
        goto L_0x0049756f;
    }
    // 00497564  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00497566  890da8cd4c00           -mov dword ptr [0x4ccda8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */) = cpu.ecx;
    // 0049756c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049756d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049756e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049756f:
    // 0049756f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497571  e81631feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00497576  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00497578  890da8cd4c00           -mov dword ptr [0x4ccda8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */) = cpu.ecx;
    // 0049757e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049757f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497584  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497585  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497586  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497587  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049758a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049758c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049758f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00497593  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00497595  a1a8cd4c00             -mov eax, dword ptr [0x4ccda8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */);
    // 0049759a  8b1578a75200           -mov edx, dword ptr [0x52a778]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416824) /* 0x52a778 */);
    // 004975a0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004975a2  39d0                   +cmp eax, edx
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
    // 004975a4  7335                   -jae 0x4975db
    if (!cpu.flags.cf)
    {
        goto L_0x004975db;
    }
    // 004975a6  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004975aa  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004975ad  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004975af  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004975b1:
    // 004975b1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004975b3  39f9                   +cmp ecx, edi
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
    // 004975b5  7c14                   -jl 0x4975cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004975cb;
    }
    // 004975b7  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004975bb  0f8674000000           -jbe 0x497635
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497635;
    }
    // 004975c1  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004975c4  7505                   -jne 0x4975cb
    if (!cpu.flags.zf)
    {
        goto L_0x004975cb;
    }
    // 004975c6  3b500c                 +cmp edx, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004975c9  745e                   -je 0x497629
    if (cpu.flags.zf)
    {
        goto L_0x00497629;
    }
L_0x004975cb:
    // 004975cb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004975ce  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004975d1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004975d3  3b0578a75200           +cmp eax, dword ptr [0x52a778]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5416824) /* 0x52a778 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004975d9  72d6                   -jb 0x4975b1
    if (cpu.flags.cf)
    {
        goto L_0x004975b1;
    }
L_0x004975db:
    // 004975db  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004975dd  0f846f000000           -je 0x497652
    if (cpu.flags.zf)
    {
        goto L_0x00497652;
    }
    // 004975e3  8d5708                 -lea edx, [edi + 8]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004975e6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004975e8  39d0                   +cmp eax, edx
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
    // 004975ea  7d51                   -jge 0x49763d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049763d;
    }
    // 004975ec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004975ee:
    // 004975ee  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004975f1  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004975f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004975f6  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004975fc  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004975ff  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00497601  7e1d                   -jle 0x497620
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497620;
    }
    // 00497603  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00497605:
    // 00497605  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497609  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049760b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049760e  40                     -inc eax
    (cpu.eax)++;
    // 0049760f  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 00497611  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00497614  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00497617  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00497619  39f8                   +cmp eax, edi
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
    // 0049761b  7ce8                   -jl 0x497605
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497605;
    }
    // 0049761d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00497620:
    // 00497620  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00497622:
    // 00497622  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497625  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497626  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497627  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497628  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497629:
    // 00497629  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049762c  83c008                 +add eax, 8
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
    // 0049762f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00497630  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00497633  ebed                   -jmp 0x497622
    goto L_0x00497622;
L_0x00497635:
    // 00497635  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00497637  7592                   -jne 0x4975cb
    if (!cpu.flags.zf)
    {
        goto L_0x004975cb;
    }
    // 00497639  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049763b  eb8e                   -jmp 0x4975cb
    goto L_0x004975cb;
L_0x0049763d:
    // 0049763d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049763f  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00497641  c744bb0c00000000       -mov dword ptr [ebx + edi*4 + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.edi * 4) = 0 /*0x0*/;
    // 00497649  83ea02                 +sub edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049764c  8954bb08               -mov dword ptr [ebx + edi*4 + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edi * 4) = cpu.edx;
    // 00497650  eb9c                   -jmp 0x4975ee
    goto L_0x004975ee;
L_0x00497652:
    // 00497652  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497654  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497657  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497658  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049765a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49765c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049765c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049765d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049765e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049765f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497660  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497661  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497663  8d48f8                 -lea ecx, [eax - 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00497666  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00497669  4a                     -dec edx
    (cpu.edx)--;
    // 0049766a  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049766d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049766f  7606                   -jbe 0x497677
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497677;
    }
L_0x00497671:
    // 00497671  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497673  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497674  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497675  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497676  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497677:
    // 00497677  a1a8cd4c00             -mov eax, dword ptr [0x4ccda8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */);
    // 0049767c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049767e  39c8                   +cmp eax, ecx
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
    // 00497680  7312                   -jae 0x497694
    if (!cpu.flags.cf)
    {
        goto L_0x00497694;
    }
L_0x00497682:
    // 00497682  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00497684  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00497687  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049768a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049768c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049768e  39c8                   +cmp eax, ecx
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
    // 00497690  72f0                   -jb 0x497682
    if (cpu.flags.cf)
    {
        goto L_0x00497682;
    }
    // 00497692  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00497694:
    // 00497694  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00497696  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00497699  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049769c  8b3578a75200           -mov esi, dword ptr [0x52a778]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5416824) /* 0x52a778 */);
    // 004976a2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004976a4  39f2                   +cmp edx, esi
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
    // 004976a6  7306                   -jae 0x4976ae
    if (!cpu.flags.cf)
    {
        goto L_0x004976ae;
    }
    // 004976a8  837a0400               +cmp dword ptr [edx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004976ac  761b                   -jbe 0x4976c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004976c9;
    }
L_0x004976ae:
    // 004976ae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004976b0  74bf                   -je 0x497671
    if (cpu.flags.zf)
    {
        goto L_0x00497671;
    }
    // 004976b2  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004976b6  77b9                   -ja 0x497671
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00497671;
    }
    // 004976b8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004976ba  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004976bc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004976bf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004976c1  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004976c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004976c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004976c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004976c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004976c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004976c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004976c9:
    // 004976c9  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004976cb  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004976cd  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004976d0  01d5                   +add ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004976d2  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 004976d4  ebd8                   -jmp 0x4976ae
    goto L_0x004976ae;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4976d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004976d8  a3a8cd4c00             -mov dword ptr [0x4ccda8], eax
    app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */) = cpu.eax;
    // 004976dd  8915a4cd4c00           -mov dword ptr [0x4ccda4], edx
    app->getMemory<x86::reg32>(x86::reg32(5033380) /* 0x4ccda4 */) = cpu.edx;
    // 004976e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4976e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004976e4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004976e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004976e6  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 004976eb  0f8599000000           -jne 0x49778a
    if (!cpu.flags.zf)
    {
        goto L_0x0049778a;
    }
L_0x004976f1:
    // 004976f1  83eb20                 +sub ebx, 0x20
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
    // 004976f4  7839                   -js 0x49772f
    if (cpu.flags.sf)
    {
        goto L_0x0049772f;
    }
L_0x004976f6:
    // 004976f6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004976f8  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004976fa  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004976fd  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00497700  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00497703  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00497706  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497709  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049770c  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049770f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497712  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00497715  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497718  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049771b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049771e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00497721  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497724  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00497727  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049772a  83eb20                 +sub ebx, 0x20
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
    // 0049772d  79c7                   -jns 0x4976f6
    if (!cpu.flags.sf)
    {
        goto L_0x004976f6;
    }
L_0x0049772f:
    // 0049772f  83c318                 +add ebx, 0x18
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
    // 00497732  7815                   -js 0x497749
    if (cpu.flags.sf)
    {
        goto L_0x00497749;
    }
L_0x00497734:
    // 00497734  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00497736  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00497738  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049773b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049773e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00497741  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00497744  83eb08                 +sub ebx, 8
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
    // 00497747  79eb                   -jns 0x497734
    if (!cpu.flags.sf)
    {
        goto L_0x00497734;
    }
L_0x00497749:
    // 00497749  83c308                 +add ebx, 8
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
    // 0049774c  7502                   -jne 0x497750
    if (!cpu.flags.zf)
    {
        goto L_0x00497750;
    }
    // 0049774e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049774f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497750:
    // 00497750  83fb04                 +cmp ebx, 4
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
    // 00497753  720d                   -jb 0x497762
    if (cpu.flags.cf)
    {
        goto L_0x00497762;
    }
    // 00497755  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00497757  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049775a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049775c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049775f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00497762:
    // 00497762  83fb02                 +cmp ebx, 2
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
    // 00497765  720f                   -jb 0x497776
    if (cpu.flags.cf)
    {
        goto L_0x00497776;
    }
    // 00497767  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049776a  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049776d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00497770  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00497773  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00497776:
    // 00497776  83fb01                 +cmp ebx, 1
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
    // 00497779  720d                   -jb 0x497788
    if (cpu.flags.cf)
    {
        goto L_0x00497788;
    }
    // 0049777b  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049777d  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00497780  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00497782  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00497785  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00497788:
    // 00497788  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497789  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049778a:
    // 0049778a  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049778f  7412                   -je 0x4977a3
    if (cpu.flags.zf)
    {
        goto L_0x004977a3;
    }
    // 00497791  83fb01                 +cmp ebx, 1
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
    // 00497794  7c0d                   -jl 0x4977a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004977a3;
    }
    // 00497796  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00497798  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049779b  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049779d  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004977a0  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004977a3:
    // 004977a3  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004977a8  7414                   -je 0x4977be
    if (cpu.flags.zf)
    {
        goto L_0x004977be;
    }
    // 004977aa  83fb02                 +cmp ebx, 2
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
    // 004977ad  7c0f                   -jl 0x4977be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004977be;
    }
    // 004977af  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004977b2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004977b5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004977b8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004977bb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004977be:
    // 004977be  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004977c3  7412                   -je 0x4977d7
    if (cpu.flags.zf)
    {
        goto L_0x004977d7;
    }
    // 004977c5  83fb04                 +cmp ebx, 4
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
    // 004977c8  7c0d                   -jl 0x4977d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004977d7;
    }
    // 004977ca  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004977cc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004977cf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004977d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004977d4  83eb04                 +sub ebx, 4
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
L_0x004977d7:
    // 004977d7  e915ffffff             -jmp 0x4976f1
    goto L_0x004976f1;
}

/* align: skip  */
void Application::sub_4976e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004976e5;
    // 004976e4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x004976e5:
    // 004976e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004976e6  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 004976eb  0f8599000000           -jne 0x49778a
    if (!cpu.flags.zf)
    {
        goto L_0x0049778a;
    }
L_0x004976f1:
    // 004976f1  83eb20                 +sub ebx, 0x20
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
    // 004976f4  7839                   -js 0x49772f
    if (cpu.flags.sf)
    {
        goto L_0x0049772f;
    }
L_0x004976f6:
    // 004976f6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004976f8  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004976fa  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004976fd  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00497700  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00497703  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00497706  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497709  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049770c  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049770f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497712  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00497715  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497718  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049771b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049771e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00497721  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497724  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00497727  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049772a  83eb20                 +sub ebx, 0x20
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
    // 0049772d  79c7                   -jns 0x4976f6
    if (!cpu.flags.sf)
    {
        goto L_0x004976f6;
    }
L_0x0049772f:
    // 0049772f  83c318                 +add ebx, 0x18
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
    // 00497732  7815                   -js 0x497749
    if (cpu.flags.sf)
    {
        goto L_0x00497749;
    }
L_0x00497734:
    // 00497734  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00497736  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00497738  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049773b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049773e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00497741  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00497744  83eb08                 +sub ebx, 8
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
    // 00497747  79eb                   -jns 0x497734
    if (!cpu.flags.sf)
    {
        goto L_0x00497734;
    }
L_0x00497749:
    // 00497749  83c308                 +add ebx, 8
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
    // 0049774c  7502                   -jne 0x497750
    if (!cpu.flags.zf)
    {
        goto L_0x00497750;
    }
    // 0049774e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049774f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497750:
    // 00497750  83fb04                 +cmp ebx, 4
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
    // 00497753  720d                   -jb 0x497762
    if (cpu.flags.cf)
    {
        goto L_0x00497762;
    }
    // 00497755  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00497757  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049775a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049775c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049775f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00497762:
    // 00497762  83fb02                 +cmp ebx, 2
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
    // 00497765  720f                   -jb 0x497776
    if (cpu.flags.cf)
    {
        goto L_0x00497776;
    }
    // 00497767  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049776a  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049776d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00497770  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00497773  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00497776:
    // 00497776  83fb01                 +cmp ebx, 1
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
    // 00497779  720d                   -jb 0x497788
    if (cpu.flags.cf)
    {
        goto L_0x00497788;
    }
    // 0049777b  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049777d  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00497780  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00497782  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00497785  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00497788:
    // 00497788  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497789  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049778a:
    // 0049778a  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049778f  7412                   -je 0x4977a3
    if (cpu.flags.zf)
    {
        goto L_0x004977a3;
    }
    // 00497791  83fb01                 +cmp ebx, 1
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
    // 00497794  7c0d                   -jl 0x4977a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004977a3;
    }
    // 00497796  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00497798  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049779b  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049779d  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004977a0  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004977a3:
    // 004977a3  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004977a8  7414                   -je 0x4977be
    if (cpu.flags.zf)
    {
        goto L_0x004977be;
    }
    // 004977aa  83fb02                 +cmp ebx, 2
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
    // 004977ad  7c0f                   -jl 0x4977be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004977be;
    }
    // 004977af  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004977b2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004977b5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004977b8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004977bb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004977be:
    // 004977be  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004977c3  7412                   -je 0x4977d7
    if (cpu.flags.zf)
    {
        goto L_0x004977d7;
    }
    // 004977c5  83fb04                 +cmp ebx, 4
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
    // 004977c8  7c0d                   -jl 0x4977d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004977d7;
    }
    // 004977ca  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004977cc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004977cf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004977d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004977d4  83eb04                 +sub ebx, 4
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
L_0x004977d7:
    // 004977d7  e915ffffff             -jmp 0x4976f1
    goto L_0x004976f1;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4977e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004977e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004977e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004977e2  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004977e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004977ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004977eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4977ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004977ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004977ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004977ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004977ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004977f0  e89792feff             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 004977f5  8b15b4a75200           -mov edx, dword ptr [0x52a7b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 004977fb  a3accd4c00             -mov dword ptr [0x4ccdac], eax
    app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */) = cpu.eax;
    // 00497800  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497802  7453                   -je 0x497857
    if (cpu.flags.zf)
    {
        goto L_0x00497857;
    }
L_0x00497804:
    // 00497804  a1accd4c00             -mov eax, dword ptr [0x4ccdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */);
    // 00497809  e8ce92feff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0049780e  8b1db4a75200           -mov ebx, dword ptr [0x52a7b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 00497814  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00497816  7436                   -je 0x49784e
    if (cpu.flags.zf)
    {
        goto L_0x0049784e;
    }
    // 00497818  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049781a  e8a993feff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0049781f  8b3580a75200           -mov esi, dword ptr [0x52a780]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5416832) /* 0x52a780 */);
    // 00497825  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497827  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00497829  7419                   -je 0x497844
    if (cpu.flags.zf)
    {
        goto L_0x00497844;
    }
L_0x0049782b:
    // 0049782b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049782d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497830  ff9080a75200           -call dword ptr [eax + 0x52a780]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416832) /* 0x52a780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497836  83fa20                 +cmp edx, 0x20
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
    // 00497839  7d09                   -jge 0x497844
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497844;
    }
    // 0049783b  83ba80a7520000         +cmp dword ptr [edx + 0x52a780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5416832) /* 0x52a780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497842  75e7                   -jne 0x49782b
    if (!cpu.flags.zf)
    {
        goto L_0x0049782b;
    }
L_0x00497844:
    // 00497844  a1b4a75200             -mov eax, dword ptr [0x52a7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 00497849  e89293feff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0049784e:
    // 0049784e  833db4a7520000         +cmp dword ptr [0x52a7b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497855  75ad                   -jne 0x497804
    if (!cpu.flags.zf)
    {
        goto L_0x00497804;
    }
L_0x00497857:
    // 00497857  a1accd4c00             -mov eax, dword ptr [0x4ccdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */);
    // 0049785c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049785e  e80593feff             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 00497863  892daccd4c00           -mov dword ptr [0x4ccdac], ebp
    app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */) = cpu.ebp;
    // 00497869  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049786a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049786b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049786c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049786d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497873  8b15b4a75200           -mov edx, dword ptr [0x52a7b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 00497879  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049787b  7504                   -jne 0x497881
    if (!cpu.flags.zf)
    {
        goto L_0x00497881;
    }
L_0x0049787d:
    // 0049787d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049787e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049787f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497880  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497881:
    // 00497881  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00497883  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00497885  e83e93feff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0049788a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049788c  b8a0a75200             -mov eax, 0x52a7a0
    cpu.eax = 5416864 /*0x52a7a0*/;
    // 00497891  8b15accd4c00           -mov edx, dword ptr [0x4ccdac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */);
    // 00497897  891db4a75200           -mov dword ptr [0x52a7b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */) = cpu.ebx;
    // 0049789d  e8fe91feff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 004978a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004978a4  e83793feff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004978a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004978ab  e84493feff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 004978b0  b8a0a75200             -mov eax, 0x52a7a0
    cpu.eax = 5416864 /*0x52a7a0*/;
    // 004978b5  e8ae8ffeff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 004978ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004978bc  75bf                   -jne 0x49787d
    if (!cpu.flags.zf)
    {
        goto L_0x0049787d;
    }
    // 004978be  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004978c0:
    // 004978c0  3b15accd4c00           +cmp edx, dword ptr [0x4ccdac]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5033388) /* 0x4ccdac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004978c6  74b5                   -je 0x49787d
    if (cpu.flags.zf)
    {
        goto L_0x0049787d;
    }
    // 004978c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004978ca  e84d8ffeff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004978cf  ebef                   -jmp 0x4978c0
    goto L_0x004978c0;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4978d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004978d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004978d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004978d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004978d7  b870784900             -mov eax, 0x497870
    cpu.eax = 4814960 /*0x497870*/;
    // 004978dc  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004978e1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004978e6  e8f18dffff             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 004978eb  e88892feff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 004978f0  a3b4a75200             -mov dword ptr [0x52a7b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */) = cpu.eax;
    // 004978f5  e8ce92feff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004978fa  68a0a75200             -push 0x52a7a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5416864 /*0x52a7a0*/;
    cpu.esp -= 4;
    // 004978ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497901  b8ec774900             -mov eax, 0x4977ec
    cpu.eax = 4814828 /*0x4977ec*/;
    // 00497906  e8558efeff             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 0049790b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049790d  7516                   -jne 0x497925
    if (!cpu.flags.zf)
    {
        goto L_0x00497925;
    }
    // 0049790f  a1b4a75200             -mov eax, dword ptr [0x52a7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 00497914  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497916  e8d992feff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 0049791b  8915b4a75200           -mov dword ptr [0x52a7b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */) = cpu.edx;
    // 00497921  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497922  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497923  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497924  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497925:
    // 00497925  a1b4a75200             -mov eax, dword ptr [0x52a7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5416884) /* 0x52a7b4 */);
    // 0049792a  e8b192feff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0049792f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497930  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497932  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
