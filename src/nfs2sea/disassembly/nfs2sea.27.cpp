#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4a25cf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a25cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a25d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a25d1  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004a25d7  7423                   -je 0x4a25fc
    if (cpu.flags.zf)
    {
        goto L_0x004a25fc;
    }
    // 004a25d9  83fb01                 +cmp ebx, 1
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
    // 004a25dc  7c1e                   -jl 0x4a25fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a25fc;
    }
    // 004a25de  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a25e1  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a25e4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a25e6  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 004a25ec  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a25ee  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a25f1  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a25f3  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a25f6  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a25f9  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x004a25fc:
    // 004a25fc  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25ff  7821                   -js 0x4a2622
    if (cpu.flags.sf)
    {
        goto L_0x004a2622;
    }
L_0x004a2601:
    // 004a2601  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2603  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2606  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a2608  81e1e07fe07f           -and ecx, 0x7fe07fe0
    cpu.ecx &= x86::reg32(x86::sreg32(2145419232 /*0x7fe07fe0*/));
    // 004a260e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2610  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a2616  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2618  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a261b  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004a261d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a2620  79df                   -jns 0x4a2601
    if (!cpu.flags.sf)
    {
        goto L_0x004a2601;
    }
L_0x004a2622:
    // 004a2622  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2625  7820                   -js 0x4a2647
    if (cpu.flags.sf)
    {
        goto L_0x004a2647;
    }
L_0x004a2627:
    // 004a2627  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a262a  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a262d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a262f  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 004a2635  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2637  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a263a  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a263c  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a263f  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a2642  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a2645  79e0                   -jns 0x4a2627
    if (!cpu.flags.sf)
    {
        goto L_0x004a2627;
    }
L_0x004a2647:
    // 004a2647  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2648  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2649  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a264a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a264a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a264b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a264c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a264d  8b3d90ad4d00           -mov edi, dword ptr [0x4dad90]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090704) /* 0x4dad90 */);
    // 004a2653  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a2655:
    // 004a2655  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2657  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a265a  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a265d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a2660  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a2663  8972fc                 -mov dword ptr [edx - 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004a2666  7fed                   -jg 0x4a2655
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a2655;
    }
    // 004a2668  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2669  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a266a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a266b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a266c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a266c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a266d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a266e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a266f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2670  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a2672  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a2674  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a2676  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2678  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a267a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a267c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a267e  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2681  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 004a2687  754e                   -jne 0x4a26d7
    if (!cpu.flags.zf)
    {
        goto L_0x004a26d7;
    }
    // 004a2689  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a268c  7849                   -js 0x4a26d7
    if (cpu.flags.sf)
    {
        goto L_0x004a26d7;
    }
    // 004a268e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a2691  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a2693  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a2696  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
L_0x004a2699:
    // 004a2699  8b04451acb5600         -mov eax, dword ptr [eax*2 + 0x56cb1a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688090) /* 0x56cb1a */ + cpu.eax * 2);
    // 004a26a0  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a26a3  8b0c4d1acb5600         -mov ecx, dword ptr [ecx*2 + 0x56cb1a]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5688090) /* 0x56cb1a */ + cpu.ecx * 2);
    // 004a26aa  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a26ad  668b045d1ccb5600       -mov ax, word ptr [ebx*2 + 0x56cb1c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.ebx * 2);
    // 004a26b5  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a26b7  668b0c551ccb5600       -mov cx, word ptr [edx*2 + 0x56cb1c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.edx * 2);
    // 004a26bf  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a26c2  8947f8                 -mov dword ptr [edi - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004a26c5  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a26c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a26ca  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a26cc  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a26cf  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a26d2  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a26d5  79c2                   -jns 0x4a2699
    if (!cpu.flags.sf)
    {
        goto L_0x004a2699;
    }
L_0x004a26d7:
    // 004a26d7  83c503                 +add ebp, 3
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a26da  7818                   -js 0x4a26f4
    if (cpu.flags.sf)
    {
        goto L_0x004a26f4;
    }
L_0x004a26dc:
    // 004a26dc  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a26de  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a26e1  668b04551ccb5600       -mov ax, word ptr [edx*2 + 0x56cb1c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.edx * 2);
    // 004a26e9  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a26ec  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a26ef  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a26f2  79e8                   -jns 0x4a26dc
    if (!cpu.flags.sf)
    {
        goto L_0x004a26dc;
    }
L_0x004a26f4:
    // 004a26f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a26f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a26f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a26f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a26f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a26f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a26f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a26fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a26fb  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a26fe  83eb04                 +sub ebx, 4
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
    // 004a2701  783f                   -js 0x4a2742
    if (cpu.flags.sf)
    {
        goto L_0x004a2742;
    }
L_0x004a2703:
    // 004a2703  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a2705  8b4e03                 -mov ecx, dword ptr [esi + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a2708  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a270a  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a270c  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a2711  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a2717  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a2719  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a271c  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004a271f  8b4e09                 -mov ecx, dword ptr [esi + 9]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 004a2722  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a2724  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a2726  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a272b  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a2731  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a2734  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a2737  83eb04                 +sub ebx, 4
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
    // 004a273a  8d760c                 -lea esi, [esi + 0xc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a273d  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a2740  79c1                   -jns 0x4a2703
    if (!cpu.flags.sf)
    {
        goto L_0x004a2703;
    }
L_0x004a2742:
    // 004a2742  83c303                 +add ebx, 3
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2745  7816                   -js 0x4a275d
    if (cpu.flags.sf)
    {
        goto L_0x004a275d;
    }
L_0x004a2747:
    // 004a2747  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a2749  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a274b  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a2750  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a2752  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2755  8d7603                 -lea esi, [esi + 3]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a2758  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a275b  79ea                   -jns 0x4a2747
    if (!cpu.flags.sf)
    {
        goto L_0x004a2747;
    }
L_0x004a275d:
    // 004a275d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a275e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a275f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2763  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2766  782f                   -js 0x4a2797
    if (cpu.flags.sf)
    {
        goto L_0x004a2797;
    }
L_0x004a2768:
    // 004a2768  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a276a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a276c  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 004a2772  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 004a2775  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a2777  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 004a277d  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a277f  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a2785  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 004a2788  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a278a  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004a278c  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a278f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2792  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a2795  79d1                   -jns 0x4a2768
    if (!cpu.flags.sf)
    {
        goto L_0x004a2768;
    }
L_0x004a2797:
    // 004a2797  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a279a  7831                   -js 0x4a27cd
    if (cpu.flags.sf)
    {
        goto L_0x004a27cd;
    }
L_0x004a279c:
    // 004a279c  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a279f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a27a1  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 004a27a7  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 004a27aa  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a27ac  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 004a27b2  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a27b4  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a27ba  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 004a27bd  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a27bf  66893a                 -mov word ptr [edx], di
    app->getMemory<x86::reg16>(cpu.edx) = cpu.di;
    // 004a27c2  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a27c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a27c8  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a27cb  79cf                   -jns 0x4a279c
    if (!cpu.flags.sf)
    {
        goto L_0x004a279c;
    }
L_0x004a27cd:
    // 004a27cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a27d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a27d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a27d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a27d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a27d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a27d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a27d7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a27d9  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a27db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a27dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a27df  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a27e1  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a27e4  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 004a27ea  754e                   -jne 0x4a283a
    if (!cpu.flags.zf)
    {
        goto L_0x004a283a;
    }
    // 004a27ec  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a27ef  7849                   -js 0x4a283a
    if (cpu.flags.sf)
    {
        goto L_0x004a283a;
    }
    // 004a27f1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a27f3  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
L_0x004a27f6:
    // 004a27f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a27f8  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004a27fb  8b144d1acb5600         -mov edx, dword ptr [ecx*2 + 0x56cb1a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688090) /* 0x56cb1a */ + cpu.ecx * 2);
    // 004a2802  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a2805  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a2807  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004a280a  8b0c4d1acb5600         -mov ecx, dword ptr [ecx*2 + 0x56cb1a]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5688090) /* 0x56cb1a */ + cpu.ecx * 2);
    // 004a2811  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a2814  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a2817  668b14451ccb5600       -mov dx, word ptr [eax*2 + 0x56cb1c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.eax * 2);
    // 004a281f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a2821  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a2824  668b0c5d1ccb5600       -mov cx, word ptr [ebx*2 + 0x56cb1c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.ebx * 2);
    // 004a282c  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a282f  8957f8                 -mov dword ptr [edi - 8], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004a2832  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a2835  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2838  79bc                   -jns 0x4a27f6
    if (!cpu.flags.sf)
    {
        goto L_0x004a27f6;
    }
L_0x004a283a:
    // 004a283a  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a283d  7827                   -js 0x4a2866
    if (cpu.flags.sf)
    {
        goto L_0x004a2866;
    }
L_0x004a283f:
    // 004a283f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a2841  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004a2844  8b144d1acb5600         -mov edx, dword ptr [ecx*2 + 0x56cb1a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688090) /* 0x56cb1a */ + cpu.ecx * 2);
    // 004a284b  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a284e  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a2851  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a2854  668b14451ccb5600       -mov dx, word ptr [eax*2 + 0x56cb1c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.eax * 2);
    // 004a285c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a285e  8957fc                 -mov dword ptr [edi - 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a2861  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2864  79d9                   -jns 0x4a283f
    if (!cpu.flags.sf)
    {
        goto L_0x004a283f;
    }
L_0x004a2866:
    // 004a2866  83c501                 +add ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2869  780e                   -js 0x4a2879
    if (cpu.flags.sf)
    {
        goto L_0x004a2879;
    }
    // 004a286b  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a286e  668b14451ccb5600       -mov dx, word ptr [eax*2 + 0x56cb1c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.eax * 2);
    // 004a2876  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
L_0x004a2879:
    // 004a2879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a287a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a287b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a287c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a287d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a287e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a287e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a287f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2880  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2881  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2884  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2886  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a2888  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2889  2eff15c8444c00         -call dword ptr cs:[0x4c44c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998344) /* 0x4c44c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2890  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2892  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004a2896  2d6c070000             -sub eax, 0x76c
    (cpu.eax) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004a289b  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a289e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28a0  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004a28a5  48                     -dec eax
    (cpu.eax)--;
    // 004a28a6  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a28a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28ab  668b442406             -mov ax, word ptr [esp + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004a28b0  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a28b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28b5  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a28ba  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a28bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28bf  668b44240a             -mov ax, word ptr [esp + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(10) /* 0xa */);
    // 004a28c4  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a28c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28c9  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a28ce  c74320ffffffff         -mov dword ptr [ebx + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 004a28d5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a28d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28d9  668b44240e             -mov ax, word ptr [esp + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 004a28de  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a28e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a28e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a28e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a28e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a28e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a28e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a28e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a28ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a28eb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a28ee  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a28f0  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004a28f5  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a28f8  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a28fb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a28fe  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2900  b9b8fe4c00             -mov ecx, 0x4cfeb8
    cpu.ecx = 5045944 /*0x4cfeb8*/;
    // 004a2905  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a2908  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a290a  81fea17efbf4           +cmp esi, 0xf4fb7ea1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4110122657 /*0xf4fb7ea1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2910  7d0a                   -jge 0x4a291c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a291c;
    }
L_0x004a2912:
    // 004a2912  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a2917  e94e010000             -jmp 0x4a2a6a
    goto L_0x004a2a6a;
L_0x004a291c:
    // 004a291c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a291f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a2921  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2924  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2926  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a2928:
    // 004a2928  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a292a  7d06                   -jge 0x4a2932
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a2932;
    }
    // 004a292c  4e                     -dec esi
    (cpu.esi)--;
    // 004a292d  83c70c                 +add edi, 0xc
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2930  ebf6                   -jmp 0x4a2928
    goto L_0x004a2928;
L_0x004a2932:
    // 004a2932  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2934  7cdc                   -jl 0x4a2912
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2912;
    }
    // 004a2936  8d866c070000           -lea eax, [esi + 0x76c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1900) /* 0x76c */);
    // 004a293c  e8e3fc0000             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004a2941  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2943  7405                   -je 0x4a294a
    if (cpu.flags.zf)
    {
        goto L_0x004a294a;
    }
    // 004a2945  b9d2fe4c00             -mov ecx, 0x4cfed2
    cpu.ecx = 5045970 /*0x4cfed2*/;
L_0x004a294a:
    // 004a294a  8d5603                 -lea edx, [esi + 3]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a294d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a294f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2952  c1e202                 +shl edx, 2
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
    // 004a2955  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a2957  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004a295a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a295c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a295e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a2961  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a2963  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a2966  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a2968  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a296a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a296d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a296f  8d5663                 -lea edx, [esi + 0x63]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(99) /* 0x63 */);
    // 004a2972  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2974  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004a2979  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a297c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a297e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2981  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2983  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a2986  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2988  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a298b  8d962b010000           -lea edx, [esi + 0x12b]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(299) /* 0x12b */);
    // 004a2991  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 004a2996  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2998  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a299b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a299d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a29a0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a29a2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a29a4  0fbf0441               -movsx eax, word ptr [ecx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2)));
    // 004a29a8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a29aa  03450c                 -add eax, dword ptr [ebp + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004a29ad  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a29b0  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a29b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a29b5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a29b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a29ba  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a29bd  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004a29c0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a29c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a29c4  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a29c7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a29c9  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a29cc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a29cf  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a29d1:
    // 004a29d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a29d3  7d09                   -jge 0x4a29de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a29de;
    }
    // 004a29d5  4f                     -dec edi
    (cpu.edi)--;
    // 004a29d6  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a29dc  ebf3                   -jmp 0x4a29d1
    goto L_0x004a29d1;
L_0x004a29de:
    // 004a29de  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a29e0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a29e2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a29e4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a29e6  e872000100             -call 0x4b2a5d
    cpu.esp -= 4;
    sub_4b2a5d(app, cpu);
    if (cpu.terminate) return;
    // 004a29eb  e8ec020100             -call 0x4b2cdc
    cpu.esp -= 4;
    sub_4b2cdc(app, cpu);
    if (cpu.terminate) return;
    // 004a29f0  8b1d32e34d00           -mov ebx, dword ptr [0x4de332]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */);
    // 004a29f6  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004a29f9  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a29fb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a29fd  7d07                   -jge 0x4a2a06
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a2a06;
    }
    // 004a29ff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a2a01  e878fd0000             -call 0x4b277e
    cpu.esp -= 4;
    sub_4b277e(app, cpu);
    if (cpu.terminate) return;
L_0x004a2a06:
    // 004a2a06  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2a0a  7e06                   -jle 0x4a2a12
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2a12;
    }
    // 004a2a0c  2b353ae34d00           -sub esi, dword ptr [0x4de33a]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */)));
L_0x004a2a12:
    // 004a2a12  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2a14  7d09                   -jge 0x4a2a1f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a2a1f;
    }
    // 004a2a16  4f                     -dec edi
    (cpu.edi)--;
    // 004a2a17  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2a1d  ebf3                   -jmp 0x4a2a12
    goto L_0x004a2a12;
L_0x004a2a1f:
    // 004a2a1f  81ffde630000           +cmp edi, 0x63de
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25566 /*0x63de*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2a25  0f8ce7feffff           -jl 0x4a2912
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2912;
    }
    // 004a2a2b  751d                   -jne 0x4a2a4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a2a4a;
    }
    // 004a2a2d  8b1d32e34d00           -mov ebx, dword ptr [0x4de332]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */);
    // 004a2a33  81ee80510100           -sub esi, 0x15180
    (cpu.esi) -= x86::reg32(x86::sreg32(86400 /*0x15180*/));
    // 004a2a39  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2a3b  0f8ed1feffff           -jle 0x4a2912
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2912;
    }
    // 004a2a41  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2a43  7d23                   -jge 0x4a2a68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a2a68;
    }
    // 004a2a45  e9c8feffff             -jmp 0x4a2912
    goto L_0x004a2912;
L_0x004a2a4a:
    // 004a2a4a  8d87219cffff           -lea eax, [edi - 0x63df]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-25567) /* -0x63df */);
    // 004a2a50  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2a52  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004a2a55  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2a57  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 004a2a5a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a2a5c  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 004a2a5f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2a61  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004a2a64  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2a66  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004a2a68:
    // 004a2a68  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a2a6a:
    // 004a2a6a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2a6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2a74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2a74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2a75  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004a2a76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2a77  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a2a79  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a2a7c  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004a2a7d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a7e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a2a80  3500002000             -xor eax, 0x200000
    cpu.eax ^= x86::reg32(x86::sreg32(2097152 /*0x200000*/));
    // 004a2a85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a86  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a87  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004a2a88  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a89  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2a8b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2a8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a8e  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2a91(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2a91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2a92  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2a93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2a94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2a95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2a96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a97  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2a99  0fa2                   -cpuid 
    cpu.cpuid();
    // 004a2a9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a9c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a2a9e  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a2aa1  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a2aa4  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a2aa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2aa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2aa9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2aaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2aab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2aac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2aad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2aad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2aae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2aaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2ab1  9e                     -sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a2ab2  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a2ab7  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a2abc  f6f3                   -div bl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.bl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
    // 004a2abe  9f                     -lahf 
    cpu.ah = 0x02 | (cpu.flags.lo & 0xD7);
    // 004a2abf  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2ac2  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a2ac7  7505                   -jne 0x4a2ace
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ace;
    }
    // 004a2ac9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a2ace:
    // 004a2ace  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2acf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ad0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2ad1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2ad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2ad3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2ad4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2ad5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a2ad7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a2ad9  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004a2ade  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a2ae0  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a2ae2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2ae3  e30b                   -jecxz 0x4a2af0
    if (cpu.ecx == 0)
    {
        goto L_0x004a2af0;
    }
    // 004a2ae5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a2ae7  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a2ae9  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004a2aeb  7503                   -jne 0x4a2af0
    if (!cpu.flags.zf)
    {
        goto L_0x004a2af0;
    }
    // 004a2aed  4f                     -dec edi
    (cpu.edi)--;
    // 004a2aee  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004a2af2;
L_0x004a2af0:
    // 004a2af0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004a2af2:
    // 004a2af2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2af3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a2af5:
    // 004a2af5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2af7  740d                   -je 0x4a2b06
    if (cpu.flags.zf)
    {
        goto L_0x004a2b06;
    }
    // 004a2af9  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a2afb  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004a2afd  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a2aff  7405                   -je 0x4a2b06
    if (cpu.flags.zf)
    {
        goto L_0x004a2b06;
    }
    // 004a2b01  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2b02  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2b03  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a2b04  ebef                   -jmp 0x4a2af5
    goto L_0x004a2af5;
L_0x004a2b06:
    // 004a2b06  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004a2b09  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a2b0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2b10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a2b14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2b14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2b15  a1c8894d00             -mov eax, dword ptr [0x4d89c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
    // 004a2b1a  a3a8bc4d00             -mov dword ptr [0x4dbca8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094568) /* 0x4dbca8 */) = cpu.eax;
    // 004a2b1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2b21  7502                   -jne 0x4a2b25
    if (!cpu.flags.zf)
    {
        goto L_0x004a2b25;
    }
    // 004a2b23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2b25:
    // 004a2b25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2b26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2b27  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2b28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2b29  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2b2a  b9ac434b00             -mov ecx, 0x4b43ac
    cpu.ecx = 4932524 /*0x4b43ac*/;
    // 004a2b2f  bbac444b00             -mov ebx, 0x4b44ac
    cpu.ebx = 4932780 /*0x4b44ac*/;
    // 004a2b34  be7c454b00             -mov esi, 0x4b457c
    cpu.esi = 4932988 /*0x4b457c*/;
    // 004a2b39  bf70464b00             -mov edi, 0x4b4670
    cpu.edi = 4933232 /*0x4b4670*/;
    // 004a2b3e  bd50474b00             -mov ebp, 0x4b4750
    cpu.ebp = 4933456 /*0x4b4750*/;
    // 004a2b43  b884474b00             -mov eax, 0x4b4784
    cpu.eax = 4933508 /*0x4b4784*/;
    // 004a2b48  ba34484b00             -mov edx, 0x4b4834
    cpu.edx = 4933684 /*0x4b4834*/;
    // 004a2b4d  890d50bc4d00           -mov dword ptr [0x4dbc50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094480) /* 0x4dbc50 */) = cpu.ecx;
    // 004a2b53  891d54bc4d00           -mov dword ptr [0x4dbc54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094484) /* 0x4dbc54 */) = cpu.ebx;
    // 004a2b59  893558bc4d00           -mov dword ptr [0x4dbc58], esi
    app->getMemory<x86::reg32>(x86::reg32(5094488) /* 0x4dbc58 */) = cpu.esi;
    // 004a2b5f  893d5cbc4d00           -mov dword ptr [0x4dbc5c], edi
    app->getMemory<x86::reg32>(x86::reg32(5094492) /* 0x4dbc5c */) = cpu.edi;
    // 004a2b65  892d80bc4d00           -mov dword ptr [0x4dbc80], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094528) /* 0x4dbc80 */) = cpu.ebp;
    // 004a2b6b  a384bc4d00             -mov dword ptr [0x4dbc84], eax
    app->getMemory<x86::reg32>(x86::reg32(5094532) /* 0x4dbc84 */) = cpu.eax;
    // 004a2b70  891588bc4d00           -mov dword ptr [0x4dbc88], edx
    app->getMemory<x86::reg32>(x86::reg32(5094536) /* 0x4dbc88 */) = cpu.edx;
    // 004a2b76  b964484b00             -mov ecx, 0x4b4864
    cpu.ecx = 4933732 /*0x4b4864*/;
    // 004a2b7b  bbe4484b00             -mov ebx, 0x4b48e4
    cpu.ebx = 4933860 /*0x4b48e4*/;
    // 004a2b80  be484c4b00             -mov esi, 0x4b4c48
    cpu.esi = 4934728 /*0x4b4c48*/;
    // 004a2b85  bf3c504b00             -mov edi, 0x4b503c
    cpu.edi = 4935740 /*0x4b503c*/;
    // 004a2b8a  bdb0534b00             -mov ebp, 0x4b53b0
    cpu.ebp = 4936624 /*0x4b53b0*/;
    // 004a2b8f  b8f4574b00             -mov eax, 0x4b57f4
    cpu.eax = 4937716 /*0x4b57f4*/;
    // 004a2b94  890d8cbc4d00           -mov dword ptr [0x4dbc8c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094540) /* 0x4dbc8c */) = cpu.ecx;
    // 004a2b9a  891d90bc4d00           -mov dword ptr [0x4dbc90], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094544) /* 0x4dbc90 */) = cpu.ebx;
    // 004a2ba0  893570bc4d00           -mov dword ptr [0x4dbc70], esi
    app->getMemory<x86::reg32>(x86::reg32(5094512) /* 0x4dbc70 */) = cpu.esi;
    // 004a2ba6  893d74bc4d00           -mov dword ptr [0x4dbc74], edi
    app->getMemory<x86::reg32>(x86::reg32(5094516) /* 0x4dbc74 */) = cpu.edi;
    // 004a2bac  892d78bc4d00           -mov dword ptr [0x4dbc78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094520) /* 0x4dbc78 */) = cpu.ebp;
    // 004a2bb2  a37cbc4d00             -mov dword ptr [0x4dbc7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5094524) /* 0x4dbc7c */) = cpu.eax;
    // 004a2bb7  893560bc4d00           -mov dword ptr [0x4dbc60], esi
    app->getMemory<x86::reg32>(x86::reg32(5094496) /* 0x4dbc60 */) = cpu.esi;
    // 004a2bbd  893d64bc4d00           -mov dword ptr [0x4dbc64], edi
    app->getMemory<x86::reg32>(x86::reg32(5094500) /* 0x4dbc64 */) = cpu.edi;
    // 004a2bc3  892d68bc4d00           -mov dword ptr [0x4dbc68], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094504) /* 0x4dbc68 */) = cpu.ebp;
    // 004a2bc9  a36cbc4d00             -mov dword ptr [0x4dbc6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5094508) /* 0x4dbc6c */) = cpu.eax;
    // 004a2bce  bf34584b00             -mov edi, 0x4b5834
    cpu.edi = 4937780 /*0x4b5834*/;
    // 004a2bd3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a2bd5  893d94bc4d00           -mov dword ptr [0x4dbc94], edi
    app->getMemory<x86::reg32>(x86::reg32(5094548) /* 0x4dbc94 */) = cpu.edi;
    // 004a2bdb  892da4bc4d00           -mov dword ptr [0x4dbca4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094564) /* 0x4dbca4 */) = cpu.ebp;
    // 004a2be1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2be2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2be3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2be4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2be5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2be6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2be7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2be8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2be8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2be9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2bea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2beb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2bec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2bed  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2bf0  8b1d98bc4d00           -mov ebx, dword ptr [0x4dbc98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a2bf6  8b35a0bc4d00           -mov esi, dword ptr [0x4dbca0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */);
    // 004a2bfc  8b3d9cbc4d00           -mov edi, dword ptr [0x4dbc9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */);
    // 004a2c02  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a2c04  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a2c06  e8352c0100             -call 0x4b5840
    cpu.esp -= 4;
    sub_4b5840(app, cpu);
    if (cpu.terminate) return;
    // 004a2c0b  e8e02c0100             -call 0x4b58f0
    cpu.esp -= 4;
    sub_4b58f0(app, cpu);
    if (cpu.terminate) return;
    // 004a2c10  e81b2e0100             -call 0x4b5a30
    cpu.esp -= 4;
    sub_4b5a30(app, cpu);
    if (cpu.terminate) return;
    // 004a2c15  e8c62e0100             -call 0x4b5ae0
    cpu.esp -= 4;
    sub_4b5ae0(app, cpu);
    if (cpu.terminate) return;
    // 004a2c1a  8b3d9cbc4d00           -mov edi, dword ptr [0x4dbc9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */);
    // 004a2c20  8b35a0bc4d00           -mov esi, dword ptr [0x4dbca0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */);
L_0x004a2c26:
    // 004a2c26  8b1d98bc4d00           -mov ebx, dword ptr [0x4dbc98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a2c2c  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 004a2c33  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a2c35  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a2c37  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2c3a  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2c3d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a2c3f  7518                   -jne 0x4a2c59
    if (!cpu.flags.zf)
    {
        goto L_0x004a2c59;
    }
L_0x004a2c41:
    // 004a2c41  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 004a2c48  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a2c4a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2c4c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2c4f  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2c52  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a2c54  740c                   -je 0x4a2c62
    if (cpu.flags.zf)
    {
        goto L_0x004a2c62;
    }
    // 004a2c56  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2c57  ebe8                   -jmp 0x4a2c41
    goto L_0x004a2c41;
L_0x004a2c59:
    // 004a2c59  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2c5a  891d98bc4d00           -mov dword ptr [0x4dbc98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */) = cpu.ebx;
    // 004a2c60  ebc4                   -jmp 0x4a2c26
    goto L_0x004a2c26;
L_0x004a2c62:
    // 004a2c62  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 004a2c69  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a2c6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2c6d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2c70  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2c73  891d98bc4d00           -mov dword ptr [0x4dbc98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */) = cpu.ebx;
    // 004a2c79  8935a0bc4d00           -mov dword ptr [0x4dbca0], esi
    app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */) = cpu.esi;
    // 004a2c7f  893d9cbc4d00           -mov dword ptr [0x4dbc9c], edi
    app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */) = cpu.edi;
    // 004a2c85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a2c87  7403                   -je 0x4a2c8c
    if (cpu.flags.zf)
    {
        goto L_0x004a2c8c;
    }
    // 004a2c89  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2c8a  ebd6                   -jmp 0x4a2c62
    goto L_0x004a2c62;
L_0x004a2c8c:
    // 004a2c8c  e883feffff             -call 0x4a2b14
    cpu.esp -= 4;
    sub_4a2b14(app, cpu);
    if (cpu.terminate) return;
    // 004a2c91  892d20d25a00           -mov dword ptr [0x5ad220], ebp
    app->getMemory<x86::reg32>(x86::reg32(5952032) /* 0x5ad220 */) = cpu.ebp;
    // 004a2c97  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004a2c9a  0f84a5000000           -je 0x4a2d45
    if (cpu.flags.zf)
    {
        goto L_0x004a2d45;
    }
    // 004a2ca0  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 004a2ca5  8b3d9cbc4d00           -mov edi, dword ptr [0x4dbc9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */);
    // 004a2cab  8b35a0bc4d00           -mov esi, dword ptr [0x4dbca0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */);
    // 004a2cb1  a18cbc4d00             -mov eax, dword ptr [0x4dbc8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094540) /* 0x4dbc8c */);
    // 004a2cb6  8b1d98bc4d00           -mov ebx, dword ptr [0x4dbc98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
L_0x004a2cbc:
    // 004a2cbc  a324d25a00             -mov dword ptr [0x5ad224], eax
    app->getMemory<x86::reg32>(x86::reg32(5952036) /* 0x5ad224 */) = cpu.eax;
    // 004a2cc1  891528d25a00           -mov dword ptr [0x5ad228], edx
    app->getMemory<x86::reg32>(x86::reg32(5952040) /* 0x5ad228 */) = cpu.edx;
L_0x004a2cc7:
    // 004a2cc7  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004a2cca  0f84ec000000           -je 0x4a2dbc
    if (cpu.flags.zf)
    {
        goto L_0x004a2dbc;
    }
    // 004a2cd0  c7052cd25a0044ac0000   -mov dword ptr [0x5ad22c], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = 44100 /*0xac44*/;
L_0x004a2cda:
    // 004a2cda  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2cdc  8935a0bc4d00           -mov dword ptr [0x4dbca0], esi
    app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */) = cpu.esi;
    // 004a2ce2  893d9cbc4d00           -mov dword ptr [0x4dbc9c], edi
    app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */) = cpu.edi;
L_0x004a2ce8:
    // 004a2ce8  05e40d0000             -add eax, 0xde4
    (cpu.eax) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 004a2ced  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a2cef  8890f8e55900           -mov byte ptr [eax + 0x59e5f8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5891576) /* 0x59e5f8 */) = cpu.dl;
    // 004a2cf5  3d40de0000             +cmp eax, 0xde40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56896 /*0xde40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2cfa  75ec                   -jne 0x4a2ce8
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ce8;
    }
    // 004a2cfc  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004a2d01  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2d02  891d98bc4d00           -mov dword ptr [0x4dbc98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */) = cpu.ebx;
    // 004a2d08  ff1590bc4d00           -call dword ptr [0x4dbc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094544) /* 0x4dbc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2d0e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2d11  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004a2d16  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004a2d1b  68acc04d00             -push 0x4dc0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5095596 /*0x4dc0ac*/;
    cpu.esp -= 4;
    // 004a2d20  a31cd25a00             -mov dword ptr [0x5ad21c], eax
    app->getMemory<x86::reg32>(x86::reg32(5952028) /* 0x5ad21c */) = cpu.eax;
    // 004a2d25  ff1590bc4d00           -call dword ptr [0x4dbc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094544) /* 0x4dbc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2d2b  8b1d98bc4d00           -mov ebx, dword ptr [0x4dbc98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a2d31  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2d34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2d36  891d98bc4d00           -mov dword ptr [0x4dbc98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */) = cpu.ebx;
    // 004a2d3c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2d3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2d45:
    // 004a2d45  8b3d9cbc4d00           -mov edi, dword ptr [0x4dbc9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */);
    // 004a2d4b  8b35a0bc4d00           -mov esi, dword ptr [0x4dbca0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */);
    // 004a2d51  8b1d98bc4d00           -mov ebx, dword ptr [0x4dbc98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a2d57  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004a2d5a  7419                   -je 0x4a2d75
    if (cpu.flags.zf)
    {
        goto L_0x004a2d75;
    }
    // 004a2d5c  a184bc4d00             -mov eax, dword ptr [0x4dbc84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094532) /* 0x4dbc84 */);
    // 004a2d61  a324d25a00             -mov dword ptr [0x5ad224], eax
    app->getMemory<x86::reg32>(x86::reg32(5952036) /* 0x5ad224 */) = cpu.eax;
    // 004a2d66  c70528d25a0000020000   -mov dword ptr [0x5ad228], 0x200
    app->getMemory<x86::reg32>(x86::reg32(5952040) /* 0x5ad228 */) = 512 /*0x200*/;
    // 004a2d70  e952ffffff             -jmp 0x4a2cc7
    goto L_0x004a2cc7;
L_0x004a2d75:
    // 004a2d75  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004a2d78  741a                   -je 0x4a2d94
    if (cpu.flags.zf)
    {
        goto L_0x004a2d94;
    }
    // 004a2d7a  a188bc4d00             -mov eax, dword ptr [0x4dbc88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094536) /* 0x4dbc88 */);
    // 004a2d7f  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 004a2d84  a324d25a00             -mov dword ptr [0x5ad224], eax
    app->getMemory<x86::reg32>(x86::reg32(5952036) /* 0x5ad224 */) = cpu.eax;
    // 004a2d89  892d28d25a00           -mov dword ptr [0x5ad228], ebp
    app->getMemory<x86::reg32>(x86::reg32(5952040) /* 0x5ad228 */) = cpu.ebp;
    // 004a2d8f  e933ffffff             -jmp 0x4a2cc7
    goto L_0x004a2cc7;
L_0x004a2d94:
    // 004a2d94  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004a2d97  740f                   -je 0x4a2da8
    if (cpu.flags.zf)
    {
        goto L_0x004a2da8;
    }
    // 004a2d99  a180bc4d00             -mov eax, dword ptr [0x4dbc80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094528) /* 0x4dbc80 */);
    // 004a2d9e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a2da3  e914ffffff             -jmp 0x4a2cbc
    goto L_0x004a2cbc;
L_0x004a2da8:
    // 004a2da8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a2dad  891d98bc4d00           -mov dword ptr [0x4dbc98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */) = cpu.ebx;
    // 004a2db3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2db6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2db7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2db8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2db9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2dba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2dbb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2dbc:
    // 004a2dbc  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004a2dbf  740f                   -je 0x4a2dd0
    if (cpu.flags.zf)
    {
        goto L_0x004a2dd0;
    }
    // 004a2dc1  c7052cd25a00007d0000   -mov dword ptr [0x5ad22c], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = 32000 /*0x7d00*/;
    // 004a2dcb  e90affffff             -jmp 0x4a2cda
    goto L_0x004a2cda;
L_0x004a2dd0:
    // 004a2dd0  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004a2dd3  740f                   -je 0x4a2de4
    if (cpu.flags.zf)
    {
        goto L_0x004a2de4;
    }
    // 004a2dd5  c7052cd25a0022560000   -mov dword ptr [0x5ad22c], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = 22050 /*0x5622*/;
    // 004a2ddf  e9f6feffff             -jmp 0x4a2cda
    goto L_0x004a2cda;
L_0x004a2de4:
    // 004a2de4  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004a2de7  740f                   -je 0x4a2df8
    if (cpu.flags.zf)
    {
        goto L_0x004a2df8;
    }
    // 004a2de9  c7052cd25a00803e0000   -mov dword ptr [0x5ad22c], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = 16000 /*0x3e80*/;
    // 004a2df3  e9e2feffff             -jmp 0x4a2cda
    goto L_0x004a2cda;
L_0x004a2df8:
    // 004a2df8  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 004a2dfb  740f                   -je 0x4a2e0c
    if (cpu.flags.zf)
    {
        goto L_0x004a2e0c;
    }
    // 004a2dfd  c7052cd25a00112b0000   -mov dword ptr [0x5ad22c], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = 11025 /*0x2b11*/;
    // 004a2e07  e9cefeffff             -jmp 0x4a2cda
    goto L_0x004a2cda;
L_0x004a2e0c:
    // 004a2e0c  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004a2e0f  740f                   -je 0x4a2e20
    if (cpu.flags.zf)
    {
        goto L_0x004a2e20;
    }
    // 004a2e11  c7052cd25a00401f0000   -mov dword ptr [0x5ad22c], 0x1f40
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = 8000 /*0x1f40*/;
    // 004a2e1b  e9bafeffff             -jmp 0x4a2cda
    goto L_0x004a2cda;
