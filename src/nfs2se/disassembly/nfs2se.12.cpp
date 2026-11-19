#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4641b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004641b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004641b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004641b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004641b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004641b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004641b5  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004641b8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004641ba  a140f34d00             -mov eax, dword ptr [0x4df340]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
    // 004641bf  8b3570f34d00           -mov esi, dword ptr [0x4df370]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
    // 004641c5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004641c8  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004641ca  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004641cc  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004641ce  882558375100           -mov byte ptr [0x513758], ah
    app->getMemory<x86::reg8>(x86::reg32(5322584) /* 0x513758 */) = cpu.ah;
    // 004641d4  e8d730feff             -call 0x4472b0
    cpu.esp -= 4;
    sub_4472b0(app, cpu);
    if (cpu.terminate) return;
    // 004641d9  833db0f34d0000         +cmp dword ptr [0x4df3b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004641e0  752f                   -jne 0x464211
    if (!cpu.flags.zf)
    {
        goto L_0x00464211;
    }
L_0x004641e2:
    // 004641e2  833d3437510000         +cmp dword ptr [0x513734], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004641e9  740e                   -je 0x4641f9
    if (cpu.flags.zf)
    {
        goto L_0x004641f9;
    }
    // 004641eb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004641ed  8935bc885100           -mov dword ptr [0x5188bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.esi;
    // 004641f3  893534375100           -mov dword ptr [0x513734], esi
    app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */) = cpu.esi;
L_0x004641f9:
    // 004641f9  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004641fb  e82087ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00464200  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464202  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00464204  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464205  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464206  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464208  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046420b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046420c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046420d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046420e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046420f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464210  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464211:
    // 00464211  833dbcf34d0000         +cmp dword ptr [0x4df3bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464218  7cc8                   -jl 0x4641e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004641e2;
    }
    // 0046421a  a1c0f34d00             -mov eax, dword ptr [0x4df3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */);
    // 0046421f  e81c140000             -call 0x465640
    cpu.esp -= 4;
    sub_465640(app, cpu);
    if (cpu.terminate) return;
    // 00464224  8b3dbcf34d00           -mov edi, dword ptr [0x4df3bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 0046422a  a3c0f34d00             -mov dword ptr [0x4df3c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */) = cpu.eax;
    // 0046422f  83ff04                 +cmp edi, 4
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
    // 00464232  740a                   -je 0x46423e
    if (cpu.flags.zf)
    {
        goto L_0x0046423e;
    }
    // 00464234  e897110000             -call 0x4653d0
    cpu.esp -= 4;
    sub_4653d0(app, cpu);
    if (cpu.terminate) return;
    // 00464239  e892100000             -call 0x4652d0
    cpu.esp -= 4;
    sub_4652d0(app, cpu);
    if (cpu.terminate) return;
L_0x0046423e:
    // 0046423e  833d3437510000         +cmp dword ptr [0x513734], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464245  0f84f2000000           -je 0x46433d
    if (cpu.flags.zf)
    {
        goto L_0x0046433d;
    }
    // 0046424b  3b353c375100           +cmp esi, dword ptr [0x51373c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5322556) /* 0x51373c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464251  0f85e6000000           -jne 0x46433d
    if (!cpu.flags.zf)
    {
        goto L_0x0046433d;
    }
    // 00464257  8b0dc0f34d00           -mov ecx, dword ptr [0x4df3c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */);
    // 0046425d  a138375100             -mov eax, dword ptr [0x513738]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322552) /* 0x513738 */);
    // 00464262  39c8                   +cmp eax, ecx
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
    // 00464264  7542                   -jne 0x4642a8
    if (!cpu.flags.zf)
    {
        goto L_0x004642a8;
    }
    // 00464266  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00464268  8b0dbcf34d00           -mov ecx, dword ptr [0x4df3bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 0046426e  a340375100             -mov dword ptr [0x513740], eax
    app->getMemory<x86::reg32>(x86::reg32(5322560) /* 0x513740 */) = cpu.eax;
    // 00464273  83f904                 +cmp ecx, 4
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
    // 00464276  7518                   -jne 0x464290
    if (!cpu.flags.zf)
    {
        goto L_0x00464290;
    }
    // 00464278  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046427a  e861010000             -call 0x4643e0
    cpu.esp -= 4;
    sub_4643e0(app, cpu);
    if (cpu.terminate) return;
    // 0046427f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464281  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00464283  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464284  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464285  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464287  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046428a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046428b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046428c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046428d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046428e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046428f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464290:
    // 00464290  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464292  e809080000             -call 0x464aa0
    cpu.esp -= 4;
    sub_464aa0(app, cpu);
    if (cpu.terminate) return;
    // 00464297  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464299  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046429b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046429c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046429d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046429f  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004642a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004642a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004642a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004642a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004642a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004642a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004642a8:
    // 004642a8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004642ad  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004642b1  890d38375100           -mov dword ptr [0x513738], ecx
    app->getMemory<x86::reg32>(x86::reg32(5322552) /* 0x513738 */) = cpu.ecx;
    // 004642b7  891d40375100           -mov dword ptr [0x513740], ebx
    app->getMemory<x86::reg32>(x86::reg32(5322560) /* 0x513740 */) = cpu.ebx;
    // 004642bd  e85efeffff             -call 0x464120
    cpu.esp -= 4;
    sub_464120(app, cpu);
    if (cpu.terminate) return;
    // 004642c2  833dbcf34d0004         +cmp dword ptr [0x4df3bc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004642c9  7567                   -jne 0x464332
    if (!cpu.flags.zf)
    {
        goto L_0x00464332;
    }
L_0x004642cb:
    // 004642cb  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004642cf  e8dc010000             -call 0x4644b0
    cpu.esp -= 4;
    sub_4644b0(app, cpu);
    if (cpu.terminate) return;
L_0x004642d4:
    // 004642d4  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004642d8  e843fcffff             -call 0x463f20
    cpu.esp -= 4;
    sub_463f20(app, cpu);
    if (cpu.terminate) return;
    // 004642dd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004642e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004642e2  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004642e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004642e7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004642eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004642ec  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004642f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004642f1  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004642f5  e87685ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 004642fa  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004642fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004642ff  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00464303  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464304  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464308  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464309  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046430d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046430e  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00464312  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464316  e85585ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0046431b  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046431f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464320  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464321  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464323  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00464325  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464326  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464327  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464329  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046432c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046432d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046432e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046432f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464330  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464331  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464332:
    // 00464332  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464336  e8e50b0000             -call 0x464f20
    cpu.esp -= 4;
    sub_464f20(app, cpu);
    if (cpu.terminate) return;
    // 0046433b  eb97                   -jmp 0x4642d4
    goto L_0x004642d4;
L_0x0046433d:
    // 0046433d  a1c0f34d00             -mov eax, dword ptr [0x4df3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */);
    // 00464342  89353c375100           -mov dword ptr [0x51373c], esi
    app->getMemory<x86::reg32>(x86::reg32(5322556) /* 0x51373c */) = cpu.esi;
    // 00464348  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046434a  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046434e  890dbc885100           -mov dword ptr [0x5188bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.ecx;
    // 00464354  a338375100             -mov dword ptr [0x513738], eax
    app->getMemory<x86::reg32>(x86::reg32(5322552) /* 0x513738 */) = cpu.eax;
    // 00464359  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046435e  890d34375100           -mov dword ptr [0x513734], ecx
    app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */) = cpu.ecx;
    // 00464364  e8e70e0000             -call 0x465250
    cpu.esp -= 4;
    sub_465250(app, cpu);
    if (cpu.terminate) return;
    // 00464369  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0046436e  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464372  e8e9080000             -call 0x464c60
    cpu.esp -= 4;
    sub_464c60(app, cpu);
    if (cpu.terminate) return;
    // 00464377  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046437b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046437c  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464380  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464381  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464385  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464386  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046438a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046438b  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046438f  e8dc84ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464394  833db4f34d0000         +cmp dword ptr [0x4df3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108660) /* 0x4df3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046439b  7426                   -je 0x4643c3
    if (cpu.flags.zf)
    {
        goto L_0x004643c3;
    }
    // 0046439d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004643a1  e85a050000             -call 0x464900
    cpu.esp -= 4;
    sub_464900(app, cpu);
    if (cpu.terminate) return;
    // 004643a6  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004643aa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004643ab  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004643af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004643b0  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004643b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004643b5  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004643b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004643ba  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004643be  e8ad84ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
L_0x004643c3:
    // 004643c3  833dbcf34d0004         +cmp dword ptr [0x4df3bc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004643ca  0f84fbfeffff           -je 0x4642cb
    if (cpu.flags.zf)
    {
        goto L_0x004642cb;
    }
    // 004643d0  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004643d4  e8470b0000             -call 0x464f20
    cpu.esp -= 4;
    sub_464f20(app, cpu);
    if (cpu.terminate) return;
    // 004643d9  e9f6feffff             -jmp 0x4642d4
    goto L_0x004642d4;
}

/* align: skip 0x00 0x00 */
void Application::sub_4643e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004643e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004643e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004643e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004643e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004643e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004643e5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004643e8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004643ea  bab4295100             -mov edx, 0x5129b4
    cpu.edx = 5319092 /*0x5129b4*/;
    // 004643ef  b83c295100             -mov eax, 0x51293c
    cpu.eax = 5318972 /*0x51293c*/;
    // 004643f4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004643f6  e8d50a0000             -call 0x464ed0
    cpu.esp -= 4;
    sub_464ed0(app, cpu);
    if (cpu.terminate) return;
    // 004643fb  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00464400  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464404  e857080000             -call 0x464c60
    cpu.esp -= 4;
    sub_464c60(app, cpu);
    if (cpu.terminate) return;
    // 00464409  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046440d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046440e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464412  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464413  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464417  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464418  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046441c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046441d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464421  e84a84ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464426  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046442a  e881000000             -call 0x4644b0
    cpu.esp -= 4;
    sub_4644b0(app, cpu);
    if (cpu.terminate) return;
    // 0046442f  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464433  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464434  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464438  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464439  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046443d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046443e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464442  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464443  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464447  e82484ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0046444c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464450  e8cbfaffff             -call 0x463f20
    cpu.esp -= 4;
    sub_463f20(app, cpu);
    if (cpu.terminate) return;
    // 00464455  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464459  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046445a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046445e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046445f  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464463  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464464  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464468  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464469  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046446d  bac4295100             -mov edx, 0x5129c4
    cpu.edx = 5319108 /*0x5129c4*/;
    // 00464472  e8f983ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464477  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046447b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046447d  e8ce090000             -call 0x464e50
    cpu.esp -= 4;
    sub_464e50(app, cpu);
    if (cpu.terminate) return;
    // 00464482  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464486  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464487  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046448b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046448c  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464490  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464491  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464495  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464496  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046449a  e8d183ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0046449f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004644a1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004644a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004644a4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004644a5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004644a7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004644aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4644b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004644b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004644b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004644b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004644b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004644b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004644b5  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004644bb  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004644bd  bba0f34d00             -mov ebx, 0x4df3a0
    cpu.ebx = 5108640 /*0x4df3a0*/;
    // 004644c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004644c4  ba94f34d00             -mov edx, 0x4df394
    cpu.edx = 5108628 /*0x4df394*/;
    // 004644c9  e83254fdff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 004644ce  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004644d0  e8bbd0fdff             -call 0x441590
    cpu.esp -= 4;
    sub_441590(app, cpu);
    if (cpu.terminate) return;
    // 004644d5  68c8f34d00             -push 0x4df3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108680 /*0x4df3c8*/;
    cpu.esp -= 4;
    // 004644da  68c4f34d00             -push 0x4df3c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108676 /*0x4df3c4*/;
    cpu.esp -= 4;
    // 004644df  b99cf34d00             -mov ecx, 0x4df39c
    cpu.ecx = 5108636 /*0x4df39c*/;
    // 004644e4  bb98f34d00             -mov ebx, 0x4df398
    cpu.ebx = 5108632 /*0x4df398*/;
    // 004644e9  68c0f34d00             -push 0x4df3c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108672 /*0x4df3c0*/;
    cpu.esp -= 4;
    // 004644ee  ba90f34d00             -mov edx, 0x4df390
    cpu.edx = 5108624 /*0x4df390*/;
    // 004644f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004644f5  e836d7fdff             -call 0x441c30
    cpu.esp -= 4;
    sub_441c30(app, cpu);
    if (cpu.terminate) return;
    // 004644fa  a1c0f34d00             -mov eax, dword ptr [0x4df3c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */);
    // 004644ff  8db42400010000         -lea esi, [esp + 0x100]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00464506  e835110000             -call 0x465640
    cpu.esp -= 4;
    sub_465640(app, cpu);
    if (cpu.terminate) return;
    // 0046450b  a3c0f34d00             -mov dword ptr [0x4df3c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */) = cpu.eax;
    // 00464510  e85b010000             -call 0x464670
    cpu.esp -= 4;
    sub_464670(app, cpu);
    if (cpu.terminate) return;
    // 00464515  a198f34d00             -mov eax, dword ptr [0x4df398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108632) /* 0x4df398 */);
    // 0046451a  8a80188f4c00           -mov al, byte ptr [eax + 0x4c8f18]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5017368) /* 0x4c8f18 */);
    // 00464520  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00464525  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464526  68b0d94b00             -push 0x4bd9b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970928 /*0x4bd9b0*/;
    cpu.esp -= 4;
    // 0046452b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046452f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464530  8db42414010000         -lea esi, [esp + 0x114]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00464537  e8a57a0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046453c  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464540  8b1df8295100           -mov ebx, dword ptr [0x5129f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319160) /* 0x5129f8 */);
    // 00464546  8b15f4295100           -mov edx, dword ptr [0x5129f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5319156) /* 0x5129f4 */);
    // 0046454c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046454f  e81c020000             -call 0x464770
    cpu.esp -= 4;
    sub_464770(app, cpu);
    if (cpu.terminate) return;
    // 00464554  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046455b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046455c  8b8c240c010000         -mov ecx, dword ptr [esp + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00464563  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464564  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046456b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046456c  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00464573  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464574  8db42410010000         -lea esi, [esp + 0x110]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0046457b  e8f082ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464580  8b159cf34d00           -mov edx, dword ptr [0x4df39c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108636) /* 0x4df39c */);
    // 00464586  a164f34d00             -mov eax, dword ptr [0x4df364]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108580) /* 0x4df364 */);
    // 0046458b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046458d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00464590  c1e810                 +shr eax, 0x10
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
    // 00464593  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00464595  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464597  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046459a  c1e210                 +shl edx, 0x10
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
    // 0046459d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046459f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004645a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004645a3  68b4d94b00             -push 0x4bd9b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970932 /*0x4bd9b4*/;
    cpu.esp -= 4;
    // 004645a8  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004645ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004645ad  e82f7a0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004645b2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004645b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004645b7  8db42408010000         -lea esi, [esp + 0x108]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004645be  8b1d802a5100           -mov ebx, dword ptr [0x512a80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319296) /* 0x512a80 */);
    // 004645c4  8b157c2a5100           -mov edx, dword ptr [0x512a7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5319292) /* 0x512a7c */);
    // 004645ca  e8a1010000             -call 0x464770
    cpu.esp -= 4;
    sub_464770(app, cpu);
    if (cpu.terminate) return;
    // 004645cf  8bbc240c010000         -mov edi, dword ptr [esp + 0x10c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004645d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004645d7  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004645de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004645df  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004645e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645e7  8b8c240c010000         -mov ecx, dword ptr [esp + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004645ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004645ef  8db42410010000         -lea esi, [esp + 0x110]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004645f6  e87582ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 004645fb  6a3e                   -push 0x3e
    app->getMemory<x86::reg32>(cpu.esp-4) = 62 /*0x3e*/;
    cpu.esp -= 4;
    // 004645fd  68b8d94b00             -push 0x4bd9b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970936 /*0x4bd9b8*/;
    cpu.esp -= 4;
    // 00464602  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464606  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464607  8db42414010000         -lea esi, [esp + 0x114]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0046460e  e8ce790100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00464613  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464617  8b1d882a5100           -mov ebx, dword ptr [0x512a88]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319304) /* 0x512a88 */);
    // 0046461d  8b15842a5100           -mov edx, dword ptr [0x512a84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5319300) /* 0x512a84 */);
    // 00464623  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00464626  e845010000             -call 0x464770
    cpu.esp -= 4;
    sub_464770(app, cpu);
    if (cpu.terminate) return;
    // 0046462b  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00464632  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464633  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046463a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046463b  8bbc240c010000         -mov edi, dword ptr [esp + 0x10c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00464642  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464643  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046464a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046464b  8db42410010000         -lea esi, [esp + 0x110]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00464652  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00464654  e81782ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464659  8db42400010000         -lea esi, [esp + 0x100]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00464660  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464661  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464662  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00464664  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0046466a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046466b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046466c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046466d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046466e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046466f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464673  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464674  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00464677  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00464679  8b156c285100           -mov edx, dword ptr [0x51286c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5318764) /* 0x51286c */);
    // 0046467f  8b3564285100           -mov esi, dword ptr [0x512864]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5318756) /* 0x512864 */);
    // 00464685  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00464687  8b1590f34d00           -mov edx, dword ptr [0x4df390]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108624) /* 0x4df390 */);
    // 0046468d  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00464690  8b0d94f34d00           -mov ecx, dword ptr [0x4df394]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108628) /* 0x4df394 */);
    // 00464696  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464698  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046469b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046469d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046469f  39f0                   +cmp eax, esi
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
    // 004646a1  7e02                   -jle 0x4646a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004646a5;
    }
    // 004646a3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004646a5:
    // 004646a5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004646a7  7d02                   -jge 0x4646ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004646ab;
    }
    // 004646a9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004646ab:
    // 004646ab  e8a081ffff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 004646b0  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004646b5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646b9  e84281ffff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 004646be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004646c0  0f8484000000           -je 0x46474a
    if (cpu.flags.zf)
    {
        goto L_0x0046474a;
    }
    // 004646c6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646ca  c7400403000000         -mov dword ptr [eax + 4], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 3 /*0x3*/;
    // 004646d1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646d5  c6402d80               -mov byte ptr [eax + 0x2d], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(45) /* 0x2d */) = 128 /*0x80*/;
    // 004646d9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646dd  c6402e80               -mov byte ptr [eax + 0x2e], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(46) /* 0x2e */) = 128 /*0x80*/;
    // 004646e1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646e5  c6402f80               -mov byte ptr [eax + 0x2f], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(47) /* 0x2f */) = 128 /*0x80*/;
    // 004646e9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646ed  c74028e82b5100         -mov dword ptr [eax + 0x28], 0x512be8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 5319656 /*0x512be8*/;
    // 004646f4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004646f8  a16c285100             -mov eax, dword ptr [0x51286c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5318764) /* 0x51286c */);
    // 004646fd  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00464700  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464704  a170285100             -mov eax, dword ptr [0x512870]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5318768) /* 0x512870 */);
    // 00464709  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046470c  8b356c285100           -mov esi, dword ptr [0x51286c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5318764) /* 0x51286c */);
    // 00464712  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464716  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00464718  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0046471b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046471f  8b1570285100           -mov edx, dword ptr [0x512870]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5318768) /* 0x512870 */);
    // 00464725  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00464728  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046472c  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0046472f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464733  8b1568285100           -mov edx, dword ptr [0x512868]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5318760) /* 0x512868 */);
    // 00464739  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046473c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464740  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00464743  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464747  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x0046474a:
    // 0046474a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046474c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046474e  e86d80ffff             -call 0x45c7c0
    cpu.esp -= 4;
    sub_45c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00464753  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464755  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464756  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464757  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00464759  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046475c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046475d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046475e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046475f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464760  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464770  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464771  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464772  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464773  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00464776  8b2d388e4c00           -mov ebp, dword ptr [0x4c8e38]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 0046477c  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00464780  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00464784  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00464788  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046478a  8d04ed00000000         -lea eax, [ebp*8]
    cpu.eax = x86::reg32(cpu.ebp * 8);
    // 00464791  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00464793  baf42b5100             -mov edx, 0x512bf4
    cpu.edx = 5319668 /*0x512bf4*/;
    // 00464798  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046479b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046479d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046479f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004647a1  49                     -dec ecx
    (cpu.ecx)--;
    // 004647a2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004647a4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004647a6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004647a8  49                     -dec ecx
    (cpu.ecx)--;
    // 004647a9  8b2d388e4c00           -mov ebp, dword ptr [0x4c8e38]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 004647af  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004647b2  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004647b5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004647b7  0f8c8e000000           -jl 0x46484b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046484b;
    }
    // 004647bd  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x004647c0:
    // 004647c0  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004647c2  80fc4e                 +cmp ah, 0x4e
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004647c5  0f85d6000000           -jne 0x4648a1
    if (!cpu.flags.zf)
    {
        goto L_0x004648a1;
    }
    // 004647cb  b8c42b5100             -mov eax, 0x512bc4
    cpu.eax = 5319620 /*0x512bc4*/;
L_0x004647d0:
    // 004647d0  83fd4f                 +cmp ebp, 0x4f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004647d3  0f8cfa000000           -jl 0x4648d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004648d3;
    }
    // 004647d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004647db:
    // 004647db  6bc924                 -imul ecx, ecx, 0x24
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 004647de  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 004647e3  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004647e5  6bcd24                 -imul ecx, ebp, 0x24
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 004647e8  89b1f42b5100           -mov dword ptr [ecx + 0x512bf4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319668) /* 0x512bf4 */) = cpu.esi;
    // 004647ee  8981142c5100           -mov dword ptr [ecx + 0x512c14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319700) /* 0x512c14 */) = cpu.eax;
    // 004647f4  c781f82b510014000000   -mov dword ptr [ecx + 0x512bf8], 0x14
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319672) /* 0x512bf8 */) = 20 /*0x14*/;
    // 004647fe  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00464800  8b7602                 -mov esi, dword ptr [esi + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00464803  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00464806  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0046480a  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046480e  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464812  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00464814  89b1fc2b5100           -mov dword ptr [ecx + 0x512bfc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319676) /* 0x512bfc */) = cpu.esi;
    // 0046481a  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046481e  89b1002c5100           -mov dword ptr [ecx + 0x512c00], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319680) /* 0x512c00 */) = cpu.esi;
    // 00464824  83fd4f                 +cmp ebp, 0x4f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464827  0f8cae000000           -jl 0x4648db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004648db;
    }
    // 0046482d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0046482f:
    // 0046482f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00464831  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00464834  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464838  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046483b  4a                     -dec edx
    (cpu.edx)--;
    // 0046483c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046483e  4b                     -dec ebx
    (cpu.ebx)--;
    // 0046483f  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00464843  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00464845  0f8d75ffffff           -jge 0x4647c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004647c0;
    }
L_0x0046484b:
    // 0046484b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046484d  0f8e8e000000           -jle 0x4648e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004648e1;
    }
    // 00464853  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
L_0x00464856:
    // 00464856  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046485d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046485f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464861  891c85f42b5100         -mov dword ptr [eax*4 + 0x512bf4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.ebx;
    // 00464868  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046486a  0f8e7b000000           -jle 0x4648eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004648eb;
    }
    // 00464870  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
L_0x00464873:
    // 00464873  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464875  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00464878  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046487a  baf42b5100             -mov edx, 0x512bf4
    cpu.edx = 5319668 /*0x512bf4*/;
    // 0046487f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464882  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464886  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464888  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046488a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046488e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046488f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464890  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464894  892d388e4c00           -mov dword ptr [0x4c8e38], ebp
    app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */) = cpu.ebp;
    // 0046489a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046489d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046489e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046489f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004648a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004648a1:
    // 004648a1  80fc52                 +cmp ah, 0x52
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(82 /*0x52*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004648a4  750a                   -jne 0x4648b0
    if (!cpu.flags.zf)
    {
        goto L_0x004648b0;
    }
    // 004648a6  b8d02b5100             -mov eax, 0x512bd0
    cpu.eax = 5319632 /*0x512bd0*/;
    // 004648ab  e920ffffff             -jmp 0x4647d0
    goto L_0x004647d0;
L_0x004648b0:
    // 004648b0  80fcb0                 +cmp ah, 0xb0
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(176 /*0xb0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004648b3  750a                   -jne 0x4648bf
    if (!cpu.flags.zf)
    {
        goto L_0x004648bf;
    }
    // 004648b5  b8dc2b5100             -mov eax, 0x512bdc
    cpu.eax = 5319644 /*0x512bdc*/;
    // 004648ba  e911ffffff             -jmp 0x4647d0
    goto L_0x004647d0;
L_0x004648bf:
    // 004648bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004648c1  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004648c3  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004648c6  6bc00c                 -imul eax, eax, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 004648c9  054c2b5100             +add eax, 0x512b4c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5319500 /*0x512b4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004648ce  e9fdfeffff             -jmp 0x4647d0
    goto L_0x004647d0;
L_0x004648d3:
    // 004648d3  8d4d01                 -lea ecx, [ebp + 1]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004648d6  e900ffffff             -jmp 0x4647db
    goto L_0x004647db;
L_0x004648db:
    // 004648db  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004648dc  e94effffff             -jmp 0x46482f
    goto L_0x0046482f;
L_0x004648e1:
    // 004648e1  ba4f000000             -mov edx, 0x4f
    cpu.edx = 79 /*0x4f*/;
    // 004648e6  e96bffffff             -jmp 0x464856
    goto L_0x00464856;
L_0x004648eb:
    // 004648eb  b84f000000             -mov eax, 0x4f
    cpu.eax = 79 /*0x4f*/;
    // 004648f0  eb81                   -jmp 0x464873
    goto L_0x00464873;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464903  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464904  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464905  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464908  8b15388e4c00           -mov edx, dword ptr [0x4c8e38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 0046490e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464910  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00464917  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464919  bbf42b5100             -mov ebx, 0x512bf4
    cpu.ebx = 5319668 /*0x512bf4*/;
    // 0046491e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464921  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464923  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00464926  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464929  0f8c39010000           -jl 0x464a68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464a68;
    }
    // 0046492f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00464931:
    // 00464931  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00464933  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00464936  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464938  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 0046493d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464940  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464942  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00464949  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046494b  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00464950  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 00464957  891c85f82b5100         -mov dword ptr [eax*4 + 0x512bf8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.ebx;
    // 0046495e  be982a5100             -mov esi, 0x512a98
    cpu.esi = 5319320 /*0x512a98*/;
    // 00464963  8b1d982a5100           -mov ebx, dword ptr [0x512a98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319320) /* 0x512a98 */);
    // 00464969  893485142c5100         -mov dword ptr [eax*4 + 0x512c14], esi
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.esi;
    // 00464970  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464973  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00464976  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00464979  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00464980  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464983  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00464986  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464989  891c85002c5100         -mov dword ptr [eax*4 + 0x512c00], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.ebx;
    // 00464990  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464993  0f8cd7000000           -jl 0x464a70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464a70;
    }
    // 00464999  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046499b:
    // 0046499b  8b3dbcf34d00           -mov edi, dword ptr [0x4df3bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 004649a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004649a3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004649a5  7573                   -jne 0x464a1a
    if (!cpu.flags.zf)
    {
        goto L_0x00464a1a;
    }
    // 004649a7  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004649aa  0f8cc8000000           -jl 0x464a78
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464a78;
    }
    // 004649b0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004649b2:
    // 004649b2  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 004649b9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004649bb  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 004649c0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004649c3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004649c5  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004649cc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004649ce  bb4c2b5100             -mov ebx, 0x512b4c
    cpu.ebx = 5319500 /*0x512b4c*/;
    // 004649d3  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 004649da  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
    // 004649df  891c85142c5100         -mov dword ptr [eax*4 + 0x512c14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.ebx;
    // 004649e6  8b1d4c2b5100           -mov ebx, dword ptr [0x512b4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319500) /* 0x512b4c */);
    // 004649ec  892c85f82b5100         -mov dword ptr [eax*4 + 0x512bf8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.ebp;
    // 004649f3  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004649f6  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 004649f9  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 004649fc  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00464a03  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464a06  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00464a09  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464a0c  891c85002c5100         -mov dword ptr [eax*4 + 0x512c00], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.ebx;
    // 00464a13  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a16  7c68                   -jl 0x464a80
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464a80;
    }
    // 00464a18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00464a1a:
    // 00464a1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00464a1c  7e65                   -jle 0x464a83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464a83;
    }
    // 00464a1e  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00464a21:
    // 00464a21  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00464a28  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464a2a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00464a2c  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 00464a33  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00464a35  7e53                   -jle 0x464a8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464a8a;
    }
    // 00464a37  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00464a3a:
    // 00464a3a  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00464a41  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464a43  bbf42b5100             -mov ebx, 0x512bf4
    cpu.ebx = 5319668 /*0x512bf4*/;
    // 00464a48  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464a4b  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464a4d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464a4f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00464a51  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00464a55  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464a56  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464a57  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00464a59  8915388e4c00           -mov dword ptr [0x4c8e38], edx
    app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */) = cpu.edx;
    // 00464a5f  83c408                 +add esp, 8
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
    // 00464a62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464a68:
    // 00464a68  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00464a6b  e9c1feffff             -jmp 0x464931
    goto L_0x00464931;
L_0x00464a70:
    // 00464a70  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00464a73  e923ffffff             -jmp 0x46499b
    goto L_0x0046499b;
L_0x00464a78:
    // 00464a78  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00464a7b  e932ffffff             -jmp 0x4649b2
    goto L_0x004649b2;
L_0x00464a80:
    // 00464a80  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00464a81  eb97                   -jmp 0x464a1a
    goto L_0x00464a1a;
L_0x00464a83:
    // 00464a83  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00464a88  eb97                   -jmp 0x464a21
    goto L_0x00464a21;
L_0x00464a8a:
    // 00464a8a  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00464a8f  eba9                   -jmp 0x464a3a
    goto L_0x00464a3a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464aa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464aa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464aa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464aa3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464aa4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464aa5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464aa8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464aaa  bab4295100             -mov edx, 0x5129b4
    cpu.edx = 5319092 /*0x5129b4*/;
    // 00464aaf  b83c295100             -mov eax, 0x51293c
    cpu.eax = 5318972 /*0x51293c*/;
    // 00464ab4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464ab6  e815040000             -call 0x464ed0
    cpu.esp -= 4;
    sub_464ed0(app, cpu);
    if (cpu.terminate) return;
    // 00464abb  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00464ac0  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464ac4  e897010000             -call 0x464c60
    cpu.esp -= 4;
    sub_464c60(app, cpu);
    if (cpu.terminate) return;
    // 00464ac9  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464acd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464ace  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464ad2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464ad3  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464ad7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464ad8  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464adc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464add  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464ae1  e88a7dffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464ae6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464aea  e871060000             -call 0x465160
    cpu.esp -= 4;
    sub_465160(app, cpu);
    if (cpu.terminate) return;
    // 00464aef  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464af3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464af4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464af8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464af9  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464afd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464afe  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b02  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464b03  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464b07  e8647dffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464b0c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464b10  e80bf4ffff             -call 0x463f20
    cpu.esp -= 4;
    sub_463f20(app, cpu);
    if (cpu.terminate) return;
    // 00464b15  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464b1a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464b1f  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464b24  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464b29  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464b2d  bac4295100             -mov edx, 0x5129c4
    cpu.edx = 5319108 /*0x5129c4*/;
    // 00464b32  e8397dffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464b37  b8042a5100             -mov eax, 0x512a04
    cpu.eax = 5319172 /*0x512a04*/;
    // 00464b3c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464b40  e88b030000             -call 0x464ed0
    cpu.esp -= 4;
    sub_464ed0(app, cpu);
    if (cpu.terminate) return;
    // 00464b45  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464b4a  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b4e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464b4f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464b54  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464b59  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464b5d  e80e7dffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464b62  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00464b67  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464b6b  e8f0000000             -call 0x464c60
    cpu.esp -= 4;
    sub_464c60(app, cpu);
    if (cpu.terminate) return;
    // 00464b70  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464b75  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464b7a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464b7f  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464b84  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464b88  e8e37cffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464b8d  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464b91  e8da040000             -call 0x465070
    cpu.esp -= 4;
    sub_465070(app, cpu);
    if (cpu.terminate) return;
    // 00464b96  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464b9b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464b9f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464ba0  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464ba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464ba5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464ba9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464baa  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464bae  e8bd7cffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464bb3  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464bb7  e864f3ffff             -call 0x463f20
    cpu.esp -= 4;
    sub_463f20(app, cpu);
    if (cpu.terminate) return;
    // 00464bbc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464bc1  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464bc6  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464bcb  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bcf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464bd0  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464bd4  bad4295100             -mov edx, 0x5129d4
    cpu.edx = 5319124 /*0x5129d4*/;
    // 00464bd9  e8927cffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464bde  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464be2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464be4  e867020000             -call 0x464e50
    cpu.esp -= 4;
    sub_464e50(app, cpu);
    if (cpu.terminate) return;
    // 00464be9  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464bee  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bf2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464bf3  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bf7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464bf8  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464bfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464bfd  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464c01  e86a7cffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464c06  833dbcf34d0002         +cmp dword ptr [0x4df3bc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464c0d  7411                   -je 0x464c20
    if (cpu.flags.zf)
    {
        goto L_0x00464c20;
    }
    // 00464c0f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464c11  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00464c13  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464c14  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464c15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00464c17  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464c1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464c20:
    // 00464c20  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464c24  e887030000             -call 0x464fb0
    cpu.esp -= 4;
    sub_464fb0(app, cpu);
    if (cpu.terminate) return;
    // 00464c29  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464c2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464c2e  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464c32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464c33  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464c37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464c38  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464c3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464c3d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464c41  e82a7cffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464c46  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464c48  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00464c4a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464c4b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464c4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00464c4e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464c51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464c56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464c60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464c61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464c62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464c63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464c64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464c65  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464c68  8b15388e4c00           -mov edx, dword ptr [0x4c8e38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 00464c6e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464c70  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00464c72  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00464c79  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464c7b  bbf42b5100             -mov ebx, 0x512bf4
    cpu.ebx = 5319668 /*0x512bf4*/;
    // 00464c80  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464c83  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464c85  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00464c88  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464c8b  0f8c83010000           -jl 0x464e14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464e14;
    }
    // 00464c91  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00464c93:
    // 00464c93  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00464c9a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464c9c  bff42b5100             -mov edi, 0x512bf4
    cpu.edi = 5319668 /*0x512bf4*/;
    // 00464ca1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464ca4  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464ca6  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00464cad  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464caf  893c85f42b5100         -mov dword ptr [eax*4 + 0x512bf4], edi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.edi;
    // 00464cb6  bb8c2a5100             -mov ebx, 0x512a8c
    cpu.ebx = 5319308 /*0x512a8c*/;
    // 00464cbb  893485f82b5100         -mov dword ptr [eax*4 + 0x512bf8], esi
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.esi;
    // 00464cc2  891c85142c5100         -mov dword ptr [eax*4 + 0x512c14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.ebx;
    // 00464cc9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00464ccb  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00464cd2  893485002c5100         -mov dword ptr [eax*4 + 0x512c00], esi
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.esi;
    // 00464cd9  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464cdc  0f8c3a010000           -jl 0x464e1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464e1c;
    }
    // 00464ce2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00464ce4:
    // 00464ce4  8b2dbcf34d00           -mov ebp, dword ptr [0x4df3bc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 00464cea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464cec  83fd07                 +cmp ebp, 7
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464cef  0f85ec000000           -jne 0x464de1
    if (!cpu.flags.zf)
    {
        goto L_0x00464de1;
    }
    // 00464cf5  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464cf8  0f8c26010000           -jl 0x464e24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464e24;
    }
    // 00464cfe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00464d00:
    // 00464d00  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00464d07  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464d09  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 00464d0e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464d11  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464d13  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00464d1a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464d1c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00464d21  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 00464d28  891c85f82b5100         -mov dword ptr [eax*4 + 0x512bf8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.ebx;
    // 00464d2f  be4c2b5100             -mov esi, 0x512b4c
    cpu.esi = 5319500 /*0x512b4c*/;
    // 00464d34  8b1d4c2b5100           -mov ebx, dword ptr [0x512b4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319500) /* 0x512b4c */);
    // 00464d3a  893485142c5100         -mov dword ptr [eax*4 + 0x512c14], esi
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.esi;
    // 00464d41  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464d44  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00464d47  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00464d4a  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00464d51  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464d54  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00464d57  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464d5a  891c85002c5100         -mov dword ptr [eax*4 + 0x512c00], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.ebx;
    // 00464d61  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464d64  0f8cc2000000           -jl 0x464e2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464e2c;
    }
    // 00464d6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00464d6c:
    // 00464d6c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464d6e  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464d71  0f8cbd000000           -jl 0x464e34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464e34;
    }
    // 00464d77  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00464d79:
    // 00464d79  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00464d80  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464d82  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 00464d87  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464d8a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464d8c  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00464d93  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464d95  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 00464d9a  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 00464da1  bd582b5100             -mov ebp, 0x512b58
    cpu.ebp = 5319512 /*0x512b58*/;
    // 00464da6  893c85f82b5100         -mov dword ptr [eax*4 + 0x512bf8], edi
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.edi;
    // 00464dad  8b1d582b5100           -mov ebx, dword ptr [0x512b58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319512) /* 0x512b58 */);
    // 00464db3  892c85142c5100         -mov dword ptr [eax*4 + 0x512c14], ebp
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.ebp;
    // 00464dba  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464dbd  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00464dc0  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00464dc3  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00464dca  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00464dcd  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00464dd0  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464dd3  891c85002c5100         -mov dword ptr [eax*4 + 0x512c00], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.ebx;
    // 00464dda  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464ddd  7c5d                   -jl 0x464e3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464e3c;
    }
    // 00464ddf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00464de1:
    // 00464de1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00464de3  7e5a                   -jle 0x464e3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464e3f;
    }
    // 00464de5  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00464de8:
    // 00464de8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00464dea  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00464ded  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464def  bbf42b5100             -mov ebx, 0x512bf4
    cpu.ebx = 5319668 /*0x512bf4*/;
    // 00464df4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00464df7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464df9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464dfb  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00464dfd  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00464e01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464e02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464e03  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00464e05  8915388e4c00           -mov dword ptr [0x4c8e38], edx
    app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */) = cpu.edx;
    // 00464e0b  83c408                 +add esp, 8
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
    // 00464e0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464e0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464e10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464e11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464e12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464e13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464e14:
    // 00464e14  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00464e17  e977feffff             -jmp 0x464c93
    goto L_0x00464c93;
L_0x00464e1c:
    // 00464e1c  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00464e1f  e9c0feffff             -jmp 0x464ce4
    goto L_0x00464ce4;
L_0x00464e24:
    // 00464e24  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00464e27  e9d4feffff             -jmp 0x464d00
    goto L_0x00464d00;
L_0x00464e2c:
    // 00464e2c  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00464e2f  e938ffffff             -jmp 0x464d6c
    goto L_0x00464d6c;
L_0x00464e34:
    // 00464e34  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00464e37  e93dffffff             -jmp 0x464d79
    goto L_0x00464d79;
L_0x00464e3c:
    // 00464e3c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00464e3d  eba2                   -jmp 0x464de1
    goto L_0x00464de1;
L_0x00464e3f:
    // 00464e3f  b84f000000             -mov eax, 0x4f
    cpu.eax = 79 /*0x4f*/;
    // 00464e44  eba2                   -jmp 0x464de8
    goto L_0x00464de8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464e51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464e52  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464e55  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464e57  c7420417000000         -mov dword ptr [edx + 4], 0x17
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 23 /*0x17*/;
    // 00464e5e  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00464e64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464e66  745b                   -je 0x464ec3
    if (cpu.flags.zf)
    {
        goto L_0x00464ec3;
    }
    // 00464e68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464e69  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464e6c  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00464e6f  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464e72  66895a08               -mov word ptr [edx + 8], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 00464e76  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464e79  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00464e7c  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464e7f  66895a0a               -mov word ptr [edx + 0xa], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 00464e83  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464e86  8b7002                 -mov esi, dword ptr [eax + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00464e89  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00464e8c  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00464e8f  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00464e92  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00464e94  66895a0c               -mov word ptr [edx + 0xc], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 00464e98  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00464e9b  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464e9e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00464ea1  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00464ea4  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00464ea7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00464ea9  6689420e               -mov word ptr [edx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00464ead  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00464eae:
    // 00464eae  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464eb0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00464eb2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00464eb6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00464eb9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464eba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464ebb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00464ebd  83c408                 +add esp, 8
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
    // 00464ec0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464ec1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464ec2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464ec3:
    // 00464ec3  66c74208ffff           -mov word ptr [edx + 8], 0xffff
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 65535 /*0xffff*/;
    // 00464ec9  ebe3                   -jmp 0x464eae
    goto L_0x00464eae;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464ed2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464ed3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464ed6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464ed8  c7420417000000         -mov dword ptr [edx + 4], 0x17
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 23 /*0x17*/;
    // 00464edf  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00464ee5  668b5810               -mov bx, word ptr [eax + 0x10]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00464ee9  66895a08               -mov word ptr [edx + 8], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 00464eed  668b5814               -mov bx, word ptr [eax + 0x14]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00464ef1  66895a0a               -mov word ptr [edx + 0xa], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 00464ef5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00464ef8  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00464efc  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00464efe  66895a0c               -mov word ptr [edx + 0xc], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 00464f02  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464f04  668b401c               -mov ax, word ptr [eax + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00464f08  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00464f0c  6689420e               -mov word ptr [edx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00464f10  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464f11  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464f12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00464f14  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00464f17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464f21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464f22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464f23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464f24  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00464f27  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00464f29  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464f2b  e830020000             -call 0x465160
    cpu.esp -= 4;
    sub_465160(app, cpu);
    if (cpu.terminate) return;
    // 00464f30  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464f34  e837010000             -call 0x465070
    cpu.esp -= 4;
    sub_465070(app, cpu);
    if (cpu.terminate) return;
    // 00464f39  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464f3e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f42  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464f43  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464f48  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464f4d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464f51  e81a79ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464f56  833dbcf34d0002         +cmp dword ptr [0x4df3bc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464f5d  7410                   -je 0x464f6f
    if (cpu.flags.zf)
    {
        goto L_0x00464f6f;
    }
    // 00464f5f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464f61  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00464f63  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464f64  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464f65  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464f67  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00464f6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464f6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464f6f:
    // 00464f6f  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464f73  e838000000             -call 0x464fb0
    cpu.esp -= 4;
    sub_464fb0(app, cpu);
    if (cpu.terminate) return;
    // 00464f78  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464f7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464f7d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464f82  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f86  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464f87  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464f8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464f8c  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464f90  e8db78ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464f95  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464f97  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00464f99  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464f9a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464f9b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464f9d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00464fa0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464fa1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464fa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464fa3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464fa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464fb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464fb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464fb3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00464fb6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00464fb8  e89378ffff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 00464fbd  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 00464fc2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464fc6  e83578ffff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 00464fcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464fcd  0f8483000000           -je 0x465056
    if (cpu.flags.zf)
    {
        goto L_0x00465056;
    }
    // 00464fd3  8b3598f34d00           -mov esi, dword ptr [0x4df398]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108632) /* 0x4df398 */);
    // 00464fd9  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464fdc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464fe0  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 00464fe7  c7400413000000         -mov dword ptr [eax + 4], 0x13
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 19 /*0x13*/;
    // 00464fee  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00464ff0  be8c2a5100             -mov esi, 0x512a8c
    cpu.esi = 5319308 /*0x512a8c*/;
    // 00464ff5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00464ff8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464ffc  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464ffe  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00465001  a198f34d00             -mov eax, dword ptr [0x4df398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108632) /* 0x4df398 */);
    // 00465006  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00465009  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00465010  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00465012  8b14858c2a5100         -mov edx, dword ptr [eax*4 + 0x512a8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5319308) /* 0x512a8c */ + cpu.eax * 4);
    // 00465019  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046501c  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046501f  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00465023  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00465026  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00465029  8b04858c2a5100         -mov eax, dword ptr [eax*4 + 0x512a8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319308) /* 0x512a8c */ + cpu.eax * 4);
    // 00465030  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00465033  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00465036  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046503a  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 0046503d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046503f  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00465042  e87977ffff             -call 0x45c7c0
    cpu.esp -= 4;
    sub_45c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00465047  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00465049  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046504b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046504c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046504d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046504f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465052  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465053  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465054  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465055  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465056:
    // 00465056  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00465058  e8c378ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 0046505d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046505f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00465061  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465062  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465063  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00465065  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465068  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465069  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046506a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046506b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_465070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465073  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465074  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465075  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00465078  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046507a  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0046507f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00465081  bed03d4600             -mov esi, 0x463dd0
    cpu.esi = 4603344 /*0x463dd0*/;
    // 00465086  ba28000000             -mov edx, 0x28
    cpu.edx = 40 /*0x28*/;
    // 0046508b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046508d  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00465092  be74285100             -mov esi, 0x512874
    cpu.esi = 5318772 /*0x512874*/;
    // 00465097  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0046509c  83c678                 -add esi, 0x78
    (cpu.esi) += x86::reg32(x86::sreg32(120 /*0x78*/));
L_0x0046509f:
    // 0046509f  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 004650a4  668b7c14d8             -mov di, word ptr [esp + edx - 0x28]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-40) /* -0x28 */ + cpu.edx * 1);
    // 004650a9  899878285100           -mov dword ptr [eax + 0x512878], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5318776) /* 0x512878 */) = cpu.ebx;
    // 004650af  668b1d042a5100         -mov bx, word ptr [0x512a04]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5319172) /* 0x512a04 */);
    // 004650b6  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004650b8  668b7c14dc             -mov di, word ptr [esp + edx - 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-36) /* -0x24 */ + cpu.edx * 1);
    // 004650bd  6689987e285100         -mov word ptr [eax + 0x51287e], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318782) /* 0x51287e */) = cpu.bx;
    // 004650c4  668b1d082a5100         -mov bx, word ptr [0x512a08]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5319176) /* 0x512a08 */);
    // 004650cb  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004650cd  668b7c14d8             -mov di, word ptr [esp + edx - 0x28]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-40) /* -0x28 */ + cpu.edx * 1);
    // 004650d2  66899880285100         -mov word ptr [eax + 0x512880], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318784) /* 0x512880 */) = cpu.bx;
    // 004650d9  668b1d0c2a5100         -mov bx, word ptr [0x512a0c]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5319180) /* 0x512a0c */);
    // 004650e0  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004650e2  668b7c14dc             -mov di, word ptr [esp + edx - 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-36) /* -0x24 */ + cpu.edx * 1);
    // 004650e7  66899882285100         -mov word ptr [eax + 0x512882], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318786) /* 0x512882 */) = cpu.bx;
    // 004650ee  668b1d102a5100         -mov bx, word ptr [0x512a10]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5319184) /* 0x512a10 */);
    // 004650f5  89b074285100           -mov dword ptr [eax + 0x512874], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5318772) /* 0x512874 */) = cpu.esi;
    // 004650fb  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004650fd  66899884285100         -mov word ptr [eax + 0x512884], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318788) /* 0x512884 */) = cpu.bx;
    // 00465104  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465107  744c                   -je 0x465155
    if (cpu.flags.zf)
    {
        goto L_0x00465155;
    }
    // 00465109  8a1d792a5100           -mov bl, byte ptr [0x512a79]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5319289) /* 0x512a79 */);
L_0x0046510f:
    // 0046510f  88987c285100           -mov byte ptr [eax + 0x51287c], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5318780) /* 0x51287c */) = cpu.bl;
    // 00465115  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00465118  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046511b  41                     -inc ecx
    (cpu.ecx)++;
    // 0046511c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046511f  83f90a                 +cmp ecx, 0xa
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
    // 00465122  0f8c77ffffff           -jl 0x46509f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046509f;
    }
    // 00465128  bfd8285100             -mov edi, 0x5128d8
    cpu.edi = 5318872 /*0x5128d8*/;
    // 0046512d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046512f  b828295100             -mov eax, 0x512928
    cpu.eax = 5318952 /*0x512928*/;
    // 00465134  893528295100           -mov dword ptr [0x512928], esi
    app->getMemory<x86::reg32>(x86::reg32(5318952) /* 0x512928 */) = cpu.esi;
    // 0046513a  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0046513e  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00465142  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00465144  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00465148  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465149  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046514a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046514c  83c430                 +add esp, 0x30
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046514f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465150  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465151  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465152  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465153  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465154  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465155:
    // 00465155  8a1d782a5100           -mov bl, byte ptr [0x512a78]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5319288) /* 0x512a78 */);
    // 0046515b  ebb2                   -jmp 0x46510f
    goto L_0x0046510f;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_465160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465163  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465164  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465165  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00465168  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046516a  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0046516f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00465171  bea83d4600             -mov esi, 0x463da8
    cpu.esi = 4603304 /*0x463da8*/;
    // 00465176  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465178  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046517a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046517c  be74285100             -mov esi, 0x512874
    cpu.esi = 5318772 /*0x512874*/;
    // 00465181  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465183  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00465186:
    // 00465186  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 0046518b  668b3c14               -mov di, word ptr [esp + edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 1);
    // 0046518f  899878285100           -mov dword ptr [eax + 0x512878], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5318776) /* 0x512878 */) = cpu.ebx;
    // 00465195  668b1d3c295100         -mov bx, word ptr [0x51293c]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5318972) /* 0x51293c */);
    // 0046519c  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046519e  668b7c1404             -mov di, word ptr [esp + edx + 4]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 004651a3  6689987e285100         -mov word ptr [eax + 0x51287e], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318782) /* 0x51287e */) = cpu.bx;
    // 004651aa  668b1d40295100         -mov bx, word ptr [0x512940]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5318976) /* 0x512940 */);
    // 004651b1  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004651b3  668b3c14               -mov di, word ptr [esp + edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 1);
    // 004651b7  66899880285100         -mov word ptr [eax + 0x512880], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318784) /* 0x512880 */) = cpu.bx;
    // 004651be  668b1d44295100         -mov bx, word ptr [0x512944]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5318980) /* 0x512944 */);
    // 004651c5  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004651c7  668b7c1404             -mov di, word ptr [esp + edx + 4]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 004651cc  66899882285100         -mov word ptr [eax + 0x512882], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318786) /* 0x512882 */) = cpu.bx;
    // 004651d3  668b1d48295100         -mov bx, word ptr [0x512948]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5318984) /* 0x512948 */);
    // 004651da  89b074285100           -mov dword ptr [eax + 0x512874], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5318772) /* 0x512874 */) = cpu.esi;
    // 004651e0  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004651e2  66899884285100         -mov word ptr [eax + 0x512884], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5318788) /* 0x512884 */) = cpu.bx;
    // 004651e9  83f904                 +cmp ecx, 4
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
    // 004651ec  744c                   -je 0x46523a
    if (cpu.flags.zf)
    {
        goto L_0x0046523a;
    }
    // 004651ee  8a1db1295100           -mov bl, byte ptr [0x5129b1]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5319089) /* 0x5129b1 */);
L_0x004651f4:
    // 004651f4  88987c285100           -mov byte ptr [eax + 0x51287c], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5318780) /* 0x51287c */) = cpu.bl;
    // 004651fa  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004651fd  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00465200  41                     -inc ecx
    (cpu.ecx)++;
    // 00465201  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465204  83f905                 +cmp ecx, 5
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465207  0f8c79ffffff           -jl 0x465186
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465186;
    }
    // 0046520d  bf74285100             -mov edi, 0x512874
    cpu.edi = 5318772 /*0x512874*/;
    // 00465212  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00465214  b8c4285100             -mov eax, 0x5128c4
    cpu.eax = 5318852 /*0x5128c4*/;
    // 00465219  8935c4285100           -mov dword ptr [0x5128c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5318852) /* 0x5128c4 */) = cpu.esi;
    // 0046521f  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00465223  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00465227  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00465229  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046522d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046522e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046522f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00465231  83c430                 +add esp, 0x30
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00465234  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465235  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465236  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465237  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465238  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465239  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046523a:
    // 0046523a  8a1db0295100           -mov bl, byte ptr [0x5129b0]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5319088) /* 0x5129b0 */);
    // 00465240  ebb2                   -jmp 0x4651f4
    goto L_0x004651f4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465250  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465251  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465252  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00465255  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00465257  8a2558375100           -mov ah, byte ptr [0x513758]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5322584) /* 0x513758 */);
    // 0046525d  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0046525f  754b                   -jne 0x4652ac
    if (!cpu.flags.zf)
    {
        goto L_0x004652ac;
    }
    // 00465261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465262  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465263  bb19000000             -mov ebx, 0x19
    cpu.ebx = 25 /*0x19*/;
    // 00465268  be44375100             -mov esi, 0x513744
    cpu.esi = 5322564 /*0x513744*/;
    // 0046526d  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00465271  a24c375100             -mov byte ptr [0x51374c], al
    app->getMemory<x86::reg8>(x86::reg32(5322572) /* 0x51374c */) = cpu.al;
    // 00465276  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465278  891d48375100           -mov dword ptr [0x513748], ebx
    app->getMemory<x86::reg32>(x86::reg32(5322568) /* 0x513748 */) = cpu.ebx;
    // 0046527e  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00465282  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00465286  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046528a  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 0046528c  890d44375100           -mov dword ptr [0x513744], ecx
    app->getMemory<x86::reg32>(x86::reg32(5322564) /* 0x513744 */) = cpu.ecx;
    // 00465292  fec3                   -inc bl
    (cpu.bl)++;
    // 00465294  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465295  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465296  881d58375100           -mov byte ptr [0x513758], bl
    app->getMemory<x86::reg8>(x86::reg32(5322584) /* 0x513758 */) = cpu.bl;
    // 0046529c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046529d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046529e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004652a0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004652a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004652a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004652a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004652a6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004652a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004652aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004652ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004652ac:
    // 004652ac  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004652ae  e86d76ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 004652b3  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004652b5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004652b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004652b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004652b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004652bb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004652be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004652bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004652c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4652d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004652d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004652d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004652d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004652d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004652d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004652d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004652d6  bab81e0000             -mov edx, 0x1eb8
    cpu.edx = 7864 /*0x1eb8*/;
    // 004652db  a19cf34d00             -mov eax, dword ptr [0x4df39c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108636) /* 0x4df39c */);
    // 004652e0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004652e2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004652e5  c1e810                 +shr eax, 0x10
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
    // 004652e8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004652ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004652ec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004652ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004652f1  c1e210                 +shl edx, 0x10
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
    // 004652f4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004652f6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004652f9  bb042a5100             -mov ebx, 0x512a04
    cpu.ebx = 5319172 /*0x512a04*/;
    // 004652fe  83f80f                 +cmp eax, 0xf
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
    // 00465301  0f8c87000000           -jl 0x46538e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046538e;
    }
    // 00465307  8b35702a5100           -mov esi, dword ptr [0x512a70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5319280) /* 0x512a70 */);
L_0x0046530d:
    // 0046530d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046530f  8b7b70                 -mov edi, dword ptr [ebx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 00465312  c0e407                 +shl ah, 7
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
    // 00465315  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00465317  00e4                   +add ah, ah
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
    // 00465319  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046531b  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046531d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00465322  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465324  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0046532b  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046532d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046532f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00465331  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00465333  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00465336  c1e810                 +shr eax, 0x10
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
    // 00465339  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046533b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046533d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046533f  8b6b70                 -mov ebp, dword ptr [ebx + 0x70]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 00465342  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00465348  c0e507                 +shl ch, 7
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
    // 0046534b  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046534d  00ed                   +add ch, ch
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
    // 0046534f  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00465351  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465353  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00465358  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046535a  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00465361  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465363  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00465365  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00465367  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00465369  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046536c  c1e810                 +shr eax, 0x10
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
    // 0046536f  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00465371  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00465373  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465375  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00465378  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046537a  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046537d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046537f  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00465382  e839010000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 00465387  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465388  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465389  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046538a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046538b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046538c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046538d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046538e:
    // 0046538e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00465391  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00465394  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00465397  2b4634                 -sub eax, dword ptr [esi + 0x34]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
    // 0046539a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046539c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004653a1  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004653a7  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004653aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004653ac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004653af  c1e210                 +shl edx, 0x10
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
    // 004653b2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004653b4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004653b7  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004653ba  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004653bc  e94cffffff             -jmp 0x46530d
    goto L_0x0046530d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4653d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004653d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004653d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004653d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004653d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004653d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004653d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004653d6  8b1590f34d00           -mov edx, dword ptr [0x4df390]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108624) /* 0x4df390 */);
    // 004653dc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004653de  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 004653e1  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004653e3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004653e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004653e7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004653ea  c1e210                 +shl edx, 0x10
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
    // 004653ed  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004653ef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004653f2  bb3c295100             -mov ebx, 0x51293c
    cpu.ebx = 5318972 /*0x51293c*/;
    // 004653f7  83f80a                 +cmp eax, 0xa
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
    // 004653fa  0f8c89000000           -jl 0x465489
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465489;
    }
    // 00465400  8b3594295100           -mov esi, dword ptr [0x512994]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5319060) /* 0x512994 */);
L_0x00465406:
    // 00465406  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465408  8b7b70                 -mov edi, dword ptr [ebx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 0046540b  c0e407                 +shl ah, 7
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
    // 0046540e  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00465410  00e4                   +add ah, ah
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
    // 00465412  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00465414  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465416  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046541b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046541d  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00465424  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465426  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00465428  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046542a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046542c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046542f  c1e810                 +shr eax, 0x10
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
    // 00465432  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00465434  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00465436  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465438  8b7b70                 -mov edi, dword ptr [ebx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 0046543b  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00465441  c0e507                 +shl ch, 7
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
    // 00465444  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00465446  00ed                   +add ch, ch
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
    // 00465448  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046544a  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046544c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00465451  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465453  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0046545a  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046545c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046545e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00465460  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00465462  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00465465  c1e810                 +shr eax, 0x10
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
    // 00465468  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046546a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046546c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046546e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00465470  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00465473  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00465476  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00465478  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046547b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046547d  e83e000000             -call 0x4654c0
    cpu.esp -= 4;
    sub_4654c0(app, cpu);
    if (cpu.terminate) return;
    // 00465482  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465484  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465485  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465486  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465487  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465489:
    // 00465489  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046548c  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0046548f  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00465492  8b5634                 -mov edx, dword ptr [esi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00465495  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00465497  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465499  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0046549f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004654a5  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004654a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004654aa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004654ad  c1e210                 +shl edx, 0x10
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
    // 004654b0  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004654b2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004654b5  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004654b8  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004654ba  e947ffffff             -jmp 0x465406
    goto L_0x00465406;
}

/* align: skip 0x00 */
void Application::sub_4654c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004654c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004654c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004654c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004654c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004654c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004654c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004654c6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004654c8  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004654cb  39d3                   +cmp ebx, edx
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
    // 004654cd  7e51                   -jle 0x465520
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465520;
    }
L_0x004654cf:
    // 004654cf  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004654d2  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004654d5  39ce                   +cmp esi, ecx
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
    // 004654d7  7e4d                   -jle 0x465526
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465526;
    }
L_0x004654d9:
    // 004654d9  49                     -dec ecx
    (cpu.ecx)--;
    // 004654da  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004654dd  4a                     -dec edx
    (cpu.edx)--;
    // 004654de  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004654e1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004654e4  39fa                   +cmp edx, edi
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
    // 004654e6  7e45                   -jle 0x46552d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046552d;
    }
L_0x004654e8:
    // 004654e8  8b6824                 -mov ebp, dword ptr [eax + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004654eb  897810                 -mov dword ptr [eax + 0x10], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004654ee  39e9                   +cmp ecx, ebp
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
    // 004654f0  7e3f                   -jle 0x465531
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465531;
    }
    // 004654f2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004654f4:
    // 004654f4  897814                 -mov dword ptr [eax + 0x14], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004654f7  8b7828                 -mov edi, dword ptr [eax + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004654fa  39fb                   +cmp ebx, edi
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
    // 004654fc  7d37                   -jge 0x465535
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00465535;
    }
L_0x004654fe:
    // 004654fe  8b682c                 -mov ebp, dword ptr [eax + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00465501  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00465504  39ee                   +cmp esi, ebp
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
    // 00465506  7d31                   -jge 0x465539
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00465539;
    }
    // 00465508  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x0046550a:
    // 0046550a  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0046550d  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00465510  895828                 -mov dword ptr [eax + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00465513  89702c                 -mov dword ptr [eax + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00465516  89781c                 -mov dword ptr [eax + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00465519  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046551a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046551b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046551c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046551d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046551e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046551f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465520:
    // 00465520  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00465522  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00465524  eba9                   -jmp 0x4654cf
    goto L_0x004654cf;
L_0x00465526:
    // 00465526  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00465528  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046552b  ebac                   -jmp 0x4654d9
    goto L_0x004654d9;
L_0x0046552d:
    // 0046552d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046552f  ebb7                   -jmp 0x4654e8
    goto L_0x004654e8;
L_0x00465531:
    // 00465531  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00465533  ebbf                   -jmp 0x4654f4
    goto L_0x004654f4;
L_0x00465535:
    // 00465535  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00465537  ebc5                   -jmp 0x4654fe
    goto L_0x004654fe;
L_0x00465539:
    // 00465539  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046553b  ebcd                   -jmp 0x46550a
    goto L_0x0046550a;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_465540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465541  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465543  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00465545  0f84d0000000           -je 0x46561b
    if (cpu.flags.zf)
    {
        goto L_0x0046561b;
    }
    // 0046554b  833d3437510000         +cmp dword ptr [0x513734], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465552  0f84c5000000           -je 0x46561d
    if (cpu.flags.zf)
    {
        goto L_0x0046561d;
    }
    // 00465558  833d4037510000         +cmp dword ptr [0x513740], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5322560) /* 0x513740 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046555f  0f85c4000000           -jne 0x465629
    if (!cpu.flags.zf)
    {
        goto L_0x00465629;
    }
L_0x00465565:
    // 00465565  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465566  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465567  8b0d58295100           -mov ecx, dword ptr [0x512958]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5319000) /* 0x512958 */);
    // 0046556d  8b1d54295100           -mov ebx, dword ptr [0x512954]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5318996) /* 0x512954 */);
    // 00465573  8b1550295100           -mov edx, dword ptr [0x512950]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5318992) /* 0x512950 */);
    // 00465579  a14c295100             -mov eax, dword ptr [0x51294c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5318988) /* 0x51294c */);
    // 0046557e  e82d330100             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 00465583  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465585  e8863e0100             -call 0x479410
    cpu.esp -= 4;
    sub_479410(app, cpu);
    if (cpu.terminate) return;
    // 0046558a  833dbcf34d0004         +cmp dword ptr [0x4df3bc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465591  7423                   -je 0x4655b6
    if (cpu.flags.zf)
    {
        goto L_0x004655b6;
    }
    // 00465593  8b0d202a5100           -mov ecx, dword ptr [0x512a20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5319200) /* 0x512a20 */);
    // 00465599  8b1d1c2a5100           -mov ebx, dword ptr [0x512a1c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5319196) /* 0x512a1c */);
    // 0046559f  8b15182a5100           -mov edx, dword ptr [0x512a18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5319192) /* 0x512a18 */);
    // 004655a5  a1142a5100             -mov eax, dword ptr [0x512a14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319188) /* 0x512a14 */);
    // 004655aa  e801330100             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 004655af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004655b1  e85a3e0100             -call 0x479410
    cpu.esp -= 4;
    sub_479410(app, cpu);
    if (cpu.terminate) return;
L_0x004655b6:
    // 004655b6  833dbcf34d0002         +cmp dword ptr [0x4df3bc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004655bd  7547                   -jne 0x465606
    if (!cpu.flags.zf)
    {
        goto L_0x00465606;
    }
    // 004655bf  8b1598f34d00           -mov edx, dword ptr [0x4df398]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108632) /* 0x4df398 */);
    // 004655c5  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004655c8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004655cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004655d1  8b04858c2a5100         -mov eax, dword ptr [eax*4 + 0x512a8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319308) /* 0x512a8c */ + cpu.eax * 4);
    // 004655d8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004655db  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004655de  8b5802                 -mov ebx, dword ptr [eax + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004655e1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004655e4  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004655e7  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004655ea  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004655ed  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 004655f0  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004655f3  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004655f6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004655f8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004655fa  e8b1320100             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 004655ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465601  e80a3e0100             -call 0x479410
    cpu.esp -= 4;
    sub_479410(app, cpu);
    if (cpu.terminate) return;
L_0x00465606:
    // 00465606  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 0046560b  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00465610  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465612  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00465614  e897320100             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 00465619  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046561a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046561b:
    // 0046561b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046561c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046561d:
    // 0046561d  c7053437510001000000   -mov dword ptr [0x513734], 1
    app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */) = 1 /*0x1*/;
    // 00465627  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465628  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465629:
    // 00465629  e8fab70200             -call 0x490e28
    cpu.esp -= 4;
    sub_490e28(app, cpu);
    if (cpu.terminate) return;
    // 0046562e  e932ffffff             -jmp 0x465565
    goto L_0x00465565;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465641  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465642  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465644  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00465649  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046564b  7c2d                   -jl 0x46567a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046567a;
    }
    // 0046564d  833d4cf54d0000         +cmp dword ptr [0x4df54c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465654  7405                   -je 0x46565b
    if (cpu.flags.zf)
    {
        goto L_0x0046565b;
    }
L_0x00465656:
    // 00465656  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x0046565b:
    // 0046565b  83fa03                 +cmp edx, 3
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
    // 0046565e  7c28                   -jl 0x465688
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465688;
    }
    // 00465660  83fa0a                 +cmp edx, 0xa
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
    // 00465663  7c12                   -jl 0x465677
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465677;
    }
    // 00465665  83fa28                 +cmp edx, 0x28
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465668  7c26                   -jl 0x465690
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465690;
    }
    // 0046566a  83fa3c                 +cmp edx, 0x3c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046566d  7c25                   -jl 0x465694
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465694;
    }
    // 0046566f  83fa5a                 +cmp edx, 0x5a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465672  7d26                   -jge 0x46569a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046569a;
    }
    // 00465674  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00465677:
    // 00465677  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465678  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465679  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046567a:
    // 0046567a  8b1d4cf54d00           -mov ebx, dword ptr [0x4df54c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 00465680  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00465682  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00465684  75d5                   -jne 0x46565b
    if (!cpu.flags.zf)
    {
        goto L_0x0046565b;
    }
    // 00465686  ebce                   -jmp 0x465656
    goto L_0x00465656;
L_0x00465688:
    // 00465688  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0046568d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046568e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046568f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465690:
    // 00465690  40                     -inc eax
    (cpu.eax)++;
    // 00465691  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465692  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465693  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465694:
    // 00465694  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00465697  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465698  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465699  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046569a:
    // 0046569a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046569d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046569e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046569f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4656a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004656a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004656a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004656a3  e85842fdff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 004656a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004656aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004656ac  e8df45fdff             -call 0x439c90
    cpu.esp -= 4;
    sub_439c90(app, cpu);
    if (cpu.terminate) return;
    // 004656b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004656b3  7517                   -jne 0x4656cc
    if (!cpu.flags.zf)
    {
        goto L_0x004656cc;
    }
    // 004656b5  80bade02000000         +cmp byte ptr [edx + 0x2de], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(734) /* 0x2de */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004656bc  750e                   -jne 0x4656cc
    if (!cpu.flags.zf)
    {
        goto L_0x004656cc;
    }
    // 004656be  a1bcf34d00             -mov eax, dword ptr [0x4df3bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 004656c3  8b0485e88e4c00         -mov eax, dword ptr [eax*4 + 0x4c8ee8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017320) /* 0x4c8ee8 */ + cpu.eax * 4);
    // 004656ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004656cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004656cc:
    // 004656cc  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 004656d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004656d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4656e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004656e0  a1bcf34d00             -mov eax, dword ptr [0x4df3bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 004656e5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004656e8  05888e4c00             -add eax, 0x4c8e88
    (cpu.eax) += x86::reg32(x86::sreg32(5017224 /*0x4c8e88*/));
    // 004656ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4656f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004656f0  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004656f6  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004656fc  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00465702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465710  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465711  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465713  e8e841fdff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 00465718  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046571a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046571c  e86f45fdff             -call 0x439c90
    cpu.esp -= 4;
    sub_439c90(app, cpu);
    if (cpu.terminate) return;
    // 00465721  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00465723  7524                   -jne 0x465749
    if (!cpu.flags.zf)
    {
        goto L_0x00465749;
    }
    // 00465725  80bade02000000         +cmp byte ptr [edx + 0x2de], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(734) /* 0x2de */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046572c  751b                   -jne 0x465749
    if (!cpu.flags.zf)
    {
        goto L_0x00465749;
    }
    // 0046572e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00465733:
    // 00465733  8b155c375100           -mov edx, dword ptr [0x51375c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5322588) /* 0x51375c */);
    // 00465739  39d0                   +cmp eax, edx
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
    // 0046573b  7410                   -je 0x46574d
    if (cpu.flags.zf)
    {
        goto L_0x0046574d;
    }
    // 0046573d  a35c375100             -mov dword ptr [0x51375c], eax
    app->getMemory<x86::reg32>(x86::reg32(5322588) /* 0x51375c */) = cpu.eax;
    // 00465742  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00465747  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465749:
    // 00465749  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046574b  ebe6                   -jmp 0x465733
    goto L_0x00465733;
L_0x0046574d:
    // 0046574d  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046574f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465750  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465760  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465770  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465771  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465773  891534375100           -mov dword ptr [0x513734], edx
    app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */) = cpu.edx;
    // 00465779  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046577a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465780  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465781  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465786  e8014f0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046578b  8b1550375100           -mov edx, dword ptr [0x513750]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5322576) /* 0x513750 */);
    // 00465791  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00465793  7502                   -jne 0x465797
    if (!cpu.flags.zf)
    {
        goto L_0x00465797;
    }
    // 00465795  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465796  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465797:
    // 00465797  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00465799  e8ee4e0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046579e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046579f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4657a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004657a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004657a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004657a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004657a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004657a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004657a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004657a6  81ec60010000           -sub esp, 0x160
    (cpu.esp) -= x86::reg32(x86::sreg32(352 /*0x160*/));
    // 004657ac  89842458010000         -mov dword ptr [esp + 0x158], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(344) /* 0x158 */) = cpu.eax;
    // 004657b3  b916000000             -mov ecx, 0x16
    cpu.ecx = 22 /*0x16*/;
    // 004657b8  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004657bf  bd8c2a5100             -mov ebp, 0x512a8c
    cpu.ebp = 5319308 /*0x512a8c*/;
    // 004657c4  be503d4600             -mov esi, 0x463d50
    cpu.esi = 4603216 /*0x463d50*/;
    // 004657c9  a170f34d00             -mov eax, dword ptr [0x4df370]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
    // 004657ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004657d0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004657d2  891534375100           -mov dword ptr [0x513734], edx
    app->getMemory<x86::reg32>(x86::reg32(5322548) /* 0x513734 */) = cpu.edx;
    // 004657d8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004657da  a33c375100             -mov dword ptr [0x51373c], eax
    app->getMemory<x86::reg32>(x86::reg32(5322556) /* 0x51373c */) = cpu.eax;
    // 004657df  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 004657e4  ba10d94b00             -mov edx, 0x4bd910
    cpu.edx = 4970768 /*0x4bd910*/;
    // 004657e9  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 004657ee  83c518                 -add ebp, 0x18
    (cpu.ebp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004657f1  e86afa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 004657f6  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 004657fb  ba38d94b00             -mov edx, 0x4bd938
    cpu.edx = 4970808 /*0x4bd938*/;
    // 00465800  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465805  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465807  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046580a  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00465811  e84afa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465816  8d4758                 -lea eax, [edi + 0x58]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(88) /* 0x58 */);
    // 00465819  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0046581e  8984245c010000         -mov dword ptr [esp + 0x15c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(348) /* 0x15c */) = cpu.eax;
L_0x00465825:
    // 00465825  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 0046582a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046582c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046582e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465830  e82bfa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465835  46                     -inc esi
    (cpu.esi)++;
    // 00465836  8b8c245c010000         -mov ecx, dword ptr [esp + 0x15c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(348) /* 0x15c */);
    // 0046583d  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00465840  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465843  39cf                   +cmp edi, ecx
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
    // 00465845  75de                   -jne 0x465825
    if (!cpu.flags.zf)
    {
        goto L_0x00465825;
    }
    // 00465847  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046584e  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 00465853  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00465855  ba40d94b00             -mov edx, 0x4bd940
    cpu.edx = 4970816 /*0x4bd940*/;
    // 0046585a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046585d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046585f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465861  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465866  46                     -inc esi
    (cpu.esi)++;
    // 00465867  e8f4f90000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046586c  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00465873  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 00465878  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046587a  ba48d94b00             -mov edx, 0x4bd948
    cpu.edx = 4970824 /*0x4bd948*/;
    // 0046587f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00465882  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465884  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465886  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 0046588b  46                     -inc esi
    (cpu.esi)++;
    // 0046588c  e8cff90000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465891  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00465898  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 0046589d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046589f  ba50d94b00             -mov edx, 0x4bd950
    cpu.edx = 4970832 /*0x4bd950*/;
    // 004658a4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004658a7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004658a9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004658ab  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 004658b0  e8abf90000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 004658b5  8b9c2458010000         -mov ebx, dword ptr [esp + 0x158]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(344) /* 0x158 */);
    // 004658bc  46                     -inc esi
    (cpu.esi)++;
    // 004658bd  83fb07                 +cmp ebx, 7
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
    // 004658c0  0f84ef000000           -je 0x4659b5
    if (cpu.flags.zf)
    {
        goto L_0x004659b5;
    }
    // 004658c6  83fb04                 +cmp ebx, 4
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
    // 004658c9  0f851f010000           -jne 0x4659ee
    if (!cpu.flags.zf)
    {
        goto L_0x004659ee;
    }
    // 004658cf  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 004658d6  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004658d8  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 004658db  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004658dd  81c58c2a5100           -add ebp, 0x512a8c
    (cpu.ebp) += x86::reg32(x86::sreg32(5319308 /*0x512a8c*/));
L_0x004658e3:
    // 004658e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004658e4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004658e8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004658ec  6868d94b00             -push 0x4bd968
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970856 /*0x4bd968*/;
    cpu.esp -= 4;
    // 004658f1  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004658f3  46                     -inc esi
    (cpu.esi)++;
    // 004658f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004658f5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004658f7  47                     -inc edi
    (cpu.edi)++;
    // 004658f8  e8e4660100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004658fd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465900  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465905  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465908  e853f90000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046590d  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465910  7cd1                   -jl 0x4658e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004658e3;
    }
    // 00465912  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00465919  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 0046591e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00465920  ba70d94b00             -mov edx, 0x4bd970
    cpu.edx = 4970864 /*0x4bd970*/;
    // 00465925  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00465928  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046592a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046592c  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465931  46                     -inc esi
    (cpu.esi)++;
    // 00465932  e829f90000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465937  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046593e  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 00465943  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00465945  ba78d94b00             -mov edx, 0x4bd978
    cpu.edx = 4970872 /*0x4bd978*/;
    // 0046594a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046594d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046594f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465951  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465956  46                     -inc esi
    (cpu.esi)++;
    // 00465957  e804f90000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046595c  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00465963  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 00465968  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046596a  ba80d94b00             -mov edx, 0x4bd980
    cpu.edx = 4970880 /*0x4bd980*/;
    // 0046596f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00465972  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465974  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465976  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 0046597b  46                     -inc esi
    (cpu.esi)++;
    // 0046597c  e8dff80000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465981  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00465988  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 0046598d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046598f  ba88d94b00             -mov edx, 0x4bd988
    cpu.edx = 4970888 /*0x4bd988*/;
    // 00465994  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00465997  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465999  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046599b  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 004659a0  e8bbf80000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 004659a5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004659a8:
    // 004659a8  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 004659ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004659b5:
    // 004659b5  b94c2b5100             -mov ecx, 0x512b4c
    cpu.ecx = 5319500 /*0x512b4c*/;
    // 004659ba  ba58d94b00             -mov edx, 0x4bd958
    cpu.edx = 4970840 /*0x4bd958*/;
    // 004659bf  a150375100             -mov eax, dword ptr [0x513750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322576) /* 0x513750 */);
    // 004659c4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004659c6  e895f80000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 004659cb  b9582b5100             -mov ecx, 0x512b58
    cpu.ecx = 5319512 /*0x512b58*/;
    // 004659d0  ba60d94b00             -mov edx, 0x4bd960
    cpu.edx = 4970848 /*0x4bd960*/;
    // 004659d5  a150375100             -mov eax, dword ptr [0x513750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322576) /* 0x513750 */);
    // 004659da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004659dc  e87ff80000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 004659e1  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 004659e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004659ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004659ee:
    // 004659ee  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004659f1  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004659f8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004659fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004659fd  058c2a5100             -add eax, 0x512a8c
    (cpu.eax) += x86::reg32(x86::sreg32(5319308 /*0x512a8c*/));
    // 00465a02  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00465a04  0f8495000000           -je 0x465a9f
    if (cpu.flags.zf)
    {
        goto L_0x00465a9f;
    }
    // 00465a0a  83fb02                 +cmp ebx, 2
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
    // 00465a0d  7599                   -jne 0x4659a8
    if (!cpu.flags.zf)
    {
        goto L_0x004659a8;
    }
    // 00465a0f  ba98d94b00             -mov edx, 0x4bd998
    cpu.edx = 4970904 /*0x4bd998*/;
    // 00465a14  8b3554375100           -mov esi, dword ptr [0x513754]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465a1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00465a1c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465a1e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465a20  e83bf80000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465a25  b98c2a5100             -mov ecx, 0x512a8c
    cpu.ecx = 5319308 /*0x512a8c*/;
    // 00465a2a  baa0d94b00             -mov edx, 0x4bd9a0
    cpu.edx = 4970912 /*0x4bd9a0*/;
    // 00465a2f  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00465a36  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465a38  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00465a3a  8d7701                 -lea esi, [edi + 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00465a3d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00465a40  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00465a45  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 00465a4c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465a4e  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00465a50  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465a55  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00465a58  e803f80000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465a5d  81c58c2a5100           -add ebp, 0x512a8c
    (cpu.ebp) += x86::reg32(x86::sreg32(5319308 /*0x512a8c*/));
L_0x00465a63:
    // 00465a63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465a64  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00465a68  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00465a6c  68a8d94b00             -push 0x4bd9a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970920 /*0x4bd9a8*/;
    cpu.esp -= 4;
    // 00465a71  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00465a73  46                     -inc esi
    (cpu.esi)++;
    // 00465a74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465a75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465a77  47                     -inc edi
    (cpu.edi)++;
    // 00465a78  e864650100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00465a7d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465a80  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465a85  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00465a88  e8d3f70000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465a8d  83ff07                 +cmp edi, 7
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465a90  7cd1                   -jl 0x465a63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465a63;
    }
    // 00465a92  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00465a98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465a99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465a9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465a9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465a9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465a9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465a9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465a9f:
    // 00465a9f  ba90d94b00             -mov edx, 0x4bd990
    cpu.edx = 4970896 /*0x4bd990*/;
    // 00465aa4  8b3554375100           -mov esi, dword ptr [0x513754]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465aaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00465aac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465aae  e8adf70000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00465ab3  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00465ab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465aba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465abb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465abc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465abd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465abe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465abf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465ac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465ac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465ac4  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00465aca  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465ad1  7414                   -je 0x465ae7
    if (cpu.flags.zf)
    {
        goto L_0x00465ae7;
    }
    // 00465ad3  8b352cf54d00           -mov esi, dword ptr [0x4df52c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 00465ad9  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 00465adc  8bb690f54d00           -mov esi, dword ptr [esi + 0x4df590]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5109136) /* 0x4df590 */);
    // 00465ae2  83fe0c                 +cmp esi, 0xc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465ae5  7c0b                   -jl 0x465af2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465af2;
    }
L_0x00465ae7:
    // 00465ae7  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00465aed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465aee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465aef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465af0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465af1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465af2:
    // 00465af2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465af3  8b0dbc074e00           -mov ecx, dword ptr [0x4e07bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113788) /* 0x4e07bc */);
    // 00465af9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465afa  6818d94b00             -push 0x4bd918
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970776 /*0x4bd918*/;
    cpu.esp -= 4;
    // 00465aff  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00465b03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465b04  e8d8640100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00465b09  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00465b0c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465b0e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00465b10  e86f7e0100             -call 0x47d984
    cpu.esp -= 4;
    sub_47d984(app, cpu);
    if (cpu.terminate) return;
    // 00465b15  a354375100             -mov dword ptr [0x513754], eax
    app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */) = cpu.eax;
    // 00465b1a  83fe05                 +cmp esi, 5
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
    // 00465b1d  746f                   -je 0x465b8e
    if (cpu.flags.zf)
    {
        goto L_0x00465b8e;
    }
    // 00465b1f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465b21  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465b23  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00465b28  e893f30000             -call 0x474ec0
    cpu.esp -= 4;
    sub_474ec0(app, cpu);
    if (cpu.terminate) return;
L_0x00465b2d:
    // 00465b2d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465b2f  891d50375100           -mov dword ptr [0x513750], ebx
    app->getMemory<x86::reg32>(x86::reg32(5322576) /* 0x513750 */) = cpu.ebx;
    // 00465b35  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465b38  75ad                   -jne 0x465ae7
    if (!cpu.flags.zf)
    {
        goto L_0x00465ae7;
    }
    // 00465b3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465b3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465b3c  8b3dbc074e00           -mov edi, dword ptr [0x4e07bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113788) /* 0x4e07bc */);
    // 00465b42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465b43  6828d94b00             -push 0x4bd928
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970792 /*0x4bd928*/;
    cpu.esp -= 4;
    // 00465b48  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00465b4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00465b4d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465b4f  e88d640100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00465b54  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00465b57  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00465b5b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00465b5d  e8227e0100             -call 0x47d984
    cpu.esp -= 4;
    sub_47d984(app, cpu);
    if (cpu.terminate) return;
    // 00465b62  8b0d2cf54d00           -mov ecx, dword ptr [0x4df52c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 00465b68  a350375100             -mov dword ptr [0x513750], eax
    app->getMemory<x86::reg32>(x86::reg32(5322576) /* 0x513750 */) = cpu.eax;
    // 00465b6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465b6f  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 00465b72  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00465b77  8b899cf54d00           -mov ecx, dword ptr [ecx + 0x4df59c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5109148) /* 0x4df59c */);
    // 00465b7d  e89e790000             -call 0x46d520
    cpu.esp -= 4;
    sub_46d520(app, cpu);
    if (cpu.terminate) return;
    // 00465b82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b83  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00465b89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b8a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465b8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465b8e:
    // 00465b8e  8b0d2cf54d00           -mov ecx, dword ptr [0x4df52c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 00465b94  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00465b96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465b98  c1e106                 +shl ecx, 6
    {
        x86::reg8 tmp = 6 /*0x6*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00465b9b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00465ba0  8b899cf54d00           -mov ecx, dword ptr [ecx + 0x4df59c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5109148) /* 0x4df59c */);
    // 00465ba6  e875790000             -call 0x46d520
    cpu.esp -= 4;
    sub_46d520(app, cpu);
    if (cpu.terminate) return;
    // 00465bab  eb80                   -jmp 0x465b2d
    goto L_0x00465b2d;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_465bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465bb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465bb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465bb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465bb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465bb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465bb5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465bb8  833dbcf34d0000         +cmp dword ptr [0x4df3bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465bbf  7d09                   -jge 0x465bca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00465bca;
    }
    // 00465bc1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465bc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465bc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465bca:
    // 00465bca  ba10d94b00             -mov edx, 0x4bd910
    cpu.edx = 4970768 /*0x4bd910*/;
    // 00465bcf  a154375100             -mov eax, dword ptr [0x513754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5322580) /* 0x513754 */);
    // 00465bd4  e88b2d0100             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 00465bd9  e816b10200             -call 0x490cf4
    cpu.esp -= 4;
    sub_490cf4(app, cpu);
    if (cpu.terminate) return;
    // 00465bde  8b0dbcf34d00           -mov ecx, dword ptr [0x4df3bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 00465be4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00465be6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00465be9  83f904                 +cmp ecx, 4
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
    // 00465bec  755e                   -jne 0x465c4c
    if (!cpu.flags.zf)
    {
        goto L_0x00465c4c;
    }
    // 00465bee  bf6c285100             -mov edi, 0x51286c
    cpu.edi = 5318764 /*0x51286c*/;
    // 00465bf3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465bf5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465bf6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465bf7  bf64285100             -mov edi, 0x512864
    cpu.edi = 5318756 /*0x512864*/;
    // 00465bfc  8d7508                 -lea esi, [ebp + 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00465bff  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c00  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c01  bf842a5100             -mov edi, 0x512a84
    cpu.edi = 5319300 /*0x512a84*/;
    // 00465c06  8d7510                 -lea esi, [ebp + 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00465c09  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c0a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c0b  bf7c2a5100             -mov edi, 0x512a7c
    cpu.edi = 5319292 /*0x512a7c*/;
    // 00465c10  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00465c13  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c14  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c15  bff4295100             -mov edi, 0x5129f4
    cpu.edi = 5319156 /*0x5129f4*/;
    // 00465c1a  8d7520                 -lea esi, [ebp + 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00465c1d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c1e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c1f  bf4c295100             -mov edi, 0x51294c
    cpu.edi = 5318988 /*0x51294c*/;
    // 00465c24  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00465c26  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c27  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c28  bf54295100             -mov edi, 0x512954
    cpu.edi = 5318996 /*0x512954*/;
    // 00465c2d  8d7528                 -lea esi, [ebp + 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00465c30  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00465c31  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00465c32:
    // 00465c32  833dbcf34d0000         +cmp dword ptr [0x4df3bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465c39  7462                   -je 0x465c9d
    if (cpu.flags.zf)
    {
        goto L_0x00465c9d;
    }
    // 00465c3b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00465c3d  8935fc295100           -mov dword ptr [0x5129fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319164) /* 0x5129fc */) = cpu.esi;
    // 00465c43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465c46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465c4c:
    // 00465c4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465c4d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00465c54  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00465c59  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465c5b  b93c8e4c00             -mov ecx, 0x4c8e3c
    cpu.ecx = 5017148 /*0x4c8e3c*/;
    // 00465c60  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465c62  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00465c64  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465c66  b83c295100             -mov eax, 0x51293c
    cpu.eax = 5318972 /*0x51293c*/;
    // 00465c6b  e850000000             -call 0x465cc0
    cpu.esp -= 4;
    sub_465cc0(app, cpu);
    if (cpu.terminate) return;
    // 00465c70  8b15bcf34d00           -mov edx, dword ptr [0x4df3bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 00465c76  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00465c7d  b93c8e4c00             -mov ecx, 0x4c8e3c
    cpu.ecx = 5017148 /*0x4c8e3c*/;
    // 00465c82  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00465c84  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00465c89  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00465c8b  8d5560                 -lea edx, [ebp + 0x60]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
    // 00465c8e  01c1                   +add ecx, eax
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
    // 00465c90  b8042a5100             -mov eax, 0x512a04
    cpu.eax = 5319172 /*0x512a04*/;
    // 00465c95  e826000000             -call 0x465cc0
    cpu.esp -= 4;
    sub_465cc0(app, cpu);
    if (cpu.terminate) return;
    // 00465c9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465c9b  eb95                   -jmp 0x465c32
    goto L_0x00465c32;
L_0x00465c9d:
    // 00465c9d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00465ca0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 00465ca3  a3fc295100             -mov dword ptr [0x5129fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5319164) /* 0x5129fc */) = cpu.eax;
    // 00465ca8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465cab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465cac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465cad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465cae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465caf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465cb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465cc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465cc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465cc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465cc3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465cc6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00465cc8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00465cca  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00465ccd  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00465ccf  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00465cd1  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00465cd4  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00465cd7  8d7208                 -lea esi, [edx + 8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00465cda  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00465cdc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00465cdf  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00465ce2  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00465ce4  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00465ce6  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465ce8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00465cea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00465cec  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00465cef  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00465cf1  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00465cf4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00465cf6  e825ae0200             -call 0x490b20
    cpu.esp -= 4;
    sub_490b20(app, cpu);
    if (cpu.terminate) return;
    // 00465cfb  8d4f30                 -lea ecx, [edi + 0x30]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00465cfe  894770                 -mov dword ptr [edi + 0x70], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00465d01  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00465d03:
    // 00465d03  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465d06  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00465d08  83c608                 +add esi, 8
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
    // 00465d0b  e8b0830200             -call 0x48e0c0
    cpu.esp -= 4;
    sub_48e0c0(app, cpu);
    if (cpu.terminate) return;
    // 00465d10  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00465d13  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00465d14  7550                   -jne 0x465d66
    if (!cpu.flags.zf)
    {
        goto L_0x00465d66;
    }
    // 00465d16  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00465d19  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465d1b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00465d1e  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00465d21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465d23  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00465d25  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00465d28  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00465d2b  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00465d2d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465d2f  8a5102                 -mov dl, byte ptr [ecx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00465d32  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00465d34  e8e3230100             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00465d39  884774                 -mov byte ptr [edi + 0x74], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(116) /* 0x74 */) = cpu.al;
    // 00465d3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465d3e  8a4103                 -mov al, byte ptr [ecx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00465d41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465d43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465d45  8a4104                 -mov al, byte ptr [ecx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00465d48  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00465d4b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00465d4e  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00465d50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465d52  8a4105                 -mov al, byte ptr [ecx + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00465d55  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00465d57  e8c0230100             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00465d5c  884775                 -mov byte ptr [edi + 0x75], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(117) /* 0x75 */) = cpu.al;
    // 00465d5f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00465d62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465d65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465d66:
    // 00465d66  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00465d68  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 00465d6a  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00465d6d  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00465d6f  2b4704                 +sub eax, dword ptr [edi + 4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00465d72  eb8f                   -jmp 0x465d03
    goto L_0x00465d03;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 0000000000000000000000000000000000000000000000000000000000000000 */
void Application::sub_465da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465da0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465da2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465db0  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00465db5  0f8555000000           -jne 0x465e10
    if (!cpu.flags.zf)
    {
        goto L_0x00465e10;
    }
    // 00465dbb  f605a83b510020         +test byte ptr [0x513ba8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) & 32 /*0x20*/));
    // 00465dc2  7546                   -jne 0x465e0a
    if (!cpu.flags.zf)
    {
        goto L_0x00465e0a;
    }
L_0x00465dc4:
    // 00465dc4  83f84b                 +cmp eax, 0x4b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(75 /*0x4b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465dc7  7509                   -jne 0x465dd2
    if (!cpu.flags.zf)
    {
        goto L_0x00465dd2;
    }
    // 00465dc9  f605a83b510004         +test byte ptr [0x513ba8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) & 4 /*0x4*/));
    // 00465dd0  7538                   -jne 0x465e0a
    if (!cpu.flags.zf)
    {
        goto L_0x00465e0a;
    }
L_0x00465dd2:
    // 00465dd2  83f84d                 +cmp eax, 0x4d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(77 /*0x4d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465dd5  7509                   -jne 0x465de0
    if (!cpu.flags.zf)
    {
        goto L_0x00465de0;
    }
    // 00465dd7  f605a83b510008         +test byte ptr [0x513ba8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) & 8 /*0x8*/));
    // 00465dde  752a                   -jne 0x465e0a
    if (!cpu.flags.zf)
    {
        goto L_0x00465e0a;
    }
L_0x00465de0:
    // 00465de0  83f848                 +cmp eax, 0x48
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465de3  7509                   -jne 0x465dee
    if (!cpu.flags.zf)
    {
        goto L_0x00465dee;
    }
    // 00465de5  f605a83b510001         +test byte ptr [0x513ba8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) & 1 /*0x1*/));
    // 00465dec  751c                   -jne 0x465e0a
    if (!cpu.flags.zf)
    {
        goto L_0x00465e0a;
    }
L_0x00465dee:
    // 00465dee  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00465df1  7509                   -jne 0x465dfc
    if (!cpu.flags.zf)
    {
        goto L_0x00465dfc;
    }
    // 00465df3  f605a83b510002         +test byte ptr [0x513ba8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) & 2 /*0x2*/));
    // 00465dfa  750e                   -jne 0x465e0a
    if (!cpu.flags.zf)
    {
        goto L_0x00465e0a;
    }
L_0x00465dfc:
    // 00465dfc  83f81c                 +cmp eax, 0x1c
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
    // 00465dff  751a                   -jne 0x465e1b
    if (!cpu.flags.zf)
    {
        goto L_0x00465e1b;
    }
    // 00465e01  f605a83b510010         +test byte ptr [0x513ba8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) & 16 /*0x10*/));
    // 00465e08  7411                   -je 0x465e1b
    if (cpu.flags.zf)
    {
        goto L_0x00465e1b;
    }
L_0x00465e0a:
    // 00465e0a  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00465e0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465e10:
    // 00465e10  80b870a74c0000         +cmp byte ptr [eax + 0x4ca770], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023600) /* 0x4ca770 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00465e17  74ab                   -je 0x465dc4
    if (cpu.flags.zf)
    {
        goto L_0x00465dc4;
    }
    // 00465e19  ebef                   -jmp 0x465e0a
    goto L_0x00465e0a;
L_0x00465e1b:
    // 00465e1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465e1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_465e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465e20  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00465e25  80b870a74c0000         +cmp byte ptr [eax + 0x4ca770], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023600) /* 0x4ca770 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00465e2c  7503                   -jne 0x465e31
    if (!cpu.flags.zf)
    {
        goto L_0x00465e31;
    }
    // 00465e2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465e30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465e31:
    // 00465e31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465e32  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00465e34  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00465e39  8835a7a74c00           -mov byte ptr [0x4ca7a7], dh
    app->getMemory<x86::reg8>(x86::reg32(5023655) /* 0x4ca7a7 */) = cpu.dh;
    // 00465e3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465e51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465e52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465e53  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00465e55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465e57  c1ea14                 -shr edx, 0x14
    cpu.edx >>= 20 /*0x14*/ % 32;
    // 00465e5a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00465e5d  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00465e60  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00465e63  8b848280375100         -mov eax, dword ptr [edx + eax*4 + 0x513780]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5322624) /* 0x513780 */ + cpu.eax * 4);
    // 00465e6a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00465e6c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00465e72  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00465e78  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00465e7b  39ca                   +cmp edx, ecx
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
    // 00465e7d  7d34                   -jge 0x465eb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00465eb3;
    }
    // 00465e7f  39d0                   +cmp eax, edx
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
    // 00465e81  7c0d                   -jl 0x465e90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465e90;
    }
    // 00465e83  39c8                   +cmp eax, ecx
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
    // 00465e85  7e0f                   -jle 0x465e96
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465e96;
    }
L_0x00465e87:
    // 00465e87  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00465e8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465e90:
    // 00465e90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465e92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465e95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465e96:
    // 00465e96  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00465e98  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00465e9a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00465e9d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00465e9f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00465ea1  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00465ea4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465ea6  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00465ea8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465eaa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00465ead  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00465eaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465eb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465eb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465eb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465eb3:
    // 00465eb3  7e08                   -jle 0x465ebd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465ebd;
    }
    // 00465eb5  39c8                   +cmp eax, ecx
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
    // 00465eb7  7cce                   -jl 0x465e87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465e87;
    }
    // 00465eb9  39d0                   +cmp eax, edx
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
    // 00465ebb  7e06                   -jle 0x465ec3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465ec3;
    }
L_0x00465ebd:
    // 00465ebd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465ebf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ec0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ec1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ec2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465ec3:
    // 00465ec3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00465ec5  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00465ec7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00465ec9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00465ecc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00465ece  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00465ed0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00465ed3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00465ed5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00465ed7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00465ed9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465edb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00465ede  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00465ee0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ee1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ee2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465ee3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465ef1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465ef2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465ef4  c1e814                 -shr eax, 0x14
    cpu.eax >>= 20 /*0x14*/ % 32;
    // 00465ef7  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 00465efa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00465efc  e89f000000             -call 0x465fa0
    cpu.esp -= 4;
    sub_465fa0(app, cpu);
    if (cpu.terminate) return;
    // 00465f01  b860375100             -mov eax, 0x513760
    cpu.eax = 5322592 /*0x513760*/;
    // 00465f06  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 00465f09  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00465f0c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00465f0e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00465f11  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00465f14  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00465f16  89841160375100         -mov dword ptr [ecx + edx + 0x513760], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5322592) /* 0x513760 */ + cpu.edx * 1) = cpu.eax;
    // 00465f1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465f1f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465f31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465f32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465f34  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00465f37  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 00465f3a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00465f3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00465f41  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00465f44  d3e0                   +shl eax, cl
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
    // 00465f46  85829c375100           -test dword ptr [edx + 0x51379c], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5322652) /* 0x51379c */) & cpu.eax));
    // 00465f4c  7408                   -je 0x465f56
    if (cpu.flags.zf)
    {
        goto L_0x00465f56;
    }
    // 00465f4e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00465f53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465f56:
    // 00465f56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465f58  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465f60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00465f63  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 00465f66  83fa10                 +cmp edx, 0x10
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
    // 00465f69  7d17                   -jge 0x465f82
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00465f82;
    }
    // 00465f6b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465f6c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00465f6f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00465f71  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00465f76  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00465f78  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00465f7a  210495603b5100         -and dword ptr [edx*4 + 0x513b60], eax
    app->getMemory<x86::reg32>(x86::reg32(5323616) /* 0x513b60 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.eax));
    // 00465f81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00465f82:
    // 00465f82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00465f84  e817000000             -call 0x465fa0
    cpu.esp -= 4;
    sub_465fa0(app, cpu);
    if (cpu.terminate) return;
    // 00465f89  b860375100             -mov eax, 0x513760
    cpu.eax = 5322592 /*0x513760*/;
    // 00465f8e  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00465f91  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00465f93  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00465f96  89827c375100           -mov dword ptr [edx + 0x51377c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5322620) /* 0x51377c */) = cpu.eax;
    // 00465f9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00465f9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465f9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_465fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465fa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465fa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465fa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00465fa4  b8ac3b5100             -mov eax, 0x513bac
    cpu.eax = 5323692 /*0x513bac*/;
L_0x00465fa9:
    // 00465fa9  0fbe10                 -movsx edx, byte ptr [eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 00465fac  83faff                 +cmp edx, -1
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
    // 00465faf  7e07                   -jle 0x465fb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00465fb8;
    }
    // 00465fb1  39ca                   +cmp edx, ecx
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
    // 00465fb3  7403                   -je 0x465fb8
    if (cpu.flags.zf)
    {
        goto L_0x00465fb8;
    }
    // 00465fb5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00465fb6  ebf1                   -jmp 0x465fa9
    goto L_0x00465fa9;
L_0x00465fb8:
    // 00465fb8  803800                 +cmp byte ptr [eax], 0
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
    // 00465fbb  7c03                   -jl 0x465fc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00465fc0;
    }
    // 00465fbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00465fc0:
    // 00465fc0  c64001ff               -mov byte ptr [eax + 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 255 /*0xff*/;
    // 00465fc4  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00465fc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00465fc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_465fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00465fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00465fd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00465fd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00465fd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00465fd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00465fd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465fd6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00465fd9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00465fdb  bfac3b5100             -mov edi, 0x513bac
    cpu.edi = 5323692 /*0x513bac*/;
    // 00465fe0  8915a83b5100           -mov dword ptr [0x513ba8], edx
    app->getMemory<x86::reg32>(x86::reg32(5323688) /* 0x513ba8 */) = cpu.edx;
L_0x00465fe6:
    // 00465fe6  0fbe37                 -movsx esi, byte ptr [edi]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edi)));
    // 00465fe9  83feff                 +cmp esi, -1
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
    // 00465fec  7e30                   -jle 0x46601e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046601e;
    }
    // 00465fee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00465ff0  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00465ff3  0560375100             +add eax, 0x513760
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5322592 /*0x513760*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00465ff8  8b6818                 -mov ebp, dword ptr [eax + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00465ffb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00465ffc  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00465fff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466000  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00466003  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466004  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00466007  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046600a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046600b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046600e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00466011  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466012  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00466014  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00466016  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00466017  e8f4010000             -call 0x466210
    cpu.esp -= 4;
    sub_466210(app, cpu);
    if (cpu.terminate) return;
    // 0046601c  ebc8                   -jmp 0x465fe6
    goto L_0x00465fe6;
L_0x0046601e:
    // 0046601e  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00466023  e808600100             -call 0x47c030
    cpu.esp -= 4;
    sub_47c030(app, cpu);
    if (cpu.terminate) return;
    // 00466028  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046602a  754d                   -jne 0x466079
    if (!cpu.flags.zf)
    {
        goto L_0x00466079;
    }
    // 0046602c  833da8f74f0000         +cmp dword ptr [0x4ff7a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240744) /* 0x4ff7a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466033  743b                   -je 0x466070
    if (cpu.flags.zf)
    {
        goto L_0x00466070;
    }
L_0x00466035:
    // 00466035  8b3da43b5100           -mov edi, dword ptr [0x513ba4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5323684) /* 0x513ba4 */);
    // 0046603b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046603d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046603f  7e38                   -jle 0x466079
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466079;
    }
    // 00466041  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x00466045:
    // 00466045  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00466049  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046604d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046604f  b9ac3b5100             -mov ecx, 0x513bac
    cpu.ecx = 5323692 /*0x513bac*/;
    // 00466054  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00466058  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0046605c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0046605f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
L_0x00466061:
    // 00466061  0fbe01                 -movsx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx)));
    // 00466064  83f8ff                 +cmp eax, -1
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
    // 00466067  7e51                   -jle 0x4660ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004660ba;
    }
    // 00466069  39f0                   +cmp eax, esi
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
    // 0046606b  7416                   -je 0x466083
    if (cpu.flags.zf)
    {
        goto L_0x00466083;
    }
L_0x0046606d:
    // 0046606d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046606e  ebf1                   -jmp 0x466061
    goto L_0x00466061;
L_0x00466070:
    // 00466070  833d34f54d0002         +cmp dword ptr [0x4df534], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466077  7dbc                   -jge 0x466035
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466035;
    }
L_0x00466079:
    // 00466079  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046607c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046607d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046607e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046607f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466080  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466081  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466082  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466083:
    // 00466083  ba60375100             -mov edx, 0x513760
    cpu.edx = 5322592 /*0x513760*/;
    // 00466088  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046608b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046608d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0046608f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466091  7407                   -je 0x46609a
    if (cpu.flags.zf)
    {
        goto L_0x0046609a;
    }
    // 00466093  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00466095  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466097  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0046609a:
    // 0046609a  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046609d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046609f  7408                   -je 0x4660a9
    if (cpu.flags.zf)
    {
        goto L_0x004660a9;
    }
    // 004660a1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004660a3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004660a5  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004660a9:
    // 004660a9  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004660ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004660ae  74bd                   -je 0x46606d
    if (cpu.flags.zf)
    {
        goto L_0x0046606d;
    }
    // 004660b0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004660b2  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004660b4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004660b8  ebb3                   -jmp 0x46606d
    goto L_0x0046606d;
L_0x004660ba:
    // 004660ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004660bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004660be  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004660c0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004660c2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004660c4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004660c6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004660c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004660ca  e841010000             -call 0x466210
    cpu.esp -= 4;
    sub_466210(app, cpu);
    if (cpu.terminate) return;
    // 004660cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004660d1  744e                   -je 0x466121
    if (cpu.flags.zf)
    {
        goto L_0x00466121;
    }
    // 004660d3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004660d6  3d00400000             +cmp eax, 0x4000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004660db  7d63                   -jge 0x466140
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466140;
    }
    // 004660dd  800da83b510004         -or byte ptr [0x513ba8], 4
    app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004660e4:
    // 004660e4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004660e8  81f900400000           +cmp ecx, 0x4000
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
    // 004660ee  7d60                   -jge 0x466150
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466150;
    }
    // 004660f0  800da83b510001         -or byte ptr [0x513ba8], 1
    app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004660f7:
    // 004660f7  8b15a83b5100           -mov edx, dword ptr [0x513ba8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5323688) /* 0x513ba8 */);
    // 004660fd  8b3d34f54d00           -mov edi, dword ptr [0x4df534]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
    // 00466103  80ca10                 -or dl, 0x10
    cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00466106  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466109  7c56                   -jl 0x466161
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466161;
    }
    // 0046610b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046610f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00466113  8581603b5100           -test dword ptr [ecx + 0x513b60], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5323616) /* 0x513b60 */) & cpu.eax));
L_0x00466119:
    // 00466119  7406                   -je 0x466121
    if (cpu.flags.zf)
    {
        goto L_0x00466121;
    }
    // 0046611b  8915a83b5100           -mov dword ptr [0x513ba8], edx
    app->getMemory<x86::reg32>(x86::reg32(5323688) /* 0x513ba8 */) = cpu.edx;
L_0x00466121:
    // 00466121  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00466125  8b15a43b5100           -mov edx, dword ptr [0x513ba4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5323684) /* 0x513ba4 */);
    // 0046612b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046612e  46                     -inc esi
    (cpu.esi)++;
    // 0046612f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00466133  39d6                   +cmp esi, edx
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
    // 00466135  0f8d3effffff           -jge 0x466079
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466079;
    }
    // 0046613b  e905ffffff             -jmp 0x466045
    goto L_0x00466045;
L_0x00466140:
    // 00466140  3d00c00000             +cmp eax, 0xc000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466145  7e9d                   -jle 0x4660e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004660e4;
    }
    // 00466147  800da83b510008         +or byte ptr [0x513ba8], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0046614e  eb94                   -jmp 0x4660e4
    goto L_0x004660e4;
L_0x00466150:
    // 00466150  81f900c00000           +cmp ecx, 0xc000
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
    // 00466156  7e9f                   -jle 0x4660f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004660f7;
    }
    // 00466158  800da83b510002         +or byte ptr [0x513ba8], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5323688) /* 0x513ba8 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0046615f  eb96                   -jmp 0x4660f7
    goto L_0x004660f7;
L_0x00466161:
    // 00466161  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00466166  ebb1                   -jmp 0x466119
    goto L_0x00466119;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466173  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466176  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00466178  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466179  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046617a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046617b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046617c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046617e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466180  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466181  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00466185  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00466189  e882000000             -call 0x466210
    cpu.esp -= 4;
    sub_466210(app, cpu);
    if (cpu.terminate) return;
    // 0046618e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00466191  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466194  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466195  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466196  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466197  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4661a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004661a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004661a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004661a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004661a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004661a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004661a5  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004661a8  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 004661ad  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004661af  be805d4600             -mov esi, 0x465d80
    cpu.esi = 4611456 /*0x465d80*/;
    // 004661b4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004661b6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004661b8  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004661bc  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004661bf  7d0e                   -jge 0x4661cf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004661cf;
    }
    // 004661c1  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004661c8  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004661cc  89140c                 -mov dword ptr [esp + ecx], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1) = cpu.edx;
L_0x004661cf:
    // 004661cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004661d1  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004661d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004661d6  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004661da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004661db  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004661df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004661e0  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004661e4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004661e8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004661e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004661eb  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004661ef  e81c000000             -call 0x466210
    cpu.esp -= 4;
    sub_466210(app, cpu);
    if (cpu.terminate) return;
    // 004661f4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004661f8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004661fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004661fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004661fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004661fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004661ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466210  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466211  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466212  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466213  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466217  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466218  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046621c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046621d  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466221  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466222  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00466226  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466227  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046622b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046622c  e83fbefbff             -call 0x422070
    cpu.esp -= 4;
    sub_422070(app, cpu);
    if (cpu.terminate) return;
    // 00466231  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466232  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466233  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466234  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466240  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466241  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00466246  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466248  740c                   -je 0x466256
    if (cpu.flags.zf)
    {
        goto L_0x00466256;
    }
    // 0046624a  b81a000000             -mov eax, 0x1a
    cpu.eax = 26 /*0x1a*/;
    // 0046624f  e88c3efeff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 00466254  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466255  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466256:
    // 00466256  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0046625b  e8803efeff             -call 0x44a0e0
    cpu.esp -= 4;
    sub_44a0e0(app, cpu);
    if (cpu.terminate) return;
    // 00466260  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466261  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466273  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466274  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466275  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466276  833da03b510000         +cmp dword ptr [0x513ba0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5323680) /* 0x513ba0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046627d  7429                   -je 0x4662a8
    if (cpu.flags.zf)
    {
        goto L_0x004662a8;
    }
    // 0046627f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00466281:
    // 00466281  8b82f0fb4d00           -mov eax, dword ptr [edx + 0x4dfbf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5110768) /* 0x4dfbf0 */);
    // 00466287  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046628c  83f801                 +cmp eax, 1
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
    // 0046628f  750c                   -jne 0x46629d
    if (!cpu.flags.zf)
    {
        goto L_0x0046629d;
    }
    // 00466291  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00466293  05f0fb4d00             -add eax, 0x4dfbf0
    (cpu.eax) += x86::reg32(x86::sreg32(5110768 /*0x4dfbf0*/));
    // 00466298  e883010000             -call 0x466420
    cpu.esp -= 4;
    sub_466420(app, cpu);
    if (cpu.terminate) return;
L_0x0046629d:
    // 0046629d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004662a0  81fa60010000           +cmp edx, 0x160
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(352 /*0x160*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004662a6  75d9                   -jne 0x466281
    if (!cpu.flags.zf)
    {
        goto L_0x00466281;
    }
L_0x004662a8:
    // 004662a8  b903010000             -mov ecx, 0x103
    cpu.ecx = 259 /*0x103*/;
    // 004662ad  be04480000             -mov esi, 0x4804
    cpu.esi = 18436 /*0x4804*/;
    // 004662b2  bf04500000             -mov edi, 0x5004
    cpu.edi = 20484 /*0x5004*/;
    // 004662b7  bd044b0000             -mov ebp, 0x4b04
    cpu.ebp = 19204 /*0x4b04*/;
    // 004662bc  b8044d0000             -mov eax, 0x4d04
    cpu.eax = 19716 /*0x4d04*/;
    // 004662c1  ba041c0000             -mov edx, 0x1c04
    cpu.edx = 7172 /*0x1c04*/;
    // 004662c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004662c8  890d68fc4d00           -mov dword ptr [0x4dfc68], ecx
    app->getMemory<x86::reg32>(x86::reg32(5110888) /* 0x4dfc68 */) = cpu.ecx;
    // 004662ce  891d6cfc4d00           -mov dword ptr [0x4dfc6c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5110892) /* 0x4dfc6c */) = cpu.ebx;
    // 004662d4  893554fc4d00           -mov dword ptr [0x4dfc54], esi
    app->getMemory<x86::reg32>(x86::reg32(5110868) /* 0x4dfc54 */) = cpu.esi;
    // 004662da  893d58fc4d00           -mov dword ptr [0x4dfc58], edi
    app->getMemory<x86::reg32>(x86::reg32(5110872) /* 0x4dfc58 */) = cpu.edi;
    // 004662e0  892d5cfc4d00           -mov dword ptr [0x4dfc5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5110876) /* 0x4dfc5c */) = cpu.ebp;
    // 004662e6  a360fc4d00             -mov dword ptr [0x4dfc60], eax
    app->getMemory<x86::reg32>(x86::reg32(5110880) /* 0x4dfc60 */) = cpu.eax;
    // 004662eb  891564fc4d00           -mov dword ptr [0x4dfc64], edx
    app->getMemory<x86::reg32>(x86::reg32(5110884) /* 0x4dfc64 */) = cpu.edx;
    // 004662f1  b9030f0000             -mov ecx, 0xf03
    cpu.ecx = 3843 /*0xf03*/;
    // 004662f6  bb033b0000             -mov ebx, 0x3b03
    cpu.ebx = 15107 /*0x3b03*/;
    // 004662fb  be033c0000             -mov esi, 0x3c03
    cpu.esi = 15363 /*0x3c03*/;
    // 00466300  bf033d0000             -mov edi, 0x3d03
    cpu.edi = 15619 /*0x3d03*/;
    // 00466305  bd033e0000             -mov ebp, 0x3e03
    cpu.ebp = 15875 /*0x3e03*/;
    // 0046630a  b8033f0000             -mov eax, 0x3f03
    cpu.eax = 16131 /*0x3f03*/;
    // 0046630f  ba03400000             -mov edx, 0x4003
    cpu.edx = 16387 /*0x4003*/;
    // 00466314  890d70fc4d00           -mov dword ptr [0x4dfc70], ecx
    app->getMemory<x86::reg32>(x86::reg32(5110896) /* 0x4dfc70 */) = cpu.ecx;
    // 0046631a  891d7cfc4d00           -mov dword ptr [0x4dfc7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5110908) /* 0x4dfc7c */) = cpu.ebx;
    // 00466320  893578fc4d00           -mov dword ptr [0x4dfc78], esi
    app->getMemory<x86::reg32>(x86::reg32(5110904) /* 0x4dfc78 */) = cpu.esi;
    // 00466326  893d84fc4d00           -mov dword ptr [0x4dfc84], edi
    app->getMemory<x86::reg32>(x86::reg32(5110916) /* 0x4dfc84 */) = cpu.edi;
    // 0046632c  892d88fc4d00           -mov dword ptr [0x4dfc88], ebp
    app->getMemory<x86::reg32>(x86::reg32(5110920) /* 0x4dfc88 */) = cpu.ebp;
    // 00466332  a398fc4d00             -mov dword ptr [0x4dfc98], eax
    app->getMemory<x86::reg32>(x86::reg32(5110936) /* 0x4dfc98 */) = cpu.eax;
    // 00466337  89159cfc4d00           -mov dword ptr [0x4dfc9c], edx
    app->getMemory<x86::reg32>(x86::reg32(5110940) /* 0x4dfc9c */) = cpu.edx;
    // 0046633d  b903410000             -mov ecx, 0x4103
    cpu.ecx = 16643 /*0x4103*/;
    // 00466342  bb03420000             -mov ebx, 0x4203
    cpu.ebx = 16899 /*0x4203*/;
    // 00466347  be03430000             -mov esi, 0x4303
    cpu.esi = 17155 /*0x4303*/;
    // 0046634c  bf03440000             -mov edi, 0x4403
    cpu.edi = 17411 /*0x4403*/;
    // 00466351  a134f54d00             -mov eax, dword ptr [0x4df534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
    // 00466356  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00466358  890d94fc4d00           -mov dword ptr [0x4dfc94], ecx
    app->getMemory<x86::reg32>(x86::reg32(5110932) /* 0x4dfc94 */) = cpu.ecx;
    // 0046635e  891da8fc4d00           -mov dword ptr [0x4dfca8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5110952) /* 0x4dfca8 */) = cpu.ebx;
    // 00466364  8935a4fc4d00           -mov dword ptr [0x4dfca4], esi
    app->getMemory<x86::reg32>(x86::reg32(5110948) /* 0x4dfca4 */) = cpu.esi;
    // 0046636a  893d74fc4d00           -mov dword ptr [0x4dfc74], edi
    app->getMemory<x86::reg32>(x86::reg32(5110900) /* 0x4dfc74 */) = cpu.edi;
    // 00466370  892d50fc4d00           -mov dword ptr [0x4dfc50], ebp
    app->getMemory<x86::reg32>(x86::reg32(5110864) /* 0x4dfc50 */) = cpu.ebp;
    // 00466376  83f802                 +cmp eax, 2
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
    // 00466379  0f8c6e000000           -jl 0x4663ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004663ed;
    }
    // 0046637f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00466384  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00466386:
    // 00466386  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466389  898a5c3b5100           -mov dword ptr [edx + 0x513b5c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5323612) /* 0x513b5c */) = cpu.ecx;
    // 0046638f  83fa40                 +cmp edx, 0x40
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
    // 00466392  75f2                   -jne 0x466386
    if (!cpu.flags.zf)
    {
        goto L_0x00466386;
    }
    // 00466394  a1acfc4d00             -mov eax, dword ptr [0x4dfcac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110956) /* 0x4dfcac */);
    // 00466399  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046639b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004663a1  83fa02                 +cmp edx, 2
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
    // 004663a4  752b                   -jne 0x4663d1
    if (!cpu.flags.zf)
    {
        goto L_0x004663d1;
    }
    // 004663a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004663a8  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004663ab  83fa10                 +cmp edx, 0x10
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
    // 004663ae  7d21                   -jge 0x4663d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004663d1;
    }
    // 004663b0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004663b2  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004663b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004663ba  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004663bd  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004663bf  8b1c95603b5100         -mov ebx, dword ptr [edx*4 + 0x513b60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5323616) /* 0x513b60 */ + cpu.edx * 4);
    // 004663c6  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004663c8  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004663ca  891c95603b5100         -mov dword ptr [edx*4 + 0x513b60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5323616) /* 0x513b60 */ + cpu.edx * 4) = cpu.ebx;
L_0x004663d1:
    // 004663d1  a1b4fc4d00             -mov eax, dword ptr [0x4dfcb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110964) /* 0x4dfcb4 */);
    // 004663d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004663d8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004663de  83fa02                 +cmp edx, 2
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
    // 004663e1  750a                   -jne 0x4663ed
    if (!cpu.flags.zf)
    {
        goto L_0x004663ed;
    }
    // 004663e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004663e5  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004663e8  83fa10                 +cmp edx, 0x10
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
    // 004663eb  7c07                   -jl 0x4663f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004663f4;
    }
L_0x004663ed:
    // 004663ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004663ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004663ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004663f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004663f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004663f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004663f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004663f4:
    // 004663f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004663f6  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004663f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004663fe  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00466401  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00466403  8b3495603b5100         -mov esi, dword ptr [edx*4 + 0x513b60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5323616) /* 0x513b60 */ + cpu.edx * 4);
    // 0046640a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0046640c  21c6                   -and esi, eax
    cpu.esi &= x86::reg32(x86::sreg32(cpu.eax));
    // 0046640e  893495603b5100         -mov dword ptr [edx*4 + 0x513b60], esi
    app->getMemory<x86::reg32>(x86::reg32(5323616) /* 0x513b60 */ + cpu.edx * 4) = cpu.esi;
    // 00466415  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466416  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466417  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466418  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466419  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046641a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046641b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_466420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466423  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466424  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466425  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466426  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00466429  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046642d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00466431  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00466435  8b0da03b5100           -mov ecx, dword ptr [0x513ba0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5323680) /* 0x513ba0 */);
    // 0046643b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046643d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046643f  c1f81c                 -sar eax, 0x1c
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (28 /*0x1c*/ % 32));
    // 00466442  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466445  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00466449  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046644d  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046644f  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00466451  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00466453  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00466456  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00466459  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046645d  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00466460  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 00466463  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00466467  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0046646a  81e600ff0000           -and esi, 0xff00
    cpu.esi &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00466470  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00466472  81e300ff0000           -and ebx, 0xff00
    cpu.ebx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00466478  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x0046647b:
    // 0046647b  a1a03b5100             -mov eax, dword ptr [0x513ba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323680) /* 0x513ba0 */);
    // 00466480  3b38                   +cmp edi, dword ptr [eax]
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
    // 00466482  0f8d7f010000           -jge 0x466607
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466607;
    }
    // 00466488  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046648c  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046648e  7406                   -je 0x466496
    if (cpu.flags.zf)
    {
        goto L_0x00466496;
    }
L_0x00466490:
    // 00466490  83c114                 +add ecx, 0x14
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00466493  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00466494  ebe5                   -jmp 0x46647b
    goto L_0x0046647b;
L_0x00466496:
    // 00466496  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046649a  3b5104                 +cmp edx, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046649d  75f1                   -jne 0x466490
    if (!cpu.flags.zf)
    {
        goto L_0x00466490;
    }
    // 0046649f  8d830080ffff           -lea eax, [ebx - 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-32768) /* -0x8000 */);
    // 004664a5  8dae0080ffff           -lea ebp, [esi - 0x8000]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-32768) /* -0x8000 */);
    // 004664ab  39f3                   +cmp ebx, esi
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
    // 004664ad  0f8dcb000000           -jge 0x46657e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046657e;
    }
    // 004664b3  81fb00800000           +cmp ebx, 0x8000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004664b9  0f8d8b000000           -jge 0x46654a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046654a;
    }
    // 004664bf  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004664c2  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004664c5  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004664c7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004664c9  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004664cb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004664cd  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004664d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004664d2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004664d5  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004664d8  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004664da  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004664dd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004664df  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004664e2  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004664e5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004664e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004664e9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004664ec  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004664ef  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004664f1  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004664f4  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x004664f7:
    // 004664f7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004664f9:
    // 004664f9  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004664fc  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 004664ff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00466501  0f8cf2000000           -jl 0x4665f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004665f9;
    }
    // 00466507  81fbff000000           +cmp ebx, 0xff
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
    // 0046650d  7e05                   -jle 0x466514
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466514;
    }
    // 0046650f  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
L_0x00466514:
    // 00466514  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00466516  0f8ce4000000           -jl 0x466600
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466600;
    }
    // 0046651c  81feff000000           +cmp esi, 0xff
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
    // 00466522  7e05                   -jle 0x466529
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466529;
    }
    // 00466524  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
L_0x00466529:
    // 00466529  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046652b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046652e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00466531  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00466533  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00466535  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00466538  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046653a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046653e  40                     -inc eax
    (cpu.eax)++;
    // 0046653f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00466541  83c114                 +add ecx, 0x14
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00466544  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00466545  e931ffffff             -jmp 0x46647b
    goto L_0x0046647b;
L_0x0046654a:
    // 0046654a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046654d  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00466550  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466552  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00466555  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00466557  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046655a  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046655d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046655f  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00466562  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00466564  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00466567  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00466569  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046656b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046656e  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00466571  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00466573  c1f80f                 +sar eax, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00466576  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00466579  e979ffffff             -jmp 0x4664f7
    goto L_0x004664f7;
L_0x0046657e:
    // 0046657e  81fb00800000           +cmp ebx, 0x8000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466584  7e3d                   -jle 0x4665c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004665c3;
    }
    // 00466586  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00466589  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046658c  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046658e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00466590  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00466592  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00466595  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00466597  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046659a  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046659d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046659f  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004665a2  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004665a5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004665a7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004665a9  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004665ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004665ae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004665b1  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004665b4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004665b6  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004665b9  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004665bc  29c3                   +sub ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004665be  e936ffffff             -jmp 0x4664f9
    goto L_0x004664f9;
L_0x004665c3:
    // 004665c3  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004665c6  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004665c9  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004665cb  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004665ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004665d0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004665d3  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004665d6  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004665d8  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004665db  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004665dd  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004665e0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004665e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004665e4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004665e7  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004665ea  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004665ec  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004665ef  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004665f2  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004665f4  e900ffffff             -jmp 0x4664f9
    goto L_0x004664f9;
L_0x004665f9:
    // 004665f9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004665fb  e914ffffff             -jmp 0x466514
    goto L_0x00466514;
L_0x00466600:
    // 00466600  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00466602  e922ffffff             -jmp 0x466529
    goto L_0x00466529;
L_0x00466607:
    // 00466607  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046660a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046660b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046660c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046660d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046660e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046660f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466620  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466621  8b15a03b5100           -mov edx, dword ptr [0x513ba0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5323680) /* 0x513ba0 */);
    // 00466627  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466629  7502                   -jne 0x46662d
    if (!cpu.flags.zf)
    {
        goto L_0x0046662d;
    }
    // 0046662b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046662c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046662d:
    // 0046662d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046662f  e858400100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00466634  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466635  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466640  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466641  b8e0d94b00             -mov eax, 0x4bd9e0
    cpu.eax = 4970976 /*0x4bd9e0*/;
    // 00466646  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00466648  e823620100             -call 0x47c870
    cpu.esp -= 4;
    sub_47c870(app, cpu);
    if (cpu.terminate) return;
    // 0046664d  a3a03b5100             -mov dword ptr [0x513ba0], eax
    app->getMemory<x86::reg32>(x86::reg32(5323680) /* 0x513ba0 */) = cpu.eax;
    // 00466652  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466660  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466662  e889bdfbff             -call 0x4223f0
    cpu.esp -= 4;
    sub_4223f0(app, cpu);
    if (cpu.terminate) return;
    // 00466667  2eff15e4754b00         -call dword ptr cs:[0x4b75e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945380) /* 0x4b75e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0046666e  83f810                 +cmp eax, 0x10
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
    // 00466671  7238                   -jb 0x4666ab
    if (cpu.flags.cf)
    {
        goto L_0x004666ab;
    }
    // 00466673  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00466678:
    // 00466678  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0046667d  a3a43b5100             -mov dword ptr [0x513ba4], eax
    app->getMemory<x86::reg32>(x86::reg32(5323684) /* 0x513ba4 */) = cpu.eax;
    // 00466682  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466684  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00466685:
    // 00466685  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00466688  89905c3b5100           -mov dword ptr [eax + 0x513b5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5323612) /* 0x513b5c */) = cpu.edx;
    // 0046668e  83f840                 +cmp eax, 0x40
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
    // 00466691  75f2                   -jne 0x466685
    if (!cpu.flags.zf)
    {
        goto L_0x00466685;
    }
    // 00466693  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 00466698  b860375100             -mov eax, 0x513760
    cpu.eax = 5322592 /*0x513760*/;
    // 0046669d  e8faa50100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 004666a2  c605ac3b5100ff         -mov byte ptr [0x513bac], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5323692) /* 0x513bac */) = 255 /*0xff*/;
    // 004666a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004666aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004666ab:
    // 004666ab  2eff15e4754b00         -call dword ptr cs:[0x4b75e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945380) /* 0x4b75e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004666b2  ebc4                   -jmp 0x466678
    goto L_0x00466678;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4666c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004666c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004666c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004666c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004666c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004666c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004666c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004666c6  a12c014e00             -mov eax, dword ptr [0x4e012c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5112108) /* 0x4e012c */);
    // 004666cb  8b1530014e00           -mov edx, dword ptr [0x4e0130]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5112112) /* 0x4e0130 */);
    // 004666d1  8b0d34014e00           -mov ecx, dword ptr [0x4e0134]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5112116) /* 0x4e0134 */);
    // 004666d7  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004666d9  8b1d38014e00           -mov ebx, dword ptr [0x4e0138]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5112120) /* 0x4e0138 */);
    // 004666df  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004666e1  8b353c014e00           -mov esi, dword ptr [0x4e013c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5112124) /* 0x4e013c */);
    // 004666e7  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004666e9  8b3d40014e00           -mov edi, dword ptr [0x4e0140]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5112128) /* 0x4e0140 */);
    // 004666ef  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004666f1  8b2d44014e00           -mov ebp, dword ptr [0x4e0144]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5112132) /* 0x4e0144 */);
    // 004666f7  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004666f9  8b1548014e00           -mov edx, dword ptr [0x4e0148]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5112136) /* 0x4e0148 */);
    // 004666ff  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00466701  8b0d4c014e00           -mov ecx, dword ptr [0x4e014c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5112140) /* 0x4e014c */);
    // 00466707  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00466709  8b1d50014e00           -mov ebx, dword ptr [0x4e0150]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5112144) /* 0x4e0150 */);
    // 0046670f  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466711  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466713  e8e8e5f9ff             -call 0x404d00
    cpu.esp -= 4;
    sub_404d00(app, cpu);
    if (cpu.terminate) return;
    // 00466718  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0046671a  740c                   -je 0x466728
    if (cpu.flags.zf)
    {
        goto L_0x00466728;
    }
    // 0046671c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00466721  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466722  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466723  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466724  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466725  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466726  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466727  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466728:
    // 00466728  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046672a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046672b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046672c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046672d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046672e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046672f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466730  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466741  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466742  8b0da0f14d00           -mov ecx, dword ptr [0x4df1a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 00466748  3b0d2cf54d00           +cmp ecx, dword ptr [0x4df52c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046674e  7e2d                   -jle 0x46677d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046677d;
    }
    // 00466750  8b90b8020000           -mov edx, dword ptr [eax + 0x2b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(696) /* 0x2b8 */);
L_0x00466756:
    // 00466756  b9703d0200             -mov ecx, 0x23d70
    cpu.ecx = 146800 /*0x23d70*/;
    // 0046675b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046675d  7e26                   -jle 0x466785
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466785;
    }
    // 0046675f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00466761:
    // 00466761  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00466763  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00466765  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00466768  c1e810                 +shr eax, 0x10
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
    // 0046676b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046676d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046676f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00466772  c1e210                 +shl edx, 0x10
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
    // 00466775  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00466777  c1f810                 +sar eax, 0x10
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
    // 0046677a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046677b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046677c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046677d:
    // 0046677d  8b90a0030000           -mov edx, dword ptr [eax + 0x3a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(928) /* 0x3a0 */);
    // 00466783  ebd1                   -jmp 0x466756
    goto L_0x00466756;
L_0x00466785:
    // 00466785  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00466787  f7d8                   +neg eax
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
    // 00466789  ebd6                   -jmp 0x466761
    goto L_0x00466761;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466791  66833d988f4c0000       +cmp word ptr [0x4c8f98], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5017496) /* 0x4c8f98 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00466799  750b                   -jne 0x4667a6
    if (!cpu.flags.zf)
    {
        goto L_0x004667a6;
    }
    // 0046679b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046679d  66891d988f4c00         -mov word ptr [0x4c8f98], bx
    app->getMemory<x86::reg16>(x86::reg32(5017496) /* 0x4c8f98 */) = cpu.bx;
    // 004667a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004667a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004667a6:
    // 004667a6  a1c23b5100             -mov eax, dword ptr [0x513bc2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323714) /* 0x513bc2 */);
    // 004667ab  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004667ae  e8adc6fbff             -call 0x422e60
    cpu.esp -= 4;
    sub_422e60(app, cpu);
    if (cpu.terminate) return;
    // 004667b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004667b5  66891d988f4c00         -mov word ptr [0x4c8f98], bx
    app->getMemory<x86::reg16>(x86::reg32(5017496) /* 0x4c8f98 */) = cpu.bx;
    // 004667bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004667bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4667c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004667c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004667c1  833d8c8f4c0000         +cmp dword ptr [0x4c8f8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004667c8  7516                   -jne 0x4667e0
    if (!cpu.flags.zf)
    {
        goto L_0x004667e0;
    }
L_0x004667ca:
    // 004667ca  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004667cc  890d908f4c00           -mov dword ptr [0x4c8f90], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */) = cpu.ecx;
    // 004667d2  890d948f4c00           -mov dword ptr [0x4c8f94], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */) = cpu.ecx;
    // 004667d8  890d8c8f4c00           -mov dword ptr [0x4c8f8c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = cpu.ecx;
    // 004667de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004667df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004667e0:
    // 004667e0  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 004667e5  c1f810                 +sar eax, 0x10
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
    // 004667e8  e873c6fbff             -call 0x422e60
    cpu.esp -= 4;
    sub_422e60(app, cpu);
    if (cpu.terminate) return;
    // 004667ed  ebdb                   -jmp 0x4667ca
    goto L_0x004667ca;
}

/* align: skip 0x00 */
void Application::sub_4667f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004667f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004667f1  8b35c0f14d00           -mov esi, dword ptr [0x4df1c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108160) /* 0x4df1c0 */);
    // 004667f7  3b359c8f4c00           +cmp esi, dword ptr [0x4c8f9c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017500) /* 0x4c8f9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004667fd  7d02                   -jge 0x466801
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466801;
    }
    // 004667ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466800  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466801:
    // 00466801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466802  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00466804  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00466806  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00466808  c1f903                 -sar ecx, 3
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (3 /*0x3*/ % 32));
    // 0046680b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046680c  8b35c0f14d00           -mov esi, dword ptr [0x4df1c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108160) /* 0x4df1c0 */);
    // 00466812  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00466814  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00466816  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00466818  89359c8f4c00           -mov dword ptr [0x4c8f9c], esi
    app->getMemory<x86::reg32>(x86::reg32(5017500) /* 0x4c8f9c */) = cpu.esi;
    // 0046681e  8b35be3b5100           -mov esi, dword ptr [0x513bbe]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5323710) /* 0x513bbe */);
    // 00466824  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00466826  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00466829  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046682e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00466830  e86bc2fbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00466835  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466836  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466837  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466842  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466843  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466844  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466845  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00466848  ba10270000             -mov edx, 0x2710
    cpu.edx = 10000 /*0x2710*/;
    // 0046684d  b9c8000000             -mov ecx, 0xc8
    cpu.ecx = 200 /*0xc8*/;
    // 00466852  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00466854  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00466856  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00466859  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046685d  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 00466861  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00466865  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 00466867  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0046686b  8854243c               -mov byte ptr [esp + 0x3c], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.dl;
    // 0046686f  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 00466871  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466873  8874243d               -mov byte ptr [esp + 0x3d], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(61) /* 0x3d */) = cpu.dh;
    // 00466877  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00466879  89742444               -mov dword ptr [esp + 0x44], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.esi;
    // 0046687d  e892c6fbff             -call 0x422f14
    cpu.esp -= 4;
    sub_422f14(app, cpu);
    if (cpu.terminate) return;
    // 00466882  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00466885  7d0b                   -jge 0x466892
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466892;
    }
L_0x00466887:
    // 00466887  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466889  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0046688c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046688d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046688e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046688f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466890  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466891  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466892:
    // 00466892  b303                   -mov bl, 3
    cpu.bl = 3 /*0x3*/;
    // 00466894  bd10270000             -mov ebp, 0x2710
    cpu.ebp = 10000 /*0x2710*/;
    // 00466899  b9e4720000             -mov ecx, 0x72e4
    cpu.ecx = 29412 /*0x72e4*/;
    // 0046689e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004668a0  66a3c03b5100           -mov word ptr [0x513bc0], ax
    app->getMemory<x86::reg16>(x86::reg32(5323712) /* 0x513bc0 */) = cpu.ax;
    // 004668a6  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004668aa  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004668ae  881c24                 -mov byte ptr [esp], bl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.bl;
    // 004668b1  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004668b5  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004668b9  bbffffff00             -mov ebx, 0xffffff
    cpu.ebx = 16777215 /*0xffffff*/;
    // 004668be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004668c0  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004668c4  e84bc6fbff             -call 0x422f14
    cpu.esp -= 4;
    sub_422f14(app, cpu);
    if (cpu.terminate) return;
    // 004668c9  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004668cc  7cb9                   -jl 0x466887
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466887;
    }
    // 004668ce  b709                   -mov bh, 9
    cpu.bh = 9 /*0x9*/;
    // 004668d0  66a3c23b5100           -mov word ptr [0x513bc2], ax
    app->getMemory<x86::reg16>(x86::reg32(5323714) /* 0x513bc2 */) = cpu.ax;
    // 004668d6  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004668da  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004668de  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004668e2  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004668e6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004668e8  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004668ec  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004668f0  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004668f4  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004668f8  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004668fc  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 00466900  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 00466904  31ea                   -xor edx, ebp
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00466906  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00466908  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0046690c  31e8                   -xor eax, ebp
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046690e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00466910  883c24                 -mov byte ptr [esp], bh
    app->getMemory<x86::reg8>(cpu.esp) = cpu.bh;
    // 00466913  e8fcc5fbff             -call 0x422f14
    cpu.esp -= 4;
    sub_422f14(app, cpu);
    if (cpu.terminate) return;
    // 00466918  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0046691b  0f8c66ffffff           -jl 0x466887
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466887;
    }
    // 00466921  66a3c43b5100           -mov word ptr [0x513bc4], ax
    app->getMemory<x86::reg16>(x86::reg32(5323716) /* 0x513bc4 */) = cpu.ax;
    // 00466927  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046692c  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0046692f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466930  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466931  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466932  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466933  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466934  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466940  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466947  7501                   -jne 0x46694a
    if (!cpu.flags.zf)
    {
        goto L_0x0046694a;
    }
    // 00466949  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046694a:
    // 0046694a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046694b  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00466950  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466952  e819cafbff             -call 0x423370
    cpu.esp -= 4;
    sub_423370(app, cpu);
    if (cpu.terminate) return;
    // 00466957  890d688f4c00           -mov dword ptr [0x4c8f68], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */) = cpu.ecx;
    // 0046695d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046695e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_466960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466962  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466964  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466965  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466966  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00466969  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046696b  833d6c8f4c0000         +cmp dword ptr [0x4c8f6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017452) /* 0x4c8f6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466972  0f84e3000000           -je 0x466a5b
    if (cpu.flags.zf)
    {
        goto L_0x00466a5b;
    }
    // 00466978  3b05888f4c00           +cmp eax, dword ptr [0x4c8f88]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046697e  0f85d7000000           -jne 0x466a5b
    if (!cpu.flags.zf)
    {
        goto L_0x00466a5b;
    }
    // 00466984  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046698b  7e0d                   -jle 0x46699a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046699a;
    }
    // 0046698d  833d14104e0002         +cmp dword ptr [0x4e1014], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466994  0f85cb000000           -jne 0x466a65
    if (!cpu.flags.zf)
    {
        goto L_0x00466a65;
    }
L_0x0046699a:
    // 0046699a  83b95c01000000         +cmp dword ptr [ecx + 0x15c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004669a1  0f8cca000000           -jl 0x466a71
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466a71;
    }
    // 004669a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004669a9  668b914c010000         -mov dx, word ptr [ecx + 0x14c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
    // 004669b0  a37c8f4c00             -mov dword ptr [0x4c8f7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5017468) /* 0x4c8f7c */) = cpu.eax;
    // 004669b5  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004669b8  0f85c9000000           -jne 0x466a87
    if (!cpu.flags.zf)
    {
        goto L_0x00466a87;
    }
    // 004669be  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004669c5  744c                   -je 0x466a13
    if (cpu.flags.zf)
    {
        goto L_0x00466a13;
    }
    // 004669c7  be44020000             -mov esi, 0x244
    cpu.esi = 580 /*0x244*/;
    // 004669cc  bb10270000             -mov ebx, 0x2710
    cpu.ebx = 10000 /*0x2710*/;
    // 004669d1  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004669d5  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004669d8  8b3dc0f14d00           -mov edi, dword ptr [0x4df1c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5108160) /* 0x4df1c0 */);
    // 004669de  66f7c70100             +test di, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & 1 /*0x1*/));
    // 004669e3  0f84b5000000           -je 0x466a9e
    if (cpu.flags.zf)
    {
        goto L_0x00466a9e;
    }
    // 004669e9  c744241c14000000       -mov dword ptr [esp + 0x1c], 0x14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 20 /*0x14*/;
L_0x004669f1:
    // 004669f1  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004669f3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004669f7  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004669fb  e8f0fdffff             -call 0x4667f0
    cpu.esp -= 4;
    sub_4667f0(app, cpu);
    if (cpu.terminate) return;
    // 00466a00  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00466a05  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466a07  8915ac8f4c00           -mov dword ptr [0x4c8fac], edx
    app->getMemory<x86::reg32>(x86::reg32(5017516) /* 0x4c8fac */) = cpu.edx;
    // 00466a0d  891d788f4c00           -mov dword ptr [0x4c8f78], ebx
    app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */) = cpu.ebx;
L_0x00466a13:
    // 00466a13  8b35848f4c00           -mov esi, dword ptr [0x4c8f84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 00466a19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00466a1b  7412                   -je 0x466a2f
    if (cpu.flags.zf)
    {
        goto L_0x00466a2f;
    }
    // 00466a1d  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00466a20  893d848f4c00           -mov dword ptr [0x4c8f84], edi
    app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */) = cpu.edi;
    // 00466a26  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00466a28  7505                   -jne 0x466a2f
    if (!cpu.flags.zf)
    {
        goto L_0x00466a2f;
    }
    // 00466a2a  e891fdffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
L_0x00466a2f:
    // 00466a2f  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466a36  7510                   -jne 0x466a48
    if (!cpu.flags.zf)
    {
        goto L_0x00466a48;
    }
    // 00466a38  833d7c8f4c0000         +cmp dword ptr [0x4c8f7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017468) /* 0x4c8f7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466a3f  7507                   -jne 0x466a48
    if (!cpu.flags.zf)
    {
        goto L_0x00466a48;
    }
    // 00466a41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00466a43  e814010000             -call 0x466b5c
    cpu.esp -= 4;
    sub_466b5c(app, cpu);
    if (cpu.terminate) return;
L_0x00466a48:
    // 00466a48  8b1dac8f4c00           -mov ebx, dword ptr [0x4c8fac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017516) /* 0x4c8fac */);
    // 00466a4e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00466a50  7e59                   -jle 0x466aab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466aab;
    }
    // 00466a52  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00466a55  8935ac8f4c00           -mov dword ptr [0x4c8fac], esi
    app->getMemory<x86::reg32>(x86::reg32(5017516) /* 0x4c8fac */) = cpu.esi;
L_0x00466a5b:
    // 00466a5b  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00466a5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466a64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466a65:
    // 00466a65  e856fdffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
    // 00466a6a  e821fdffff             -call 0x466790
    cpu.esp -= 4;
    sub_466790(app, cpu);
    if (cpu.terminate) return;
    // 00466a6f  ebea                   -jmp 0x466a5b
    goto L_0x00466a5b;
L_0x00466a71:
    // 00466a71  e84afdffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
    // 00466a76  e815fdffff             -call 0x466790
    cpu.esp -= 4;
    sub_466790(app, cpu);
    if (cpu.terminate) return;
    // 00466a7b  c7057c8f4c0001000000   -mov dword ptr [0x4c8f7c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017468) /* 0x4c8f7c */) = 1 /*0x1*/;
    // 00466a85  ebd4                   -jmp 0x466a5b
    goto L_0x00466a5b;
L_0x00466a87:
    // 00466a87  e834fdffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
    // 00466a8c  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00466a91  e8fafcffff             -call 0x466790
    cpu.esp -= 4;
    sub_466790(app, cpu);
    if (cpu.terminate) return;
    // 00466a96  892d788f4c00           -mov dword ptr [0x4c8f78], ebp
    app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */) = cpu.ebp;
    // 00466a9c  ebbd                   -jmp 0x466a5b
    goto L_0x00466a5b;
L_0x00466a9e:
    // 00466a9e  c744241c54010000       -mov dword ptr [esp + 0x1c], 0x154
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 340 /*0x154*/;
    // 00466aa6  e946ffffff             -jmp 0x4669f1
    goto L_0x004669f1;
L_0x00466aab:
    // 00466aab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00466aad  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 00466ab2  e8a5040000             -call 0x466f5c
    cpu.esp -= 4;
    sub_466f5c(app, cpu);
    if (cpu.terminate) return;
    // 00466ab7  893dac8f4c00           -mov dword ptr [0x4c8fac], edi
    app->getMemory<x86::reg32>(x86::reg32(5017516) /* 0x4c8fac */) = cpu.edi;
    // 00466abd  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00466ac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ac1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ac2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ac3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ac4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ac5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466ac6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466ad0  833d6c8f4c0000         +cmp dword ptr [0x4c8f6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017452) /* 0x4c8f6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466ad7  7433                   -je 0x466b0c
    if (cpu.flags.zf)
    {
        goto L_0x00466b0c;
    }
    // 00466ad9  3b05888f4c00           +cmp eax, dword ptr [0x4c8f88]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466adf  752b                   -jne 0x466b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00466b0c;
    }
    // 00466ae1  833d7c8f4c0000         +cmp dword ptr [0x4c8f7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017468) /* 0x4c8f7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466ae8  7522                   -jne 0x466b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00466b0c;
    }
    // 00466aea  833d34f54d0001         +cmp dword ptr [0x4df534], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466af1  7e09                   -jle 0x466afc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466afc;
    }
    // 00466af3  833d14104e0002         +cmp dword ptr [0x4e1014], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466afa  7506                   -jne 0x466b02
    if (!cpu.flags.zf)
    {
        goto L_0x00466b02;
    }
L_0x00466afc:
    // 00466afc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00466b01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466b02:
    // 00466b02  e8b9fcffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
    // 00466b07  e884fcffff             -call 0x466790
    cpu.esp -= 4;
    sub_466790(app, cpu);
    if (cpu.terminate) return;
L_0x00466b0c:
    // 00466b0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466b0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_466b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00466b10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_466b5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00466b5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466b5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466b5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466b5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466b60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466b61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466b62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00466b64  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00466b67  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00466b6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00466b6c  e8cffbffff             -call 0x466740
    cpu.esp -= 4;
    sub_466740(app, cpu);
    if (cpu.terminate) return;
    // 00466b71  83f802                 +cmp eax, 2
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
    // 00466b74  7c41                   -jl 0x466bb7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00466bb7;
    }
    // 00466b76  83f805                 +cmp eax, 5
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
    // 00466b79  7d43                   -jge 0x466bbe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466bbe;
    }
    // 00466b7b  bec4090000             -mov esi, 0x9c4
    cpu.esi = 2500 /*0x9c4*/;
    // 00466b80  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
L_0x00466b85:
    // 00466b85  8b8284010000           -mov eax, dword ptr [edx + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(388) /* 0x184 */);
    // 00466b8b  a3708f4c00             -mov dword ptr [0x4c8f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5017456) /* 0x4c8f70 */) = cpu.eax;
    // 00466b90  48                     -dec eax
    (cpu.eax)--;
    // 00466b91  83f80e                 +cmp eax, 0xe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466b94  7707                   -ja 0x466b9d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00466b9d;
    }
    // 00466b96  ff2485206b4600         -jmp dword ptr [eax*4 + 0x466b20]
    cpu.ip = app->getMemory<x86::reg32>(4614944 + cpu.eax * 4); goto dynamic_jump;
  case 0x00466b9d:
L_0x00466b9d:
    // 00466b9d  e81efcffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00466ba2:
L_0x00466ba2:
    // 00466ba2  8935948f4c00           -mov dword ptr [0x4c8f94], esi
    app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */) = cpu.esi;
    // 00466ba8  893d908f4c00           -mov dword ptr [0x4c8f90], edi
    app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */) = cpu.edi;
L_0x00466bae:
    // 00466bae  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00466bb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00466bb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00466bb7:
    // 00466bb7  e804fcffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
    // 00466bbc  ebf0                   -jmp 0x466bae
    goto L_0x00466bae;
L_0x00466bbe:
    // 00466bbe  83f80a                 +cmp eax, 0xa
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
    // 00466bc1  7d0c                   -jge 0x466bcf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466bcf;
    }
    // 00466bc3  beb80b0000             -mov esi, 0xbb8
    cpu.esi = 3000 /*0xbb8*/;
    // 00466bc8  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
    // 00466bcd  ebb6                   -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466bcf:
    // 00466bcf  83f80f                 +cmp eax, 0xf
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
    // 00466bd2  7d0c                   -jge 0x466be0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466be0;
    }
    // 00466bd4  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 00466bd9  bf07000000             -mov edi, 7
    cpu.edi = 7 /*0x7*/;
    // 00466bde  eba5                   -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466be0:
    // 00466be0  83f814                 +cmp eax, 0x14
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
    // 00466be3  7d0c                   -jge 0x466bf1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466bf1;
    }
    // 00466be5  bea00f0000             -mov esi, 0xfa0
    cpu.esi = 4000 /*0xfa0*/;
    // 00466bea  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 00466bef  eb94                   -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466bf1:
    // 00466bf1  83f81e                 +cmp eax, 0x1e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466bf4  7d0c                   -jge 0x466c02
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c02;
    }
    // 00466bf6  be94110000             -mov esi, 0x1194
    cpu.esi = 4500 /*0x1194*/;
    // 00466bfb  bf09000000             -mov edi, 9
    cpu.edi = 9 /*0x9*/;
    // 00466c00  eb83                   -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c02:
    // 00466c02  83f828                 +cmp eax, 0x28
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c05  7d0f                   -jge 0x466c16
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c16;
    }
    // 00466c07  be88130000             -mov esi, 0x1388
    cpu.esi = 5000 /*0x1388*/;
    // 00466c0c  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 00466c11  e96fffffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c16:
    // 00466c16  83f83c                 +cmp eax, 0x3c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c19  7d0f                   -jge 0x466c2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c2a;
    }
    // 00466c1b  be94110000             -mov esi, 0x1194
    cpu.esi = 4500 /*0x1194*/;
    // 00466c20  bf0b000000             -mov edi, 0xb
    cpu.edi = 11 /*0xb*/;
    // 00466c25  e95bffffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c2a:
    // 00466c2a  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c2d  7d0f                   -jge 0x466c3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c3e;
    }
    // 00466c2f  bea00f0000             -mov esi, 0xfa0
    cpu.esi = 4000 /*0xfa0*/;
    // 00466c34  bf0c000000             -mov edi, 0xc
    cpu.edi = 12 /*0xc*/;
    // 00466c39  e947ffffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c3e:
    // 00466c3e  83f864                 +cmp eax, 0x64
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
    // 00466c41  7d0f                   -jge 0x466c52
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c52;
    }
    // 00466c43  bea00f0000             -mov esi, 0xfa0
    cpu.esi = 4000 /*0xfa0*/;
    // 00466c48  bf0d000000             -mov edi, 0xd
    cpu.edi = 13 /*0xd*/;
    // 00466c4d  e933ffffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c52:
    // 00466c52  3d8c000000             +cmp eax, 0x8c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c57  7d0f                   -jge 0x466c68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c68;
    }
    // 00466c59  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 00466c5e  bf0e000000             -mov edi, 0xe
    cpu.edi = 14 /*0xe*/;
    // 00466c63  e91dffffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c68:
    // 00466c68  3da4060000             +cmp eax, 0x6a4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1700 /*0x6a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c6d  7d0f                   -jge 0x466c7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c7e;
    }
    // 00466c6f  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 00466c74  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 00466c79  e907ffffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c7e:
    // 00466c7e  3dc8000000             +cmp eax, 0xc8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466c83  7d0f                   -jge 0x466c94
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466c94;
    }
    // 00466c85  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 00466c8a  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 00466c8f  e9f1feffff             -jmp 0x466b85
    goto L_0x00466b85;
L_0x00466c94:
    // 00466c94  beb80b0000             -mov esi, 0xbb8
    cpu.esi = 3000 /*0xbb8*/;
    // 00466c99  bf11000000             -mov edi, 0x11
    cpu.edi = 17 /*0x11*/;
    // 00466c9e  e9e2feffff             -jmp 0x466b85
    goto L_0x00466b85;
  case 0x00466ca3:
    // 00466ca3  8b0d8c8f4c00           -mov ecx, dword ptr [0x4c8f8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */);
    // 00466ca9  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00466cac  81eee8030000           -sub esi, 0x3e8
    (cpu.esi) -= x86::reg32(x86::sreg32(1000 /*0x3e8*/));
    // 00466cb2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00466cb4  7414                   -je 0x466cca
    if (cpu.flags.zf)
    {
        goto L_0x00466cca;
    }
    // 00466cb6  3b3d908f4c00           +cmp edi, dword ptr [0x4c8f90]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466cbc  750c                   -jne 0x466cca
    if (!cpu.flags.zf)
    {
        goto L_0x00466cca;
    }
    // 00466cbe  3b35948f4c00           +cmp esi, dword ptr [0x4c8f94]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466cc4  0f84d8feffff           -je 0x466ba2
    if (cpu.flags.zf)
    {
        goto L_0x00466ba2;
    }
L_0x00466cca:
    // 00466cca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00466ccc  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00466cd0  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00466cd4  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00466cd8  dc3d0cdb4b00           -fdivr qword ptr [0x4bdb0c]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4971276) /* 0x4bdb0c */)) / cpu.fpu.st(0);
    // 00466cde  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00466ce0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466ce1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00466ce5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466ce7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466ce8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466cea  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00466cee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466cef  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00466cf3  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 00466cf8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466cf9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00466cfe  dc0514db4b00           -fadd qword ptr [0x4bdb14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4971284) /* 0x4bdb14 */));
    // 00466d04  c1f810                 +sar eax, 0x10
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
    // 00466d07  e804530100             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 00466d0c  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00466d10  e88bbdfbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00466d15  c7058c8f4c0001000000   -mov dword ptr [0x4c8f8c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = 1 /*0x1*/;
    // 00466d1f  e97efeffff             -jmp 0x466ba2
    goto L_0x00466ba2;
  case 0x00466d24:
    // 00466d24  a18c8f4c00             -mov eax, dword ptr [0x4c8f8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */);
    // 00466d29  4f                     -dec edi
    (cpu.edi)--;
    // 00466d2a  81eedc050000           -sub esi, 0x5dc
    (cpu.esi) -= x86::reg32(x86::sreg32(1500 /*0x5dc*/));
    // 00466d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00466d32  7414                   -je 0x466d48
    if (cpu.flags.zf)
    {
        goto L_0x00466d48;
    }
    // 00466d34  3b3d908f4c00           +cmp edi, dword ptr [0x4c8f90]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466d3a  750c                   -jne 0x466d48
    if (!cpu.flags.zf)
    {
        goto L_0x00466d48;
    }
    // 00466d3c  3b35948f4c00           +cmp esi, dword ptr [0x4c8f94]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466d42  0f845afeffff           -je 0x466ba2
    if (cpu.flags.zf)
    {
        goto L_0x00466ba2;
    }
L_0x00466d48:
    // 00466d48  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466d4a  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00466d4e  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00466d52  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00466d56  dc3d0cdb4b00           -fdivr qword ptr [0x4bdb0c]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4971276) /* 0x4bdb0c */)) / cpu.fpu.st(0);
    // 00466d5c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00466d5e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466d5f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00466d64  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00466d68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466d69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466d6b  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00466d6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466d70  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00466d74  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 00466d79  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466d7a  dc0514db4b00           -fadd qword ptr [0x4bdb14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4971284) /* 0x4bdb14 */));
    // 00466d80  c1f810                 +sar eax, 0x10
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
    // 00466d83  e888520100             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 00466d88  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00466d8c  e80fbdfbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00466d91  c7058c8f4c0001000000   -mov dword ptr [0x4c8f8c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = 1 /*0x1*/;
    // 00466d9b  e902feffff             -jmp 0x466ba2
    goto L_0x00466ba2;
  case 0x00466da0:
    // 00466da0  8b158c8f4c00           -mov edx, dword ptr [0x4c8f8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */);
    // 00466da6  47                     -inc edi
    (cpu.edi)++;
    // 00466da7  81eef4010000           -sub esi, 0x1f4
    (cpu.esi) -= x86::reg32(x86::sreg32(500 /*0x1f4*/));
    // 00466dad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466daf  7414                   -je 0x466dc5
    if (cpu.flags.zf)
    {
        goto L_0x00466dc5;
    }
    // 00466db1  3b3d908f4c00           +cmp edi, dword ptr [0x4c8f90]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466db7  750c                   -jne 0x466dc5
    if (!cpu.flags.zf)
    {
        goto L_0x00466dc5;
    }
    // 00466db9  3b35948f4c00           +cmp esi, dword ptr [0x4c8f94]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466dbf  0f84ddfdffff           -je 0x466ba2
    if (cpu.flags.zf)
    {
        goto L_0x00466ba2;
    }
L_0x00466dc5:
    // 00466dc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466dc7  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00466dcb  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00466dcf  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00466dd3  dc3d0cdb4b00           -fdivr qword ptr [0x4bdb0c]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4971276) /* 0x4bdb0c */)) / cpu.fpu.st(0);
    // 00466dd9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00466dde  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00466de1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466de2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00466de6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00466dea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466deb  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00466def  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466df1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466df2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466df4  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 00466df9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466dfa  dc0514db4b00           -fadd qword ptr [0x4bdb14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4971284) /* 0x4bdb14 */));
    // 00466e00  c1f810                 +sar eax, 0x10
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
    // 00466e03  e808520100             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 00466e08  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00466e0c  e88fbcfbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00466e11  c7058c8f4c0001000000   -mov dword ptr [0x4c8f8c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = 1 /*0x1*/;
    // 00466e1b  e982fdffff             -jmp 0x466ba2
    goto L_0x00466ba2;
  case 0x00466e20:
    // 00466e20  8b1d8c8f4c00           -mov ebx, dword ptr [0x4c8f8c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */);
    // 00466e26  47                     -inc edi
    (cpu.edi)++;
    // 00466e27  81c6e8030000           -add esi, 0x3e8
    (cpu.esi) += x86::reg32(x86::sreg32(1000 /*0x3e8*/));
    // 00466e2d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00466e2f  7414                   -je 0x466e45
    if (cpu.flags.zf)
    {
        goto L_0x00466e45;
    }
    // 00466e31  3b3d908f4c00           +cmp edi, dword ptr [0x4c8f90]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466e37  750c                   -jne 0x466e45
    if (!cpu.flags.zf)
    {
        goto L_0x00466e45;
    }
    // 00466e39  3b35948f4c00           +cmp esi, dword ptr [0x4c8f94]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466e3f  0f845dfdffff           -je 0x466ba2
    if (cpu.flags.zf)
    {
        goto L_0x00466ba2;
    }
L_0x00466e45:
    // 00466e45  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466e47  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00466e4b  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00466e4f  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00466e53  dc3d0cdb4b00           -fdivr qword ptr [0x4bdb0c]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4971276) /* 0x4bdb0c */)) / cpu.fpu.st(0);
    // 00466e59  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00466e5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466e5c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00466e61  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00466e65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466e66  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466e68  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00466e6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466e6d  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00466e71  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 00466e76  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466e77  dc0514db4b00           -fadd qword ptr [0x4bdb14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4971284) /* 0x4bdb14 */));
    // 00466e7d  c1f810                 +sar eax, 0x10
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
    // 00466e80  e88b510100             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 00466e85  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00466e89  e812bcfbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00466e8e  c7058c8f4c0001000000   -mov dword ptr [0x4c8f8c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = 1 /*0x1*/;
    // 00466e98  e905fdffff             -jmp 0x466ba2
    goto L_0x00466ba2;
  case 0x00466e9d:
    // 00466e9d  8b158c8f4c00           -mov edx, dword ptr [0x4c8f8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */);
    // 00466ea3  83ef05                 -sub edi, 5
    (cpu.edi) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00466ea6  81c6d0070000           -add esi, 0x7d0
    (cpu.esi) += x86::reg32(x86::sreg32(2000 /*0x7d0*/));
    // 00466eac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00466eae  7414                   -je 0x466ec4
    if (cpu.flags.zf)
    {
        goto L_0x00466ec4;
    }
    // 00466eb0  3b3d908f4c00           +cmp edi, dword ptr [0x4c8f90]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466eb6  750c                   -jne 0x466ec4
    if (!cpu.flags.zf)
    {
        goto L_0x00466ec4;
    }
    // 00466eb8  3b35948f4c00           +cmp esi, dword ptr [0x4c8f94]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466ebe  0f84defcffff           -je 0x466ba2
    if (cpu.flags.zf)
    {
        goto L_0x00466ba2;
    }
L_0x00466ec4:
    // 00466ec4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00466ec6  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00466eca  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00466ece  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00466ed2  dc3d0cdb4b00           -fdivr qword ptr [0x4bdb0c]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(4971276) /* 0x4bdb0c */)) / cpu.fpu.st(0);
    // 00466ed8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00466edd  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00466ee0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466ee1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00466ee5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00466ee9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466eea  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00466eee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00466ef0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00466ef1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00466ef3  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 00466ef8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466ef9  dc0514db4b00           -fadd qword ptr [0x4bdb14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4971284) /* 0x4bdb14 */));
    // 00466eff  c1f810                 +sar eax, 0x10
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
    // 00466f02  e809510100             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 00466f07  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00466f0b  e890bbfbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00466f10  c7058c8f4c0001000000   -mov dword ptr [0x4c8f8c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = 1 /*0x1*/;
    // 00466f1a  e983fcffff             -jmp 0x466ba2
    goto L_0x00466ba2;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_466f5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00466f5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00466f5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00466f5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00466f5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00466f60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00466f61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00466f62  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00466f65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00466f67  e8d4f7ffff             -call 0x466740
    cpu.esp -= 4;
    sub_466740(app, cpu);
    if (cpu.terminate) return;
    // 00466f6c  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00466f6e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00466f70  8b8264060000           -mov eax, dword ptr [edx + 0x664]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1636) /* 0x664 */);
    // 00466f76  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00466f78  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00466f7b  8b0da88f4c00           -mov ecx, dword ptr [0x4c8fa8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017512) /* 0x4c8fa8 */);
    // 00466f81  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00466f83  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00466f85  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00466f87  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00466f89  3df0d8ffff             +cmp eax, 0xffffd8f0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294957296 /*0xffffd8f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466f8e  7d05                   -jge 0x466f95
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466f95;
    }
    // 00466f90  b8f0d8ffff             -mov eax, 0xffffd8f0
    cpu.eax = 4294957296 /*0xffffd8f0*/;
L_0x00466f95:
    // 00466f95  3d10270000             +cmp eax, 0x2710
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466f9a  7e05                   -jle 0x466fa1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466fa1;
    }
    // 00466f9c  b810270000             -mov eax, 0x2710
    cpu.eax = 10000 /*0x2710*/;
L_0x00466fa1:
    // 00466fa1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00466fa3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00466fa5  7502                   -jne 0x466fa9
    if (!cpu.flags.zf)
    {
        goto L_0x00466fa9;
    }
    // 00466fa7  31c3                   -xor ebx, eax
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00466fa9:
    // 00466fa9  891da88f4c00           -mov dword ptr [0x4c8fa8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5017512) /* 0x4c8fa8 */) = cpu.ebx;
    // 00466faf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00466fb1  0f8c0d010000           -jl 0x4670c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004670c4;
    }
    // 00466fb7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00466fb9:
    // 00466fb9  8b8268060000           -mov eax, dword ptr [edx + 0x668]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1640) /* 0x668 */);
    // 00466fbf  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00466fc1  8b35a48f4c00           -mov esi, dword ptr [0x4c8fa4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017508) /* 0x4c8fa4 */);
    // 00466fc7  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00466fc9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00466fcb  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00466fcd  83f89c                 +cmp eax, -0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-100 /*-0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00466fd0  7d05                   -jge 0x466fd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00466fd7;
    }
    // 00466fd2  b89cffffff             -mov eax, 0xffffff9c
    cpu.eax = 4294967196 /*0xffffff9c*/;
L_0x00466fd7:
    // 00466fd7  83f864                 +cmp eax, 0x64
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
    // 00466fda  7e05                   -jle 0x466fe1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00466fe1;
    }
    // 00466fdc  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
L_0x00466fe1:
    // 00466fe1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00466fe3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00466fe5  7502                   -jne 0x466fe9
    if (!cpu.flags.zf)
    {
        goto L_0x00466fe9;
    }
    // 00466fe7  31c6                   -xor esi, eax
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00466fe9:
    // 00466fe9  8a0d808f4c00           -mov cl, byte ptr [0x4c8f80]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5017472) /* 0x4c8f80 */);
    // 00466fef  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 00466ff1  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00466ff4  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00466ff6  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00466ff9  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00466ffb  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00466ffd  8935a48f4c00           -mov dword ptr [0x4c8fa4], esi
    app->getMemory<x86::reg32>(x86::reg32(5017508) /* 0x4c8fa4 */) = cpu.esi;
    // 00467003  83f964                 +cmp ecx, 0x64
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467006  7e05                   -jle 0x46700d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046700d;
    }
    // 00467008  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x0046700d:
    // 0046700d  8baa24030000           -mov ebp, dword ptr [edx + 0x324]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(804) /* 0x324 */);
    // 00467013  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00467015  81fd00000100           +cmp ebp, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046701b  7e03                   -jle 0x467020
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00467020;
    }
    // 0046701d  8d41f6                 -lea eax, [ecx - 0xa]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-10) /* -0xa */);
L_0x00467020:
    // 00467020  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467022  0f8ca5000000           -jl 0x4670cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004670cd;
    }
    // 00467028  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0046702a:
    // 0046702a  8b0d708f4c00           -mov ecx, dword ptr [0x4c8f70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017456) /* 0x4c8f70 */);
    // 00467030  49                     -dec ecx
    (cpu.ecx)--;
    // 00467031  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00467033  83f90e                 +cmp ecx, 0xe
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
    // 00467036  7707                   -ja 0x46703f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046703f;
    }
    // 00467038  ff248d206f4600         -jmp dword ptr [ecx*4 + 0x466f20]
    cpu.ip = app->getMemory<x86::reg32>(4615968 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0046703f:
L_0x0046703f:
    // 0046703f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00467041  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00467045  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00467049  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0046704d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00467050  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00467054  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00467056  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0046705a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046705d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046705f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00467061  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467063  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00467066  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 0046706d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00467071  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00467075  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00467079  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046707d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046707f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467081  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00467084  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00467088  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467089  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0046708d  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046708f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467090  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00467094  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00467097  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00467098  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046709a  a1c23b5100             -mov eax, dword ptr [0x513bc2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323714) /* 0x513bc2 */);
    // 0046709f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004670a0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004670a5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004670a8  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004670ac  e8efb9fbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 004670b1  66c705988f4c000100     -mov word ptr [0x4c8f98], 1
    app->getMemory<x86::reg16>(x86::reg32(5017496) /* 0x4c8f98 */) = 1 /*0x1*/;
    // 004670ba  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004670bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004670c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004670c4:
    // 004670c4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004670c6  f7df                   +neg edi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004670c8  e9ecfeffff             -jmp 0x466fb9
    goto L_0x00466fb9;
L_0x004670cd:
    // 004670cd  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004670cf  e956ffffff             -jmp 0x46702a
    goto L_0x0046702a;
  case 0x004670d4:
    // 004670d4  8d42f6                 -lea eax, [edx - 0xa]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-10) /* -0xa */);
    // 004670d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004670d9  0f8d60ffffff           -jge 0x46703f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046703f;
    }
    // 004670df  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004670e1  e959ffffff             -jmp 0x46703f
    goto L_0x0046703f;
  case 0x004670e6:
    // 004670e6  83e814                 -sub eax, 0x14
    (cpu.eax) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004670e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004670eb  0f8d4effffff           -jge 0x46703f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046703f;
    }
    // 004670f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004670f3  e947ffffff             -jmp 0x46703f
    goto L_0x0046703f;
  case 0x004670f8:
    // 004670f8  83e81e                 -sub eax, 0x1e
    (cpu.eax) -= x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 004670fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004670fd  7c07                   -jl 0x467106
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00467106;
    }
  [[fallthrough]];
  case 0x004670ff:
    // 004670ff  f7d8                   +neg eax
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
    // 00467101  e939ffffff             -jmp 0x46703f
    goto L_0x0046703f;
L_0x00467106:
    // 00467106  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467108  f7d8                   +neg eax
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
    // 0046710a  e930ffffff             -jmp 0x46703f
    goto L_0x0046703f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_467110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467113  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467114  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467115  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467116  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00467119  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046711b  8a1da08f4c00           -mov bl, byte ptr [0x4c8fa0]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5017504) /* 0x4c8fa0 */);
    // 00467121  e8aaf9ffff             -call 0x466ad0
    cpu.esp -= 4;
    sub_466ad0(app, cpu);
    if (cpu.terminate) return;
    // 00467126  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467128  7436                   -je 0x467160
    if (cpu.flags.zf)
    {
        goto L_0x00467160;
    }
    // 0046712a  803da08f4c0064         +cmp byte ptr [0x4c8fa0], 0x64
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017504) /* 0x4c8fa0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00467131  7437                   -je 0x46716a
    if (cpu.flags.zf)
    {
        goto L_0x0046716a;
    }
    // 00467133  8b8ab8020000           -mov ecx, dword ptr [edx + 0x2b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
    // 00467139  81f999190000           +cmp ecx, 0x1999
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6553 /*0x1999*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046713f  7c1f                   -jl 0x467160
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00467160;
    }
    // 00467141  8a82da020000           -mov al, byte ptr [edx + 0x2da]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(730) /* 0x2da */);
    // 00467147  a2a08f4c00             -mov byte ptr [0x4c8fa0], al
    app->getMemory<x86::reg8>(x86::reg32(5017504) /* 0x4c8fa0 */) = cpu.al;
    // 0046714c  3c02                   +cmp al, 2
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
    // 0046714e  0f837c000000           -jae 0x4671d0
    if (!cpu.flags.cf)
    {
        goto L_0x004671d0;
    }
    // 00467154  3c01                   +cmp al, 1
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
    // 00467156  7408                   -je 0x467160
    if (cpu.flags.zf)
    {
        goto L_0x00467160;
    }
    // 00467158  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046715e  7f17                   -jg 0x467177
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00467177;
    }
L_0x00467160:
    // 00467160  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00467163  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467164  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467165  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467166  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467167  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467168  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467169  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046716a:
    // 0046716a  8a82da020000           -mov al, byte ptr [edx + 0x2da]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(730) /* 0x2da */);
    // 00467170  a2a08f4c00             -mov byte ptr [0x4c8fa0], al
    app->getMemory<x86::reg8>(x86::reg32(5017504) /* 0x4c8fa0 */) = cpu.al;
    // 00467175  ebe9                   -jmp 0x467160
    goto L_0x00467160;
L_0x00467177:
    // 00467177  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046717c  be88130000             -mov esi, 0x1388
    cpu.esi = 5000 /*0x1388*/;
    // 00467181  b8409c0000             -mov eax, 0x9c40
    cpu.eax = 40000 /*0x9c40*/;
    // 00467186  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046718b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046718d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046718f  891d848f4c00           -mov dword ptr [0x4c8f84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */) = cpu.ebx;
    // 00467195  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467196  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0046719a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046719e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046719f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004671a3  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004671a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004671a8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004671aa  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 004671af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004671b0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004671b3  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004671b7  e8e4b8fbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 004671bc  c7058c8f4c0001000000   -mov dword ptr [0x4c8f8c], 1
    app->getMemory<x86::reg32>(x86::reg32(5017484) /* 0x4c8f8c */) = 1 /*0x1*/;
    // 004671c6  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004671c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004671ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004671cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004671cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004671cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004671ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004671cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004671d0:
    // 004671d0  38c3                   +cmp bl, al
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004671d2  7640                   -jbe 0x467214
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00467214;
    }
    // 004671d4  c7442418b5000000       -mov dword ptr [esp + 0x18], 0xb5
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 181 /*0xb5*/;
L_0x004671dc:
    // 004671dc  8bbaf0020000           -mov edi, dword ptr [edx + 0x2f0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(752) /* 0x2f0 */);
    // 004671e2  81ffd0070000           +cmp edi, 0x7d0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004671e8  7d34                   -jge 0x46721e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046721e;
    }
    // 004671ea  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 004671ef  b868100000             -mov eax, 0x1068
    cpu.eax = 4200 /*0x1068*/;
    // 004671f4  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004671f8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004671fb:
    // 004671fb  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004671fd  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467201  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467205  e8e6f5ffff             -call 0x4667f0
    cpu.esp -= 4;
    sub_4667f0(app, cpu);
    if (cpu.terminate) return;
    // 0046720a  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046720d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046720e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046720f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467210  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467211  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467212  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467213  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467214:
    // 00467214  c744241801000000       -mov dword ptr [esp + 0x18], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 1 /*0x1*/;
    // 0046721c  ebbe                   -jmp 0x4671dc
    goto L_0x004671dc;
L_0x0046721e:
    // 0046721e  81ffb80b0000           +cmp edi, 0xbb8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3000 /*0xbb8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467224  7d13                   -jge 0x467239
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00467239;
    }
    // 00467226  bd96000000             -mov ebp, 0x96
    cpu.ebp = 150 /*0x96*/;
    // 0046722b  bf50140000             -mov edi, 0x1450
    cpu.edi = 5200 /*0x1450*/;
    // 00467230  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 00467234  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00467237  ebc2                   -jmp 0x4671fb
    goto L_0x004671fb;
L_0x00467239:
    // 00467239  81ffa00f0000           +cmp edi, 0xfa0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046723f  7d13                   -jge 0x467254
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00467254;
    }
    // 00467241  bec8000000             -mov esi, 0xc8
    cpu.esi = 200 /*0xc8*/;
    // 00467246  bb38180000             -mov ebx, 0x1838
    cpu.ebx = 6200 /*0x1838*/;
    // 0046724b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0046724f  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00467252  eba7                   -jmp 0x4671fb
    goto L_0x004671fb;
L_0x00467254:
    // 00467254  b9fa000000             -mov ecx, 0xfa
    cpu.ecx = 250 /*0xfa*/;
    // 00467259  ba201c0000             -mov edx, 0x1c20
    cpu.edx = 7200 /*0x1c20*/;
    // 0046725e  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00467262  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00467265  eb94                   -jmp 0x4671fb
    goto L_0x004671fb;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467270  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00467273  e858f8ffff             -call 0x466ad0
    cpu.esp -= 4;
    sub_466ad0(app, cpu);
    if (cpu.terminate) return;
    // 00467278  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046727a  7504                   -jne 0x467280
    if (!cpu.flags.zf)
    {
        goto L_0x00467280;
    }
    // 0046727c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046727f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467280:
    // 00467280  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467282  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467283  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 00467288  b95a000000             -mov ecx, 0x5a
    cpu.ecx = 90 /*0x5a*/;
    // 0046728d  bb0e010000             -mov ebx, 0x10e
    cpu.ebx = 270 /*0x10e*/;
    // 00467292  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00467296  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046729a  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0046729e  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004672a2  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004672a6  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004672aa  e841f5ffff             -call 0x4667f0
    cpu.esp -= 4;
    sub_4667f0(app, cpu);
    if (cpu.terminate) return;
    // 004672af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672b2  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004672b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4672c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004672c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004672c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004672c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004672c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004672c4  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004672c7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004672c9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004672cb  e800f8ffff             -call 0x466ad0
    cpu.esp -= 4;
    sub_466ad0(app, cpu);
    if (cpu.terminate) return;
    // 004672d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004672d2  7508                   -jne 0x4672dc
    if (!cpu.flags.zf)
    {
        goto L_0x004672dc;
    }
L_0x004672d4:
    // 004672d4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004672d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004672db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004672dc:
    // 004672dc  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004672df  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004672e6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004672e8  8b1518ec4d00           -mov edx, dword ptr [0x4dec18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 004672ee  8b54820c               -mov edx, dword ptr [edx + eax*4 + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 004672f2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004672f5  8b81dc000000           -mov eax, dword ptr [ecx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 004672fb  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004672fd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00467300  c1e810                 +shr eax, 0x10
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
    // 00467303  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00467305  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00467308  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046730a  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00467311  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00467313  8b1518ec4d00           -mov edx, dword ptr [0x4dec18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 00467319  8b54820d               -mov edx, dword ptr [edx + eax*4 + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */ + cpu.eax * 4);
    // 0046731d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00467320  8b81e0000000           -mov eax, dword ptr [ecx + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 00467326  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00467328  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046732b  c1e810                 +shr eax, 0x10
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
    // 0046732e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00467330  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00467333  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467335  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046733c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046733e  a118ec4d00             -mov eax, dword ptr [0x4dec18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 00467343  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00467346  8b54020e               -mov edx, dword ptr [edx + eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */ + cpu.eax * 1);
    // 0046734a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0046734d  8b81e4000000           -mov eax, dword ptr [ecx + 0xe4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 00467353  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00467355  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00467358  c1e810                 +shr eax, 0x10
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
    // 0046735b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046735d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046735f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467361  7c40                   -jl 0x4673a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004673a3;
    }
L_0x00467363:
    // 00467363  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00467365  7e44                   -jle 0x4673ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004673ab;
    }
    // 00467367  c744241c5a000000       -mov dword ptr [esp + 0x1c], 0x5a
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 90 /*0x5a*/;
L_0x0046736f:
    // 0046736f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00467371  e8caf3ffff             -call 0x466740
    cpu.esp -= 4;
    sub_466740(app, cpu);
    if (cpu.terminate) return;
    // 00467376  83f828                 +cmp eax, 0x28
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467379  7e54                   -jle 0x4673cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004673cf;
    }
    // 0046737b  bbc8000000             -mov ebx, 0xc8
    cpu.ebx = 200 /*0xc8*/;
    // 00467380  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00467385  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00467389  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
L_0x0046738c:
    // 0046738c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046738e  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467392  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467396  e855f4ffff             -call 0x4667f0
    cpu.esp -= 4;
    sub_4667f0(app, cpu);
    if (cpu.terminate) return;
    // 0046739b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046739e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046739f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004673a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004673a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004673a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004673a3:
    // 004673a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004673a5  74bc                   -je 0x467363
    if (cpu.flags.zf)
    {
        goto L_0x00467363;
    }
    // 004673a7  f7db                   +neg ebx
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
    // 004673a9  ebb8                   -jmp 0x467363
    goto L_0x00467363;
L_0x004673ab:
    // 004673ab  7d0a                   -jge 0x4673b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004673b7;
    }
    // 004673ad  c744241c0e010000       -mov dword ptr [esp + 0x1c], 0x10e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 270 /*0x10e*/;
    // 004673b5  ebb8                   -jmp 0x46736f
    goto L_0x0046736f;
L_0x004673b7:
    // 004673b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004673b9  e882f3ffff             -call 0x466740
    cpu.esp -= 4;
    sub_466740(app, cpu);
    if (cpu.terminate) return;
    // 004673be  83f805                 +cmp eax, 5
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
    // 004673c1  0f8e0dffffff           -jle 0x4672d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004672d4;
    }
    // 004673c7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004673c9  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004673cd  eba0                   -jmp 0x46736f
    goto L_0x0046736f;
L_0x004673cf:
    // 004673cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004673d1  e86af3ffff             -call 0x466740
    cpu.esp -= 4;
    sub_466740(app, cpu);
    if (cpu.terminate) return;
    // 004673d6  83f814                 +cmp eax, 0x14
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
    // 004673d9  7e13                   -jle 0x4673ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004673ee;
    }
    // 004673db  ba2c010000             -mov edx, 0x12c
    cpu.edx = 300 /*0x12c*/;
    // 004673e0  b828230000             -mov eax, 0x2328
    cpu.eax = 9000 /*0x2328*/;
    // 004673e5  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004673e9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004673ec  eb9e                   -jmp 0x46738c
    goto L_0x0046738c;
L_0x004673ee:
    // 004673ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004673ef  bd90010000             -mov ebp, 0x190
    cpu.ebp = 400 /*0x190*/;
    // 004673f4  bf581b0000             -mov edi, 0x1b58
    cpu.edi = 7000 /*0x1b58*/;
    // 004673f9  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 004673fd  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00467401  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467402  eb88                   -jmp 0x46738c
    goto L_0x0046738c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467413  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467414  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00467417  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046741b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046741d  8b352cf54d00           -mov esi, dword ptr [0x4df52c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 00467423  3bb0e8010000           +cmp esi, dword ptr [eax + 0x1e8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467429  0f85bd000000           -jne 0x4674ec
    if (!cpu.flags.zf)
    {
        goto L_0x004674ec;
    }
    // 0046742f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00467431:
    // 00467431  e89af6ffff             -call 0x466ad0
    cpu.esp -= 4;
    sub_466ad0(app, cpu);
    if (cpu.terminate) return;
    // 00467436  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467438  0f84b5000000           -je 0x4674f3
    if (cpu.flags.zf)
    {
        goto L_0x004674f3;
    }
L_0x0046743e:
    // 0046743e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046743f  81fb00200000           +cmp ebx, 0x2000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467445  0f8db8000000           -jge 0x467503
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00467503;
    }
    // 0046744b  b9401f0000             -mov ecx, 0x1f40
    cpu.ecx = 8000 /*0x1f40*/;
    // 00467450  b88a020000             -mov eax, 0x28a
    cpu.eax = 650 /*0x28a*/;
L_0x00467455:
    // 00467455  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00467459  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0046745d:
    // 0046745d  8b1d748f4c00           -mov ebx, dword ptr [0x4c8f74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */);
    // 00467463  8b35748f4c00           -mov esi, dword ptr [0x4c8f74]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */);
    // 00467469  8b829c000000           -mov eax, dword ptr [edx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */);
    // 0046746f  8baa9c000000           -mov ebp, dword ptr [edx + 0x9c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */);
    // 00467475  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00467477  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467479  8b8270010000           -mov eax, dword ptr [edx + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(368) /* 0x170 */);
    // 0046747f  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00467481  39e8                   +cmp eax, ebp
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
    // 00467483  0f8ee6000000           -jle 0x46756f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046756f;
    }
    // 00467489  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0046748e:
    // 0046748e  8b8278010000           -mov eax, dword ptr [edx + 0x178]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(376) /* 0x178 */);
    // 00467494  3b82a4000000           +cmp eax, dword ptr [edx + 0xa4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046749a  0f8ed6000000           -jle 0x467576
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00467576;
    }
    // 004674a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004674a5:
    // 004674a5  8baa70010000           -mov ebp, dword ptr [edx + 0x170]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(368) /* 0x170 */);
    // 004674ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004674ad  39eb                   +cmp ebx, ebp
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
    // 004674af  0f8dc8000000           -jge 0x46757d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046757d;
    }
L_0x004674b5:
    // 004674b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004674ba:
    // 004674ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004674bc  0f84e2000000           -je 0x4675a4
    if (cpu.flags.zf)
    {
        goto L_0x004675a4;
    }
    // 004674c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004674c4  0f84c2000000           -je 0x46758c
    if (cpu.flags.zf)
    {
        goto L_0x0046758c;
    }
    // 004674ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004674cc:
    // 004674cc  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004674d0  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004674d4  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004674d8  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004674dc  e80ff3ffff             -call 0x4667f0
    cpu.esp -= 4;
    sub_4667f0(app, cpu);
    if (cpu.terminate) return;
    // 004674e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004674e2:
    // 004674e2  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004674e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004674e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004674e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004674e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004674e9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004674ec:
    // 004674ec  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004674ee  e93effffff             -jmp 0x467431
    goto L_0x00467431;
L_0x004674f3:
    // 004674f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004674f5  e8d6f5ffff             -call 0x466ad0
    cpu.esp -= 4;
    sub_466ad0(app, cpu);
    if (cpu.terminate) return;
    // 004674fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004674fc  74e4                   -je 0x4674e2
    if (cpu.flags.zf)
    {
        goto L_0x004674e2;
    }
    // 004674fe  e93bffffff             -jmp 0x46743e
    goto L_0x0046743e;
L_0x00467503:
    // 00467503  81fb00500000           +cmp ebx, 0x5000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20480 /*0x5000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467509  7d17                   -jge 0x467522
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00467522;
    }
    // 0046750b  bd34210000             -mov ebp, 0x2134
    cpu.ebp = 8500 /*0x2134*/;
    // 00467510  bff4010000             -mov edi, 0x1f4
    cpu.edi = 500 /*0x1f4*/;
    // 00467515  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00467519  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0046751d  e93bffffff             -jmp 0x46745d
    goto L_0x0046745d;
L_0x00467522:
    // 00467522  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467528  7d17                   -jge 0x467541
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00467541;
    }
    // 0046752a  be28230000             -mov esi, 0x2328
    cpu.esi = 9000 /*0x2328*/;
    // 0046752f  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 00467534  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00467538  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0046753c  e91cffffff             -jmp 0x46745d
    goto L_0x0046745d;
L_0x00467541:
    // 00467541  81fb00001000           +cmp ebx, 0x100000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048576 /*0x100000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467547  7d0f                   -jge 0x467558
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00467558;
    }
    // 00467549  b91c250000             -mov ecx, 0x251c
    cpu.ecx = 9500 /*0x251c*/;
    // 0046754e  b85e010000             -mov eax, 0x15e
    cpu.eax = 350 /*0x15e*/;
    // 00467553  e9fdfeffff             -jmp 0x467455
    goto L_0x00467455;
L_0x00467558:
    // 00467558  bd10270000             -mov ebp, 0x2710
    cpu.ebp = 10000 /*0x2710*/;
    // 0046755d  bf5e010000             -mov edi, 0x15e
    cpu.edi = 350 /*0x15e*/;
    // 00467562  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00467566  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0046756a  e9eefeffff             -jmp 0x46745d
    goto L_0x0046745d;
L_0x0046756f:
    // 0046756f  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00467571  e918ffffff             -jmp 0x46748e
    goto L_0x0046748e;
L_0x00467576:
    // 00467576  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467578  e928ffffff             -jmp 0x4674a5
    goto L_0x004674a5;
L_0x0046757d:
    // 0046757d  39ef                   +cmp edi, ebp
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
    // 0046757f  0f8f30ffffff           -jg 0x4674b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004674b5;
    }
    // 00467585  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00467587  e92effffff             -jmp 0x4674ba
    goto L_0x004674ba;
L_0x0046758c:
    // 0046758c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046758e  740a                   -je 0x46759a
    if (cpu.flags.zf)
    {
        goto L_0x0046759a;
    }
    // 00467590  b82d000000             -mov eax, 0x2d
    cpu.eax = 45 /*0x2d*/;
    // 00467595  e932ffffff             -jmp 0x4674cc
    goto L_0x004674cc;
L_0x0046759a:
    // 0046759a  b83b010000             -mov eax, 0x13b
    cpu.eax = 315 /*0x13b*/;
    // 0046759f  e928ffffff             -jmp 0x4674cc
    goto L_0x004674cc;
L_0x004675a4:
    // 004675a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004675a6  740a                   -je 0x4675b2
    if (cpu.flags.zf)
    {
        goto L_0x004675b2;
    }
    // 004675a8  b8b4000000             -mov eax, 0xb4
    cpu.eax = 180 /*0xb4*/;
    // 004675ad  e91affffff             -jmp 0x4674cc
    goto L_0x004674cc;
L_0x004675b2:
    // 004675b2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004675b4  740a                   -je 0x4675c0
    if (cpu.flags.zf)
    {
        goto L_0x004675c0;
    }
    // 004675b6  b887000000             -mov eax, 0x87
    cpu.eax = 135 /*0x87*/;
    // 004675bb  e90cffffff             -jmp 0x4674cc
    goto L_0x004674cc;
L_0x004675c0:
    // 004675c0  b8e1000000             -mov eax, 0xe1
    cpu.eax = 225 /*0xe1*/;
    // 004675c5  e902ffffff             -jmp 0x4674cc
    goto L_0x004674cc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4675d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004675d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004675d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004675d2  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004675d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004675d7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004675d9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004675db  e8f0f4ffff             -call 0x466ad0
    cpu.esp -= 4;
    sub_466ad0(app, cpu);
    if (cpu.terminate) return;
    // 004675e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004675e2  7506                   -jne 0x4675ea
    if (!cpu.flags.zf)
    {
        goto L_0x004675ea;
    }
L_0x004675e4:
    // 004675e4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004675e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004675e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004675e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004675ea:
    // 004675ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004675ec  e84ff1ffff             -call 0x466740
    cpu.esp -= 4;
    sub_466740(app, cpu);
    if (cpu.terminate) return;
    // 004675f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004675f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004675f5  74ed                   -je 0x4675e4
    if (cpu.flags.zf)
    {
        goto L_0x004675e4;
    }
    // 004675f7  be58020000             -mov esi, 0x258
    cpu.esi = 600 /*0x258*/;
    // 004675fc  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004675fe  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00467600  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00467604  81fec8000000           +cmp esi, 0xc8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046760a  7308                   -jae 0x467614
    if (!cpu.flags.cf)
    {
        goto L_0x00467614;
    }
    // 0046760c  c7442418c8000000       -mov dword ptr [esp + 0x18], 0xc8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 200 /*0xc8*/;
L_0x00467614:
    // 00467614  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00467616  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00467619  0534210000             -add eax, 0x2134
    (cpu.eax) += x86::reg32(x86::sreg32(8500 /*0x2134*/));
    // 0046761e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00467621  3d10270000             +cmp eax, 0x2710
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467626  7e07                   -jle 0x46762f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046762f;
    }
    // 00467628  c7042410270000         -mov dword ptr [esp], 0x2710
    app->getMemory<x86::reg32>(cpu.esp) = 10000 /*0x2710*/;
L_0x0046762f:
    // 0046762f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00467631  7e3c                   -jle 0x46766f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046766f;
    }
    // 00467633  c744241c1e000000       -mov dword ptr [esp + 0x1c], 0x1e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 30 /*0x1e*/;
L_0x0046763b:
    // 0046763b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046763d  751b                   -jne 0x46765a
    if (!cpu.flags.zf)
    {
        goto L_0x0046765a;
    }
    // 0046763f  b864190000             -mov eax, 0x1964
    cpu.eax = 6500 /*0x1964*/;
    // 00467644  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00467647  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467649  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046764d  81eb5e010000           -sub ebx, 0x15e
    (cpu.ebx) -= x86::reg32(x86::sreg32(350 /*0x15e*/));
    // 00467653  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00467656  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
L_0x0046765a:
    // 0046765a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046765c  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467660  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467664  e887f1ffff             -call 0x4667f0
    cpu.esp -= 4;
    sub_4667f0(app, cpu);
    if (cpu.terminate) return;
    // 00467669  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046766c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046766d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046766e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046766f:
    // 0046766f  c744241c4a010000       -mov dword ptr [esp + 0x1c], 0x14a
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 330 /*0x14a*/;
    // 00467677  ebc2                   -jmp 0x46763b
    goto L_0x0046763b;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467680  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467687  7501                   -jne 0x46768a
    if (!cpu.flags.zf)
    {
        goto L_0x0046768a;
    }
    // 00467689  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046768a:
    // 0046768a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046768b  e830f1ffff             -call 0x4667c0
    cpu.esp -= 4;
    sub_4667c0(app, cpu);
    if (cpu.terminate) return;
    // 00467690  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467692  e8f9f0ffff             -call 0x466790
    cpu.esp -= 4;
    sub_466790(app, cpu);
    if (cpu.terminate) return;
    // 00467697  890d243c5100           -mov dword ptr [0x513c24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5323812) /* 0x513c24 */) = cpu.ecx;
    // 0046769d  890d9c8f4c00           -mov dword ptr [0x4c8f9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017500) /* 0x4c8f9c */) = cpu.ecx;
    // 004676a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004676a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4676e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004676e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004676e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004676e2  e8cd000000             -call 0x4677b4
    cpu.esp -= 4;
    sub_4677b4(app, cpu);
    if (cpu.terminate) return;
    // 004676e7  8b1c8528f04d00         -mov ebx, dword ptr [eax*4 + 0x4df028]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5107752) /* 0x4df028 */ + cpu.eax * 4);
    // 004676ee  e8cdefffff             -call 0x4666c0
    cpu.esp -= 4;
    sub_4666c0(app, cpu);
    if (cpu.terminate) return;
    // 004676f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004676f5  0f848a000000           -je 0x467785
    if (cpu.flags.zf)
    {
        goto L_0x00467785;
    }
    // 004676fb  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467702  0f847d000000           -je 0x467785
    if (cpu.flags.zf)
    {
        goto L_0x00467785;
    }
    // 00467708  803df4014e0000         +cmp byte ptr [0x4e01f4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112308) /* 0x4e01f4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046770f  7474                   -je 0x467785
    if (cpu.flags.zf)
    {
        goto L_0x00467785;
    }
    // 00467711  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467712  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467713  8b9308010000           -mov edx, dword ptr [ebx + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(264) /* 0x108 */);
    // 00467719  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046771b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046771e  c1e202                 +shl edx, 2
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
    // 00467721  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00467723  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00467726  a3748f4c00             -mov dword ptr [0x4c8f74], eax
    app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */) = cpu.eax;
    // 0046772b  8b831c020000           -mov eax, dword ptr [ebx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(540) /* 0x21c */);
    // 00467731  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00467736  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00467738  890d6c8f4c00           -mov dword ptr [0x4c8f6c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017452) /* 0x4c8f6c */) = cpu.ecx;
    // 0046773e  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467741  774d                   -ja 0x467790
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00467790;
    }
    // 00467743  ff2485b0764600         -jmp dword ptr [eax*4 + 0x4676b0]
    cpu.ip = app->getMemory<x86::reg32>(4617904 + cpu.eax * 4); goto dynamic_jump;
  case 0x0046774a:
    // 0046774a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046774b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046774d  893d808f4c00           -mov dword ptr [0x4c8f80], edi
    app->getMemory<x86::reg32>(x86::reg32(5017472) /* 0x4c8f80 */) = cpu.edi;
    // 00467753  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00467754:
    // 00467754  e85b000000             -call 0x4677b4
    cpu.esp -= 4;
    sub_4677b4(app, cpu);
    if (cpu.terminate) return;
    // 00467759  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0046775e  8b048528f04d00         -mov eax, dword ptr [eax*4 + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107752) /* 0x4df028 */ + cpu.eax * 4);
    // 00467765  ba60694600             -mov edx, 0x466960
    cpu.edx = 4614496 /*0x466960*/;
    // 0046776a  a3888f4c00             -mov dword ptr [0x4c8f88], eax
    app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */) = cpu.eax;
    // 0046776f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00467771  a1d0f74f00             -mov eax, dword ptr [0x4ff7d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240784) /* 0x4ff7d0 */);
    // 00467776  e8056cffff             -call 0x45e380
    cpu.esp -= 4;
    sub_45e380(app, cpu);
    if (cpu.terminate) return;
    // 0046777b  e800ffffff             -call 0x467680
    cpu.esp -= 4;
    sub_467680(app, cpu);
    if (cpu.terminate) return;
    // 00467780  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467781  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467782  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467783  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467784  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467785:
    // 00467785  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00467787  892d6c8f4c00           -mov dword ptr [0x4c8f6c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5017452) /* 0x4c8f6c */) = cpu.ebp;
    // 0046778d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046778e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046778f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00467790:
L_0x00467790:
    // 00467790  c705808f4c0001000000   -mov dword ptr [0x4c8f80], 1
    app->getMemory<x86::reg32>(x86::reg32(5017472) /* 0x4c8f80 */) = 1 /*0x1*/;
    // 0046779a  ebb8                   -jmp 0x467754
    goto L_0x00467754;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4677b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004677b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004677b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004677b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004677b7  a128f54d00             -mov eax, dword ptr [0x4df528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 004677bc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004677be  83f804                 +cmp eax, 4
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
    // 004677c1  770d                   -ja 0x4677d0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004677d0;
    }
    // 004677c3  ff2485a0774600         -jmp dword ptr [eax*4 + 0x4677a0]
    cpu.ip = app->getMemory<x86::reg32>(4618144 + cpu.eax * 4); goto dynamic_jump;
  case 0x004677ca:
    // 004677ca  8b1d2cf54d00           -mov ebx, dword ptr [0x4df52c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
L_0x004677d0:
    // 004677d0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004677d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004677d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004677d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004677d5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004677d6:
    // 004677d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004677d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004677da:
    // 004677da  8b8a041e4c00           -mov ecx, dword ptr [edx + 0x4c1e04]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4988420) /* 0x4c1e04 */);
    // 004677e0  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004677e2  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004677e8  83f903                 +cmp ecx, 3
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
    // 004677eb  750b                   -jne 0x4677f8
    if (!cpu.flags.zf)
    {
        goto L_0x004677f8;
    }
    // 004677ed  40                     -inc eax
    (cpu.eax)++;
    // 004677ee  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004677f1  83f814                 +cmp eax, 0x14
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
    // 004677f4  7dda                   -jge 0x4677d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004677d0;
    }
    // 004677f6  ebe2                   -jmp 0x4677da
    goto L_0x004677da;
L_0x004677f8:
    // 004677f8  83f809                 +cmp eax, 9
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
    // 004677fb  7e12                   -jle 0x46780f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046780f;
    }
    // 004677fd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00467802  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00467804  40                     -inc eax
    (cpu.eax)++;
    // 00467805  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467808  83f814                 +cmp eax, 0x14
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
    // 0046780b  7dc3                   -jge 0x4677d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004677d0;
    }
    // 0046780d  ebcb                   -jmp 0x4677da
    goto L_0x004677da;
L_0x0046780f:
    // 0046780f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467811  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00467813  40                     -inc eax
    (cpu.eax)++;
    // 00467814  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467817  83f814                 +cmp eax, 0x14
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
    // 0046781a  7db4                   -jge 0x4677d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004677d0;
    }
    // 0046781c  ebbc                   -jmp 0x4677da
    goto L_0x004677da;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_467820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467820  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467827  7501                   -jne 0x46782a
    if (!cpu.flags.zf)
    {
        goto L_0x0046782a;
    }
    // 00467829  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046782a:
    // 0046782a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0046782f  e93cbbfbff             -jmp 0x423370
    return sub_423370(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467840  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467847  7501                   -jne 0x46784a
    if (!cpu.flags.zf)
    {
        goto L_0x0046784a;
    }
    // 00467849  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046784a:
    // 0046784a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0046784f  e97cbbfbff             -jmp 0x4233d0
    return sub_4233d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467860  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467867  7501                   -jne 0x46786a
    if (!cpu.flags.zf)
    {
        goto L_0x0046786a;
    }
    // 00467869  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046786a:
    // 0046786a  e811feffff             -call 0x467680
    cpu.esp -= 4;
    sub_467680(app, cpu);
    if (cpu.terminate) return;
    // 0046786f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00467874  e8c7bbfbff             -call 0x423440
    cpu.esp -= 4;
    sub_423440(app, cpu);
    if (cpu.terminate) return;
    // 00467879  e9a2ffffff             -jmp 0x467820
    return sub_467820(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_467880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467880  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467887  7501                   -jne 0x46788a
    if (!cpu.flags.zf)
    {
        goto L_0x0046788a;
    }
    // 00467889  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046788a:
    // 0046788a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0046788f  e9acbbfbff             -jmp 0x423440
    return sub_423440(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4678a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004678a0  833d688f4c0000         +cmp dword ptr [0x4c8f68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004678a7  7501                   -jne 0x4678aa
    if (!cpu.flags.zf)
    {
        goto L_0x004678aa;
    }
    // 004678a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004678aa:
    // 004678aa  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004678af  e9ecbbfbff             -jmp 0x4234a0
    return sub_4234a0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4678c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004678c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004678c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004678c3  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004678c8  e873b9fbff             -call 0x423240
    cpu.esp -= 4;
    sub_423240(app, cpu);
    if (cpu.terminate) return;
    // 004678cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004678ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4678d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004678d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004678d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004678d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004678d3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004678d6  c60424ff               -mov byte ptr [esp], 0xff
    app->getMemory<x86::reg8>(cpu.esp) = 255 /*0xff*/;
    // 004678da  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 004678df  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004678e2  e8e9b4fbff             -call 0x422dd0
    cpu.esp -= 4;
    sub_422dd0(app, cpu);
    if (cpu.terminate) return;
    // 004678e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004678e9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004678ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004678ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004678f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004678f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004678f4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004678f6  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 004678fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004678fd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00467900  e89bb1fbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 00467905  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467908  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467909  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046790a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046790b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_467910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467910  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467911  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00467913  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00467918  e823b9fbff             -call 0x423240
    cpu.esp -= 4;
    sub_423240(app, cpu);
    if (cpu.terminate) return;
    // 0046791d  66833d9a8f4c0000       +cmp word ptr [0x4c8f9a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5017498) /* 0x4c8f9a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00467925  7402                   -je 0x467929
    if (cpu.flags.zf)
    {
        goto L_0x00467929;
    }
    // 00467927  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467928  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467929:
    // 00467929  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 0046792e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00467931  e85ab5fbff             -call 0x422e90
    cpu.esp -= 4;
    sub_422e90(app, cpu);
    if (cpu.terminate) return;
    // 00467936  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467937  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467943  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467944  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00467947  baffffff00             -mov edx, 0xffffff
    cpu.edx = 16777215 /*0xffffff*/;
    // 0046794c  b988130000             -mov ecx, 0x1388
    cpu.ecx = 5000 /*0x1388*/;
    // 00467951  bfe4720000             -mov edi, 0x72e4
    cpu.edi = 29412 /*0x72e4*/;
    // 00467956  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467958  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046795a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046795e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00467961  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00467965  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00467969  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0046796d  668b159a8f4c00         -mov dx, word ptr [0x4c8f9a]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5017498) /* 0x4c8f9a */);
    // 00467974  8864241c               -mov byte ptr [esp + 0x1c], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ah;
    // 00467978  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0046797b  742e                   -je 0x4679ab
    if (cpu.flags.zf)
    {
        goto L_0x004679ab;
    }
    // 0046797d  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x0046797f:
    // 0046797f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00467981  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00467985  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467989  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046798a  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046798e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467991  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00467994  a1c03b5100             -mov eax, dword ptr [0x513bc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5323712) /* 0x513bc0 */);
    // 00467999  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046799b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046799e  e8fdb0fbff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 004679a3  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004679a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004679a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004679a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004679a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004679aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004679ab:
    // 004679ab  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004679ad  ebd0                   -jmp 0x46797f
    goto L_0x0046797f;
}

/* align: skip 0x00 */
void Application::sub_4679b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004679b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004679b1  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 004679b6  8b15688f4c00           -mov edx, dword ptr [0x4c8f68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */);
    // 004679bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004679be  7407                   -je 0x4679c7
    if (cpu.flags.zf)
    {
        goto L_0x004679c7;
    }
    // 004679c0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004679c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004679c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004679c7:
    // 004679c7  e8c494fcff             -call 0x430e90
    cpu.esp -= 4;
    sub_430e90(app, cpu);
    if (cpu.terminate) return;
    // 004679cc  e82fbbfbff             -call 0x423500
    cpu.esp -= 4;
    sub_423500(app, cpu);
    if (cpu.terminate) return;
    // 004679d1  a3688f4c00             -mov dword ptr [0x4c8f68], eax
    app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */) = cpu.eax;
    // 004679d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004679d8  7450                   -je 0x467a2a
    if (cpu.flags.zf)
    {
        goto L_0x00467a2a;
    }
    // 004679da  e861eeffff             -call 0x466840
    cpu.esp -= 4;
    sub_466840(app, cpu);
    if (cpu.terminate) return;
    // 004679df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004679e1  7450                   -je 0x467a33
    if (cpu.flags.zf)
    {
        goto L_0x00467a33;
    }
    // 004679e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004679e4  e85794fcff             -call 0x430e40
    cpu.esp -= 4;
    sub_430e40(app, cpu);
    if (cpu.terminate) return;
    // 004679e9  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004679ee  8a15f4014e00           -mov dl, byte ptr [0x4e01f4]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112308) /* 0x4e01f4 */);
    // 004679f4  e847b8fbff             -call 0x423240
    cpu.esp -= 4;
    sub_423240(app, cpu);
    if (cpu.terminate) return;
    // 004679f9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004679fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004679fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004679ff  e8aca6fbff             -call 0x4220b0
    cpu.esp -= 4;
    sub_4220b0(app, cpu);
    if (cpu.terminate) return;
    // 00467a04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467a06  741a                   -je 0x467a22
    if (cpu.flags.zf)
    {
        goto L_0x00467a22;
    }
    // 00467a08  baecd94b00             -mov edx, 0x4bd9ec
    cpu.edx = 4970988 /*0x4bd9ec*/;
    // 00467a0d  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00467a10  e8b2960200             -call 0x4910c7
    cpu.esp -= 4;
    sub_4910c7(app, cpu);
    if (cpu.terminate) return;
    // 00467a15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467a17  7409                   -je 0x467a22
    if (cpu.flags.zf)
    {
        goto L_0x00467a22;
    }
    // 00467a19  66c7059a8f4c000100     -mov word ptr [0x4c8f9a], 1
    app->getMemory<x86::reg16>(x86::reg32(5017498) /* 0x4c8f9a */) = 1 /*0x1*/;
L_0x00467a22:
    // 00467a22  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00467a27  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467a28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467a29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467a2a:
    // 00467a2a  e81194fcff             -call 0x430e40
    cpu.esp -= 4;
    sub_430e40(app, cpu);
    if (cpu.terminate) return;
    // 00467a2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467a31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467a32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467a33:
    // 00467a33  e80894fcff             -call 0x430e40
    cpu.esp -= 4;
    sub_430e40(app, cpu);
    if (cpu.terminate) return;
    // 00467a38  8915688f4c00           -mov dword ptr [0x4c8f68], edx
    app->getMemory<x86::reg32>(x86::reg32(5017448) /* 0x4c8f68 */) = cpu.edx;
    // 00467a3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467a40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467a41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 0d0000000b0000000f000000110000000c0000000a0000000e000000100000001b0000001c0000001d0000001e0000001f0000002000000021000000220000002300000012000000130000001400000015000000160000001700000018000000190000001a0000000000000000000000 */
void Application::sub_467ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00467ae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467ae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467ae2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467ae3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467ae4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467ae5  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00467ae8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00467aea  8d7c2458               -lea edi, [esp + 0x58]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00467aee  be507a4600             -mov esi, 0x467a50
    cpu.esi = 4618832 /*0x467a50*/;
    // 00467af3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467af4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467af5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467af6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467af7  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00467afb  be607a4600             -mov esi, 0x467a60
    cpu.esi = 4618848 /*0x467a60*/;
    // 00467b00  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467b01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467b02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467b03  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467b04  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00467b09  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00467b0d  be707a4600             -mov esi, 0x467a70
    cpu.esi = 4618864 /*0x467a70*/;
    // 00467b12  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467b14  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00467b19  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00467b1b  be947a4600             -mov esi, 0x467a94
    cpu.esi = 4618900 /*0x467a94*/;
    // 00467b20  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467b22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467b24  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467b26  e8254dffff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 00467b2b  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00467b30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467b32  e8d9020000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467b37  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00467b39  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00467b3b:
    // 00467b3b  8b1520104e00           -mov edx, dword ptr [0x4e1020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115936) /* 0x4e1020 */);
    // 00467b41  39d6                   +cmp esi, edx
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
    // 00467b43  0f8518020000           -jne 0x467d61
    if (!cpu.flags.zf)
    {
        goto L_0x00467d61;
    }
    // 00467b49  8b1d24104e00           -mov ebx, dword ptr [0x4e1024]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5115940) /* 0x4e1024 */);
    // 00467b4f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00467b51  0f8441010000           -je 0x467c98
    if (cpu.flags.zf)
    {
        goto L_0x00467c98;
    }
    // 00467b57  83fa03                 +cmp edx, 3
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
    // 00467b5a  773c                   -ja 0x467b98
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00467b98;
    }
    // 00467b5c  ffa7c07a4600           -jmp dword ptr [edi + 0x467ac0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + 4618944); goto dynamic_jump;
  case 0x00467b62:
    // 00467b62  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467b67  bae1ffffff             -mov edx, 0xffffffe1
    cpu.edx = 4294967265 /*0xffffffe1*/;
    // 00467b6c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00467b71  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467b73  e898020000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467b78  8b1510104e00           -mov edx, dword ptr [0x4e1010]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */);
    // 00467b7e  83fa01                 +cmp edx, 1
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
    // 00467b81  0f8578000000           -jne 0x467bff
    if (!cpu.flags.zf)
    {
        goto L_0x00467bff;
    }
    // 00467b87  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467b8c  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00467b91  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00467b93:
    // 00467b93  e878020000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
L_0x00467b98:
    // 00467b98  46                     -inc esi
    (cpu.esi)++;
    // 00467b99  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467b9c  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467b9f  7c9a                   -jl 0x467b3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00467b3b;
    }
    // 00467ba1  8b0dd88b4c00           -mov ecx, dword ptr [0x4c8bd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016536) /* 0x4c8bd8 */);
    // 00467ba7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00467ba9  7438                   -je 0x467be3
    if (cpu.flags.zf)
    {
        goto L_0x00467be3;
    }
    // 00467bab  8b15c4f74f00           -mov edx, dword ptr [0x4ff7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00467bb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00467bb3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00467bb6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467bb8  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00467bbb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00467bbd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00467bc0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00467bc2  3d88000000             +cmp eax, 0x88
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467bc7  0f8ef9010000           -jle 0x467dc6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00467dc6;
    }
    // 00467bcd  ba88000000             -mov edx, 0x88
    cpu.edx = 136 /*0x88*/;
L_0x00467bd2:
    // 00467bd2  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467bd7  b824000000             -mov eax, 0x24
    cpu.eax = 36 /*0x24*/;
    // 00467bdc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467bde  e82d020000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
L_0x00467be3:
    // 00467be3  8d742468               -lea esi, [esp + 0x68]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00467be7  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00467be9  e8d24bffff             -call 0x45c7c0
    cpu.esp -= 4;
    sub_45c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00467bee  8d742468               -lea esi, [esp + 0x68]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00467bf2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467bf3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467bf4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00467bf6  83c470                 +add esp, 0x70
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
    // 00467bf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bfa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467bfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467bff:
    // 00467bff  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c04  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00467c09  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00467c0e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00467c10  eb81                   -jmp 0x467b93
    goto L_0x00467b93;
  case 0x00467c12:
    // 00467c12  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c17  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00467c1c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467c1e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467c20  e8eb010000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467c25  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00467c2a  a114104e00             -mov eax, dword ptr [0x4e1014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
    // 00467c2f  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c34  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00467c36  8b448458               -mov eax, dword ptr [esp + eax*4 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */ + cpu.eax * 4);
    // 00467c3a  e954ffffff             -jmp 0x467b93
    goto L_0x00467b93;
  case 0x00467c3f:
    // 00467c3f  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c44  ba1f000000             -mov edx, 0x1f
    cpu.edx = 31 /*0x1f*/;
    // 00467c49  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00467c4e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00467c50  e8bb010000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467c55  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c5a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00467c5f  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00467c64  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00467c66  e928ffffff             -jmp 0x467b93
    goto L_0x00467b93;
  case 0x00467c6b:
    // 00467c6b  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c70  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00467c75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467c77  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467c79  e892010000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467c7e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00467c83  a11c104e00             -mov eax, dword ptr [0x4e101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 00467c88  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467c8d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00467c8f  8b448424               -mov eax, dword ptr [esp + eax*4 + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */ + cpu.eax * 4);
    // 00467c93  e9fbfeffff             -jmp 0x467b93
    goto L_0x00467b93;
L_0x00467c98:
    // 00467c98  83fa03                 +cmp edx, 3
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
    // 00467c9b  0f87f7feffff           -ja 0x467b98
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00467b98;
    }
    // 00467ca1  ffa7d07a4600           -jmp dword ptr [edi + 0x467ad0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + 4618960); goto dynamic_jump;
  case 0x00467ca7:
    // 00467ca7  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467cac  bae1ffffff             -mov edx, 0xffffffe1
    cpu.edx = 4294967265 /*0xffffffe1*/;
    // 00467cb1  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00467cb6  e855010000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467cbb  833d10104e0001         +cmp dword ptr [0x4e1010], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467cc2  7513                   -jne 0x467cd7
    if (!cpu.flags.zf)
    {
        goto L_0x00467cd7;
    }
    // 00467cc4  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467cc9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00467cce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467cd0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467cd2  e9bcfeffff             -jmp 0x467b93
    goto L_0x00467b93;
L_0x00467cd7:
    // 00467cd7  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467cdc  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00467ce1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467ce3  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467ce5  e9a9feffff             -jmp 0x467b93
    goto L_0x00467b93;
  case 0x00467cea:
    // 00467cea  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467cef  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00467cf4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467cf6  e815010000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467cfb  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d00  a114104e00             -mov eax, dword ptr [0x4e1014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
    // 00467d05  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467d07  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467d09  8b448458               -mov eax, dword ptr [esp + eax*4 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */ + cpu.eax * 4);
    // 00467d0d  e981feffff             -jmp 0x467b93
    goto L_0x00467b93;
  case 0x00467d12:
    // 00467d12  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d17  ba1f000000             -mov edx, 0x1f
    cpu.edx = 31 /*0x1f*/;
    // 00467d1c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00467d21  e8ea000000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467d26  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d2b  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00467d30  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467d32  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467d34  e95afeffff             -jmp 0x467b93
    goto L_0x00467b93;
  case 0x00467d39:
    // 00467d39  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d3e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00467d43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467d45  e8c6000000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467d4a  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d4f  a11c104e00             -mov eax, dword ptr [0x4e101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 00467d54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467d56  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467d58  8b448424               -mov eax, dword ptr [esp + eax*4 + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */ + cpu.eax * 4);
    // 00467d5c  e932feffff             -jmp 0x467b93
    goto L_0x00467b93;
L_0x00467d61:
    // 00467d61  83fe01                 +cmp esi, 1
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
    // 00467d64  7328                   -jae 0x467d8e
    if (!cpu.flags.cf)
    {
        goto L_0x00467d8e;
    }
    // 00467d66  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00467d68  0f852afeffff           -jne 0x467b98
    if (!cpu.flags.zf)
    {
        goto L_0x00467b98;
    }
    // 00467d6e  833d10104e0001         +cmp dword ptr [0x4e1010], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00467d75  0f851dfeffff           -jne 0x467b98
    if (!cpu.flags.zf)
    {
        goto L_0x00467b98;
    }
    // 00467d7b  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d80  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00467d85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467d87  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467d89  e905feffff             -jmp 0x467b93
    goto L_0x00467b93;
L_0x00467d8e:
    // 00467d8e  761f                   -jbe 0x467daf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00467daf;
    }
    // 00467d90  83fe03                 +cmp esi, 3
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
    // 00467d93  0f85fffdffff           -jne 0x467b98
    if (!cpu.flags.zf)
    {
        goto L_0x00467b98;
    }
    // 00467d99  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467d9e  a11c104e00             -mov eax, dword ptr [0x4e101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
    // 00467da3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467da5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467da7  8b0484                 -mov eax, dword ptr [esp + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 4);
    // 00467daa  e9e4fdffff             -jmp 0x467b93
    goto L_0x00467b93;
L_0x00467daf:
    // 00467daf  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00467db4  a114104e00             -mov eax, dword ptr [0x4e1014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115924) /* 0x4e1014 */);
    // 00467db9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467dbb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00467dbd  8b448448               -mov eax, dword ptr [esp + eax*4 + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */ + cpu.eax * 4);
    // 00467dc1  e9cdfdffff             -jmp 0x467b93
    goto L_0x00467b93;
L_0x00467dc6:
    // 00467dc6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00467dc8  e905feffff             -jmp 0x467bd2
    goto L_0x00467bd2;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_467dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467dd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467dd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467dd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467dd5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00467dd8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00467dda  e8714affff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 00467ddf  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00467de4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467de6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467de8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00467dea  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00467dec  e81f000000             -call 0x467e10
    cpu.esp -= 4;
    sub_467e10(app, cpu);
    if (cpu.terminate) return;
    // 00467df1  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00467df3  e8c849ffff             -call 0x45c7c0
    cpu.esp -= 4;
    sub_45c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00467df8  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00467dfa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467dfb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00467dfc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00467dfe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00467e01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_467e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467e10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00467e11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467e12  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467e15  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00467e17  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00467e19  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 00467e1e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00467e20  e8db49ffff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 00467e25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00467e27  7506                   -jne 0x467e2f
    if (!cpu.flags.zf)
    {
        goto L_0x00467e2f;
    }
    // 00467e29  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467e2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00467e2f:
    // 00467e2f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00467e32  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00467e35  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00467e37  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00467e3a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00467e3c  bec45d5100             -mov esi, 0x515dc4
    cpu.esi = 5332420 /*0x515dc4*/;
    // 00467e41  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00467e44  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00467e47  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00467e49  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00467e4c  8bb0c45d5100           -mov esi, dword ptr [eax + 0x515dc4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5332420) /* 0x515dc4 */);
    // 00467e52  8b760c                 -mov esi, dword ptr [esi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00467e55  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00467e58  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00467e5b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00467e5e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00467e60  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00467e63  8b80c45d5100           -mov eax, dword ptr [eax + 0x515dc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5332420) /* 0x515dc4 */);
    // 00467e69  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00467e6c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00467e6f  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00467e72  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00467e75  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00467e77  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00467e7a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467e7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00467e7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_467e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00467e80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00467e81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00467e82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00467e83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00467e84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00467e85  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00467e88  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00467e8c  e86f1afdff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 00467e91  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 00467e96  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 00467e9b  8b1d10ec4d00           -mov ebx, dword ptr [0x4dec10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 00467ea1  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00467ea5  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00467ea8  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00467eac  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 00467eaf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00467eb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00467eb3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00467eb6  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00467eb8  a3c8944c00             -mov dword ptr [0x4c94c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5018824) /* 0x4c94c8 */) = cpu.eax;
    // 00467ebd  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 00467ec3  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00467ec6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00467eca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00467ecc  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00467ed2  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00467ed4  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00467ed7  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00467edb  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00467edf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00467ee1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00467ee3  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00467ee5  e806080000             -call 0x4686f0
    cpu.esp -= 4;
    sub_4686f0(app, cpu);
    if (cpu.terminate) return;
    // 00467eea  a1c05d5100             -mov eax, dword ptr [0x515dc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332416) /* 0x515dc0 */);
    // 00467eef  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00467ef3  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00467ef9  c0e507                 +shl ch, 7
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
    // 00467efc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00467efe  00ed                   +add ch, ch
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
    // 00467f00  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00467f02  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467f04  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00467f09  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467f0b  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00467f12  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467f14  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00467f16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00467f18  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00467f1c  a1c05d5100             -mov eax, dword ptr [0x515dc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332416) /* 0x515dc0 */);
    // 00467f21  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00467f25  c0e407                 +shl ah, 7
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
    // 00467f28  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00467f2a  00e4                   +add ah, ah
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
    // 00467f2c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00467f2e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467f30  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00467f35  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00467f37  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00467f3e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467f40  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00467f42  0335c8904c00           -add esi, dword ptr [0x4c90c8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017800) /* 0x4c90c8 */)));
    // 00467f48  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00467f4c  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00467f4f  bf7e000000             -mov edi, 0x7e
    cpu.edi = 126 /*0x7e*/;
    // 00467f54  bac8904c00             -mov edx, 0x4c90c8
    cpu.edx = 5017800 /*0x4c90c8*/;
    // 00467f59  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 00467f5d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467f60  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00467f64  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00467f68  033dc8924c00           -add edi, dword ptr [0x4c92c8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5018312) /* 0x4c92c8 */)));
    // 00467f6e  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00467f71  bdc8924c00             -mov ebp, 0x4c92c8
    cpu.ebp = 5018312 /*0x4c92c8*/;
    // 00467f76  b93c605100             -mov ecx, 0x51603c
    cpu.ecx = 5333052 /*0x51603c*/;
    // 00467f7b  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00467f7e  8b1548f54d00           -mov edx, dword ptr [0x4df548]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00467f84  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00467f86  33154cf54d00           -xor edx, dword ptr [0x4df54c]
    cpu.edx ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */)));
    // 00467f8c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00467f8f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00467f91  0f8458030000           -je 0x4682ef
    if (cpu.flags.zf)
    {
        goto L_0x004682ef;
    }
    // 00467f97  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 00467f9c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00467f9e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00467fa0:
    // 00467fa0  0faf7c242c             -imul edi, dword ptr [esp + 0x2c]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00467fa5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00467fa9  0faf742428             -imul esi, dword ptr [esp + 0x28]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00467fae  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00467fb1  8b1548f54d00           -mov edx, dword ptr [0x4df548]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00467fb7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00467fba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00467fbc  0f8435030000           -je 0x4682f7
    if (cpu.flags.zf)
    {
        goto L_0x004682f7;
    }
    // 00467fc2  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
L_0x00467fc6:
    // 00467fc6  bbcc944c00             -mov ebx, 0x4c94cc
    cpu.ebx = 5018828 /*0x4c94cc*/;
    // 00467fcb  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00467fcf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00467fd1  b8d0944c00             -mov eax, 0x4c94d0
    cpu.eax = 5018832 /*0x4c94d0*/;
L_0x00467fd6:
    // 00467fd6  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00467fda  660fbe33               -movsx si, byte ptr [ebx]
    cpu.si = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx)));
    // 00467fde  43                     -inc ebx
    (cpu.ebx)++;
    // 00467fdf  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00467fe1  40                     -inc eax
    (cpu.eax)++;
    // 00467fe2  6689790a               -mov word ptr [ecx + 0xa], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.di;
    // 00467fe6  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00467fea  660fbe70ff             -movsx si, byte ptr [eax - 1]
    cpu.si = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */)));
    // 00467fef  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00467ff2  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00467ff4  42                     -inc edx
    (cpu.edx)++;
    // 00467ff5  668979f8               -mov word ptr [ecx - 8], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-8) /* -0x8 */) = cpu.di;
    // 00467ff9  83fa04                 +cmp edx, 4
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
    // 00467ffc  7cd8                   -jl 0x467fd6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00467fd6;
    }
    // 00467ffe  83e950                 -sub ecx, 0x50
    (cpu.ecx) -= x86::reg32(x86::sreg32(80 /*0x50*/));
L_0x00468001:
    // 00468001  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00468005  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468009  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046800c  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0046800e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00468010  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468014  89742438               -mov dword ptr [esp + 0x38], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.esi;
    // 00468018  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0046801a  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046801c  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046801e  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468022  0faff2                 -imul esi, edx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00468025  8b3d4cf54d00           -mov edi, dword ptr [0x4df54c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 0046802b  333d48f54d00           -xor edi, dword ptr [0x4df548]
    cpu.edi ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */)));
    // 00468031  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00468035  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00468038  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046803a  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046803d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00468040  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468042  0f84bc020000           -je 0x468304
    if (cpu.flags.zf)
    {
        goto L_0x00468304;
    }
    // 00468048  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046804c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046804e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00468050:
    // 00468050  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468054  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00468057  0faf542428             -imul edx, dword ptr [esp + 0x28]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 0046805c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046805e  8b3d48f54d00           -mov edi, dword ptr [0x4df548]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00468064  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00468067  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468069  0f849e020000           -je 0x46830d
    if (cpu.flags.zf)
    {
        goto L_0x0046830d;
    }
    // 0046806f  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
L_0x00468073:
    // 00468073  bacc944c00             -mov edx, 0x4c94cc
    cpu.edx = 5018828 /*0x4c94cc*/;
    // 00468078  bbd0944c00             -mov ebx, 0x4c94d0
    cpu.ebx = 5018832 /*0x4c94d0*/;
    // 0046807d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00468081  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00468083:
    // 00468083  660fbe3a               -movsx di, byte ptr [edx]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 00468087  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00468089  43                     -inc ebx
    (cpu.ebx)++;
    // 0046808a  6689790e               -mov word ptr [ecx + 0xe], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.di;
    // 0046808e  42                     -inc edx
    (cpu.edx)++;
    // 0046808f  660fbe7bff             -movsx di, byte ptr [ebx - 1]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */)));
    // 00468094  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00468097  037c2408               -add edi, dword ptr [esp + 8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046809b  40                     -inc eax
    (cpu.eax)++;
    // 0046809c  668979fc               -mov word ptr [ecx - 4], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.di;
    // 004680a0  83f804                 +cmp eax, 4
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
    // 004680a3  7cde                   -jl 0x468083
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468083;
    }
    // 004680a5  bbd0944c00             -mov ebx, 0x4c94d0
    cpu.ebx = 5018832 /*0x4c94d0*/;
    // 004680aa  bacc944c00             -mov edx, 0x4c94cc
    cpu.edx = 5018828 /*0x4c94cc*/;
    // 004680af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004680b1:
    // 004680b1  660fbe3a               -movsx di, byte ptr [edx]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 004680b5  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004680b7  43                     -inc ebx
    (cpu.ebx)++;
    // 004680b8  6689790a               -mov word ptr [ecx + 0xa], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.di;
    // 004680bc  42                     -inc edx
    (cpu.edx)++;
    // 004680bd  660fbe7bff             -movsx di, byte ptr [ebx - 1]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */)));
    // 004680c2  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004680c5  037c2408               -add edi, dword ptr [esp + 8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004680c9  40                     -inc eax
    (cpu.eax)++;
    // 004680ca  668979f8               -mov word ptr [ecx - 8], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-8) /* -0x8 */) = cpu.di;
    // 004680ce  83f804                 +cmp eax, 4
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
    // 004680d1  7cde                   -jl 0x4680b1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004680b1;
    }
    // 004680d3  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004680d7  4b                     -dec ebx
    (cpu.ebx)--;
    // 004680d8  83e950                 -sub ecx, 0x50
    (cpu.ecx) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004680db  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004680df  83fbff                 +cmp ebx, -1
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
    // 004680e2  0f8519ffffff           -jne 0x468001
    if (!cpu.flags.zf)
    {
        goto L_0x00468001;
    }
    // 004680e8  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004680ec  8b3dc8904c00           -mov edi, dword ptr [0x4c90c8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5017800) /* 0x4c90c8 */);
    // 004680f2  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004680f6  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004680f8  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004680fb  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004680ff  8b2dc8924c00           -mov ebp, dword ptr [0x4c92c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5018312) /* 0x4c92c8 */);
    // 00468105  8b354cf54d00           -mov esi, dword ptr [0x4df54c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 0046810b  8b3d48f54d00           -mov edi, dword ptr [0x4df548]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00468111  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00468113  31f7                   -xor edi, esi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00468115  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00468119  0faff2                 -imul esi, edx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046811c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046811e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00468121  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468123  0f84f1010000           -je 0x46831a
    if (cpu.flags.zf)
    {
        goto L_0x0046831a;
    }
    // 00468129  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046812d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046812f:
    // 0046812f  0faf54242c             -imul edx, dword ptr [esp + 0x2c]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00468134  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00468138  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0046813b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046813d  8b2d48f54d00           -mov ebp, dword ptr [0x4df548]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00468143  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00468146  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00468148  0f84d7010000           -je 0x468325
    if (cpu.flags.zf)
    {
        goto L_0x00468325;
    }
    // 0046814e  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
L_0x00468152:
    // 00468152  bbcc944c00             -mov ebx, 0x4c94cc
    cpu.ebx = 5018828 /*0x4c94cc*/;
    // 00468157  bad0944c00             -mov edx, 0x4c94d0
    cpu.edx = 5018832 /*0x4c94d0*/;
    // 0046815c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00468160  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00468162:
    // 00468162  660fbe3b               -movsx di, byte ptr [ebx]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx)));
    // 00468166  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00468168  42                     -inc edx
    (cpu.edx)++;
    // 00468169  6689790e               -mov word ptr [ecx + 0xe], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.di;
    // 0046816d  43                     -inc ebx
    (cpu.ebx)++;
    // 0046816e  660fbe7aff             -movsx di, byte ptr [edx - 1]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */)));
    // 00468173  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00468176  037c2408               -add edi, dword ptr [esp + 8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046817a  40                     -inc eax
    (cpu.eax)++;
    // 0046817b  668979fc               -mov word ptr [ecx - 4], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.di;
    // 0046817f  83f804                 +cmp eax, 4
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
    // 00468182  7cde                   -jl 0x468162
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468162;
    }
    // 00468184  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468188  a118ec4d00             -mov eax, dword ptr [0x4dec18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 0046818d  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468191  8b35c8904c00           -mov esi, dword ptr [0x4c90c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017800) /* 0x4c90c8 */);
    // 00468197  8b500f                 -mov edx, dword ptr [eax + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0046819a  8b7811                 -mov edi, dword ptr [eax + 0x11]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 0046819d  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046819f  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004681a2  a1c8924c00             -mov eax, dword ptr [0x4c92c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018312) /* 0x4c92c8 */);
    // 004681a7  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004681aa  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004681ac  c1fa0d                 -sar edx, 0xd
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (13 /*0xd*/ % 32));
    // 004681af  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004681b3  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004681b5  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004681b8  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 004681bb  c1e709                 -shl edi, 9
    cpu.edi <<= 9 /*0x9*/ % 32;
    // 004681be  c1ff0d                 -sar edi, 0xd
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (13 /*0xd*/ % 32));
    // 004681c1  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004681c5  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004681c7  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004681cb  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004681ce  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004681d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004681d2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004681d5  c1e210                 +shl edx, 0x10
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
    // 004681d8  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004681da  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004681dd  0faf5c2428             -imul ebx, dword ptr [esp + 0x28]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 004681e2  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004681e6  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004681e9  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004681eb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004681ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004681ef  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004681f2  c1e210                 +shl edx, 0x10
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
    // 004681f5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004681f7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004681fa  8b1d4cf54d00           -mov ebx, dword ptr [0x4df54c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 00468200  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00468204  a148f54d00             -mov eax, dword ptr [0x4df548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00468209  31d8                   +xor eax, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046820b  0f8421010000           -je 0x468332
    if (cpu.flags.zf)
    {
        goto L_0x00468332;
    }
    // 00468211  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00468215  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00468217:
    // 00468217  8b3548f54d00           -mov esi, dword ptr [0x4df548]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 0046821d  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00468221  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468223  0f8414010000           -je 0x46833d
    if (cpu.flags.zf)
    {
        goto L_0x0046833d;
    }
    // 00468229  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046822d  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x00468231:
    // 00468231  6689410c               -mov word ptr [ecx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 00468235  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468239  8b1dc8904c00           -mov ebx, dword ptr [0x4c90c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017800) /* 0x4c90c8 */);
    // 0046823f  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468243  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00468245  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00468249  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046824b  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0046824e  a1c8924c00             -mov eax, dword ptr [0x4c92c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018312) /* 0x4c92c8 */);
    // 00468253  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468257  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468259  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046825d  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046825f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00468262  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00468264  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468266  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00468269  c1e210                 +shl edx, 0x10
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
    // 0046826c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046826e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00468271  0faf6c2428             -imul ebp, dword ptr [esp + 0x28]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00468276  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046827a  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0046827d  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046827f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468281  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468283  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00468286  c1e210                 +shl edx, 0x10
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
    // 00468289  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046828b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046828e  8b1d4cf54d00           -mov ebx, dword ptr [0x4df54c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 00468294  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00468298  a148f54d00             -mov eax, dword ptr [0x4df548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 0046829d  31d8                   +xor eax, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046829f  0f84a5000000           -je 0x46834a
    if (cpu.flags.zf)
    {
        goto L_0x0046834a;
    }
    // 004682a5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004682a9  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004682ab:
    // 004682ab  8b3548f54d00           -mov esi, dword ptr [0x4df548]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 004682b1  6689410e               -mov word ptr [ecx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004682b5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004682b7  0f8498000000           -je 0x468355
    if (cpu.flags.zf)
    {
        goto L_0x00468355;
    }
    // 004682bd  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004682c1  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x004682c5:
    // 004682c5  ba3c885100             -mov edx, 0x51883c
    cpu.edx = 5343292 /*0x51883c*/;
    // 004682ca  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004682ce  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004682d0  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004682d4  b83c605100             -mov eax, 0x51603c
    cpu.eax = 5333052 /*0x51603c*/;
    // 004682d9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004682dd  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004682e0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004682e1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004682e2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004682e6  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004682e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004682ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004682eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004682ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004682ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004682ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004682ef:
    // 004682ef  83c035                 +add eax, 0x35
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004682f2  e9a9fcffff             -jmp 0x467fa0
    goto L_0x00467fa0;
L_0x004682f7:
    // 004682f7  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004682fb  29c2                   +sub edx, eax
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
    // 004682fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004682ff  e9c2fcffff             -jmp 0x467fc6
    goto L_0x00467fc6;
L_0x00468304:
    // 00468304  03742424               +add esi, dword ptr [esp + 0x24]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00468308  e943fdffff             -jmp 0x468050
    goto L_0x00468050;
L_0x0046830d:
    // 0046830d  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00468311  29c2                   +sub edx, eax
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
    // 00468313  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468315  e959fdffff             -jmp 0x468073
    goto L_0x00468073;
L_0x0046831a:
    // 0046831a  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046831e  01c6                   +add esi, eax
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
    // 00468320  e90afeffff             -jmp 0x46812f
    goto L_0x0046812f;
L_0x00468325:
    // 00468325  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00468329  29c2                   +sub edx, eax
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
    // 0046832b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046832d  e920feffff             -jmp 0x468152
    goto L_0x00468152;
L_0x00468332:
    // 00468332  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00468336  01f0                   +add eax, esi
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
    // 00468338  e9dafeffff             -jmp 0x468217
    goto L_0x00468217;
L_0x0046833d:
    // 0046833d  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00468341  2b442408               +sub eax, dword ptr [esp + 8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00468345  e9e7feffff             -jmp 0x468231
    goto L_0x00468231;
L_0x0046834a:
    // 0046834a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046834e  01f0                   +add eax, esi
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
    // 00468350  e956ffffff             -jmp 0x4682ab
    goto L_0x004682ab;
L_0x00468355:
    // 00468355  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00468359  2b442408               +sub eax, dword ptr [esp + 8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046835d  e963ffffff             -jmp 0x4682c5
    goto L_0x004682c5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_468370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468372  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468373  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468374  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468375  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00468378  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046837e  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00468382  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00468384  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 00468389  be44000000             -mov esi, 0x44
    cpu.esi = 68 /*0x44*/;
    // 0046838e  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00468395  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00468399  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046839b  b9e04c5100             -mov ecx, 0x514ce0
    cpu.ecx = 5328096 /*0x514ce0*/;
    // 004683a0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004683a3  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004683a7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004683a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004683ab  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004683ae  e84d15fdff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 004683b3  8b909c000000           -mov edx, dword ptr [eax + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 004683b9  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004683bd  c1fa13                 -sar edx, 0x13
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (19 /*0x13*/ % 32));
    // 004683c0  8b80a4000000           -mov eax, dword ptr [eax + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 004683c6  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004683ca  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004683cc  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 004683cf  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004683d1  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004683d5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004683d7  a1c05d5100             -mov eax, dword ptr [0x515dc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332416) /* 0x515dc0 */);
    // 004683dc  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004683e0  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004683e2  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004683e8  c0e507                 +shl ch, 7
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
    // 004683eb  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004683ed  00ed                   +add ch, ch
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
    // 004683ef  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004683f1  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004683f3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004683f8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004683fa  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00468401  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00468403  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468405  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00468409  a1c05d5100             -mov eax, dword ptr [0x515dc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332416) /* 0x515dc0 */);
    // 0046840e  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00468412  c0e407                 +shl ah, 7
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
    // 00468415  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00468417  00e4                   +add ah, ah
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
    // 00468419  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046841b  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046841d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00468422  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468424  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0046842b  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046842d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046842f  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468435  8b15a4f14d00           -mov edx, dword ptr [0x4df1a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 0046843b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046843d  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00468441  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00468445  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00468447  0f8e52010000           -jle 0x46859f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046859f;
    }
    // 0046844d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046844f:
    // 0046844f  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468453  3bb268ef4d00           +cmp esi, dword ptr [edx + 0x4def68]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107560) /* 0x4def68 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468459  0f846e020000           -je 0x4686cd
    if (cpu.flags.zf)
    {
        goto L_0x004686cd;
    }
    // 0046845f  83fb77                 +cmp ebx, 0x77
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468462  0f8c08020000           -jl 0x468670
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468670;
    }
    // 00468468  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046846a:
    // 0046846a  6bc024                 -imul eax, eax, 0x24
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 0046846d  bee04c5100             -mov esi, 0x514ce0
    cpu.esi = 5328096 /*0x514ce0*/;
    // 00468472  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468474  6bc324                 -imul eax, ebx, 0x24
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00468477  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 0046847c  89b0e04c5100           -mov dword ptr [eax + 0x514ce0], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328096) /* 0x514ce0 */) = cpu.esi;
    // 00468482  89b8e44c5100           -mov dword ptr [eax + 0x514ce4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328100) /* 0x514ce4 */) = cpu.edi;
    // 00468488  8b8268ef4d00           -mov eax, dword ptr [edx + 0x4def68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107560) /* 0x4def68 */);
    // 0046848e  891db08f4c00           -mov dword ptr [0x4c8fb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */) = cpu.ebx;
    // 00468494  f680f401000004         +test byte ptr [eax + 0x1f4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 4 /*0x4*/));
    // 0046849b  0f84d7010000           -je 0x468678
    if (cpu.flags.zf)
    {
        goto L_0x00468678;
    }
    // 004684a1  8b800c060000           -mov eax, dword ptr [eax + 0x60c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1548) /* 0x60c */);
    // 004684a7  e884e8fdff             -call 0x446d30
    cpu.esp -= 4;
    sub_446d30(app, cpu);
    if (cpu.terminate) return;
    // 004684ac  6bc00c                 -imul eax, eax, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 004684af  0570485100             -add eax, 0x514870
    (cpu.eax) += x86::reg32(x86::sreg32(5326960 /*0x514870*/));
L_0x004684b4:
    // 004684b4  8bba68ef4d00           -mov edi, dword ptr [edx + 0x4def68]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107560) /* 0x4def68 */);
    // 004684ba  8bb79c000000           -mov esi, dword ptr [edi + 0x9c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(156) /* 0x9c */);
    // 004684c0  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004684c4  c1fe13                 -sar esi, 0x13
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (19 /*0x13*/ % 32));
    // 004684c7  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004684c9  8b6c2430               -mov ebp, dword ptr [esp + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004684cd  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004684d0  8bbfa4000000           -mov edi, dword ptr [edi + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(164) /* 0xa4 */);
    // 004684d6  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004684da  c1ff13                 -sar edi, 0x13
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (19 /*0x13*/ % 32));
    // 004684dd  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004684df  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004684e3  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004684e7  0fafef                 -imul ebp, edi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004684ea  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004684ee  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004684f2  2b6c240c               -sub ebp, dword ptr [esp + 0xc]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004684f6  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 004684fb  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004684fe  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 00468502  0faf74242c             -imul esi, dword ptr [esp + 0x2c]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00468507  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046850d  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046850f  6bf324                 -imul esi, ebx, 0x24
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00468512  8b2d4cf54d00           -mov ebp, dword ptr [0x4df54c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 00468518  8986004d5100           -mov dword ptr [esi + 0x514d00], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5328128) /* 0x514d00 */) = cpu.eax;
    // 0046851e  8b3548f54d00           -mov esi, dword ptr [0x4df548]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00468524  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00468527  31ee                   +xor esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00468529  0f8466010000           -je 0x468695
    if (cpu.flags.zf)
    {
        goto L_0x00468695;
    }
    // 0046852f  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00468531  8b7606                 -mov esi, dword ptr [esi + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00468534  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00468537  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046853b  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0046853f  be35000000             -mov esi, 0x35
    cpu.esi = 53 /*0x35*/;
    // 00468544  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00468546  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046854a  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046854c  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
L_0x00468550:
    // 00468550  6bf324                 -imul esi, ebx, 0x24
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00468553  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00468557  89aee84c5100           -mov dword ptr [esi + 0x514ce8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5328104) /* 0x514ce8 */) = cpu.ebp;
    // 0046855d  833d48f54d0000         +cmp dword ptr [0x4df548], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468564  0f8445010000           -je 0x4686af
    if (cpu.flags.zf)
    {
        goto L_0x004686af;
    }
    // 0046856a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046856c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046856f  83c744                 -add edi, 0x44
    (cpu.edi) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00468572  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00468575  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00468577  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00468579:
    // 00468579  6bf324                 -imul esi, ebx, 0x24
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 0046857c  8986ec4c5100           -mov dword ptr [esi + 0x514cec], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5328108) /* 0x514cec */) = cpu.eax;
    // 00468582  83fb77                 +cmp ebx, 0x77
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468585  0f8c3c010000           -jl 0x4686c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004686c7;
    }
    // 0046858b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046858d:
    // 0046858d  8b35a4f14d00           -mov esi, dword ptr [0x4df1a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 00468593  41                     -inc ecx
    (cpu.ecx)++;
    // 00468594  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00468597  39f1                   +cmp ecx, esi
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
    // 00468599  0f8cb0feffff           -jl 0x46844f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046844f;
    }
L_0x0046859f:
    // 0046859f  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 004685a6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004685a8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004685aa  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
    // 004685af  893c85e04c5100         -mov dword ptr [eax*4 + 0x514ce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.edi;
    // 004685b6  892c85e44c5100         -mov dword ptr [eax*4 + 0x514ce4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5328100) /* 0x514ce4 */ + cpu.eax * 4) = cpu.ebp;
    // 004685bd  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004685c1  8b048568ef4d00         -mov eax, dword ptr [eax*4 + 0x4def68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107560) /* 0x4def68 */ + cpu.eax * 4);
    // 004685c8  8b800c060000           -mov eax, dword ptr [eax + 0x60c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1548) /* 0x60c */);
    // 004685ce  891db08f4c00           -mov dword ptr [0x4c8fb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */) = cpu.ebx;
    // 004685d4  e857e7fdff             -call 0x446d30
    cpu.esp -= 4;
    sub_446d30(app, cpu);
    if (cpu.terminate) return;
    // 004685d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004685db  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004685de  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004685e0  ba70485100             -mov edx, 0x514870
    cpu.edx = 5326960 /*0x514870*/;
    // 004685e5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004685e8  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 004685ee  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004685f0  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 004685f7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004685f9  891485004d5100         -mov dword ptr [eax*4 + 0x514d00], edx
    app->getMemory<x86::reg32>(x86::reg32(5328128) /* 0x514d00 */ + cpu.eax * 4) = cpu.edx;
    // 00468600  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00468602  8b4906                 -mov ecx, dword ptr [ecx + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00468605  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468609  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046860c  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046860e  893485e84c5100         -mov dword ptr [eax*4 + 0x514ce8], esi
    app->getMemory<x86::reg32>(x86::reg32(5328104) /* 0x514ce8 */ + cpu.eax * 4) = cpu.esi;
    // 00468615  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00468617  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046861a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046861e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00468621  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468623  890c85ec4c5100         -mov dword ptr [eax*4 + 0x514cec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5328108) /* 0x514cec */ + cpu.eax * 4) = cpu.ecx;
    // 0046862a  83fb77                 +cmp ebx, 0x77
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046862d  0f8ca3000000           -jl 0x4686d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004686d6;
    }
    // 00468633  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00468635:
    // 00468635  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00468637  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468639  0f8e9f000000           -jle 0x4686de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004686de;
    }
    // 0046863f  48                     -dec eax
    (cpu.eax)--;
L_0x00468640:
    // 00468640  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00468642  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00468645  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468647  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 0046864c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046864f  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468653  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468655  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468657  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046865b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046865c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046865d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468661  891db08f4c00           -mov dword ptr [0x4c8fb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */) = cpu.ebx;
    // 00468667  83c43c                 +add esp, 0x3c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046866a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046866b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046866c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046866d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046866e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046866f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468670:
    // 00468670  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00468673  e9f2fdffff             -jmp 0x46846a
    goto L_0x0046846a;
L_0x00468678:
    // 00468678  8b800c060000           -mov eax, dword ptr [eax + 0x60c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1548) /* 0x60c */);
    // 0046867e  e8ade6fdff             -call 0x446d30
    cpu.esp -= 4;
    sub_446d30(app, cpu);
    if (cpu.terminate) return;
    // 00468683  6bc00c                 -imul eax, eax, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00468686  0570485100             -add eax, 0x514870
    (cpu.eax) += x86::reg32(x86::sreg32(5326960 /*0x514870*/));
    // 0046868b  05c0000000             +add eax, 0xc0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00468690  e91ffeffff             -jmp 0x4684b4
    goto L_0x004684b4;
L_0x00468695:
    // 00468695  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00468697  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046869b  8b7606                 -mov esi, dword ptr [esi + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0046869e  83c535                 -add ebp, 0x35
    (cpu.ebp) += x86::reg32(x86::sreg32(53 /*0x35*/));
    // 004686a1  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004686a4  29f5                   +sub ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004686a6  896c2434               -mov dword ptr [esp + 0x34], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebp;
    // 004686aa  e9a1feffff             -jmp 0x468550
    goto L_0x00468550;
L_0x004686af:
    // 004686af  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004686b1  be44000000             -mov esi, 0x44
    cpu.esi = 68 /*0x44*/;
    // 004686b6  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004686b9  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004686bb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004686be  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004686c0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004686c2  e9b2feffff             -jmp 0x468579
    goto L_0x00468579;
L_0x004686c7:
    // 004686c7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004686c8  e9c0feffff             -jmp 0x46858d
    goto L_0x0046858d;
L_0x004686cd:
    // 004686cd  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004686d1  e9b7feffff             -jmp 0x46858d
    goto L_0x0046858d;
L_0x004686d6:
    // 004686d6  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004686d9  e957ffffff             -jmp 0x468635
    goto L_0x00468635;
L_0x004686de:
    // 004686de  b877000000             -mov eax, 0x77
    cpu.eax = 119 /*0x77*/;
    // 004686e3  e958ffffff             -jmp 0x468640
    goto L_0x00468640;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4686f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004686f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004686f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004686f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004686f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004686f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004686f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004686f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004686f9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004686fb  8b1510ec4d00           -mov edx, dword ptr [0x4dec10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 00468701  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00468704  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00468706  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00468708  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046870b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046870d:
    // 0046870d  6bf824                 -imul edi, eax, 0x24
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00468710  8b0d18ec4d00           -mov ecx, dword ptr [0x4dec18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 00468716  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00468718  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046871b  8b490e                 -mov ecx, dword ptr [ecx + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0046871e  40                     -inc eax
    (cpu.eax)++;
    // 0046871f  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00468722  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00468725  c1e109                 -shl ecx, 9
    cpu.ecx <<= 9 /*0x9*/ % 32;
    // 00468728  c1e709                 -shl edi, 9
    cpu.edi <<= 9 /*0x9*/ % 32;
    // 0046872b  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046872d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00468730  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00468732  39c8                   +cmp eax, ecx
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
    // 00468734  7d45                   -jge 0x46877b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046877b;
    }
L_0x00468736:
    // 00468736  42                     -inc edx
    (cpu.edx)++;
    // 00468737  83fa20                 +cmp edx, 0x20
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
    // 0046873a  7cd1                   -jl 0x46870d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046870d;
    }
    // 0046873c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046873e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00468740  c1fa05                 -sar edx, 5
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (5 /*0x5*/ % 32));
    // 00468743  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00468746  e875590200             -call 0x48e0c0
    cpu.esp -= 4;
    sub_48e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046874b  8b9d88020000           -mov ebx, dword ptr [ebp + 0x288]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(648) /* 0x288 */);
    // 00468751  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00468753  81fb94000000           +cmp ebx, 0x94
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(148 /*0x94*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468759  7c11                   -jl 0x46876c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046876c;
    }
    // 0046875b  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00468760  3d00020000             +cmp eax, 0x200
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468765  7c05                   -jl 0x46876c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046876c;
    }
    // 00468767  2d00040000             -sub eax, 0x400
    (cpu.eax) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
L_0x0046876c:
    // 0046876c  a3c05d5100             -mov dword ptr [0x515dc0], eax
    app->getMemory<x86::reg32>(x86::reg32(5332416) /* 0x515dc0 */) = cpu.eax;
    // 00468771  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00468774  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468775  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468776  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468777  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468778  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468779  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046877a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046877b:
    // 0046877b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046877d  ebb7                   -jmp 0x468736
    goto L_0x00468736;
}

/* align: skip 0x00 */
void Application::sub_468780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468780  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468781  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468782  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468783  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00468786  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00468788  8b15b0f34d00           -mov edx, dword ptr [0x4df3b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
    // 0046878e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00468790  0f850f010000           -jne 0x4688a5
    if (!cpu.flags.zf)
    {
        goto L_0x004688a5;
    }
    // 00468796  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468797  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468798  8b35b08f4c00           -mov esi, dword ptr [0x4c8fb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046879e  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 004687a5  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004687a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004687aa  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 004687af  8990e04c5100           -mov dword ptr [eax + 0x514ce0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328096) /* 0x514ce0 */) = cpu.edx;
    // 004687b5  8998e44c5100           -mov dword ptr [eax + 0x514ce4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328100) /* 0x514ce4 */) = cpu.ebx;
    // 004687bb  bee04c5100             -mov esi, 0x514ce0
    cpu.esi = 5328096 /*0x514ce0*/;
    // 004687c0  8990e84c5100           -mov dword ptr [eax + 0x514ce8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328104) /* 0x514ce8 */) = cpu.edx;
    // 004687c6  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004687c8  8990ec4c5100           -mov dword ptr [eax + 0x514cec], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328108) /* 0x514cec */) = cpu.edx;
    // 004687ce  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004687d2  beb04c5100             -mov esi, 0x514cb0
    cpu.esi = 5328048 /*0x514cb0*/;
    // 004687d7  8b0db08f4c00           -mov ecx, dword ptr [0x4c8fb0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 004687dd  89b0004d5100           -mov dword ptr [eax + 0x514d00], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5328128) /* 0x514d00 */) = cpu.esi;
    // 004687e3  83f977                 +cmp ecx, 0x77
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004687e6  0f8ccf000000           -jl 0x4688bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004688bb;
    }
    // 004687ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004687ee:
    // 004687ee  a3b08f4c00             -mov dword ptr [0x4c8fb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */) = cpu.eax;
    // 004687f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004687f5  0f8ec8000000           -jle 0x4688c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004688c3;
    }
    // 004687fb  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004687fe:
    // 004687fe  68704c5100             -push 0x514c70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5327984 /*0x514c70*/;
    cpu.esp -= 4;
    // 00468803  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046880a  b987000000             -mov ecx, 0x87
    cpu.ecx = 135 /*0x87*/;
    // 0046880f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00468811  bee04c5100             -mov esi, 0x514ce0
    cpu.esi = 5328096 /*0x514ce0*/;
    // 00468816  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468819  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 0046881e  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468820  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00468822  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00468826  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468828  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046882c  e89f000000             -call 0x4688d0
    cpu.esp -= 4;
    sub_4688d0(app, cpu);
    if (cpu.terminate) return;
    // 00468831  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00468835  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468836  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046883a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046883b  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046883f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468843  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468844  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00468849  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0046884e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046884f  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468853  bb61000000             -mov ebx, 0x61
    cpu.ebx = 97 /*0x61*/;
    // 00468858  e81340ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0046885d  68604c5100             -push 0x514c60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5327968 /*0x514c60*/;
    cpu.esp -= 4;
    // 00468862  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468866  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468868  e863000000             -call 0x4688d0
    cpu.esp -= 4;
    sub_4688d0(app, cpu);
    if (cpu.terminate) return;
    // 0046886d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468871  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468872  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468876  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468877  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046887b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046887c  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468880  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468881  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468885  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00468889  e8e23fffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0046888e  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468892  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468893  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468894  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468896  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468898  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046889a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046889b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046889c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046889e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004688a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004688a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004688a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004688a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004688a5:
    // 004688a5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004688a7  e854b5ffff             -call 0x463e00
    cpu.esp -= 4;
    sub_463e00(app, cpu);
    if (cpu.terminate) return;
    // 004688ac  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004688ae  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004688b0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004688b1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004688b2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004688b4  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004688b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004688b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004688b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004688ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004688bb:
    // 004688bb  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004688be  e92bffffff             -jmp 0x4687ee
    goto L_0x004687ee;
L_0x004688c3:
    // 004688c3  be77000000             -mov esi, 0x77
    cpu.esi = 119 /*0x77*/;
    // 004688c8  e931ffffff             -jmp 0x4687fe
    goto L_0x004687fe;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4688d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004688d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004688d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004688d2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004688d5  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004688d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004688d9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004688dd  c7400417000000         -mov dword ptr [eax + 4], 0x17
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 23 /*0x17*/;
    // 004688e4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004688ea  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004688ed  66897008               -mov word ptr [eax + 8], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 004688f1  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004688f3  6689500a               -mov word ptr [eax + 0xa], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 004688f7  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004688f9  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004688fb  6689700c               -mov word ptr [eax + 0xc], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.si;
    // 004688ff  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468901  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00468905  6689500e               -mov word ptr [eax + 0xe], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 00468909  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046890a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046890b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046890d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468910  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468911  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468912  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_468920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468920  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468921  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00468922  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468923  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468924  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468927  8b2d10ec4d00           -mov ebp, dword ptr [0x4dec10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 0046892d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046892e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046892f  b8e0e0e000             -mov eax, 0xe0e0e0
    cpu.eax = 14737632 /*0xe0e0e0*/;
    // 00468934  b93c605100             -mov ecx, 0x51603c
    cpu.ecx = 5333052 /*0x51603c*/;
    // 00468939  e8def70000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 0046893e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00468940  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00468944  b840e04000             -mov eax, 0x40e040
    cpu.eax = 4251712 /*0x40e040*/;
    // 00468949  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046894d  e8caf70000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00468952  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
L_0x00468956:
    // 00468956  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046895a  8b2d10ec4d00           -mov ebp, dword ptr [0x4dec10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 00468960  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00468962:
    // 00468962  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00468964  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00468967  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468969  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046896c  c1e207                 +shl edx, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046896f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00468971  c1f807                 -sar eax, 7
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (7 /*0x7*/ % 32));
    // 00468974  6bc024                 -imul eax, eax, 0x24
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00468977  8b1518ec4d00           -mov edx, dword ptr [0x4dec18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 0046897d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046897f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00468981  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00468984  8986c8904c00           -mov dword ptr [esi + 0x4c90c8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5017800) /* 0x4c90c8 */) = cpu.eax;
    // 0046898a  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046898d  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00468990  8986c8924c00           -mov dword ptr [esi + 0x4c92c8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5018312) /* 0x4c92c8 */) = cpu.eax;
    // 00468996  8d4150                 -lea eax, [ecx + 0x50]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00468999  c7410411000000         -mov dword ptr [ecx + 4], 0x11
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 17 /*0x11*/;
    // 004689a0  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004689a2  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004689a5  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004689a9  43                     -inc ebx
    (cpu.ebx)++;
    // 004689aa  8841f4                 -mov byte ptr [ecx - 0xc], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-12) /* -0xc */) = cpu.al;
    // 004689ad  83fb04                 +cmp ebx, 4
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
    // 004689b0  7cb0                   -jl 0x468962
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468962;
    }
    // 004689b2  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004689b6  47                     -inc edi
    (cpu.edi)++;
    // 004689b7  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004689ba  892d10ec4d00           -mov dword ptr [0x4dec10], ebp
    app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */) = cpu.ebp;
    // 004689c0  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004689c4  81ff80000000           +cmp edi, 0x80
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004689ca  7c8a                   -jl 0x468956
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468956;
    }
    // 004689cc  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004689d0  ba3c605100             -mov edx, 0x51603c
    cpu.edx = 5333052 /*0x51603c*/;
    // 004689d5  c7410411000000         -mov dword ptr [ecx + 4], 0x11
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 17 /*0x11*/;
    // 004689dc  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004689df  884108                 -mov byte ptr [ecx + 8], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 004689e2  b8b0270000             -mov eax, 0x27b0
    cpu.eax = 10160 /*0x27b0*/;
    // 004689e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004689e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004689e9:
    // 004689e9  89903c605100           -mov dword ptr [eax + 0x51603c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5333052) /* 0x51603c */) = cpu.edx;
    // 004689ef  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004689f2  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004689f5  3dec270000             +cmp eax, 0x27ec
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10220 /*0x27ec*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004689fa  75ed                   -jne 0x4689e9
    if (!cpu.flags.zf)
    {
        goto L_0x004689e9;
    }
    // 004689fc  ba3c605100             -mov edx, 0x51603c
    cpu.edx = 5333052 /*0x51603c*/;
    // 00468a01  b8b0270000             -mov eax, 0x27b0
    cpu.eax = 10160 /*0x27b0*/;
    // 00468a06  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00468a09:
    // 00468a09  89903c605100           -mov dword ptr [eax + 0x51603c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5333052) /* 0x51603c */) = cpu.edx;
    // 00468a0f  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00468a12  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00468a15  3dec270000             +cmp eax, 0x27ec
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10220 /*0x27ec*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468a1a  75ed                   -jne 0x468a09
    if (!cpu.flags.zf)
    {
        goto L_0x00468a09;
    }
    // 00468a1c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00468a1e  be3c885100             -mov esi, 0x51883c
    cpu.esi = 5343292 /*0x51883c*/;
    // 00468a23  893d3c885100           -mov dword ptr [0x51883c], edi
    app->getMemory<x86::reg32>(x86::reg32(5343292) /* 0x51883c */) = cpu.edi;
    // 00468a29  893528885100           -mov dword ptr [0x518828], esi
    app->getMemory<x86::reg32>(x86::reg32(5343272) /* 0x518828 */) = cpu.esi;
    // 00468a2f  892d10ec4d00           -mov dword ptr [0x4dec10], ebp
    app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */) = cpu.ebp;
    // 00468a35  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00468a38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468a3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_468a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468a41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468a42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468a43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468a44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468a45  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468a48  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00468a4a  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468a50  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468a57  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468a59  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00468a5e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468a61  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468a63  a18c4c5100             -mov eax, dword ptr [0x514c8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328012) /* 0x514c8c */);
    // 00468a68  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00468a6b  ba8c4c5100             -mov edx, 0x514c8c
    cpu.edx = 5328012 /*0x514c8c*/;
    // 00468a70  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468a73  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468a76  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00468a7b  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468a7e  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468a81  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468a84  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468a87  e804220000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00468a8c  8b157cf34d00           -mov edx, dword ptr [0x4df37c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */);
    // 00468a92  83c205                 -add edx, 5
    (cpu.edx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00468a95  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00468a9c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468a9e  ba804c5100             -mov edx, 0x514c80
    cpu.edx = 5328000 /*0x514c80*/;
    // 00468aa3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468aa6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468aa8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00468aaa  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468aad  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468ab0  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468ab5  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468ab8  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468abb  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468abe  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468ac1  e8ca210000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00468ac6  a1984c5100             -mov eax, dword ptr [0x514c98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328024) /* 0x514c98 */);
    // 00468acb  ba984c5100             -mov edx, 0x514c98
    cpu.edx = 5328024 /*0x514c98*/;
    // 00468ad0  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468ad3  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468ad6  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468adb  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468ade  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468ae1  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468ae4  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468ae7  e8a4210000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00468aec  a1a44c5100             -mov eax, dword ptr [0x514ca4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328036) /* 0x514ca4 */);
    // 00468af1  baa44c5100             -mov edx, 0x514ca4
    cpu.edx = 5328036 /*0x514ca4*/;
    // 00468af6  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468af9  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468afc  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468b01  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468b04  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468b07  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468b0a  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468b0d  e87e210000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00468b12  a1804c5100             -mov eax, dword ptr [0x514c80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328000) /* 0x514c80 */);
    // 00468b17  ba804c5100             -mov edx, 0x514c80
    cpu.edx = 5328000 /*0x514c80*/;
    // 00468b1c  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468b1f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468b22  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468b27  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468b2a  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468b2d  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468b30  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468b33  e858210000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00468b38  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468b3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00468b40  7e48                   -jle 0x468b8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468b8a;
    }
    // 00468b42  4a                     -dec edx
    (cpu.edx)--;
L_0x00468b43:
    // 00468b43  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468b4a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468b4c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468b4e  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468b54  890c85e04c5100         -mov dword ptr [eax*4 + 0x514ce0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.ecx;
    // 00468b5b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00468b5d  7e32                   -jle 0x468b91
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468b91;
    }
    // 00468b5f  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
L_0x00468b62:
    // 00468b62  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468b69  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468b6b  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00468b70  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468b73  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468b75  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468b77  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00468b79  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00468b7d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468b7e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468b7f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00468b81  83c408                 +add esp, 8
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
    // 00468b84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468b89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468b8a:
    // 00468b8a  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00468b8f  ebb2                   -jmp 0x468b43
    goto L_0x00468b43;
L_0x00468b91:
    // 00468b91  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00468b96  ebca                   -jmp 0x468b62
    goto L_0x00468b62;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_468ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468ba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468ba1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468ba2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468ba3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00468ba6  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00468ba8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00468bac  8b0d34f34d00           -mov ecx, dword ptr [0x4df334]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
    // 00468bb2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468bb4  0f84f3010000           -je 0x468dad
    if (cpu.flags.zf)
    {
        goto L_0x00468dad;
    }
    // 00468bba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468bbc  0f8ee1010000           -jle 0x468da3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468da3;
    }
    // 00468bc2  b8f1000000             -mov eax, 0xf1
    cpu.eax = 241 /*0xf1*/;
L_0x00468bc7:
    // 00468bc7  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00468bcb:
    // 00468bcb  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00468bce  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00468bd0  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00468bd3  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00468bd5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00468bd7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00468bd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00468bdc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00468bde  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00468be0  83f80e                 +cmp eax, 0xe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468be3  0f8ecd010000           -jle 0x468db6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468db6;
    }
    // 00468be9  be0e000000             -mov esi, 0xe
    cpu.esi = 14 /*0xe*/;
L_0x00468bee:
    // 00468bee  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468bf4  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468bfb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468bfd  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00468c02  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468c05  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468c09  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468c0b  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00468c12  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00468c16  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468c18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00468c1a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468c1d  8a9698904c00           -mov dl, byte ptr [esi + 0x4c9098]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5017752) /* 0x4c9098 */);
    // 00468c23  8b8888435100           -mov ecx, dword ptr [eax + 0x514388]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5325704) /* 0x514388 */);
    // 00468c29  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00468c2b  39ca                   +cmp edx, ecx
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
    // 00468c2d  7449                   -je 0x468c78
    if (cpu.flags.zf)
    {
        goto L_0x00468c78;
    }
    // 00468c2f  899088435100           -mov dword ptr [eax + 0x514388], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5325704) /* 0x514388 */) = cpu.edx;
    // 00468c35  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00468c3c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468c3e  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00468c45  8b82e83d5100           -mov eax, dword ptr [edx + 0x513de8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5324264) /* 0x513de8 */);
    // 00468c4b  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468c4e  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468c51  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468c55  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468c58  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00468c5a  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468c5d  81c2e83d5100           -add edx, 0x513de8
    (cpu.edx) += x86::reg32(x86::sreg32(5324264 /*0x513de8*/));
    // 00468c63  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468c66  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468c6b  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468c6e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00468c73  e818200000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
L_0x00468c78:
    // 00468c78  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468c7c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00468c83  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468c85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00468c87  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468c8a  8a96a7904c00           -mov dl, byte ptr [esi + 0x4c90a7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5017767) /* 0x4c90a7 */);
    // 00468c90  3b908c435100           +cmp edx, dword ptr [eax + 0x51438c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5325708) /* 0x51438c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468c96  7443                   -je 0x468cdb
    if (cpu.flags.zf)
    {
        goto L_0x00468cdb;
    }
    // 00468c98  89908c435100           -mov dword ptr [eax + 0x51438c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5325708) /* 0x51438c */) = cpu.edx;
    // 00468c9e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00468ca5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468ca7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468caa  8b90e83d5100           -mov edx, dword ptr [eax + 0x513de8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5324264) /* 0x513de8 */);
    // 00468cb0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00468cb3  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00468cb6  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468cba  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00468cbd  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00468cbf  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00468cc2  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468cc5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00468cc7  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468ccc  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468ccf  81c2e83d5100           -add edx, 0x513de8
    (cpu.edx) += x86::reg32(x86::sreg32(5324264 /*0x513de8*/));
    // 00468cd5  47                     -inc edi
    (cpu.edi)++;
    // 00468cd6  e8b51f0000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
L_0x00468cdb:
    // 00468cdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468cdd  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00468ce1  8a86b6904c00           -mov al, byte ptr [esi + 0x4c90b6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5017782) /* 0x4c90b6 */);
    // 00468ce7  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 00468cee  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468cf0  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00468cf3  3b8690435100           +cmp eax, dword ptr [esi + 0x514390]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5325712) /* 0x514390 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468cf9  7442                   -je 0x468d3d
    if (cpu.flags.zf)
    {
        goto L_0x00468d3d;
    }
    // 00468cfb  898690435100           -mov dword ptr [esi + 0x514390], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5325712) /* 0x514390 */) = cpu.eax;
    // 00468d01  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00468d08  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00468d0a  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00468d0d  8b86e83d5100           -mov eax, dword ptr [esi + 0x513de8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5324264) /* 0x513de8 */);
    // 00468d13  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468d17  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468d1a  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468d1d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00468d20  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00468d25  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00468d28  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00468d2b  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468d2d  bae83d5100             -mov edx, 0x513de8
    cpu.edx = 5324264 /*0x513de8*/;
    // 00468d32  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00468d35  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00468d37  47                     -inc edi
    (cpu.edi)++;
    // 00468d38  e8531f0000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
L_0x00468d3d:
    // 00468d3d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468d3f  0f8480000000           -je 0x468dc5
    if (cpu.flags.zf)
    {
        goto L_0x00468dc5;
    }
    // 00468d45  8b0db08f4c00           -mov ecx, dword ptr [0x4c8fb0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468d4b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00468d4d  0f8e7b000000           -jle 0x468dce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468dce;
    }
    // 00468d53  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
L_0x00468d56:
    // 00468d56  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468d5d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468d5f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00468d61  8b35b08f4c00           -mov esi, dword ptr [0x4c8fb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468d67  891c85e04c5100         -mov dword ptr [eax*4 + 0x514ce0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.ebx;
    // 00468d6e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00468d70  7e63                   -jle 0x468dd5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00468dd5;
    }
    // 00468d72  8d56ff                 -lea edx, [esi - 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x00468d75:
    // 00468d75  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468d7c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468d7e  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00468d83  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00468d86  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00468d88  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00468d8a  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00468d8e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00468d92  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468d93  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00468d94:
    // 00468d94  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468d96  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00468d98  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468d99  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468d9a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00468d9c  83c418                 +add esp, 0x18
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
    // 00468d9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468da0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468da1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468da2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468da3:
    // 00468da3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00468da8  e91afeffff             -jmp 0x468bc7
    goto L_0x00468bc7;
L_0x00468dad:
    // 00468dad  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00468db1  e915feffff             -jmp 0x468bcb
    goto L_0x00468bcb;
L_0x00468db6:
    // 00468db6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468db8  0f8d30feffff           -jge 0x468bee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00468bee;
    }
    // 00468dbe  31c6                   +xor esi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00468dc0  e929feffff             -jmp 0x468bee
    goto L_0x00468bee;
L_0x00468dc5:
    // 00468dc5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468dc7  e8543bffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00468dcc  ebc6                   -jmp 0x468d94
    goto L_0x00468d94;
L_0x00468dce:
    // 00468dce  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00468dd3  eb81                   -jmp 0x468d56
    goto L_0x00468d56;
L_0x00468dd5:
    // 00468dd5  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00468dda  eb99                   -jmp 0x468d75
    goto L_0x00468d75;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_468de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468de0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468de1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468de2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468de5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00468de7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468de9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00468deb  e8303bffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00468df0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468df2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468df3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468df4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468df6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00468df9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468dfa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468dfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_468e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00468e01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468e02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00468e03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468e04  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00468e0a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00468e0c  8b1554f34d00           -mov edx, dword ptr [0x4df354]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108564) /* 0x4df354 */);
    // 00468e12  83faff                 +cmp edx, -1
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
    // 00468e15  743b                   -je 0x468e52
    if (cpu.flags.zf)
    {
        goto L_0x00468e52;
    }
    // 00468e17  803d58f34d0000         +cmp byte ptr [0x4df358], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5108568) /* 0x4df358 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00468e1e  7540                   -jne 0x468e60
    if (!cpu.flags.zf)
    {
        goto L_0x00468e60;
    }
    // 00468e20  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00468e25  8db42480000000         -lea esi, [esp + 0x80]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00468e2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00468e2e:
    // 00468e2e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00468e30  e8fbf2fdff             -call 0x448130
    cpu.esp -= 4;
    sub_448130(app, cpu);
    if (cpu.terminate) return;
    // 00468e35  e856000000             -call 0x468e90
    cpu.esp -= 4;
    sub_468e90(app, cpu);
    if (cpu.terminate) return;
L_0x00468e3a:
    // 00468e3a  8db42480000000         -lea esi, [esp + 0x80]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00468e41  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00468e43  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468e44  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468e45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00468e47  81c488000000           +add esp, 0x88
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00468e4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468e51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468e52:
    // 00468e52  8db42480000000         -lea esi, [esp + 0x80]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00468e59  e8c23affff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00468e5e  ebda                   -jmp 0x468e3a
    goto L_0x00468e3a;
L_0x00468e60:
    // 00468e60  6858f34d00             -push 0x4df358
    app->getMemory<x86::reg32>(cpu.esp-4) = 5108568 /*0x4df358*/;
    cpu.esp -= 4;
    // 00468e65  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00468e67  e8c4f2fdff             -call 0x448130
    cpu.esp -= 4;
    sub_448130(app, cpu);
    if (cpu.terminate) return;
    // 00468e6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468e6d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00468e71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00468e72  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00468e77  8db4248c000000         -lea esi, [esp + 0x8c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00468e7e  e85e310100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00468e83  83c40c                 +add esp, 0xc
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
    // 00468e86  a154f34d00             -mov eax, dword ptr [0x4df354]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108564) /* 0x4df354 */);
    // 00468e8b  eba1                   -jmp 0x468e2e
    goto L_0x00468e2e;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_468e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00468e90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00468e91  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00468e92  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00468e95  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00468e99  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00468e9d  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00468ea1  833c957cf34d0001       +cmp dword ptr [edx*4 + 0x4df37c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */ + cpu.edx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468ea9  7512                   -jne 0x468ebd
    if (!cpu.flags.zf)
    {
        goto L_0x00468ebd;
    }
    // 00468eab  83fb08                 +cmp ebx, 8
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
    // 00468eae  0f84b1000000           -je 0x468f65
    if (cpu.flags.zf)
    {
        goto L_0x00468f65;
    }
    // 00468eb4  83fb07                 +cmp ebx, 7
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
    // 00468eb7  0f84a8000000           -je 0x468f65
    if (cpu.flags.zf)
    {
        goto L_0x00468f65;
    }
L_0x00468ebd:
    // 00468ebd  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468ec1  e86a020000             -call 0x469130
    cpu.esp -= 4;
    sub_469130(app, cpu);
    if (cpu.terminate) return;
    // 00468ec6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468ec8  0f8597000000           -jne 0x468f65
    if (!cpu.flags.zf)
    {
        goto L_0x00468f65;
    }
    // 00468ece  833d34f34d0000         +cmp dword ptr [0x4df334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468ed5  0f84a3000000           -je 0x468f7e
    if (cpu.flags.zf)
    {
        goto L_0x00468f7e;
    }
    // 00468edb  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00468ede  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00468ee5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00468ee7  0590475100             -add eax, 0x514790
    (cpu.eax) += x86::reg32(x86::sreg32(5326736 /*0x514790*/));
L_0x00468eec:
    // 00468eec  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468ef0  8b2cd0                 -mov ebp, dword ptr [eax + edx*8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 00468ef3  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00468ef7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00468ef9  7c6a                   -jl 0x468f65
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468f65;
    }
    // 00468efb  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468efe  0f8584000000           -jne 0x468f88
    if (!cpu.flags.zf)
    {
        goto L_0x00468f88;
    }
    // 00468f04  bb62000000             -mov ebx, 0x62
    cpu.ebx = 98 /*0x62*/;
L_0x00468f09:
    // 00468f09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00468f0a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468f0e  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00468f11  0f8cda010000           -jl 0x4690f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004690f1;
    }
    // 00468f17  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00468f1b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00468f1d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00468f1f:
    // 00468f1f  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00468f23  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00468f25  49                     -dec ecx
    (cpu.ecx)--;
    // 00468f26  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00468f28  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00468f2a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00468f2c  49                     -dec ecx
    (cpu.ecx)--;
    // 00468f2d  39cd                   +cmp ebp, ecx
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
    // 00468f2f  7366                   -jae 0x468f97
    if (!cpu.flags.cf)
    {
        goto L_0x00468f97;
    }
    // 00468f31  39de                   +cmp esi, ebx
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
    // 00468f33  7d62                   -jge 0x468f97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00468f97;
    }
    // 00468f35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00468f37  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00468f39  e832020000             -call 0x469170
    cpu.esp -= 4;
    sub_469170(app, cpu);
    if (cpu.terminate) return;
    // 00468f3e  0fb6f8                 -movzx edi, al
    cpu.edi = x86::reg32(cpu.al);
    // 00468f41  8b3cbd20435100         -mov edi, dword ptr [edi*4 + 0x514320]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5325600) /* 0x514320 */ + cpu.edi * 4);
    // 00468f48  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00468f4a  7446                   -je 0x468f92
    if (cpu.flags.zf)
    {
        goto L_0x00468f92;
    }
    // 00468f4c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00468f4e  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00468f51  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468f54  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 00468f57  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00468f5a  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00468f5d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00468f5f  01c6                   +add esi, eax
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
L_0x00468f61:
    // 00468f61  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00468f62  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00468f63  ebba                   -jmp 0x468f1f
    goto L_0x00468f1f;
L_0x00468f65:
    // 00468f65  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468f67  e8b439ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00468f6c  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468f70  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00468f72  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468f73  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00468f74  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00468f78  83c428                 +add esp, 0x28
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
    // 00468f7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468f7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00468f7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00468f7e:
    // 00468f7e  b820475100             -mov eax, 0x514720
    cpu.eax = 5326624 /*0x514720*/;
    // 00468f83  e964ffffff             -jmp 0x468eec
    goto L_0x00468eec;
L_0x00468f88:
    // 00468f88  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00468f8d  e977ffffff             -jmp 0x468f09
    goto L_0x00468f09;
L_0x00468f92:
    // 00468f92  83c60a                 +add esi, 0xa
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00468f95  ebca                   -jmp 0x468f61
    goto L_0x00468f61;
L_0x00468f97:
    // 00468f97  39de                   +cmp esi, ebx
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
    // 00468f99  7c36                   -jl 0x468fd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00468fd1;
    }
    // 00468f9b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00468f9f  8a0428                 -mov al, byte ptr [eax + ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1);
    // 00468fa2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00468fa7  e856300100             -call 0x47c002
    cpu.esp -= 4;
    sub_47c002(app, cpu);
    if (cpu.terminate) return;
    // 00468fac  8b048520435100         -mov eax, dword ptr [eax*4 + 0x514320]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5325600) /* 0x514320 */ + cpu.eax * 4);
    // 00468fb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00468fb5  0f842e010000           -je 0x4690e9
    if (cpu.flags.zf)
    {
        goto L_0x004690e9;
    }
    // 00468fbb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00468fbd  8b5006                 -mov edx, dword ptr [eax + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00468fc0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00468fc3  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 00468fc6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00468fc9  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00468fcc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468fce  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00468fd0:
    // 00468fd0  4d                     -dec ebp
    (cpu.ebp)--;
L_0x00468fd1:
    // 00468fd1  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468fd5  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468fd9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00468fdc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00468fde  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00468fe0  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00468fe2  4d                     -dec ebp
    (cpu.ebp)--;
    // 00468fe3  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
L_0x00468fe5:
    // 00468fe5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00468fe9  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00468fed  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00468ff0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00468ff2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00468ff5  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00468ffb  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00468fff  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00469006  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469008  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 0046900d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469010  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469012  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00469016  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00469018  7c6b                   -jl 0x469085
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469085;
    }
    // 0046901a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046901e  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00469020  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00469024:
    // 00469024  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00469028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046902a  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0046902c  e83f010000             -call 0x469170
    cpu.esp -= 4;
    sub_469170(app, cpu);
    if (cpu.terminate) return;
    // 00469031  0fb6f8                 -movzx edi, al
    cpu.edi = x86::reg32(cpu.al);
    // 00469034  8b3cbd20435100         -mov edi, dword ptr [edi*4 + 0x514320]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5325600) /* 0x514320 */ + cpu.edi * 4);
    // 0046903b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046903d  0f84d3000000           -je 0x469116
    if (cpu.flags.zf)
    {
        goto L_0x00469116;
    }
    // 00469043  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00469045  8b4206                 -mov eax, dword ptr [edx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00469048  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046904b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046904d  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00469050  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469054  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00469057  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00469059  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 0046905c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046905e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469060  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00469065  e8261c0000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 0046906a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0046906c  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046906f  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 00469072  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00469075  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00469077:
    // 00469077  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046907b  49                     -dec ecx
    (cpu.ecx)--;
    // 0046907c  4d                     -dec ebp
    (cpu.ebp)--;
    // 0046907d  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00469081  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00469083  7d9f                   -jge 0x469024
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00469024;
    }
L_0x00469085:
    // 00469085  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046908b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046908d  0f8e8b000000           -jle 0x46911e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046911e;
    }
    // 00469093  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
L_0x00469096:
    // 00469096  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046909d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046909f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004690a1  8b3db08f4c00           -mov edi, dword ptr [0x4c8fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 004690a7  893485e04c5100         -mov dword ptr [eax*4 + 0x514ce0], esi
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.esi;
    // 004690ae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004690b0  7e76                   -jle 0x469128
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469128;
    }
    // 004690b2  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
L_0x004690b5:
    // 004690b5  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004690bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004690be  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 004690c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004690c6  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004690ca  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004690cc  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004690d0  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004690d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004690d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004690d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690d7  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004690db  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004690dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004690de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004690df  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004690e3  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004690e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004690e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004690e9:
    // 004690e9  83ee0a                 +sub esi, 0xa
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004690ec  e9dffeffff             -jmp 0x468fd0
    goto L_0x00468fd0;
L_0x004690f1:
    // 004690f1  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004690f5  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004690fc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004690fe  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00469102  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00469104  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469106  49                     -dec ecx
    (cpu.ecx)--;
    // 00469107  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00469109  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0046910b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046910d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046910e  8d69ff                 -lea ebp, [ecx - 1]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00469111  e9cffeffff             -jmp 0x468fe5
    goto L_0x00468fe5;
L_0x00469116:
    // 00469116  83ee0a                 +sub esi, 0xa
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00469119  e959ffffff             -jmp 0x469077
    goto L_0x00469077;
L_0x0046911e:
    // 0046911e  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00469123  e96effffff             -jmp 0x469096
    goto L_0x00469096;
L_0x00469128:
    // 00469128  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 0046912d  eb86                   -jmp 0x4690b5
    goto L_0x004690b5;
}

/* align: skip 0x00 */
void Application::sub_469130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469133  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469134  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469135  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00469137  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00469139  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046913b  49                     -dec ecx
    (cpu.ecx)--;
    // 0046913c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046913e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00469140  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00469142  49                     -dec ecx
    (cpu.ecx)--;
    // 00469143  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00469145  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00469147  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046914c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046914e  7415                   -je 0x469165
    if (cpu.flags.zf)
    {
        goto L_0x00469165;
    }
    // 00469150  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00469152  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469154  7e0f                   -jle 0x469165
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469165;
    }
    // 00469156  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00469158:
    // 00469158  803a20                 +cmp byte ptr [edx], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046915b  7402                   -je 0x46915f
    if (cpu.flags.zf)
    {
        goto L_0x0046915f;
    }
    // 0046915d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046915f:
    // 0046915f  40                     -inc eax
    (cpu.eax)++;
    // 00469160  42                     -inc edx
    (cpu.edx)++;
    // 00469161  39f0                   +cmp eax, esi
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
    // 00469163  7cf3                   -jl 0x469158
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469158;
    }
L_0x00469165:
    // 00469165  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00469167  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469168  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469169  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046916a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046916b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046916c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_469170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469170  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00469172  3ce4                   +cmp al, 0xe4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(228 /*0xe4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469174  7320                   -jae 0x469196
    if (!cpu.flags.cf)
    {
        goto L_0x00469196;
    }
    // 00469176  3c60                   +cmp al, 0x60
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(96 /*0x60*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469178  0f8386000000           -jae 0x469204
    if (!cpu.flags.cf)
    {
        goto L_0x00469204;
    }
    // 0046917e  3c5d                   +cmp al, 0x5d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469180  0f83b0000000           -jae 0x469236
    if (!cpu.flags.cf)
    {
        goto L_0x00469236;
    }
    // 00469186  3c5b                   +cmp al, 0x5b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(91 /*0x5b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469188  7502                   -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
L_0x0046918a:
    // 0046918a  b028                   -mov al, 0x28
    cpu.al = 40 /*0x28*/;
L_0x0046918c:
    // 0046918c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469191  e96c2e0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469196:
    // 00469196  0f86c8000000           -jbe 0x469264
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469264;
    }
    // 0046919c  3cf1                   +cmp al, 0xf1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(241 /*0xf1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046919e  7314                   -jae 0x4691b4
    if (!cpu.flags.cf)
    {
        goto L_0x004691b4;
    }
    // 004691a0  3ce9                   +cmp al, 0xe9
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(233 /*0xe9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691a2  734a                   -jae 0x4691ee
    if (!cpu.flags.cf)
    {
        goto L_0x004691ee;
    }
    // 004691a4  3ce7                   +cmp al, 0xe7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(231 /*0xe7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691a6  75e4                   -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
    // 004691a8  b0c7                   -mov al, 0xc7
    cpu.al = 199 /*0xc7*/;
    // 004691aa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004691af  e94e2e0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x004691b4:
    // 004691b4  0f86c2000000           -jbe 0x46927c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046927c;
    }
    // 004691ba  3cf6                   +cmp al, 0xf6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(246 /*0xf6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691bc  7310                   -jae 0x4691ce
    if (!cpu.flags.cf)
    {
        goto L_0x004691ce;
    }
    // 004691be  3cf3                   +cmp al, 0xf3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(243 /*0xf3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691c0  75ca                   -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
    // 004691c2  b0d3                   -mov al, 0xd3
    cpu.al = 211 /*0xd3*/;
    // 004691c4  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004691c9  e9342e0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x004691ce:
    // 004691ce  0f86b4000000           -jbe 0x469288
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469288;
    }
    // 004691d4  3cfa                   +cmp al, 0xfa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(250 /*0xfa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691d6  72b4                   -jb 0x46918c
    if (cpu.flags.cf)
    {
        goto L_0x0046918c;
    }
    // 004691d8  0f86b6000000           -jbe 0x469294
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469294;
    }
    // 004691de  3cfc                   +cmp al, 0xfc
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691e0  75aa                   -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
    // 004691e2  b0dc                   -mov al, 0xdc
    cpu.al = 220 /*0xdc*/;
    // 004691e4  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004691e9  e9142e0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x004691ee:
    // 004691ee  0f867c000000           -jbe 0x469270
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469270;
    }
    // 004691f4  3ced                   +cmp al, 0xed
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(237 /*0xed*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004691f6  7594                   -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
    // 004691f8  b0cd                   -mov al, 0xcd
    cpu.al = 205 /*0xcd*/;
    // 004691fa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004691ff  e9fe2d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469204:
    // 00469204  763a                   -jbe 0x469240
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469240;
    }
    // 00469206  3c7c                   +cmp al, 0x7c
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(124 /*0x7c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469208  7312                   -jae 0x46921c
    if (!cpu.flags.cf)
    {
        goto L_0x0046921c;
    }
    // 0046920a  3c7b                   +cmp al, 0x7b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(123 /*0x7b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046920c  0f8478ffffff           -je 0x46918a
    if (cpu.flags.zf)
    {
        goto L_0x0046918a;
    }
    // 00469212  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469217  e9e62d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x0046921c:
    // 0046921c  763a                   -jbe 0x469258
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469258;
    }
    // 0046921e  3c7d                   +cmp al, 0x7d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(125 /*0x7d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469220  762a                   -jbe 0x46924c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046924c;
    }
    // 00469222  3ce1                   +cmp al, 0xe1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(225 /*0xe1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469224  0f8562ffffff           -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
    // 0046922a  b0c1                   -mov al, 0xc1
    cpu.al = 193 /*0xc1*/;
    // 0046922c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469231  e9cc2d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469236:
    // 00469236  7614                   -jbe 0x46924c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046924c;
    }
    // 00469238  3c5e                   +cmp al, 0x5e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046923a  0f854cffffff           -jne 0x46918c
    if (!cpu.flags.zf)
    {
        goto L_0x0046918c;
    }
L_0x00469240:
    // 00469240  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 00469242  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469247  e9b62d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x0046924c:
    // 0046924c  b029                   -mov al, 0x29
    cpu.al = 41 /*0x29*/;
    // 0046924e  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469253  e9aa2d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469258:
    // 00469258  b049                   -mov al, 0x49
    cpu.al = 73 /*0x49*/;
    // 0046925a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0046925f  e99e2d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469264:
    // 00469264  b0c4                   -mov al, 0xc4
    cpu.al = 196 /*0xc4*/;
    // 00469266  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0046926b  e9922d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469270:
    // 00469270  b0c9                   -mov al, 0xc9
    cpu.al = 201 /*0xc9*/;
    // 00469272  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469277  e9862d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x0046927c:
    // 0046927c  b0d1                   -mov al, 0xd1
    cpu.al = 209 /*0xd1*/;
    // 0046927e  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469283  e97a2d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469288:
    // 00469288  b0d6                   -mov al, 0xd6
    cpu.al = 214 /*0xd6*/;
    // 0046928a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0046928f  e96e2d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
L_0x00469294:
    // 00469294  b0da                   -mov al, 0xda
    cpu.al = 218 /*0xda*/;
    // 00469296  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0046929b  e9622d0100             -jmp 0x47c002
    return sub_47c002(app, cpu);
}

/* align: skip  */
void Application::sub_4692a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004692a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004692a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004692a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004692a3  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004692a6  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004692aa  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004692ae  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004692b2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004692b4  83fb0b                 +cmp ebx, 0xb
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004692b7  0f8492010000           -je 0x46944f
    if (cpu.flags.zf)
    {
        goto L_0x0046944f;
    }
    // 004692bd  833c957cf34d0001       +cmp dword ptr [edx*4 + 0x4df37c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */ + cpu.edx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004692c5  7509                   -jne 0x4692d0
    if (!cpu.flags.zf)
    {
        goto L_0x004692d0;
    }
    // 004692c7  83fb02                 +cmp ebx, 2
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
    // 004692ca  0f8e88010000           -jle 0x469458
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469458;
    }
L_0x004692d0:
    // 004692d0  833d34f34d0000         +cmp dword ptr [0x4df334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004692d7  0f8495010000           -je 0x469472
    if (cpu.flags.zf)
    {
        goto L_0x00469472;
    }
    // 004692dd  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004692e1  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004692e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004692e6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004692e9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004692eb  0590475100             -add eax, 0x514790
    (cpu.eax) += x86::reg32(x86::sreg32(5326736 /*0x514790*/));
L_0x004692f0:
    // 004692f0  8d14ed00000000         -lea edx, [ebp*8]
    cpu.edx = x86::reg32(cpu.ebp * 8);
    // 004692f7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004692f9  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004692fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004692fd  0f8c55010000           -jl 0x469458
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469458;
    }
    // 00469303  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00469307  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046930d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00469310  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00469314  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00469318  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046931f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00469321  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469323  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00469328  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046932b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0046932f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469331  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469333  49                     -dec ecx
    (cpu.ecx)--;
    // 00469334  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00469336  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00469338  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0046933a  49                     -dec ecx
    (cpu.ecx)--;
    // 0046933b  8d71ff                 -lea esi, [ecx - 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0046933e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00469342  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00469344  0f8c9c000000           -jl 0x4693e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004693e6;
    }
    // 0046934a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046934c  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00469350  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00469353  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00469356  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0046935a:
    // 0046935a  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046935e  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00469360  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00469362  80fa27                 +cmp dl, 0x27
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(39 /*0x27*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469365  7506                   -jne 0x46936d
    if (!cpu.flags.zf)
    {
        goto L_0x0046936d;
    }
    // 00469367  3a50ff                 +cmp dl, byte ptr [eax - 1]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046936a  7501                   -jne 0x46936d
    if (!cpu.flags.zf)
    {
        goto L_0x0046936d;
    }
    // 0046936c  4e                     -dec esi
    (cpu.esi)--;
L_0x0046936d:
    // 0046936d  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00469371  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00469375  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00469377  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00469379  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046937b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046937d  3a99283c5100           +cmp bl, byte ptr [ecx + 0x513c28]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5323816) /* 0x513c28 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469383  0f84f3000000           -je 0x46947c
    if (cpu.flags.zf)
    {
        goto L_0x0046947c;
    }
    // 00469389  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046938d  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0046938f  8899283c5100           -mov byte ptr [ecx + 0x513c28], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5323816) /* 0x513c28 */) = cpu.bl;
    // 00469395  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469396  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046939a  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046939e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004693a3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004693a5  e876080000             -call 0x469c20
    cpu.esp -= 4;
    sub_469c20(app, cpu);
    if (cpu.terminate) return;
    // 004693aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004693ac  7421                   -je 0x4693cf
    if (cpu.flags.zf)
    {
        goto L_0x004693cf;
    }
    // 004693ae  6b5424100c             -imul edx, dword ptr [esp + 0x10], 0xc
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 004693b3  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004693b7  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004693bb  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 004693c0  81c2f0495100           -add edx, 0x5149f0
    (cpu.edx) += x86::reg32(x86::sreg32(5327344 /*0x5149f0*/));
    // 004693c6  e8c5180000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 004693cb  ff44241c               -inc dword ptr [esp + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))++;
L_0x004693cf:
    // 004693cf  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004693d3  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004693d7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004693d9  4e                     -dec esi
    (cpu.esi)--;
    // 004693da  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004693de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004693e0  0f8d74ffffff           -jge 0x46935a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046935a;
    }
L_0x004693e6:
    // 004693e6  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004693eb  746b                   -je 0x469458
    if (cpu.flags.zf)
    {
        goto L_0x00469458;
    }
    // 004693ed  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 004693f3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004693f5  0f8ea1000000           -jle 0x46949c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046949c;
    }
    // 004693fb  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
L_0x004693fe:
    // 004693fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00469400  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00469403  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469405  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00469407  8b3db08f4c00           -mov edi, dword ptr [0x4c8fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046940d  893485e04c5100         -mov dword ptr [eax*4 + 0x514ce0], esi
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.esi;
    // 00469414  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00469416  0f8e8a000000           -jle 0x4694a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004694a6;
    }
    // 0046941c  8d47ff                 -lea eax, [edi - 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
L_0x0046941f:
    // 0046941f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00469421  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00469424  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469426  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 0046942b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046942e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00469430  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469432  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469436  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046943a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046943b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0046943c:
    // 0046943c  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00469440  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00469442  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469443  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469444  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00469448  83c434                 +add esp, 0x34
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046944b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046944c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046944d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046944e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046944f:
    // 0046944f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00469451  e83afaffff             -call 0x468e90
    cpu.esp -= 4;
    sub_468e90(app, cpu);
    if (cpu.terminate) return;
    // 00469456  ebe4                   -jmp 0x46943c
    goto L_0x0046943c;
L_0x00469458:
    // 00469458  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046945a  e8c134ffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 0046945f  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00469463  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00469465  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469466  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469467  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046946b  83c434                 +add esp, 0x34
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046946e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046946f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469470  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469471  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469472:
    // 00469472  b820475100             -mov eax, 0x514720
    cpu.eax = 5326624 /*0x514720*/;
    // 00469477  e974feffff             -jmp 0x4692f0
    goto L_0x004692f0;
L_0x0046947c:
    // 0046947c  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469480  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00469482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469483  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469487  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046948b  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00469490  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00469492  e889070000             -call 0x469c20
    cpu.esp -= 4;
    sub_469c20(app, cpu);
    if (cpu.terminate) return;
    // 00469497  e933ffffff             -jmp 0x4693cf
    goto L_0x004693cf;
L_0x0046949c:
    // 0046949c  b877000000             -mov eax, 0x77
    cpu.eax = 119 /*0x77*/;
    // 004694a1  e958ffffff             -jmp 0x4693fe
    goto L_0x004693fe;
L_0x004694a6:
    // 004694a6  b877000000             -mov eax, 0x77
    cpu.eax = 119 /*0x77*/;
    // 004694ab  e96fffffff             -jmp 0x46941f
    goto L_0x0046941f;
}

/* align: skip  */
void Application::sub_4694b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004694b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004694b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004694b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004694b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004694b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004694b5  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004694b8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004694ba  8b1534f34d00           -mov edx, dword ptr [0x4df334]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
    // 004694c0  8b3d70f34d00           -mov edi, dword ptr [0x4df370]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
    // 004694c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004694c8  7409                   -je 0x4694d3
    if (cpu.flags.zf)
    {
        goto L_0x004694d3;
    }
    // 004694ca  a174f34d00             -mov eax, dword ptr [0x4df374]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108596) /* 0x4df374 */);
    // 004694cf  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004694d1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004694d3:
    // 004694d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004694d5  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004694d9  e8a2e3fdff             -call 0x447880
    cpu.esp -= 4;
    sub_447880(app, cpu);
    if (cpu.terminate) return;
    // 004694de  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004694e3  e868bdffff             -call 0x465250
    cpu.esp -= 4;
    sub_465250(app, cpu);
    if (cpu.terminate) return;
    // 004694e8  833dc488510000         +cmp dword ptr [0x5188c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5343428) /* 0x5188c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004694ef  753a                   -jne 0x46952b
    if (!cpu.flags.zf)
    {
        goto L_0x0046952b;
    }
    // 004694f1  833d14f64f0002         +cmp dword ptr [0x4ff614], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5240340) /* 0x4ff614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004694f8  7c31                   -jl 0x46952b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046952b;
    }
    // 004694fa  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004694ff  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469503  892dc4885100           -mov dword ptr [0x5188c4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5343428) /* 0x5188c4 */) = cpu.ebp;
    // 00469509  e8c2e8ffff             -call 0x467dd0
    cpu.esp -= 4;
    sub_467dd0(app, cpu);
    if (cpu.terminate) return;
    // 0046950e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469512  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469513  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469517  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469518  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046951c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046951d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469521  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469522  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00469526  e84533ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
L_0x0046952b:
    // 0046952b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046952d  0f84fc000000           -je 0x46962f
    if (cpu.flags.zf)
    {
        goto L_0x0046962f;
    }
    // 00469533  3b3dbc885100           +cmp edi, dword ptr [0x5188bc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469539  0f8524010000           -jne 0x469663
    if (!cpu.flags.zf)
    {
        goto L_0x00469663;
    }
    // 0046953f  833d34f34d0000         +cmp dword ptr [0x4df334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469546  0f85ac000000           -jne 0x4695f8
    if (!cpu.flags.zf)
    {
        goto L_0x004695f8;
    }
    // 0046954c  8b154cf34d00           -mov edx, dword ptr [0x4df34c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108556) /* 0x4df34c */);
    // 00469552  3b15c8885100           +cmp edx, dword ptr [0x5188c8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5343432) /* 0x5188c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469558  0f849a000000           -je 0x4695f8
    if (cpu.flags.zf)
    {
        goto L_0x004695f8;
    }
    // 0046955e  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469562  e889010000             -call 0x4696f0
    cpu.esp -= 4;
    sub_4696f0(app, cpu);
    if (cpu.terminate) return;
    // 00469567  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046956b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046956c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469571  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469575  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00469576  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046957a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046957b  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046957f  e8ec32ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00469584  8b154cf34d00           -mov edx, dword ptr [0x4df34c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108556) /* 0x4df34c */);
    // 0046958a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046958c  7460                   -je 0x4695ee
    if (cpu.flags.zf)
    {
        goto L_0x004695ee;
    }
    // 0046958e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00469590  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00469592  8a92f4010000           -mov dl, byte ptr [edx + 0x1f4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(500) /* 0x1f4 */);
    // 00469598  891dbc885100           -mov dword ptr [0x5188bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.ebx;
    // 0046959e  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004695a1  0f84a7000000           -je 0x46964e
    if (cpu.flags.zf)
    {
        goto L_0x0046964e;
    }
    // 004695a7  8bb0ec010000           -mov esi, dword ptr [eax + 0x1ec]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(492) /* 0x1ec */);
    // 004695ad  bb09000000             -mov ebx, 9
    cpu.ebx = 9 /*0x9*/;
    // 004695b2  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 004695b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004695bb  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004695bd  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004695c1  05a4014e00             -add eax, 0x4e01a4
    (cpu.eax) += x86::reg32(x86::sreg32(5112228 /*0x4e01a4*/));
L_0x004695c6:
    // 004695c6  e8c5f8ffff             -call 0x468e90
    cpu.esp -= 4;
    sub_468e90(app, cpu);
    if (cpu.terminate) return;
    // 004695cb  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004695cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004695d0  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004695d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004695d5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004695d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004695da  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004695de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004695df  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004695e3  e88832ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 004695e8  893dbc885100           -mov dword ptr [0x5188bc], edi
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.edi;
L_0x004695ee:
    // 004695ee  a14cf34d00             -mov eax, dword ptr [0x4df34c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108556) /* 0x4df34c */);
    // 004695f3  a3c8885100             -mov dword ptr [0x5188c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5343432) /* 0x5188c8 */) = cpu.eax;
L_0x004695f8:
    // 004695f8  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004695fc  e83fddfdff             -call 0x447340
    cpu.esp -= 4;
    sub_447340(app, cpu);
    if (cpu.terminate) return;
    // 00469601  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00469605  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469606  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046960a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046960b  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046960f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469610  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469614  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00469615  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469619  e85232ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 0046961e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00469620  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00469622  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469623  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469624  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00469626  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00469629  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046962a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046962b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046962c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046962d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046962e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046962f:
    // 0046962f  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469633  893dbc885100           -mov dword ptr [0x5188bc], edi
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.edi;
    // 00469639  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046963b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046963c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046963d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046963f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00469641  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469642  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469643  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00469645  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00469648  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469649  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046964a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046964b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046964c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046964d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046964e:
    // 0046964e  bb09000000             -mov ebx, 9
    cpu.ebx = 9 /*0x9*/;
    // 00469653  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469657  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00469659  e8720efbff             -call 0x41a4d0
    cpu.esp -= 4;
    sub_41a4d0(app, cpu);
    if (cpu.terminate) return;
    // 0046965e  e963ffffff             -jmp 0x4695c6
    goto L_0x004695c6;
L_0x00469663:
    // 00469663  833d34f34d0000         +cmp dword ptr [0x4df334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046966a  7475                   -je 0x4696e1
    if (cpu.flags.zf)
    {
        goto L_0x004696e1;
    }
    // 0046966c  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469670  e87b030000             -call 0x4699f0
    cpu.esp -= 4;
    sub_4699f0(app, cpu);
    if (cpu.terminate) return;
L_0x00469675:
    // 00469675  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469679  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046967a  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046967e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046967f  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469683  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469684  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00469688  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00469689  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046968d  e8de31ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00469692  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00469696  e8a5dcfdff             -call 0x447340
    cpu.esp -= 4;
    sub_447340(app, cpu);
    if (cpu.terminate) return;
    // 0046969b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046969f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004696a0  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004696a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004696a5  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004696a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004696aa  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004696ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004696af  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004696b3  e8b831ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 004696b8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004696bc  a14cf34d00             -mov eax, dword ptr [0x4df34c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108556) /* 0x4df34c */);
    // 004696c1  893dbc885100           -mov dword ptr [0x5188bc], edi
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.edi;
    // 004696c7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004696c9  a3c8885100             -mov dword ptr [0x5188c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5343432) /* 0x5188c8 */) = cpu.eax;
    // 004696ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004696cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004696d0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004696d2  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004696d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004696d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004696d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004696d8  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004696db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004696dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004696dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004696de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004696df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004696e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004696e1:
    // 004696e1  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004696e5  e856f3ffff             -call 0x468a40
    cpu.esp -= 4;
    sub_468a40(app, cpu);
    if (cpu.terminate) return;
    // 004696ea  eb89                   -jmp 0x469675
    goto L_0x00469675;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4696f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004696f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004696f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004696f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004696f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004696f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004696f5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004696f8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004696fa  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00469700  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00469707  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00469709  b9e04c5100             -mov ecx, 0x514ce0
    cpu.ecx = 5328096 /*0x514ce0*/;
    // 0046970e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469711  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469713  a1a44c5100             -mov eax, dword ptr [0x514ca4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328036) /* 0x514ca4 */);
    // 00469718  baa44c5100             -mov edx, 0x514ca4
    cpu.edx = 5328036 /*0x514ca4*/;
    // 0046971d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00469720  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469723  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469726  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 0046972b  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0046972e  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469731  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00469734  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469737  e854150000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 0046973c  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00469742  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469744  7e48                   -jle 0x46978e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046978e;
    }
    // 00469746  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00469749:
    // 00469749  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00469750  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00469752  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00469754  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046975a  890c85e04c5100         -mov dword ptr [eax*4 + 0x514ce0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.ecx;
    // 00469761  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00469763  7e30                   -jle 0x469795
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469795;
    }
    // 00469765  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
L_0x00469768:
    // 00469768  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046976a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046976d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046976f  b9e04c5100             -mov ecx, 0x514ce0
    cpu.ecx = 5328096 /*0x514ce0*/;
    // 00469774  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469777  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00469779  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046977b  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046977d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00469781  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469782  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469783  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00469785  83c408                 +add esp, 8
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
    // 00469788  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469789  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046978a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046978b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046978c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046978d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046978e:
    // 0046978e  bb77000000             -mov ebx, 0x77
    cpu.ebx = 119 /*0x77*/;
    // 00469793  ebb4                   -jmp 0x469749
    goto L_0x00469749;
L_0x00469795:
    // 00469795  b877000000             -mov eax, 0x77
    cpu.eax = 119 /*0x77*/;
    // 0046979a  ebcc                   -jmp 0x469768
    goto L_0x00469768;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4697a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004697a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004697a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004697a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004697a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004697a4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004697a7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004697a9  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004697ad  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004697b0  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004697b2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004697b4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004697b6  0f848b000000           -je 0x469847
    if (cpu.flags.zf)
    {
        goto L_0x00469847;
    }
    // 004697bc  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004697be:
    // 004697be  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004697c0  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004697c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004697c4  3c7b                   +cmp al, 0x7b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(123 /*0x7b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004697c6  0f8383000000           -jae 0x46984f
    if (!cpu.flags.cf)
    {
        goto L_0x0046984f;
    }
    // 004697cc  3c3a                   +cmp al, 0x3a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004697ce  0f8354010000           -jae 0x469928
    if (!cpu.flags.cf)
    {
        goto L_0x00469928;
    }
    // 004697d4  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004697d6  0f83a4010000           -jae 0x469980
    if (!cpu.flags.cf)
    {
        goto L_0x00469980;
    }
    // 004697dc  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004697de  0f83c1010000           -jae 0x4699a5
    if (!cpu.flags.cf)
    {
        goto L_0x004699a5;
    }
L_0x004697e4:
    // 004697e4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004697e9  e814280100             -call 0x47c002
    cpu.esp -= 4;
    sub_47c002(app, cpu);
    if (cpu.terminate) return;
    // 004697ee  8b3c8520435100         -mov edi, dword ptr [eax*4 + 0x514320]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5325600) /* 0x514320 */ + cpu.eax * 4);
    // 004697f5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004697f7  0f84cf010000           -je 0x4699cc
    if (cpu.flags.zf)
    {
        goto L_0x004699cc;
    }
    // 004697fd  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004697ff  8b5802                 -mov ebx, dword ptr [eax + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00469802  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00469805  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00469809  8b1d805f5100           -mov ebx, dword ptr [0x515f80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */);
    // 0046980f  2b5c2408               -sub ebx, dword ptr [esp + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00469813  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00469817  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 00469819  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046981b  031424                 -add edx, dword ptr [esp]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0046981e  8d1c2a                 -lea ebx, [edx + ebp]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 00469821  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00469823  e8182f0100             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 00469828  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0046982a  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046982d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00469830  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469832  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00469836  40                     -inc eax
    (cpu.eax)++;
    // 00469837  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00469839  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046983b  8a5601                 -mov dl, byte ptr [esi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046983e  46                     -inc esi
    (cpu.esi)++;
    // 0046983f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00469841  0f8577ffffff           -jne 0x4697be
    if (!cpu.flags.zf)
    {
        goto L_0x004697be;
    }
L_0x00469847:
    // 00469847  83c410                 +add esp, 0x10
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
    // 0046984a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046984b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046984c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046984d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046984e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046984f:
    // 0046984f  7704                   -ja 0x469855
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469855;
    }
L_0x00469851:
    // 00469851  b028                   -mov al, 0x28
    cpu.al = 40 /*0x28*/;
    // 00469853  eb8f                   -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469855:
    // 00469855  3ce7                   +cmp al, 0xe7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(231 /*0xe7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469857  7317                   -jae 0x469870
    if (!cpu.flags.cf)
    {
        goto L_0x00469870;
    }
    // 00469859  3cbf                   +cmp al, 0xbf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(191 /*0xbf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046985b  0f837b000000           -jae 0x4698dc
    if (!cpu.flags.cf)
    {
        goto L_0x004698dc;
    }
    // 00469861  3c7d                   +cmp al, 0x7d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(125 /*0x7d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469863  0f83a7000000           -jae 0x469910
    if (!cpu.flags.cf)
    {
        goto L_0x00469910;
    }
    // 00469869  b049                   -mov al, 0x49
    cpu.al = 73 /*0x49*/;
    // 0046986b  e974ffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469870:
    // 00469870  7707                   -ja 0x469879
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469879;
    }
    // 00469872  b0c7                   -mov al, 0xc7
    cpu.al = 199 /*0xc7*/;
    // 00469874  e96bffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469879:
    // 00469879  3cf3                   +cmp al, 0xf3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(243 /*0xf3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046987b  7313                   -jae 0x469890
    if (!cpu.flags.cf)
    {
        goto L_0x00469890;
    }
    // 0046987d  3ced                   +cmp al, 0xed
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(237 /*0xed*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046987f  7343                   -jae 0x4698c4
    if (!cpu.flags.cf)
    {
        goto L_0x004698c4;
    }
    // 00469881  3ce9                   +cmp al, 0xe9
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(233 /*0xe9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469883  0f855bffffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 00469889  b0c9                   -mov al, 0xc9
    cpu.al = 201 /*0xc9*/;
    // 0046988b  e954ffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469890:
    // 00469890  7707                   -ja 0x469899
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469899;
    }
    // 00469892  b0d3                   -mov al, 0xd3
    cpu.al = 211 /*0xd3*/;
    // 00469894  e94bffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469899:
    // 00469899  3cfa                   +cmp al, 0xfa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(250 /*0xfa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046989b  730f                   -jae 0x4698ac
    if (!cpu.flags.cf)
    {
        goto L_0x004698ac;
    }
    // 0046989d  3cf6                   +cmp al, 0xf6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(246 /*0xf6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046989f  0f853fffffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 004698a5  b0d6                   -mov al, 0xd6
    cpu.al = 214 /*0xd6*/;
    // 004698a7  e938ffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698ac:
    // 004698ac  7707                   -ja 0x4698b5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004698b5;
    }
    // 004698ae  b0da                   -mov al, 0xda
    cpu.al = 218 /*0xda*/;
    // 004698b0  e92fffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698b5:
    // 004698b5  3cfc                   +cmp al, 0xfc
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004698b7  0f8527ffffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 004698bd  b0dc                   -mov al, 0xdc
    cpu.al = 220 /*0xdc*/;
    // 004698bf  e920ffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698c4:
    // 004698c4  7707                   -ja 0x4698cd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004698cd;
    }
    // 004698c6  b0cd                   -mov al, 0xcd
    cpu.al = 205 /*0xcd*/;
    // 004698c8  e917ffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698cd:
    // 004698cd  3cf1                   +cmp al, 0xf1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(241 /*0xf1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004698cf  0f850fffffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 004698d5  b0d1                   -mov al, 0xd1
    cpu.al = 209 /*0xd1*/;
    // 004698d7  e908ffffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698dc:
    // 004698dc  7707                   -ja 0x4698e5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004698e5;
    }
    // 004698de  b0a8                   -mov al, 0xa8
    cpu.al = 168 /*0xa8*/;
    // 004698e0  e9fffeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698e5:
    // 004698e5  3ce4                   +cmp al, 0xe4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(228 /*0xe4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004698e7  730f                   -jae 0x4698f8
    if (!cpu.flags.cf)
    {
        goto L_0x004698f8;
    }
    // 004698e9  3ce1                   +cmp al, 0xe1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(225 /*0xe1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004698eb  0f85f3feffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 004698f1  b0c1                   -mov al, 0xc1
    cpu.al = 193 /*0xc1*/;
    // 004698f3  e9ecfeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004698f8:
    // 004698f8  7707                   -ja 0x469901
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469901;
    }
    // 004698fa  b0c4                   -mov al, 0xc4
    cpu.al = 196 /*0xc4*/;
    // 004698fc  e9e3feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469901:
    // 00469901  3ce5                   +cmp al, 0xe5
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(229 /*0xe5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469903  0f85dbfeffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 00469909  b0c5                   -mov al, 0xc5
    cpu.al = 197 /*0xc5*/;
    // 0046990b  e9d4feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469910:
    // 00469910  7707                   -ja 0x469919
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469919;
    }
L_0x00469912:
    // 00469912  b029                   -mov al, 0x29
    cpu.al = 41 /*0x29*/;
    // 00469914  e9cbfeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469919:
    // 00469919  3ca1                   +cmp al, 0xa1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(161 /*0xa1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046991b  0f85c3feffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 00469921  b0ad                   -mov al, 0xad
    cpu.al = 173 /*0xad*/;
    // 00469923  e9bcfeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469928:
    // 00469928  770a                   -ja 0x469934
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469934;
    }
L_0x0046992a:
    // 0046992a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0046992f  e9b0feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469934:
    // 00469934  3c5d                   +cmp al, 0x5d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469936  730d                   -jae 0x469945
    if (!cpu.flags.cf)
    {
        goto L_0x00469945;
    }
    // 00469938  3c3d                   +cmp al, 0x3d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046993a  732b                   -jae 0x469967
    if (!cpu.flags.cf)
    {
        goto L_0x00469967;
    }
    // 0046993c  3c3b                   +cmp al, 0x3b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(59 /*0x3b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046993e  74ea                   -je 0x46992a
    if (cpu.flags.zf)
    {
        goto L_0x0046992a;
    }
    // 00469940  e99ffeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469945:
    // 00469945  76cb                   -jbe 0x469912
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469912;
    }
    // 00469947  3c5f                   +cmp al, 0x5f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(95 /*0x5f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469949  7307                   -jae 0x469952
    if (!cpu.flags.cf)
    {
        goto L_0x00469952;
    }
L_0x0046994b:
    // 0046994b  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 0046994d  e992feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469952:
    // 00469952  770a                   -ja 0x46995e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046995e;
    }
    // 00469954  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00469959  e986feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x0046995e:
    // 0046995e  3c60                   +cmp al, 0x60
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(96 /*0x60*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469960  74e9                   -je 0x46994b
    if (cpu.flags.zf)
    {
        goto L_0x0046994b;
    }
    // 00469962  e97dfeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469967:
    // 00469967  770a                   -ja 0x469973
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469973;
    }
L_0x00469969:
    // 00469969  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0046996e  e971feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469973:
    // 00469973  3c5b                   +cmp al, 0x5b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(91 /*0x5b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469975  0f84d6feffff           -je 0x469851
    if (cpu.flags.zf)
    {
        goto L_0x00469851;
    }
    // 0046997b  e964feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x00469980:
    // 00469980  770a                   -ja 0x46998c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046998c;
    }
    // 00469982  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00469987  e958feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x0046998c:
    // 0046998c  3c2d                   +cmp al, 0x2d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046998e  730a                   -jae 0x46999a
    if (!cpu.flags.cf)
    {
        goto L_0x0046999a;
    }
L_0x00469990:
    // 00469990  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 00469995  e94afeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x0046999a:
    // 0046999a  76cd                   -jbe 0x469969
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00469969;
    }
    // 0046999c  3c2e                   +cmp al, 0x2e
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
    // 0046999e  74f0                   -je 0x469990
    if (cpu.flags.zf)
    {
        goto L_0x00469990;
    }
    // 004699a0  e93ffeffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004699a5:
    // 004699a5  7716                   -ja 0x4699bd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004699bd;
    }
    // 004699a7  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004699ab  b020                   -mov al, 0x20
    cpu.al = 32 /*0x20*/;
    // 004699ad  8b1d805f5100           -mov ebx, dword ptr [0x515f80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */);
    // 004699b3  83c50f                 -add ebp, 0xf
    (cpu.ebp) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004699b6  29d9                   +sub ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004699b8  e927feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004699bd:
    // 004699bd  3c27                   +cmp al, 0x27
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(39 /*0x27*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004699bf  0f851ffeffff           -jne 0x4697e4
    if (!cpu.flags.zf)
    {
        goto L_0x004697e4;
    }
    // 004699c5  b02c                   -mov al, 0x2c
    cpu.al = 44 /*0x2c*/;
    // 004699c7  e918feffff             -jmp 0x4697e4
    goto L_0x004697e4;
L_0x004699cc:
    // 004699cc  030d805f5100           -add ecx, dword ptr [0x515f80]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */)));
    // 004699d2  8a5601                 -mov dl, byte ptr [esi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004699d5  46                     -inc esi
    (cpu.esi)++;
    // 004699d6  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004699d8  0f85e0fdffff           -jne 0x4697be
    if (!cpu.flags.zf)
    {
        goto L_0x004697be;
    }
    // 004699de  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004699e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004699e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004699e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004699e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004699e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4699f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004699f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004699f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004699f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004699f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004699f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004699f5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004699f8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004699fa  8b15b08f4c00           -mov edx, dword ptr [0x4c8fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00469a00  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00469a07  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469a09  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00469a0e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469a11  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469a13  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00469a16  833d70f34d0000         +cmp dword ptr [0x4df370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469a1d  0f8527010000           -jne 0x469b4a
    if (!cpu.flags.zf)
    {
        goto L_0x00469b4a;
    }
L_0x00469a23:
    // 00469a23  833d74f34d0000         +cmp dword ptr [0x4df374], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108596) /* 0x4df374 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469a2a  0f84be000000           -je 0x469aee
    if (cpu.flags.zf)
    {
        goto L_0x00469aee;
    }
    // 00469a30  8b1580f34d00           -mov edx, dword ptr [0x4df380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108608) /* 0x4df380 */);
    // 00469a36  83c205                 -add edx, 5
    (cpu.edx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00469a39  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00469a40  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00469a42  ba804c5100             -mov edx, 0x514c80
    cpu.edx = 5328000 /*0x514c80*/;
    // 00469a47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469a4a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469a4c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00469a4e  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469a51  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469a54  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00469a59  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00469a5c  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469a5f  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00469a62  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469a65  81c1f1000000           -add ecx, 0xf1
    (cpu.ecx) += x86::reg32(x86::sreg32(241 /*0xf1*/));
    // 00469a6b  e820120000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469a70  a1804c5100             -mov eax, dword ptr [0x514c80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328000) /* 0x514c80 */);
    // 00469a75  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469a78  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469a7b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00469a7e  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00469a83  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00469a86  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469a89  8d8af1000000           -lea ecx, [edx + 0xf1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(241) /* 0xf1 */);
    // 00469a8f  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469a92  ba804c5100             -mov edx, 0x514c80
    cpu.edx = 5328000 /*0x514c80*/;
    // 00469a97  e8f4110000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469a9c  a18c4c5100             -mov eax, dword ptr [0x514c8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328012) /* 0x514c8c */);
    // 00469aa1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469aa4  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469aa7  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00469aaa  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00469aaf  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00469ab2  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469ab5  8d8af1000000           -lea ecx, [edx + 0xf1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(241) /* 0xf1 */);
    // 00469abb  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469abe  ba8c4c5100             -mov edx, 0x514c8c
    cpu.edx = 5328012 /*0x514c8c*/;
    // 00469ac3  e8c8110000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469ac8  a1984c5100             -mov eax, dword ptr [0x514c98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328024) /* 0x514c98 */);
    // 00469acd  ba984c5100             -mov edx, 0x514c98
    cpu.edx = 5328024 /*0x514c98*/;
    // 00469ad2  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469ad5  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469ad8  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00469add  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00469ae0  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469ae3  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00469ae6  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469ae9  e8a2110000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
L_0x00469aee:
    // 00469aee  8b1db08f4c00           -mov ebx, dword ptr [0x4c8fb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00469af4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00469af6  0f8e0a010000           -jle 0x469c06
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469c06;
    }
    // 00469afc  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
L_0x00469aff:
    // 00469aff  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00469b06  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469b08  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00469b0a  8b3db08f4c00           -mov edi, dword ptr [0x4c8fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 00469b10  893485e04c5100         -mov dword ptr [eax*4 + 0x514ce0], esi
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.esi;
    // 00469b17  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00469b19  0f8ef1000000           -jle 0x469c10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469c10;
    }
    // 00469b1f  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
L_0x00469b22:
    // 00469b22  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00469b29  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00469b2b  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 00469b30  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469b33  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00469b35  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469b37  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00469b39  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00469b3d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469b3e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00469b3f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00469b41  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00469b44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469b45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469b46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469b47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469b48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469b49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469b4a:
    // 00469b4a  8b157cf34d00           -mov edx, dword ptr [0x4df37c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */);
    // 00469b50  83c205                 -add edx, 5
    (cpu.edx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00469b53  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00469b5a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00469b5c  ba804c5100             -mov edx, 0x514c80
    cpu.edx = 5328000 /*0x514c80*/;
    // 00469b61  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00469b64  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00469b66  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00469b68  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469b6b  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469b6e  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00469b73  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00469b76  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469b79  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00469b7c  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469b7f  41                     -inc ecx
    (cpu.ecx)++;
    // 00469b80  e80b110000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469b85  a1804c5100             -mov eax, dword ptr [0x514c80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328000) /* 0x514c80 */);
    // 00469b8a  ba804c5100             -mov edx, 0x514c80
    cpu.edx = 5328000 /*0x514c80*/;
    // 00469b8f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469b92  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469b95  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00469b9a  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00469b9d  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469ba0  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00469ba3  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469ba6  41                     -inc ecx
    (cpu.ecx)++;
    // 00469ba7  e8e4100000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469bac  a18c4c5100             -mov eax, dword ptr [0x514c8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328012) /* 0x514c8c */);
    // 00469bb1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469bb4  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469bb7  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00469bba  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00469bbf  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00469bc2  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469bc5  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00469bc8  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00469bcb  ba8c4c5100             -mov edx, 0x514c8c
    cpu.edx = 5328012 /*0x514c8c*/;
    // 00469bd0  e8bb100000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469bd5  a1984c5100             -mov eax, dword ptr [0x514c98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5328024) /* 0x514c98 */);
    // 00469bda  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469bdd  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00469be0  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00469be3  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00469be8  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00469beb  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00469bee  8d8a10ffffff           -lea ecx, [edx - 0xf0]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-240) /* -0xf0 */);
    // 00469bf4  c1fb14                 +sar ebx, 0x14
    {
        x86::reg8 tmp = 20 /*0x14*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00469bf7  ba984c5100             -mov edx, 0x514c98
    cpu.edx = 5328024 /*0x514c98*/;
    // 00469bfc  e88f100000             -call 0x46ac90
    cpu.esp -= 4;
    sub_46ac90(app, cpu);
    if (cpu.terminate) return;
    // 00469c01  e91dfeffff             -jmp 0x469a23
    goto L_0x00469a23;
L_0x00469c06:
    // 00469c06  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00469c0b  e9effeffff             -jmp 0x469aff
    goto L_0x00469aff;
L_0x00469c10:
    // 00469c10  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 00469c15  e908ffffff             -jmp 0x469b22
    goto L_0x00469b22;
}

}