L_0x004a2e20:
    // 004a2e20  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a2e25  8935a0bc4d00           -mov dword ptr [0x4dbca0], esi
    app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */) = cpu.esi;
    // 004a2e2b  893d9cbc4d00           -mov dword ptr [0x4dbc9c], edi
    app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */) = cpu.edi;
    // 004a2e31  891d98bc4d00           -mov dword ptr [0x4dbc98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */) = cpu.ebx;
    // 004a2e37  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2e3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2e43  8b152cd25a00           -mov edx, dword ptr [0x5ad22c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */);
    // 004a2e49  8b0d24d25a00           -mov ecx, dword ptr [0x5ad224]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5952036) /* 0x5ad224 */);
    // 004a2e4f  8b1d28d25a00           -mov ebx, dword ptr [0x5ad228]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5952040) /* 0x5ad228 */);
    // 004a2e55  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a2e57  7435                   -je 0x4a2e8e
    if (cpu.flags.zf)
    {
        goto L_0x004a2e8e;
    }
    // 004a2e59  bb00040000             -mov ebx, 0x400
    cpu.ebx = 1024 /*0x400*/;
    // 004a2e5e  8b0d8cbc4d00           -mov ecx, dword ptr [0x4dbc8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094540) /* 0x4dbc8c */);
L_0x004a2e64:
    // 004a2e64  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004a2e67  745f                   -je 0x4a2ec8
    if (cpu.flags.zf)
    {
        goto L_0x004a2ec8;
    }
    // 004a2e69  ba44ac0000             -mov edx, 0xac44
    cpu.edx = 44100 /*0xac44*/;
L_0x004a2e6e:
    // 004a2e6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a2e70:
    // 004a2e70  40                     -inc eax
    (cpu.eax)++;
    // 004a2e71  83f810                 +cmp eax, 0x10
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
    // 004a2e74  7cfa                   -jl 0x4a2e70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2e70;
    }
    // 004a2e76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a2e78:
    // 004a2e78  891d28d25a00           -mov dword ptr [0x5ad228], ebx
    app->getMemory<x86::reg32>(x86::reg32(5952040) /* 0x5ad228 */) = cpu.ebx;
    // 004a2e7e  890d24d25a00           -mov dword ptr [0x5ad224], ecx
    app->getMemory<x86::reg32>(x86::reg32(5952036) /* 0x5ad224 */) = cpu.ecx;
    // 004a2e84  89152cd25a00           -mov dword ptr [0x5ad22c], edx
    app->getMemory<x86::reg32>(x86::reg32(5952044) /* 0x5ad22c */) = cpu.edx;
    // 004a2e8a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2e8e:
    // 004a2e8e  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a2e90  740d                   -je 0x4a2e9f
    if (cpu.flags.zf)
    {
        goto L_0x004a2e9f;
    }
    // 004a2e92  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 004a2e97  8b0d84bc4d00           -mov ecx, dword ptr [0x4dbc84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094532) /* 0x4dbc84 */);
    // 004a2e9d  ebc5                   -jmp 0x4a2e64
    goto L_0x004a2e64;
L_0x004a2e9f:
    // 004a2e9f  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a2ea1  740d                   -je 0x4a2eb0
    if (cpu.flags.zf)
    {
        goto L_0x004a2eb0;
    }
    // 004a2ea3  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 004a2ea8  8b0d88bc4d00           -mov ecx, dword ptr [0x4dbc88]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094536) /* 0x4dbc88 */);
    // 004a2eae  ebb4                   -jmp 0x4a2e64
    goto L_0x004a2e64;
L_0x004a2eb0:
    // 004a2eb0  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a2eb2  740d                   -je 0x4a2ec1
    if (cpu.flags.zf)
    {
        goto L_0x004a2ec1;
    }
    // 004a2eb4  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 004a2eb9  8b0d80bc4d00           -mov ecx, dword ptr [0x4dbc80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094528) /* 0x4dbc80 */);
    // 004a2ebf  eba3                   -jmp 0x4a2e64
    goto L_0x004a2e64;
L_0x004a2ec1:
    // 004a2ec1  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a2ec6  ebb0                   -jmp 0x4a2e78
    goto L_0x004a2e78;
L_0x004a2ec8:
    // 004a2ec8  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004a2ecb  7407                   -je 0x4a2ed4
    if (cpu.flags.zf)
    {
        goto L_0x004a2ed4;
    }
    // 004a2ecd  ba007d0000             -mov edx, 0x7d00
    cpu.edx = 32000 /*0x7d00*/;
    // 004a2ed2  eb9a                   -jmp 0x4a2e6e
    goto L_0x004a2e6e;
L_0x004a2ed4:
    // 004a2ed4  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004a2ed7  7407                   -je 0x4a2ee0
    if (cpu.flags.zf)
    {
        goto L_0x004a2ee0;
    }
    // 004a2ed9  ba22560000             -mov edx, 0x5622
    cpu.edx = 22050 /*0x5622*/;
    // 004a2ede  eb8e                   -jmp 0x4a2e6e
    goto L_0x004a2e6e;
L_0x004a2ee0:
    // 004a2ee0  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004a2ee3  7407                   -je 0x4a2eec
    if (cpu.flags.zf)
    {
        goto L_0x004a2eec;
    }
    // 004a2ee5  ba803e0000             -mov edx, 0x3e80
    cpu.edx = 16000 /*0x3e80*/;
    // 004a2eea  eb82                   -jmp 0x4a2e6e
    goto L_0x004a2e6e;
L_0x004a2eec:
    // 004a2eec  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004a2eef  740a                   -je 0x4a2efb
    if (cpu.flags.zf)
    {
        goto L_0x004a2efb;
    }
    // 004a2ef1  ba112b0000             -mov edx, 0x2b11
    cpu.edx = 11025 /*0x2b11*/;
    // 004a2ef6  e973ffffff             -jmp 0x4a2e6e
    goto L_0x004a2e6e;
L_0x004a2efb:
    // 004a2efb  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004a2efe  74c1                   -je 0x4a2ec1
    if (cpu.flags.zf)
    {
        goto L_0x004a2ec1;
    }
    // 004a2f00  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004a2f05  e964ffffff             -jmp 0x4a2e6e
    goto L_0x004a2e6e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a2f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2f0c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2f0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2f0e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2f0f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2f12  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a2f16  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a2f19  8d34c500000000         -lea esi, [eax*8]
    cpu.esi = x86::reg32(cpu.eax * 8);
    // 004a2f20  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2f22  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2f24  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 004a2f27  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2f29  81c6dcf35900           -add esi, 0x59f3dc
    (cpu.esi) += x86::reg32(x86::sreg32(5895132 /*0x59f3dc*/));
    // 004a2f2f  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004a2f32  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a2f35  c64609ff               -mov byte ptr [esi + 9], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 255 /*0xff*/;
    // 004a2f39  8986600d0000           -mov dword ptr [esi + 0xd60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */) = cpu.eax;
    // 004a2f3f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a2f42  7559                   -jne 0x4a2f9d
    if (!cpu.flags.zf)
    {
        goto L_0x004a2f9d;
    }
    // 004a2f44  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004a2f47  0f847a000000           -je 0x4a2fc7
    if (cpu.flags.zf)
    {
        goto L_0x004a2fc7;
    }
    // 004a2f4d  a15cbc4d00             -mov eax, dword ptr [0x4dbc5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094492) /* 0x4dbc5c */);
    // 004a2f52  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a2f55  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a2f5a  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f5d  7f60                   -jg 0x4a2fbf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a2fbf;
    }
    // 004a2f5f  8b3d6cbc4d00           -mov edi, dword ptr [0x4dbc6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094508) /* 0x4dbc6c */);
L_0x004a2f65:
    // 004a2f65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2f67  0f85bc000000           -jne 0x4a3029
    if (!cpu.flags.zf)
    {
        goto L_0x004a3029;
    }
L_0x004a2f6d:
    // 004a2f6d  83f901                 +cmp ecx, 1
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
    // 004a2f70  0f8520010000           -jne 0x4a3096
    if (!cpu.flags.zf)
    {
        goto L_0x004a3096;
    }
    // 004a2f76  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 004a2f7b  7e02                   -jle 0x4a2f7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2f7f;
    }
L_0x004a2f7d:
    // 004a2f7d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a2f7f:
    // 004a2f7f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a2f82  83b8d8bb4d0000         +cmp dword ptr [eax + 0x4dbbd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5094360) /* 0x4dbbd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f89  0f851e010000           -jne 0x4a30ad
    if (!cpu.flags.zf)
    {
        goto L_0x004a30ad;
    }
L_0x004a2f8f:
    // 004a2f8f  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004a2f94  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2f97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f9a  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a2f9d:
    // 004a2f9d  a158bc4d00             -mov eax, dword ptr [0x4dbc58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094488) /* 0x4dbc58 */);
    // 004a2fa2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a2fa5  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004a2faa  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2fad  7f08                   -jg 0x4a2fb7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a2fb7;
    }
    // 004a2faf  8b3d68bc4d00           -mov edi, dword ptr [0x4dbc68]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094504) /* 0x4dbc68 */);
    // 004a2fb5  ebae                   -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a2fb7:
    // 004a2fb7  8b3d78bc4d00           -mov edi, dword ptr [0x4dbc78]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094520) /* 0x4dbc78 */);
    // 004a2fbd  eba6                   -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a2fbf:
    // 004a2fbf  8b3d7cbc4d00           -mov edi, dword ptr [0x4dbc7c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094524) /* 0x4dbc7c */);
    // 004a2fc5  eb9e                   -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a2fc7:
    // 004a2fc7  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a2fca  7422                   -je 0x4a2fee
    if (cpu.flags.zf)
    {
        goto L_0x004a2fee;
    }
    // 004a2fcc  a150bc4d00             -mov eax, dword ptr [0x4dbc50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094480) /* 0x4dbc50 */);
    // 004a2fd1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a2fd4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2fd6  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2fd9  7f08                   -jg 0x4a2fe3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a2fe3;
    }
    // 004a2fdb  8b3d60bc4d00           -mov edi, dword ptr [0x4dbc60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094496) /* 0x4dbc60 */);
    // 004a2fe1  eb82                   -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a2fe3:
    // 004a2fe3  8b3d70bc4d00           -mov edi, dword ptr [0x4dbc70]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094512) /* 0x4dbc70 */);
    // 004a2fe9  e977ffffff             -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a2fee:
    // 004a2fee  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a2ff1  7428                   -je 0x4a301b
    if (cpu.flags.zf)
    {
        goto L_0x004a301b;
    }
    // 004a2ff3  a154bc4d00             -mov eax, dword ptr [0x4dbc54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094484) /* 0x4dbc54 */);
    // 004a2ff8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a2ffb  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a3000  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3003  7f0b                   -jg 0x4a3010
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a3010;
    }
    // 004a3005  8b3d64bc4d00           -mov edi, dword ptr [0x4dbc64]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094500) /* 0x4dbc64 */);
    // 004a300b  e955ffffff             -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a3010:
    // 004a3010  8b3d74bc4d00           -mov edi, dword ptr [0x4dbc74]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094516) /* 0x4dbc74 */);
    // 004a3016  e94affffff             -jmp 0x4a2f65
    goto L_0x004a2f65;
L_0x004a301b:
    // 004a301b  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 004a3020  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3023  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3024  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3025  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3026  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a3029:
    // 004a3029  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a302c  752c                   -jne 0x4a305a
    if (!cpu.flags.zf)
    {
        goto L_0x004a305a;
    }
    // 004a302e  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a3031  740a                   -je 0x4a303d
    if (cpu.flags.zf)
    {
        goto L_0x004a303d;
    }
    // 004a3033  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 004a3038  e930ffffff             -jmp 0x4a2f6d
    goto L_0x004a2f6d;
L_0x004a303d:
    // 004a303d  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004a3040  740a                   -je 0x4a304c
    if (cpu.flags.zf)
    {
        goto L_0x004a304c;
    }
    // 004a3042  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004a3047  e921ffffff             -jmp 0x4a2f6d
    goto L_0x004a2f6d;
L_0x004a304c:
    // 004a304c  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a3051  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3054  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3055  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3056  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3057  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a305a:
    // 004a305a  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a305d  750f                   -jne 0x4a306e
    if (!cpu.flags.zf)
    {
        goto L_0x004a306e;
    }
L_0x004a305f:
    // 004a305f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a3062  74e8                   -je 0x4a304c
    if (cpu.flags.zf)
    {
        goto L_0x004a304c;
    }
    // 004a3064  b81b000000             -mov eax, 0x1b
    cpu.eax = 27 /*0x1b*/;
    // 004a3069  e9fffeffff             -jmp 0x4a2f6d
    goto L_0x004a2f6d;
L_0x004a306e:
    // 004a306e  83fb08                 +cmp ebx, 8
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
    // 004a3071  74ec                   -je 0x4a305f
    if (cpu.flags.zf)
    {
        goto L_0x004a305f;
    }
    // 004a3073  83fb02                 +cmp ebx, 2
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
    // 004a3076  75a3                   -jne 0x4a301b
    if (!cpu.flags.zf)
    {
        goto L_0x004a301b;
    }
    // 004a3078  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004a307b  740a                   -je 0x4a3087
    if (cpu.flags.zf)
    {
        goto L_0x004a3087;
    }
    // 004a307d  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004a3082  e9e6feffff             -jmp 0x4a2f6d
    goto L_0x004a2f6d;
L_0x004a3087:
    // 004a3087  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004a308a  74c0                   -je 0x4a304c
    if (cpu.flags.zf)
    {
        goto L_0x004a304c;
    }
    // 004a308c  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 004a3091  e9d7feffff             -jmp 0x4a2f6d
    goto L_0x004a2f6d;
L_0x004a3096:
    // 004a3096  83f902                 +cmp ecx, 2
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
    // 004a3099  0f84defeffff           -je 0x4a2f7d
    if (cpu.flags.zf)
    {
        goto L_0x004a2f7d;
    }
    // 004a309f  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004a30a4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a30a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a30a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a30a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a30aa  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004a30ad:
    // 004a30ad  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a30af  8d86ac0d0000           -lea eax, [esi + 0xdac]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3500) /* 0xdac */);
    // 004a30b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a30b6  8d86a80d0000           -lea eax, [esi + 0xda8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    // 004a30bc  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a30c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a30c1  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a30c5  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a30c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a30ca  8b86600d0000           -mov eax, dword ptr [esi + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004a30d0  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a30d4  ff95d8bb4d00           -call dword ptr [ebp + 0x4dbbd8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5094360) /* 0x4dbbd8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a30da  833c2400               +cmp dword ptr [esp], 0
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
    // 004a30de  0f84abfeffff           -je 0x4a2f8f
    if (cpu.flags.zf)
    {
        goto L_0x004a2f8f;
    }
    // 004a30e4  8d86bc0d0000           -lea eax, [esi + 0xdbc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    // 004a30ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a30eb  8d86c00d0000           -lea eax, [esi + 0xdc0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    // 004a30f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a30f2  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004a30f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a30f9  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a30fd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3100  8d86dc0d0000           -lea eax, [esi + 0xddc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3548) /* 0xddc */);
    // 004a3106  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3107  8d86e00d0000           -lea eax, [esi + 0xde0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    // 004a310d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a310e  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 004a3114  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3115  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3119  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a311c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a311e  0f846bfeffff           -je 0x4a2f8f
    if (cpu.flags.zf)
    {
        goto L_0x004a2f8f;
    }
    // 004a3124  8d86b80d0000           -lea eax, [esi + 0xdb8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    // 004a312a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a312b  8d86b40d0000           -lea eax, [esi + 0xdb4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    // 004a3131  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3132  8d86b00d0000           -lea eax, [esi + 0xdb0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    // 004a3138  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3139  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 004a313f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3140  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3142  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3145  817c242c00000800       +cmp dword ptr [esp + 0x2c], 0x80000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a314d  7608                   -jbe 0x4a3157
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a3157;
    }
    // 004a314f  c744242c00000800       -mov dword ptr [esp + 0x2c], 0x80000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 524288 /*0x80000*/;
L_0x004a3157:
    // 004a3157  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a315b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a315c  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 004a3162  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3163  ff96b00d0000           -call dword ptr [esi + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3169  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a316c  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a3170  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a3173  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a3177  884602                 -mov byte ptr [esi + 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a317a  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a317e  884604                 -mov byte ptr [esi + 4], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004a3181  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a3185  884605                 -mov byte ptr [esi + 5], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 004a3188  8a442434               -mov al, byte ptr [esp + 0x34]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a318c  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a318f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3191  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a3195  e826020000             -call 0x4a33c0
    cpu.esp -= 4;
    sub_4a33c0(app, cpu);
    if (cpu.terminate) return;
    // 004a319a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a319b  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a319f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a31a0  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004a31a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a31a7  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a31ad  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a31b0  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 004a31b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a31b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a31b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31bb  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a31c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a31c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a31c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a31c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a31c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a31c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a31c5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a31c8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a31ca  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a31cc  05c40d0000             -add eax, 0xdc4
    (cpu.eax) += x86::reg32(x86::sreg32(3524 /*0xdc4*/));
    // 004a31d1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a31d4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a31d6  05900d0000             -add eax, 0xd90
    (cpu.eax) += x86::reg32(x86::sreg32(3472 /*0xd90*/));
    // 004a31db  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a31df  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a31e1  05640d0000             -add eax, 0xd64
    (cpu.eax) += x86::reg32(x86::sreg32(3428 /*0xd64*/));
    // 004a31e6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a31e8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a31ec:
    // 004a31ec  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a31ef  3a4604                 +cmp al, byte ptr [esi + 4]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a31f2  0f84cd000000           -je 0x4a32c5
    if (cpu.flags.zf)
    {
        goto L_0x004a32c5;
    }
L_0x004a31f8:
    // 004a31f8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a31fa  0f84d1000000           -je 0x4a32d1
    if (cpu.flags.zf)
    {
        goto L_0x004a32d1;
    }
    // 004a3200  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a3203  8a7604                 -mov dh, byte ptr [esi + 4]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a3206  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a3207  38f0                   +cmp al, dh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3209  0f85cd000000           -jne 0x4a32dc
    if (!cpu.flags.zf)
    {
        goto L_0x004a32dc;
    }
L_0x004a320f:
    // 004a320f  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a3212  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3215  7406                   -je 0x4a321d
    if (cpu.flags.zf)
    {
        goto L_0x004a321d;
    }
    // 004a3217  8a4607                 -mov al, byte ptr [esi + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 004a321a  004602                 -add byte ptr [esi + 2], al
    (app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)) += x86::reg8(x86::sreg8(cpu.al));
L_0x004a321d:
    // 004a321d  0fbe4602               -movsx eax, byte ptr [esi + 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)));
    // 004a3221  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3222  0fbe4601               -movsx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
    // 004a3226  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3227  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a322b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a322c  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3232  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3235  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3237  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a323b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a323c  ff96b40d0000           -call dword ptr [esi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3242  8b0d9cbc4d00           -mov ecx, dword ptr [0x4dbc9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */);
    // 004a3248  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a324b  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a324e  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a3252  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3256  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004a325c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a325e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3260  ff96a80d0000           -call dword ptr [esi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3266  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3268  7c67                   -jl 0x4a32d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a32d1;
    }
    // 004a326a  a1a0bc4d00             -mov eax, dword ptr [0x4dbca0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */);
    // 004a326f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3273  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a3277  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a327b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a327c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a327d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a327f  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3283  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3284  ff96b80d0000           -call dword ptr [esi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a328a  8a0da4bc4d00           -mov cl, byte ptr [0x4dbca4]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5094564) /* 0x4dbca4 */);
    // 004a3290  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a3292  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a3294  8b0d98bc4d00           -mov ecx, dword ptr [0x4dbc98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a329a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a329d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a32a0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a32a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a32a3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a32a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a32a8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a32aa  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a32ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a32af  ff96c00d0000           -call dword ptr [esi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a32b5  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a32b8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a32bb  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004a32bd  7528                   -jne 0x4a32e7
    if (!cpu.flags.zf)
    {
        goto L_0x004a32e7;
    }
    // 004a32bf  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a32c0  e927ffffff             -jmp 0x4a31ec
    goto L_0x004a31ec;
L_0x004a32c5:
    // 004a32c5  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a32c8  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a32cb  0f8527ffffff           -jne 0x4a31f8
    if (!cpu.flags.zf)
    {
        goto L_0x004a31f8;
    }
L_0x004a32d1:
    // 004a32d1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a32d3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a32d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a32dc:
    // 004a32dc  8a4606                 -mov al, byte ptr [esi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004a32df  004601                 +add byte ptr [esi + 1], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a32e2  e928ffffff             -jmp 0x4a320f
    goto L_0x004a320f;
L_0x004a32e7:
    // 004a32e7  8a0da4bc4d00           -mov cl, byte ptr [0x4dbca4]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5094564) /* 0x4dbca4 */);
    // 004a32ed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a32ef  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a32f1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a32f4  05acc04d00             -add eax, 0x4dc0ac
    (cpu.eax) += x86::reg32(x86::sreg32(5095596 /*0x4dc0ac*/));
    // 004a32f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a32fa  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a32fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a32ff  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3301  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a3305  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3306  ff96e00d0000           -call dword ptr [esi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a330c  83c410                 +add esp, 0x10
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
    // 004a330f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a3310  e9d7feffff             -jmp 0x4a31ec
    goto L_0x004a31ec;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3318  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3319  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a331a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a331b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a331d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a3320  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3322  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a3325  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3327  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3329  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a332c  bfdcf35900             -mov edi, 0x59f3dc
    cpu.edi = 5895132 /*0x59f3dc*/;
    // 004a3331  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3333  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a3335  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3338  7509                   -jne 0x4a3343
    if (!cpu.flags.zf)
    {
        goto L_0x004a3343;
    }
    // 004a333a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a333f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3340  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3341  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3342  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3343:
    // 004a3343  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3344  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3345  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3347  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a3349  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a334b  e8c0000000             -call 0x4a3410
    cpu.esp -= 4;
    sub_4a3410(app, cpu);
    if (cpu.terminate) return;
    // 004a3350  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a3355  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a3357  e864feffff             -call 0x4a31c0
    cpu.esp -= 4;
    sub_4a31c0(app, cpu);
    if (cpu.terminate) return;
    // 004a335c  ff1594bc4d00           -call dword ptr [0x4dbc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094548) /* 0x4dbc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3362  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3364  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 004a3367  ff1520d25a00           -call dword ptr [0x5ad220]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5952032) /* 0x5ad220 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a336d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a336f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3370  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3371  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3372  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3373  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3374  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3378(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3378  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3379  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a337b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a337e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3380  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a3383  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3385  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3387  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a338a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a338c  05dcf35900             -add eax, 0x59f3dc
    (cpu.eax) += x86::reg32(x86::sreg32(5895132 /*0x59f3dc*/));
    // 004a3391  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3394  7422                   -je 0x4a33b8
    if (cpu.flags.zf)
    {
        goto L_0x004a33b8;
    }
    // 004a3396  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a339c  7605                   -jbe 0x4a33a3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a33a3;
    }
    // 004a339e  b900000800             -mov ecx, 0x80000
    cpu.ecx = 524288 /*0x80000*/;
L_0x004a33a3:
    // 004a33a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a33a4  8d90640d0000           -lea edx, [eax + 0xd64]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3428) /* 0xd64 */);
    // 004a33aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a33ab  ff90b00d0000           -call dword ptr [eax + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a33b1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a33b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a33b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a33b8:
    // 004a33b8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a33bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a33c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a33c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a33c1  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004a33c4  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a33c6  7505                   -jne 0x4a33cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a33cd;
    }
    // 004a33c8  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004a33cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a33cd:
    // 004a33cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a33ce  8b5001                 -mov edx, dword ptr [eax + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a33d1  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a33d4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a33d7  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a33da  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a33dc  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004a33de  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004a33e1  8b4805                 -mov ecx, dword ptr [eax + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004a33e4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a33e6  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a33e9  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a33ec  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a33ef  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 004a33f2  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004a33f5  8b5005                 -mov edx, dword ptr [eax + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004a33f8  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a33fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a33fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a33fd  8d90c40d0000           -lea edx, [eax + 0xdc4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3524) /* 0xdc4 */);
    // 004a3403  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3404  ff90dc0d0000           -call dword ptr [eax + 0xddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3548) /* 0xddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a340a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a340d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a340e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a340f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a3410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3411  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a3413  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a3416  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3418  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a341b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a341d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a341f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a3422  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3424  05dcf35900             -add eax, 0x59f3dc
    (cpu.eax) += x86::reg32(x86::sreg32(5895132 /*0x59f3dc*/));
    // 004a3429  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a342c  7427                   -je 0x4a3455
    if (cpu.flags.zf)
    {
        goto L_0x004a3455;
    }
    // 004a342e  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
    // 004a3431  0fbe5001               -movsx edx, byte ptr [eax + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */)));
    // 004a3435  885805                 -mov byte ptr [eax + 5], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = cpu.bl;
    // 004a3438  39ca                   +cmp edx, ecx
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
    // 004a343a  7c20                   -jl 0x4a345c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a345c;
    }
    // 004a343c  c64006ff               -mov byte ptr [eax + 6], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 255 /*0xff*/;
L_0x004a3440:
    // 004a3440  0fbe5002               -movsx edx, byte ptr [eax + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */)));
    // 004a3444  39da                   +cmp edx, ebx
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
    // 004a3446  7d1a                   -jge 0x4a3462
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3462;
    }
    // 004a3448  c6400701               -mov byte ptr [eax + 7], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 1 /*0x1*/;
    // 004a344c  e86fffffff             -call 0x4a33c0
    cpu.esp -= 4;
    sub_4a33c0(app, cpu);
    if (cpu.terminate) return;
    // 004a3451  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a3453  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3454  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3455:
    // 004a3455  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a345a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a345b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a345c:
    // 004a345c  c6400601               -mov byte ptr [eax + 6], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 004a3460  ebde                   -jmp 0x4a3440
    goto L_0x004a3440;
L_0x004a3462:
    // 004a3462  c64007ff               -mov byte ptr [eax + 7], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 255 /*0xff*/;
    // 004a3466  e855ffffff             -call 0x4a33c0
    cpu.esp -= 4;
    sub_4a33c0(app, cpu);
    if (cpu.terminate) return;
    // 004a346b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a346d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a346e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a3470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3470  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a3473  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3475  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a3478  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a347a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a347c  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a347f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3481  05dcf35900             -add eax, 0x59f3dc
    (cpu.eax) += x86::reg32(x86::sreg32(5895132 /*0x59f3dc*/));
    // 004a3486  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3489  7506                   -jne 0x4a3491
    if (!cpu.flags.zf)
    {
        goto L_0x004a3491;
    }
    // 004a348b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a3490  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3491:
    // 004a3491  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 004a3494  e827ffffff             -call 0x4a33c0
    cpu.esp -= 4;
    sub_4a33c0(app, cpu);
    if (cpu.terminate) return;
    // 004a3499  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a349b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a349c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a349c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a349d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a34a0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a34a2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a34a5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a34a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a34a9  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004a34ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a34ae  badcf35900             -mov edx, 0x59f3dc
    cpu.edx = 5895132 /*0x59f3dc*/;
    // 004a34b3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a34b5  83baac0d000000         +cmp dword ptr [edx + 0xdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a34bc  7507                   -jne 0x4a34c5
    if (!cpu.flags.zf)
    {
        goto L_0x004a34c5;
    }
    // 004a34be  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a34c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a34c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a34c5:
    // 004a34c5  8b82600d0000           -mov eax, dword ptr [edx + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3424) /* 0xd60 */);
    // 004a34cb  ff92ac0d0000           -call dword ptr [edx + 0xdac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a34d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a34d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a34d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a34d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a34d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a34d6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a34d9  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a34dd  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a34e1  ff1594bc4d00           -call dword ptr [0x4dbc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094548) /* 0x4dbc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a34e7  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a34eb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a34ee  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a34f0  39cb                   +cmp ebx, ecx
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
    // 004a34f2  7320                   -jae 0x4a3514
    if (!cpu.flags.cf)
    {
        goto L_0x004a3514;
    }
L_0x004a34f4:
    // 004a34f4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a34f6  0fbf16                 -movsx edx, word ptr [esi]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi)));
    // 004a34f9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a34fc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a34fe  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3501  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a3504  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3507  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004a350a  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a350d  39cb                   +cmp ebx, ecx
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
    // 004a350f  72e3                   -jb 0x4a34f4
    if (cpu.flags.cf)
    {
        goto L_0x004a34f4;
    }
    // 004a3511  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a3514:
    // 004a3514  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3517  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3518  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3519  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a351c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a351c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a351d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a351e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3521  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a3525  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a3529  ff1594bc4d00           -call dword ptr [0x4dbc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094548) /* 0x4dbc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a352f  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a3533  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a3536  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a3538  39ce                   +cmp esi, ecx
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
    // 004a353a  0f8390000000           -jae 0x4a35d0
    if (!cpu.flags.cf)
    {
        goto L_0x004a35d0;
    }
L_0x004a3540:
    // 004a3540  df03                   -fild word ptr [ebx]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx))));
    // 004a3542  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 004a3544  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a3548  df4302                 -fild word ptr [ebx + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */))));
    // 004a354b  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 004a354d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a3551  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004a3555  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a3557  dd0510f34c00           -fld qword ptr [0x4cf310]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5042960) /* 0x4cf310 */)));
    // 004a355d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a355f  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004a3561  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3564  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a3566  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a3568  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a356c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a3570  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004a3572  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a3576  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a3578  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a357a  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a357e  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a3582  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a3587  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a358d  3dff7f0000             +cmp eax, 0x7fff
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
    // 004a3592  7649                   -jbe 0x4a35dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a35dd;
    }
    // 004a3594  3d00800f00             +cmp eax, 0xf8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3599  7342                   -jae 0x4a35dd
    if (!cpu.flags.cf)
    {
        goto L_0x004a35dd;
    }
    // 004a359b  3d00000800             +cmp eax, 0x80000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a35a0  7334                   -jae 0x4a35d6
    if (!cpu.flags.cf)
    {
        goto L_0x004a35d6;
    }
    // 004a35a2  66c703ff7f             -mov word ptr [ebx], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx) = 32767 /*0x7fff*/;
L_0x004a35a7:
    // 004a35a7  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a35ad  763b                   -jbe 0x4a35ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a35ea;
    }
    // 004a35af  81fa00800f00           +cmp edx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a35b5  7333                   -jae 0x4a35ea
    if (!cpu.flags.cf)
    {
        goto L_0x004a35ea;
    }
    // 004a35b7  81fa00000800           +cmp edx, 0x80000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a35bd  7323                   -jae 0x4a35e2
    if (!cpu.flags.cf)
    {
        goto L_0x004a35e2;
    }
    // 004a35bf  66c74302ff7f           -mov word ptr [ebx + 2], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32767 /*0x7fff*/;
L_0x004a35c5:
    // 004a35c5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a35c8  39ce                   +cmp esi, ecx
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
    // 004a35ca  0f8270ffffff           -jb 0x4a3540
    if (cpu.flags.cf)
    {
        goto L_0x004a3540;
    }
L_0x004a35d0:
    // 004a35d0  83c410                 +add esp, 0x10
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
    // 004a35d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a35d6:
    // 004a35d6  66c7030080             -mov word ptr [ebx], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx) = 32768 /*0x8000*/;
    // 004a35db  ebca                   -jmp 0x4a35a7
    goto L_0x004a35a7;
L_0x004a35dd:
    // 004a35dd  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004a35e0  ebc5                   -jmp 0x4a35a7
    goto L_0x004a35a7;
L_0x004a35e2:
    // 004a35e2  66c743020080           -mov word ptr [ebx + 2], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32768 /*0x8000*/;
    // 004a35e8  ebdb                   -jmp 0x4a35c5
    goto L_0x004a35c5;
L_0x004a35ea:
    // 004a35ea  66895302               -mov word ptr [ebx + 2], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004a35ee  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a35f1  39ce                   +cmp esi, ecx
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
    // 004a35f3  0f8247ffffff           -jb 0x4a3540
    if (cpu.flags.cf)
    {
        goto L_0x004a3540;
    }
    // 004a35f9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a35fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a3600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3600  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3602  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3603  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3604  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3605  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 004a3608  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004a360c  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004a3610  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3612  bedcf35900             -mov esi, 0x59f3dc
    cpu.esi = 5895132 /*0x59f3dc*/;
    // 004a3617  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 004a361b  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x004a361f:
    // 004a361f  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 004a3621  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a3623  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a3625  0f85bb000000           -jne 0x4a36e6
    if (!cpu.flags.zf)
    {
        goto L_0x004a36e6;
    }
L_0x004a362b:
    // 004a362b  8b6c2460               -mov ebp, dword ptr [esp + 0x60]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a362f  45                     -inc ebp
    (cpu.ebp)++;
    // 004a3630  81c6e40d0000           -add esi, 0xde4
    (cpu.esi) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 004a3636  896c2460               -mov dword ptr [esp + 0x60], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ebp;
    // 004a363a  83fd10                 +cmp ebp, 0x10
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
    // 004a363d  7ce0                   -jl 0x4a361f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a361f;
    }
L_0x004a363f:
    // 004a363f  837c245000             +cmp dword ptr [esp + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3644  0f8498010000           -je 0x4a37e2
    if (cpu.flags.zf)
    {
        goto L_0x004a37e2;
    }
    // 004a364a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a364c  89351cd25a00           -mov dword ptr [0x5ad21c], esi
    app->getMemory<x86::reg32>(x86::reg32(5952028) /* 0x5ad21c */) = cpu.esi;
L_0x004a3652:
    // 004a3652  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a3656  8b3da8bc4d00           -mov edi, dword ptr [0x4dbca8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094568) /* 0x4dbca8 */);
    // 004a365c  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a365e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a3660  0f849a010000           -je 0x4a3800
    if (cpu.flags.zf)
    {
        goto L_0x004a3800;
    }
    // 004a3666  68acbc4d00             -push 0x4dbcac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5094572 /*0x4dbcac*/;
    cpu.esp -= 4;
    // 004a366b  68acc04d00             -push 0x4dc0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5095596 /*0x4dc0ac*/;
    cpu.esp -= 4;
    // 004a3670  8b74245c               -mov esi, dword ptr [esp + 0x5c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a3674  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3675  e85afeffff             -call 0x4a34d4
    cpu.esp -= 4;
    sub_4a34d4(app, cpu);
    if (cpu.terminate) return;
    // 004a367a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a367d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a367e  68acc04d00             -push 0x4dc0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5095596 /*0x4dc0ac*/;
    cpu.esp -= 4;
    // 004a3683  ff1590bc4d00           -call dword ptr [0x4dbc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094544) /* 0x4dbc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3689  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a368c  68acbc4d00             -push 0x4dbcac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5094572 /*0x4dbcac*/;
    cpu.esp -= 4;
    // 004a3691  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3692  e899240100             -call 0x4b5b30
    cpu.esp -= 4;
    sub_4b5b30(app, cpu);
    if (cpu.terminate) return;
    // 004a3697  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a369a  8b2d98bc4d00           -mov ebp, dword ptr [0x4dbc98]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a36a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a36a1  68acbc4d00             -push 0x4dbcac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5094572 /*0x4dbcac*/;
    cpu.esp -= 4;
    // 004a36a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a36a7  e870feffff             -call 0x4a351c
    cpu.esp -= 4;
    sub_4a351c(app, cpu);
    if (cpu.terminate) return;
    // 004a36ac  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004a36af:
    // 004a36af  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a36b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a36b4  8b0d98bc4d00           -mov ecx, dword ptr [0x4dbc98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a36ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a36bb  8b5c245c               -mov ebx, dword ptr [esp + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a36bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a36c0  ff1524d25a00           -call dword ptr [0x5ad224]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5952036) /* 0x5ad224 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a36c6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a36c9  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004a36cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a36cd  8b3598bc4d00           -mov esi, dword ptr [0x4dbc98]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a36d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a36d4  ff1590bc4d00           -call dword ptr [0x4dbc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094544) /* 0x4dbc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a36da  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a36dd  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 004a36e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a36e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a36e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a36e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a36e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a36e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a36e6:
    // 004a36e6  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a36ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a36ec  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a36f0  e8cbfaffff             -call 0x4a31c0
    cpu.esp -= 4;
    sub_4a31c0(app, cpu);
    if (cpu.terminate) return;
    // 004a36f5  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 004a36f9  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a36fb  0f843effffff           -je 0x4a363f
    if (cpu.flags.zf)
    {
        goto L_0x004a363f;
    }
    // 004a3701  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3702  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 004a3708  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3709  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004a370d  ff97b40d0000           -call dword ptr [edi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3713  8b0d9cbc4d00           -mov ecx, dword ptr [0x4dbc9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094556) /* 0x4dbc9c */);
    // 004a3719  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a371c  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a371f  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 004a3723  8d5c2440               -lea ebx, [esp + 0x40]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a3727  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004a372d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a372f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3731  ff97a80d0000           -call dword ptr [edi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3737  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3739  0f8c95000000           -jl 0x4a37d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a37d4;
    }
    // 004a373f  8b0da0bc4d00           -mov ecx, dword ptr [0x4dbca0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094560) /* 0x4dbca0 */);
    // 004a3745  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a3749  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 004a374d  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a3751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3752  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3753  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3754  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004a3758  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3759  ff97b80d0000           -call dword ptr [edi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a375f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3762  8a0da4bc4d00           -mov cl, byte ptr [0x4dbca4]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5094564) /* 0x4dbca4 */);
    // 004a3768  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a376c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a376e  8b0d98bc4d00           -mov ecx, dword ptr [0x4dbc98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a3774  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a3777  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a3779  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a377a  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a377e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a377f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3780  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004a3786  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3787  ff97c00d0000           -call dword ptr [edi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a378d  8a5608                 -mov dl, byte ptr [esi + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a3790  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3793  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a3795  0f8490feffff           -je 0x4a362b
    if (cpu.flags.zf)
    {
        goto L_0x004a362b;
    }
    // 004a379b  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a379f  8a0da4bc4d00           -mov cl, byte ptr [0x4dbca4]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5094564) /* 0x4dbca4 */);
    // 004a37a5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a37a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a37aa  05acc04d00             -add eax, 0x4dc0ac
    (cpu.eax) += x86::reg32(x86::sreg32(5095596 /*0x4dc0ac*/));
    // 004a37af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a37b0  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a37b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a37b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a37b6  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 004a37bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a37bd  ff97e00d0000           -call dword ptr [edi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a37c3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a37c8  83c410                 +add esp, 0x10
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
    // 004a37cb  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 004a37cf  e957feffff             -jmp 0x4a362b
    goto L_0x004a362b;
L_0x004a37d4:
    // 004a37d4  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a37d8  e83bfbffff             -call 0x4a3318
    cpu.esp -= 4;
    sub_4a3318(app, cpu);
    if (cpu.terminate) return;
    // 004a37dd  e949feffff             -jmp 0x4a362b
    goto L_0x004a362b;
L_0x004a37e2:
    // 004a37e2  8b0d1cd25a00           -mov ecx, dword ptr [0x5ad21c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5952028) /* 0x5ad21c */);
    // 004a37e8  41                     -inc ecx
    (cpu.ecx)++;
    // 004a37e9  890d1cd25a00           -mov dword ptr [0x5ad21c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5952028) /* 0x5ad21c */) = cpu.ecx;
    // 004a37ef  81f9f4010000           +cmp ecx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a37f5  0f8c57feffff           -jl 0x4a3652
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3652;
    }
    // 004a37fb  e9affeffff             -jmp 0x4a36af
    goto L_0x004a36af;
L_0x004a3800:
    // 004a3800  68acbc4d00             -push 0x4dbcac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5094572 /*0x4dbcac*/;
    cpu.esp -= 4;
    // 004a3805  68acc04d00             -push 0x4dc0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5095596 /*0x4dc0ac*/;
    cpu.esp -= 4;
    // 004a380a  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004a380e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a380f  e8ec240100             -call 0x4b5d00
    cpu.esp -= 4;
    sub_4b5d00(app, cpu);
    if (cpu.terminate) return;
    // 004a3814  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3817  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3818  68acc04d00             -push 0x4dc0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5095596 /*0x4dc0ac*/;
    cpu.esp -= 4;
    // 004a381d  ff1590bc4d00           -call dword ptr [0x4dbc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094544) /* 0x4dbc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3823  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3826  68acbc4d00             -push 0x4dbcac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5094572 /*0x4dbcac*/;
    cpu.esp -= 4;
    // 004a382b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a382c  e8ff220100             -call 0x4b5b30
    cpu.esp -= 4;
    sub_4b5b30(app, cpu);
    if (cpu.terminate) return;
    // 004a3831  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3834  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a3838  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3839  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a383d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a383e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a3842  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3843  e8d0f70000             -call 0x4b3018
    cpu.esp -= 4;
    sub_4b3018(app, cpu);
    if (cpu.terminate) return;
    // 004a3848  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a384b  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 004a384d  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 004a384f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a3853  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3854  ff542450               -call dword ptr [esp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3858  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a385b  8b1598bc4d00           -mov edx, dword ptr [0x4dbc98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094552) /* 0x4dbc98 */);
    // 004a3861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3862  68acbc4d00             -push 0x4dbcac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5094572 /*0x4dbcac*/;
    cpu.esp -= 4;
    // 004a3867  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3868  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a386c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a386d  ff542458               -call dword ptr [esp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3871  83c410                 +add esp, 0x10
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
    // 004a3874  e936feffff             -jmp 0x4a36af
    goto L_0x004a36af;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a387c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a387c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a387d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a387e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a3880  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a3882  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3884  7e28                   -jle 0x4a38ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a38ae;
    }
L_0x004a3886:
    // 004a3886  81f900010000           +cmp ecx, 0x100
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
    // 004a388c  7e23                   -jle 0x4a38b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a38b1;
    }
    // 004a388e  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
L_0x004a3893:
    // 004a3893  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3895  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a3897  e864fdffff             -call 0x4a3600
    cpu.esp -= 4;
    sub_4a3600(app, cpu);
    if (cpu.terminate) return;
    // 004a389c  8b1528d25a00           -mov edx, dword ptr [0x5ad228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5952040) /* 0x5ad228 */);
    // 004a38a2  81e900010000           -sub ecx, 0x100
    (cpu.ecx) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004a38a8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a38aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a38ac  7fd8                   -jg 0x4a3886
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a3886;
    }
L_0x004a38ae:
    // 004a38ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a38af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a38b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a38b1:
    // 004a38b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a38b3  ebde                   -jmp 0x4a3893
    goto L_0x004a3893;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a38c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a38c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a38c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a38c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a38c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a38c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a38c5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a38c8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a38cc  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a38d0  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 004a38d4  e8c710feff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 004a38d9  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x004a38dc:
    // 004a38dc  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004a38e1  3b0c24                 +cmp ecx, dword ptr [esp]
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
    // 004a38e4  7f11                   -jg 0x4a38f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a38f7;
    }
    // 004a38e6  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x004a38e9:
    // 004a38e9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a38ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a38ee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a38f1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a38f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a38f5  750f                   -jne 0x4a3906
    if (!cpu.flags.zf)
    {
        goto L_0x004a3906;
    }
L_0x004a38f7:
    // 004a38f7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a38fa  39f9                   +cmp ecx, edi
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
    // 004a38fc  740f                   -je 0x4a390d
    if (cpu.flags.zf)
    {
        goto L_0x004a390d;
    }
    // 004a38fe  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a3901  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a3904  ebd6                   -jmp 0x4a38dc
    goto L_0x004a38dc;
L_0x004a3906:
    // 004a3906  41                     -inc ecx
    (cpu.ecx)++;
    // 004a3907  39f1                   +cmp ecx, esi
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
    // 004a3909  7ede                   -jle 0x4a38e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a38e9;
    }
    // 004a390b  ebea                   -jmp 0x4a38f7
    goto L_0x004a38f7;
L_0x004a390d:
    // 004a390d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a390f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3912  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3913  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3914  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3915  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3916  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3917  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a391c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a391c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a391d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a391e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a391f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3922  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a3924  c7442408cdcccc3d       -mov dword ptr [esp + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 004a392c  3d22560000             +cmp eax, 0x5622
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3931  0f8f96000000           -jg 0x4a39cd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a39cd;
    }
    // 004a3937  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a3939:
    // 004a3939  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a393c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a393e  898a3cd25a00           -mov dword ptr [edx + 0x5ad23c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5952060) /* 0x5ad23c */) = cpu.ecx;
    // 004a3944  81fa10590000           +cmp edx, 0x5910
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22800 /*0x5910*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a394a  75ed                   -jne 0x4a3939
    if (!cpu.flags.zf)
    {
        goto L_0x004a3939;
    }
    // 004a394c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a394d  b940d25a00             -mov ecx, 0x5ad240
    cpu.ecx = 5952064 /*0x5ad240*/;
    // 004a3952  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a3954:
    // 004a3954  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3957  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004a395b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a395d  898a6c2b5b00           -mov dword ptr [edx + 0x5b2b6c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5974892) /* 0x5b2b6c */) = cpu.ecx;
    // 004a3963  e858ffffff             -call 0x4a38c0
    cpu.esp -= 4;
    sub_4a38c0(app, cpu);
    if (cpu.terminate) return;
    // 004a3968  d982b8c84d00           -fld dword ptr [edx + 0x4dc8b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(5097656) /* 0x4dc8b8 */)));
    // 004a396e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a3970  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a3972  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004a3979  d99ac8c84d00           -fstp dword ptr [edx + 0x4dc8c8]
    app->getMemory<float>(cpu.edx + x86::reg32(5097672) /* 0x4dc8c8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a397f  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a3983  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a3985  dc0d18f34c00           -fmul qword ptr [0x4cf318]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5042968) /* 0x4cf318 */));
    // 004a398b  8b826c2b5b00           -mov eax, dword ptr [edx + 0x5b2b6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5974892) /* 0x5b2b6c */);
    // 004a3991  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a3993  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3996  89824c2b5b00           -mov dword ptr [edx + 0x5b2b4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5974860) /* 0x5b2b4c */) = cpu.eax;
    // 004a399c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a399e  89825c2b5b00           -mov dword ptr [edx + 0x5b2b5c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5974876) /* 0x5b2b5c */) = cpu.eax;
    // 004a39a4  899a8c2b5b00           -mov dword ptr [edx + 0x5b2b8c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5974924) /* 0x5b2b8c */) = cpu.ebx;
    // 004a39aa  899a2cd25a00           -mov dword ptr [edx + 0x5ad22c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5952044) /* 0x5ad22c */) = cpu.ebx;
    // 004a39b0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a39b2  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a39b4  899a7c2b5b00           -mov dword ptr [edx + 0x5b2b7c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5974908) /* 0x5b2b7c */) = cpu.ebx;
    // 004a39ba  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a39be  83fa10                 +cmp edx, 0x10
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
    // 004a39c1  7591                   -jne 0x4a3954
    if (!cpu.flags.zf)
    {
        goto L_0x004a3954;
    }
    // 004a39c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a39c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39c6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a39c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a39cd:
    // 004a39cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a39d2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a39d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a39d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a39e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a39e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a39e1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a39e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a39e6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a39e8  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a39ec  e83f230100             -call 0x4b5d30
    cpu.esp -= 4;
    sub_4b5d30(app, cpu);
    if (cpu.terminate) return;
    // 004a39f1  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a39f5  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a39f7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a39fb  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a39ff  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a3a01  d80d20f34c00           -fmul dword ptr [0x4cf320]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5042976) /* 0x4cf320 */));
    // 004a3a07  e8940ffeff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 004a3a0c  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a3a0f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a3a12  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3a15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a3a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3a20  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a3a22  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a3a24  83f840                 +cmp eax, 0x40
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
    // 004a3a27  740a                   -je 0x4a3a33
    if (cpu.flags.zf)
    {
        goto L_0x004a3a33;
    }
    // 004a3a29  7d09                   -jge 0x4a3a34
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3a34;
    }
    // 004a3a2b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a3a2e  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a3a31  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004a3a33:
    // 004a3a33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3a34:
    // 004a3a34  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004a3a39  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3a3b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3a3d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a3a40  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a3a43  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a3a45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a3a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3a51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3a52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3a53  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a3a55  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a3a57:
    // 004a3a57  4a                     -dec edx
    (cpu.edx)--;
    // 004a3a58  83faff                 +cmp edx, -1
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
    // 004a3a5b  740c                   -je 0x4a3a69
    if (cpu.flags.zf)
    {
        goto L_0x004a3a69;
    }
    // 004a3a5d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a3a5f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a3a62  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a3a64  40                     -inc eax
    (cpu.eax)++;
    // 004a3a65  01d9                   +add ecx, ebx
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
    // 004a3a67  ebee                   -jmp 0x4a3a57
    goto L_0x004a3a57;
L_0x004a3a69:
    // 004a3a69  83fe01                 +cmp esi, 1
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
    // 004a3a6c  7505                   -jne 0x4a3a73
    if (!cpu.flags.zf)
    {
        goto L_0x004a3a73;
    }
    // 004a3a6e  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3a71  7f26                   -jg 0x4a3a99
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a3a99;
    }
L_0x004a3a73:
    // 004a3a73  83fe02                 +cmp esi, 2
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
    // 004a3a76  7508                   -jne 0x4a3a80
    if (!cpu.flags.zf)
    {
        goto L_0x004a3a80;
    }
    // 004a3a78  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3a7e  7f21                   -jg 0x4a3aa1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a3aa1;
    }
L_0x004a3a80:
    // 004a3a80  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3a83  750e                   -jne 0x4a3a93
    if (!cpu.flags.zf)
    {
        goto L_0x004a3a93;
    }
    // 004a3a85  81f9ffff7f00           +cmp ecx, 0x7fffff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388607 /*0x7fffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3a8b  7e06                   -jle 0x4a3a93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3a93;
    }
    // 004a3a8d  81e900000001           -sub ecx, 0x1000000
    (cpu.ecx) -= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
L_0x004a3a93:
    // 004a3a93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3a95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3a99:
    // 004a3a99  81e900010000           +sub ecx, 0x100
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a3a9f  ebf2                   -jmp 0x4a3a93
    goto L_0x004a3a93;
L_0x004a3aa1:
    // 004a3aa1  81e900000100           -sub ecx, 0x10000
    (cpu.ecx) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004a3aa7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3aa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3aaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3aab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3aac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3ab0  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004a3ab6  c7809000000000000000   -mov dword ptr [eax + 0x90], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 004a3ac0  c7406c0f000000         -mov dword ptr [eax + 0x6c], 0xf
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 15 /*0xf*/;
    // 004a3ac7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a3ac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3ac8  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a3acf  c740087f000000         -mov dword ptr [eax + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 004a3ad6  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a3add  c740107f000000         -mov dword ptr [eax + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
    // 004a3ae4  c74014ffffffff         -mov dword ptr [eax + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 004a3aeb  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a3af2  c7401c3c000000         -mov dword ptr [eax + 0x1c], 0x3c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 60 /*0x3c*/;
    // 004a3af9  c74020ffffffff         -mov dword ptr [eax + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 004a3b00  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004a3b07  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004a3b0e  c7402c01000000         -mov dword ptr [eax + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 004a3b15  c7403040000000         -mov dword ptr [eax + 0x30], 0x40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 64 /*0x40*/;
    // 004a3b1c  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004a3b23  c740387f000000         -mov dword ptr [eax + 0x38], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 127 /*0x7f*/;
    // 004a3b2a  c7403c00000000         -mov dword ptr [eax + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 004a3b31  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 004a3b38  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004a3b3f  c7404800000000         -mov dword ptr [eax + 0x48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004a3b46  c7404c00000000         -mov dword ptr [eax + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004a3b4d  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004a3b54  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 004a3b5b  c74064ecc84d00         -mov dword ptr [eax + 0x64], 0x4dc8ec
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 5097708 /*0x4dc8ec*/;
    // 004a3b62  c740707f000000         -mov dword ptr [eax + 0x70], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = 127 /*0x7f*/;
    // 004a3b69  c7407400000000         -mov dword ptr [eax + 0x74], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 004a3b70  c7407800000000         -mov dword ptr [eax + 0x78], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 004a3b77  c7407c00000000         -mov dword ptr [eax + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 004a3b7e  c7808000000000000000   -mov dword ptr [eax + 0x80], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 004a3b88  c7808400000000000000   -mov dword ptr [eax + 0x84], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 004a3b92  c7808c00000000000000   -mov dword ptr [eax + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 004a3b9c  c7808800000000000000   -mov dword ptr [eax + 0x88], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a3ba6  c7809400000001000000   -mov dword ptr [eax + 0x94], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
    // 004a3bb0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3bb2  81c298000000           -add edx, 0x98
    (cpu.edx) += x86::reg32(x86::sreg32(152 /*0x98*/));
L_0x004a3bb8:
    // 004a3bb8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a3bbe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3bc1  39d0                   +cmp eax, edx
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
    // 004a3bc3  75f3                   -jne 0x4a3bb8
    if (!cpu.flags.zf)
    {
        goto L_0x004a3bb8;
    }
    // 004a3bc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a3bc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3bc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3bc9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3bca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3bcb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3bcc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3bcd  83784800               +cmp dword ptr [eax + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3bd1  7552                   -jne 0x4a3c25
    if (!cpu.flags.zf)
    {
        goto L_0x004a3c25;
    }
L_0x004a3bd3:
    // 004a3bd3  8b7054                 -mov esi, dword ptr [eax + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a3bd6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3bd8  7409                   -je 0x4a3be3
    if (cpu.flags.zf)
    {
        goto L_0x004a3be3;
    }
    // 004a3bda  8b4a54                 -mov ecx, dword ptr [edx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004a3bdd  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004a3be0  897854                 -mov dword ptr [eax + 0x54], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edi;
L_0x004a3be3:
    // 004a3be3  8b685c                 -mov ebp, dword ptr [eax + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004a3be6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a3be8  7409                   -je 0x4a3bf3
    if (cpu.flags.zf)
    {
        goto L_0x004a3bf3;
    }
    // 004a3bea  8b4a5c                 -mov ecx, dword ptr [edx + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 004a3bed  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a3bf0  89585c                 -mov dword ptr [eax + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.ebx;
L_0x004a3bf3:
    // 004a3bf3  8b7064                 -mov esi, dword ptr [eax + 0x64]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 004a3bf6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3bf8  7409                   -je 0x4a3c03
    if (cpu.flags.zf)
    {
        goto L_0x004a3c03;
    }
    // 004a3bfa  8b4a64                 -mov ecx, dword ptr [edx + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    // 004a3bfd  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004a3c00  897864                 -mov dword ptr [eax + 0x64], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = cpu.edi;
L_0x004a3c03:
    // 004a3c03  8b6874                 -mov ebp, dword ptr [eax + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004a3c06  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a3c08  7409                   -je 0x4a3c13
    if (cpu.flags.zf)
    {
        goto L_0x004a3c13;
    }
    // 004a3c0a  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 004a3c0d  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a3c10  895874                 -mov dword ptr [eax + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ebx;
L_0x004a3c13:
    // 004a3c13  8bb080000000           -mov esi, dword ptr [eax + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a3c19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3c1b  7510                   -jne 0x4a3c2d
    if (!cpu.flags.zf)
    {
        goto L_0x004a3c2d;
    }
    // 004a3c1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3c1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3c25:
    // 004a3c25  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004a3c28  014848                 +add dword ptr [eax + 0x48], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a3c2b  eba6                   -jmp 0x4a3bd3
    goto L_0x004a3bd3;
L_0x004a3c2d:
    // 004a3c2d  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 004a3c33  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004a3c36  89b880000000           -mov dword ptr [eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = cpu.edi;
    // 004a3c3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3c3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a3c44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3c44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3c45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3c46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3c47  8a3df4c84d00           -mov bh, byte ptr [0x4dc8f4]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5097716) /* 0x4dc8f4 */);
    // 004a3c4d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x004a3c4f:
    // 004a3c4f  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004a3c51  742a                   -je 0x4a3c7d
    if (cpu.flags.zf)
    {
        goto L_0x004a3c7d;
    }
L_0x004a3c53:
    // 004a3c53  b8f09b5900             -mov eax, 0x599bf0
    cpu.eax = 5872624 /*0x599bf0*/;
    // 004a3c58  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004a3c5a:
    // 004a3c5a  3a480c                 +cmp cl, byte ptr [eax + 0xc]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3c5d  7407                   -je 0x4a3c66
    if (cpu.flags.zf)
    {
        goto L_0x004a3c66;
    }
    // 004a3c5f  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004a3c62  38fb                   +cmp bl, bh
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
    // 004a3c64  74e9                   -je 0x4a3c4f
    if (cpu.flags.zf)
    {
        goto L_0x004a3c4f;
    }
L_0x004a3c66:
    // 004a3c66  42                     -inc edx
    (cpu.edx)++;
    // 004a3c67  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a3c6a  83fa10                 +cmp edx, 0x10
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
    // 004a3c6d  7ceb                   -jl 0x4a3c5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3c5a;
    }
    // 004a3c6f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a3c71  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 004a3c73  883df4c84d00           -mov byte ptr [0x4dc8f4], bh
    app->getMemory<x86::reg8>(x86::reg32(5097716) /* 0x4dc8f4 */) = cpu.bh;
    // 004a3c79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3c7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3c7d:
    // 004a3c7d  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004a3c7f  ebd2                   -jmp 0x4a3c53
    goto L_0x004a3c53;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3c84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3c84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3c85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3c86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3c87  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a3c8a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a3c8d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a3c91  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a3c93  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a3c95  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a3c99  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a3c9c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a3c9f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a3ca3  8b4305                 -mov eax, dword ptr [ebx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 004a3ca6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a3ca9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a3cad  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004a3cb0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a3cb3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a3cb7  8b4307                 -mov eax, dword ptr [ebx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004a3cba  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a3cbd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a3cc1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3cc3  e800ffffff             -call 0x4a3bc8
    cpu.esp -= 4;
    sub_4a3bc8(app, cpu);
    if (cpu.terminate) return;
    // 004a3cc8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a3ccc  83faff                 +cmp edx, -1
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
    // 004a3ccf  0f8429030000           -je 0x4a3ffe
    if (cpu.flags.zf)
    {
        goto L_0x004a3ffe;
    }
    // 004a3cd5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3cd7  0f8c2e030000           -jl 0x4a400b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a400b;
    }
    // 004a3cdd  83fa7f                 +cmp edx, 0x7f
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
    // 004a3ce0  0f8f25030000           -jg 0x4a400b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a400b;
    }
L_0x004a3ce6:
    // 004a3ce6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a3cea  83f8ff                 +cmp eax, -1
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
    // 004a3ced  0f8526030000           -jne 0x4a4019
    if (!cpu.flags.zf)
    {
        goto L_0x004a4019;
    }
    // 004a3cf3  c744241840000000       -mov dword ptr [esp + 0x18], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 64 /*0x40*/;
L_0x004a3cfb:
    // 004a3cfb  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a3cff  83fdff                 +cmp ebp, -1
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
    // 004a3d02  0f852c030000           -jne 0x4a4034
    if (!cpu.flags.zf)
    {
        goto L_0x004a4034;
    }
    // 004a3d08  c74424087f000000       -mov dword ptr [esp + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
L_0x004a3d10:
    // 004a3d10  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004a3d13  8b5e34                 -mov ebx, dword ptr [esi + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004a3d16  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a3d1a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a3d1c  7411                   -je 0x4a3d2f
    if (cpu.flags.zf)
    {
        goto L_0x004a3d2f;
    }
    // 004a3d1e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a3d20  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3d24  e8b7e10000             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a3d29  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a3d2b  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x004a3d2f:
    // 004a3d2f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3d33  83f87f                 +cmp eax, 0x7f
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
    // 004a3d36  0f8e13030000           -jle 0x4a404f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a404f;
    }
    // 004a3d3c  c74424147f000000       -mov dword ptr [esp + 0x14], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 127 /*0x7f*/;
L_0x004a3d44:
    // 004a3d44  8bae94000000           -mov ebp, dword ptr [esi + 0x94]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004a3d4a  83fd01                 +cmp ebp, 1
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
    // 004a3d4d  7411                   -je 0x4a3d60
    if (cpu.flags.zf)
    {
        goto L_0x004a3d60;
    }
    // 004a3d4f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a3d53  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a3d56  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a3d59  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a3d5c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004a3d60:
    // 004a3d60  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3d64  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a3d68  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a3d6b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a3d6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3d71  0f8ceb020000           -jl 0x4a4062
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4062;
    }
    // 004a3d77  83f87f                 +cmp eax, 0x7f
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
    // 004a3d7a  7e08                   -jle 0x4a3d84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3d84;
    }
    // 004a3d7c  c74424187f000000       -mov dword ptr [esp + 0x18], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 127 /*0x7f*/;
L_0x004a3d84:
    // 004a3d84  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3d88  83f9ff                 +cmp ecx, -1
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
    // 004a3d8b  0f85dc020000           -jne 0x4a406d
    if (!cpu.flags.zf)
    {
        goto L_0x004a406d;
    }
    // 004a3d91  c744241040000000       -mov dword ptr [esp + 0x10], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 64 /*0x40*/;
L_0x004a3d99:
    // 004a3d99  b9a02b5b00             -mov ecx, 0x5b2ba0
    cpu.ecx = 5974944 /*0x5b2ba0*/;
    // 004a3d9e  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a3da1  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004a3da4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a3da7  e880d1ffff             -call 0x4a0f2c
    cpu.esp -= 4;
    sub_4a0f2c(app, cpu);
    if (cpu.terminate) return;
    // 004a3dac  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a3dae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3db0  0f8c3f020000           -jl 0x4a3ff5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3ff5;
    }
    // 004a3db6  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004a3dbd  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3dbf  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004a3dc2  81c1f09b5900           -add ecx, 0x599bf0
    (cpu.ecx) += x86::reg32(x86::sreg32(5872624 /*0x599bf0*/));
    // 004a3dc8  8a8694000000           -mov al, byte ptr [esi + 0x94]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004a3dce  884137                 -mov byte ptr [ecx + 0x37], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */) = cpu.al;
    // 004a3dd1  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004a3dd5  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004a3dd9  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a3ddd  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a3de1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3de3  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004a3de6  668b5910               -mov bx, word ptr [ecx + 0x10]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a3dea  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3dec  66895910               -mov word ptr [ecx + 0x10], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.bx;
    // 004a3df0  83be9000000000         +cmp dword ptr [esi + 0x90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3df7  740c                   -je 0x4a3e05
    if (cpu.flags.zf)
    {
        goto L_0x004a3e05;
    }
    // 004a3df9  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a3dfd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a3dff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a3e01  66895110               -mov word ptr [ecx + 0x10], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dx;
L_0x004a3e05:
    // 004a3e05  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004a3e08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a3e0a  740b                   -je 0x4a3e17
    if (cpu.flags.zf)
    {
        goto L_0x004a3e17;
    }
    // 004a3e0c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a3e0e  e8cde00000             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a3e13  66014110               -add word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x004a3e17:
    // 004a3e17  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004a3e1a  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004a3e1d  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004a3e20  894150                 -mov dword ptr [ecx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004a3e23  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004a3e26  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 004a3e29  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 004a3e2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3e2e  740b                   -je 0x4a3e3b
    if (cpu.flags.zf)
    {
        goto L_0x004a3e3b;
    }
    // 004a3e30  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a3e34  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a3e37  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004a3e3b:
    // 004a3e3b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a3e3d  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a3e40  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a3e44  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a3e4b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a3e4e  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a3e51  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004a3e54  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004a3e57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a3e59  7409                   -je 0x4a3e64
    if (cpu.flags.zf)
    {
        goto L_0x004a3e64;
    }
    // 004a3e5b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a3e5d  e87ee00000             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a3e62  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a3e64:
    // 004a3e64  83fa7f                 +cmp edx, 0x7f
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
    // 004a3e67  0f8e1b020000           -jle 0x4a4088
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4088;
    }
    // 004a3e6d  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x004a3e72:
    // 004a3e72  0faf542434             -imul edx, dword ptr [esp + 0x34]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 004a3e77  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 004a3e7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3e7e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a3e81  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a3e83  884130                 -mov byte ptr [ecx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 004a3e86  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3e8a  884132                 -mov byte ptr [ecx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 004a3e8d  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a3e91  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a3e94  668b4628               -mov ax, word ptr [esi + 0x28]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004a3e98  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004a3e9b  66894142               -mov word ptr [ecx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 004a3e9f  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3ea3  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004a3ea6  8b4664                 -mov eax, dword ptr [esi + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 004a3ea9  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004a3eac  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 004a3eaf  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a3eb2  c6413500               -mov byte ptr [ecx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 004a3eb6  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a3eb9  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a3ebc  884134                 -mov byte ptr [ecx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 004a3ebf  8a4620                 -mov al, byte ptr [esi + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a3ec2  884136                 -mov byte ptr [ecx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 004a3ec5  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004a3ec8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a3eca  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a3ecd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3ecf  0f8cc6010000           -jl 0x4a409b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a409b;
    }
L_0x004a3ed5:
    // 004a3ed5  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004a3ed8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a3edb  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a3ede  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a3ee1  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a3ee3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3ee5  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004a3ee8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a3eeb  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a3eed  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a3ef0  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 004a3ef3  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004a3ef6  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004a3efc  89415c                 -mov dword ptr [ecx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 004a3eff  8a4678                 -mov al, byte ptr [esi + 0x78]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004a3f02  88413c                 -mov byte ptr [ecx + 0x3c], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.al;
    // 004a3f05  8a8684000000           -mov al, byte ptr [esi + 0x84]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004a3f0b  88413d                 -mov byte ptr [ecx + 0x3d], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(61) /* 0x3d */) = cpu.al;
    // 004a3f0e  668b8688000000         -mov ax, word ptr [esi + 0x88]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004a3f15  66894140               -mov word ptr [ecx + 0x40], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.ax;
    // 004a3f19  837e7c00               +cmp dword ptr [esi + 0x7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3f1d  0f8484010000           -je 0x4a40a7
    if (cpu.flags.zf)
    {
        goto L_0x004a40a7;
    }
    // 004a3f23  e8bc25feff             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 004a3f28  8b5e78                 -mov ebx, dword ptr [esi + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004a3f2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3f2d  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a3f2f  88513e                 -mov byte ptr [ecx + 0x3e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.dl;
L_0x004a3f32:
    // 004a3f32  83be8c00000000         +cmp dword ptr [esi + 0x8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3f39  0f8471010000           -je 0x4a40b0
    if (cpu.flags.zf)
    {
        goto L_0x004a40b0;
    }
    // 004a3f3f  e8a025feff             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 004a3f44  8b9e84000000           -mov ebx, dword ptr [esi + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004a3f4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3f4c  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a3f4e  88513f                 -mov byte ptr [ecx + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = cpu.dl;
L_0x004a3f51:
    // 004a3f51  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a3f53  e898890000             -call 0x4ac8f0
    cpu.esp -= 4;
    sub_4ac8f0(app, cpu);
    if (cpu.terminate) return;
    // 004a3f58  8a466c                 -mov al, byte ptr [esi + 0x6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 004a3f5b  88410b                 -mov byte ptr [ecx + 0xb], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = cpu.al;
    // 004a3f5e  8a464c                 -mov al, byte ptr [esi + 0x4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004a3f61  884138                 -mov byte ptr [ecx + 0x38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 004a3f64  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a3f68  884139                 -mov byte ptr [ecx + 0x39], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 004a3f6b  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a3f6e  88410a                 -mov byte ptr [ecx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 004a3f71  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004a3f74  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004a3f78  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a3f7a  e831080000             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 004a3f7f  807f0b00               +cmp byte ptr [edi + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3f83  0f8430010000           -je 0x4a40b9
    if (cpu.flags.zf)
    {
        goto L_0x004a40b9;
    }
    // 004a3f89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a3f8b:
    // 004a3f8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3f8c  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a3f8f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a3f92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3f93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3f95  668b470c               -mov ax, word ptr [edi + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a3f99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3f9a  8b4135                 -mov eax, dword ptr [ecx + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 004a3f9d  8b3de49b5900           -mov edi, dword ptr [0x599be4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5872612) /* 0x599be4 */);
    // 004a3fa3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a3fa6  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a3fa9  8b5136                 -mov edx, dword ptr [ecx + 0x36]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(54) /* 0x36 */);
    // 004a3fac  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a3faf  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a3fb2  bb013f0000             -mov ebx, 0x3f01
    cpu.ebx = 16129 /*0x3f01*/;
    // 004a3fb7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3fb9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a3fbc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a3fbe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3fbf  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a3fc2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a3fc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3fc6  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a3fc9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a3fcc  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3fd0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3fd1  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a3fd5  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a3fd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3fd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3fda  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a3fdc  8a4202                 -mov al, byte ptr [edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a3fdf  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a3fe3  e8c033feff             -call 0x4873a8
    cpu.esp -= 4;
    sub_4873a8(app, cpu);
    if (cpu.terminate) return;
    // 004a3fe8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3fea  0f8cd3000000           -jl 0x4a40c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a40c3;
    }
    // 004a3ff0  a1a02b5b00             -mov eax, dword ptr [0x5b2ba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5974944) /* 0x5b2ba0 */);
L_0x004a3ff5:
    // 004a3ff5  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a3ff8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ff9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ffb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a3ffe:
    // 004a3ffe  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
    // 004a4006  e9dbfcffff             -jmp 0x4a3ce6
    goto L_0x004a3ce6;
L_0x004a400b:
    // 004a400b  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a4010  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a4013  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4014  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4015  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4016  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a4019:
    // 004a4019  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a401b  7c09                   -jl 0x4a4026
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4026;
    }
    // 004a401d  83f87f                 +cmp eax, 0x7f
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
    // 004a4020  0f8ed5fcffff           -jle 0x4a3cfb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3cfb;
    }
L_0x004a4026:
    // 004a4026  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a402b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a402e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a402f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4030  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4031  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a4034:
    // 004a4034  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a4036  7c09                   -jl 0x4a4041
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4041;
    }
    // 004a4038  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a403b  0f8ecffcffff           -jle 0x4a3d10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3d10;
    }
L_0x004a4041:
    // 004a4041  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a4046  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a4049  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a404a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a404b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a404c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a404f:
    // 004a404f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4051  0f8dedfcffff           -jge 0x4a3d44
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3d44;
    }
    // 004a4057  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a4059  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a405d  e9e2fcffff             -jmp 0x4a3d44
    goto L_0x004a3d44;
L_0x004a4062:
    // 004a4062  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a4064  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a4068  e917fdffff             -jmp 0x4a3d84
    goto L_0x004a3d84;
L_0x004a406d:
    // 004a406d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a406f  7c09                   -jl 0x4a407a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a407a;
    }
    // 004a4071  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4074  0f8e1ffdffff           -jle 0x4a3d99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3d99;
    }
L_0x004a407a:
    // 004a407a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a407f  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a4082  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4083  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4085  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a4088:
    // 004a4088  83fa80                 +cmp edx, -0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-128 /*-0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a408b  0f8de1fdffff           -jge 0x4a3e72
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3e72;
    }
    // 004a4091  ba80ffffff             -mov edx, 0xffffff80
    cpu.edx = 4294967168 /*0xffffff80*/;
    // 004a4096  e9d7fdffff             -jmp 0x4a3e72
    goto L_0x004a3e72;
L_0x004a409b:
    // 004a409b  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 004a40a2  e92efeffff             -jmp 0x4a3ed5
    goto L_0x004a3ed5;
L_0x004a40a7:
    // 004a40a7  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
    // 004a40ab  e982feffff             -jmp 0x4a3f32
    goto L_0x004a3f32;
L_0x004a40b0:
    // 004a40b0  c6413f00               -mov byte ptr [ecx + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
    // 004a40b4  e998feffff             -jmp 0x4a3f51
    goto L_0x004a3f51;
L_0x004a40b9:
    // 004a40b9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a40be  e9c8feffff             -jmp 0x4a3f8b
    goto L_0x004a3f8b;
L_0x004a40c3:
    // 004a40c3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a40c5  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a40ca  e819d1ffff             -call 0x4a11e8
    cpu.esp -= 4;
    sub_4a11e8(app, cpu);
    if (cpu.terminate) return;
    // 004a40cf  8915a02b5b00           -mov dword ptr [0x5b2ba0], edx
    app->getMemory<x86::reg32>(x86::reg32(5974944) /* 0x5b2ba0 */) = cpu.edx;
    // 004a40d5  a1a02b5b00             -mov eax, dword ptr [0x5b2ba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5974944) /* 0x5b2ba0 */);
    // 004a40da  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a40dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a40de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a40df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a40e0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a40e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a40e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a40e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a40e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a40e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a40e8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a40e9  81ec98010000           -sub esp, 0x198
    (cpu.esp) -= x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004a40ef  89842480010000         -mov dword ptr [esp + 0x180], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.eax;
    // 004a40f6  8994247c010000         -mov dword ptr [esp + 0x17c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */) = cpu.edx;
    // 004a40fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a40ff  b9f7ffffff             -mov ecx, 0xfffffff7
    cpu.ecx = 4294967287 /*0xfffffff7*/;
    // 004a4104  89942488010000         -mov dword ptr [esp + 0x188], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.edx;
    // 004a410b  898c2470010000         -mov dword ptr [esp + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 004a4112  8994248c010000         -mov dword ptr [esp + 0x18c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.edx;
    // 004a4119  89942490010000         -mov dword ptr [esp + 0x190], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.edx;
    // 004a4120  89942474010000         -mov dword ptr [esp + 0x174], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.edx;
    // 004a4127  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4129  0f84e8000000           -je 0x4a4217
    if (cpu.flags.zf)
    {
        goto L_0x004a4217;
    }
    // 004a412f  6681385054             +cmp word ptr [eax], 0x5450
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
    // 004a4134  0f85ba000000           -jne 0x4a41f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a41f4;
    }
    // 004a413a  8bac247c010000         -mov ebp, dword ptr [esp + 0x17c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 004a4141  8bbc247c010000         -mov edi, dword ptr [esp + 0x17c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 004a4148  8b6d03                 -mov ebp, dword ptr [ebp + 3]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 004a414b  8b7f02                 -mov edi, dword ptr [edi + 2]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a414e  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 004a4151  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 004a4154  83fdff                 +cmp ebp, -1
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
    // 004a4157  0f859e000000           -jne 0x4a41fb
    if (!cpu.flags.zf)
    {
        goto L_0x004a41fb;
    }
    // 004a415d  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x004a4162:
    // 004a4162  83ffff                 +cmp edi, -1
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
    // 004a4165  0f859f000000           -jne 0x4a420a
    if (!cpu.flags.zf)
    {
        goto L_0x004a420a;
    }
    // 004a416b  bf3c000000             -mov edi, 0x3c
    cpu.edi = 60 /*0x3c*/;
L_0x004a4170:
    // 004a4170  8b842480010000         -mov eax, dword ptr [esp + 0x180]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 004a4177  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004a417b  0f84a7000000           -je 0x4a4228
    if (cpu.flags.zf)
    {
        goto L_0x004a4228;
    }
    // 004a4181  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a4184:
    // 004a4184  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a418b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a418d  e81ef9ffff             -call 0x4a3ab0
    cpu.esp -= 4;
    sub_4a3ab0(app, cpu);
    if (cpu.terminate) return;
    // 004a4192  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a4199  e82af9ffff             -call 0x4a3ac8
    cpu.esp -= 4;
    sub_4a3ac8(app, cpu);
    if (cpu.terminate) return;
    // 004a419e  e82dcdffff             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 004a41a3  e89cfaffff             -call 0x4a3c44
    cpu.esp -= 4;
    sub_4a3c44(app, cpu);
    if (cpu.terminate) return;
    // 004a41a8  89842478010000         -mov dword ptr [esp + 0x178], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */) = cpu.eax;
    // 004a41af  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a41b6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a41b9  89842494010000         -mov dword ptr [esp + 0x194], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.eax;
L_0x004a41c0:
    // 004a41c0  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a41c7  40                     -inc eax
    (cpu.eax)++;
    // 004a41c8  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a41ca  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 004a41d1  80feff                 +cmp dh, 0xff
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a41d4  0f8489010000           -je 0x4a4363
    if (cpu.flags.zf)
    {
        goto L_0x004a4363;
    }
    // 004a41da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a41dc  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 004a41de  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a41e1  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41e7  7547                   -jne 0x4a4230
    if (!cpu.flags.zf)
    {
        goto L_0x004a4230;
    }
    // 004a41e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a41eb  89842488010000         -mov dword ptr [esp + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 004a41f2  ebcc                   -jmp 0x4a41c0
    goto L_0x004a41c0;
L_0x004a41f4:
    // 004a41f4  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a41f9  eb21                   -jmp 0x4a421c
    goto L_0x004a421c;
L_0x004a41fb:
    // 004a41fb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a41fd  7c18                   -jl 0x4a4217
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4217;
    }
    // 004a41ff  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4202  0f8e5affffff           -jle 0x4a4162
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4162;
    }
    // 004a4208  eb0d                   -jmp 0x4a4217
    goto L_0x004a4217;
L_0x004a420a:
    // 004a420a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a420c  7c09                   -jl 0x4a4217
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4217;
    }
    // 004a420e  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4211  0f8e59ffffff           -jle 0x4a4170
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4170;
    }
L_0x004a4217:
    // 004a4217  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004a421c:
    // 004a421c  81c498010000           +add esp, 0x198
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(408 /*0x198*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4222  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4223  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4224  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4225  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4226  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4227  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4228:
    // 004a4228  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a422b  e954ffffff             -jmp 0x4a4184
    goto L_0x004a4184;
L_0x004a4230:
    // 004a4230  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4236  0f85b1000000           -jne 0x4a42ed
    if (!cpu.flags.zf)
    {
        goto L_0x004a42ed;
    }
    // 004a423c  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4243  7d14                   -jge 0x4a4259
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4259;
    }
L_0x004a4245:
    // 004a4245  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a4247  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a424e  e875f8ffff             -call 0x4a3ac8
    cpu.esp -= 4;
    sub_4a3ac8(app, cpu);
    if (cpu.terminate) return;
    // 004a4253  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4254  e967ffffff             -jmp 0x4a41c0
    goto L_0x004a41c0;
L_0x004a4259:
    // 004a4259  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4260  7fe3                   -jg 0x4a4245
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4245;
    }
    // 004a4262  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4269  7cda                   -jl 0x4a4245
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4245;
    }
    // 004a426b  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4272  7fd1                   -jg 0x4a4245
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4245;
    }
    // 004a4274  8b942474010000         -mov edx, dword ptr [esp + 0x174]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 004a427b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a427c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a427d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4281  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4282  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004a4289  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 004a4290  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4291  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 004a4298  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 004a429f  e8e0f9ffff             -call 0x4a3c84
    cpu.esp -= 4;
    sub_4a3c84(app, cpu);
    if (cpu.terminate) return;
    // 004a42a4  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 004a42ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a42ad  0f8c3a010000           -jl 0x4a43ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a43ed;
    }
    // 004a42b3  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 004a42ba  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a42bd  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 004a42c4  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 004a42cb  898c2494010000         -mov dword ptr [esp + 0x194], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.ecx;
    // 004a42d2  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 004a42d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a42db  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a42e2  e8e1f7ffff             -call 0x4a3ac8
    cpu.esp -= 4;
    sub_4a3ac8(app, cpu);
    if (cpu.terminate) return;
    // 004a42e7  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a42e8  e9d3feffff             -jmp 0x4a41c0
    goto L_0x004a41c0;
L_0x004a42ed:
    // 004a42ed  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a42ef  81fbfc000000           +cmp ebx, 0xfc
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
    // 004a42f5  0f84c5feffff           -je 0x4a41c0
    if (cpu.flags.zf)
    {
        goto L_0x004a41c0;
    }
    // 004a42fb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a42fd  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a42ff  81f9ff000000           +cmp ecx, 0xff
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
    // 004a4305  7514                   -jne 0x4a431b
    if (!cpu.flags.zf)
    {
        goto L_0x004a431b;
    }
    // 004a4307  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a430a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a430f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4311  e83af7ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a4316  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a4318  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a431b:
    // 004a431b  46                     -inc esi
    (cpu.esi)++;
    // 004a431c  83fb26                 +cmp ebx, 0x26
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a431f  7c07                   -jl 0x4a4328
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4328;
    }
L_0x004a4321:
    // 004a4321  01ce                   +add esi, ecx
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
    // 004a4323  e998feffff             -jmp 0x4a41c0
    goto L_0x004a41c0;
L_0x004a4328:
    // 004a4328  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a432a  7cf5                   -jl 0x4a4321
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4321;
    }
    // 004a432c  83f904                 +cmp ecx, 4
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
    // 004a432f  7ff0                   -jg 0x4a4321
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4321;
    }
    // 004a4331  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4333  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4335  e816f7ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a433a  89849c98000000         -mov dword ptr [esp + ebx*4 + 0x98], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */ + cpu.ebx * 4) = cpu.eax;
    // 004a4341  89349c                 -mov dword ptr [esp + ebx*4], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 4) = cpu.esi;
    // 004a4344  83fb24                 +cmp ebx, 0x24
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4347  75d8                   -jne 0x4a4321
    if (!cpu.flags.zf)
    {
        goto L_0x004a4321;
    }
    // 004a4349  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004a4350  e88bdb0000             -call 0x4b1ee0
    cpu.esp -= 4;
    sub_4b1ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a4355  89842474010000         -mov dword ptr [esp + 0x174], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.eax;
    // 004a435c  01ce                   +add esi, ecx
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
    // 004a435e  e95dfeffff             -jmp 0x4a41c0
    goto L_0x004a41c0;
L_0x004a4363:
    // 004a4363  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a436a  0f8c72000000           -jl 0x4a43e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a43e2;
    }
    // 004a4370  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4377  7f69                   -jg 0x4a43e2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a43e2;
    }
    // 004a4379  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4380  7c60                   -jl 0x4a43e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a43e2;
    }
    // 004a4382  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4389  7f57                   -jg 0x4a43e2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a43e2;
    }
    // 004a438b  8bb42474010000         -mov esi, dword ptr [esp + 0x174]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 004a4392  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4393  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4394  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4398  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4399  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004a43a0  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 004a43a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a43a8  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 004a43af  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 004a43b6  e8c9f8ffff             -call 0x4a3c84
    cpu.esp -= 4;
    sub_4a3c84(app, cpu);
    if (cpu.terminate) return;
    // 004a43bb  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 004a43c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a43c4  7c27                   -jl 0x4a43ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a43ed;
    }
    // 004a43c6  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 004a43cd  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 004a43d4  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 004a43db  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
L_0x004a43e2:
    // 004a43e2  8bbc248c010000         -mov edi, dword ptr [esp + 0x18c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a43e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a43eb  7542                   -jne 0x4a442f
    if (!cpu.flags.zf)
    {
        goto L_0x004a442f;
    }
L_0x004a43ed:
    // 004a43ed  8b9c248c010000         -mov ebx, dword ptr [esp + 0x18c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004a43f4  e8ebcaffff             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004a43f9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a43fb  7e1f                   -jle 0x4a441c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a441c;
    }
    // 004a43fd  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004a4404  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a4406:
    // 004a4406  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 004a440d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4410  e89b38feff             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
    // 004a4415  39d1                   +cmp ecx, edx
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
    // 004a4417  7ced                   -jl 0x4a4406
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4406;
    }
    // 004a4419  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a441c:
    // 004a441c  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004a4423  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004a4429  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a442a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a442b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a442c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a442d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a442e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a442f:
    // 004a442f  83ff01                 +cmp edi, 1
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
    // 004a4432  753f                   -jne 0x4a4473
    if (!cpu.flags.zf)
    {
        goto L_0x004a4473;
    }
    // 004a4434  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004a443b  e89cceffff             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 004a4440  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4442  7c17                   -jl 0x4a445b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a445b;
    }
    // 004a4444  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4446  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a4449  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a444b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a444e  05f09b5900             -add eax, 0x599bf0
    (cpu.eax) += x86::reg32(x86::sreg32(5872624 /*0x599bf0*/));
    // 004a4453  c6403b00               -mov byte ptr [eax + 0x3b], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */) = 0 /*0x0*/;
    // 004a4457  c6403a00               -mov byte ptr [eax + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
L_0x004a445b:
    // 004a445b  e884caffff             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004a4460  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004a4467  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004a446d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a446e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a446f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4470  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4471  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4472  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4473:
    // 004a4473  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a4475  7e3f                   -jle 0x4a44b6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a44b6;
    }
    // 004a4477  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004a447e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a4480:
    // 004a4480  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 004a4487  e850ceffff             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 004a448c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a448e  7c1f                   -jl 0x4a44af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a44af;
    }
    // 004a4490  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a4493  bbf09b5900             -mov ebx, 0x599bf0
    cpu.ebx = 5872624 /*0x599bf0*/;
    // 004a4498  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a449a  8a842478010000         -mov al, byte ptr [esp + 0x178]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 004a44a1  c6433a00               -mov byte ptr [ebx + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
    // 004a44a5  899c2490010000         -mov dword ptr [esp + 0x190], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.ebx;
    // 004a44ac  88433b                 -mov byte ptr [ebx + 0x3b], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(59) /* 0x3b */) = cpu.al;
L_0x004a44af:
    // 004a44af  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a44b2  39d1                   +cmp ecx, edx
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
    // 004a44b4  7cca                   -jl 0x4a4480
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4480;
    }
L_0x004a44b6:
    // 004a44b6  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 004a44bd  c6403a01               -mov byte ptr [eax + 0x3a], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 1 /*0x1*/;
    // 004a44c1  eb98                   -jmp 0x4a445b
    goto L_0x004a445b;
}

/* align: skip 0x90 */
void Application::sub_4a44c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a44c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a44c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a44c6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a44c9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a44cc  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a44ce  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a44d0  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a44d3  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a44d8  6681fa5054             +cmp dx, 0x5450
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a44dd  7552                   -jne 0x4a4531
    if (!cpu.flags.zf)
    {
        goto L_0x004a4531;
    }
    // 004a44df  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004a44e2  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a44e5  7555                   -jne 0x4a453c
    if (!cpu.flags.zf)
    {
        goto L_0x004a453c;
    }
    // 004a44e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a44e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a44e9  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a44ec  7452                   -je 0x4a4540
    if (cpu.flags.zf)
    {
        goto L_0x004a4540;
    }
    // 004a44ee  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a44f1:
    // 004a44f1  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a44f3  3cff                   +cmp al, 0xff
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
    // 004a44f5  7460                   -je 0x4a4557
    if (cpu.flags.zf)
    {
        goto L_0x004a4557;
    }
    // 004a44f7  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 004a44fa  81fefd000000           +cmp esi, 0xfd
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
    // 004a4500  750e                   -jne 0x4a4510
    if (!cpu.flags.zf)
    {
        goto L_0x004a4510;
    }
    // 004a4502  41                     -inc ecx
    (cpu.ecx)++;
    // 004a4503  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a4505  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a4507  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4509  e81232feff             -call 0x487720
    cpu.esp -= 4;
    sub_487720(app, cpu);
    if (cpu.terminate) return;
    // 004a450e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a4510:
    // 004a4510  41                     -inc ecx
    (cpu.ecx)++;
    // 004a4511  81fefe000000           +cmp esi, 0xfe
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4517  74d8                   -je 0x4a44f1
    if (cpu.flags.zf)
    {
        goto L_0x004a44f1;
    }
    // 004a4519  81fefc000000           +cmp esi, 0xfc
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
    // 004a451f  74d0                   -je 0x4a44f1
    if (cpu.flags.zf)
    {
        goto L_0x004a44f1;
    }
    // 004a4521  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4523  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a4525  3dff000000             +cmp eax, 0xff
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
    // 004a452a  7419                   -je 0x4a4545
    if (cpu.flags.zf)
    {
        goto L_0x004a4545;
    }
L_0x004a452c:
    // 004a452c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a452d  01c1                   +add ecx, eax
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
    // 004a452f  ebc0                   -jmp 0x4a44f1
    goto L_0x004a44f1;
L_0x004a4531:
    // 004a4531  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x004a4536:
    // 004a4536  83c404                 +add esp, 4
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
    // 004a4539  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a453a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a453b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a453c:
    // 004a453c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a453e  ebf6                   -jmp 0x4a4536
    goto L_0x004a4536;
L_0x004a4540:
    // 004a4540  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a4543  ebac                   -jmp 0x4a44f1
    goto L_0x004a44f1;
L_0x004a4545:
    // 004a4545  41                     -inc ecx
    (cpu.ecx)++;
    // 004a4546  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a454b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a454d  e8fef4ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a4552  83c103                 +add ecx, 3
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
    // 004a4555  ebd5                   -jmp 0x4a452c
    goto L_0x004a452c;
L_0x004a4557:
    // 004a4557  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4559  7c08                   -jl 0x4a4563
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4563;
    }
    // 004a455b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a455f  80480301               -or byte ptr [eax + 3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004a4563:
    // 004a4563  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a4565  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4566  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4567  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a456a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a456b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a456c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a4570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4573  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4574  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a4576  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a4578  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004a457c  7437                   -je 0x4a45b5
    if (cpu.flags.zf)
    {
        goto L_0x004a45b5;
    }
    // 004a457e  8d4f08                 -lea ecx, [edi + 8]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
L_0x004a4581:
    // 004a4581  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a4583  80faff                 +cmp dl, 0xff
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4586  7450                   -je 0x4a45d8
    if (cpu.flags.zf)
    {
        goto L_0x004a45d8;
    }
    // 004a4588  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a458a  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 004a458c  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4592  7426                   -je 0x4a45ba
    if (cpu.flags.zf)
    {
        goto L_0x004a45ba;
    }
L_0x004a4594:
    // 004a4594  41                     -inc ecx
    (cpu.ecx)++;
    // 004a4595  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a459b  74e4                   -je 0x4a4581
    if (cpu.flags.zf)
    {
        goto L_0x004a4581;
    }
    // 004a459d  81fbfc000000           +cmp ebx, 0xfc
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
    // 004a45a3  74dc                   -je 0x4a4581
    if (cpu.flags.zf)
    {
        goto L_0x004a4581;
    }
    // 004a45a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a45a7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a45a9  3dff000000             +cmp eax, 0xff
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
    // 004a45ae  7416                   -je 0x4a45c6
    if (cpu.flags.zf)
    {
        goto L_0x004a45c6;
    }
L_0x004a45b0:
    // 004a45b0  41                     -inc ecx
    (cpu.ecx)++;
    // 004a45b1  01c1                   +add ecx, eax
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
    // 004a45b3  ebcc                   -jmp 0x4a4581
    goto L_0x004a4581;
L_0x004a45b5:
    // 004a45b5  8d4f04                 -lea ecx, [edi + 4]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a45b8  ebc7                   -jmp 0x4a4581
    goto L_0x004a4581;
L_0x004a45ba:
    // 004a45ba  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a45bb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a45bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a45bf  e8dc29feff             -call 0x486fa0
    cpu.esp -= 4;
    sub_486fa0(app, cpu);
    if (cpu.terminate) return;
    // 004a45c4  ebce                   -jmp 0x4a4594
    goto L_0x004a4594;
L_0x004a45c6:
    // 004a45c6  41                     -inc ecx
    (cpu.ecx)++;
    // 004a45c7  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a45cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a45ce  e87df4ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a45d3  83c103                 +add ecx, 3
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
    // 004a45d6  ebd8                   -jmp 0x4a45b0
    goto L_0x004a45b0;
L_0x004a45d8:
    // 004a45d8  8a7703                 -mov dh, byte ptr [edi + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004a45db  80e6fe                 -and dh, 0xfe
    cpu.dh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a45de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a45e0  887703                 -mov byte ptr [edi + 3], dh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 004a45e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a45f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a45f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a45f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a45f2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a45f4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a45f6  e8b5170100             -call 0x4b5db0
    cpu.esp -= 4;
    sub_4b5db0(app, cpu);
    if (cpu.terminate) return;
    // 004a45fb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a45fd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a45ff  7c09                   -jl 0x4a460a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a460a;
    }
    // 004a4601  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a4603  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4605  7c11                   -jl 0x4a4618
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4618;
    }
    // 004a4607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4609  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a460a:
    // 004a460a  6bc2ff                 -imul eax, edx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a460d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a460f  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a4611  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4613  7c03                   -jl 0x4a4618
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4618;
    }
    // 004a4615  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4616  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4617  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4618:
    // 004a4618  6bc3ff                 -imul eax, ebx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a461b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a461d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a461e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a461f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4622  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4623  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4626  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a462a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a462d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a462f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a4631  e87a170100             -call 0x4b5db0
    cpu.esp -= 4;
    sub_4b5db0(app, cpu);
    if (cpu.terminate) return;
    // 004a4636  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a463a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a463c  0f8c93000000           -jl 0x4a46d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a46d5;
    }
L_0x004a4642:
    // 004a4642  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4646  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a4648  0f8ca1000000           -jl 0x4a46ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a46ef;
    }
    // 004a464e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a4650  0f8c99000000           -jl 0x4a46ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a46ef;
    }
    // 004a4656  39cd                   +cmp ebp, ecx
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
    // 004a4658  0f8e87000000           -jle 0x4a46e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a46e5;
    }
L_0x004a465e:
    // 004a465e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004a4663:
    // 004a4663  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a4666  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4668  81f900400000           +cmp ecx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a466e  0f8cc5000000           -jl 0x4a4739
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4739;
    }
    // 004a4674  81f900c00000           +cmp ecx, 0xc000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a467a  0f8db9000000           -jge 0x4a4739
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4739;
    }
    // 004a4680  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a4682  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 004a4684  0f8da5000000           -jge 0x4a472f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a472f;
    }
    // 004a468a  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
L_0x004a468f:
    // 004a468f  83f802                 +cmp eax, 2
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
    // 004a4692  7f13                   -jg 0x4a46a7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a46a7;
    }
    // 004a4694  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a4699  83f903                 +cmp ecx, 3
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
    // 004a469c  7509                   -jne 0x4a46a7
    if (!cpu.flags.zf)
    {
        goto L_0x004a46a7;
    }
    // 004a469e  39d0                   +cmp eax, edx
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
L_0x004a46a0:
    // 004a46a0  7505                   -jne 0x4a46a7
    if (!cpu.flags.zf)
    {
        goto L_0x004a46a7;
    }
    // 004a46a2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a46a7:
    // 004a46a7  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004a46ac  0f8cb7000000           -jl 0x4a4769
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4769;
    }
L_0x004a46b2:
    // 004a46b2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a46b4  0f8cbb000000           -jl 0x4a4775
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4775;
    }
L_0x004a46ba:
    // 004a46ba  83fa01                 +cmp edx, 1
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
    // 004a46bd  0f84be000000           -je 0x4a4781
    if (cpu.flags.zf)
    {
        goto L_0x004a4781;
    }
    // 004a46c3  83fa02                 +cmp edx, 2
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
    // 004a46c6  0f84c5000000           -je 0x4a4791
    if (cpu.flags.zf)
    {
        goto L_0x004a4791;
    }
    // 004a46cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a46cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a46d5:
    // 004a46d5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a46d7  0f8d65ffffff           -jge 0x4a4642
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4642;
    }
    // 004a46dd  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a46df  0f8e79ffffff           -jle 0x4a465e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a465e;
    }
L_0x004a46e5:
    // 004a46e5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a46ea  e974ffffff             -jmp 0x4a4663
    goto L_0x004a4663;
L_0x004a46ef:
    // 004a46ef  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a46f3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a46f5  7e16                   -jle 0x4a470d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a470d;
    }
    // 004a46f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a46f9:
    // 004a46f9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a46fb  7e16                   -jle 0x4a4713
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4713;
    }
    // 004a46fd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a46ff  39d0                   +cmp eax, edx
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
    // 004a4701  7e22                   -jle 0x4a4725
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4725;
    }
    // 004a4703  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a4708  e956ffffff             -jmp 0x4a4663
    goto L_0x004a4663;
L_0x004a470d:
    // 004a470d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a470f  f7d8                   +neg eax
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
    // 004a4711  ebe6                   -jmp 0x4a46f9
    goto L_0x004a46f9;
L_0x004a4713:
    // 004a4713  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a4715  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a4717  39d0                   +cmp eax, edx
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
    // 004a4719  7e0a                   -jle 0x4a4725
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4725;
    }
    // 004a471b  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a4720  e93effffff             -jmp 0x4a4663
    goto L_0x004a4663;
L_0x004a4725:
    // 004a4725  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a472a  e934ffffff             -jmp 0x4a4663
    goto L_0x004a4663;
L_0x004a472f:
    // 004a472f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004a4734  e956ffffff             -jmp 0x4a468f
    goto L_0x004a468f;
L_0x004a4739:
    // 004a4739  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a473b  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 004a473d  7d23                   -jge 0x4a4762
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4762;
    }
    // 004a473f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x004a4744:
    // 004a4744  83f803                 +cmp eax, 3
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
    // 004a4747  0f8c5affffff           -jl 0x4a46a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a46a7;
    }
    // 004a474d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a4752  39d1                   +cmp ecx, edx
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
    // 004a4754  0f854dffffff           -jne 0x4a46a7
    if (!cpu.flags.zf)
    {
        goto L_0x004a46a7;
    }
    // 004a475a  83f803                 +cmp eax, 3
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
    // 004a475d  e93effffff             -jmp 0x4a46a0
    goto L_0x004a46a0;
L_0x004a4762:
    // 004a4762  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a4767  ebdb                   -jmp 0x4a4744
    goto L_0x004a4744;
L_0x004a4769:
    // 004a4769  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a476b  6bc1ff                 +imul eax, ecx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004a476e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4770  e93dffffff             -jmp 0x4a46b2
    goto L_0x004a46b2;
L_0x004a4775:
    // 004a4775  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4777  6bc3ff                 +imul eax, ebx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004a477a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a477c  e939ffffff             -jmp 0x4a46ba
    goto L_0x004a46ba;
L_0x004a4781:
    // 004a4781  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 004a4783  6bc5ff                 -imul eax, ebp, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a4786  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4788  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a478b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a478c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a478d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a478e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a4791:
    // 004a4791  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4793  6bc7ff                 -imul eax, edi, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004a4796  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a4798  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a479b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a479c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a479d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a479e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a47b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a47b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a47b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a47b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a47b3  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004a47ba  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a47bc  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004a47bf  81c1f09b5900           -add ecx, 0x599bf0
    (cpu.ecx) += x86::reg32(x86::sreg32(5872624 /*0x599bf0*/));
    // 004a47c5  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a47c8  8b512d                 -mov edx, dword ptr [ecx + 0x2d]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(45) /* 0x2d */);
    // 004a47cb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a47ce  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a47d1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a47d4  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a47d7  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a47da  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a47dd  8b154aa25900           -mov edx, dword ptr [0x59a24a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5874250) /* 0x59a24a */);
    // 004a47e3  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a47e6  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a47e9  bb7f411f00             -mov ebx, 0x1f417f
    cpu.ebx = 2048383 /*0x1f417f*/;
    // 004a47ee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a47f0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a47f3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a47f5  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004a47f8  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 004a47fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a47fd  750b                   -jne 0x4a480a
    if (!cpu.flags.zf)
    {
        goto L_0x004a480a;
    }
    // 004a47ff  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004a4802  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4804  7533                   -jne 0x4a4839
    if (!cpu.flags.zf)
    {
        goto L_0x004a4839;
    }
    // 004a4806  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4807  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4808  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4809  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a480a:
    // 004a480a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a480c  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004a480f  8a513e                 -mov dl, byte ptr [ecx + 0x3e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 004a4812  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
    // 004a4816  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a4819  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a481c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a481f  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 004a4824  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4826  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a4829  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a482b  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 004a482e  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004a4831  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4833  7504                   -jne 0x4a4839
    if (!cpu.flags.zf)
    {
        goto L_0x004a4839;
    }
    // 004a4835  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4836  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4837  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4838  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4839:
    // 004a4839  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a483c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a483e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a4841  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a4844  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 004a4847  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4848  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4849  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a484a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a484c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a484c  a300c94d00             -mov dword ptr [0x4dc900], eax
    app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */) = cpu.eax;
    // 004a4851  8915fcc84d00           -mov dword ptr [0x4dc8fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */) = cpu.edx;
    // 004a4857  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4858(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4858  a3f8c84d00             -mov dword ptr [0x4dc8f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */) = cpu.eax;
    // 004a485d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a485e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a485e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a485f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4860  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4861  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4865  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4869  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a486d  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4873  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4879  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a487f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4881  803d78904d0008         +cmp byte ptr [0x4d9078], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4888  7f61                   -jg 0x4a48eb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a48eb;
    }
    // 004a488a  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a488d  783d                   -js 0x4a48cc
    if (cpu.flags.sf)
    {
        goto L_0x004a48cc;
    }
L_0x004a488f:
    // 004a488f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4891  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4894  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4897  3cff                   +cmp al, 0xff
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
    // 004a4899  7402                   -je 0x4a489d
    if (cpu.flags.zf)
    {
        goto L_0x004a489d;
    }
    // 004a489b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a489d:
    // 004a489d  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a48a0  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a48a3  3cff                   +cmp al, 0xff
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
    // 004a48a5  7403                   -je 0x4a48aa
    if (cpu.flags.zf)
    {
        goto L_0x004a48aa;
    }
    // 004a48a7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x004a48aa:
    // 004a48aa  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a48ad  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a48b0  3cff                   +cmp al, 0xff
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
    // 004a48b2  7403                   -je 0x4a48b7
    if (cpu.flags.zf)
    {
        goto L_0x004a48b7;
    }
    // 004a48b4  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x004a48b7:
    // 004a48b7  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a48ba  3cff                   +cmp al, 0xff
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
    // 004a48bc  7403                   -je 0x4a48c1
    if (cpu.flags.zf)
    {
        goto L_0x004a48c1;
    }
    // 004a48be  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x004a48c1:
    // 004a48c1  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a48c4  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a48c7  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a48ca  79c3                   -jns 0x4a488f
    if (!cpu.flags.sf)
    {
        goto L_0x004a488f;
    }
L_0x004a48cc:
    // 004a48cc  83c103                 +add ecx, 3
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
    // 004a48cf  7816                   -js 0x4a48e7
    if (cpu.flags.sf)
    {
        goto L_0x004a48e7;
    }
L_0x004a48d1:
    // 004a48d1  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a48d3  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a48d6  3cff                   +cmp al, 0xff
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
    // 004a48d8  7402                   -je 0x4a48dc
    if (cpu.flags.zf)
    {
        goto L_0x004a48dc;
    }
    // 004a48da  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a48dc:
    // 004a48dc  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a48df  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a48e2  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a48e5  79ea                   -jns 0x4a48d1
    if (!cpu.flags.sf)
    {
        goto L_0x004a48d1;
    }
L_0x004a48e7:
    // 004a48e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a48eb:
    // 004a48eb  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a48ed  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a48f4  7f21                   -jg 0x4a4917
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4917;
    }
    // 004a48f6  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a48f9  78ec                   -js 0x4a48e7
    if (cpu.flags.sf)
    {
        goto L_0x004a48e7;
    }
L_0x004a48fb:
    // 004a48fb  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a48ff  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 004a4902  7403                   -je 0x4a4907
    if (cpu.flags.zf)
    {
        goto L_0x004a4907;
    }
    // 004a4904  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
L_0x004a4907:
    // 004a4907  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a490a  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a490d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4910  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4913  79e6                   -jns 0x4a48fb
    if (!cpu.flags.sf)
    {
        goto L_0x004a48fb;
    }
    // 004a4915  ebd0                   -jmp 0x4a48e7
    goto L_0x004a48e7;
L_0x004a4917:
    // 004a4917  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a491a  78cb                   -js 0x4a48e7
    if (cpu.flags.sf)
    {
        goto L_0x004a48e7;
    }
L_0x004a491c:
    // 004a491c  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a491f  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4921  7402                   -je 0x4a4925
    if (cpu.flags.zf)
    {
        goto L_0x004a4925;
    }
    // 004a4923  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004a4925:
    // 004a4925  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4928  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a492b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a492e  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a4931  79e9                   -jns 0x4a491c
    if (!cpu.flags.sf)
    {
        goto L_0x004a491c;
    }
    // 004a4933  ebb2                   -jmp 0x4a48e7
    goto L_0x004a48e7;
}

/* align: skip  */
void Application::sub_4a4935(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4935  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4936  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4937  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4938  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a493c  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4940  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4944  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a494a  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4950  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4956  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4958  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a495b  7855                   -js 0x4a49b2
    if (cpu.flags.sf)
    {
        goto L_0x004a49b2;
    }
L_0x004a495d:
    // 004a495d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a495f  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4962  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4965  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a496b  3cff                   +cmp al, 0xff
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
    // 004a496d  7402                   -je 0x4a4971
    if (cpu.flags.zf)
    {
        goto L_0x004a4971;
    }
    // 004a496f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a4971:
    // 004a4971  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4974  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4977  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a497d  3cff                   +cmp al, 0xff
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
    // 004a497f  7403                   -je 0x4a4984
    if (cpu.flags.zf)
    {
        goto L_0x004a4984;
    }
    // 004a4981  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x004a4984:
    // 004a4984  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4987  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a498a  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a4990  3cff                   +cmp al, 0xff
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
    // 004a4992  7403                   -je 0x4a4997
    if (cpu.flags.zf)
    {
        goto L_0x004a4997;
    }
    // 004a4994  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x004a4997:
    // 004a4997  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a499a  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a49a0  3cff                   +cmp al, 0xff
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
    // 004a49a2  7403                   -je 0x4a49a7
    if (cpu.flags.zf)
    {
        goto L_0x004a49a7;
    }
    // 004a49a4  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x004a49a7:
    // 004a49a7  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a49aa  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a49ad  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a49b0  79ab                   -jns 0x4a495d
    if (!cpu.flags.sf)
    {
        goto L_0x004a495d;
    }
L_0x004a49b2:
    // 004a49b2  83c103                 +add ecx, 3
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
    // 004a49b5  781c                   -js 0x4a49d3
    if (cpu.flags.sf)
    {
        goto L_0x004a49d3;
    }
L_0x004a49b7:
    // 004a49b7  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a49b9  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a49bc  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a49c2  3cff                   +cmp al, 0xff
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
    // 004a49c4  7402                   -je 0x4a49c8
    if (cpu.flags.zf)
    {
        goto L_0x004a49c8;
    }
    // 004a49c6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a49c8:
    // 004a49c8  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a49cb  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a49ce  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a49d1  79e4                   -jns 0x4a49b7
    if (!cpu.flags.sf)
    {
        goto L_0x004a49b7;
    }
L_0x004a49d3:
    // 004a49d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a49d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a49d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a49d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a49d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a49d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a49d8  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a49da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a49db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a49dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a49dd  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a49e0  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a49e3  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a49e6  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a49ec  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a49f2  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a49f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a49fa:
    // 004a49fa  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a49fc  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a49ff  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a4a05  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4a08  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a4a0a  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4a0d  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4a10  75e8                   -jne 0x4a49fa
    if (!cpu.flags.zf)
    {
        goto L_0x004a49fa;
    }
    // 004a4a12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4a17(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4a17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4a18  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a4a1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4a1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4a1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4a1d  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a4a20  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a4a23  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a4a26  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4a2c  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4a32  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4a38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a4a3a:
    // 004a4a3a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4a3c  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4a3f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4a42  3cfe                   +cmp al, 0xfe
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
    // 004a4a44  720a                   -jb 0x4a4a50
    if (cpu.flags.cf)
    {
        goto L_0x004a4a50;
    }
    // 004a4a46  750a                   -jne 0x4a4a52
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a52;
    }
    // 004a4a48  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a4a4a  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a4a50:
    // 004a4a50  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a4a52:
    // 004a4a52  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4a55  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4a58  75e0                   -jne 0x4a4a3a
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a3a;
    }
    // 004a4a5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4a5f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4a5f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4a60  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a4a62  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4a63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4a64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4a65  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a4a68  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a4a6b  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a4a6e  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4a74  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4a7a  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4a80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a4a82:
    // 004a4a82  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4a84  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4a87  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004a4a8d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4a90  3cfe                   +cmp al, 0xfe
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
    // 004a4a92  720a                   -jb 0x4a4a9e
    if (cpu.flags.cf)
    {
        goto L_0x004a4a9e;
    }
    // 004a4a94  750a                   -jne 0x4a4aa0
    if (!cpu.flags.zf)
    {
        goto L_0x004a4aa0;
    }
    // 004a4a96  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a4a98  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a4a9e:
    // 004a4a9e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004a4aa0:
    // 004a4aa0  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4aa3  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4aa6  75da                   -jne 0x4a4a82
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a82;
    }
    // 004a4aa8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4aad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4aad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4aae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4aaf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4ab0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4ab1  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4ab5  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4ab9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a4abd  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4ac3  032d7c904d00           -add ebp, dword ptr [0x4d907c]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4ac9  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4acf  8b3df8c84d00           -mov edi, dword ptr [0x4dc8f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004a4ad5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4ad7  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4ada  782e                   -js 0x4a4b0a
    if (cpu.flags.sf)
    {
        goto L_0x004a4b0a;
    }
L_0x004a4adc:
    // 004a4adc  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4ade  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4ae1  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004a4ae4  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a4ae7  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 004a4aea  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004a4aed  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4af0  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4af3  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004a4af6  8a4501                 -mov al, byte ptr [ebp + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004a4af9  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 004a4afc  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a4aff  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4b02  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4b05  8d6d02                 -lea ebp, [ebp + 2]
    cpu.ebp = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004a4b08  79d2                   -jns 0x4a4adc
    if (!cpu.flags.sf)
    {
        goto L_0x004a4adc;
    }
L_0x004a4b0a:
    // 004a4b0a  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4b0d  7811                   -js 0x4a4b20
    if (cpu.flags.sf)
    {
        goto L_0x004a4b20;
    }
    // 004a4b0f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4b11  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004a4b14  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004a4b17  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a4b1a  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 004a4b1d  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
L_0x004a4b20:
    // 004a4b20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4b25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4b25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4b26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4b27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4b28  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4b29  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4b2d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4b31  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a4b35  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4b3b  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4b41  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4b47  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a4b4a  803d78904d0008         +cmp byte ptr [0x4d9078], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4b51  0f8f26010000           -jg 0x4a4c7d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4c7d;
    }
    // 004a4b57  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4b5a  0f8c99000000           -jl 0x4a4bf9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4bf9;
    }
    // 004a4b60  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a4b66  0f85e2000000           -jne 0x4a4c4e
    if (!cpu.flags.zf)
    {
        goto L_0x004a4c4e;
    }
L_0x004a4b6c:
    // 004a4b6c  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4b6f  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4b72  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4b75  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4b79  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4b7c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4b7e  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4b81  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a4b84  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4b88  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a4b8b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4b8d  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4b90  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a4b93  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4b97  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4b9a  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a4b9d  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4ba0  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004a4ba3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4ba7  8b6a28                 -mov ebp, dword ptr [edx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 004a4baa  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a4bad  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4bb0  8b5a24                 -mov ebx, dword ptr [edx + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004a4bb3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4bb7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4bba  8b6a20                 -mov ebp, dword ptr [edx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a4bbd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4bc0  8b5a3c                 -mov ebx, dword ptr [edx + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004a4bc3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4bc7  8b6a38                 -mov ebp, dword ptr [edx + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 004a4bca  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a4bcd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4bd0  8b5a34                 -mov ebx, dword ptr [edx + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 004a4bd3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4bd7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4bda  8b6a30                 -mov ebp, dword ptr [edx + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004a4bdd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4be0  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 004a4be3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4be7  8d5240                 -lea edx, [edx + 0x40]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004a4bea  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a4bed  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4bf0  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a4bf3  0f8973ffffff           -jns 0x4a4b6c
    if (!cpu.flags.sf)
    {
        goto L_0x004a4b6c;
    }
L_0x004a4bf9:
    // 004a4bf9  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4bfc  7831                   -js 0x4a4c2f
    if (cpu.flags.sf)
    {
        goto L_0x004a4c2f;
    }
    // 004a4bfe  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a4c04  7529                   -jne 0x4a4c2f
    if (!cpu.flags.zf)
    {
        goto L_0x004a4c2f;
    }
L_0x004a4c06:
    // 004a4c06  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4c09  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4c0c  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c0f  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4c13  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4c16  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4c18  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4c1b  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a4c1e  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a4c22  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a4c25  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4c27  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4c2a  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a4c2d  79d7                   -jns 0x4a4c06
    if (!cpu.flags.sf)
    {
        goto L_0x004a4c06;
    }
L_0x004a4c2f:
    // 004a4c2f  83c103                 +add ecx, 3
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
    // 004a4c32  7815                   -js 0x4a4c49
    if (cpu.flags.sf)
    {
        goto L_0x004a4c49;
    }
    // 004a4c34  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004a4c36:
    // 004a4c36  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4c39  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c3c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a4c3e  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4c41  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c44  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4c47  79ed                   -jns 0x4a4c36
    if (!cpu.flags.sf)
    {
        goto L_0x004a4c36;
    }
L_0x004a4c49:
    // 004a4c49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4c4e:
    // 004a4c4e  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4c51  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004a4c53:
    // 004a4c53  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4c56  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c59  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a4c5b  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4c5e  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c61  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a4c67  8d49ff                 -lea ecx, [ecx - 1]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004a4c6a  75e7                   -jne 0x4a4c53
    if (!cpu.flags.zf)
    {
        goto L_0x004a4c53;
    }
    // 004a4c6c  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a4c6f  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4c72  0f89f4feffff           -jns 0x4a4b6c
    if (!cpu.flags.sf)
    {
        goto L_0x004a4b6c;
    }
    // 004a4c78  e97cffffff             -jmp 0x4a4bf9
    goto L_0x004a4bf9;
L_0x004a4c7d:
    // 004a4c7d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4c7f  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4c86  7f1c                   -jg 0x4a4ca4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4ca4;
    }
    // 004a4c88  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4c8b  78bc                   -js 0x4a4c49
    if (cpu.flags.sf)
    {
        goto L_0x004a4c49;
    }
L_0x004a4c8d:
    // 004a4c8d  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4c91  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c94  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a4c97  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4c9a  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4c9d  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4ca0  79eb                   -jns 0x4a4c8d
    if (!cpu.flags.sf)
    {
        goto L_0x004a4c8d;
    }
    // 004a4ca2  eba5                   -jmp 0x4a4c49
    goto L_0x004a4c49;
L_0x004a4ca4:
    // 004a4ca4  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4ca7  78a0                   -js 0x4a4c49
    if (cpu.flags.sf)
    {
        goto L_0x004a4c49;
    }
L_0x004a4ca9:
    // 004a4ca9  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a4cac  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4caf  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4cb1  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4cb4  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4cb7  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a4cba  79ed                   -jns 0x4a4ca9
    if (!cpu.flags.sf)
    {
        goto L_0x004a4ca9;
    }
    // 004a4cbc  eb8b                   -jmp 0x4a4c49
    goto L_0x004a4c49;
}

/* align: skip  */
void Application::sub_4a4cbe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4cbe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4cbf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4cc0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4cc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4cc2  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4cc6  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4cca  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a4cce  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4cd4  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4cda  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4ce0  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4ce2  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4ce5  7820                   -js 0x4a4d07
    if (cpu.flags.sf)
    {
        goto L_0x004a4d07;
    }
    // 004a4ce7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4ce9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a4ceb:
    // 004a4ceb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4cee  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4cf1  668b0c451ccb5600       -mov cx, word ptr [eax*2 + 0x56cb1c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.eax * 2);
    // 004a4cf9  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4cfc  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004a4cff  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4d02  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4d05  79e4                   -jns 0x4a4ceb
    if (!cpu.flags.sf)
    {
        goto L_0x004a4ceb;
    }
L_0x004a4d07:
    // 004a4d07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4d0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4d0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4d0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4d0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4d0f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4d10  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4d14  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4d18  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a4d1c  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4d22  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4d28  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4d2e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4d30  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4d33  7822                   -js 0x4a4d57
    if (cpu.flags.sf)
    {
        goto L_0x004a4d57;
    }
    // 004a4d35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a4d37:
    // 004a4d37  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4d3a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4d3d  3cff                   +cmp al, 0xff
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
    // 004a4d3f  740b                   -je 0x4a4d4c
    if (cpu.flags.zf)
    {
        goto L_0x004a4d4c;
    }
    // 004a4d41  668b0c451ccb5600       -mov cx, word ptr [eax*2 + 0x56cb1c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.eax * 2);
    // 004a4d49  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
L_0x004a4d4c:
    // 004a4d4c  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4d4f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4d52  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4d55  79e0                   -jns 0x4a4d37
    if (!cpu.flags.sf)
    {
        goto L_0x004a4d37;
    }
L_0x004a4d57:
    // 004a4d57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4d5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4d5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4d5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4d5f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4d60  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4d64  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4d68  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a4d6c  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4d72  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4d78  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4d7e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4d80  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4d83  7822                   -js 0x4a4da7
    if (cpu.flags.sf)
    {
        goto L_0x004a4da7;
    }
    // 004a4d85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a4d87:
    // 004a4d87  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4d8a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4d8d  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4d8f  731b                   -jae 0x4a4dac
    if (!cpu.flags.cf)
    {
        goto L_0x004a4dac;
    }
    // 004a4d91  668b0c451ccb5600       -mov cx, word ptr [eax*2 + 0x56cb1c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5688092) /* 0x56cb1c */ + cpu.eax * 2);
    // 004a4d99  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004a4d9c  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4d9f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4da2  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4da5  79e0                   -jns 0x4a4d87
    if (!cpu.flags.sf)
    {
        goto L_0x004a4d87;
    }
L_0x004a4da7:
    // 004a4da7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4da8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4da9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4daa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4dab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4dac:
    // 004a4dac  3cfe                   +cmp al, 0xfe
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
    // 004a4dae  7435                   -je 0x4a4de5
    if (cpu.flags.zf)
    {
        goto L_0x004a4de5;
    }
    // 004a4db0  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4db2  740d                   -je 0x4a4dc1
    if (cpu.flags.zf)
    {
        goto L_0x004a4dc1;
    }
    // 004a4db4  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4db7  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4dba  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4dbd  79c8                   -jns 0x4a4d87
    if (!cpu.flags.sf)
    {
        goto L_0x004a4d87;
    }
    // 004a4dbf  ebe6                   -jmp 0x4a4da7
    goto L_0x004a4da7;
L_0x004a4dc1:
    // 004a4dc1  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 004a4dc4  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 004a4dc7  66c1e902               -shr cx, 2
    cpu.cx >>= 2 /*0x2*/ % 32;
    // 004a4dcb  6681e1e739             -and cx, 0x39e7
    cpu.cx &= x86::reg16(x86::sreg16(14823 /*0x39e7*/));
    // 004a4dd0  6629c8                 -sub ax, cx
    (cpu.ax) -= x86::reg16(x86::sreg16(cpu.cx));
    // 004a4dd3  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a4dd6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4dd8  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4ddb  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4dde  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4de1  79a4                   -jns 0x4a4d87
    if (!cpu.flags.sf)
    {
        goto L_0x004a4d87;
    }
    // 004a4de3  ebc2                   -jmp 0x4a4da7
    goto L_0x004a4da7;
L_0x004a4de5:
    // 004a4de5  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 004a4de8  66d1e9                 -shr cx, 1
    cpu.cx >>= 1 /*0x1*/ % 32;
    // 004a4deb  6681e1ef7b             -and cx, 0x7bef
    cpu.cx &= x86::reg16(x86::sreg16(31727 /*0x7bef*/));
    // 004a4df0  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004a4df3  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4df6  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4df9  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4dfc  7989                   -jns 0x4a4d87
    if (!cpu.flags.sf)
    {
        goto L_0x004a4d87;
    }
    // 004a4dfe  eba7                   -jmp 0x4a4da7
    goto L_0x004a4da7;
}

/* align: skip  */
void Application::sub_4a4e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4e01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4e02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4e03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4e04  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4e08  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4e0c  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a4e12  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a4e18  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a4e1e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4e20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4e22  803d78904d0008         +cmp byte ptr [0x4d9078], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4e29  0f8f32010000           -jg 0x4a4f61
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4f61;
    }
    // 004a4e2f  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a4e35  7421                   -je 0x4a4e58
    if (cpu.flags.zf)
    {
        goto L_0x004a4e58;
    }
L_0x004a4e37:
    // 004a4e37  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4e3a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4e3d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a4e3f  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4e44  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4e47  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4e4a  0f880c010000           -js 0x4a4f5c
    if (cpu.flags.sf)
    {
        goto L_0x004a4f5c;
    }
    // 004a4e50  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a4e56  75df                   -jne 0x4a4e37
    if (!cpu.flags.zf)
    {
        goto L_0x004a4e37;
    }
L_0x004a4e58:
    // 004a4e58  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4e5d  0f8c8d000000           -jl 0x4a4ef0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4ef0;
    }
L_0x004a4e63:
    // 004a4e63  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4e66  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4e69  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4e6c  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4e6f  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4e72  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4e75  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004a4e79  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4e7c  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4e7f  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a4e82  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4e85  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a4e89  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4e8c  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4e8f  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a4e92  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4e95  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 004a4e99  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4e9c  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4e9f  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a4ea2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4ea5  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a4ea9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4eac  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4eaf  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a4eb2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4eb5  0f73f028               -psllq mm0, 0x28
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 40 /*0x28*/) };
    // 004a4eb9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4ebc  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4ebf  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a4ec2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4ec5  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a4ec9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4ecc  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4ecf  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a4ed2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4ed5  0f73f038               -psllq mm0, 0x38
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 56 /*0x38*/) };
    // 004a4ed9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4edc  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 004a4edf  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4ee4  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a4ee7  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a4eea  0f8973ffffff           -jns 0x4a4e63
    if (!cpu.flags.sf)
    {
        goto L_0x004a4e63;
    }
L_0x004a4ef0:
    // 004a4ef0  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4ef5  7849                   -js 0x4a4f40
    if (cpu.flags.sf)
    {
        goto L_0x004a4f40;
    }
L_0x004a4ef7:
    // 004a4ef7  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4efa  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4efd  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4f00  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4f03  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4f06  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4f09  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004a4f0d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4f10  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4f13  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a4f16  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4f19  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a4f1d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4f20  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4f23  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a4f26  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4f29  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 004a4f2d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4f30  0f7e0f                 -movd dword ptr [edi], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm1);
    // 004a4f33  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4f38  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a4f3b  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a4f3e  79b7                   -jns 0x4a4ef7
    if (!cpu.flags.sf)
    {
        goto L_0x004a4ef7;
    }
L_0x004a4f40:
    // 004a4f40  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4f45  7815                   -js 0x4a4f5c
    if (cpu.flags.sf)
    {
        goto L_0x004a4f5c;
    }
L_0x004a4f47:
    // 004a4f47  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a4f4a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4f4d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a4f4f  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4f54  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4f57  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4f5a  79eb                   -jns 0x4a4f47
    if (!cpu.flags.sf)
    {
        goto L_0x004a4f47;
    }
L_0x004a4f5c:
    // 004a4f5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4f61:
    // 004a4f61  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4f68  0f8f47010000           -jg 0x4a50b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a50b5;
    }
    // 004a4f6e  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a4f74  741f                   -je 0x4a4f95
    if (cpu.flags.zf)
    {
        goto L_0x004a4f95;
    }
L_0x004a4f76:
    // 004a4f76  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4f7a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4f7d  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a4f80  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4f85  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4f88  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4f8b  78cf                   -js 0x4a4f5c
    if (cpu.flags.sf)
    {
        goto L_0x004a4f5c;
    }
    // 004a4f8d  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004a4f93  75e1                   -jne 0x4a4f76
    if (!cpu.flags.zf)
    {
        goto L_0x004a4f76;
    }
L_0x004a4f95:
    // 004a4f95  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4f9a  0f8c92000000           -jl 0x4a5032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5032;
    }
L_0x004a4fa0:
    // 004a4fa0  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fa4  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4fa7  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4faa  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fae  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4fb1  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4fb4  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a4fb8  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4fbb  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fbf  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a4fc2  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4fc5  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a4fc9  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4fcc  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fd0  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a4fd3  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4fd6  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a4fda  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4fdd  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 004a4fe0  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fe4  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a4fe7  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4fea  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fee  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a4ff1  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a4ff4  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a4ff8  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a4ffb  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a4fff  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a5002  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a5005  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a5009  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a500c  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a5010  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a5013  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a5016  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a501a  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a501d  0f7f4f08               -movq qword ptr [edi + 8], mm1
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004a5021  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5026  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a5029  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a502c  0f896effffff           -jns 0x4a4fa0
    if (!cpu.flags.sf)
    {
        goto L_0x004a4fa0;
    }
L_0x004a5032:
    // 004a5032  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5037  7855                   -js 0x4a508e
    if (cpu.flags.sf)
    {
        goto L_0x004a508e;
    }
    // 004a5039  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a503f  754d                   -jne 0x4a508e
    if (!cpu.flags.zf)
    {
        goto L_0x004a508e;
    }
L_0x004a5041:
    // 004a5041  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a5045  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5048  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a504b  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a504f  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5052  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a5055  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004a5059  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a505c  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a5060  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a5063  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a5066  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004a506a  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a506d  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a5071  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5074  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a5077  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004a507b  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a507e  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 004a5081  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5086  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5089  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a508c  79b3                   -jns 0x4a5041
    if (!cpu.flags.sf)
    {
        goto L_0x004a5041;
    }
L_0x004a508e:
    // 004a508e  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5093  0f88c3feffff           -js 0x4a4f5c
    if (cpu.flags.sf)
    {
        goto L_0x004a4f5c;
    }
L_0x004a5099:
    // 004a5099  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a509d  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a50a0  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a50a3  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a50a8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a50ab  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a50ae  79e9                   -jns 0x4a5099
    if (!cpu.flags.sf)
    {
        goto L_0x004a5099;
    }
    // 004a50b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a50b5:
    // 004a50b5  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a50ba  0f889cfeffff           -js 0x4a4f5c
    if (cpu.flags.sf)
    {
        goto L_0x004a4f5c;
    }
L_0x004a50c0:
    // 004a50c0  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a50c3  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a50c6  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a50c8  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a50cd  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a50d0  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a50d3  79eb                   -jns 0x4a50c0
    if (!cpu.flags.sf)
    {
        goto L_0x004a50c0;
    }
    // 004a50d5  e982feffff             -jmp 0x4a4f5c
    goto L_0x004a4f5c;
}

/* align: skip  */
void Application::sub_4a50da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a50da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a50db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a50dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a50dd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a50de  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a50e2  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a50e6  8b15fcc84d00           -mov edx, dword ptr [0x4dc8fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5097724) /* 0x4dc8fc */);
    // 004a50ec  033500c94d00           -add esi, dword ptr [0x4dc900]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097728) /* 0x4dc900 */)));
    // 004a50f2  033d7c904d00           -add edi, dword ptr [0x4d907c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004a50f8  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a50fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a50fc  803d78904d0008         +cmp byte ptr [0x4d9078], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5103  0f8ffd000000           -jg 0x4a5206
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5206;
    }
    // 004a5109  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a510f  7421                   -je 0x4a5132
    if (cpu.flags.zf)
    {
        goto L_0x004a5132;
    }
L_0x004a5111:
    // 004a5111  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a5114  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5117  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a5119  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a511e  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5121  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a5124  0f88d7000000           -js 0x4a5201
    if (cpu.flags.sf)
    {
        goto L_0x004a5201;
    }
    // 004a512a  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004a5130  75df                   -jne 0x4a5111
    if (!cpu.flags.zf)
    {
        goto L_0x004a5111;
    }
L_0x004a5132:
    // 004a5132  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a5135  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a513a  7c67                   -jl 0x4a51a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a51a3;
    }
L_0x004a513c:
    // 004a513c  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a513f  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a5142  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5145  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5147  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a514a  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a514e  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5150  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5152  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a5155  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a5158  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a515b  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a515d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a5160  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a5164  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5166  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a5169  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a516c  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a516f  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004a5171  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5173  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a5176  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a517a  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a517d  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a517f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a5182  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a5185  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004a5188  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a518a  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a518d  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a5191  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5193  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5198  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a519b  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a519e  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a51a1  7999                   -jns 0x4a513c
    if (!cpu.flags.sf)
    {
        goto L_0x004a513c;
    }
L_0x004a51a3:
    // 004a51a3  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a51a8  7839                   -js 0x4a51e3
    if (cpu.flags.sf)
    {
        goto L_0x004a51e3;
    }
L_0x004a51aa:
    // 004a51aa  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a51ad  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a51b0  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a51b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a51b5  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a51b8  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a51bc  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a51be  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a51c0  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a51c3  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a51c6  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a51c9  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a51cb  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a51ce  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004a51d2  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a51d4  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004a51d6  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a51db  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a51de  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a51e1  79c7                   -jns 0x4a51aa
    if (!cpu.flags.sf)
    {
        goto L_0x004a51aa;
    }
L_0x004a51e3:
    // 004a51e3  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a51e8  7817                   -js 0x4a5201
    if (cpu.flags.sf)
    {
        goto L_0x004a5201;
    }
    // 004a51ea  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004a51ec:
    // 004a51ec  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004a51ef  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a51f2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a51f4  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a51f9  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a51fc  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a51ff  79eb                   -jns 0x4a51ec
    if (!cpu.flags.sf)
    {
        goto L_0x004a51ec;
    }
L_0x004a5201:
    // 004a5201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5205  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5206:
    // 004a5206  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5208  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a520a  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5211  7f20                   -jg 0x4a5233
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5233;
    }
    // 004a5213  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5218  78e7                   -js 0x4a5201
    if (cpu.flags.sf)
    {
        goto L_0x004a5201;
    }
L_0x004a521a:
    // 004a521a  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004a521e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5221  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a5224  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5229  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a522c  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a522f  79e9                   -jns 0x4a521a
    if (!cpu.flags.sf)
    {
        goto L_0x004a521a;
    }
    // 004a5231  ebce                   -jmp 0x4a5201
    goto L_0x004a5201;
L_0x004a5233:
    // 004a5233  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5238  78c7                   -js 0x4a5201
    if (cpu.flags.sf)
    {
        goto L_0x004a5201;
    }
L_0x004a523a:
    // 004a523a  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a523d  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5240  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a5242  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5247  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a524a  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a524d  79eb                   -jns 0x4a523a
    if (!cpu.flags.sf)
    {
        goto L_0x004a523a;
    }
    // 004a524f  ebb0                   -jmp 0x4a5201
    goto L_0x004a5201;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a5260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5260  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5261  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5262  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5264  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a5266  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a526b  83f87b                 +cmp eax, 0x7b
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
    // 004a526e  7509                   -jne 0x4a5279
    if (!cpu.flags.zf)
    {
        goto L_0x004a5279;
    }
    // 004a5270  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a5273  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a5276  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5277  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5278  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5279:
    // 004a5279  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a527b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a527d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004a5280  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 004a5286  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5288  83f80f                 +cmp eax, 0xf
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
    // 004a528b  7505                   -jne 0x4a5292
    if (!cpu.flags.zf)
    {
        goto L_0x004a5292;
    }
    // 004a528d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x004a5292:
    // 004a5292  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5293  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a5296  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004a5299  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a529c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a529e  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004a52a3  83f840                 +cmp eax, 0x40
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
    // 004a52a6  750c                   -jne 0x4a52b4
    if (!cpu.flags.zf)
    {
        goto L_0x004a52b4;
    }
    // 004a52a8  8d410f                 -lea eax, [ecx + 0xf]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(15) /* 0xf */);
    // 004a52ab  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004a52ad  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a52b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a52b4:
    // 004a52b4  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004a52b7  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a52b9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a52bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a52c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a52c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a52c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a52c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a52c3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a52c6  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a52ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a52cc  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a52ce  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a52d2  47                     -inc edi
    (cpu.edi)++;
    // 004a52d3  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004a52d5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a52d7  7e5b                   -jle 0x4a5334
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5334;
    }
    // 004a52d9  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a52dc  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 004a52de  745d                   -je 0x4a533d
    if (cpu.flags.zf)
    {
        goto L_0x004a533d;
    }
L_0x004a52e0:
    // 004a52e0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a52e2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a52e5  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a52e8  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a52ec  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a52ee  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a52f1  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a52f4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a52f8  030c24                 -add ecx, dword ptr [esp]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004a52fb  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004a52fd  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5301  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5303  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a5305  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a5308  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a530b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a530d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a5310  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a5312  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a5315  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a5319  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a531c  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a531f  034c2404               -add ecx, dword ptr [esp + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a5323  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a5326  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a532a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a532c  01cb                   +add ebx, ecx
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
    // 004a532e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a532f  75af                   -jne 0x4a52e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a52e0;
    }
    // 004a5331  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a5334:
    // 004a5334  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a5337  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5338  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5339  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a533a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a533d:
    // 004a533d  e86e420000             -call 0x4a95b0
    cpu.esp -= 4;
    sub_4a95b0(app, cpu);
    if (cpu.terminate) return;
    // 004a5342  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a5346:
    // 004a5346  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5348  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a534b  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a534f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a5351  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5354  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5356  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5359  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a535c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a535e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5362  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5364  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5366  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004a5368  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a536b  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a536f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a5371  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a5373  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5376  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5378  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a537b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a537e  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5381  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5383  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a5386  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a538a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a538c  01cb                   +add ebx, ecx
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
    // 004a538e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a538f  75b5                   -jne 0x4a5346
    if (!cpu.flags.zf)
    {
        goto L_0x004a5346;
    }
    // 004a5391  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a5394  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5395  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5396  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5397  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a539a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a539a  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a539d  7c08                   -jl 0x4a53a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a53a7;
    }
    // 004a539f  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a53a2  7f03                   -jg 0x4a53a7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a53a7;
    }
    // 004a53a4  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004a53a7:
    // 004a53a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a53a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a53a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a53a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a53aa  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a53ae  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a53b1  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a53b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a53b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a53b7  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a53bb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a53bc  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a53c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a53c1  e806000000             -call 0x4a53cc
    cpu.esp -= 4;
    sub_4a53cc(app, cpu);
    if (cpu.terminate) return;
    // 004a53c6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a53c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a53cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a53cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a53cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a53ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a53cf  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a53d2  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a53d6  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004a53d8  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a53dc  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a53e0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a53e3  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a53e7  e807000000             -call 0x4a53f3
    cpu.esp -= 4;
    sub_4a53f3(app, cpu);
    if (cpu.terminate) return;
    // 004a53ec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a53ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a53f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a53f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a53f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a53f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a53f6  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a53f9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a53fb  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a53ff  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a5403  e8080b0100             -call 0x4b5f10
    cpu.esp -= 4;
    sub_4b5f10(app, cpu);
    if (cpu.terminate) return;
    // 004a5408  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a540a  7414                   -je 0x4a5420
    if (cpu.flags.zf)
    {
        goto L_0x004a5420;
    }
    // 004a540c  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
L_0x004a5411:
    // 004a5411  e80aceffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a5416  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a541b  e9d5010000             -jmp 0x4a55f5
    goto L_0x004a55f5;
L_0x004a5420:
    // 004a5420  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a5422  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a5426  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a5429  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a542d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a542f  e8200d0100             -call 0x4b6154
    cpu.esp -= 4;
    sub_4b6154(app, cpu);
    if (cpu.terminate) return;
    // 004a5434  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5438  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a543c  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a543e  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a5443  e8380d0100             -call 0x4b6180
    cpu.esp -= 4;
    sub_4b6180(app, cpu);
    if (cpu.terminate) return;
    // 004a5448  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a544a  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004a544f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a5453  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5457  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a545a  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 004a545d  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004a5460  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5465  8b1570cb4d00           -mov edx, dword ptr [0x4dcb70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098352) /* 0x4dcb70 */);
    // 004a546b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a546f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5471  7435                   -je 0x4a54a8
    if (cpu.flags.zf)
    {
        goto L_0x004a54a8;
    }
    // 004a5473  ba60f34c00             -mov edx, 0x4cf360
    cpu.edx = 5043040 /*0x4cf360*/;
    // 004a5478  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a547a  e8244cffff             -call 0x49a0a3
    cpu.esp -= 4;
    sub_49a0a3(app, cpu);
    if (cpu.terminate) return;
    // 004a547f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5481  7525                   -jne 0x4a54a8
    if (!cpu.flags.zf)
    {
        goto L_0x004a54a8;
    }
    // 004a5483  e8760c0100             -call 0x4b60fe
    cpu.esp -= 4;
    sub_4b60fe(app, cpu);
    if (cpu.terminate) return;
    // 004a5488  ff1528cb4d00           -call dword ptr [0x4dcb28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098280) /* 0x4dcb28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a548e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a5490  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5491  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a5493  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 004a5498  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a549a  ff1570cb4d00           -call dword ptr [0x4dcb70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098352) /* 0x4dcb70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a54a0  83c40c                 +add esp, 0xc
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
    // 004a54a3  e9fd000000             -jmp 0x4a55a5
    goto L_0x004a55a5;
L_0x004a54a8:
    // 004a54a8  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a54ac  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004a54af  7462                   -je 0x4a5513
    if (cpu.flags.zf)
    {
        goto L_0x004a5513;
    }
    // 004a54b1  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a54b3  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a54b6  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 004a54b8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a54bb  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a54bf  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004a54c5  a1e4e44d00             -mov eax, dword ptr [0x4de4e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104868) /* 0x4de4e4 */);
    // 004a54ca  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a54ce  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004a54d0  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004a54d2  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a54d6  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 004a54db  740c                   -je 0x4a54e9
    if (cpu.flags.zf)
    {
        goto L_0x004a54e9;
    }
    // 004a54dd  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 004a54e2  7505                   -jne 0x4a54e9
    if (!cpu.flags.zf)
    {
        goto L_0x004a54e9;
    }
    // 004a54e4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004a54e9:
    // 004a54e9  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 004a54ee  7409                   -je 0x4a54f9
    if (cpu.flags.zf)
    {
        goto L_0x004a54f9;
    }
    // 004a54f0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a54f5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a54f7  eb24                   -jmp 0x4a551d
    goto L_0x004a551d;
L_0x004a54f9:
    // 004a54f9  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 004a54fe  740c                   -je 0x4a550c
    if (cpu.flags.zf)
    {
        goto L_0x004a550c;
    }
    // 004a5500  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
L_0x004a5505:
    // 004a5505  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a550a  eb11                   -jmp 0x4a551d
    goto L_0x004a551d;
L_0x004a550c:
    // 004a550c  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 004a5511  eb05                   -jmp 0x4a5518
    goto L_0x004a5518;
L_0x004a5513:
    // 004a5513  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 004a5516  75ed                   -jne 0x4a5505
    if (!cpu.flags.zf)
    {
        goto L_0x004a5505;
    }
L_0x004a5518:
    // 004a5518  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x004a551d:
    // 004a551d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a551f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5520  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5521  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5525  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5526  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a552a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a552b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a552f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5530  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5531  2eff1530444c00         -call dword ptr cs:[0x4c4430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998192) /* 0x4c4430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5538  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a553a  83f8ff                 +cmp eax, -1
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
    // 004a553d  7530                   -jne 0x4a556f
    if (!cpu.flags.zf)
    {
        goto L_0x004a556f;
    }
    // 004a553f  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 004a5544  741a                   -je 0x4a5560
    if (cpu.flags.zf)
    {
        goto L_0x004a5560;
    }
    // 004a5546  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a5548  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5549  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a554a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a554c  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5550  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5551  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a5555  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5556  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5557  2eff1530444c00         -call dword ptr cs:[0x4c4430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998192) /* 0x4c4430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a555e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a5560:
    // 004a5560  83f9ff                 +cmp ecx, -1
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
    // 004a5563  750a                   -jne 0x4a556f
    if (!cpu.flags.zf)
    {
        goto L_0x004a556f;
    }
    // 004a5565  e8b8cbffff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 004a556a  e986000000             -jmp 0x4a55f5
    goto L_0x004a55f5;
L_0x004a556f:
    // 004a556f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5571  ff1528cb4d00           -call dword ptr [0x4dcb28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098280) /* 0x4dcb28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5577  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5579  8b2de8e44d00           -mov ebp, dword ptr [0x4de4e8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5104872) /* 0x4de4e8 */);
    // 004a557f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a5581  39e8                   +cmp eax, ebp
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
    // 004a5583  7212                   -jb 0x4a5597
    if (cpu.flags.cf)
    {
        goto L_0x004a5597;
    }
    // 004a5585  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5586  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a558d  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a5592  e97afeffff             -jmp 0x4a5411
    goto L_0x004a5411;
L_0x004a5597:
    // 004a5597  e8b20c0100             -call 0x4b624e
    cpu.esp -= 4;
    sub_4b624e(app, cpu);
    if (cpu.terminate) return;
    // 004a559c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a559e  7405                   -je 0x4a55a5
    if (cpu.flags.zf)
    {
        goto L_0x004a55a5;
    }
    // 004a55a0  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x004a55a5:
    // 004a55a5  83fe02                 +cmp esi, 2
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
    // 004a55a8  7505                   -jne 0x4a55af
    if (!cpu.flags.zf)
    {
        goto L_0x004a55af;
    }
    // 004a55aa  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a55ad  eb11                   -jmp 0x4a55c0
    goto L_0x004a55c0;
L_0x004a55af:
    // 004a55af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a55b1  7505                   -jne 0x4a55b8
    if (!cpu.flags.zf)
    {
        goto L_0x004a55b8;
    }
    // 004a55b3  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004a55b6  eb08                   -jmp 0x4a55c0
    goto L_0x004a55c0;
L_0x004a55b8:
    // 004a55b8  83fe01                 +cmp esi, 1
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
    // 004a55bb  7503                   -jne 0x4a55c0
    if (!cpu.flags.zf)
    {
        goto L_0x004a55c0;
    }
    // 004a55bd  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004a55c0:
    // 004a55c0  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 004a55c5  7403                   -je 0x4a55ca
    if (cpu.flags.zf)
    {
        goto L_0x004a55ca;
    }
    // 004a55c7  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004a55ca:
    // 004a55ca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a55cc  8a7c241d               -mov bh, byte ptr [esp + 0x1d]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 004a55d0  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004a55d2  f6c703                 +test bh, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 3 /*0x3*/));
    // 004a55d5  7407                   -je 0x4a55de
    if (cpu.flags.zf)
    {
        goto L_0x004a55de;
    }
    // 004a55d7  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004a55da  7410                   -je 0x4a55ec
    if (cpu.flags.zf)
    {
        goto L_0x004a55ec;
    }
    // 004a55dc  eb0c                   -jmp 0x4a55ea
    goto L_0x004a55ea;
L_0x004a55de:
    // 004a55de  813d11cb4d0000020000   +cmp dword ptr [0x4dcb11], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098257) /* 0x4dcb11 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a55e8  7502                   -jne 0x4a55ec
    if (!cpu.flags.zf)
    {
        goto L_0x004a55ec;
    }
L_0x004a55ea:
    // 004a55ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a55ec:
    // 004a55ec  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a55ee  e83a0c0100             -call 0x4b622d
    cpu.esp -= 4;
    sub_4b622d(app, cpu);
    if (cpu.terminate) return;
    // 004a55f3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a55f5:
    // 004a55f5  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a55f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a55f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a55fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a55fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a55fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a55fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a55fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a55fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a55ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5600  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5601  ff1530cb4d00           -call dword ptr [0x4dcb30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098288) /* 0x4dcb30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5607  8b35e8435b00           -mov esi, dword ptr [0x5b43e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */);
    // 004a560d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a560f  7419                   -je 0x4a562a
    if (cpu.flags.zf)
    {
        goto L_0x004a562a;
    }
    // 004a5611  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a5614  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5617  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a5619  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 004a561f  a3e8435b00             -mov dword ptr [0x5b43e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */) = cpu.eax;
    // 004a5624  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 004a5628  eb47                   -jmp 0x4a5671
    goto L_0x004a5671;
L_0x004a562a:
    // 004a562a  b908c94d00             -mov ecx, 0x4dc908
    cpu.ecx = 5097736 /*0x4dc908*/;
    // 004a562f  eb20                   -jmp 0x4a5651
    goto L_0x004a5651;
L_0x004a5631:
    // 004a5631  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 004a5635  7517                   -jne 0x4a564e
    if (!cpu.flags.zf)
    {
        goto L_0x004a564e;
    }
    // 004a5637  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004a563c  e8f2caffff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004a5641  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a5643  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5645  7458                   -je 0x4a569f
    if (cpu.flags.zf)
    {
        goto L_0x004a569f;
    }
    // 004a5647  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 004a564c  eb23                   -jmp 0x4a5671
    goto L_0x004a5671;
L_0x004a564e:
    // 004a564e  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
L_0x004a5651:
    // 004a5651  81f910cb4d00           +cmp ecx, 0x4dcb10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5098256 /*0x4dcb10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5657  72d8                   -jb 0x4a5631
    if (cpu.flags.cf)
    {
        goto L_0x004a5631;
    }
    // 004a5659  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 004a565e  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 004a5663  e8cbcaffff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004a5668  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a566a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a566c  7431                   -je 0x4a569f
    if (cpu.flags.zf)
    {
        goto L_0x004a569f;
    }
    // 004a566e  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x004a5671:
    // 004a5671  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 004a5676  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5678  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a567a  e8f07efeff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004a567f  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a5682  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a5685  a1e4435b00             -mov eax, dword ptr [0x5b43e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 004a568a  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a568d  8935e4435b00           -mov dword ptr [0x5b43e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */) = cpu.esi;
    // 004a5693  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a5695  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a569b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a569d  eb12                   -jmp 0x4a56b1
    goto L_0x004a56b1;
L_0x004a569f:
    // 004a569f  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a56a4  e877cbffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a56a9  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a56af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a56b1:
    // 004a56b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a56b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a56b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a56b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a56b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a56ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a56bc  bae4435b00             -mov edx, 0x5b43e4
    cpu.edx = 5981156 /*0x5b43e4*/;
L_0x004a56c1:
    // 004a56c1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a56c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a56c5  7425                   -je 0x4a56ec
    if (cpu.flags.zf)
    {
        goto L_0x004a56ec;
    }
    // 004a56c7  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a56ca  39cb                   +cmp ebx, ecx
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
    // 004a56cc  7404                   -je 0x4a56d2
    if (cpu.flags.zf)
    {
        goto L_0x004a56d2;
    }
    // 004a56ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a56d0  ebef                   -jmp 0x4a56c1
    goto L_0x004a56c1;
L_0x004a56d2:
    // 004a56d2  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a56d5  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004a56d8  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 004a56db  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a56dd  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a56df  8b15e8435b00           -mov edx, dword ptr [0x5b43e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */);
    // 004a56e5  a3e8435b00             -mov dword ptr [0x5b43e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */) = cpu.eax;
    // 004a56ea  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004a56ec:
    // 004a56ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a56ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a56f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a56f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004a56f1:
    // 004a56f1  8b15e8435b00           -mov edx, dword ptr [0x5b43e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */);
    // 004a56f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a56f9  7411                   -je 0x4a570c
    if (cpu.flags.zf)
    {
        goto L_0x004a570c;
    }
    // 004a56fb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a56fd  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a56ff  e8b4190000             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004a5704  8915e8435b00           -mov dword ptr [0x5b43e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */) = cpu.edx;
    // 004a570a  ebe5                   -jmp 0x4a56f1
    goto L_0x004a56f1;
L_0x004a570c:
    // 004a570c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a570d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a570e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a570e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a570f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5710  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5711  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5712  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5715  7f2c                   -jg 0x4a5743
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5743;
    }
    // 004a5717  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a571a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a571c  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a571f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5721  39d8                   +cmp eax, ebx
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
    // 004a5723  7c1e                   -jl 0x4a5743
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5743;
    }
    // 004a5725  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a5728  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a572a  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a572d  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a5730  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5732  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004a5735  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5737  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a5739  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a573b  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a573e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a573f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5740  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5741  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5742  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5743:
    // 004a5743  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a5748  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5749  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a574a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a574b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a574c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a574d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a574d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a574e  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a5752  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5755  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5758  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a575f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a5761  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5762  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5763(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5763  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5764  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5765  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5766  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5768  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a576a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a576d  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5773  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5776  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 004a5779  7465                   -je 0x4a57e0
    if (cpu.flags.zf)
    {
        goto L_0x004a57e0;
    }
    // 004a577b  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a577f  741f                   -je 0x4a57a0
    if (cpu.flags.zf)
    {
        goto L_0x004a57a0;
    }
    // 004a5781  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5783  e8c7160000             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
    // 004a5788  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a578a  742b                   -je 0x4a57b7
    if (cpu.flags.zf)
    {
        goto L_0x004a57b7;
    }
    // 004a578c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a578e  753e                   -jne 0x4a57ce
    if (!cpu.flags.zf)
    {
        goto L_0x004a57ce;
    }
    // 004a5790  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5792  7d3a                   -jge 0x4a57ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a57ce;
    }
L_0x004a5794:
    // 004a5794  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a5799  e882caffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a579e  eb2e                   -jmp 0x4a57ce
    goto L_0x004a57ce;
L_0x004a57a0:
    // 004a57a0  83fb01                 +cmp ebx, 1
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
    // 004a57a3  7503                   -jne 0x4a57a8
    if (!cpu.flags.zf)
    {
        goto L_0x004a57a8;
    }
    // 004a57a5  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x004a57a8:
    // 004a57a8  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a57ab  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a57ae  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a57b5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x004a57b7:
    // 004a57b7  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 004a57bb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a57bd  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
L_0x004a57c0:
    // 004a57c0  e8f2170000             -call 0x4a6fb7
    cpu.esp -= 4;
    sub_4a6fb7(app, cpu);
    if (cpu.terminate) return;
    // 004a57c5  83f8ff                 +cmp eax, -1
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
    // 004a57c8  0f8596000000           -jne 0x4a5864
    if (!cpu.flags.zf)
    {
        goto L_0x004a5864;
    }
L_0x004a57ce:
    // 004a57ce  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a57d1  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a57d7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a57dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a57dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a57de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a57df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a57e0:
    // 004a57e0  83fb01                 +cmp ebx, 1
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
    // 004a57e3  7209                   -jb 0x4a57ee
    if (cpu.flags.cf)
    {
        goto L_0x004a57ee;
    }
    // 004a57e5  760d                   -jbe 0x4a57f4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a57f4;
    }
    // 004a57e7  83fb02                 +cmp ebx, 2
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
    // 004a57ea  7457                   -je 0x4a5843
    if (cpu.flags.zf)
    {
        goto L_0x004a5843;
    }
    // 004a57ec  eba6                   -jmp 0x4a5794
    goto L_0x004a5794;
L_0x004a57ee:
    // 004a57ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a57f0  742c                   -je 0x4a581e
    if (cpu.flags.zf)
    {
        goto L_0x004a581e;
    }
    // 004a57f2  eba0                   -jmp 0x4a5794
    goto L_0x004a5794;
L_0x004a57f4:
    // 004a57f4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a57f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a57f8  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a57fb  e80effffff             -call 0x4a570e
    cpu.esp -= 4;
    sub_4a570e(app, cpu);
    if (cpu.terminate) return;
    // 004a5800  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5802  7460                   -je 0x4a5864
    if (cpu.flags.zf)
    {
        goto L_0x004a5864;
    }
    // 004a5804  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a5806  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5809  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a580b:
    // 004a580b  e8a7170000             -call 0x4a6fb7
    cpu.esp -= 4;
    sub_4a6fb7(app, cpu);
    if (cpu.terminate) return;
    // 004a5810  83f8ff                 +cmp eax, -1
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
    // 004a5813  74b9                   -je 0x4a57ce
    if (cpu.flags.zf)
    {
        goto L_0x004a57ce;
    }
    // 004a5815  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5817  e831ffffff             -call 0x4a574d
    cpu.esp -= 4;
    sub_4a574d(app, cpu);
    if (cpu.terminate) return;
    // 004a581c  eb46                   -jmp 0x4a5864
    goto L_0x004a5864;
L_0x004a581e:
    // 004a581e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5821  e87e0a0100             -call 0x4b62a4
    cpu.esp -= 4;
    sub_4b62a4(app, cpu);
    if (cpu.terminate) return;
    // 004a5826  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a5829  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a582b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a582d  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a582f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a5831  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a5833  e8d6feffff             -call 0x4a570e
    cpu.esp -= 4;
    sub_4a570e(app, cpu);
    if (cpu.terminate) return;
    // 004a5838  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a583a  7428                   -je 0x4a5864
    if (cpu.flags.zf)
    {
        goto L_0x004a5864;
    }
    // 004a583c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a583e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5841  ebc8                   -jmp 0x4a580b
    goto L_0x004a580b;
L_0x004a5843:
    // 004a5843  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004a5845  80e2ef                 +and dl, 0xef
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 004a5848  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a584b  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004a584e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5851  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a5853  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a5855  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5858  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a585f  e95cffffff             -jmp 0x4a57c0
    goto L_0x004a57c0;
L_0x004a5864:
    // 004a5864  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5867  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a586d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a586f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5870  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5871  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5872  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5873(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5873  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5874  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5875  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5876  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5878  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 004a587c  7522                   -jne 0x4a58a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a58a0;
    }
    // 004a587e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5881  e8c8090100             -call 0x4b624e
    cpu.esp -= 4;
    sub_4b624e(app, cpu);
    if (cpu.terminate) return;
    // 004a5886  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5888  7416                   -je 0x4a58a0
    if (cpu.flags.zf)
    {
        goto L_0x004a58a0;
    }
    // 004a588a  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004a588d  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a5890  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004a5893  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 004a5896  7508                   -jne 0x4a58a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a58a0;
    }
    // 004a5898  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a589a  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004a589d  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x004a58a0:
    // 004a58a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58a4  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a58aa  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 004a58af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58b0  a1f0435b00             -mov eax, dword ptr [0x5b43f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981168) /* 0x5b43f0 */);
    // 004a58b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a58b5;
    // 004a58b0  a1f0435b00             -mov eax, dword ptr [0x5b43f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981168) /* 0x5b43f0 */);
L_entry_0x004a58b5:
    // 004a58b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58b6  e99a060100             -jmp 0x4b5f55
    return sub_4b5f55(app, cpu);
}

/* align: skip  */
void Application::sub_4a58bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58bb  e9b3070100             -jmp 0x4b6073
    return sub_4b6073(app, cpu);
}

/* align: skip  */
void Application::sub_4a58c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a58c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a58c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a58c3  81ec18060000           -sub esp, 0x618
    (cpu.esp) -= x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 004a58c9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a58cb  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a58cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a58cf  893dec435b00           -mov dword ptr [0x5b43ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5981164) /* 0x5b43ec */) = cpu.edi;
    // 004a58d5  e8000c0100             -call 0x4b64da
    cpu.esp -= 4;
    sub_4b64da(app, cpu);
    if (cpu.terminate) return;
    // 004a58da  a3f0435b00             -mov dword ptr [0x5b43f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5981168) /* 0x5b43f0 */) = cpu.eax;
    // 004a58df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a58e1  7511                   -jne 0x4a58f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a58f4;
    }
    // 004a58e3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a58e5  0f85f6010000           -jne 0x4a5ae1
    if (!cpu.flags.zf)
    {
        goto L_0x004a5ae1;
    }
    // 004a58eb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a58ed  2eff1558444c00         -call dword ptr cs:[0x4c4458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998232) /* 0x4c4458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a58f4:
    // 004a58f4  e8a6070100             -call 0x4b609f
    cpu.esp -= 4;
    sub_4b609f(app, cpu);
    if (cpu.terminate) return;
    // 004a58f9  2eff15b0444c00         -call dword ptr cs:[0x4c44b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998320) /* 0x4c44b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5900  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5902  a3c9b84d00             -mov dword ptr [0x4db8c9], eax
    app->getMemory<x86::reg32>(x86::reg32(5093577) /* 0x4db8c9 */) = cpu.eax;
    // 004a5907  891574705b00           -mov dword ptr [0x5b7074], edx
    app->getMemory<x86::reg32>(x86::reg32(5992564) /* 0x5b7074 */) = cpu.edx;
    // 004a590d  2eff1500454c00         -call dword ptr cs:[0x4c4500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998400) /* 0x4c4500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5914  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5916  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5918  a2cfb84d00             -mov byte ptr [0x4db8cf], al
    app->getMemory<x86::reg8>(x86::reg32(5093583) /* 0x4db8cf */) = cpu.al;
    // 004a591d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a5920  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a5925  66a3d1b84d00           -mov word ptr [0x4db8d1], ax
    app->getMemory<x86::reg16>(x86::reg32(5093585) /* 0x4db8d1 */) = cpu.ax;
    // 004a592b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a592d  66a1d1b84d00           -mov ax, word ptr [0x4db8d1]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5093585) /* 0x4db8d1 */);
    // 004a5933  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a5939  a3d3b84d00             -mov dword ptr [0x4db8d3], eax
    app->getMemory<x86::reg32>(x86::reg32(5093587) /* 0x4db8d3 */) = cpu.eax;
    // 004a593e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5940  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a5943  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004a5945  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a594b  a3d7b84d00             -mov dword ptr [0x4db8d7], eax
    app->getMemory<x86::reg32>(x86::reg32(5093591) /* 0x4db8d7 */) = cpu.eax;
    // 004a5950  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5952  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a5954  8815d0b84d00           -mov byte ptr [0x4db8d0], dl
    app->getMemory<x86::reg8>(x86::reg32(5093584) /* 0x4db8d0 */) = cpu.dl;
    // 004a595a  a3dbb84d00             -mov dword ptr [0x4db8db], eax
    app->getMemory<x86::reg32>(x86::reg32(5093595) /* 0x4db8db */) = cpu.eax;
    // 004a595f  a1d7b84d00             -mov eax, dword ptr [0x4db8d7]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093591) /* 0x4db8d7 */);
    // 004a5964  8b15dbb84d00           -mov edx, dword ptr [0x4db8db]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093595) /* 0x4db8db */);
    // 004a596a  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a596d  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a596f  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004a5974  a3dfb84d00             -mov dword ptr [0x4db8df], eax
    app->getMemory<x86::reg32>(x86::reg32(5093599) /* 0x4db8df */) = cpu.eax;
    // 004a5979  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004a5980  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5981  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a5983  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 004a5988  2eff15d4444c00         -call dword ptr cs:[0x4c44d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998356) /* 0x4c44d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a598f  8d842410040000         -lea eax, [esp + 0x410]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1040) /* 0x410 */);
    // 004a5996  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a5998  e8230e0100             -call 0x4b67c0
    cpu.esp -= 4;
    sub_4b67c0(app, cpu);
    if (cpu.terminate) return;
    // 004a599d  a390b84d00             -mov dword ptr [0x4db890], eax
    app->getMemory<x86::reg32>(x86::reg32(5093520) /* 0x4db890 */) = cpu.eax;
    // 004a59a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a59a4  e85c0e0100             -call 0x4b6805
    cpu.esp -= 4;
    sub_4b6805(app, cpu);
    if (cpu.terminate) return;
    // 004a59a9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a59ab  e8e50e0100             -call 0x4b6895
    cpu.esp -= 4;
    sub_4b6895(app, cpu);
    if (cpu.terminate) return;
    // 004a59b0  a39cb84d00             -mov dword ptr [0x4db89c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093532) /* 0x4db89c */) = cpu.eax;
    // 004a59b5  2eff1588444c00         -call dword ptr cs:[0x4c4488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998280) /* 0x4c4488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a59bc  e8ff0d0100             -call 0x4b67c0
    cpu.esp -= 4;
    sub_4b67c0(app, cpu);
    if (cpu.terminate) return;
    // 004a59c1  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a59c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a59c5  80fb22                 +cmp bl, 0x22
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a59c8  7514                   -jne 0x4a59de
    if (!cpu.flags.zf)
    {
        goto L_0x004a59de;
    }
L_0x004a59ca:
    // 004a59ca  40                     -inc eax
    (cpu.eax)++;
    // 004a59cb  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004a59cd  80fd22                 +cmp ch, 0x22
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a59d0  7404                   -je 0x4a59d6
    if (cpu.flags.zf)
    {
        goto L_0x004a59d6;
    }
    // 004a59d2  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004a59d4  75f4                   -jne 0x4a59ca
    if (!cpu.flags.zf)
    {
        goto L_0x004a59ca;
    }
L_0x004a59d6:
    // 004a59d6  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a59d9  741e                   -je 0x4a59f9
    if (cpu.flags.zf)
    {
        goto L_0x004a59f9;
    }
L_0x004a59db:
    // 004a59db  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a59dc  eb1b                   -jmp 0x4a59f9
    goto L_0x004a59f9;
L_0x004a59de:
    // 004a59de  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a59e0  fec2                   -inc dl
    (cpu.dl)++;
    // 004a59e2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a59e8  f68228cd4d0002         +test byte ptr [edx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a59ef  7508                   -jne 0x4a59f9
    if (!cpu.flags.zf)
    {
        goto L_0x004a59f9;
    }
    // 004a59f1  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a59f4  7403                   -je 0x4a59f9
    if (cpu.flags.zf)
    {
        goto L_0x004a59f9;
    }
    // 004a59f6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a59f7  ebe5                   -jmp 0x4a59de
    goto L_0x004a59de;
L_0x004a59f9:
    // 004a59f9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a59fb  fec2                   -inc dl
    (cpu.dl)++;
    // 004a59fd  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5a03  f68228cd4d0002         +test byte ptr [edx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a5a0a  75cf                   -jne 0x4a59db
    if (!cpu.flags.zf)
    {
        goto L_0x004a59db;
    }
    // 004a5a0c  a38cb84d00             -mov dword ptr [0x4db88c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093516) /* 0x4db88c */) = cpu.eax;
    // 004a5a11  2eff158c444c00         -call dword ptr cs:[0x4c448c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998284) /* 0x4c448c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5a18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5a1a  0f845f000000           -je 0x4a5a7f
    if (cpu.flags.zf)
    {
        goto L_0x004a5a7f;
    }
    // 004a5a20  e8700e0100             -call 0x4b6895
    cpu.esp -= 4;
    sub_4b6895(app, cpu);
    if (cpu.terminate) return;
    // 004a5a25  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a5a28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5a2a  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a5a2e  751c                   -jne 0x4a5a4c
    if (!cpu.flags.zf)
    {
        goto L_0x004a5a4c;
    }
L_0x004a5a30:
    // 004a5a30  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a5a33  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a5a36  6683fa22               +cmp dx, 0x22
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a5a3a  7405                   -je 0x4a5a41
    if (cpu.flags.zf)
    {
        goto L_0x004a5a41;
    }
    // 004a5a3c  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004a5a3f  75ef                   -jne 0x4a5a30
    if (!cpu.flags.zf)
    {
        goto L_0x004a5a30;
    }
L_0x004a5a41:
    // 004a5a41  66833800               +cmp word ptr [eax], 0
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
    // 004a5a45  7423                   -je 0x4a5a6a
    if (cpu.flags.zf)
    {
        goto L_0x004a5a6a;
    }
L_0x004a5a47:
    // 004a5a47  83c002                 +add eax, 2
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
    // 004a5a4a  eb1e                   -jmp 0x4a5a6a
    goto L_0x004a5a6a;
L_0x004a5a4c:
    // 004a5a4c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5a4e  fec2                   -inc dl
    (cpu.dl)++;
    // 004a5a50  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5a56  f68228cd4d0002         +test byte ptr [edx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a5a5d  750b                   -jne 0x4a5a6a
    if (!cpu.flags.zf)
    {
        goto L_0x004a5a6a;
    }
    // 004a5a5f  66833800               +cmp word ptr [eax], 0
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
    // 004a5a63  7405                   -je 0x4a5a6a
    if (cpu.flags.zf)
    {
        goto L_0x004a5a6a;
    }
    // 004a5a65  83c002                 +add eax, 2
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
    // 004a5a68  ebe2                   -jmp 0x4a5a4c
    goto L_0x004a5a4c;
L_0x004a5a6a:
    // 004a5a6a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5a6c  fec2                   -inc dl
    (cpu.dl)++;
    // 004a5a6e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5a74  f68228cd4d0002         +test byte ptr [edx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a5a7b  740c                   -je 0x4a5a89
    if (cpu.flags.zf)
    {
        goto L_0x004a5a89;
    }
    // 004a5a7d  ebc8                   -jmp 0x4a5a47
    goto L_0x004a5a47;
L_0x004a5a7f:
    // 004a5a7f  b864f34c00             -mov eax, 0x4cf364
    cpu.eax = 5043044 /*0x4cf364*/;
    // 004a5a84  e80c0e0100             -call 0x4b6895
    cpu.esp -= 4;
    sub_4b6895(app, cpu);
    if (cpu.terminate) return;
L_0x004a5a89:
    // 004a5a89  a398b84d00             -mov dword ptr [0x4db898], eax
    app->getMemory<x86::reg32>(x86::reg32(5093528) /* 0x4db898 */) = cpu.eax;
    // 004a5a8e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a5a90  744a                   -je 0x4a5adc
    if (cpu.flags.zf)
    {
        goto L_0x004a5adc;
    }
    // 004a5a92  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004a5a97  8d842418050000         -lea eax, [esp + 0x518]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 004a5a9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5a9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5aa0  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 004a5aa5  2eff15d4444c00         -call dword ptr cs:[0x4c44d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998356) /* 0x4c44d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5aac  8d842414050000         -lea eax, [esp + 0x514]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 004a5ab3  8d942408020000         -lea edx, [esp + 0x208]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 004a5aba  e8010d0100             -call 0x4b67c0
    cpu.esp -= 4;
    sub_4b67c0(app, cpu);
    if (cpu.terminate) return;
    // 004a5abf  a394b84d00             -mov dword ptr [0x4db894], eax
    app->getMemory<x86::reg32>(x86::reg32(5093524) /* 0x4db894 */) = cpu.eax;
    // 004a5ac4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5ac6  e83a0d0100             -call 0x4b6805
    cpu.esp -= 4;
    sub_4b6805(app, cpu);
    if (cpu.terminate) return;
    // 004a5acb  8d842408020000         -lea eax, [esp + 0x208]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 004a5ad2  e8be0d0100             -call 0x4b6895
    cpu.esp -= 4;
    sub_4b6895(app, cpu);
    if (cpu.terminate) return;
    // 004a5ad7  a3a0b84d00             -mov dword ptr [0x4db8a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5093536) /* 0x4db8a0 */) = cpu.eax;
L_0x004a5adc:
    // 004a5adc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a5ae1:
    // 004a5ae1  81c418060000           -add esp, 0x618
    (cpu.esp) += x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 004a5ae7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ae8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5aea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5aeb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5aeb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5aec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5aed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5aee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5aef  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a5af1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a5af3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a5af5  2eff15dc444c00         -call dword ptr cs:[0x4c44dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998364) /* 0x4c44dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5afc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5afe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a5b00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b02  e8b9fdffff             -call 0x4a58c0
    cpu.esp -= 4;
    sub_4a58c0(app, cpu);
    if (cpu.terminate) return;
    // 004a5b07  baacb84d00             -mov edx, 0x4db8ac
    cpu.edx = 5093548 /*0x4db8ac*/;
    // 004a5b0c  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b12  e8a50d0100             -call 0x4b68bc
    cpu.esp -= 4;
    sub_4b68bc(app, cpu);
    if (cpu.terminate) return;
    // 004a5b17  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5b19  e825120100             -call 0x4b6d43
    cpu.esp -= 4;
    sub_4b6d43(app, cpu);
    if (cpu.terminate) return;
    // 004a5b1e  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 004a5b23  e8c8630000             -call 0x4abef0
    cpu.esp -= 4;
    sub_4abef0(app, cpu);
    if (cpu.terminate) return;
    // 004a5b28  ff155ccb4d00           -call dword ptr [0x4dcb5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098332) /* 0x4dcb5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b2e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a5b33  e8b8630000             -call 0x4abef0
    cpu.esp -= 4;
    sub_4abef0(app, cpu);
    if (cpu.terminate) return;
    // 004a5b38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5b3d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5b3d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5b3f  833dec435b0000         +cmp dword ptr [0x5b43ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5981164) /* 0x5b43ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5b46  7418                   -je 0x4a5b60
    if (cpu.flags.zf)
    {
        goto L_0x004a5b60;
    }
    // 004a5b48  833d64cb4d0000         +cmp dword ptr [0x4dcb64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098340) /* 0x4dcb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5b4f  7426                   -je 0x4a5b77
    if (cpu.flags.zf)
    {
        goto L_0x004a5b77;
    }
    // 004a5b51  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a5b56  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a5b58  ff1564cb4d00           -call dword ptr [0x4dcb64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098340) /* 0x4dcb64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b5e  eb17                   -jmp 0x4a5b77
    goto L_0x004a5b77;
L_0x004a5b60:
    // 004a5b60  e82a120100             -call 0x4b6d8f
    cpu.esp -= 4;
    sub_4b6d8f(app, cpu);
    if (cpu.terminate) return;
    // 004a5b65  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004a5b6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b6c  e8cb630000             -call 0x4abf3c
    cpu.esp -= 4;
    sub_4abf3c(app, cpu);
    if (cpu.terminate) return;
    // 004a5b71  ff1558cb4d00           -call dword ptr [0x4dcb58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098328) /* 0x4dcb58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a5b77:
    // 004a5b77  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5b78  2eff1558444c00         -call dword ptr cs:[0x4c4458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998232) /* 0x4c4458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5b80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5b81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5b82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5b83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5b84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5b86  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a5b89  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b8f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5b92  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a5b95  83fb01                 +cmp ebx, 1
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
    // 004a5b98  741e                   -je 0x4a5bb8
    if (cpu.flags.zf)
    {
        goto L_0x004a5bb8;
    }
    // 004a5b9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5b9c  7413                   -je 0x4a5bb1
    if (cpu.flags.zf)
    {
        goto L_0x004a5bb1;
    }
    // 004a5b9e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5ba1  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5ba7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a5bac  e98d000000             -jmp 0x4a5c3e
    goto L_0x004a5c3e;
L_0x004a5bb1:
    // 004a5bb1  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a5bb8:
    // 004a5bb8  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004a5bbc  7515                   -jne 0x4a5bd3
    if (!cpu.flags.zf)
    {
        goto L_0x004a5bd3;
    }
    // 004a5bbe  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a5bc3  e858c6ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a5bc8  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004a5bcc  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a5bd1  eb1f                   -jmp 0x4a5bf2
    goto L_0x004a5bf2;
L_0x004a5bd3:
    // 004a5bd3  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5bd6  4e                     -dec esi
    (cpu.esi)--;
    // 004a5bd7  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a5bda  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5bdc  7d0b                   -jge 0x4a5be9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5be9;
    }
    // 004a5bde  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5be0  e85f000000             -call 0x4a5c44
    cpu.esp -= 4;
    sub_4a5c44(app, cpu);
    if (cpu.terminate) return;
    // 004a5be5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5be7  eb09                   -jmp 0x4a5bf2
    goto L_0x004a5bf2;
L_0x004a5be9:
    // 004a5be9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5beb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5bed  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5bef  40                     -inc eax
    (cpu.eax)++;
    // 004a5bf0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a5bf2:
    // 004a5bf2  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004a5bf6  753b                   -jne 0x4a5c33
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c33;
    }
    // 004a5bf8  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5bfb  7523                   -jne 0x4a5c20
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c20;
    }
    // 004a5bfd  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5c00  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a5c01  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a5c04  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a5c06  7d0b                   -jge 0x4a5c13
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5c13;
    }
    // 004a5c08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5c0a  e835000000             -call 0x4a5c44
    cpu.esp -= 4;
    sub_4a5c44(app, cpu);
    if (cpu.terminate) return;
    // 004a5c0f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5c11  eb0d                   -jmp 0x4a5c20
    goto L_0x004a5c20;
L_0x004a5c13:
    // 004a5c13  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5c15  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5c17  40                     -inc eax
    (cpu.eax)++;
    // 004a5c18  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5c1e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a5c20:
    // 004a5c20  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5c23  750e                   -jne 0x4a5c33
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c33;
    }
    // 004a5c25  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a5c28  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004a5c2b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a5c30  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x004a5c33:
    // 004a5c33  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5c36  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5c3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a5c3e:
    // 004a5c3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5b7f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a5b7f;
    // 004a5b3d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5b3f  833dec435b0000         +cmp dword ptr [0x5b43ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5981164) /* 0x5b43ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5b46  7418                   -je 0x4a5b60
    if (cpu.flags.zf)
    {
        goto L_0x004a5b60;
    }
    // 004a5b48  833d64cb4d0000         +cmp dword ptr [0x4dcb64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098340) /* 0x4dcb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5b4f  7426                   -je 0x4a5b77
    if (cpu.flags.zf)
    {
        goto L_0x004a5b77;
    }
    // 004a5b51  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a5b56  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a5b58  ff1564cb4d00           -call dword ptr [0x4dcb64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098340) /* 0x4dcb64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b5e  eb17                   -jmp 0x4a5b77
    goto L_0x004a5b77;
L_0x004a5b60:
    // 004a5b60  e82a120100             -call 0x4b6d8f
    cpu.esp -= 4;
    sub_4b6d8f(app, cpu);
    if (cpu.terminate) return;
    // 004a5b65  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004a5b6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b6c  e8cb630000             -call 0x4abf3c
    cpu.esp -= 4;
    sub_4abf3c(app, cpu);
    if (cpu.terminate) return;
    // 004a5b71  ff1558cb4d00           -call dword ptr [0x4dcb58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098328) /* 0x4dcb58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a5b77:
    // 004a5b77  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5b78  2eff1558444c00         -call dword ptr cs:[0x4c4458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998232) /* 0x4c4458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004a5b7f:
    // 004a5b7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5b80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5b81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5b82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5b83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5b84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5b86  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a5b89  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5b8f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5b92  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a5b95  83fb01                 +cmp ebx, 1
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
    // 004a5b98  741e                   -je 0x4a5bb8
    if (cpu.flags.zf)
    {
        goto L_0x004a5bb8;
    }
    // 004a5b9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5b9c  7413                   -je 0x4a5bb1
    if (cpu.flags.zf)
    {
        goto L_0x004a5bb1;
    }
    // 004a5b9e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5ba1  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5ba7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a5bac  e98d000000             -jmp 0x4a5c3e
    goto L_0x004a5c3e;
L_0x004a5bb1:
    // 004a5bb1  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a5bb8:
    // 004a5bb8  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004a5bbc  7515                   -jne 0x4a5bd3
    if (!cpu.flags.zf)
    {
        goto L_0x004a5bd3;
    }
    // 004a5bbe  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a5bc3  e858c6ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a5bc8  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004a5bcc  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a5bd1  eb1f                   -jmp 0x4a5bf2
    goto L_0x004a5bf2;
L_0x004a5bd3:
    // 004a5bd3  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5bd6  4e                     -dec esi
    (cpu.esi)--;
    // 004a5bd7  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a5bda  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5bdc  7d0b                   -jge 0x4a5be9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5be9;
    }
    // 004a5bde  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5be0  e85f000000             -call 0x4a5c44
    cpu.esp -= 4;
    sub_4a5c44(app, cpu);
    if (cpu.terminate) return;
    // 004a5be5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5be7  eb09                   -jmp 0x4a5bf2
    goto L_0x004a5bf2;
L_0x004a5be9:
    // 004a5be9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5beb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5bed  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5bef  40                     -inc eax
    (cpu.eax)++;
    // 004a5bf0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a5bf2:
    // 004a5bf2  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004a5bf6  753b                   -jne 0x4a5c33
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c33;
    }
    // 004a5bf8  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5bfb  7523                   -jne 0x4a5c20
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c20;
    }
    // 004a5bfd  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5c00  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a5c01  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a5c04  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a5c06  7d0b                   -jge 0x4a5c13
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5c13;
    }
    // 004a5c08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5c0a  e835000000             -call 0x4a5c44
    cpu.esp -= 4;
    sub_4a5c44(app, cpu);
    if (cpu.terminate) return;
    // 004a5c0f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5c11  eb0d                   -jmp 0x4a5c20
    goto L_0x004a5c20;
L_0x004a5c13:
    // 004a5c13  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5c15  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5c17  40                     -inc eax
    (cpu.eax)++;
    // 004a5c18  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5c1e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a5c20:
    // 004a5c20  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5c23  750e                   -jne 0x4a5c33
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c33;
    }
    // 004a5c25  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a5c28  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004a5c2b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a5c30  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x004a5c33:
    // 004a5c33  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5c36  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5c3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a5c3e:
    // 004a5c3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5c44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5c44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5c45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5c46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5c47  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5c49  e825000000             -call 0x4a5c73
    cpu.esp -= 4;
    sub_4a5c73(app, cpu);
    if (cpu.terminate) return;
    // 004a5c4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5c50  7509                   -jne 0x4a5c5b
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c5b;
    }
    // 004a5c52  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a5c57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5c5b:
    // 004a5c5b  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5c5e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5c60  4b                     -dec ebx
    (cpu.ebx)--;
    // 004a5c61  41                     -inc ecx
    (cpu.ecx)++;
    // 004a5c62  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a5c65  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004a5c67  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004a5c6a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5c6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5c73(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5c73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5c74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5c75  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5c76  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5c77  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5c79  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5c7c  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004a5c80  7507                   -jne 0x4a5c89
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c89;
    }
    // 004a5c82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5c84  e842610000             -call 0x4abdcb
    cpu.esp -= 4;
    sub_4abdcb(app, cpu);
    if (cpu.terminate) return;
L_0x004a5c89:
    // 004a5c89  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004a5c8c  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004a5c8f  740f                   -je 0x4a5ca0
    if (cpu.flags.zf)
    {
        goto L_0x004a5ca0;
    }
    // 004a5c91  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 004a5c94  740a                   -je 0x4a5ca0
    if (cpu.flags.zf)
    {
        goto L_0x004a5ca0;
    }
    // 004a5c96  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 004a5c9b  e818110100             -call 0x4b6db8
    cpu.esp -= 4;
    sub_4b6db8(app, cpu);
    if (cpu.terminate) return;
L_0x004a5ca0:
    // 004a5ca0  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5ca3  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004a5ca6  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a5ca9  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 004a5cac  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5caf  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a5cb1  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5cb4  2500240000             -and eax, 0x2400
    cpu.eax &= x86::reg32(x86::sreg32(9216 /*0x2400*/));
    // 004a5cb9  3d00240000             +cmp eax, 0x2400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9216 /*0x2400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5cbe  7523                   -jne 0x4a5ce3
    if (!cpu.flags.zf)
    {
        goto L_0x004a5ce3;
    }
    // 004a5cc0  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5cc3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5cc5  751c                   -jne 0x4a5ce3
    if (!cpu.flags.zf)
    {
        goto L_0x004a5ce3;
    }
    // 004a5cc7  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a5cca  e824110100             -call 0x4b6df3
    cpu.esp -= 4;
    sub_4b6df3(app, cpu);
    if (cpu.terminate) return;
    // 004a5ccf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5cd1  83f8ff                 +cmp eax, -1
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
    // 004a5cd4  742a                   -je 0x4a5d00
    if (cpu.flags.zf)
    {
        goto L_0x004a5d00;
    }
    // 004a5cd6  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a5cd8  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004a5cda  c7410401000000         -mov dword ptr [ecx + 4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004a5ce1  eb3c                   -jmp 0x4a5d1f
    goto L_0x004a5d1f;
L_0x004a5ce3:
    // 004a5ce3  f6410d04               +test byte ptr [ecx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004a5ce7  7407                   -je 0x4a5cf0
    if (cpu.flags.zf)
    {
        goto L_0x004a5cf0;
    }
    // 004a5ce9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a5cee  eb03                   -jmp 0x4a5cf3
    goto L_0x004a5cf3;
L_0x004a5cf0:
    // 004a5cf0  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
L_0x004a5cf3:
    // 004a5cf3  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a5cf5  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5cf8  e855610000             -call 0x4abe52
    cpu.esp -= 4;
    sub_4abe52(app, cpu);
    if (cpu.terminate) return;
    // 004a5cfd  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a5d00:
    // 004a5d00  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a5d03  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5d05  7f18                   -jg 0x4a5d1f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5d1f;
    }
    // 004a5d07  7506                   -jne 0x4a5d0f
    if (!cpu.flags.zf)
    {
        goto L_0x004a5d0f;
    }
    // 004a5d09  80490c10               +or byte ptr [ecx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004a5d0d  eb10                   -jmp 0x4a5d1f
    goto L_0x004a5d1f;
L_0x004a5d0f:
    // 004a5d0f  8a790c                 -mov bh, byte ptr [ecx + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5d12  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a5d19  80cf20                 -or bh, 0x20
    cpu.bh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a5d1c  88790c                 -mov byte ptr [ecx + 0xc], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bh;
L_0x004a5d1f:
    // 004a5d1f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a5d22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5d27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5d27  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5d28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5d29  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5d2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5d2b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5d2d  83f8ff                 +cmp eax, -1
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
    // 004a5d30  0f84a6000000           -je 0x4a5ddc
    if (cpu.flags.zf)
    {
        goto L_0x004a5ddc;
    }
    // 004a5d36  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5d39  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5d3f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5d42  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a5d45  83f901                 +cmp ecx, 1
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
    // 004a5d48  741e                   -je 0x4a5d68
    if (cpu.flags.zf)
    {
        goto L_0x004a5d68;
    }
    // 004a5d4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a5d4c  7413                   -je 0x4a5d61
    if (cpu.flags.zf)
    {
        goto L_0x004a5d61;
    }
L_0x004a5d4e:
    // 004a5d4e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5d51  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5d57  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a5d5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5d61:
    // 004a5d61  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a5d68:
    // 004a5d68  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a5d6c  75e0                   -jne 0x4a5d4e
    if (!cpu.flags.zf)
    {
        goto L_0x004a5d4e;
    }
    // 004a5d6e  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004a5d72  74da                   -je 0x4a5d4e
    if (cpu.flags.zf)
    {
        goto L_0x004a5d4e;
    }
    // 004a5d74  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5d77  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004a5d7b  7507                   -jne 0x4a5d84
    if (!cpu.flags.zf)
    {
        goto L_0x004a5d84;
    }
    // 004a5d7d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5d7f  e847600000             -call 0x4abdcb
    cpu.esp -= 4;
    sub_4abdcb(app, cpu);
    if (cpu.terminate) return;
L_0x004a5d84:
    // 004a5d84  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5d87  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a5d89  7517                   -jne 0x4a5da2
    if (!cpu.flags.zf)
    {
        goto L_0x004a5da2;
    }
    // 004a5d8b  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004a5d92  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5d95  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a5d98  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5d9b  01c8                   +add eax, ecx
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
    // 004a5d9d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5d9e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a5da0  eb21                   -jmp 0x4a5dc3
    goto L_0x004a5dc3;
L_0x004a5da2:
    // 004a5da2  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5da5  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5da7  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5daa  74a2                   -je 0x4a5d4e
    if (cpu.flags.zf)
    {
        goto L_0x004a5d4e;
    }
    // 004a5dac  8d7d01                 -lea edi, [ebp + 1]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004a5daf  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5db1  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a5db4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a5db5  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004a5db7  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a5dba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5dbf  39d8                   +cmp eax, ebx
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
    // 004a5dc1  7404                   -je 0x4a5dc7
    if (cpu.flags.zf)
    {
        goto L_0x004a5dc7;
    }
L_0x004a5dc3:
    // 004a5dc3  804a0c04               -or byte ptr [edx + 0xc], 4
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004a5dc7:
    // 004a5dc7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5dc9  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004a5dcb  80620cef               -and byte ptr [edx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a5dcf  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a5dd2  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5dd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5dda  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x004a5ddc:
    // 004a5ddc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ddd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5dde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ddf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5de0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5de1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5de1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5de2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5de4  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5de6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5de7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5de8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5de9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a5deb  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5dee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5def  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5df1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5df2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5df3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5df4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5df7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a5df9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a5dfc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a5dfe  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a5e02  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a5e05  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a5e07  80e4fd                 -and ah, 0xfd
    cpu.ah &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a5e0a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a5e0c  886610                 -mov byte ptr [esi + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ah;
L_0x004a5e0f:
    // 004a5e0f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5e12  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a5e15  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a5e18  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a5e1a  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a5e20  0f8423020000           -je 0x4a6049
    if (cpu.flags.zf)
    {
        goto L_0x004a6049;
    }
    // 004a5e26  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004a5e28  fec0                   -inc al
    (cpu.al)++;
    // 004a5e2a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5e2f  f68028cd4d0002         +test byte ptr [eax + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a5e36  740e                   -je 0x4a5e46
    if (cpu.flags.zf)
    {
        goto L_0x004a5e46;
    }
    // 004a5e38  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5e3a  e81c030000             -call 0x4a615b
    cpu.esp -= 4;
    sub_4a615b(app, cpu);
    if (cpu.terminate) return;
    // 004a5e3f  01c7                   +add edi, eax
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
    // 004a5e41  e9cd010000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5e46:
    // 004a5e46  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5e49  7425                   -je 0x4a5e70
    if (cpu.flags.zf)
    {
        goto L_0x004a5e70;
    }
    // 004a5e4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5e4d  e88fffffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a5e52  39d8                   +cmp eax, ebx
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
    // 004a5e54  0f84b8010000           -je 0x4a6012
    if (cpu.flags.zf)
    {
        goto L_0x004a6012;
    }
L_0x004a5e5a:
    // 004a5e5a  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a5e5e  0f85e5010000           -jne 0x4a6049
    if (!cpu.flags.zf)
    {
        goto L_0x004a6049;
    }
    // 004a5e64  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a5e66  e87dffffff             -call 0x4a5de8
    cpu.esp -= 4;
    sub_4a5de8(app, cpu);
    if (cpu.terminate) return;
    // 004a5e6b  e9d9010000             -jmp 0x4a6049
    goto L_0x004a6049;
L_0x004a5e70:
    // 004a5e70  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5e73  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a5e75  e8ea010000             -call 0x4a6064
    cpu.esp -= 4;
    sub_4a6064(app, cpu);
    if (cpu.terminate) return;
    // 004a5e7a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5e7c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5e7f  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5e81  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5e83  7404                   -je 0x4a5e89
    if (cpu.flags.zf)
    {
        goto L_0x004a5e89;
    }
    // 004a5e85  40                     -inc eax
    (cpu.eax)++;
    // 004a5e86  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004a5e89:
    // 004a5e89  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5e8c  7265                   -jb 0x4a5ef3
    if (cpu.flags.cf)
    {
        goto L_0x004a5ef3;
    }
    // 004a5e8e  0f86c3000000           -jbe 0x4a5f57
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5f57;
    }
    // 004a5e94  83fb6f                 +cmp ebx, 0x6f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5e97  7233                   -jb 0x4a5ecc
    if (cpu.flags.cf)
    {
        goto L_0x004a5ecc;
    }
    // 004a5e99  0f86e1000000           -jbe 0x4a5f80
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5f80;
    }
    // 004a5e9f  83fb73                 +cmp ebx, 0x73
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5ea2  7223                   -jb 0x4a5ec7
    if (cpu.flags.cf)
    {
        goto L_0x004a5ec7;
    }
    // 004a5ea4  0f860e010000           -jbe 0x4a5fb8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5fb8;
    }
    // 004a5eaa  83fb75                 +cmp ebx, 0x75
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5ead  0f8260010000           -jb 0x4a6013
    if (cpu.flags.cf)
    {
        goto L_0x004a6013;
    }
    // 004a5eb3  0f86d3000000           -jbe 0x4a5f8c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5f8c;
    }
    // 004a5eb9  83fb78                 +cmp ebx, 0x78
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x004a5ebc:
    // 004a5ebc  0f84d9000000           -je 0x4a5f9b
    if (cpu.flags.zf)
    {
        goto L_0x004a5f9b;
    }
    // 004a5ec2  e94c010000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5ec7:
    // 004a5ec7  83fb70                 +cmp ebx, 0x70
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5eca  ebf0                   -jmp 0x4a5ebc
    goto L_0x004a5ebc;
L_0x004a5ecc:
    // 004a5ecc  83fb69                 +cmp ebx, 0x69
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5ecf  7214                   -jb 0x4a5ee5
    if (cpu.flags.cf)
    {
        goto L_0x004a5ee5;
    }
    // 004a5ed1  0f869a000000           -jbe 0x4a5f71
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5f71;
    }
    // 004a5ed7  83fb6e                 +cmp ebx, 0x6e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5eda  0f8414010000           -je 0x4a5ff4
    if (cpu.flags.zf)
    {
        goto L_0x004a5ff4;
    }
    // 004a5ee0  e92e010000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5ee5:
    // 004a5ee5  83fb67                 +cmp ebx, 0x67
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5ee8  0f86b9000000           -jbe 0x4a5fa7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5fa7;
    }
    // 004a5eee  e920010000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5ef3:
    // 004a5ef3  83fb47                 +cmp ebx, 0x47
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5ef6  723c                   -jb 0x4a5f34
    if (cpu.flags.cf)
    {
        goto L_0x004a5f34;
    }
    // 004a5ef8  0f86a9000000           -jbe 0x4a5fa7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5fa7;
    }
    // 004a5efe  83fb58                 +cmp ebx, 0x58
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f01  7223                   -jb 0x4a5f26
    if (cpu.flags.cf)
    {
        goto L_0x004a5f26;
    }
    // 004a5f03  0f8692000000           -jbe 0x4a5f9b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5f9b;
    }
    // 004a5f09  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f0c  0f8201010000           -jb 0x4a6013
    if (cpu.flags.cf)
    {
        goto L_0x004a6013;
    }
    // 004a5f12  0f86ad000000           -jbe 0x4a5fc5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5fc5;
    }
    // 004a5f18  83fb63                 +cmp ebx, 0x63
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f1b  0f84b7000000           -je 0x4a5fd8
    if (cpu.flags.zf)
    {
        goto L_0x004a5fd8;
    }
    // 004a5f21  e9ed000000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5f26:
    // 004a5f26  83fb53                 +cmp ebx, 0x53
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f29  0f8485000000           -je 0x4a5fb4
    if (cpu.flags.zf)
    {
        goto L_0x004a5fb4;
    }
    // 004a5f2f  e9df000000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5f34:
    // 004a5f34  83fb43                 +cmp ebx, 0x43
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f37  7210                   -jb 0x4a5f49
    if (cpu.flags.cf)
    {
        goto L_0x004a5f49;
    }
    // 004a5f39  0f8695000000           -jbe 0x4a5fd4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5fd4;
    }
    // 004a5f3f  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f42  7463                   -je 0x4a5fa7
    if (cpu.flags.zf)
    {
        goto L_0x004a5fa7;
    }
    // 004a5f44  e9ca000000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5f49:
    // 004a5f49  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f4c  0f84b1000000           -je 0x4a6003
    if (cpu.flags.zf)
    {
        goto L_0x004a6003;
    }
    // 004a5f52  e9bc000000             -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5f57:
    // 004a5f57  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a5f5c  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
L_0x004a5f61:
    // 004a5f61  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5f65  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a5f67:
    // 004a5f67  e8c8080000             -call 0x4a6834
    cpu.esp -= 4;
    sub_4a6834(app, cpu);
    if (cpu.terminate) return;
    // 004a5f6c  e972000000             -jmp 0x4a5fe3
    goto L_0x004a5fe3;
L_0x004a5f71:
    // 004a5f71  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a5f76  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5f7a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5f7c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a5f7e  ebe7                   -jmp 0x4a5f67
    goto L_0x004a5f67;
L_0x004a5f80:
    // 004a5f80  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a5f85  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004a5f8a  ebd5                   -jmp 0x4a5f61
    goto L_0x004a5f61;
L_0x004a5f8c:
    // 004a5f8c  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004a5f91  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5f95  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5f97  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a5f99  ebcc                   -jmp 0x4a5f67
    goto L_0x004a5f67;
L_0x004a5f9b:
    // 004a5f9b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a5fa0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004a5fa5  ebba                   -jmp 0x4a5f61
    goto L_0x004a5f61;
L_0x004a5fa7:
    // 004a5fa7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5fab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5fad  e8ac050000             -call 0x4a655e
    cpu.esp -= 4;
    sub_4a655e(app, cpu);
    if (cpu.terminate) return;
    // 004a5fb2  eb2f                   -jmp 0x4a5fe3
    goto L_0x004a5fe3;
L_0x004a5fb4:
    // 004a5fb4  804e1020               +or byte ptr [esi + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
L_0x004a5fb8:
    // 004a5fb8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5fbc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5fbe  e8b1020000             -call 0x4a6274
    cpu.esp -= 4;
    sub_4a6274(app, cpu);
    if (cpu.terminate) return;
    // 004a5fc3  eb1e                   -jmp 0x4a5fe3
    goto L_0x004a5fe3;
L_0x004a5fc5:
    // 004a5fc5  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a5fc7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5fcb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5fcd  e896040000             -call 0x4a6468
    cpu.esp -= 4;
    sub_4a6468(app, cpu);
    if (cpu.terminate) return;
    // 004a5fd2  eb0f                   -jmp 0x4a5fe3
    goto L_0x004a5fe3;
L_0x004a5fd4:
    // 004a5fd4  804e1020               -or byte ptr [esi + 0x10], 0x20
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004a5fd8:
    // 004a5fd8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5fdc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5fde  e8af010000             -call 0x4a6192
    cpu.esp -= 4;
    sub_4a6192(app, cpu);
    if (cpu.terminate) return;
L_0x004a5fe3:
    // 004a5fe3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5fe5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5fe7  7e60                   -jle 0x4a6049
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6049;
    }
    // 004a5fe9  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5feb  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a5fef  7422                   -je 0x4a6013
    if (cpu.flags.zf)
    {
        goto L_0x004a6013;
    }
    // 004a5ff1  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a5ff2  eb1f                   -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a5ff4:
    // 004a5ff4  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5ff8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a5ffa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5ffc  e8c6030000             -call 0x4a63c7
    cpu.esp -= 4;
    sub_4a63c7(app, cpu);
    if (cpu.terminate) return;
    // 004a6001  eb10                   -jmp 0x4a6013
    goto L_0x004a6013;
L_0x004a6003:
    // 004a6003  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6005  e8d7fdffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a600a  39d8                   +cmp eax, ebx
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
    // 004a600c  0f8548feffff           -jne 0x4a5e5a
    if (!cpu.flags.zf)
    {
        goto L_0x004a5e5a;
    }
L_0x004a6012:
    // 004a6012  47                     -inc edi
    (cpu.edi)++;
L_0x004a6013:
    // 004a6013  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a6017  0f84f2fdffff           -je 0x4a5e0f
    if (cpu.flags.zf)
    {
        goto L_0x004a5e0f;
    }
    // 004a601d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a6020  803825                 +cmp byte ptr [eax], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6023  7524                   -jne 0x4a6049
    if (!cpu.flags.zf)
    {
        goto L_0x004a6049;
    }
    // 004a6025  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a6028  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a602a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a602c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a602f  e830000000             -call 0x4a6064
    cpu.esp -= 4;
    sub_4a6064(app, cpu);
    if (cpu.terminate) return;
    // 004a6034  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a6037  80386e                 +cmp byte ptr [eax], 0x6e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a603a  750d                   -jne 0x4a6049
    if (!cpu.flags.zf)
    {
        goto L_0x004a6049;
    }
    // 004a603c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a6040  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a6042  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6044  e87e030000             -call 0x4a63c7
    cpu.esp -= 4;
    sub_4a63c7(app, cpu);
    if (cpu.terminate) return;
L_0x004a6049:
    // 004a6049  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a604b  750d                   -jne 0x4a605a
    if (!cpu.flags.zf)
    {
        goto L_0x004a605a;
    }
    // 004a604d  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a6051  7407                   -je 0x4a605a
    if (cpu.flags.zf)
    {
        goto L_0x004a605a;
    }
    // 004a6053  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a6058  eb02                   -jmp 0x4a605c
    goto L_0x004a605c;
L_0x004a605a:
    // 004a605a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004a605c:
    // 004a605c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a605f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6060  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6062  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6065  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6066  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6067  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a606a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a606c  8a5210                 -mov dl, byte ptr [edx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a606f  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a6072  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004a6075  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004a6077  c7430cffffffff         -mov dword ptr [ebx + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 004a607e  80e603                 -and dh, 3
    cpu.dh &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004a6081  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 004a6084  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6087  750a                   -jne 0x4a6093
    if (!cpu.flags.zf)
    {
        goto L_0x004a6093;
    }
    // 004a6089  8a6b10                 -mov ch, byte ptr [ebx + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a608c  80e5fe                 -and ch, 0xfe
    cpu.ch &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a608f  40                     -inc eax
    (cpu.eax)++;
    // 004a6090  886b10                 -mov byte ptr [ebx + 0x10], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ch;
L_0x004a6093:
    // 004a6093  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6095  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a6097  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a609a  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a609d  fec2                   -inc dl
    (cpu.dl)++;
    // 004a609f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a60a5  f68228cd4d0020         +test byte ptr [edx + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a60ac  7428                   -je 0x4a60d6
    if (cpu.flags.zf)
    {
        goto L_0x004a60d6;
    }
    // 004a60ae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a60b0:
    // 004a60b0  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004a60b3  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a60b6  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a60b9  40                     -inc eax
    (cpu.eax)++;
    // 004a60ba  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a60bc  0fb630                 -movzx esi, byte ptr [eax]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 004a60bf  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a60c2  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a60c5  fec1                   -inc cl
    (cpu.cl)++;
    // 004a60c7  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 004a60ca  f68628cd4d0020         +test byte ptr [esi + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a60d1  75dd                   -jne 0x4a60b0
    if (!cpu.flags.zf)
    {
        goto L_0x004a60b0;
    }
    // 004a60d3  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004a60d6:
    // 004a60d6  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a60d8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a60db  80f94e                 +cmp cl, 0x4e
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a60de  7506                   -jne 0x4a60e6
    if (!cpu.flags.zf)
    {
        goto L_0x004a60e6;
    }
    // 004a60e0  804b1008               +or byte ptr [ebx + 0x10], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004a60e4  eb09                   -jmp 0x4a60ef
    goto L_0x004a60ef;
L_0x004a60e6:
    // 004a60e6  80f946                 +cmp cl, 0x46
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a60e9  7506                   -jne 0x4a60f1
    if (!cpu.flags.zf)
    {
        goto L_0x004a60f1;
    }
    // 004a60eb  804b1004               -or byte ptr [ebx + 0x10], 4
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004a60ef:
    // 004a60ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004a60f1:
    // 004a60f1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a60f3  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a60f6  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a60f9  7210                   -jb 0x4a610b
    if (cpu.flags.cf)
    {
        goto L_0x004a610b;
    }
    // 004a60fb  761c                   -jbe 0x4a6119
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6119;
    }
    // 004a60fd  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6100  7252                   -jb 0x4a6154
    if (cpu.flags.cf)
    {
        goto L_0x004a6154;
    }
    // 004a6102  761f                   -jbe 0x4a6123
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6123;
    }
    // 004a6104  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6107  741a                   -je 0x4a6123
    if (cpu.flags.zf)
    {
        goto L_0x004a6123;
    }
    // 004a6109  eb49                   -jmp 0x4a6154
    goto L_0x004a6154;
L_0x004a610b:
    // 004a610b  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a610e  7244                   -jb 0x4a6154
    if (cpu.flags.cf)
    {
        goto L_0x004a6154;
    }
    // 004a6110  762a                   -jbe 0x4a613c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a613c;
    }
    // 004a6112  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6115  7418                   -je 0x4a612f
    if (cpu.flags.zf)
    {
        goto L_0x004a612f;
    }
    // 004a6117  eb3b                   -jmp 0x4a6154
    goto L_0x004a6154;
L_0x004a6119:
    // 004a6119  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a611c  80ce10                 +or dh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004a611f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6121  eb2e                   -jmp 0x4a6151
    goto L_0x004a6151;
L_0x004a6123:
    // 004a6123  8a5310                 -mov dl, byte ptr [ebx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a6126  80ca20                 +or dl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004a6129  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a612a  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004a612d  eb25                   -jmp 0x4a6154
    goto L_0x004a6154;
L_0x004a612f:
    // 004a612f  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a6132  80c940                 +or cl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004a6135  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6137  884b10                 -mov byte ptr [ebx + 0x10], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.cl;
    // 004a613a  eb18                   -jmp 0x4a6154
    goto L_0x004a6154;
L_0x004a613c:
    // 004a613c  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6140  7512                   -jne 0x4a6154
    if (!cpu.flags.zf)
    {
        goto L_0x004a6154;
    }
    // 004a6142  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6146  750c                   -jne 0x4a6154
    if (!cpu.flags.zf)
    {
        goto L_0x004a6154;
    }
    // 004a6148  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a614b  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004a614e  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a6151:
    // 004a6151  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
L_0x004a6154:
    // 004a6154  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6157  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6158  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6159  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a615a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a615b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a615b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a615c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a615d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a615e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6160  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a6162:
    // 004a6162  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a6164  e878fcffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a6169  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a616b  fec2                   -inc dl
    (cpu.dl)++;
    // 004a616d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6173  f68228cd4d0002         +test byte ptr [edx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a617a  7403                   -je 0x4a617f
    if (cpu.flags.zf)
    {
        goto L_0x004a617f;
    }
    // 004a617c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a617d  ebe3                   -jmp 0x4a6162
    goto L_0x004a6162;
L_0x004a617f:
    // 004a617f  f6431002               +test byte ptr [ebx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a6183  7507                   -jne 0x4a618c
    if (!cpu.flags.zf)
    {
        goto L_0x004a618c;
    }
    // 004a6185  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a6187  e85cfcffff             -call 0x4a5de8
    cpu.esp -= 4;
    sub_4a5de8(app, cpu);
    if (cpu.terminate) return;
L_0x004a618c:
    // 004a618c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a618e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a618f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6190  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6191  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6192(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6192  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6193  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6194  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6195  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6196  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6197  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6198  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a619b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a619d  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a61a1  7437                   -je 0x4a61da
    if (cpu.flags.zf)
    {
        goto L_0x004a61da;
    }
    // 004a61a3  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a61a6  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004a61a9  740c                   -je 0x4a61b7
    if (cpu.flags.zf)
    {
        goto L_0x004a61b7;
    }
    // 004a61ab  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a61ad  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a61b0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004a61b2  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004a61b5  eb23                   -jmp 0x4a61da
    goto L_0x004a61da;
L_0x004a61b7:
    // 004a61b7  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004a61ba  7410                   -je 0x4a61cc
    if (cpu.flags.zf)
    {
        goto L_0x004a61cc;
    }
    // 004a61bc  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a61be  83c604                 +add esi, 4
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
    // 004a61c1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a61c3  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a61c5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a61c7  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004a61ca  eb0e                   -jmp 0x4a61da
    goto L_0x004a61da;
L_0x004a61cc:
    // 004a61cc  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a61ce  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a61d1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a61d3  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a61d5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a61d7  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004a61da:
    // 004a61da  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a61dd  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a61df  83ffff                 +cmp edi, -1
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
    // 004a61e2  7505                   -jne 0x4a61e9
    if (!cpu.flags.zf)
    {
        goto L_0x004a61e9;
    }
    // 004a61e4  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004a61e9:
    // 004a61e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a61eb  0f8e77000000           -jle 0x4a6268
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6268;
    }
    // 004a61f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a61f3  e8e9fbffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a61f8  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a61fb  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a61fe  0f8564000000           -jne 0x4a6268
    if (!cpu.flags.zf)
    {
        goto L_0x004a6268;
    }
    // 004a6204  45                     -inc ebp
    (cpu.ebp)++;
    // 004a6205  4f                     -dec edi
    (cpu.edi)--;
    // 004a6206  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a6209  74de                   -je 0x4a61e9
    if (cpu.flags.zf)
    {
        goto L_0x004a61e9;
    }
    // 004a620b  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004a620e  7452                   -je 0x4a6262
    if (cpu.flags.zf)
    {
        goto L_0x004a6262;
    }
    // 004a6210  8b1590805b00           -mov edx, dword ptr [0x5b8090]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
    // 004a6216  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004a621a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a621c  741f                   -je 0x4a623d
    if (cpu.flags.zf)
    {
        goto L_0x004a623d;
    }
    // 004a621e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6223  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004a6229  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a622b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a6230  740b                   -je 0x4a623d
    if (cpu.flags.zf)
    {
        goto L_0x004a623d;
    }
    // 004a6232  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6234  e8a8fbffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a6239  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x004a623d:
    // 004a623d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a6242  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a6246  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a6248  e8dd0b0100             -call 0x4b6e2a
    cpu.esp -= 4;
    sub_4b6e2a(app, cpu);
    if (cpu.terminate) return;
    // 004a624d  83f8ff                 +cmp eax, -1
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
    // 004a6250  7504                   -jne 0x4a6256
    if (!cpu.flags.zf)
    {
        goto L_0x004a6256;
    }
    // 004a6252  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a6254  eb14                   -jmp 0x4a626a
    goto L_0x004a626a;
L_0x004a6256:
    // 004a6256  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a6259  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 004a625d  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6260  eb87                   -jmp 0x4a61e9
    goto L_0x004a61e9;
L_0x004a6262:
    // 004a6262  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 004a6265  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6266  eb81                   -jmp 0x4a61e9
    goto L_0x004a61e9;
L_0x004a6268:
    // 004a6268  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004a626a:
    // 004a626a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a626d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a626e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a626f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6270  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6271  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6272  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6273  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a626d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a626d;
    // 004a6192  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6193  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6194  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6195  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6196  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6197  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6198  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a619b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a619d  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a61a1  7437                   -je 0x4a61da
    if (cpu.flags.zf)
    {
        goto L_0x004a61da;
    }
    // 004a61a3  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a61a6  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004a61a9  740c                   -je 0x4a61b7
    if (cpu.flags.zf)
    {
        goto L_0x004a61b7;
    }
    // 004a61ab  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a61ad  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a61b0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004a61b2  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004a61b5  eb23                   -jmp 0x4a61da
    goto L_0x004a61da;
L_0x004a61b7:
    // 004a61b7  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004a61ba  7410                   -je 0x4a61cc
    if (cpu.flags.zf)
    {
        goto L_0x004a61cc;
    }
    // 004a61bc  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a61be  83c604                 +add esi, 4
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
    // 004a61c1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a61c3  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a61c5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a61c7  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004a61ca  eb0e                   -jmp 0x4a61da
    goto L_0x004a61da;
L_0x004a61cc:
    // 004a61cc  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a61ce  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a61d1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a61d3  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a61d5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a61d7  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004a61da:
    // 004a61da  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a61dd  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a61df  83ffff                 +cmp edi, -1
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
    // 004a61e2  7505                   -jne 0x4a61e9
    if (!cpu.flags.zf)
    {
        goto L_0x004a61e9;
    }
    // 004a61e4  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004a61e9:
    // 004a61e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a61eb  0f8e77000000           -jle 0x4a6268
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6268;
    }
    // 004a61f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a61f3  e8e9fbffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a61f8  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a61fb  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a61fe  0f8564000000           -jne 0x4a6268
    if (!cpu.flags.zf)
    {
        goto L_0x004a6268;
    }
    // 004a6204  45                     -inc ebp
    (cpu.ebp)++;
    // 004a6205  4f                     -dec edi
    (cpu.edi)--;
    // 004a6206  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a6209  74de                   -je 0x4a61e9
    if (cpu.flags.zf)
    {
        goto L_0x004a61e9;
    }
    // 004a620b  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004a620e  7452                   -je 0x4a6262
    if (cpu.flags.zf)
    {
        goto L_0x004a6262;
    }
    // 004a6210  8b1590805b00           -mov edx, dword ptr [0x5b8090]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
    // 004a6216  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004a621a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a621c  741f                   -je 0x4a623d
    if (cpu.flags.zf)
    {
        goto L_0x004a623d;
    }
    // 004a621e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6223  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004a6229  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a622b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a6230  740b                   -je 0x4a623d
    if (cpu.flags.zf)
    {
        goto L_0x004a623d;
    }
    // 004a6232  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6234  e8a8fbffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a6239  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x004a623d:
    // 004a623d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a6242  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a6246  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a6248  e8dd0b0100             -call 0x4b6e2a
    cpu.esp -= 4;
    sub_4b6e2a(app, cpu);
    if (cpu.terminate) return;
    // 004a624d  83f8ff                 +cmp eax, -1
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
    // 004a6250  7504                   -jne 0x4a6256
    if (!cpu.flags.zf)
    {
        goto L_0x004a6256;
    }
    // 004a6252  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a6254  eb14                   -jmp 0x4a626a
    goto L_0x004a626a;
L_0x004a6256:
    // 004a6256  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a6259  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 004a625d  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6260  eb87                   -jmp 0x4a61e9
    goto L_0x004a61e9;
L_0x004a6262:
    // 004a6262  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 004a6265  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6266  eb81                   -jmp 0x4a61e9
    goto L_0x004a61e9;
L_0x004a6268:
    // 004a6268  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004a626a:
    // 004a626a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_entry_0x004a626d:
    // 004a626d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a626e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a626f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6270  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6271  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6272  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6273  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6274  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6275  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6276  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6277  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6278  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6279  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a627a  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a627d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a627f  f6401020               +test byte ptr [eax + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 004a6283  7407                   -je 0x4a628c
    if (cpu.flags.zf)
    {
        goto L_0x004a628c;
    }
    // 004a6285  c644240802             -mov byte ptr [esp + 8], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 2 /*0x2*/;
    // 004a628a  eb09                   -jmp 0x4a6295
    goto L_0x004a6295;
L_0x004a628c:
    // 004a628c  f6411010               -test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004a6290  c644240801             -mov byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x004a6295:
    // 004a6295  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6298  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004a629b  7434                   -je 0x4a62d1
    if (cpu.flags.zf)
    {
        goto L_0x004a62d1;
    }
    // 004a629d  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004a62a0  740c                   -je 0x4a62ae
    if (cpu.flags.zf)
    {
        goto L_0x004a62ae;
    }
    // 004a62a2  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a62a4  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a62a7  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004a62a9  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004a62ac  eb23                   -jmp 0x4a62d1
    goto L_0x004a62d1;
L_0x004a62ae:
    // 004a62ae  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004a62b1  7410                   -je 0x4a62c3
    if (cpu.flags.zf)
    {
        goto L_0x004a62c3;
    }
    // 004a62b3  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a62b5  83c604                 +add esi, 4
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
    // 004a62b8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a62ba  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a62bc  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a62be  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004a62c1  eb0e                   -jmp 0x4a62d1
    goto L_0x004a62d1;
L_0x004a62c3:
    // 004a62c3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a62c5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a62c8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a62ca  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a62cc  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a62ce  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004a62d1:
    // 004a62d1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a62d3:
    // 004a62d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a62d5  e807fbffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a62da  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a62dc  fec0                   -inc al
    (cpu.al)++;
    // 004a62de  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a62e3  f68028cd4d0002         +test byte ptr [eax + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a62ea  7403                   -je 0x4a62ef
    if (cpu.flags.zf)
    {
        goto L_0x004a62ef;
    }
    // 004a62ec  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a62ed  ebe4                   -jmp 0x4a62d3
    goto L_0x004a62d3;
L_0x004a62ef:
    // 004a62ef  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a62f3  7407                   -je 0x4a62fc
    if (cpu.flags.zf)
    {
        goto L_0x004a62fc;
    }
    // 004a62f5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a62f7  e9a4000000             -jmp 0x4a63a0
    goto L_0x004a63a0;
L_0x004a62fc:
    // 004a62fc  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a62ff  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a6302  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a6305  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6307  0f848a000000           -je 0x4a6397
    if (cpu.flags.zf)
    {
        goto L_0x004a6397;
    }
L_0x004a630d:
    // 004a630d  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6310  47                     -inc edi
    (cpu.edi)++;
    // 004a6311  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a6313  7460                   -je 0x4a6375
    if (cpu.flags.zf)
    {
        goto L_0x004a6375;
    }
    // 004a6315  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a631a  7505                   -jne 0x4a6321
    if (!cpu.flags.zf)
    {
        goto L_0x004a6321;
    }
    // 004a631c  26881e                 -mov byte ptr es:[esi], bl
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.bl;
    // 004a631f  eb4c                   -jmp 0x4a636d
    goto L_0x004a636d;
L_0x004a6321:
    // 004a6321  8b2d90805b00           -mov ebp, dword ptr [0x5b8090]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
    // 004a6327  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 004a632b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a632d  741e                   -je 0x4a634d
    if (cpu.flags.zf)
    {
        goto L_0x004a634d;
    }
    // 004a632f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6331  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004a6333  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004a6339  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a633b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a6340  740b                   -je 0x4a634d
    if (cpu.flags.zf)
    {
        goto L_0x004a634d;
    }
    // 004a6342  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6344  e898faffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a6349  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x004a634d:
    // 004a634d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a6352  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a6356  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a6358  e8cd0a0100             -call 0x4b6e2a
    cpu.esp -= 4;
    sub_4b6e2a(app, cpu);
    if (cpu.terminate) return;
    // 004a635d  83f8ff                 +cmp eax, -1
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
    // 004a6360  7504                   -jne 0x4a6366
    if (!cpu.flags.zf)
    {
        goto L_0x004a6366;
    }
    // 004a6362  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a6364  eb59                   -jmp 0x4a63bf
    goto L_0x004a63bf;
L_0x004a6366:
    // 004a6366  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a6369  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
L_0x004a636d:
    // 004a636d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a636f  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6373  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a6375:
    // 004a6375  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6377  e8e4080000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a637c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a637e  83f8ff                 +cmp eax, -1
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
    // 004a6381  741d                   -je 0x4a63a0
    if (cpu.flags.zf)
    {
        goto L_0x004a63a0;
    }
    // 004a6383  fec0                   -inc al
    (cpu.al)++;
    // 004a6385  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a638a  f68028cd4d0002         +test byte ptr [eax + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a6391  0f8476ffffff           -je 0x4a630d
    if (cpu.flags.zf)
    {
        goto L_0x004a630d;
    }
L_0x004a6397:
    // 004a6397  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a6399  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a639b  e848faffff             -call 0x4a5de8
    cpu.esp -= 4;
    sub_4a5de8(app, cpu);
    if (cpu.terminate) return;
L_0x004a63a0:
    // 004a63a0  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a63a4  7417                   -je 0x4a63bd
    if (cpu.flags.zf)
    {
        goto L_0x004a63bd;
    }
    // 004a63a6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a63a8  7e13                   -jle 0x4a63bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a63bd;
    }
    // 004a63aa  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a63af  7506                   -jne 0x4a63b7
    if (!cpu.flags.zf)
    {
        goto L_0x004a63b7;
    }
    // 004a63b1  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
    // 004a63b5  eb06                   -jmp 0x4a63bd
    goto L_0x004a63bd;
L_0x004a63b7:
    // 004a63b7  6626c7060000           -mov word ptr es:[esi], 0
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x004a63bd:
    // 004a63bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a63bf:
    // 004a63bf  83c40c                 +add esp, 0xc
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
    // 004a63c2  e9a6feffff             -jmp 0x4a626d
    return sub_4a626d(app, cpu);
}

/* align: skip  */
void Application::sub_4a63c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a63c7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a63c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a63c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a63ca  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a63cb  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a63ce  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004a63d1  744d                   -je 0x4a6420
    if (cpu.flags.zf)
    {
        goto L_0x004a6420;
    }
    // 004a63d3  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004a63d6  740c                   -je 0x4a63e4
    if (cpu.flags.zf)
    {
        goto L_0x004a63e4;
    }
    // 004a63d8  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a63da  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a63dd  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004a63df  c457f8                 -les edx, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 004a63e2  eb25                   -jmp 0x4a6409
    goto L_0x004a6409;
L_0x004a63e4:
    // 004a63e4  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004a63e7  7410                   -je 0x4a63f9
    if (cpu.flags.zf)
    {
        goto L_0x004a63f9;
    }
    // 004a63e9  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a63eb  83c604                 +add esi, 4
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
    // 004a63ee  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 004a63f0  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a63f2  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004a63f4  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004a63f7  eb10                   -jmp 0x4a6409
    goto L_0x004a6409;
L_0x004a63f9:
    // 004a63f9  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a63fb  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a63fe  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004a6400  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a6402  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 004a6404  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004a6406  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x004a6409:
    // 004a6409  8a6810                 -mov ch, byte ptr [eax + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a640c  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004a640f  7409                   -je 0x4a641a
    if (cpu.flags.zf)
    {
        goto L_0x004a641a;
    }
    // 004a6411  6626891a               -mov word ptr es:[edx], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.bx;
    // 004a6415  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a6416  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6417  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6418  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6419  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a641a:
    // 004a641a  f6c520                 -test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004a641d  26891a                 -mov dword ptr es:[edx], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.ebx;
L_0x004a6420:
    // 004a6420  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a6421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6423  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6424  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6425(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6425  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6426  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6427  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6428  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a642a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a642c  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004a6431  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6433  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6435  e83571feff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004a643a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a643c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a643e  41                     -inc ecx
    (cpu.ecx)++;
    // 004a643f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6441  741f                   -je 0x4a6462
    if (cpu.flags.zf)
    {
        goto L_0x004a6462;
    }
L_0x004a6443:
    // 004a6443  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6445  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a6448  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 004a644b  8a80accb4d00           -mov al, byte ptr [eax + 0x4dcbac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098412) /* 0x4dcbac */);
    // 004a6451  080432                 -or byte ptr [edx + esi], al
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) |= x86::reg8(x86::sreg8(cpu.al));
    // 004a6454  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6456  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a6458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a645a  7406                   -je 0x4a6462
    if (cpu.flags.zf)
    {
        goto L_0x004a6462;
    }
    // 004a645c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a645d  83f85d                 +cmp eax, 0x5d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6460  75e1                   -jne 0x4a6443
    if (!cpu.flags.zf)
    {
        goto L_0x004a6443;
    }
L_0x004a6462:
    // 004a6462  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6464  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6465  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6466  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6467  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6468(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6468  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6469  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a646a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a646b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a646c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a646d  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a6470  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6472  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a6474  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6476  80385e                 +cmp byte ptr [eax], 0x5e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6479  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 004a647c  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a6482  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a6486  7403                   -je 0x4a648b
    if (cpu.flags.zf)
    {
        goto L_0x004a648b;
    }
    // 004a6488  40                     -inc eax
    (cpu.eax)++;
    // 004a6489  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004a648b:
    // 004a648b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a648d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a648f  e891ffffff             -call 0x4a6425
    cpu.esp -= 4;
    sub_4a6425(app, cpu);
    if (cpu.terminate) return;
    // 004a6494  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a6496  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6499  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004a649c  7434                   -je 0x4a64d2
    if (cpu.flags.zf)
    {
        goto L_0x004a64d2;
    }
    // 004a649e  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004a64a1  740c                   -je 0x4a64af
    if (cpu.flags.zf)
    {
        goto L_0x004a64af;
    }
    // 004a64a3  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 004a64a5  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a64a8  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 004a64aa  c476f8                 -les esi, ptr [esi - 8]
    NFS2_ASSERT(false);
    // 004a64ad  eb23                   -jmp 0x4a64d2
    goto L_0x004a64d2;
L_0x004a64af:
    // 004a64af  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004a64b2  7410                   -je 0x4a64c4
    if (cpu.flags.zf)
    {
        goto L_0x004a64c4;
    }
    // 004a64b4  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a64b6  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a64b9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a64bb  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004a64bd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a64bf  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a64c2  eb0e                   -jmp 0x4a64d2
    goto L_0x004a64d2;
L_0x004a64c4:
    // 004a64c4  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a64c6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a64c9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a64cb  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004a64cd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a64cf  8b72fc                 -mov esi, dword ptr [edx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x004a64d2:
    // 004a64d2  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a64d5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a64d7:
    // 004a64d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a64d9  766a                   -jbe 0x4a6545
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6545;
    }
    // 004a64db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a64dd  e8fff8ffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a64e2  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a64e5  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a64e9  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004a64ec  7557                   -jne 0x4a6545
    if (!cpu.flags.zf)
    {
        goto L_0x004a6545;
    }
    // 004a64ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a64f0  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004a64f3  8a1c1c                 -mov bl, byte ptr [esp + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.ebx * 1);
    // 004a64f6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a64fc  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a6500  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6502  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a6505  8a9baccb4d00           -mov bl, byte ptr [ebx + 0x4dcbac]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5098412) /* 0x4dcbac */);
    // 004a650b  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a650f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6515  85eb                   +test ebx, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebp));
    // 004a6517  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 004a651a  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a651e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6524  39eb                   +cmp ebx, ebp
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
    // 004a6526  7409                   -je 0x4a6531
    if (cpu.flags.zf)
    {
        goto L_0x004a6531;
    }
    // 004a6528  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a652a  e8b9f8ffff             -call 0x4a5de8
    cpu.esp -= 4;
    sub_4a5de8(app, cpu);
    if (cpu.terminate) return;
    // 004a652f  eb14                   -jmp 0x4a6545
    goto L_0x004a6545;
L_0x004a6531:
    // 004a6531  47                     -inc edi
    (cpu.edi)++;
    // 004a6532  8a7910                 -mov bh, byte ptr [ecx + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6535  4a                     -dec edx
    (cpu.edx)--;
    // 004a6536  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004a6539  749c                   -je 0x4a64d7
    if (cpu.flags.zf)
    {
        goto L_0x004a64d7;
    }
    // 004a653b  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a653f  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 004a6542  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6543  eb92                   -jmp 0x4a64d7
    goto L_0x004a64d7;
L_0x004a6545:
    // 004a6545  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a6549  7408                   -je 0x4a6553
    if (cpu.flags.zf)
    {
        goto L_0x004a6553;
    }
    // 004a654b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a654d  7e04                   -jle 0x4a6553
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6553;
    }
    // 004a654f  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x004a6553:
    // 004a6553  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6555  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a6558  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6559  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a655a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a655b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a655c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a655d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a655e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a655e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a655f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6560  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6561  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6562  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6563  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6564  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a6567  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6569  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 004a656d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a656f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a6571  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
L_0x004a6575:
    // 004a6575  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6577  e865f8ffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a657c  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004a657e  fec2                   -inc dl
    (cpu.dl)++;
    // 004a6580  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 004a6583  8a9528cd4d00           -mov dl, byte ptr [ebp + 0x4dcd28]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5098792) /* 0x4dcd28 */);
    // 004a6589  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a658b  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004a658e  7406                   -je 0x4a6596
    if (cpu.flags.zf)
    {
        goto L_0x004a6596;
    }
    // 004a6590  ff442468               +inc dword ptr [esp + 0x68]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6594  ebdf                   -jmp 0x4a6575
    goto L_0x004a6575;
L_0x004a6596:
    // 004a6596  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a659a  0f85d7010000           -jne 0x4a6777
    if (!cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
    // 004a65a0  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a65a3  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a65a6  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004a65a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a65ab  0f84bd010000           -je 0x4a676e
    if (cpu.flags.zf)
    {
        goto L_0x004a676e;
    }
    // 004a65b1  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a65b4  7405                   -je 0x4a65bb
    if (cpu.flags.zf)
    {
        goto L_0x004a65bb;
    }
    // 004a65b6  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a65b9  751e                   -jne 0x4a65d9
    if (!cpu.flags.zf)
    {
        goto L_0x004a65d9;
    }
L_0x004a65bb:
    // 004a65bb  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004a65bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a65c1  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a65c3  e898060000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a65c8  43                     -inc ebx
    (cpu.ebx)++;
    // 004a65c9  45                     -inc ebp
    (cpu.ebp)++;
    // 004a65ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a65cc  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 004a65d0  83f8ff                 +cmp eax, -1
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
    // 004a65d3  0f849e010000           -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
L_0x004a65d9:
    // 004a65d9  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004a65db  fec0                   -inc al
    (cpu.al)++;
    // 004a65dd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a65e2  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a65e9  7509                   -jne 0x4a65f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a65f4;
    }
    // 004a65eb  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a65ee  0f857a010000           -jne 0x4a676e
    if (!cpu.flags.zf)
    {
        goto L_0x004a676e;
    }
L_0x004a65f4:
    // 004a65f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a65f6  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004a65fa  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004a65fc  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a65fe  fec0                   -inc al
    (cpu.al)++;
    // 004a6600  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6605  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a660c  7441                   -je 0x4a664f
    if (cpu.flags.zf)
    {
        goto L_0x004a664f;
    }
    // 004a660e  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x004a6613:
    // 004a6613  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a6615  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a6618  43                     -inc ebx
    (cpu.ebx)++;
    // 004a6619  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a661b  740f                   -je 0x4a662c
    if (cpu.flags.zf)
    {
        goto L_0x004a662c;
    }
    // 004a661d  6b4424660a             -imul eax, dword ptr [esp + 0x66], 0xa
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(102) /* 0x66 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004a6622  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6624  83e930                 -sub ecx, 0x30
    (cpu.ecx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a6627  66894c2466             -mov word ptr [esp + 0x66], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.cx;
L_0x004a662c:
    // 004a662c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a662e  47                     -inc edi
    (cpu.edi)++;
    // 004a662f  e82c060000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6634  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6636  83f8ff                 +cmp eax, -1
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
    // 004a6639  0f8438010000           -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
    // 004a663f  fec0                   -inc al
    (cpu.al)++;
    // 004a6641  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6646  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a664d  75c4                   -jne 0x4a6613
    if (!cpu.flags.zf)
    {
        goto L_0x004a6613;
    }
L_0x004a664f:
    // 004a664f  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6652  0f8598000000           -jne 0x4a66f0
    if (!cpu.flags.zf)
    {
        goto L_0x004a66f0;
    }
    // 004a6658  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a665a  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a665c  e8ff050000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6661  43                     -inc ebx
    (cpu.ebx)++;
    // 004a6662  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6664  83f8ff                 +cmp eax, -1
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
    // 004a6667  0f840a010000           -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
    // 004a666d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a666f  7514                   -jne 0x4a6685
    if (!cpu.flags.zf)
    {
        goto L_0x004a6685;
    }
    // 004a6671  fec0                   -inc al
    (cpu.al)++;
    // 004a6673  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6678  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a667f  0f84e9000000           -je 0x4a676e
    if (cpu.flags.zf)
    {
        goto L_0x004a676e;
    }
L_0x004a6685:
    // 004a6685  47                     -inc edi
    (cpu.edi)++;
L_0x004a6686:
    // 004a6686  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004a6688  fec0                   -inc al
    (cpu.al)++;
    // 004a668a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a668f  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a6696  7412                   -je 0x4a66aa
    if (cpu.flags.zf)
    {
        goto L_0x004a66aa;
    }
    // 004a6698  47                     -inc edi
    (cpu.edi)++;
    // 004a6699  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a669b  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a669d  e8be050000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a66a2  43                     -inc ebx
    (cpu.ebx)++;
    // 004a66a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a66a5  83f8ff                 +cmp eax, -1
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
    // 004a66a8  75dc                   -jne 0x4a6686
    if (!cpu.flags.zf)
    {
        goto L_0x004a6686;
    }
L_0x004a66aa:
    // 004a66aa  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004a66ae  7437                   -je 0x4a66e7
    if (cpu.flags.zf)
    {
        goto L_0x004a66e7;
    }
    // 004a66b0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a66b2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a66b4  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x004a66b8:
    // 004a66b8  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a66b9  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a66bc  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a66be  741e                   -je 0x4a66de
    if (cpu.flags.zf)
    {
        goto L_0x004a66de;
    }
    // 004a66c0  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004a66c2  c744245c0a000000       -mov dword ptr [esp + 0x5c], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 10 /*0xa*/;
    // 004a66ca  88442462               -mov byte ptr [esp + 0x62], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.al;
    // 004a66ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a66d0  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a66d4  f774245c               +div dword ptr [esp + 0x5c]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a66d8  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004a66dc  ebda                   -jmp 0x4a66b8
    goto L_0x004a66b8;
L_0x004a66de:
    // 004a66de  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a66e2  6689442464             -mov word ptr [esp + 0x64], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ax;
L_0x004a66e7:
    // 004a66e7  83f9ff                 +cmp ecx, -1
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
    // 004a66ea  0f8487000000           -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
L_0x004a66f0:
    // 004a66f0  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004a66f4  0f8574000000           -jne 0x4a676e
    if (!cpu.flags.zf)
    {
        goto L_0x004a676e;
    }
    // 004a66fa  83f965                 +cmp ecx, 0x65
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a66fd  7409                   -je 0x4a6708
    if (cpu.flags.zf)
    {
        goto L_0x004a6708;
    }
    // 004a66ff  83f945                 +cmp ecx, 0x45
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6702  0f8566000000           -jne 0x4a676e
    if (!cpu.flags.zf)
    {
        goto L_0x004a676e;
    }
L_0x004a6708:
    // 004a6708  47                     -inc edi
    (cpu.edi)++;
    // 004a6709  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a670b  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a670d  e84e050000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6712  43                     -inc ebx
    (cpu.ebx)++;
    // 004a6713  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6715  83f8ff                 +cmp eax, -1
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
    // 004a6718  745d                   -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
    // 004a671a  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a671d  7405                   -je 0x4a6724
    if (cpu.flags.zf)
    {
        goto L_0x004a6724;
    }
    // 004a671f  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6722  7512                   -jne 0x4a6736
    if (!cpu.flags.zf)
    {
        goto L_0x004a6736;
    }
L_0x004a6724:
    // 004a6724  47                     -inc edi
    (cpu.edi)++;
    // 004a6725  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6727  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a6729  e832050000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a672e  43                     -inc ebx
    (cpu.ebx)++;
    // 004a672f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6731  83f8ff                 +cmp eax, -1
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
    // 004a6734  7441                   -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
L_0x004a6736:
    // 004a6736  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004a6738  fec0                   -inc al
    (cpu.al)++;
    // 004a673a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a673f  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a6746  7504                   -jne 0x4a674c
    if (!cpu.flags.zf)
    {
        goto L_0x004a674c;
    }
    // 004a6748  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a674a  eb22                   -jmp 0x4a676e
    goto L_0x004a676e;
L_0x004a674c:
    // 004a674c  47                     -inc edi
    (cpu.edi)++;
    // 004a674d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a674f  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a6751  e80a050000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6756  43                     -inc ebx
    (cpu.ebx)++;
    // 004a6757  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6759  83f8ff                 +cmp eax, -1
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
    // 004a675c  7419                   -je 0x4a6777
    if (cpu.flags.zf)
    {
        goto L_0x004a6777;
    }
    // 004a675e  fec0                   -inc al
    (cpu.al)++;
    // 004a6760  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6765  f68028cd4d0020         +test byte ptr [eax + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 004a676c  75de                   -jne 0x4a674c
    if (!cpu.flags.zf)
    {
        goto L_0x004a674c;
    }
L_0x004a676e:
    // 004a676e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a6770  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6772  e871f6ffff             -call 0x4a5de8
    cpu.esp -= 4;
    sub_4a5de8(app, cpu);
    if (cpu.terminate) return;
L_0x004a6777:
    // 004a6777  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a6779  0f8eab000000           -jle 0x4a682a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a682a;
    }
    // 004a677f  037c2468               -add edi, dword ptr [esp + 0x68]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 004a6783  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a6787  0f849d000000           -je 0x4a682a
    if (cpu.flags.zf)
    {
        goto L_0x004a682a;
    }
    // 004a678d  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004a6790  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004a6794  740c                   -je 0x4a67a2
    if (cpu.flags.zf)
    {
        goto L_0x004a67a2;
    }
    // 004a6796  803c242d               +cmp byte ptr [esp], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a679a  7512                   -jne 0x4a67ae
    if (!cpu.flags.zf)
    {
        goto L_0x004a67ae;
    }
    // 004a679c  f75c2464               +neg dword ptr [esp + 0x64]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004a67a0  eb0c                   -jmp 0x4a67ae
    goto L_0x004a67ae;
L_0x004a67a2:
    // 004a67a2  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004a67a6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a67a8  ff156ce54d00           -call dword ptr [0x4de56c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105004) /* 0x4de56c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a67ae:
    // 004a67ae  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a67b1  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004a67b4  7410                   -je 0x4a67c6
    if (cpu.flags.zf)
    {
        goto L_0x004a67c6;
    }
    // 004a67b6  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a67ba  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a67bc  83c108                 +add ecx, 8
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
    // 004a67bf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a67c1  c459f8                 -les ebx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 004a67c4  eb2b                   -jmp 0x4a67f1
    goto L_0x004a67f1;
L_0x004a67c6:
    // 004a67c6  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004a67c9  7414                   -je 0x4a67df
    if (cpu.flags.zf)
    {
        goto L_0x004a67df;
    }
    // 004a67cb  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a67cf  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a67d1  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a67d4  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a67d6  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a67d8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a67da  8b5bfc                 -mov ebx, dword ptr [ebx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a67dd  eb12                   -jmp 0x4a67f1
    goto L_0x004a67f1;
L_0x004a67df:
    // 004a67df  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a67e3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a67e5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a67e8  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a67ea  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a67ec  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a67ee  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x004a67f1:
    // 004a67f1  8a7610                 -mov dh, byte ptr [esi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a67f4  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004a67f7  7406                   -je 0x4a67ff
    if (cpu.flags.zf)
    {
        goto L_0x004a67ff;
    }
    // 004a67f9  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004a67fd  eb28                   -jmp 0x4a6827
    goto L_0x004a6827;
L_0x004a67ff:
    // 004a67ff  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004a6802  7505                   -jne 0x4a6809
    if (!cpu.flags.zf)
    {
        goto L_0x004a6809;
    }
    // 004a6804  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004a6807  7411                   -je 0x4a681a
    if (cpu.flags.zf)
    {
        goto L_0x004a681a;
    }
L_0x004a6809:
    // 004a6809  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004a680d  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
    // 004a6810  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a6814  26894304               -mov dword ptr es:[ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a6818  eb10                   -jmp 0x4a682a
    goto L_0x004a682a;
L_0x004a681a:
    // 004a681a  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004a681e  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a6822  e8a9060100             -call 0x4b6ed0
    cpu.esp -= 4;
    sub_4b6ed0(app, cpu);
    if (cpu.terminate) return;
L_0x004a6827:
    // 004a6827  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
L_0x004a682a:
    // 004a682a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a682c  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a682f  e939faffff             -jmp 0x4a626d
    return sub_4a626d(app, cpu);
}

/* align: skip  */
void Application::sub_4a6834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6834  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6835  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6836  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6837  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6838  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a683b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a683d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a6841  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004a6845  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6847  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a6849  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a684d  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a6851  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a6855  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004a6859:
    // 004a6859  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a685b  e881f5ffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a6860  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a6864  8a5c242c               -mov bl, byte ptr [esp + 0x2c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a6868  fec3                   -inc bl
    (cpu.bl)++;
    // 004a686a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6870  f68328cd4d0002         +test byte ptr [ebx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 004a6877  7406                   -je 0x4a687f
    if (cpu.flags.zf)
    {
        goto L_0x004a687f;
    }
    // 004a6879  ff442420               +inc dword ptr [esp + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a687d  ebda                   -jmp 0x4a6859
    goto L_0x004a6859;
L_0x004a687f:
    // 004a687f  f6471002               +test byte ptr [edi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a6883  0f8590020000           -jne 0x4a6b19
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a6889  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a688c  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004a688f  89770c                 -mov dword ptr [edi + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004a6892  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a6894  0f8474020000           -je 0x4a6b0e
    if (cpu.flags.zf)
    {
        goto L_0x004a6b0e;
    }
    // 004a689a  bb2b000000             -mov ebx, 0x2b
    cpu.ebx = 43 /*0x2b*/;
    // 004a689f  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a68a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a68a5  742e                   -je 0x4a68d5
    if (cpu.flags.zf)
    {
        goto L_0x004a68d5;
    }
    // 004a68a7  39d8                   +cmp eax, ebx
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
    // 004a68a9  7405                   -je 0x4a68b0
    if (cpu.flags.zf)
    {
        goto L_0x004a68b0;
    }
    // 004a68ab  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a68ae  7525                   -jne 0x4a68d5
    if (!cpu.flags.zf)
    {
        goto L_0x004a68d5;
    }
L_0x004a68b0:
    // 004a68b0  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a68b4  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a68b8  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a68bc  41                     -inc ecx
    (cpu.ecx)++;
    // 004a68bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a68bf  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004a68c3  e898030000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a68c8  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a68cc  83f8ff                 +cmp eax, -1
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
    // 004a68cf  0f8444020000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
L_0x004a68d5:
    // 004a68d5  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a68d9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a68db  0f8569000000           -jne 0x4a694a
    if (!cpu.flags.zf)
    {
        goto L_0x004a694a;
    }
    // 004a68e1  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a68e6  7558                   -jne 0x4a6940
    if (!cpu.flags.zf)
    {
        goto L_0x004a6940;
    }
    // 004a68e8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a68ea  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a68ef  e86c030000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a68f4  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a68f8  83f8ff                 +cmp eax, -1
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
    // 004a68fb  0f8418020000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a6901  83f878                 +cmp eax, 0x78
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
    // 004a6904  7405                   -je 0x4a690b
    if (cpu.flags.zf)
    {
        goto L_0x004a690b;
    }
    // 004a6906  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6909  752b                   -jne 0x4a6936
    if (!cpu.flags.zf)
    {
        goto L_0x004a6936;
    }
L_0x004a690b:
    // 004a690b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a690d  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a6911  e84a030000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6916  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a6918  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a691b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a691f  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a6923  83f8ff                 +cmp eax, -1
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
    // 004a6926  0f84ed010000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a692c  c744242810000000       -mov dword ptr [esp + 0x28], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 16 /*0x10*/;
    // 004a6934  eb64                   -jmp 0x4a699a
    goto L_0x004a699a;
L_0x004a6936:
    // 004a6936  c744242808000000       -mov dword ptr [esp + 0x28], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 004a693e  eb5a                   -jmp 0x4a699a
    goto L_0x004a699a;
L_0x004a6940:
    // 004a6940  c74424280a000000       -mov dword ptr [esp + 0x28], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 10 /*0xa*/;
    // 004a6948  eb50                   -jmp 0x4a699a
    goto L_0x004a699a;
L_0x004a694a:
    // 004a694a  83fe10                 +cmp esi, 0x10
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
    // 004a694d  754b                   -jne 0x4a699a
    if (!cpu.flags.zf)
    {
        goto L_0x004a699a;
    }
    // 004a694f  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6954  7544                   -jne 0x4a699a
    if (!cpu.flags.zf)
    {
        goto L_0x004a699a;
    }
    // 004a6956  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6958  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a695d  e8fe020000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6962  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a6966  83f8ff                 +cmp eax, -1
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
    // 004a6969  0f84aa010000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a696f  83f878                 +cmp eax, 0x78
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
    // 004a6972  7405                   -je 0x4a6979
    if (cpu.flags.zf)
    {
        goto L_0x004a6979;
    }
    // 004a6974  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6977  7521                   -jne 0x4a699a
    if (!cpu.flags.zf)
    {
        goto L_0x004a699a;
    }
L_0x004a6979:
    // 004a6979  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a697b  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a697f  e8dc020000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6984  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a6986  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a6989  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a698d  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a6991  83f8ff                 +cmp eax, -1
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
    // 004a6994  0f847f010000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
L_0x004a699a:
    // 004a699a  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 004a699e  0f84ff000000           -je 0x4a6aa3
    if (cpu.flags.zf)
    {
        goto L_0x004a6aa3;
    }
    // 004a69a4  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a69a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a69aa  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a69ae  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004a69b2:
    // 004a69b2  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a69b6  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a69ba  e87a020000             -call 0x4a6c39
    cpu.esp -= 4;
    sub_4a6c39(app, cpu);
    if (cpu.terminate) return;
    // 004a69bf  39d0                   +cmp eax, edx
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
    // 004a69c1  7d5d                   -jge 0x4a6a20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6a20;
    }
    // 004a69c3  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a69c7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a69ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a69cc  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a69d0  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a69d4  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a69d8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a69db  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a69dd  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a69e0  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a69e2  e835050100             -call 0x4b6f1c
    cpu.esp -= 4;
    sub_4b6f1c(app, cpu);
    if (cpu.terminate) return;
    // 004a69e7  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a69ea  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a69ec  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a69f0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a69f2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a69f6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a69f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a69fb  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a69fe  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6a00  01d8                   +add eax, ebx
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
    // 004a6a02  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004a6a04  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a6a07  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a6a09  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6a0b  45                     -inc ebp
    (cpu.ebp)++;
    // 004a6a0c  e84f020000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6a11  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a6a15  83f8ff                 +cmp eax, -1
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
    // 004a6a18  0f84fb000000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a6a1e  eb92                   -jmp 0x4a69b2
    goto L_0x004a69b2;
L_0x004a6a20:
    // 004a6a20  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6a25  0f85e3000000           -jne 0x4a6b0e
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b0e;
    }
    // 004a6a2b  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 004a6a2f  0f84d9000000           -je 0x4a6b0e
    if (cpu.flags.zf)
    {
        goto L_0x004a6b0e;
    }
L_0x004a6a35:
    // 004a6a35  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6a37  45                     -inc ebp
    (cpu.ebp)++;
    // 004a6a38  e823020000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6a3d  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a6a41  83f8ff                 +cmp eax, -1
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
    // 004a6a44  0f84cf000000           -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a6a4a  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a6a4e  e8e6010000             -call 0x4a6c39
    cpu.esp -= 4;
    sub_4a6c39(app, cpu);
    if (cpu.terminate) return;
    // 004a6a53  39f0                   +cmp eax, esi
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
    // 004a6a55  0f8db3000000           -jge 0x4a6b0e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6b0e;
    }
    // 004a6a5b  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6a5f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a6a62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6a64  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6a68  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a6a6c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6a70  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a6a73  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6a75  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6a78  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6a7a  e89d040100             -call 0x4b6f1c
    cpu.esp -= 4;
    sub_4b6f1c(app, cpu);
    if (cpu.terminate) return;
    // 004a6a7f  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a6a82  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a6a84  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6a88  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a6a8a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6a8e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a6a91  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6a93  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6a96  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6a98  01d8                   +add eax, ebx
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
    // 004a6a9a  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6a9c  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a6a9f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a6aa1  eb92                   -jmp 0x4a6a35
    goto L_0x004a6a35;
L_0x004a6aa3:
    // 004a6aa3  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x004a6aa7:
    // 004a6aa7  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a6aab  e889010000             -call 0x4a6c39
    cpu.esp -= 4;
    sub_4a6c39(app, cpu);
    if (cpu.terminate) return;
    // 004a6ab0  39f0                   +cmp eax, esi
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
    // 004a6ab2  7d20                   -jge 0x4a6ad4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6ad4;
    }
    // 004a6ab4  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a6ab8  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a6abb  45                     -inc ebp
    (cpu.ebp)++;
    // 004a6abc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6abe  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6ac0  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004a6ac4  e897010000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6ac9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a6acd  83f8ff                 +cmp eax, -1
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
    // 004a6ad0  7447                   -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a6ad2  ebd3                   -jmp 0x4a6aa7
    goto L_0x004a6aa7;
L_0x004a6ad4:
    // 004a6ad4  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6ad9  7533                   -jne 0x4a6b0e
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b0e;
    }
    // 004a6adb  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 004a6adf  742d                   -je 0x4a6b0e
    if (cpu.flags.zf)
    {
        goto L_0x004a6b0e;
    }
    // 004a6ae1  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x004a6ae5:
    // 004a6ae5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6ae7  45                     -inc ebp
    (cpu.ebp)++;
    // 004a6ae8  e873010000             -call 0x4a6c60
    cpu.esp -= 4;
    sub_4a6c60(app, cpu);
    if (cpu.terminate) return;
    // 004a6aed  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a6af1  83f8ff                 +cmp eax, -1
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
    // 004a6af4  7423                   -je 0x4a6b19
    if (cpu.flags.zf)
    {
        goto L_0x004a6b19;
    }
    // 004a6af6  e83e010000             -call 0x4a6c39
    cpu.esp -= 4;
    sub_4a6c39(app, cpu);
    if (cpu.terminate) return;
    // 004a6afb  39c8                   +cmp eax, ecx
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
    // 004a6afd  7d0f                   -jge 0x4a6b0e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6b0e;
    }
    // 004a6aff  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a6b03  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a6b06  01c3                   +add ebx, eax
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
    // 004a6b08  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004a6b0c  ebd7                   -jmp 0x4a6ae5
    goto L_0x004a6ae5;
L_0x004a6b0e:
    // 004a6b0e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a6b12  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a6b14  e8cff2ffff             -call 0x4a5de8
    cpu.esp -= 4;
    sub_4a5de8(app, cpu);
    if (cpu.terminate) return;
L_0x004a6b19:
    // 004a6b19  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 004a6b1d  0f8492000000           -je 0x4a6bb5
    if (cpu.flags.zf)
    {
        goto L_0x004a6bb5;
    }
    // 004a6b23  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6b28  7524                   -jne 0x4a6b4e
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b4e;
    }
    // 004a6b2a  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6b2e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6b32  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 004a6b34  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004a6b36  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a6b3a  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6b3d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a6b41  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a6b45  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a6b47  7501                   -jne 0x4a6b4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b4a;
    }
    // 004a6b49  40                     -inc eax
    (cpu.eax)++;
L_0x004a6b4a:
    // 004a6b4a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004a6b4e:
    // 004a6b4e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a6b50  0f8ed9000000           -jle 0x4a6c2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6c2f;
    }
    // 004a6b56  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a6b5a  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a6b5d  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6b5f  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004a6b62  0f84c7000000           -je 0x4a6c2f
    if (cpu.flags.zf)
    {
        goto L_0x004a6c2f;
    }
    // 004a6b68  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004a6b6b  7414                   -je 0x4a6b81
    if (cpu.flags.zf)
    {
        goto L_0x004a6b81;
    }
    // 004a6b6d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a6b71  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6b73  83c208                 +add edx, 8
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
    // 004a6b76  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a6b78  668b42fc               -mov ax, word ptr [edx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a6b7c  8b7af8                 -mov edi, dword ptr [edx - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004a6b7f  eb27                   -jmp 0x4a6ba8
    goto L_0x004a6ba8;
L_0x004a6b81:
    // 004a6b81  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 004a6b84  7412                   -je 0x4a6b98
    if (cpu.flags.zf)
    {
        goto L_0x004a6b98;
    }
    // 004a6b86  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a6b8a  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6b8c  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b8f  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004a6b91  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a6b93  8b7ffc                 -mov edi, dword ptr [edi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004a6b96  eb10                   -jmp 0x4a6ba8
    goto L_0x004a6ba8;
L_0x004a6b98:
    // 004a6b98  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a6b9c  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6b9e  83c604                 +add esi, 4
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
    // 004a6ba1  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004a6ba3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a6ba5  8b7efc                 -mov edi, dword ptr [esi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x004a6ba8:
    // 004a6ba8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6bac  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a6bae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a6baf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a6bb0  e97a000000             -jmp 0x4a6c2f
    goto L_0x004a6c2f;
L_0x004a6bb5:
    // 004a6bb5  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6bba  7504                   -jne 0x4a6bc0
    if (!cpu.flags.zf)
    {
        goto L_0x004a6bc0;
    }
    // 004a6bbc  f75c2424               -neg dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = ~app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) + 1;
L_0x004a6bc0:
    // 004a6bc0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a6bc2  0f8e67000000           -jle 0x4a6c2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6c2f;
    }
    // 004a6bc8  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a6bcc  8a4710                 -mov al, byte ptr [edi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a6bcf  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6bd1  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a6bd3  745a                   -je 0x4a6c2f
    if (cpu.flags.zf)
    {
        goto L_0x004a6c2f;
    }
    // 004a6bd5  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a6bd7  7410                   -je 0x4a6be9
    if (cpu.flags.zf)
    {
        goto L_0x004a6be9;
    }
    // 004a6bd9  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a6bdd  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6bdf  83c308                 +add ebx, 8
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
    // 004a6be2  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a6be4  c443f8                 -les eax, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 004a6be7  eb2a                   -jmp 0x4a6c13
    goto L_0x004a6c13;
L_0x004a6be9:
    // 004a6be9  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a6beb  7414                   -je 0x4a6c01
    if (cpu.flags.zf)
    {
        goto L_0x004a6c01;
    }
    // 004a6bed  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a6bf1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6bf3  83c204                 +add edx, 4
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
    // 004a6bf6  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 004a6bf8  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a6bfa  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 004a6bfc  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a6bff  eb12                   -jmp 0x4a6c13
    goto L_0x004a6c13;
L_0x004a6c01:
    // 004a6c01  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a6c05  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6c07  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6c0a  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 004a6c0c  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004a6c0e  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 004a6c10  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x004a6c13:
    // 004a6c13  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a6c16  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004a6c19  740a                   -je 0x4a6c25
    if (cpu.flags.zf)
    {
        goto L_0x004a6c25;
    }
    // 004a6c1b  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a6c1f  66268918               -mov word ptr es:[eax], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.eax) = cpu.bx;
    // 004a6c23  eb0a                   -jmp 0x4a6c2f
    goto L_0x004a6c2f;
L_0x004a6c25:
    // 004a6c25  f6c620                 -test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004a6c28  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a6c2c  268918                 -mov dword ptr es:[eax], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.eax) = cpu.ebx;
L_0x004a6c2f:
    // 004a6c2f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a6c31  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a6c34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c35  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a6c36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6c39(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c39  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6c3c  7c09                   -jl 0x4a6c47
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6c47;
    }
    // 004a6c3e  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6c41  7f04                   -jg 0x4a6c47
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6c47;
    }
    // 004a6c43  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a6c46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6c47:
    // 004a6c47  e84ee7ffff             -call 0x4a539a
    cpu.esp -= 4;
    sub_4a539a(app, cpu);
    if (cpu.terminate) return;
    // 004a6c4c  83f861                 +cmp eax, 0x61
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
    // 004a6c4f  7c09                   -jl 0x4a6c5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6c5a;
    }
    // 004a6c51  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6c54  7f04                   -jg 0x4a6c5a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6c5a;
    }
    // 004a6c56  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004a6c59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6c5a:
    // 004a6c5a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004a6c5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6c61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6c62  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6c64  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a6c67  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a6c6a  895a0c                 -mov dword ptr [edx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a6c6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6c6f  740d                   -je 0x4a6c7e
    if (cpu.flags.zf)
    {
        goto L_0x004a6c7e;
    }
    // 004a6c71  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6c73  e869f1ffff             -call 0x4a5de1
    cpu.esp -= 4;
    sub_4a5de1(app, cpu);
    if (cpu.terminate) return;
    // 004a6c78  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004a6c7c  7405                   -je 0x4a6c83
    if (cpu.flags.zf)
    {
        goto L_0x004a6c83;
    }
L_0x004a6c7e:
    // 004a6c7e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004a6c83:
    // 004a6c83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6c86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c86  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6c87  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6c88  2eff159c444c00         -call dword ptr cs:[0x4c449c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998300) /* 0x4c449c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6c8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6c92(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c92  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6c93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6c94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6c95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6c96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6c97  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 004a6c9d  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6ca3  bd81f34c00             -mov ebp, 0x4cf381
    cpu.ebp = 5043073 /*0x4cf381*/;
    // 004a6ca8  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a6cab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a6cad:
    // 004a6cad  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004a6cb4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a6cb6  e8cc1ffeff             -call 0x488c87
    cpu.esp -= 4;
    sub_488c87(app, cpu);
    if (cpu.terminate) return;
    // 004a6cbb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a6cc0  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004a6cc7  41                     -inc ecx
    (cpu.ecx)++;
    // 004a6cc8  e86b020100             -call 0x4b6f38
    cpu.esp -= 4;
    sub_4b6f38(app, cpu);
    if (cpu.terminate) return;
    // 004a6ccd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6ccf  74dc                   -je 0x4a6cad
    if (cpu.flags.zf)
    {
        goto L_0x004a6cad;
    }
    // 004a6cd1  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004a6cd8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a6cda  e82f1dfeff             -call 0x488a0e
    cpu.esp -= 4;
    sub_488a0e(app, cpu);
    if (cpu.terminate) return;
    // 004a6cdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6ce1  751b                   -jne 0x4a6cfe
    if (!cpu.flags.zf)
    {
        goto L_0x004a6cfe;
    }
    // 004a6ce3  e884020100             -call 0x4b6f6c
    cpu.esp -= 4;
    sub_4b6f6c(app, cpu);
    if (cpu.terminate) return;
    // 004a6ce8  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6ceb  740a                   -je 0x4a6cf7
    if (cpu.flags.zf)
    {
        goto L_0x004a6cf7;
    }
    // 004a6ced  e87a020100             -call 0x4b6f6c
    cpu.esp -= 4;
    sub_4b6f6c(app, cpu);
    if (cpu.terminate) return;
    // 004a6cf2  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6cf5  75b6                   -jne 0x4a6cad
    if (!cpu.flags.zf)
    {
        goto L_0x004a6cad;
    }
L_0x004a6cf7:
    // 004a6cf7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a6cf9  e97d000000             -jmp 0x4a6d7b
    goto L_0x004a6d7b;
L_0x004a6cfe:
    // 004a6cfe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6d00  e8221ffeff             -call 0x488c27
    cpu.esp -= 4;
    sub_488c27(app, cpu);
    if (cpu.terminate) return;
    // 004a6d05  8a1d10cb4d00           -mov bl, byte ptr [0x4dcb10]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5098256) /* 0x4dcb10 */);
L_0x004a6d0b:
    // 004a6d0b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a6d0d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a6d0f  e8731ffeff             -call 0x488c87
    cpu.esp -= 4;
    sub_488c87(app, cpu);
    if (cpu.terminate) return;
    // 004a6d14  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a6d16  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004a6d1d  e85e020100             -call 0x4b6f80
    cpu.esp -= 4;
    sub_4b6f80(app, cpu);
    if (cpu.terminate) return;
    // 004a6d22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6d24  7539                   -jne 0x4a6d5f
    if (!cpu.flags.zf)
    {
        goto L_0x004a6d5f;
    }
    // 004a6d26  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a6d28  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a6d2a  e8df1cfeff             -call 0x488a0e
    cpu.esp -= 4;
    sub_488a0e(app, cpu);
    if (cpu.terminate) return;
    // 004a6d2f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6d31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6d33  7420                   -je 0x4a6d55
    if (cpu.flags.zf)
    {
        goto L_0x004a6d55;
    }
    // 004a6d35  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004a6d38  80cc08                 +or ah, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004a6d3b  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004a6d3e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a6d41  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 004a6d44  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6d46  881d10cb4d00           -mov byte ptr [0x4dcb10], bl
    app->getMemory<x86::reg8>(x86::reg32(5098256) /* 0x4dcb10 */) = cpu.bl;
    // 004a6d4c  e8cfb4ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a6d51  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6d53  eb26                   -jmp 0x4a6d7b
    goto L_0x004a6d7b;
L_0x004a6d55:
    // 004a6d55  e812020100             -call 0x4b6f6c
    cpu.esp -= 4;
    sub_4b6f6c(app, cpu);
    if (cpu.terminate) return;
    // 004a6d5a  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6d5d  7498                   -je 0x4a6cf7
    if (cpu.flags.zf)
    {
        goto L_0x004a6cf7;
    }
L_0x004a6d5f:
    // 004a6d5f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a6d64  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004a6d6b  43                     -inc ebx
    (cpu.ebx)++;
    // 004a6d6c  e8c7010100             -call 0x4b6f38
    cpu.esp -= 4;
    sub_4b6f38(app, cpu);
    if (cpu.terminate) return;
    // 004a6d71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6d73  0f8534ffffff           -jne 0x4a6cad
    if (!cpu.flags.zf)
    {
        goto L_0x004a6cad;
    }
    // 004a6d79  eb90                   -jmp 0x4a6d0b
    goto L_0x004a6d0b;
L_0x004a6d7b:
    // 004a6d7b  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 004a6d81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d86  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
