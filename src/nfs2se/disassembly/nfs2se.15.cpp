#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473231  833801                 +cmp dword ptr [eax], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473234  7528                   -jne 0x47325e
    if (!cpu.flags.zf)
    {
        goto L_0x0047325e;
    }
    // 00473236  8b506c                 -mov edx, dword ptr [eax + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 00473239  8915d8fa4d00           -mov dword ptr [0x4dfad8], edx
    app->getMemory<x86::reg32>(x86::reg32(5110488) /* 0x4dfad8 */) = cpu.edx;
    // 0047323f  83c246                 -add edx, 0x46
    (cpu.edx) += x86::reg32(x86::sreg32(70 /*0x46*/));
    // 00473242  8915d0fa4d00           -mov dword ptr [0x4dfad0], edx
    app->getMemory<x86::reg32>(x86::reg32(5110480) /* 0x4dfad0 */) = cpu.edx;
    // 00473248  8b5068                 -mov edx, dword ptr [eax + 0x68]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0047324b  8915ccfa4d00           -mov dword ptr [0x4dfacc], edx
    app->getMemory<x86::reg32>(x86::reg32(5110476) /* 0x4dfacc */) = cpu.edx;
    // 00473251  8d8296000000           -lea eax, [edx + 0x96]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(150) /* 0x96 */);
    // 00473257  a3c8fa4d00             -mov dword ptr [0x4dfac8], eax
    app->getMemory<x86::reg32>(x86::reg32(5110472) /* 0x4dfac8 */) = cpu.eax;
    // 0047325c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047325d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047325e:
    // 0047325e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047325f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473260  68d0fa4d00             -push 0x4dfad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5110480 /*0x4dfad0*/;
    cpu.esp -= 4;
    // 00473265  b9c8fa4d00             -mov ecx, 0x4dfac8
    cpu.ecx = 5110472 /*0x4dfac8*/;
    // 0047326a  bbd8fa4d00             -mov ebx, 0x4dfad8
    cpu.ebx = 5110488 /*0x4dfad8*/;
    // 0047326f  baccfa4d00             -mov edx, 0x4dfacc
    cpu.edx = 5110476 /*0x4dfacc*/;
    // 00473274  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00473277  e8d4d8ffff             -call 0x470b50
    cpu.esp -= 4;
    sub_470b50(app, cpu);
    if (cpu.terminate) return;
    // 0047327c  a1d8fa4d00             -mov eax, dword ptr [0x4dfad8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110488) /* 0x4dfad8 */);
    // 00473281  0105d0fa4d00           -add dword ptr [0x4dfad0], eax
    (app->getMemory<x86::reg32>(x86::reg32(5110480) /* 0x4dfad0 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473287  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473288  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473289  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047328a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473290  80356cb8510001         -xor byte ptr [0x51b86c], 1
    app->getMemory<x86::reg8>(x86::reg32(5355628) /* 0x51b86c */) ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00473297  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4732a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004732a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004732a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004732a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004732a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004732a4  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004732a7  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004732ab  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004732af  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004732b1  8d7c2444               -lea edi, [esp + 0x44]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004732b5  be602a4700             -mov esi, 0x472a60
    cpu.esi = 4663904 /*0x472a60*/;
    // 004732ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004732bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004732bc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004732be  7e20                   -jle 0x4732e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004732e0;
    }
    // 004732c0  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004732c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004732c5:
    // 004732c5  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004732c8  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004732cb  890c14                 -mov dword ptr [esp + edx], ecx
    app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 1) = cpu.ecx;
    // 004732ce  8b0d68b85100           -mov ecx, dword ptr [0x51b868]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355624) /* 0x51b868 */);
    // 004732d4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004732d7  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004732da  39da                   +cmp edx, ebx
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
    // 004732dc  7ce7                   -jl 0x4732c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004732c5;
    }
    // 004732de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004732e0:
    // 004732e0  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004732e4  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004732e8  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004732ec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004732ee  e81d6cfdff             -call 0x449f10
    cpu.esp -= 4;
    sub_449f10(app, cpu);
    if (cpu.terminate) return;
    // 004732f3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004732f5  7e1d                   -jle 0x473314
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473314;
    }
    // 004732f7  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004732fb  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 00473302  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00473304:
    // 00473304  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473307  8b0c04                 -mov ecx, dword ptr [esp + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 0047330a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047330d  894afc                 -mov dword ptr [edx - 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00473310  39d8                   +cmp eax, ebx
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
    // 00473312  7cf0                   -jl 0x473304
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473304;
    }
L_0x00473314:
    // 00473314  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00473317  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473318  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473319  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047331a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047331b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473320  a1d4fa4d00             -mov eax, dword ptr [0x4dfad4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110484) /* 0x4dfad4 */);
    // 00473325  e862730000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047332a  a1dcfa4d00             -mov eax, dword ptr [0x4dfadc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110492) /* 0x4dfadc */);
    // 0047332f  e958730000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473343  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473344  ba94e74b00             -mov edx, 0x4be794
    cpu.edx = 4974484 /*0x4be794*/;
    // 00473349  b9c5000000             -mov ecx, 0xc5
    cpu.ecx = 197 /*0xc5*/;
    // 0047334e  bec7000000             -mov esi, 0xc7
    cpu.esi = 199 /*0xc7*/;
    // 00473353  a170f54d00             -mov eax, dword ptr [0x4df570]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109104) /* 0x4df570 */);
    // 00473358  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047335a  a36cb85100             -mov dword ptr [0x51b86c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355628) /* 0x51b86c */) = cpu.eax;
    // 0047335f  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00473365  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 0047336a  b8b0e74b00             -mov eax, 0x4be7b0
    cpu.eax = 4974512 /*0x4be7b0*/;
    // 0047336f  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 00473375  e8ae6e0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0047337a  bb94e74b00             -mov ebx, 0x4be794
    cpu.ebx = 4974484 /*0x4be794*/;
    // 0047337f  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00473384  a3d4fa4d00             -mov dword ptr [0x4dfad4], eax
    app->getMemory<x86::reg32>(x86::reg32(5110484) /* 0x4dfad4 */) = cpu.eax;
    // 00473389  b8c0e74b00             -mov eax, 0x4be7c0
    cpu.eax = 4974528 /*0x4be7c0*/;
    // 0047338e  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00473394  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473396  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 0047339c  e8876e0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 004733a1  a3dcfa4d00             -mov dword ptr [0x4dfadc], eax
    app->getMemory<x86::reg32>(x86::reg32(5110492) /* 0x4dfadc */) = cpu.eax;
    // 004733a6  e805000000             -call 0x4733b0
    cpu.esp -= 4;
    sub_4733b0(app, cpu);
    if (cpu.terminate) return;
    // 004733ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004733af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4733b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004733b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004733b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004733b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004733b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004733b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004733b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004733b7  89154cb85100           -mov dword ptr [0x51b84c], edx
    app->getMemory<x86::reg32>(x86::reg32(5355596) /* 0x51b84c */) = cpu.edx;
    // 004733bd  8b1574b85100           -mov edx, dword ptr [0x51b874]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355636) /* 0x51b874 */);
    // 004733c3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004733ca  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004733cc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004733ce  8b1560b85100           -mov edx, dword ptr [0x51b860]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355616) /* 0x51b860 */);
    // 004733d4  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004733d6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004733d8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004733da  890d54b85100           -mov dword ptr [0x51b854], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355604) /* 0x51b854 */) = cpu.ecx;
    // 004733e0  891550b85100           -mov dword ptr [0x51b850], edx
    app->getMemory<x86::reg32>(x86::reg32(5355600) /* 0x51b850 */) = cpu.edx;
    // 004733e6  8b1560b85100           -mov edx, dword ptr [0x51b860]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355616) /* 0x51b860 */);
    // 004733ec  890db0b75100           -mov dword ptr [0x51b7b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355440) /* 0x51b7b0 */) = cpu.ecx;
    // 004733f2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004733f4  890db8b75100           -mov dword ptr [0x51b7b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355448) /* 0x51b7b8 */) = cpu.ecx;
    // 004733fa  8915b4b75100           -mov dword ptr [0x51b7b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5355444) /* 0x51b7b4 */) = cpu.edx;
L_0x00473400:
    // 00473400  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00473402  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473404  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473407  c1e204                 +shl edx, 4
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
    // 0047340a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047340c  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047340f  8b35c4b75100           -mov esi, dword ptr [0x51b7c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355460) /* 0x51b7c4 */);
    // 00473415  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473417  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473419  8b1570b85100           -mov edx, dword ptr [0x51b870]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355632) /* 0x51b870 */);
    // 0047341f  e8fcc50100             -call 0x48fa20
    cpu.esp -= 4;
    sub_48fa20(app, cpu);
    if (cpu.terminate) return;
    // 00473424  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00473426  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00473429  c1e810                 +shr eax, 0x10
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
    // 0047342c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047342e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473430  a1dcfa4d00             -mov eax, dword ptr [0x4dfadc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110492) /* 0x4dfadc */);
    // 00473435  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00473438  8b1560b85100           -mov edx, dword ptr [0x51b860]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355616) /* 0x51b860 */);
    // 0047343e  89540304               -mov dword ptr [ebx + eax + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.edx;
    // 00473442  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473444  8b1570b85100           -mov edx, dword ptr [0x51b870]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355632) /* 0x51b870 */);
    // 0047344a  e841c60100             -call 0x48fa90
    cpu.esp -= 4;
    sub_48fa90(app, cpu);
    if (cpu.terminate) return;
    // 0047344f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00473451  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00473454  c1e810                 +shr eax, 0x10
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
    // 00473457  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473459  8b35dcfa4d00           -mov esi, dword ptr [0x4dfadc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5110492) /* 0x4dfadc */);
    // 0047345f  89441e08               -mov dword ptr [esi + ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1) = cpu.eax;
    // 00473463  a1d4fa4d00             -mov eax, dword ptr [0x4dfad4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110484) /* 0x4dfad4 */);
    // 00473468  8b141e                 -mov edx, dword ptr [esi + ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 1);
    // 0047346b  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 0047346e  8b3d74b85100           -mov edi, dword ptr [0x51b874]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355636) /* 0x51b874 */);
    // 00473474  8b541e04               -mov edx, dword ptr [esi + ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebx * 1);
    // 00473478  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047347b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047347d  895403f8               -mov dword ptr [ebx + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 00473481  8b541efc               -mov edx, dword ptr [esi + ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ebx * 1);
    // 00473485  81c100000100           -add ecx, 0x10000
    (cpu.ecx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0047348b  895403fc               -mov dword ptr [ebx + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 0047348f  81f900002000           +cmp ecx, 0x200000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2097152 /*0x200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473495  0f8565ffffff           -jne 0x473400
    if (!cpu.flags.zf)
    {
        goto L_0x00473400;
    }
    // 0047349b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047349c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047349d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047349e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047349f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4734b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004734b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004734b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004734b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004734b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004734b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004734b7  a0c2b75100             -mov al, byte ptr [0x51b7c2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355458) /* 0x51b7c2 */);
    // 004734bc  8a15c1b75100           -mov dl, byte ptr [0x51b7c1]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5355457) /* 0x51b7c1 */);
    // 004734c2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004734c5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004734c8  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004734ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004734cc  a0c0b75100             -mov al, byte ptr [0x51b7c0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355456) /* 0x51b7c0 */);
    // 004734d1  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004734d3  e8444c0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 004734d8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004734da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004734dc  a05ab85100             -mov al, byte ptr [0x51b85a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355610) /* 0x51b85a */);
    // 004734e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004734e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004734e5  a059b85100             -mov al, byte ptr [0x51b859]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355609) /* 0x51b859 */);
    // 004734ea  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004734ed  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004734f0  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004734f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004734f4  a058b85100             -mov al, byte ptr [0x51b858]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355608) /* 0x51b858 */);
    // 004734f9  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004734fb  e81c4c0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00473500  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473502  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473504  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00473509  e80e4c0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 0047350e  891dccb75100           -mov dword ptr [0x51b7cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355468) /* 0x51b7cc */) = cpu.ebx;
    // 00473514  880df0b75100           -mov byte ptr [0x51b7f0], cl
    app->getMemory<x86::reg8>(x86::reg32(5355504) /* 0x51b7f0 */) = cpu.cl;
    // 0047351a  891df8b75100           -mov dword ptr [0x51b7f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355512) /* 0x51b7f8 */) = cpu.ebx;
    // 00473520  88151cb85100           -mov byte ptr [0x51b81c], dl
    app->getMemory<x86::reg8>(x86::reg32(5355548) /* 0x51b81c */) = cpu.dl;
    // 00473526  891d24b85100           -mov dword ptr [0x51b824], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355556) /* 0x51b824 */) = cpu.ebx;
    // 0047352c  a248b85100             -mov byte ptr [0x51b848], al
    app->getMemory<x86::reg8>(x86::reg32(5355592) /* 0x51b848 */) = cpu.al;
    // 00473531  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473532  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473533  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473534  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473540  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473541  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473543  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00473545:
    // 00473545  899090b75100           -mov dword ptr [eax + 0x51b790], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5355408) /* 0x51b790 */) = cpu.edx;
    // 0047354b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047354e  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473551  83f820                 +cmp eax, 0x20
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
    // 00473554  75ef                   -jne 0x473545
    if (!cpu.flags.zf)
    {
        goto L_0x00473545;
    }
    // 00473556  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473557  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473563  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473564  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473565  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047356b  8b153cf54d00           -mov edx, dword ptr [0x4df53c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 00473571  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473572  8b0d9c074e00           -mov ecx, dword ptr [0x4e079c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113756) /* 0x4e079c */);
    // 00473578  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473579  6884e74b00             -push 0x4be784
    app->getMemory<x86::reg32>(cpu.esp-4) = 4974468 /*0x4be784*/;
    cpu.esp -= 4;
    // 0047357e  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473582  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473583  e8598a0000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00473588  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047358b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047358d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047358f  e8cc920000             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 00473594  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00473596  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0047359d  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004735a4  e8b7a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004735a9  a3bcb75100             -mov dword ptr [0x51b7bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5355452) /* 0x51b7bc */) = cpu.eax;
    // 004735ae  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004735b5  e8a6a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004735ba  a364b85100             -mov dword ptr [0x51b864], eax
    app->getMemory<x86::reg32>(x86::reg32(5355620) /* 0x51b864 */) = cpu.eax;
    // 004735bf  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004735c6  e895a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004735cb  a370b85100             -mov dword ptr [0x51b870], eax
    app->getMemory<x86::reg32>(x86::reg32(5355632) /* 0x51b870 */) = cpu.eax;
    // 004735d0  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004735d7  e884a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004735dc  a3c4b75100             -mov dword ptr [0x51b7c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5355460) /* 0x51b7c4 */) = cpu.eax;
    // 004735e1  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004735e8  e873a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004735ed  a368b85100             -mov dword ptr [0x51b868], eax
    app->getMemory<x86::reg32>(x86::reg32(5355624) /* 0x51b868 */) = cpu.eax;
    // 004735f2  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004735f9  e862a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004735fe  a360b85100             -mov dword ptr [0x51b860], eax
    app->getMemory<x86::reg32>(x86::reg32(5355616) /* 0x51b860 */) = cpu.eax;
    // 00473603  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047360a  e851a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 0047360f  a374b85100             -mov dword ptr [0x51b874], eax
    app->getMemory<x86::reg32>(x86::reg32(5355636) /* 0x51b874 */) = cpu.eax;
    // 00473614  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047361b  e840a7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473620  a35cb85100             -mov dword ptr [0x51b85c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355612) /* 0x51b85c */) = cpu.eax;
    // 00473625  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047362c  e82fa7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473631  a2c2b75100             -mov byte ptr [0x51b7c2], al
    app->getMemory<x86::reg8>(x86::reg32(5355458) /* 0x51b7c2 */) = cpu.al;
    // 00473636  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047363d  e81ea7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473642  a2c1b75100             -mov byte ptr [0x51b7c1], al
    app->getMemory<x86::reg8>(x86::reg32(5355457) /* 0x51b7c1 */) = cpu.al;
    // 00473647  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047364e  e80da7feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473653  a2c0b75100             -mov byte ptr [0x51b7c0], al
    app->getMemory<x86::reg8>(x86::reg32(5355456) /* 0x51b7c0 */) = cpu.al;
    // 00473658  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047365f  e8fca6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473664  a25ab85100             -mov byte ptr [0x51b85a], al
    app->getMemory<x86::reg8>(x86::reg32(5355610) /* 0x51b85a */) = cpu.al;
    // 00473669  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473670  e8eba6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473675  a259b85100             -mov byte ptr [0x51b859], al
    app->getMemory<x86::reg8>(x86::reg32(5355609) /* 0x51b859 */) = cpu.al;
    // 0047367a  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473681  e8daa6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473686  a258b85100             -mov byte ptr [0x51b858], al
    app->getMemory<x86::reg8>(x86::reg32(5355608) /* 0x51b858 */) = cpu.al;
    // 0047368b  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473692  e8c9a6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473697  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473699  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047369b  e890f3ffff             -call 0x472a30
    cpu.esp -= 4;
    sub_472a30(app, cpu);
    if (cpu.terminate) return;
    // 004736a0  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004736a7  e8b4a6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004736ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004736ae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004736b3  e878f3ffff             -call 0x472a30
    cpu.esp -= 4;
    sub_472a30(app, cpu);
    if (cpu.terminate) return;
    // 004736b8  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004736bf  e89ca6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004736c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004736c6  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004736cb  e860f3ffff             -call 0x472a30
    cpu.esp -= 4;
    sub_472a30(app, cpu);
    if (cpu.terminate) return;
    // 004736d0  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004736d7  e884a6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004736dc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004736de  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004736e3  e848f3ffff             -call 0x472a30
    cpu.esp -= 4;
    sub_472a30(app, cpu);
    if (cpu.terminate) return;
    // 004736e8  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004736ef  e86ca6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 004736f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004736f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004736f8  e823f3ffff             -call 0x472a20
    cpu.esp -= 4;
    sub_472a20(app, cpu);
    if (cpu.terminate) return;
    // 004736fd  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473704  e857a6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473709  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047370b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473710  e80bf3ffff             -call 0x472a20
    cpu.esp -= 4;
    sub_472a20(app, cpu);
    if (cpu.terminate) return;
    // 00473715  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047371c  e83fa6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473721  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473723  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00473728  e8f3f2ffff             -call 0x472a20
    cpu.esp -= 4;
    sub_472a20(app, cpu);
    if (cpu.terminate) return;
    // 0047372d  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473734  e827a6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473739  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047373b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00473740  e8dbf2ffff             -call 0x472a20
    cpu.esp -= 4;
    sub_472a20(app, cpu);
    if (cpu.terminate) return;
    // 00473745  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047374c  e80fa6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 00473751  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00473753  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047375a  e801a6feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 0047375f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473761  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473768  e8f3a5feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 0047376d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047376f  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473776  e8e5a5feff             -call 0x45dd60
    cpu.esp -= 4;
    sub_45dd60(app, cpu);
    if (cpu.terminate) return;
    // 0047377b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047377d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047377f  e88c78ffff             -call 0x46b010
    cpu.esp -= 4;
    sub_46b010(app, cpu);
    if (cpu.terminate) return;
    // 00473784  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473786  e8016f0000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047378b  e840f1ffff             -call 0x4728d0
    cpu.esp -= 4;
    sub_4728d0(app, cpu);
    if (cpu.terminate) return;
    // 00473790  8b155cb85100           -mov edx, dword ptr [0x51b85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355612) /* 0x51b85c */);
    // 00473796  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00473799  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047379e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004737a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004737a3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004737a5  8b15c4b75100           -mov edx, dword ptr [0x51b7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355460) /* 0x51b7c4 */);
    // 004737ab  bb68010000             -mov ebx, 0x168
    cpu.ebx = 360 /*0x168*/;
    // 004737b0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004737b3  a35cb85100             -mov dword ptr [0x51b85c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355612) /* 0x51b85c */) = cpu.eax;
    // 004737b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004737ba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004737bd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004737bf  a3c4b75100             -mov dword ptr [0x51b7c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5355460) /* 0x51b7c4 */) = cpu.eax;
    // 004737c4  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004737ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
/* data blob: d0e74b00f0e74b0020e84b0048e84b0078e84b00a0e84b00c4e84b003ce94b00b0e94b004cea4b00ccea4b0060eb4b00e0eb4b0074ec4b0044ed4b0008ee4b00c0ee4b0054ef4b00fcef4b0004f04b000cf04b001cf04b0028f04b0034f04b003cf04b00a8f04b003cf14b00e0f14b007cf24b00f8f24b00fcef4b0004f04b000cf04b001cf04b0028f04b0034f04b00494e5354414c4c2e57494e00655860626758433a4e46533253454e2e45584500 */
void Application::sub_473880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473882  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473883  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473884  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473885  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473886  81ec24010000           -sub esp, 0x124
    (cpu.esp) -= x86::reg32(x86::sreg32(292 /*0x124*/));
    // 0047388c  8dbc2410010000         -lea edi, [esp + 0x110]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00473893  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00473898  be60384700             -mov esi, 0x473860
    cpu.esi = 4667488 /*0x473860*/;
    // 0047389d  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004738a4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004738a6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004738a7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004738a8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004738a9  e8121e0200             -call 0x4956c0
    cpu.esp -= 4;
    sub_4956c0(app, cpu);
    if (cpu.terminate) return;
    // 004738ae  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004738b0  e86b1e0200             -call 0x495720
    cpu.esp -= 4;
    sub_495720(app, cpu);
    if (cpu.terminate) return;
    // 004738b5  e88e1e0200             -call 0x495748
    cpu.esp -= 4;
    sub_495748(app, cpu);
    if (cpu.terminate) return;
    // 004738ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004738bc  0f8585000000           -jne 0x473947
    if (!cpu.flags.zf)
    {
        goto L_0x00473947;
    }
L_0x004738c2:
    // 004738c2  8dbc241c010000         -lea edi, [esp + 0x11c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004738c9  be6c384700             -mov esi, 0x47386c
    cpu.esi = 4667500 /*0x47386c*/;
    // 004738ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004738d0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004738d1  66a5                   -movsw word ptr es:[edi], word ptr [esi]
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
        cpu.esi -= 2;
    }
    else
    {
        cpu.edi += 2;
        cpu.esi += 2;
    }
L_0x004738d3:
    // 004738d3  8aa4141c010000         -mov ah, byte ptr [esp + edx + 0x11c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(284) /* 0x11c */ + cpu.edx * 1);
    // 004738da  42                     -inc edx
    (cpu.edx)++;
    // 004738db  80c40d                 -add ah, 0xd
    (cpu.ah) += x86::reg8(x86::sreg8(13 /*0xd*/));
    // 004738de  88a4141b010000         -mov byte ptr [esp + edx + 0x11b], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(283) /* 0x11b */ + cpu.edx * 1) = cpu.ah;
    // 004738e5  83fa06                 +cmp edx, 6
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
    // 004738e8  7ce9                   -jl 0x4738d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004738d3;
    }
    // 004738ea  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 004738ef  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004738f6  a188074e00             -mov eax, dword ptr [0x4e0788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113736) /* 0x4e0788 */);
    // 004738fb  e8c0ec0000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00473900  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473902  7436                   -je 0x47393a
    if (cpu.flags.zf)
    {
        goto L_0x0047393a;
    }
    // 00473904  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047390b  be72384700             -mov esi, 0x473872
    cpu.esi = 4667506 /*0x473872*/;
    // 00473910  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473912  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473914  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473915  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473916  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473917  66a5                   -movsw word ptr es:[edi], word ptr [esi]
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
        cpu.esi -= 2;
    }
    else
    {
        cpu.edi += 2;
        cpu.esi += 2;
    }
L_0x00473919:
    // 00473919  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047391b  e8281e0200             -call 0x495748
    cpu.esp -= 4;
    sub_495748(app, cpu);
    if (cpu.terminate) return;
    // 00473920  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473922  0f8571010000           -jne 0x473a99
    if (!cpu.flags.zf)
    {
        goto L_0x00473a99;
    }
L_0x00473928:
    // 00473928  42                     -inc edx
    (cpu.edx)++;
    // 00473929  83fa19                 +cmp edx, 0x19
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047392c  7d04                   -jge 0x473932
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473932;
    }
    // 0047392e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473930  74e7                   -je 0x473919
    if (cpu.flags.zf)
    {
        goto L_0x00473919;
    }
L_0x00473932:
    // 00473932  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473934  0f8488010000           -je 0x473ac2
    if (cpu.flags.zf)
    {
        goto L_0x00473ac2;
    }
L_0x0047393a:
    // 0047393a  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 00473940  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473941  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473942  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473943  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473944  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473945  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473946  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473947:
    // 00473947  b8d0f34b00             -mov eax, 0x4bf3d0
    cpu.eax = 4977616 /*0x4bf3d0*/;
    // 0047394c  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473952  e8595b0000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473957  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473959  7523                   -jne 0x47397e
    if (!cpu.flags.zf)
    {
        goto L_0x0047397e;
    }
    // 0047395b  ba84f34b00             -mov edx, 0x4bf384
    cpu.edx = 4977540 /*0x4bf384*/;
    // 00473960  b94b010000             -mov ecx, 0x14b
    cpu.ecx = 331 /*0x14b*/;
    // 00473965  686cf44b00             -push 0x4bf46c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977772 /*0x4bf46c*/;
    cpu.esp -= 4;
    // 0047396a  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00473970  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 00473976  e805650000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0047397b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047397e:
    // 0047397e  b8d8f34b00             -mov eax, 0x4bf3d8
    cpu.eax = 4977624 /*0x4bf3d8*/;
    // 00473983  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473989  e8225b0000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 0047398e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473990  7523                   -jne 0x4739b5
    if (!cpu.flags.zf)
    {
        goto L_0x004739b5;
    }
    // 00473992  bb84f34b00             -mov ebx, 0x4bf384
    cpu.ebx = 4977540 /*0x4bf384*/;
    // 00473997  be4d010000             -mov esi, 0x14d
    cpu.esi = 333 /*0x14d*/;
    // 0047399c  68c8f44b00             -push 0x4bf4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977864 /*0x4bf4c8*/;
    cpu.esp -= 4;
    // 004739a1  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 004739a7  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 004739ad  e8ce640000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 004739b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004739b5:
    // 004739b5  b8e0f34b00             -mov eax, 0x4bf3e0
    cpu.eax = 4977632 /*0x4bf3e0*/;
    // 004739ba  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 004739c0  e8eb5a0000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 004739c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004739c7  7523                   -jne 0x4739ec
    if (!cpu.flags.zf)
    {
        goto L_0x004739ec;
    }
    // 004739c9  bf84f34b00             -mov edi, 0x4bf384
    cpu.edi = 4977540 /*0x4bf384*/;
    // 004739ce  bd4f010000             -mov ebp, 0x14f
    cpu.ebp = 335 /*0x14f*/;
    // 004739d3  6830f54b00             -push 0x4bf530
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977968 /*0x4bf530*/;
    cpu.esp -= 4;
    // 004739d8  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 004739de  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 004739e4  e897640000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 004739e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004739ec:
    // 004739ec  b8e8f34b00             -mov eax, 0x4bf3e8
    cpu.eax = 4977640 /*0x4bf3e8*/;
    // 004739f1  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 004739f7  e8b45a0000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 004739fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004739fe  7522                   -jne 0x473a22
    if (!cpu.flags.zf)
    {
        goto L_0x00473a22;
    }
    // 00473a00  b884f34b00             -mov eax, 0x4bf384
    cpu.eax = 4977540 /*0x4bf384*/;
    // 00473a05  ba51010000             -mov edx, 0x151
    cpu.edx = 337 /*0x151*/;
    // 00473a0a  6898f54b00             -push 0x4bf598
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978072 /*0x4bf598*/;
    cpu.esp -= 4;
    // 00473a0f  a378a64c00             -mov dword ptr [0x4ca678], eax
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.eax;
    // 00473a14  89157ca64c00           -mov dword ptr [0x4ca67c], edx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edx;
    // 00473a1a  e861640000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473a1f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473a22:
    // 00473a22  b8f0f34b00             -mov eax, 0x4bf3f0
    cpu.eax = 4977648 /*0x4bf3f0*/;
    // 00473a27  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473a2d  e87e5a0000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473a32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473a34  7523                   -jne 0x473a59
    if (!cpu.flags.zf)
    {
        goto L_0x00473a59;
    }
    // 00473a36  b984f34b00             -mov ecx, 0x4bf384
    cpu.ecx = 4977540 /*0x4bf384*/;
    // 00473a3b  bb53010000             -mov ebx, 0x153
    cpu.ebx = 339 /*0x153*/;
    // 00473a40  68f8f54b00             -push 0x4bf5f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978168 /*0x4bf5f8*/;
    cpu.esp -= 4;
    // 00473a45  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 00473a4b  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00473a51  e82a640000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473a56  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473a59:
    // 00473a59  b8f8f34b00             -mov eax, 0x4bf3f8
    cpu.eax = 4977656 /*0x4bf3f8*/;
    // 00473a5e  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473a64  e8475a0000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473a69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473a6b  0f8551feffff           -jne 0x4738c2
    if (!cpu.flags.zf)
    {
        goto L_0x004738c2;
    }
    // 00473a71  be84f34b00             -mov esi, 0x4bf384
    cpu.esi = 4977540 /*0x4bf384*/;
    // 00473a76  bf55010000             -mov edi, 0x155
    cpu.edi = 341 /*0x155*/;
    // 00473a7b  6854f64b00             -push 0x4bf654
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978260 /*0x4bf654*/;
    cpu.esp -= 4;
    // 00473a80  893578a64c00           -mov dword ptr [0x4ca678], esi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.esi;
    // 00473a86  893d7ca64c00           -mov dword ptr [0x4ca67c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edi;
    // 00473a8c  e8ef630000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473a91  83c404                 +add esp, 4
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
    // 00473a94  e929feffff             -jmp 0x4738c2
    goto L_0x004738c2;
L_0x00473a99:
    // 00473a99  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00473a9b  0441                   -add al, 0x41
    (cpu.al) += x86::reg8(x86::sreg8(65 /*0x41*/));
    // 00473a9d  88842400010000         -mov byte ptr [esp + 0x100], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.al;
    // 00473aa4  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00473aab  e87cb10000             -call 0x47ec2c
    cpu.esp -= 4;
    sub_47ec2c(app, cpu);
    if (cpu.terminate) return;
    // 00473ab0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473ab2  0f8470feffff           -je 0x473928
    if (cpu.flags.zf)
    {
        goto L_0x00473928;
    }
    // 00473ab8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00473abd  e966feffff             -jmp 0x473928
    goto L_0x00473928;
L_0x00473ac2:
    // 00473ac2  b8d0f34b00             -mov eax, 0x4bf3d0
    cpu.eax = 4977616 /*0x4bf3d0*/;
    // 00473ac7  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473acd  e8de590000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473ad2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473ad4  7522                   -jne 0x473af8
    if (!cpu.flags.zf)
    {
        goto L_0x00473af8;
    }
    // 00473ad6  bd84f34b00             -mov ebp, 0x4bf384
    cpu.ebp = 4977540 /*0x4bf384*/;
    // 00473adb  b879010000             -mov eax, 0x179
    cpu.eax = 377 /*0x179*/;
    // 00473ae0  68b0f64b00             -push 0x4bf6b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978352 /*0x4bf6b0*/;
    cpu.esp -= 4;
    // 00473ae5  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 00473aeb  a37ca64c00             -mov dword ptr [0x4ca67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.eax;
    // 00473af0  e88b630000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473af5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473af8:
    // 00473af8  b8d8f34b00             -mov eax, 0x4bf3d8
    cpu.eax = 4977624 /*0x4bf3d8*/;
    // 00473afd  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473b03  e8a8590000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473b08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473b0a  7523                   -jne 0x473b2f
    if (!cpu.flags.zf)
    {
        goto L_0x00473b2f;
    }
    // 00473b0c  ba84f34b00             -mov edx, 0x4bf384
    cpu.edx = 4977540 /*0x4bf384*/;
    // 00473b11  b97b010000             -mov ecx, 0x17b
    cpu.ecx = 379 /*0x17b*/;
    // 00473b16  68fcf64b00             -push 0x4bf6fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978428 /*0x4bf6fc*/;
    cpu.esp -= 4;
    // 00473b1b  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00473b21  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 00473b27  e854630000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473b2c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473b2f:
    // 00473b2f  b8e0f34b00             -mov eax, 0x4bf3e0
    cpu.eax = 4977632 /*0x4bf3e0*/;
    // 00473b34  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473b3a  e871590000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473b3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473b41  7523                   -jne 0x473b66
    if (!cpu.flags.zf)
    {
        goto L_0x00473b66;
    }
    // 00473b43  bb84f34b00             -mov ebx, 0x4bf384
    cpu.ebx = 4977540 /*0x4bf384*/;
    // 00473b48  be7d010000             -mov esi, 0x17d
    cpu.esi = 381 /*0x17d*/;
    // 00473b4d  6858f74b00             -push 0x4bf758
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978520 /*0x4bf758*/;
    cpu.esp -= 4;
    // 00473b52  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00473b58  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 00473b5e  e81d630000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473b63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473b66:
    // 00473b66  b8e8f34b00             -mov eax, 0x4bf3e8
    cpu.eax = 4977640 /*0x4bf3e8*/;
    // 00473b6b  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473b71  e83a590000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473b76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473b78  7523                   -jne 0x473b9d
    if (!cpu.flags.zf)
    {
        goto L_0x00473b9d;
    }
    // 00473b7a  bf84f34b00             -mov edi, 0x4bf384
    cpu.edi = 4977540 /*0x4bf384*/;
    // 00473b7f  bd7f010000             -mov ebp, 0x17f
    cpu.ebp = 383 /*0x17f*/;
    // 00473b84  68b8f74b00             -push 0x4bf7b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978616 /*0x4bf7b8*/;
    cpu.esp -= 4;
    // 00473b89  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 00473b8f  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 00473b95  e8e6620000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473b9a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473b9d:
    // 00473b9d  b8f0f34b00             -mov eax, 0x4bf3f0
    cpu.eax = 4977648 /*0x4bf3f0*/;
    // 00473ba2  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473ba8  e803590000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473bad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473baf  7522                   -jne 0x473bd3
    if (!cpu.flags.zf)
    {
        goto L_0x00473bd3;
    }
    // 00473bb1  b884f34b00             -mov eax, 0x4bf384
    cpu.eax = 4977540 /*0x4bf384*/;
    // 00473bb6  ba81010000             -mov edx, 0x181
    cpu.edx = 385 /*0x181*/;
    // 00473bbb  6810f84b00             -push 0x4bf810
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978704 /*0x4bf810*/;
    cpu.esp -= 4;
    // 00473bc0  a378a64c00             -mov dword ptr [0x4ca678], eax
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.eax;
    // 00473bc5  89157ca64c00           -mov dword ptr [0x4ca67c], edx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edx;
    // 00473bcb  e8b0620000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473bd0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00473bd3:
    // 00473bd3  b8f8f34b00             -mov eax, 0x4bf3f8
    cpu.eax = 4977656 /*0x4bf3f8*/;
    // 00473bd8  8b1584074e00           -mov edx, dword ptr [0x4e0784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113732) /* 0x4e0784 */);
    // 00473bde  e8cd580000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00473be3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473be5  0f854ffdffff           -jne 0x47393a
    if (!cpu.flags.zf)
    {
        goto L_0x0047393a;
    }
    // 00473beb  b984f34b00             -mov ecx, 0x4bf384
    cpu.ecx = 4977540 /*0x4bf384*/;
    // 00473bf0  bb83010000             -mov ebx, 0x183
    cpu.ebx = 387 /*0x183*/;
    // 00473bf5  6868f84b00             -push 0x4bf868
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978792 /*0x4bf868*/;
    cpu.esp -= 4;
    // 00473bfa  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 00473c00  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00473c06  e875620000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00473c0b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473c0e  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 00473c14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473c20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473c30  e8eb29ffff             -call 0x466620
    cpu.esp -= 4;
    sub_466620(app, cpu);
    if (cpu.terminate) return;
    // 00473c35  e8b6effeff             -call 0x462bf0
    cpu.esp -= 4;
    sub_462bf0(app, cpu);
    if (cpu.terminate) return;
    // 00473c3a  e801fafeff             -call 0x463640
    cpu.esp -= 4;
    sub_463640(app, cpu);
    if (cpu.terminate) return;
    // 00473c3f  e8ecddfdff             -call 0x451a30
    cpu.esp -= 4;
    sub_451a30(app, cpu);
    if (cpu.terminate) return;
    // 00473c44  b884b85100             -mov eax, 0x51b884
    cpu.eax = 5355652 /*0x51b884*/;
    // 00473c49  e8a2cb0000             -call 0x4807f0
    cpu.esp -= 4;
    sub_4807f0(app, cpu);
    if (cpu.terminate) return;
    // 00473c4e  e8cd280000             -call 0x476520
    cpu.esp -= 4;
    sub_476520(app, cpu);
    if (cpu.terminate) return;
    // 00473c53  e8e82cffff             -call 0x466940
    cpu.esp -= 4;
    sub_466940(app, cpu);
    if (cpu.terminate) return;
    // 00473c58  e803e2faff             -call 0x421e60
    cpu.esp -= 4;
    sub_421e60(app, cpu);
    if (cpu.terminate) return;
    // 00473c5d  e97fca0100             -jmp 0x4906e1
    return sub_4906e1(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473c73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473c74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473c75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473c76  b854f44b00             -mov eax, 0x4bf454
    cpu.eax = 4977748 /*0x4bf454*/;
    // 00473c7b  e864610000             -call 0x479de4
    cpu.esp -= 4;
    sub_479de4(app, cpu);
    if (cpu.terminate) return;
    // 00473c80  e8cb020000             -call 0x473f50
    cpu.esp -= 4;
    sub_473f50(app, cpu);
    if (cpu.terminate) return;
    // 00473c85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473c87  e8f4010000             -call 0x473e80
    cpu.esp -= 4;
    sub_473e80(app, cpu);
    if (cpu.terminate) return;
    // 00473c8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473c8e  e80d010000             -call 0x473da0
    cpu.esp -= 4;
    sub_473da0(app, cpu);
    if (cpu.terminate) return;
    // 00473c93  ba0000a000             -mov edx, 0xa00000
    cpu.edx = 10485760 /*0xa00000*/;
    // 00473c98  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 00473c9d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00473ca2  e885180200             -call 0x49552c
    cpu.esp -= 4;
    sub_49552c(app, cpu);
    if (cpu.terminate) return;
    // 00473ca7  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00473cac  a36c034e00             -mov dword ptr [0x4e036c], eax
    app->getMemory<x86::reg32>(x86::reg32(5112684) /* 0x4e036c */) = cpu.eax;
    // 00473cb1  890dd8a34c00           -mov dword ptr [0x4ca3d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */) = cpu.ecx;
    // 00473cb7  8915dca34c00           -mov dword ptr [0x4ca3dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */) = cpu.edx;
    // 00473cbd  e8fe180200             -call 0x4955c0
    cpu.esp -= 4;
    sub_4955c0(app, cpu);
    if (cpu.terminate) return;
    // 00473cc2  833db0a34c0000         +cmp dword ptr [0x4ca3b0], 0
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
    // 00473cc9  0f849d000000           -je 0x473d6c
    if (cpu.flags.zf)
    {
        goto L_0x00473d6c;
    }
L_0x00473ccf:
    // 00473ccf  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00473cd4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00473cd6  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 00473cdb  893568a74c00           -mov dword ptr [0x4ca768], esi
    app->getMemory<x86::reg32>(x86::reg32(5023592) /* 0x4ca768 */) = cpu.esi;
    // 00473ce1  893da8a64c00           -mov dword ptr [0x4ca6a8], edi
    app->getMemory<x86::reg32>(x86::reg32(5023400) /* 0x4ca6a8 */) = cpu.edi;
    // 00473ce7  e89491ffff             -call 0x46ce80
    cpu.esp -= 4;
    sub_46ce80(app, cpu);
    if (cpu.terminate) return;
    // 00473cec  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 00473cf1  ba00414700             -mov edx, 0x474100
    cpu.edx = 4669696 /*0x474100*/;
    // 00473cf6  e8ad5c0000             -call 0x4799a8
    cpu.esp -= 4;
    sub_4799a8(app, cpu);
    if (cpu.terminate) return;
    // 00473cfb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00473cfd  892d20a44c00           -mov dword ptr [0x4ca420], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */) = cpu.ebp;
    // 00473d03  e8d8270000             -call 0x4764e0
    cpu.esp -= 4;
    sub_4764e0(app, cpu);
    if (cpu.terminate) return;
    // 00473d08  68803d4700             -push 0x473d80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4668800 /*0x473d80*/;
    cpu.esp -= 4;
    // 00473d0d  6818020000             -push 0x218
    app->getMemory<x86::reg32>(cpu.esp-4) = 536 /*0x218*/;
    cpu.esp -= 4;
    // 00473d12  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473d14  e807400000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00473d19  e832ddfdff             -call 0x451a50
    cpu.esp -= 4;
    sub_451a50(app, cpu);
    if (cpu.terminate) return;
    // 00473d1e  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00473d23  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00473d28  e8bf720000             -call 0x47afec
    cpu.esp -= 4;
    sub_47afec(app, cpu);
    if (cpu.terminate) return;
    // 00473d2d  e8deecfaff             -call 0x422a10
    cpu.esp -= 4;
    sub_422a10(app, cpu);
    if (cpu.terminate) return;
    // 00473d32  e8294df9ff             -call 0x408a60
    cpu.esp -= 4;
    sub_408a60(app, cpu);
    if (cpu.terminate) return;
    // 00473d37  e824fafeff             -call 0x463760
    cpu.esp -= 4;
    sub_463760(app, cpu);
    if (cpu.terminate) return;
    // 00473d3c  e82ff6feff             -call 0x463370
    cpu.esp -= 4;
    sub_463370(app, cpu);
    if (cpu.terminate) return;
    // 00473d41  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00473d43  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00473d48  e843dafdff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 00473d4d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00473d4f  6884b85100             -push 0x51b884
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355652 /*0x51b884*/;
    cpu.esp -= 4;
    // 00473d54  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473d56  b8a01e4400             -mov eax, 0x441ea0
    cpu.eax = 4464288 /*0x441ea0*/;
    // 00473d5b  e800ca0000             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 00473d60  e8db28ffff             -call 0x466640
    cpu.esp -= 4;
    sub_466640(app, cpu);
    if (cpu.terminate) return;
    // 00473d65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473d6c:
    // 00473d6c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00473d6e  e832c70100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 00473d73  e957ffffff             -jmp 0x473ccf
    goto L_0x00473ccf;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473d80  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00473d84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473d86  7405                   -je 0x473d8d
    if (cpu.flags.zf)
    {
        goto L_0x00473d8d;
    }
    // 00473d88  83f801                 +cmp eax, 1
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
    // 00473d8b  7508                   -jne 0x473d95
    if (!cpu.flags.zf)
    {
        goto L_0x00473d95;
    }
L_0x00473d8d:
    // 00473d8d  b844514d42             -mov eax, 0x424d5144
    cpu.eax = 1112363332 /*0x424d5144*/;
    // 00473d92  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00473d95:
    // 00473d95  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473d9a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_473da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473da1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473da2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473da4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473da5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473da6  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473da9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00473dab  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00473db0  6898b85100             -push 0x51b898
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355672 /*0x51b898*/;
    cpu.esp -= 4;
    // 00473db5  891598b85100           -mov dword ptr [0x51b898], edx
    app->getMemory<x86::reg32>(x86::reg32(5355672) /* 0x51b898 */) = cpu.edx;
    // 00473dbb  2eff1534754b00         -call dword ptr cs:[0x4b7534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945204) /* 0x4b7534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473dc2  a1a4b85100             -mov eax, dword ptr [0x51b8a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355684) /* 0x51b8a4 */);
    // 00473dc7  0305acb85100           -add eax, dword ptr [0x51b8ac]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5355692) /* 0x51b8ac */)));
    // 00473dcd  3d00000001             +cmp eax, 0x1000000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473dd2  7341                   -jae 0x473e15
    if (!cpu.flags.cf)
    {
        goto L_0x00473e15;
    }
    // 00473dd4  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00473dd9  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473ddd  be00384700             -mov esi, 0x473800
    cpu.esi = 4667392 /*0x473800*/;
    // 00473de2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473de4  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00473de9  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00473ded  be18384700             -mov esi, 0x473818
    cpu.esi = 4667416 /*0x473818*/;
    // 00473df2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473df4  6a31                   -push 0x31
    app->getMemory<x86::reg32>(cpu.esp-4) = 49 /*0x31*/;
    cpu.esp -= 4;
    // 00473df6  8b749c34               -mov esi, dword ptr [esp + ebx*4 + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.ebx * 4);
    // 00473dfa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473dfb  8b7c9c20               -mov edi, dword ptr [esp + ebx*4 + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */ + cpu.ebx * 4);
    // 00473dff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473e00  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00473e02  2eff1500744b00         -call dword ptr cs:[0x4b7400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944896) /* 0x4b7400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473e09  83f802                 +cmp eax, 2
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
    // 00473e0c  7507                   -jne 0x473e15
    if (!cpu.flags.zf)
    {
        goto L_0x00473e15;
    }
    // 00473e0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473e10  e890c60100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
L_0x00473e15:
    // 00473e15  b800001000             -mov eax, 0x100000
    cpu.eax = 1048576 /*0x100000*/;
    // 00473e1a  e80122f9ff             -call 0x406020
    cpu.esp -= 4;
    sub_406020(app, cpu);
    if (cpu.terminate) return;
    // 00473e1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473e21  740a                   -je 0x473e2d
    if (cpu.flags.zf)
    {
        goto L_0x00473e2d;
    }
L_0x00473e23:
    // 00473e23  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473e26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473e2d:
    // 00473e2d  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00473e32  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00473e34  be30384700             -mov esi, 0x473830
    cpu.esi = 4667440 /*0x473830*/;
    // 00473e39  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473e3b  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00473e40  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00473e44  be48384700             -mov esi, 0x473848
    cpu.esi = 4667464 /*0x473848*/;
    // 00473e49  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473e4b  6a31                   -push 0x31
    app->getMemory<x86::reg32>(cpu.esp-4) = 49 /*0x31*/;
    cpu.esp -= 4;
    // 00473e4d  8b6c9c4c               -mov ebp, dword ptr [esp + ebx*4 + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */ + cpu.ebx * 4);
    // 00473e51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473e52  8b449c08               -mov eax, dword ptr [esp + ebx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.ebx * 4);
    // 00473e56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473e57  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00473e59  2eff1500744b00         -call dword ptr cs:[0x4b7400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944896) /* 0x4b7400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473e60  83f802                 +cmp eax, 2
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
    // 00473e63  75be                   -jne 0x473e23
    if (!cpu.flags.zf)
    {
        goto L_0x00473e23;
    }
    // 00473e65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473e67  e839c60100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 00473e6c  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473e6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473e80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473e81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473e82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473e84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473e85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473e86  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00473e89  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00473e8b  6800f44b00             -push 0x4bf400
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977664 /*0x4bf400*/;
    cpu.esp -= 4;
    // 00473e90  2eff1540754b00         -call dword ptr cs:[0x4b7540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945216) /* 0x4b7540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473e97  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00473e99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473e9b  7545                   -jne 0x473ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00473ee2;
    }
    // 00473e9d  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00473ea2  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473ea6  bed0374700             -mov esi, 0x4737d0
    cpu.esi = 4667344 /*0x4737d0*/;
    // 00473eab  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00473ead  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473eaf  6824f44b00             -push 0x4bf424
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977700 /*0x4bf424*/;
    cpu.esp -= 4;
    // 00473eb4  8b549c20               -mov edx, dword ptr [esp + ebx*4 + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */ + cpu.ebx * 4);
    // 00473eb8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473eb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473eba  2eff1500744b00         -call dword ptr cs:[0x4b7400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944896) /* 0x4b7400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473ec1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473ec3  e8ddc50100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
L_0x00473ec8:
    // 00473ec8  66837c243005           +cmp word ptr [esp + 0x30], 5
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00473ece  7236                   -jb 0x473f06
    if (cpu.flags.cf)
    {
        goto L_0x00473f06;
    }
    // 00473ed0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473ed1  2eff1598744b00         -call dword ptr cs:[0x4b7498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945048) /* 0x4b7498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473ed8  83c438                 +add esp, 0x38
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00473edb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473edc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473edd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ede  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473edf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ee0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ee1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473ee2:
    // 00473ee2  680cf44b00             -push 0x4bf40c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977676 /*0x4bf40c*/;
    cpu.esp -= 4;
    // 00473ee7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473ee8  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473eef  a380b85100             -mov dword ptr [0x51b880], eax
    app->getMemory<x86::reg32>(x86::reg32(5355648) /* 0x51b880 */) = cpu.eax;
    // 00473ef4  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00473ef8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473ef9  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00473efd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473efe  ff1580b85100           -call dword ptr [0x51b880]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5355648) /* 0x51b880 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473f04  ebc2                   -jmp 0x473ec8
    goto L_0x00473ec8;
L_0x00473f06:
    // 00473f06  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00473f0b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00473f0d  bee8374700             -mov esi, 0x4737e8
    cpu.esi = 4667368 /*0x4737e8*/;
    // 00473f12  6a30                   -push 0x30
    app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00473f14  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473f16  6824f44b00             -push 0x4bf424
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977700 /*0x4bf424*/;
    cpu.esp -= 4;
    // 00473f1b  8b4c9c08               -mov ecx, dword ptr [esp + ebx*4 + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.ebx * 4);
    // 00473f1f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473f20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00473f22  2eff1500744b00         -call dword ptr cs:[0x4b7400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944896) /* 0x4b7400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473f29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473f2b  e875c50100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 00473f30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473f31  2eff1598744b00         -call dword ptr cs:[0x4b7498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945048) /* 0x4b7498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473f38  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00473f3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473f50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473f51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473f52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473f53  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473f56  bac0f34b00             -mov edx, 0x4bf3c0
    cpu.edx = 4977600 /*0x4bf3c0*/;
    // 00473f5b  b8c4f34b00             -mov eax, 0x4bf3c4
    cpu.eax = 4977604 /*0x4bf3c4*/;
    // 00473f60  e8b9d20000             -call 0x48121e
    cpu.esp -= 4;
    sub_48121e(app, cpu);
    if (cpu.terminate) return;
    // 00473f65  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00473f67  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00473f69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473f6b  0f8479010000           -je 0x4740ea
    if (cpu.flags.zf)
    {
        goto L_0x004740ea;
    }
    // 00473f71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473f72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473f73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473f74  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473f79  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00473f7e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473f80  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473f84  bfd0f34b00             -mov edi, 0x4bf3d0
    cpu.edi = 4977616 /*0x4bf3d0*/;
    // 00473f89  e863110200             -call 0x4950f1
    cpu.esp -= 4;
    sub_4950f1(app, cpu);
    if (cpu.terminate) return;
    // 00473f8e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473f90  49                     -dec ecx
    (cpu.ecx)--;
    // 00473f91  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00473f93  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00473f95  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00473f97  49                     -dec ecx
    (cpu.ecx)--;
    // 00473f98  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 00473f9c  b8d0f34b00             -mov eax, 0x4bf3d0
    cpu.eax = 4977616 /*0x4bf3d0*/;
    // 00473fa1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00473fa3  e818e60000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00473fa8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473faa  7513                   -jne 0x473fbf
    if (!cpu.flags.zf)
    {
        goto L_0x00473fbf;
    }
L_0x00473fac:
    // 00473fac  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00473fae  e884d40000             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 00473fb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fb6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473fb8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473fbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fbe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473fbf:
    // 00473fbf  bfd8f34b00             -mov edi, 0x4bf3d8
    cpu.edi = 4977624 /*0x4bf3d8*/;
    // 00473fc4  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 00473fc8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473fca  49                     -dec ecx
    (cpu.ecx)--;
    // 00473fcb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00473fcd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00473fcf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00473fd1  49                     -dec ecx
    (cpu.ecx)--;
    // 00473fd2  b8d8f34b00             -mov eax, 0x4bf3d8
    cpu.eax = 4977624 /*0x4bf3d8*/;
    // 00473fd7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00473fd9  e8e2e50000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00473fde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473fe0  7518                   -jne 0x473ffa
    if (!cpu.flags.zf)
    {
        goto L_0x00473ffa;
    }
    // 00473fe2  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00473fe7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00473fe9  e849d40000             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 00473fee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ff0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ff1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473ff3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473ff6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ff7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ff8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ff9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473ffa:
    // 00473ffa  bfe0f34b00             -mov edi, 0x4bf3e0
    cpu.edi = 4977632 /*0x4bf3e0*/;
    // 00473fff  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 00474003  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474005  49                     -dec ecx
    (cpu.ecx)--;
    // 00474006  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00474008  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047400a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047400c  49                     -dec ecx
    (cpu.ecx)--;
    // 0047400d  b8e0f34b00             -mov eax, 0x4bf3e0
    cpu.eax = 4977632 /*0x4bf3e0*/;
    // 00474012  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00474014  e8a7e50000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00474019  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047401b  7518                   -jne 0x474035
    if (!cpu.flags.zf)
    {
        goto L_0x00474035;
    }
    // 0047401d  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00474022  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00474024  e80ed40000             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 00474029  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047402a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047402b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047402c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047402e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474031  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474032  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474033  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474034  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474035:
    // 00474035  bfe8f34b00             -mov edi, 0x4bf3e8
    cpu.edi = 4977640 /*0x4bf3e8*/;
    // 0047403a  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 0047403e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474040  49                     -dec ecx
    (cpu.ecx)--;
    // 00474041  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00474043  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474045  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00474047  49                     -dec ecx
    (cpu.ecx)--;
    // 00474048  b8e8f34b00             -mov eax, 0x4bf3e8
    cpu.eax = 4977640 /*0x4bf3e8*/;
    // 0047404d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047404f  e86ce50000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 00474054  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474056  7518                   -jne 0x474070
    if (!cpu.flags.zf)
    {
        goto L_0x00474070;
    }
    // 00474058  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 0047405d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047405f  e8d3d30000             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 00474064  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474065  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474066  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474067  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00474069  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047406c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047406d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047406e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047406f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474070:
    // 00474070  bff0f34b00             -mov edi, 0x4bf3f0
    cpu.edi = 4977648 /*0x4bf3f0*/;
    // 00474075  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 00474079  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047407b  49                     -dec ecx
    (cpu.ecx)--;
    // 0047407c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047407e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474080  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00474082  49                     -dec ecx
    (cpu.ecx)--;
    // 00474083  b8f0f34b00             -mov eax, 0x4bf3f0
    cpu.eax = 4977648 /*0x4bf3f0*/;
    // 00474088  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047408a  e831e50000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 0047408f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474091  7518                   -jne 0x4740ab
    if (!cpu.flags.zf)
    {
        goto L_0x004740ab;
    }
    // 00474093  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 00474098  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047409a  e898d30000             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 0047409f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004740a4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004740a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004740ab:
    // 004740ab  bff8f34b00             -mov edi, 0x4bf3f8
    cpu.edi = 4977656 /*0x4bf3f8*/;
    // 004740b0  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 004740b4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004740b6  49                     -dec ecx
    (cpu.ecx)--;
    // 004740b7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004740b9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004740bb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004740bd  49                     -dec ecx
    (cpu.ecx)--;
    // 004740be  b8f8f34b00             -mov eax, 0x4bf3f8
    cpu.eax = 4977656 /*0x4bf3f8*/;
    // 004740c3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004740c5  e8f6e40000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 004740ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004740cc  0f85dafeffff           -jne 0x473fac
    if (!cpu.flags.zf)
    {
        goto L_0x00473fac;
    }
    // 004740d2  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 004740d7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004740d9  e859d30000             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 004740de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004740e3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004740e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004740ea:
    // 004740ea  e8b6c30100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 004740ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004740f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004740f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474100  83fa2c                 +cmp edx, 0x2c
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
    // 00474103  7406                   -je 0x47410b
    if (cpu.flags.zf)
    {
        goto L_0x0047410b;
    }
    // 00474105  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047410a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047410b:
    // 0047410b  c605a7a74c0001         -mov byte ptr [0x4ca7a7], 1
    app->getMemory<x86::reg8>(x86::reg32(5023655) /* 0x4ca7a7 */) = 1 /*0x1*/;
    // 00474112  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00474117  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474120  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474121  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474122  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474123  2eff1530754b00         -call dword ptr cs:[0x4b7530]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945200) /* 0x4b7530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047412a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047412b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_474130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474130  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474140  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474150  e937650000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474163  ba84f34b00             -mov edx, 0x4bf384
    cpu.edx = 4977540 /*0x4bf384*/;
    // 00474168  b926000000             -mov ecx, 0x26
    cpu.ecx = 38 /*0x26*/;
    // 0047416d  c70000780500           -mov dword ptr [eax], 0x57800
    app->getMemory<x86::reg32>(cpu.eax) = 358400 /*0x57800*/;
    // 00474173  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474175  b8a4f34b00             -mov eax, 0x4bf3a4
    cpu.eax = 4977572 /*0x4bf3a4*/;
    // 0047417a  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00474180  ba00780500             -mov edx, 0x57800
    cpu.edx = 358400 /*0x57800*/;
    // 00474185  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0047418b  e898600000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00474190  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474191  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474192  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474193  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4741c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004741c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004741c5  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004741c7  feca                   -dec dl
    (cpu.dl)--;
    // 004741c9  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004741cc  7714                   -ja 0x4741e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004741e2;
    }
    // 004741ce  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004741d4  ff2495a0414700         -jmp dword ptr [edx*4 + 0x4741a0]
    cpu.ip = app->getMemory<x86::reg32>(4669856 + cpu.edx * 4); goto dynamic_jump;
  case 0x004741db:
    // 004741db  c7400410000000         -mov dword ptr [eax + 4], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 16 /*0x10*/;
L_0x004741e2:
    // 004741e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741e3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004741e4:
    // 004741e4  c7400408000000         -mov dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004741eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741ec  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004741ed:
    // 004741ed  c7400420000000         -mov dword ptr [eax + 4], 0x20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 32 /*0x20*/;
    // 004741f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741f5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004741f6:
    // 004741f6  c7400403000000         -mov dword ptr [eax + 4], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 3 /*0x3*/;
    // 004741fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741fe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004741ff:
    // 004741ff  c7400404000000         -mov dword ptr [eax + 4], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4 /*0x4*/;
    // 00474206  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474207  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00474234  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474235  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474236  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474237  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474238  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047423b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047423d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047423f  bad4000000             -mov edx, 0xd4
    cpu.edx = 212 /*0xd4*/;
    // 00474244  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474246  e8f586feff             -call 0x45c940
    cpu.esp -= 4;
    sub_45c940(app, cpu);
    if (cpu.terminate) return;
    // 0047424b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047424d  7427                   -je 0x474276
    if (cpu.flags.zf)
    {
        goto L_0x00474276;
    }
    // 0047424f  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00474251  80fc04                 +cmp ah, 4
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474254  7528                   -jne 0x47427e
    if (!cpu.flags.zf)
    {
        goto L_0x0047427e;
    }
L_0x00474256:
    // 00474256  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474259  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x0047425e:
    // 0047425e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047425f  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00474262  6800800800             -push 0x88000
    app->getMemory<x86::reg32>(cpu.esp-4) = 557056 /*0x88000*/;
    cpu.esp -= 4;
    // 00474267  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00474269  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047426b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047426d  e89e9dfeff             -call 0x45e010
    cpu.esp -= 4;
    sub_45e010(app, cpu);
    if (cpu.terminate) return;
    // 00474272  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474274  7517                   -jne 0x47428d
    if (!cpu.flags.zf)
    {
        goto L_0x0047428d;
    }
L_0x00474276:
    // 00474276  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474279  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047427a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047427b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047427c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047427d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047427e:
    // 0047427e  80fc05                 +cmp ah, 5
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474281  74d3                   -je 0x474256
    if (cpu.flags.zf)
    {
        goto L_0x00474256;
    }
    // 00474283  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474286  05a4000000             +add eax, 0xa4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047428b  ebd1                   -jmp 0x47425e
    goto L_0x0047425e;
L_0x0047428d:
    // 0047428d  bad4000000             -mov edx, 0xd4
    cpu.edx = 212 /*0xd4*/;
    // 00474292  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474294  e8d786feff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00474299  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047429b  fec8                   -dec al
    (cpu.al)--;
    // 0047429d  3c08                   +cmp al, 8
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
    // 0047429f  77d5                   -ja 0x474276
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00474276;
    }
    // 004742a1  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004742a6  ff248510424700         -jmp dword ptr [eax*4 + 0x474210]
    cpu.ip = app->getMemory<x86::reg32>(4669968 + cpu.eax * 4); goto dynamic_jump;
  case 0x004742ad:
    // 004742ad  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004742b0  f6c603                 +test dh, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 3 /*0x3*/));
    // 004742b3  7562                   -jne 0x474317
    if (!cpu.flags.zf)
    {
        goto L_0x00474317;
    }
    // 004742b5  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004742b8  0f84af000000           -je 0x47436d
    if (cpu.flags.zf)
    {
        goto L_0x0047436d;
    }
    // 004742be  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004742c3  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004742c6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004742c9  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004742cb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004742cd  83c320                 -add ebx, 0x20
    (cpu.ebx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004742d0  e88b070000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 004742d5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004742d8  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 004742e2  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004742e7  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004742ea  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004742ec  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004742ef  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004742f6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004742f8  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004742ff  bb78b95100             -mov ebx, 0x51b978
    cpu.ebx = 5355896 /*0x51b978*/;
    // 00474304  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474307  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00474309  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 0047430f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474312  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474313  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474314  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474315  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474316  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474317:
    // 00474317  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0047431c  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047431f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00474322  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00474325  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00474328  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047432a  e831070000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 0047432f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474332  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 0047433c  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00474341  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474344  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00474346  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00474349  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00474350  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474352  bb78b95100             -mov ebx, 0x51b978
    cpu.ebx = 5355896 /*0x51b978*/;
    // 00474357  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047435a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047435d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047435f  899acc000000           -mov dword ptr [edx + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00474365  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474368  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474369  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047436a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047436b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047436c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047436d:
    // 0047436d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00474372  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474375  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474377  8d5820                 -lea ebx, [eax + 0x20]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047437a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047437d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047437f  e8dc060000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 00474384  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474387  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 00474391  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00474396  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474399  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047439b  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047439e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004743a5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004743a7  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004743ae  bb78b95100             -mov ebx, 0x51b978
    cpu.ebx = 5355896 /*0x51b978*/;
    // 004743b3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004743b6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004743b8  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 004743be  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004743c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743c5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004743c6:
    // 004743c6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004743c9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004743cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004743cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004743cf  e89c020000             -call 0x474670
    cpu.esp -= 4;
    sub_474670(app, cpu);
    if (cpu.terminate) return;
    // 004743d4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004743d7  c7808400000009000000   -mov dword ptr [eax + 0x84], 9
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 9 /*0x9*/;
    // 004743e1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004743e4  66c780880000000300     -mov word ptr [eax + 0x88], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(136) /* 0x88 */) = 3 /*0x3*/;
    // 004743ed  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004743f0  66c7808a0000000200     -mov word ptr [eax + 0x8a], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(138) /* 0x8a */) = 2 /*0x2*/;
    // 004743f9  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004743fe  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474401  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00474404  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047440b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047440d  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00474414  bb18b95100             -mov ebx, 0x51b918
    cpu.ebx = 5355800 /*0x51b918*/;
    // 00474419  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047441c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047441e  89989c000000           -mov dword ptr [eax + 0x9c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = cpu.ebx;
    // 00474424  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474427  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474428  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474429  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047442a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047442b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047442c:
    // 0047442c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00474431  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00474434  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00474436  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00474438  e833020000             -call 0x474670
    cpu.esp -= 4;
    sub_474670(app, cpu);
    if (cpu.terminate) return;
    // 0047443d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474440  c7808400000009000000   -mov dword ptr [eax + 0x84], 9
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 9 /*0x9*/;
    // 0047444a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047444d  66c780880000000300     -mov word ptr [eax + 0x88], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(136) /* 0x88 */) = 3 /*0x3*/;
    // 00474456  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474459  66c7808a0000000200     -mov word ptr [eax + 0x8a], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(138) /* 0x8a */) = 2 /*0x2*/;
    // 00474462  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00474467  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047446a  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047446d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00474474  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474476  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0047447d  bb18b95100             -mov ebx, 0x51b918
    cpu.ebx = 5355800 /*0x51b918*/;
    // 00474482  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474485  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00474487  89989c000000           -mov dword ptr [eax + 0x9c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = cpu.ebx;
    // 0047448d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474490  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474491  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474492  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474493  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474494  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00474495:
    // 00474495  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0047449a  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047449d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047449f  8d5820                 -lea ebx, [eax + 0x20]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004744a2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004744a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004744a7  e8b4050000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 004744ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004744af  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 004744b9  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004744be  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004744c1  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004744c3  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004744c6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004744cd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004744cf  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004744d6  bbb8b85100             -mov ebx, 0x51b8b8
    cpu.ebx = 5355704 /*0x51b8b8*/;
    // 004744db  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004744de  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004744e0  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 004744e6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004744e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744ed  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004744ee:
    // 004744ee  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004744f3  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004744f6  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004744f8  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004744fb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004744fe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00474500  e85b050000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 00474505  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474508  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 00474512  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00474517  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047451a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047451c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047451e  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 00474521  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00474524  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047452b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047452d  bb78b95100             -mov ebx, 0x51b978
    cpu.ebx = 5355896 /*0x51b978*/;
    // 00474532  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00474535  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00474538  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047453a  899acc000000           -mov dword ptr [edx + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00474540  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474543  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474544  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474545  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474546  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474547  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00474548:
    // 00474548  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047454b  c780a800000004000000   -mov dword ptr [eax + 0xa8], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4 /*0x4*/;
    // 00474555  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047455a  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047455d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047455f  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00474562  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00474565  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00474567  e8f4040000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 0047456c  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00474571  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474574  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00474576  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047457b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047457d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474580  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474582  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00474589  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047458b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00474592  bb04ba5100             -mov ebx, 0x51ba04
    cpu.ebx = 5356036 /*0x51ba04*/;
    // 00474597  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047459a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047459c  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 004745a2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004745a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745a9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004745aa:
    // 004745aa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004745ad  c780a800000004000000   -mov dword ptr [eax + 0xa8], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4 /*0x4*/;
    // 004745b7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004745bc  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004745bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004745c1  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004745c3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004745c6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004745c9  e892040000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 004745ce  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004745d3  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004745d6  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004745d8  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004745dd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004745df  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004745e2  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004745e4  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004745eb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004745ed  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004745f4  bbdcb95100             -mov ebx, 0x51b9dc
    cpu.ebx = 5355996 /*0x51b9dc*/;
    // 004745f9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004745fc  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004745fe  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00474604  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474609  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047460a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047460b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047460c:
    // 0047460c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047460f  c780a800000004000000   -mov dword ptr [eax + 0xa8], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4 /*0x4*/;
    // 00474619  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047461e  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474621  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474623  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00474626  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00474629  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047462b  e830040000             -call 0x474a60
    cpu.esp -= 4;
    sub_474a60(app, cpu);
    if (cpu.terminate) return;
    // 00474630  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00474635  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00474638  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047463a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047463f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474641  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474644  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474646  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047464d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047464f  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00474656  bb2cba5100             -mov ebx, 0x51ba2c
    cpu.ebx = 5356076 /*0x51ba2c*/;
    // 0047465b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047465e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00474660  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00474666  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474669  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047466a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047466b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047466c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047466d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_474670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474671  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474673  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00474676  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0047467a  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0047467e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00474680  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00474682  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00474686  8d761c                 -lea esi, [esi + 0x1c]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00474689  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047468d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047468e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047468f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00474690  e85b79fdff             -call 0x44bff0
    cpu.esp -= 4;
    sub_44bff0(app, cpu);
    if (cpu.terminate) return;
    // 00474695  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00474699  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047469d  83c644                 -add esi, 0x44
    (cpu.esi) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004746a0  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004746a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004746a5  0f84b4020000           -je 0x47495f
    if (cpu.flags.zf)
    {
        goto L_0x0047495f;
    }
    // 004746ab  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004746af  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004746b2  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004746b4  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004746b6  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004746ba  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004746be  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004746c1  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004746c3  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004746c5  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004746c9  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004746cd  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004746d0  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004746d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004746d4  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004746d6  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004746d8  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004746dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004746de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004746df  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004746e4  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004746e8  e833b3ffff             -call 0x46fa20
    cpu.esp -= 4;
    sub_46fa20(app, cpu);
    if (cpu.terminate) return;
    // 004746ed  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004746f1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004746f5  2b412c                 -sub eax, dword ptr [ecx + 0x2c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */)));
    // 004746f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004746fa  0f8e4d020000           -jle 0x47494d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047494d;
    }
L_0x00474700:
    // 00474700  3d00800000             +cmp eax, 0x8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474705  7d1d                   -jge 0x474724
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474724;
    }
    // 00474707  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047470b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047470f  8b792c                 -mov edi, dword ptr [ecx + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00474712  39f8                   +cmp eax, edi
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
    // 00474714  0f8e3a020000           -jle 0x474954
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474954;
    }
    // 0047471a  8d8700800000           -lea eax, [edi + 0x8000]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(32768) /* 0x8000 */);
L_0x00474720:
    // 00474720  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00474724:
    // 00474724  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00474728  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0047472b  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00474730  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00474733  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00474737  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0047473a  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047473d  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00474741  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00474744  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00474747  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047474b  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0047474e  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 00474753  894560                 -mov dword ptr [ebp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00474756  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047475a  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0047475d  894564                 -mov dword ptr [ebp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00474760  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00474764  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00474767  894568                 -mov dword ptr [ebp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0047476a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047476d  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00474772  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00474775  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474779  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047477c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474780  894528                 -mov dword ptr [ebp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00474783  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474786  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 0047478b  894540                 -mov dword ptr [ebp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0047478e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00474792:
    // 00474792  894544                 -mov dword ptr [ebp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00474795  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474799  894548                 -mov dword ptr [ebp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0047479c  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004747a2  66c7452c0000           -mov word ptr [ebp + 0x2c], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004747a8  66c7454c0000           -mov word ptr [ebp + 0x4c], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004747ae  8d7d10                 -lea edi, [ebp + 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004747b1  66c7456c0000           -mov word ptr [ebp + 0x6c], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(108) /* 0x6c */) = 0 /*0x0*/;
    // 004747b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004747b9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004747bb  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004747bd  a380a44c00             -mov dword ptr [0x4ca480], eax
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.eax;
    // 004747c2  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004747c6  7e2a                   -jle 0x4747f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004747f2;
    }
    // 004747c8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004747ca  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 004747d0  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004747d3  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 004747d9  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004747db  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004747de  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 004747e4  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004747e7  030574a44c00           +add eax, dword ptr [0x4ca474]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004747ed  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004747f0  eb14                   -jmp 0x474806
    goto L_0x00474806;
L_0x004747f2:
    // 004747f2  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004747f8  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004747ff  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00474806:
    // 00474806  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 0047480c  8d7d30                 -lea edi, [ebp + 0x30]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0047480f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474811  6689450e               -mov word ptr [ebp + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00474815  8d4520                 -lea eax, [ebp + 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00474818  891580a44c00           -mov dword ptr [0x4ca480], edx
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.edx;
    // 0047481e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00474820  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00474824  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474828  7e2a                   -jle 0x474854
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474854;
    }
    // 0047482a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047482c  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 00474832  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474835  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 0047483b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047483d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00474840  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 00474846  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474849  030574a44c00           +add eax, dword ptr [0x4ca474]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047484f  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00474852  eb14                   -jmp 0x474868
    goto L_0x00474868;
L_0x00474854:
    // 00474854  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 0047485a  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00474861  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00474868:
    // 00474868  8d7d50                 -lea edi, [ebp + 0x50]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(80) /* 0x50 */);
    // 0047486b  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 00474871  8d5d40                 -lea ebx, [ebp + 0x40]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(64) /* 0x40 */);
    // 00474874  890d80a44c00           -mov dword ptr [0x4ca480], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.ecx;
    // 0047487a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047487c  6689452e               -mov word ptr [ebp + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 00474880  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474884  7e2a                   -jle 0x4748b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004748b0;
    }
    // 00474886  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00474888  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 0047488e  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474891  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 00474897  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00474899  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047489c  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 004748a2  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004748a5  030574a44c00           +add eax, dword ptr [0x4ca474]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004748ab  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004748ae  eb14                   -jmp 0x4748c4
    goto L_0x004748c4;
L_0x004748b0:
    // 004748b0  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004748b6  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004748bd  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004748c4:
    // 004748c4  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 004748ca  8d7d70                 -lea edi, [ebp + 0x70]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(112) /* 0x70 */);
    // 004748cd  890d80a44c00           -mov dword ptr [0x4ca480], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.ecx;
    // 004748d3  8d4d60                 -lea ecx, [ebp + 0x60]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
    // 004748d6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004748d8  6689454e               -mov word ptr [ebp + 0x4e], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(78) /* 0x4e */) = cpu.ax;
    // 004748dc  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004748e0  7e2a                   -jle 0x47490c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047490c;
    }
    // 004748e2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004748e4  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 004748ea  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004748ed  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 004748f3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004748f5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004748f8  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 004748fe  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474901  030574a44c00           +add eax, dword ptr [0x4ca474]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00474907  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047490a  eb14                   -jmp 0x474920
    goto L_0x00474920;
L_0x0047490c:
    // 0047490c  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00474912  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00474919  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00474920:
    // 00474920  89ad8c000000           -mov dword ptr [ebp + 0x8c], ebp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */) = cpu.ebp;
    // 00474926  899d94000000           -mov dword ptr [ebp + 0x94], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(148) /* 0x94 */) = cpu.ebx;
    // 0047492c  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 00474932  898d98000000           -mov dword ptr [ebp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00474938  6689456e               -mov word ptr [ebp + 0x6e], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.ax;
    // 0047493c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00474940  898590000000           -mov dword ptr [ebp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00474946  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00474949  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047494a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047494b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047494c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047494d:
    // 0047494d  f7d8                   +neg eax
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
    // 0047494f  e9acfdffff             -jmp 0x474700
    goto L_0x00474700;
L_0x00474954:
    // 00474954  8d870080ffff           -lea eax, [edi - 0x8000]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-32768) /* -0x8000 */);
    // 0047495a  e9c1fdffff             -jmp 0x474720
    goto L_0x00474720;
L_0x0047495f:
    // 0047495f  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00474963  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00474966  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00474969  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047496b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047496f  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00474973  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00474976  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00474979  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047497b  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047497f  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00474983  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00474986  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00474989  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047498b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047498d  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0047498f  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00474993  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00474995  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474996  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047499b  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047499f  e87cb0ffff             -call 0x46fa20
    cpu.esp -= 4;
    sub_46fa20(app, cpu);
    if (cpu.terminate) return;
    // 004749a4  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004749a8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004749ab  2b4128                 -sub eax, dword ptr [ecx + 0x28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
    // 004749ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004749b0  0f8e95000000           -jle 0x474a4b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474a4b;
    }
L_0x004749b6:
    // 004749b6  3d00800000             +cmp eax, 0x8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004749bb  7d1b                   -jge 0x4749d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004749d8;
    }
    // 004749bd  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004749c1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004749c4  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004749c7  39d8                   +cmp eax, ebx
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
    // 004749c9  0f8e83000000           -jle 0x474a52
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474a52;
    }
    // 004749cf  8d8300800000           -lea eax, [ebx + 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */);
L_0x004749d5:
    // 004749d5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004749d8:
    // 004749d8  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004749dc  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004749df  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004749e2  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004749e6  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004749e9  05cc4c0000             -add eax, 0x4ccc
    (cpu.eax) += x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
    // 004749ee  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004749f1  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004749f5  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004749f8  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004749fb  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004749ff  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00474a02  894560                 -mov dword ptr [ebp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00474a05  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00474a09  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00474a0c  2dcc4c0000             -sub eax, 0x4ccc
    (cpu.eax) -= x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
    // 00474a11  894564                 -mov dword ptr [ebp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00474a14  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00474a18  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00474a1b  894568                 -mov dword ptr [ebp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00474a1e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474a21  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00474a24  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474a28  05cc4c0000             -add eax, 0x4ccc
    (cpu.eax) += x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
    // 00474a2d  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00474a30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474a34  894528                 -mov dword ptr [ebp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00474a37  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474a3a  894540                 -mov dword ptr [ebp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00474a3d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474a41  2dcc4c0000             +sub eax, 0x4ccc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00474a46  e947fdffff             -jmp 0x474792
    goto L_0x00474792;
L_0x00474a4b:
    // 00474a4b  f7d8                   +neg eax
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
    // 00474a4d  e964ffffff             -jmp 0x4749b6
    goto L_0x004749b6;
L_0x00474a52:
    // 00474a52  8d830080ffff           -lea eax, [ebx - 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-32768) /* -0x8000 */);
    // 00474a58  e978ffffff             -jmp 0x4749d5
    goto L_0x004749d5;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_474a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474a60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474a61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474a62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474a63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474a64  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474a67  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00474a69  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00474a6b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00474a6d  81783000000100         +cmp dword ptr [eax + 0x30], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a74  0f8c63010000           -jl 0x474bdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474bdd;
    }
L_0x00474a7a:
    // 00474a7a  813d78a44c00f4010000   +cmp dword ptr [0x4ca478], 0x1f4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a84  0f8e5f010000           -jle 0x474be9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474be9;
    }
    // 00474a8a  ba99990100             -mov edx, 0x19999
    cpu.edx = 104857 /*0x19999*/;
    // 00474a8f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00474a91  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474a93  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474a96  c1e810                 +shr eax, 0x10
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
    // 00474a99  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474a9b  6689442408             -mov word ptr [esp + 8], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00474aa0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00474aa2:
    // 00474aa2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00474aa5  0fbfea                 -movsx ebp, dx
    cpu.ebp = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00474aa8  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00474aae  c0e507                 +shl ch, 7
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
    // 00474ab1  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474ab3  00ed                   +add ch, ch
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
    // 00474ab5  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00474ab7  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474ab9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00474abe  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474ac0  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00474ac7  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474ac9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474acb  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474acd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474acf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474ad2  c1e810                 +shr eax, 0x10
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
    // 00474ad5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474ad7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00474ada  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00474add  c0e407                 +shl ah, 7
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
    // 00474ae0  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474ae2  00e4                   +add ah, ah
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
    // 00474ae4  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00474ae6  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474ae8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00474aed  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474aef  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00474af6  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474af8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474afa  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474afc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474afe  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474b01  c1e810                 +shr eax, 0x10
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
    // 00474b04  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474b06  8b6c2406               -mov ebp, dword ptr [esp + 6]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00474b0a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00474b0c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00474b0f  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00474b12  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00474b18  c0e507                 +shl ch, 7
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
    // 00474b1b  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474b1d  00ed                   +add ch, ch
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
    // 00474b1f  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00474b21  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474b23  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00474b28  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474b2a  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00474b31  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474b33  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474b35  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474b37  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474b39  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474b3c  c1e810                 +shr eax, 0x10
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
    // 00474b3f  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474b41  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00474b45  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00474b48  c0e407                 +shl ah, 7
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
    // 00474b4b  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474b4d  00e4                   +add ah, ah
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
    // 00474b4f  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00474b51  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474b53  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00474b58  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474b5a  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00474b61  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474b63  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474b65  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474b67  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474b69  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474b6c  c1e810                 +shr eax, 0x10
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
    // 00474b6f  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474b71  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00474b74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474b76  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00474b79  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00474b7b  8987c4000000           -mov dword ptr [edi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00474b81  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00474b84  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00474b86  8987c8000000           -mov dword ptr [edi + 0xc8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(200) /* 0xc8 */) = cpu.eax;
    // 00474b8c  8b6e38                 -mov ebp, dword ptr [esi + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00474b8f  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00474b91  89afbc000000           -mov dword ptr [edi + 0xbc], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */) = cpu.ebp;
    // 00474b97  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474b9b  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00474b9e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474ba0  8987c0000000           -mov dword ptr [edi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00474ba6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00474ba9  8b6e38                 -mov ebp, dword ptr [esi + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00474bac  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474bae  89afb4000000           -mov dword ptr [edi + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00474bb4  8b6e3c                 -mov ebp, dword ptr [esi + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00474bb7  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474bb9  89afb8000000           -mov dword ptr [edi + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
    // 00474bbf  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00474bc2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474bc4  8987ac000000           -mov dword ptr [edi + 0xac], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 00474bca  8b763c                 -mov esi, dword ptr [esi + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00474bcd  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00474bcf  89b7b0000000           -mov dword ptr [edi + 0xb0], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(176) /* 0xb0 */) = cpu.esi;
    // 00474bd5  83c40c                 +add esp, 0xc
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
    // 00474bd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bd9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bdb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474bdd:
    // 00474bdd  c7403000000100         -mov dword ptr [eax + 0x30], 0x10000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 65536 /*0x10000*/;
    // 00474be4  e991feffff             -jmp 0x474a7a
    goto L_0x00474a7a;
L_0x00474be9:
    // 00474be9  a1d8b95100             -mov eax, dword ptr [0x51b9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355992) /* 0x51b9d8 */);
    // 00474bee  8b5e30                 -mov ebx, dword ptr [esi + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00474bf1  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00474bf2  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474bf4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00474bf6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474bf8  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00474bfc  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00474bff  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474c01  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00474c04  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00474c06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474c08  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00474c0a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474c0c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474c0f  c1e810                 +shr eax, 0x10
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
    // 00474c12  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474c14  8a0d51ba5100           -mov cl, byte ptr [0x51ba51]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5356113) /* 0x51ba51 */);
    // 00474c1a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474c1c  66d3fa                 -sar dx, cl
    cpu.dx = x86::reg16(x86::sreg16(cpu.dx) >> (cpu.cl % 32));
    // 00474c1f  8a0d50ba5100           -mov cl, byte ptr [0x51ba50]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5356112) /* 0x51ba50 */);
    // 00474c25  66d3f8                 +sar ax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg16(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg16(x86::sreg16(op) >> tmp)));
        }
    }
    // 00474c28  6689442408             -mov word ptr [esp + 8], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00474c2d  e970feffff             -jmp 0x474aa2
    goto L_0x00474aa2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474c40  881551ba5100           -mov byte ptr [0x51ba51], dl
    app->getMemory<x86::reg8>(x86::reg32(5356113) /* 0x51ba51 */) = cpu.dl;
    // 00474c46  8b04854ca34c00         -mov eax, dword ptr [eax*4 + 0x4ca34c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022540) /* 0x4ca34c */ + cpu.eax * 4);
    // 00474c4d  881d50ba5100           -mov byte ptr [0x51ba50], bl
    app->getMemory<x86::reg8>(x86::reg32(5356112) /* 0x51ba50 */) = cpu.bl;
    // 00474c53  a3d8b95100             -mov dword ptr [0x51b9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5355992) /* 0x51b9d8 */) = cpu.eax;
    // 00474c58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474c60  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00474c65  e8225a0000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00474c6a  a100ba5100             -mov eax, dword ptr [0x51ba00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356032) /* 0x51ba00 */);
    // 00474c6f  e9185a0000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474c80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474c81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474c82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474c83  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00474c88  bb78b95100             -mov ebx, 0x51b978
    cpu.ebx = 5355896 /*0x51b978*/;
    // 00474c8d  b8d8f84b00             -mov eax, 0x4bf8d8
    cpu.eax = 4978904 /*0x4bf8d8*/;
    // 00474c92  8b1500ba5100           -mov edx, dword ptr [0x51ba00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356032) /* 0x51ba00 */);
    // 00474c98  e833010000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474c9d  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00474ca2  bbb8b85100             -mov ebx, 0x51b8b8
    cpu.ebx = 5355704 /*0x51b8b8*/;
    // 00474ca7  b8dcf84b00             -mov eax, 0x4bf8dc
    cpu.eax = 4978908 /*0x4bf8dc*/;
    // 00474cac  8b1500ba5100           -mov edx, dword ptr [0x51ba00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356032) /* 0x51ba00 */);
    // 00474cb2  e819010000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474cb7  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00474cbc  bb04ba5100             -mov ebx, 0x51ba04
    cpu.ebx = 5356036 /*0x51ba04*/;
    // 00474cc1  b8e0f84b00             -mov eax, 0x4bf8e0
    cpu.eax = 4978912 /*0x4bf8e0*/;
    // 00474cc6  8b1528ba5100           -mov edx, dword ptr [0x51ba28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00474ccc  e8ff000000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474cd1  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00474cd6  bbdcb95100             -mov ebx, 0x51b9dc
    cpu.ebx = 5355996 /*0x51b9dc*/;
    // 00474cdb  b8e4f84b00             -mov eax, 0x4bf8e4
    cpu.eax = 4978916 /*0x4bf8e4*/;
    // 00474ce0  8b1528ba5100           -mov edx, dword ptr [0x51ba28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00474ce6  e8e5000000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474ceb  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00474cf0  bb2cba5100             -mov ebx, 0x51ba2c
    cpu.ebx = 5356076 /*0x51ba2c*/;
    // 00474cf5  b8e8f84b00             -mov eax, 0x4bf8e8
    cpu.eax = 4978920 /*0x4bf8e8*/;
    // 00474cfa  8b1528ba5100           -mov edx, dword ptr [0x51ba28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00474d00  e8cb000000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474d05  833d3cf54d0008         +cmp dword ptr [0x4df53c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474d0c  751e                   -jne 0x474d2c
    if (!cpu.flags.zf)
    {
        goto L_0x00474d2c;
    }
    // 00474d0e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00474d13  bb18b95100             -mov ebx, 0x51b918
    cpu.ebx = 5355800 /*0x51b918*/;
    // 00474d18  b8ecf84b00             -mov eax, 0x4bf8ec
    cpu.eax = 4978924 /*0x4bf8ec*/;
    // 00474d1d  8b1528ba5100           -mov edx, dword ptr [0x51ba28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00474d23  e8a8000000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474d28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474d2c:
    // 00474d2c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00474d31  bb18b95100             -mov ebx, 0x51b918
    cpu.ebx = 5355800 /*0x51b918*/;
    // 00474d36  b8f0f84b00             -mov eax, 0x4bf8f0
    cpu.eax = 4978928 /*0x4bf8f0*/;
    // 00474d3b  8b1528ba5100           -mov edx, dword ptr [0x51ba28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00474d41  e88a000000             -call 0x474dd0
    cpu.esp -= 4;
    sub_474dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474d46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474d50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474d51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474d52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474d53  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00474d59  8b15b8074e00           -mov edx, dword ptr [0x4e07b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113784) /* 0x4e07b8 */);
    // 00474d5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474d60  68bcf84b00             -push 0x4bf8bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978876 /*0x4bf8bc*/;
    cpu.esp -= 4;
    // 00474d65  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474d69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474d6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474d6c  e870720000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00474d71  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474d74  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474d76  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474d78  e8078c0000             -call 0x47d984
    cpu.esp -= 4;
    sub_47d984(app, cpu);
    if (cpu.terminate) return;
    // 00474d7d  a328ba5100             -mov dword ptr [0x51ba28], eax
    app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */) = cpu.eax;
    // 00474d82  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474d84  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00474d89  e832010000             -call 0x474ec0
    cpu.esp -= 4;
    sub_474ec0(app, cpu);
    if (cpu.terminate) return;
    // 00474d8e  8b0db8074e00           -mov ecx, dword ptr [0x4e07b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113784) /* 0x4e07b8 */);
    // 00474d94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474d95  68c8f84b00             -push 0x4bf8c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978888 /*0x4bf8c8*/;
    cpu.esp -= 4;
    // 00474d9a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474d9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474d9f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474da1  e83b720000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00474da6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474da9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474dab  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00474db0  e8cf8b0000             -call 0x47d984
    cpu.esp -= 4;
    sub_47d984(app, cpu);
    if (cpu.terminate) return;
    // 00474db5  a300ba5100             -mov dword ptr [0x51ba00], eax
    app->getMemory<x86::reg32>(x86::reg32(5356032) /* 0x51ba00 */) = cpu.eax;
    // 00474dba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474dbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00474dbe  e8fd000000             -call 0x474ec0
    cpu.esp -= 4;
    sub_474ec0(app, cpu);
    if (cpu.terminate) return;
    // 00474dc3  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00474dc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474dca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474dcb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474dcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_474dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474dd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474dd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474dd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474dd3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474dd6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00474dda  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00474ddc  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00474de0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00474de2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474de4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474de6  7e38                   -jle 0x474e20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474e20;
    }
    // 00474de8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00474dea:
    // 00474dea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474deb  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474def  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474df0  68b4f84b00             -push 0x4bf8b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978868 /*0x4bf8b4*/;
    cpu.esp -= 4;
    // 00474df5  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474df9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474dfa  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00474dfc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474dfe  e8de710000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00474e03  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00474e07  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474e0a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00474e0c  46                     -inc esi
    (cpu.esi)++;
    // 00474e0d  e84e040000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474e12  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474e16  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474e19  39c6                   +cmp esi, eax
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
    // 00474e1b  7ccd                   -jl 0x474dea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474dea;
    }
    // 00474e1d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00474e20:
    // 00474e20  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474e23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474e30  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474e35  e852580000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00474e3a  e8d15effff             -call 0x46ad10
    cpu.esp -= 4;
    sub_46ad10(app, cpu);
    if (cpu.terminate) return;
    // 00474e3f  e91cfeffff             -jmp 0x474c60
    return sub_474c60(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474e50  e8cb5effff             -call 0x46ad20
    cpu.esp -= 4;
    sub_46ad20(app, cpu);
    if (cpu.terminate) return;
    // 00474e55  e8a660ffff             -call 0x46af00
    cpu.esp -= 4;
    sub_46af00(app, cpu);
    if (cpu.terminate) return;
    // 00474e5a  e871b3ffff             -call 0x4701d0
    cpu.esp -= 4;
    sub_4701d0(app, cpu);
    if (cpu.terminate) return;
    // 00474e5f  e99c84ffff             -jmp 0x46d300
    return sub_46d300(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474e70  e85b000000             -call 0x474ed0
    cpu.esp -= 4;
    sub_474ed0(app, cpu);
    if (cpu.terminate) return;
    // 00474e75  e906feffff             -jmp 0x474c80
    return sub_474c80(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474e80  e88b9effff             -call 0x46ed10
    cpu.esp -= 4;
    sub_46ed10(app, cpu);
    if (cpu.terminate) return;
    // 00474e85  e85685ffff             -call 0x46d3e0
    cpu.esp -= 4;
    sub_46d3e0(app, cpu);
    if (cpu.terminate) return;
    // 00474e8a  e80185ffff             -call 0x46d390
    cpu.esp -= 4;
    sub_46d390(app, cpu);
    if (cpu.terminate) return;
    // 00474e8f  e80c84ffff             -call 0x46d2a0
    cpu.esp -= 4;
    sub_46d2a0(app, cpu);
    if (cpu.terminate) return;
    // 00474e94  e8a760ffff             -call 0x46af40
    cpu.esp -= 4;
    sub_46af40(app, cpu);
    if (cpu.terminate) return;
    // 00474e99  e82281ffff             -call 0x46cfc0
    cpu.esp -= 4;
    sub_46cfc0(app, cpu);
    if (cpu.terminate) return;
    // 00474e9e  e95d9effff             -jmp 0x46ed00
    return sub_46ed00(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474eb0  e91b87ffff             -jmp 0x46d5d0
    return sub_46d5d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474ec0  e9cb87ffff             -jmp 0x46d690
    return sub_46d690(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474ed2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474ed3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474ed4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474ed5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474ed6  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00474edc  be54ba5100             -mov esi, 0x51ba54
    cpu.esi = 5356116 /*0x51ba54*/;
    // 00474ee1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00474ee3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00474ee5:
    // 00474ee5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474ee6  6804f94b00             -push 0x4bf904
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978948 /*0x4bf904*/;
    cpu.esp -= 4;
    // 00474eeb  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474eef  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474ef3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474ef4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00474ef6  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474ef9  e8e3700000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00474efe  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00474f04  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474f07  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474f0c  47                     -inc edi
    (cpu.edi)++;
    // 00474f0d  e84e030000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474f12  89b538bb5100           -mov dword ptr [ebp + 0x51bb38], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5356344) /* 0x51bb38 */) = cpu.esi;
    // 00474f18  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474f1b  83ff08                 +cmp edi, 8
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
    // 00474f1e  7cc5                   -jl 0x474ee5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474ee5;
    }
    // 00474f20  b9b4ba5100             -mov ecx, 0x51bab4
    cpu.ecx = 5356212 /*0x51bab4*/;
    // 00474f25  ba0cf94b00             -mov edx, 0x4bf90c
    cpu.edx = 4978956 /*0x4bf90c*/;
    // 00474f2a  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00474f30  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474f35  e826030000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474f3a  bab4ba5100             -mov edx, 0x51bab4
    cpu.edx = 5356212 /*0x51bab4*/;
    // 00474f3f  b9c0ba5100             -mov ecx, 0x51bac0
    cpu.ecx = 5356224 /*0x51bac0*/;
    // 00474f44  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00474f4a  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474f4f  891580bb5100           -mov dword ptr [0x51bb80], edx
    app->getMemory<x86::reg32>(x86::reg32(5356416) /* 0x51bb80 */) = cpu.edx;
    // 00474f55  ba14f94b00             -mov edx, 0x4bf914
    cpu.edx = 4978964 /*0x4bf914*/;
    // 00474f5a  bed8ba5100             -mov esi, 0x51bad8
    cpu.esi = 5356248 /*0x51bad8*/;
    // 00474f5f  e8fc020000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474f64  b9c0ba5100             -mov ecx, 0x51bac0
    cpu.ecx = 5356224 /*0x51bac0*/;
    // 00474f69  ba1cf94b00             -mov edx, 0x4bf91c
    cpu.edx = 4978972 /*0x4bf91c*/;
    // 00474f6e  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00474f74  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474f79  890d2cbb5100           -mov dword ptr [0x51bb2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5356332) /* 0x51bb2c */) = cpu.ecx;
    // 00474f7f  b9ccba5100             -mov ecx, 0x51bacc
    cpu.ecx = 5356236 /*0x51bacc*/;
    // 00474f84  bfe4ba5100             -mov edi, 0x51bae4
    cpu.edi = 5356260 /*0x51bae4*/;
    // 00474f89  e8d2020000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474f8e  bbccba5100             -mov ebx, 0x51bacc
    cpu.ebx = 5356236 /*0x51bacc*/;
    // 00474f93  b9d8ba5100             -mov ecx, 0x51bad8
    cpu.ecx = 5356248 /*0x51bad8*/;
    // 00474f98  ba24f94b00             -mov edx, 0x4bf924
    cpu.edx = 4978980 /*0x4bf924*/;
    // 00474f9d  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474fa2  891d30bb5100           -mov dword ptr [0x51bb30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5356336) /* 0x51bb30 */) = cpu.ebx;
    // 00474fa8  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00474fae  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00474fb0  e8ab020000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474fb5  b9e4ba5100             -mov ecx, 0x51bae4
    cpu.ecx = 5356260 /*0x51bae4*/;
    // 00474fba  ba2cf94b00             -mov edx, 0x4bf92c
    cpu.edx = 4978988 /*0x4bf92c*/;
    // 00474fbf  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00474fc5  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00474fca  893534bb5100           -mov dword ptr [0x51bb34], esi
    app->getMemory<x86::reg32>(x86::reg32(5356340) /* 0x51bb34 */) = cpu.esi;
    // 00474fd0  e88b020000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00474fd5  be54ba5100             -mov esi, 0x51ba54
    cpu.esi = 5356116 /*0x51ba54*/;
    // 00474fda  893d38bb5100           -mov dword ptr [0x51bb38], edi
    app->getMemory<x86::reg32>(x86::reg32(5356344) /* 0x51bb38 */) = cpu.edi;
    // 00474fe0  81c69c000000           -add esi, 0x9c
    (cpu.esi) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 00474fe6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00474fe8:
    // 00474fe8  47                     -inc edi
    (cpu.edi)++;
    // 00474fe9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474fea  6834f94b00             -push 0x4bf934
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978996 /*0x4bf934*/;
    cpu.esp -= 4;
    // 00474fef  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474ff3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474ff4  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474ff8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00474ffa  e8e26f0000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00474fff  8b1d5cbb5100           -mov ebx, dword ptr [0x51bb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 00475005  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475008  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 0047500d  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475010  e84b020000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475015  89b568bb5100           -mov dword ptr [ebp + 0x51bb68], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5356392) /* 0x51bb68 */) = cpu.esi;
    // 0047501b  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047501e  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475021  7cc5                   -jl 0x474fe8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474fe8;
    }
    // 00475023  bd54ba5100             -mov ebp, 0x51ba54
    cpu.ebp = 5356116 /*0x51ba54*/;
    // 00475028  ba3cf94b00             -mov edx, 0x4bf93c
    cpu.edx = 4979004 /*0x4bf93c*/;
    // 0047502d  a168bb5100             -mov eax, dword ptr [0x51bb68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */);
    // 00475032  892d84bb5100           -mov dword ptr [0x51bb84], ebp
    app->getMemory<x86::reg32>(x86::reg32(5356420) /* 0x51bb84 */) = cpu.ebp;
    // 00475038  e827390000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 0047503d  a364bb5100             -mov dword ptr [0x51bb64], eax
    app->getMemory<x86::reg32>(x86::reg32(5356388) /* 0x51bb64 */) = cpu.eax;
    // 00475042  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00475048  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475049  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047504a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047504b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047504c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047504d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047504e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_475050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475051  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475052  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00475058  8b15b8074e00           -mov edx, dword ptr [0x4e07b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113784) /* 0x4e07b8 */);
    // 0047505e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047505f  68f4f84b00             -push 0x4bf8f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4978932 /*0x4bf8f4*/;
    cpu.esp -= 4;
    // 00475064  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475068  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475069  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047506b  e8716f0000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00475070  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475073  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475075  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047507a  e8e1770000             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 0047507f  a368bb5100             -mov dword ptr [0x51bb68], eax
    app->getMemory<x86::reg32>(x86::reg32(5356392) /* 0x51bb68 */) = cpu.eax;
    // 00475084  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475086  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047508b  e80086ffff             -call 0x46d690
    cpu.esp -= 4;
    sub_46d690(app, cpu);
    if (cpu.terminate) return;
    // 00475090  a35cbb5100             -mov dword ptr [0x51bb5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */) = cpu.eax;
    // 00475095  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0047509b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047509c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047509d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4750b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004750b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004750b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004750b6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004750b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004750ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004750bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004750bc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004750bd  83fa04                 +cmp edx, 4
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
    // 004750c0  771f                   -ja 0x4750e1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004750e1;
    }
    // 004750c2  ff2495a0504700         -jmp dword ptr [edx*4 + 0x4750a0]
    cpu.ip = app->getMemory<x86::reg32>(4673696 + cpu.edx * 4); goto dynamic_jump;
  case 0x004750c9:
    // 004750c9  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004750cc  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004750cf  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004750d2  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004750d5  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004750d8  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004750db  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004750de  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
L_0x004750e1:
    // 004750e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750e3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004750e4:
    // 004750e4  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004750e7  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004750ea  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004750ed  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004750f0  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004750f3  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004750f6  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004750f9  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004750fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750fe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004750ff:
    // 004750ff  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475102  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00475105  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475108  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0047510b  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047510e  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00475111  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00475114  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00475117  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475118  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475119  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047511a:
    // 0047511a  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047511d  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00475120  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475123  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00475126  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475129  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047512c  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047512f  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00475132  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475133  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475134  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00475135:
    // 00475135  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00475138  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047513b  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047513e  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00475141  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475144  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00475147  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047514a  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047514d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047514e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047514f  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_475164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00475164  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475165  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475166  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475167  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00475169  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047516b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047516c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047516d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047516e  83fa04                 +cmp edx, 4
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
    // 00475171  771f                   -ja 0x475192
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475192;
    }
    // 00475173  ff249550514700         -jmp dword ptr [edx*4 + 0x475150]
    cpu.ip = app->getMemory<x86::reg32>(4673872 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047517a:
    // 0047517a  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047517d  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00475180  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475183  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00475186  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475189  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047518c  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047518f  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
L_0x00475192:
    // 00475192  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475193  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475194  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475195  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00475196:
    // 00475196  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475199  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047519c  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047519f  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004751a2  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004751a5  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004751a8  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004751ab  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004751ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751b1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004751b2:
    // 004751b2  8a4b05                 -mov cl, byte ptr [ebx + 5]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 004751b5  3a4b04                 +cmp cl, byte ptr [ebx + 4]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004751b8  731c                   -jae 0x4751d6
    if (!cpu.flags.cf)
    {
        goto L_0x004751d6;
    }
L_0x004751ba:
    // 004751ba  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004751bd  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004751c0  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004751c3  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004751c6  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004751c9  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004751cc  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004751cf  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004751d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004751d6:
    // 004751d6  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004751d9  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004751dc  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004751df  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004751e2  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004751e5  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004751e8  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004751eb  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004751ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751f1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004751f2:
    // 004751f2  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004751f5  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004751f8  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004751fb  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004751fe  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475201  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00475204  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00475207  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047520a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047520b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047520c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047520d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047520e:
    // 0047520e  8a5304                 -mov dl, byte ptr [ebx + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00475211  3a5305                 +cmp dl, byte ptr [ebx + 5]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475214  76a4                   -jbe 0x4751ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004751ba;
    }
    // 00475216  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00475219  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047521c  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047521f  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00475222  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475225  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00475228  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047522b  884307                 -mov byte ptr [ebx + 7], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047522e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047522f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475230  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475231  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475240  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475241  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475242  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00475244  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475246  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00475248  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475249  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047524a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047524b  e8f07cffff             -call 0x46cf40
    cpu.esp -= 4;
    sub_46cf40(app, cpu);
    if (cpu.terminate) return;
    // 00475250  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00475253  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475254  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475255  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475260  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475262  751d                   -jne 0x475281
    if (!cpu.flags.zf)
    {
        goto L_0x00475281;
    }
    // 00475264  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
L_0x00475266:
    // 00475266  c6410400               -mov byte ptr [ecx + 4], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0047526a  c6410501               -mov byte ptr [ecx + 5], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 1 /*0x1*/;
    // 0047526e  c6410602               -mov byte ptr [ecx + 6], 2
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = 2 /*0x2*/;
    // 00475272  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475274  c6410703               -mov byte ptr [ecx + 7], 3
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = 3 /*0x3*/;
    // 00475278  e8c37cffff             -call 0x46cf40
    cpu.esp -= 4;
    sub_46cf40(app, cpu);
    if (cpu.terminate) return;
    // 0047527d  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00475280  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475281:
    // 00475281  e8de360000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 00475286  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00475288  ebdc                   -jmp 0x475266
    goto L_0x00475266;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475290  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475291  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475292  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475295  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475297  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 0047529e  7424                   -je 0x4752c4
    if (cpu.flags.zf)
    {
        goto L_0x004752c4;
    }
    // 004752a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004752a1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004752a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004752a7  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004752ab  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004752af  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004752b3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004752b4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004752b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752b6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004752b8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004752ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004752bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004752bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004752be  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004752c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004752c4:
    // 004752c4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004752c6  e85576feff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 004752cb  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004752cd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004752cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004752d0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004752d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004752d3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004752d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4752e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004752e0  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 004752e7  7503                   -jne 0x4752ec
    if (!cpu.flags.zf)
    {
        goto L_0x004752ec;
    }
    // 004752e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004752eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004752ec:
    // 004752ec  8b048590bb5100         -mov eax, dword ptr [eax*4 + 0x51bb90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356432) /* 0x51bb90 */ + cpu.eax * 4);
    // 004752f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475301  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475308  740a                   -je 0x475314
    if (cpu.flags.zf)
    {
        goto L_0x00475314;
    }
    // 0047530a  8b15c8bb5100           -mov edx, dword ptr [0x51bbc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356488) /* 0x51bbc8 */);
    // 00475310  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475312  7502                   -jne 0x475316
    if (!cpu.flags.zf)
    {
        goto L_0x00475316;
    }
L_0x00475314:
    // 00475314  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475316:
    // 00475316  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475318  e86f530000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047531d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047531e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_475320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475321  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00475323  8b1534f34d00           -mov edx, dword ptr [0x4df334]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
    // 00475329  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047532b  7420                   -je 0x47534d
    if (cpu.flags.zf)
    {
        goto L_0x0047534d;
    }
    // 0047532d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047532f  750f                   -jne 0x475340
    if (!cpu.flags.zf)
    {
        goto L_0x00475340;
    }
    // 00475331  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475332  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00475334  bbb4000000             -mov ebx, 0xb4
    cpu.ebx = 180 /*0xb4*/;
L_0x00475339:
    // 00475339  e822000000             -call 0x475360
    cpu.esp -= 4;
    sub_475360(app, cpu);
    if (cpu.terminate) return;
    // 0047533e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047533f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475340:
    // 00475340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475341  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 00475346  bba4010000             -mov ebx, 0x1a4
    cpu.ebx = 420 /*0x1a4*/;
    // 0047534b  ebec                   -jmp 0x475339
    goto L_0x00475339;
L_0x0047534d:
    // 0047534d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047534e  bb68010000             -mov ebx, 0x168
    cpu.ebx = 360 /*0x168*/;
    // 00475353  e808000000             -call 0x475360
    cpu.esp -= 4;
    sub_475360(app, cpu);
    if (cpu.terminate) return;
    // 00475358  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475359  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475360  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475361  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475362  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475363  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00475366  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00475368  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047536b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047536d  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00475371  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00475376  8a2538f54d00           -mov ah, byte ptr [0x4df538]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */);
    // 0047537c  8b0dc8bb5100           -mov ecx, dword ptr [0x51bbc8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356488) /* 0x51bbc8 */);
    // 00475382  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00475386  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00475389  741a                   -je 0x4753a5
    if (cpu.flags.zf)
    {
        goto L_0x004753a5;
    }
    // 0047538b  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475390  7413                   -je 0x4753a5
    if (cpu.flags.zf)
    {
        goto L_0x004753a5;
    }
    // 00475392  833cbd90bb510000       +cmp dword ptr [edi*4 + 0x51bb90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5356432) /* 0x51bb90 */ + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047539a  7409                   -je 0x4753a5
    if (cpu.flags.zf)
    {
        goto L_0x004753a5;
    }
    // 0047539c  833d10104e0000         +cmp dword ptr [0x4e1010], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753a3  7409                   -je 0x4753ae
    if (cpu.flags.zf)
    {
        goto L_0x004753ae;
    }
L_0x004753a5:
    // 004753a5  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004753a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753ab  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004753ae:
    // 004753ae  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004753b0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004753b2  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004753b5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004753b7  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004753ba  8b93d4514c00           -mov edx, dword ptr [ebx + 0x4c51d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5001684) /* 0x4c51d4 */);
    // 004753c0  b8a53c0200             -mov eax, 0x23ca5
    cpu.eax = 146597 /*0x23ca5*/;
    // 004753c5  8b92b8020000           -mov edx, dword ptr [edx + 0x2b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
    // 004753cb  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004753cd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004753d0  c1e810                 +shr eax, 0x10
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
    // 004753d3  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004753d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004753d7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004753da  c1e210                 +shl edx, 0x10
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
    // 004753dd  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004753df  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004753e2  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004753e6  8b9304524c00           -mov edx, dword ptr [ebx + 0x4c5204]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5001732) /* 0x4c5204 */);
    // 004753ec  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 004753f1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004753f3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004753f6  c1e810                 +shr eax, 0x10
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
    // 004753f9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004753fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004753fd  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00475401  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475403  e898090000             -call 0x475da0
    cpu.esp -= 4;
    sub_475da0(app, cpu);
    if (cpu.terminate) return;
    // 00475408  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047540b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047540d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047540f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00475412  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475414  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475416  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475419  c1e210                 +shl edx, 0x10
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
    // 0047541c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047541e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475421  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00475423  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475425  0f8c9e010000           -jl 0x4755c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004755c9;
    }
L_0x0047542b:
    // 0047542b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047542e  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475430  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475432  833cbd90bb510001       +cmp dword ptr [edi*4 + 0x51bb90], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5356432) /* 0x51bb90 */ + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047543a  0f8590010000           -jne 0x4755d0
    if (!cpu.flags.zf)
    {
        goto L_0x004755d0;
    }
    // 00475440  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475442  8d34dd00000000         -lea esi, [ebx*8]
    cpu.esi = x86::reg32(cpu.ebx * 8);
L_0x00475449:
    // 00475449  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047544c  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047544e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00475450  40                     -inc eax
    (cpu.eax)++;
    // 00475451  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00475455  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0047545a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047545c  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00475460  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475463  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00475465  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475469  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047546d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00475474  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475476  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00475479  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047547b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047547f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00475481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475483  0f8e1cffffff           -jle 0x4753a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004753a5;
    }
    // 00475489  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047548d  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047548f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475491  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475494  c1e210                 +shl edx, 0x10
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
    // 00475497  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475499  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047549c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004754a0  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004754a3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004754a6  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004754a8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004754ac  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004754b0:
    // 004754b0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004754b4  0faf442424             -imul eax, dword ptr [esp + 0x24]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 004754b9  83bf90bb510001         +cmp dword ptr [edi + 0x51bb90], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5356432) /* 0x51bb90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004754c0  0f8518010000           -jne 0x4755de
    if (!cpu.flags.zf)
    {
        goto L_0x004755de;
    }
    // 004754c6  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004754c8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004754cb  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004754ce  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004754d1  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004754d5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004754d7  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
L_0x004754dc:
    // 004754dc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004754de  0faf442424             -imul eax, dword ptr [esp + 0x24]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 004754e3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004754e5  0fbf11                 -movsx edx, word ptr [ecx]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx)));
    // 004754e8  39c2                   +cmp edx, eax
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
    // 004754ea  7e30                   -jle 0x47551c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047551c;
    }
    // 004754ec  e83f930000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004754f1  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004754f3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004754f6  241f                   -and al, 0x1f
    cpu.al &= x86::reg8(x86::sreg8(31 /*0x1f*/));
    // 004754f8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004754fa  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004754fd  83bf90bb510001         +cmp dword ptr [edi + 0x51bb90], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5356432) /* 0x51bb90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475504  0f85f2000000           -jne 0x4755fc
    if (!cpu.flags.zf)
    {
        goto L_0x004755fc;
    }
    // 0047550a  e821930000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0047550f  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00475511  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
L_0x00475513:
    // 00475513  0502000000             -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00475518  66894102               -mov word ptr [ecx + 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ax;
L_0x0047551c:
    // 0047551c  837c241c32             +cmp dword ptr [esp + 0x1c], 0x32
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475521  0f8de3000000           -jge 0x47560a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047560a;
    }
    // 00475527  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047552b  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
L_0x0047552e:
    // 0047552e  83bf90bb510001         +cmp dword ptr [edi + 0x51bb90], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5356432) /* 0x51bb90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475535  0f85e4000000           -jne 0x47561f
    if (!cpu.flags.zf)
    {
        goto L_0x0047561f;
    }
    // 0047553b  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047553d  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00475540  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00475543  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00475547  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475549  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047554c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047554e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475550  8b510e                 -mov edx, dword ptr [ecx + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 00475553  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00475556  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00475558  8b510e                 -mov edx, dword ptr [ecx + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0047555b  66894114               -mov word ptr [ecx + 0x14], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ax;
    // 0047555f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475563  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00475566  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00475569  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047556b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047556e  c1e210                 +shl edx, 0x10
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
    // 00475571  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475573  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475576  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00475578  8b5112                 -mov edx, dword ptr [ecx + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(18) /* 0x12 */);
    // 0047557b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047557d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00475580  6689410e               -mov word ptr [ecx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00475584  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475588  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047558b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047558d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475590  c1e210                 +shl edx, 0x10
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
    // 00475593  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475595  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475598  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047559a  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047559c:
    // 0047559c  66894112               -mov word ptr [ecx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004755a0  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004755a4  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004755a8  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004755ab  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004755ae  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004755b1  46                     -inc esi
    (cpu.esi)++;
    // 004755b2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004755b4  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004755b8  668959e8               -mov word ptr [ecx - 0x18], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-24) /* -0x18 */) = cpu.bx;
    // 004755bc  39d6                   +cmp esi, edx
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
    // 004755be  0f8de1fdffff           -jge 0x4753a5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004753a5;
    }
    // 004755c4  e9e7feffff             -jmp 0x4754b0
    goto L_0x004754b0;
L_0x004755c9:
    // 004755c9  31c5                   +xor ebp, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004755cb  e95bfeffff             -jmp 0x47542b
    goto L_0x0047542b;
L_0x004755d0:
    // 004755d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004755d2  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 004755d9  e96bfeffff             -jmp 0x475449
    goto L_0x00475449;
L_0x004755de:
    // 004755de  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004755e1  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004755e3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004755e6  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004755e9  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004755ec  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004755f0  01c2                   +add edx, eax
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
    // 004755f2  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004755f7  e9e0feffff             -jmp 0x4754dc
    goto L_0x004754dc;
L_0x004755fc:
    // 004755fc  e82f920000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475601  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00475603  2401                   +and al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00475605  e909ffffff             -jmp 0x475513
    goto L_0x00475513;
L_0x0047560a:
    // 0047560a  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 0047560f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475611  e81a920000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475616  f7f3                   +div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00475618  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047561a  e90fffffff             -jmp 0x47552e
    goto L_0x0047552e;
L_0x0047561f:
    // 0047561f  e80c920000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475624  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00475626  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00475628  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 0047562b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047562d  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00475631  66895110               -mov word ptr [ecx + 0x10], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 00475635  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475637  66895114               -mov word ptr [ecx + 0x14], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.dx;
    // 0047563b  8b510e                 -mov edx, dword ptr [ecx + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0047563e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475642  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00475645  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00475648  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047564a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047564d  c1e210                 +shl edx, 0x10
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
    // 00475650  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475652  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475655  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00475657  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00475659  48                     -dec eax
    (cpu.eax)--;
    // 0047565a  6689410e               -mov word ptr [ecx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0047565e  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00475661  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475665  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475668  01d0                   +add eax, edx
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
    // 0047566a  e92dffffff             -jmp 0x47559c
    goto L_0x0047559c;
}

/* align: skip 0x00 */
void Application::sub_475670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475670  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475677  7501                   -jne 0x47567a
    if (!cpu.flags.zf)
    {
        goto L_0x0047567a;
    }
    // 00475679  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047567a:
    // 0047567a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047567b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047567c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047567d  ba44f94b00             -mov edx, 0x4bf944
    cpu.edx = 4979012 /*0x4bf944*/;
    // 00475682  b9ef010000             -mov ecx, 0x1ef
    cpu.ecx = 495 /*0x1ef*/;
    // 00475687  b864f94b00             -mov eax, 0x4bf964
    cpu.eax = 4979044 /*0x4bf964*/;
    // 0047568c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047568e  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00475694  bac0030000             -mov edx, 0x3c0
    cpu.edx = 960 /*0x3c0*/;
    // 00475699  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0047569f  e8844b0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 004756a4  a3c8bb5100             -mov dword ptr [0x51bbc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5356488) /* 0x51bbc8 */) = cpu.eax;
    // 004756a9  e816040000             -call 0x475ac4
    cpu.esp -= 4;
    sub_475ac4(app, cpu);
    if (cpu.terminate) return;
    // 004756ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4756c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004756c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004756c1  8a2538f54d00           -mov ah, byte ptr [0x4df538]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */);
    // 004756c7  8b0dc8bb5100           -mov ecx, dword ptr [0x51bbc8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356488) /* 0x51bbc8 */);
    // 004756cd  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004756d0  7458                   -je 0x47572a
    if (cpu.flags.zf)
    {
        goto L_0x0047572a;
    }
    // 004756d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004756d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004756d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004756d5  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
    // 004756da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004756dc:
    // 004756dc  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004756e3  c7410811000000         -mov dword ptr [ecx + 8], 0x11
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 17 /*0x11*/;
    // 004756ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004756ec  e83f910000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004756f1  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004756f3  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004756f6  e835910000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004756fb  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004756fd  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 004756ff  0502000000             -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00475704  43                     -inc ebx
    (cpu.ebx)++;
    // 00475705  66894102               -mov word ptr [ecx + 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00475709  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047570b  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047570e  83fb28                 +cmp ebx, 0x28
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475711  7d0c                   -jge 0x47571f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047571f;
    }
    // 00475713  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475715  7ec5                   -jle 0x4756dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004756dc;
    }
    // 00475717  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047571a  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047571d  ebbd                   -jmp 0x4756dc
    goto L_0x004756dc;
L_0x0047571f:
    // 0047571f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475721  891558a34c00           -mov dword ptr [0x4ca358], edx
    app->getMemory<x86::reg32>(x86::reg32(5022552) /* 0x4ca358 */) = cpu.edx;
    // 00475727  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475728  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475729  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047572a:
    // 0047572a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047572b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_475744(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00475744  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475745  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475746  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475747  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047574a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047574c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047574e  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475755  743f                   -je 0x475796
    if (cpu.flags.zf)
    {
        goto L_0x00475796;
    }
    // 00475757  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475758  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047575a  e821010000             -call 0x475880
    cpu.esp -= 4;
    sub_475880(app, cpu);
    if (cpu.terminate) return;
    // 0047575f  8b048d90bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356432) /* 0x51bb90 */ + cpu.ecx * 4);
    // 00475766  83f804                 +cmp eax, 4
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
    // 00475769  7707                   -ja 0x475772
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475772;
    }
    // 0047576b  ff248530574700         -jmp dword ptr [eax*4 + 0x475730]
    cpu.ip = app->getMemory<x86::reg32>(4675376 + cpu.eax * 4); goto dynamic_jump;
  case 0x00475772:
L_0x00475772:
    // 00475772  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475774  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00475778  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0047577c:
    // 0047577c  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475780  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475784  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475785  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475786  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475787  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475789  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047578b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047578c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047578d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047578f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00475792  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475793  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475794  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475795  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475796:
    // 00475796  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475798  e88371feff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 0047579d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047579f  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004757a1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004757a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004757a3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004757a5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004757a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004757a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004757aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004757ab  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004757ac:
    // 004757ac  8b148d88bb5100         -mov edx, dword ptr [ecx*4 + 0x51bb88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356424) /* 0x51bb88 */ + cpu.ecx * 4);
    // 004757b3  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004757b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004757b8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004757bb  c1e210                 +shl edx, 0x10
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
    // 004757be  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004757c0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004757c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004757c5  0f84a6000000           -je 0x475871
    if (cpu.flags.zf)
    {
        goto L_0x00475871;
    }
    // 004757cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004757cc  8b3534f34d00           -mov esi, dword ptr [0x4df334]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
    // 004757d2  8b1dc8bb5100           -mov ebx, dword ptr [0x51bbc8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356488) /* 0x51bbc8 */);
    // 004757d8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004757da  7467                   -je 0x475843
    if (cpu.flags.zf)
    {
        goto L_0x00475843;
    }
    // 004757dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004757de  755c                   -jne 0x47583c
    if (!cpu.flags.zf)
    {
        goto L_0x0047583c;
    }
    // 004757e0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004757e2:
    // 004757e2  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
L_0x004757e7:
    // 004757e7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004757ee  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004757f0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004757f3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004757f5  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004757f8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004757fc  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004757ff  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00475803  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475807  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047580a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047580c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047580f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475811  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00475814  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00475818  a158a34c00             -mov eax, dword ptr [0x4ca358]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022552) /* 0x4ca358 */);
    // 0047581d  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00475824  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475826  7505                   -jne 0x47582d
    if (!cpu.flags.zf)
    {
        goto L_0x0047582d;
    }
    // 00475828  e813060000             -call 0x475e40
    cpu.esp -= 4;
    sub_475e40(app, cpu);
    if (cpu.terminate) return;
L_0x0047582d:
    // 0047582d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047582f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475831  e8eafaffff             -call 0x475320
    cpu.esp -= 4;
    sub_475320(app, cpu);
    if (cpu.terminate) return;
    // 00475836  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475837  e940ffffff             -jmp 0x47577c
    goto L_0x0047577c;
L_0x0047583c:
    // 0047583c  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00475841  eb9f                   -jmp 0x4757e2
    goto L_0x004757e2;
L_0x00475843:
    // 00475843  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00475848  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047584a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00475851  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475853  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00475856  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475858  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047585b  c1e203                 +shl edx, 3
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
    // 0047585e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475860  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00475863  be28000000             -mov esi, 0x28
    cpu.esi = 40 /*0x28*/;
    // 00475868  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047586a  29c6                   +sub esi, eax
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
    // 0047586c  e976ffffff             -jmp 0x4757e7
    goto L_0x004757e7;
L_0x00475871:
    // 00475871  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00475875  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00475879  e9fefeffff             -jmp 0x47577c
    goto L_0x0047577c;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_475880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475882  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475883  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475884  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475885  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475886  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475889  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047588b  8a2538f54d00           -mov ah, byte ptr [0x4df538]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */);
    // 00475891  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475893  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00475896  750a                   -jne 0x4758a2
    if (!cpu.flags.zf)
    {
        goto L_0x004758a2;
    }
    // 00475898  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047589b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047589c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047589d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047589e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047589f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004758a2:
    // 004758a2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004758a4  e85740fcff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 004758a9  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004758ac  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004758ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004758b0  e81f010000             -call 0x4759d4
    cpu.esp -= 4;
    sub_4759d4(app, cpu);
    if (cpu.terminate) return;
    // 004758b5  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004758b9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004758bb  743f                   -je 0x4758fc
    if (cpu.flags.zf)
    {
        goto L_0x004758fc;
    }
    // 004758bd  a110ec4d00             -mov eax, dword ptr [0x4dec10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 004758c2  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004758c5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004758c7  39e8                   +cmp eax, ebp
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
    // 004758c9  7d52                   -jge 0x47591d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047591d;
    }
    // 004758cb  39ca                   +cmp edx, ecx
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
    // 004758cd  7d4e                   -jge 0x47591d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047591d;
    }
    // 004758cf  8b0d10ec4d00           -mov ecx, dword ptr [0x4dec10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 004758d5  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004758d7  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004758d9:
    // 004758d9  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004758e0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004758e2  a118ec4d00             -mov eax, dword ptr [0x4dec18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5106712) /* 0x4dec18 */);
    // 004758e7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004758ea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004758ec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004758ee  8a501e                 -mov dl, byte ptr [eax + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004758f1  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004758f4  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004758f7  83fa02                 +cmp edx, 2
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
    // 004758fa  7534                   -jne 0x475930
    if (!cpu.flags.zf)
    {
        goto L_0x00475930;
    }
L_0x004758fc:
    // 004758fc  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004758ff  899f88bb5100           -mov dword ptr [edi + 0x51bb88], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5356424) /* 0x51bb88 */) = cpu.ebx;
    // 00475905  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475907  0f8565000000           -jne 0x475972
    if (!cpu.flags.zf)
    {
        goto L_0x00475972;
    }
    // 0047590d  899f90bb5100           -mov dword ptr [edi + 0x51bb90], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5356432) /* 0x51bb90 */) = cpu.ebx;
    // 00475913  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475916  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475918  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475919  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047591a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047591b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047591c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047591d:
    // 0047591d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00475920  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475922  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475924  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475926  7e04                   -jle 0x47592c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047592c;
    }
L_0x00475928:
    // 00475928  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047592a  ebad                   -jmp 0x4758d9
    goto L_0x004758d9;
L_0x0047592c:
    // 0047592c  f7d8                   +neg eax
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
    // 0047592e  ebf8                   -jmp 0x475928
    goto L_0x00475928;
L_0x00475930:
    // 00475930  8a401e                 -mov al, byte ptr [eax + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 00475933  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00475935  3c02                   +cmp al, 2
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
    // 00475937  74c3                   -je 0x4758fc
    if (cpu.flags.zf)
    {
        goto L_0x004758fc;
    }
    // 00475939  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047593d  39e9                   +cmp ecx, ebp
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
    // 0047593f  7dbb                   -jge 0x4758fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004758fc;
    }
    // 00475941  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00475943  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00475945  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475947  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0047594a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047594d  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0047594e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00475950  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475952  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475954  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00475958  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047595b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047595d  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00475960  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475962  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00475964  3d00000100             +cmp eax, 0x10000
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
    // 00475969  7e91                   -jle 0x4758fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004758fc;
    }
    // 0047596b  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 00475970  eb8a                   -jmp 0x4758fc
    goto L_0x004758fc;
L_0x00475972:
    // 00475972  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475976  898790bb5100           -mov dword ptr [edi + 0x51bb90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5356432) /* 0x51bb90 */) = cpu.eax;
    // 0047597c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047597f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475980  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475981  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475982  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475983  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475984  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475985  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475990  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475997  7503                   -jne 0x47599c
    if (!cpu.flags.zf)
    {
        goto L_0x0047599c;
    }
    // 00475999  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047599b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047599c:
    // 0047599c  8b048588bb5100         -mov eax, dword ptr [eax*4 + 0x51bb88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356424) /* 0x51bb88 */ + cpu.eax * 4);
    // 004759a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4759d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004759d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004759d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004759d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004759d7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004759da  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004759de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004759e0  a13cf54d00             -mov eax, dword ptr [0x4df53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 004759e5  83f808                 +cmp eax, 8
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
    // 004759e8  0f8782000000           -ja 0x475a70
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475a70;
    }
    // 004759ee  ff2485b0594700         -jmp dword ptr [eax*4 + 0x4759b0]
    cpu.ip = app->getMemory<x86::reg32>(4676016 + cpu.eax * 4); goto dynamic_jump;
  case 0x004759f5:
    // 004759f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004759f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004759f7  bb10270000             -mov ebx, 0x2710
    cpu.ebx = 10000 /*0x2710*/;
    // 004759fc  8b2dccbb5100           -mov ebp, dword ptr [0x51bbcc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */);
    // 00475a02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475a04  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00475a06  7e24                   -jle 0x475a2c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475a2c;
    }
    // 00475a08  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00475a0a:
    // 00475a0a  8b9198bb5100           -mov edx, dword ptr [ecx + 0x51bb98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356440) /* 0x51bb98 */);
    // 00475a10  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00475a12  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475a14  7e56                   -jle 0x475a6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475a6c;
    }
L_0x00475a16:
    // 00475a16  39da                   +cmp edx, ebx
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
    // 00475a18  7d04                   -jge 0x475a1e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475a1e;
    }
    // 00475a1a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00475a1c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00475a1e:
    // 00475a1e  8b15ccbb5100           -mov edx, dword ptr [0x51bbcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */);
    // 00475a24  40                     -inc eax
    (cpu.eax)++;
    // 00475a25  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475a28  39d0                   +cmp eax, edx
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
    // 00475a2a  7cde                   -jl 0x475a0a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475a0a;
    }
L_0x00475a2c:
    // 00475a2c  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 00475a33  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00475a35  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00475a38  8b8298bb5100           -mov eax, dword ptr [edx + 0x51bb98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5356440) /* 0x51bb98 */);
    // 00475a3e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00475a42  8b829cbb5100           -mov eax, dword ptr [edx + 0x51bb9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5356444) /* 0x51bb9c */);
    // 00475a48  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00475a4c  8b82a0bb5100           -mov eax, dword ptr [edx + 0x51bba0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5356448) /* 0x51bba0 */);
    // 00475a52  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00475a56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a58  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475a5c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475a5e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475a5f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475a60  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475a61  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475a65  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475a68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475a6c:
    // 00475a6c  f7da                   +neg edx
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
    // 00475a6e  eba6                   -jmp 0x475a16
    goto L_0x00475a16;
  case 0x00475a70:
L_0x00475a70:
    // 00475a70  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475a72  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00475a76  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00475a7a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00475a7d  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475a81  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475a83  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475a84  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475a85  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475a86  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475a8a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475a8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a90  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475ac4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00475ac4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475ac5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475ac6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475ac7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475ac8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475ac9  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475acc  a13cf54d00             -mov eax, dword ptr [0x4df53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 00475ad1  83f808                 +cmp eax, 8
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
    // 00475ad4  0f8717020000           -ja 0x475cf1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475cf1;
    }
    // 00475ada  ff2485a05a4700         -jmp dword ptr [eax*4 + 0x475aa0]
    cpu.ip = app->getMemory<x86::reg32>(4676256 + cpu.eax * 4); goto dynamic_jump;
  case 0x00475ae1:
    // 00475ae1  c705ccbb510001000000   -mov dword ptr [0x51bbcc], 1
    app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */) = 1 /*0x1*/;
    // 00475aeb  e8408d0000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475af0  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00475af2  742d                   -je 0x475b21
    if (cpu.flags.zf)
    {
        goto L_0x00475b21;
    }
    // 00475af4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475af9  bac2010000             -mov edx, 0x1c2
    cpu.edx = 450 /*0x1c2*/;
    // 00475afe  b832000000             -mov eax, 0x32
    cpu.eax = 50 /*0x32*/;
    // 00475b03  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475b07  bf98bb5100             -mov edi, 0x51bb98
    cpu.edi = 5356440 /*0x51bb98*/;
    // 00475b0c  e8ff010000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475b11  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475b15  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475b16  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475b17  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x00475b18:
    // 00475b18  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475b1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475b21:
    // 00475b21  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475b26  bae8030000             -mov edx, 0x3e8
    cpu.edx = 1000 /*0x3e8*/;
    // 00475b2b  b8bc020000             -mov eax, 0x2bc
    cpu.eax = 700 /*0x2bc*/;
    // 00475b30  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00475b34  bf98bb5100             -mov edi, 0x51bb98
    cpu.edi = 5356440 /*0x51bb98*/;
    // 00475b39  e8d2010000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475b3e  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00475b42  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475b43  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475b44  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475b45  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475b48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b4d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00475b4e:
    // 00475b4e  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 00475b53  b869020000             -mov eax, 0x269
    cpu.eax = 617 /*0x269*/;
    // 00475b58  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00475b5d  bb74020000             -mov ebx, 0x274
    cpu.ebx = 628 /*0x274*/;
    // 00475b62  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 00475b67  892dccbb5100           -mov dword ptr [0x51bbcc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */) = cpu.ebp;
    // 00475b6d  a398bb5100             -mov dword ptr [0x51bb98], eax
    app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */) = cpu.eax;
    // 00475b72  89159cbb5100           -mov dword ptr [0x51bb9c], edx
    app->getMemory<x86::reg32>(x86::reg32(5356444) /* 0x51bb9c */) = cpu.edx;
    // 00475b78  892da0bb5100           -mov dword ptr [0x51bba0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5356448) /* 0x51bba0 */) = cpu.ebp;
    // 00475b7e  891da4bb5100           -mov dword ptr [0x51bba4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5356452) /* 0x51bba4 */) = cpu.ebx;
    // 00475b84  8935a8bb5100           -mov dword ptr [0x51bba8], esi
    app->getMemory<x86::reg32>(x86::reg32(5356456) /* 0x51bba8 */) = cpu.esi;
    // 00475b8a  892dacbb5100           -mov dword ptr [0x51bbac], ebp
    app->getMemory<x86::reg32>(x86::reg32(5356460) /* 0x51bbac */) = cpu.ebp;
    // 00475b90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475b92  e8998c0000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475b97  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00475b99  83fa01                 +cmp edx, 1
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
    // 00475b9c  7335                   -jae 0x475bd3
    if (!cpu.flags.cf)
    {
        goto L_0x00475bd3;
    }
    // 00475b9e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475ba0  0f8572ffffff           -jne 0x475b18
    if (!cpu.flags.zf)
    {
        goto L_0x00475b18;
    }
    // 00475ba6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475bab  baf4010000             -mov edx, 0x1f4
    cpu.edx = 500 /*0x1f4*/;
    // 00475bb0  b832000000             -mov eax, 0x32
    cpu.eax = 50 /*0x32*/;
    // 00475bb5  8d74243c               -lea esi, [esp + 0x3c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00475bb9  bfb0bb5100             -mov edi, 0x51bbb0
    cpu.edi = 5356464 /*0x51bbb0*/;
    // 00475bbe  e84d010000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475bc3  8d74243c               -lea esi, [esp + 0x3c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00475bc7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475bc8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475bc9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475bca  83c460                 +add esp, 0x60
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00475bcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475bce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475bcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475bd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475bd1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475bd2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475bd3:
    // 00475bd3  7632                   -jbe 0x475c07
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475c07;
    }
    // 00475bd5  83fa02                 +cmp edx, 2
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
    // 00475bd8  0f853affffff           -jne 0x475b18
    if (!cpu.flags.zf)
    {
        goto L_0x00475b18;
    }
    // 00475bde  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475be3  baaa050000             -mov edx, 0x5aa
    cpu.edx = 1450 /*0x5aa*/;
    // 00475be8  b8c0030000             -mov eax, 0x3c0
    cpu.eax = 960 /*0x3c0*/;
    // 00475bed  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475bef  bfb0bb5100             -mov edi, 0x51bbb0
    cpu.edi = 5356464 /*0x51bbb0*/;
    // 00475bf4  e817010000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475bf9  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475bfb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475bfc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475bfd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475bfe  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475c01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475c07:
    // 00475c07  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475c0c  ba52030000             -mov edx, 0x352
    cpu.edx = 850 /*0x352*/;
    // 00475c11  b8d5020000             -mov eax, 0x2d5
    cpu.eax = 725 /*0x2d5*/;
    // 00475c16  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00475c1a  bfb0bb5100             -mov edi, 0x51bbb0
    cpu.edi = 5356464 /*0x51bbb0*/;
    // 00475c1f  e8ec000000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475c24  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00475c28  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c29  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c2a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c2b  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475c2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c33  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00475c34:
    // 00475c34  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00475c39  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475c3e  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 00475c43  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475c47  8915ccbb5100           -mov dword ptr [0x51bbcc], edx
    app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */) = cpu.edx;
    // 00475c4d  ba7c010000             -mov edx, 0x17c
    cpu.edx = 380 /*0x17c*/;
    // 00475c52  bf98bb5100             -mov edi, 0x51bb98
    cpu.edi = 5356440 /*0x51bb98*/;
    // 00475c57  e8b4000000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475c5c  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475c60  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c61  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c62  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c63  e8c88b0000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475c68  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00475c6a  742d                   -je 0x475c99
    if (cpu.flags.zf)
    {
        goto L_0x00475c99;
    }
    // 00475c6c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00475c71  ba60040000             -mov edx, 0x460
    cpu.edx = 1120 /*0x460*/;
    // 00475c76  b826020000             -mov eax, 0x226
    cpu.eax = 550 /*0x226*/;
    // 00475c7b  8d742454               -lea esi, [esp + 0x54]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00475c7f  bfa4bb5100             -mov edi, 0x51bba4
    cpu.edi = 5356452 /*0x51bba4*/;
    // 00475c84  e887000000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475c89  8d742454               -lea esi, [esp + 0x54]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00475c8d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c8e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c8f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c90  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475c93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475c99:
    // 00475c99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475c9a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00475c9f  bad6060000             -mov edx, 0x6d6
    cpu.edx = 1750 /*0x6d6*/;
    // 00475ca4  b8b0040000             -mov eax, 0x4b0
    cpu.eax = 1200 /*0x4b0*/;
    // 00475ca9  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00475cad  bfa4bb5100             -mov edi, 0x51bba4
    cpu.edi = 5356452 /*0x51bba4*/;
    // 00475cb2  e859000000             -call 0x475d10
    cpu.esp -= 4;
    sub_475d10(app, cpu);
    if (cpu.terminate) return;
    // 00475cb7  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00475cbb  b9f0060000             -mov ecx, 0x6f0
    cpu.ecx = 1776 /*0x6f0*/;
    // 00475cc0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475cc1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475cc2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475cc3  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00475cc8  8b3dccbb5100           -mov edi, dword ptr [0x51bbcc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */);
    // 00475cce  890db0bb5100           -mov dword ptr [0x51bbb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5356464) /* 0x51bbb0 */) = cpu.ecx;
    // 00475cd4  891db4bb5100           -mov dword ptr [0x51bbb4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5356468) /* 0x51bbb4 */) = cpu.ebx;
    // 00475cda  47                     -inc edi
    (cpu.edi)++;
    // 00475cdb  891db8bb5100           -mov dword ptr [0x51bbb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5356472) /* 0x51bbb8 */) = cpu.ebx;
    // 00475ce1  893dccbb5100           -mov dword ptr [0x51bbcc], edi
    app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */) = cpu.edi;
    // 00475ce7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ce8  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475ceb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ced  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cf0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00475cf1:
L_0x00475cf1:
    // 00475cf1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00475cf3  892dccbb5100           -mov dword ptr [0x51bbcc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5356492) /* 0x51bbcc */) = cpu.ebp;
    // 00475cf9  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00475cfc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d01  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475d10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475d11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475d13  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475d16  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475d18  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475d1a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00475d1c  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
    // 00475d21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475d23  e8088b0000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475d28  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00475d2a  83c23c                 -add edx, 0x3c
    (cpu.edx) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00475d2d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00475d31  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00475d34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00475d36  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00475d38  39d0                   +cmp eax, edx
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
    // 00475d3a  7e30                   -jle 0x475d6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475d6c;
    }
    // 00475d3c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d3e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475d41  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475d43  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475d45  8d1437                 -lea edx, [edi + esi]
    cpu.edx = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00475d48  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00475d4c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d4e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475d51  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475d53  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475d55  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00475d58  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475d5a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00475d5c  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00475d60  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475d61  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475d62  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475d63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475d65  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475d68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d6c:
    // 00475d6c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475d70  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00475d72  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00475d74  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00475d76  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00475d79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475d7b  e8b08a0000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00475d80  f7f7                   -div edi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.edi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00475d82  011424                 -add dword ptr [esp], edx
    (app->getMemory<x86::reg32>(cpu.esp)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00475d85  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475d87  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00475d89  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00475d8d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475d8e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475d8f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475d90  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475d92  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475d95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475da1  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00475da8  83b990bb510000         +cmp dword ptr [ecx + 0x51bb90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356432) /* 0x51bb90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475daf  7454                   -je 0x475e05
    if (cpu.flags.zf)
    {
        goto L_0x00475e05;
    }
    // 00475db1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475db2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475db3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475db5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00475db8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00475dba  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00475dbd  8b90fc514c00           -mov edx, dword ptr [eax + 0x4c51fc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5001724) /* 0x4c51fc */);
    // 00475dc3  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00475dca  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475dcc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475dce  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475dd1  c1e210                 +shl edx, 0x10
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
    // 00475dd4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475dd6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00475dd9  8d5007                 -lea edx, [eax + 7]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00475ddc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475dde  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475de1  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475de3  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475de5  8b9990bb5100           -mov ebx, dword ptr [ecx + 0x51bb90]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356432) /* 0x51bb90 */);
    // 00475deb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00475dee  83fb01                 +cmp ebx, 1
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
    // 00475df1  7525                   -jne 0x475e18
    if (!cpu.flags.zf)
    {
        goto L_0x00475e18;
    }
    // 00475df3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475df5  83f809                 +cmp eax, 9
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
    // 00475df8  7e12                   -jle 0x475e0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475e0c;
    }
    // 00475dfa  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
L_0x00475dff:
    // 00475dff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e05:
    // 00475e05  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00475e0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e0c:
    // 00475e0c  83f802                 +cmp eax, 2
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
    // 00475e0f  7dee                   -jge 0x475dff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475dff;
    }
    // 00475e11  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00475e16  ebe7                   -jmp 0x475dff
    goto L_0x00475dff;
L_0x00475e18:
    // 00475e18  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475e1a  83f805                 +cmp eax, 5
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
    // 00475e1d  7e0b                   -jle 0x475e2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475e2a;
    }
    // 00475e1f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00475e24  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e2a:
    // 00475e2a  83f802                 +cmp eax, 2
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
    // 00475e2d  7dd0                   -jge 0x475dff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475dff;
    }
    // 00475e2f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00475e34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e37  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475e41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475e42  b8848484ff             -mov eax, 0xff848484
    cpu.eax = 4286874756 /*0xff848484*/;
    // 00475e47  8b15c8bb5100           -mov edx, dword ptr [0x51bbc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356488) /* 0x51bbc8 */);
    // 00475e4d  e8ca220000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00475e52  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00475e54  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475e5b  741c                   -je 0x475e79
    if (cpu.flags.zf)
    {
        goto L_0x00475e79;
    }
    // 00475e5d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00475e5f  741b                   -je 0x475e7c
    if (cpu.flags.zf)
    {
        goto L_0x00475e7c;
    }
L_0x00475e61:
    // 00475e61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00475e63:
    // 00475e63  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00475e66  40                     -inc eax
    (cpu.eax)++;
    // 00475e67  885af4                 -mov byte ptr [edx - 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.bl;
    // 00475e6a  83f828                 +cmp eax, 0x28
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
    // 00475e6d  7cf4                   -jl 0x475e63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475e63;
    }
    // 00475e6f  c70558a34c0001000000   -mov dword ptr [0x4ca358], 1
    app->getMemory<x86::reg32>(x86::reg32(5022552) /* 0x4ca358 */) = 1 /*0x1*/;
L_0x00475e79:
    // 00475e79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e7c:
    // 00475e7c  b318                   -mov bl, 0x18
    cpu.bl = 24 /*0x18*/;
    // 00475e7e  ebe1                   -jmp 0x475e61
    goto L_0x00475e61;
}

/* align: skip  */
void Application::sub_475e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475e80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475e90  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475e97  7501                   -jne 0x475e9a
    if (!cpu.flags.zf)
    {
        goto L_0x00475e9a;
    }
    // 00475e99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e9a:
    // 00475e9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475e9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475e9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475e9d  b960cb5100             -mov ecx, 0x51cb60
    cpu.ecx = 5360480 /*0x51cb60*/;
    // 00475ea2  ba68f94b00             -mov edx, 0x4bf968
    cpu.edx = 4979048 /*0x4bf968*/;
    // 00475ea7  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00475eac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475eae  e8adf3ffff             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475eb3  b96ccb5100             -mov ecx, 0x51cb6c
    cpu.ecx = 5360492 /*0x51cb6c*/;
    // 00475eb8  ba70f94b00             -mov edx, 0x4bf970
    cpu.edx = 4979056 /*0x4bf970*/;
    // 00475ebd  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00475ec2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475ec4  e897f3ffff             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475ec9  b978cb5100             -mov ecx, 0x51cb78
    cpu.ecx = 5360504 /*0x51cb78*/;
    // 00475ece  ba78f94b00             -mov edx, 0x4bf978
    cpu.edx = 4979064 /*0x4bf978*/;
    // 00475ed3  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00475ed8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475eda  e881f3ffff             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475edf  b984cb5100             -mov ecx, 0x51cb84
    cpu.ecx = 5360516 /*0x51cb84*/;
    // 00475ee4  ba80f94b00             -mov edx, 0x4bf980
    cpu.edx = 4979072 /*0x4bf980*/;
    // 00475ee9  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00475eee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475ef0  e86bf3ffff             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475ef5  b990cb5100             -mov ecx, 0x51cb90
    cpu.ecx = 5360528 /*0x51cb90*/;
    // 00475efa  ba88f94b00             -mov edx, 0x4bf988
    cpu.edx = 4979080 /*0x4bf988*/;
    // 00475eff  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00475f04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475f06  e855f3ffff             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475f0b  b99ccb5100             -mov ecx, 0x51cb9c
    cpu.ecx = 5360540 /*0x51cb9c*/;
    // 00475f10  ba90f94b00             -mov edx, 0x4bf990
    cpu.edx = 4979088 /*0x4bf990*/;
    // 00475f15  a128ba5100             -mov eax, dword ptr [0x51ba28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356072) /* 0x51ba28 */);
    // 00475f1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475f1c  e83ff3ffff             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00475f21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475f44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00475f44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475f45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475f46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475f47  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475f4a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475f4c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475f4e  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475f55  7450                   -je 0x475fa7
    if (cpu.flags.zf)
    {
        goto L_0x00475fa7;
    }
    // 00475f57  833db0f34d0000         +cmp dword ptr [0x4df3b0], 0
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
    // 00475f5e  7447                   -je 0x475fa7
    if (cpu.flags.zf)
    {
        goto L_0x00475fa7;
    }
    // 00475f60  833d34f34d0000         +cmp dword ptr [0x4df334], 0
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
    // 00475f67  753e                   -jne 0x475fa7
    if (!cpu.flags.zf)
    {
        goto L_0x00475fa7;
    }
    // 00475f69  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475f6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475f6f  e85c000000             -call 0x475fd0
    cpu.esp -= 4;
    sub_475fd0(app, cpu);
    if (cpu.terminate) return;
    // 00475f74  833d10104e0000         +cmp dword ptr [0x4e1010], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115920) /* 0x4e1010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475f7b  7513                   -jne 0x475f90
    if (!cpu.flags.zf)
    {
        goto L_0x00475f90;
    }
    // 00475f7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475f7f  e85cf3ffff             -call 0x4752e0
    cpu.esp -= 4;
    sub_4752e0(app, cpu);
    if (cpu.terminate) return;
    // 00475f84  83f804                 +cmp eax, 4
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
    // 00475f87  7707                   -ja 0x475f90
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475f90;
    }
    // 00475f89  ff2485305f4700         -jmp dword ptr [eax*4 + 0x475f30]
    cpu.ip = app->getMemory<x86::reg32>(4677424 + cpu.eax * 4); goto dynamic_jump;
  case 0x00475f90:
L_0x00475f90:
    // 00475f90  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00475f92  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475f96  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475f97  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475f98  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475f9a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475f9c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475f9d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475f9e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475fa0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475fa3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fa4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fa5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fa6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475fa7:
    // 00475fa7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475fa9  e87269feff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00475fae  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475fb0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475fb2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475fb3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475fb4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475fb6  83c410                 +add esp, 0x10
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
    // 00475fb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fbc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00475fbd:
    // 00475fbd  e81e020000             -call 0x4761e0
    cpu.esp -= 4;
    sub_4761e0(app, cpu);
    if (cpu.terminate) return;
    // 00475fc2  ebcc                   -jmp 0x475f90
    goto L_0x00475f90;
  case 0x00475fc4:
    // 00475fc4  e897000000             -call 0x476060
    cpu.esp -= 4;
    sub_476060(app, cpu);
    if (cpu.terminate) return;
    // 00475fc9  ebc5                   -jmp 0x475f90
    goto L_0x00475f90;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475fd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475fd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475fd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475fd3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475fd6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475fd8  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00475fdf  7468                   -je 0x476049
    if (cpu.flags.zf)
    {
        goto L_0x00476049;
    }
    // 00475fe1  e8aaf9ffff             -call 0x475990
    cpu.esp -= 4;
    sub_475990(app, cpu);
    if (cpu.terminate) return;
    // 00475fe6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475fe8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00475feb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475fed  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00475ff0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475ff2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00475ff5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475ff7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475ffa  c1e210                 +shl edx, 0x10
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
    // 00475ffd  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00475fff  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00476002  a3b4cb5100             -mov dword ptr [0x51cbb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5360564) /* 0x51cbb4 */) = cpu.eax;
    // 00476007  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476009  743e                   -je 0x476049
    if (cpu.flags.zf)
    {
        goto L_0x00476049;
    }
    // 0047600b  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00476010  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00476012  bebcc95100             -mov esi, 0x51c9bc
    cpu.esi = 5360060 /*0x51c9bc*/;
    // 00476017  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047601e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00476020  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476022  bad0bb5100             -mov edx, 0x51bbd0
    cpu.edx = 5356496 /*0x51bbd0*/;
    // 00476027  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047602a  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047602e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00476030  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476034  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00476038  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476039  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047603a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047603c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047603e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047603f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476042  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476045  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476046  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476047  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476049:
    // 00476049  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047604b  e8d068feff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00476050  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00476052  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00476054  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476055  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476056  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476058  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047605b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047605c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047605d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047605e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_476060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476062  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476063  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476064  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476065  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476066  b8a53c0200             -mov eax, 0x23ca5
    cpu.eax = 146597 /*0x23ca5*/;
    // 0047606b  8b159cf34d00           -mov edx, dword ptr [0x4df39c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108636) /* 0x4df39c */);
    // 00476071  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00476073  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00476076  c1e810                 +shr eax, 0x10
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
    // 00476079  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047607b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047607d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00476080  c1e210                 +shl edx, 0x10
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
    // 00476083  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00476085  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00476088  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047608d  2b1db4cb5100           -sub ebx, dword ptr [0x51cbb4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5360564) /* 0x51cbb4 */)));
    // 00476093  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476095  83fb64                 +cmp ebx, 0x64
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
    // 00476098  0f8dbd000000           -jge 0x47615b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047615b;
    }
    // 0047609e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004760a0  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 004760a5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004760a8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004760aa  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 004760b1  bf07000000             -mov edi, 7
    cpu.edi = 7 /*0x7*/;
    // 004760b6  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004760b8  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004760ba  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
L_0x004760bd:
    // 004760bd  8aa3bccb5100           -mov ah, byte ptr [ebx + 0x51cbbc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */);
    // 004760c3  80fc64                 +cmp ah, 0x64
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004760c6  0f8796000000           -ja 0x476162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00476162;
    }
    // 004760cc  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004760ce  fec2                   -inc dl
    (cpu.dl)++;
    // 004760d0  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004760d2  8893bccb5100           -mov byte ptr [ebx + 0x51cbbc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */) = cpu.dl;
    // 004760d8  83ff02                 +cmp edi, 2
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
    // 004760db  7d05                   -jge 0x4760e2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004760e2;
    }
    // 004760dd  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x004760e2:
    // 004760e2  83fd3c                 +cmp ebp, 0x3c
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004760e5  7e67                   -jle 0x47614e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047614e;
    }
    // 004760e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004760e9  8a93bccb5100           -mov dl, byte ptr [ebx + 0x51cbbc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */);
    // 004760ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004760f1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004760f4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004760f6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004760f8  7554                   -jne 0x47614e
    if (!cpu.flags.zf)
    {
        goto L_0x0047614e;
    }
    // 004760fa  a15ca34c00             -mov eax, dword ptr [0x4ca35c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022556) /* 0x4ca35c */);
    // 004760ff  8bb1dcbb5100           -mov esi, dword ptr [ecx + 0x51bbdc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */);
    // 00476105  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00476107  a120cc5100             -mov eax, dword ptr [0x51cc20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360672) /* 0x51cc20 */);
    // 0047610c  8b91d8bb5100           -mov edx, dword ptr [ecx + 0x51bbd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */);
    // 00476112  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00476115  89b1dcbb5100           -mov dword ptr [ecx + 0x51bbdc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */) = cpu.esi;
    // 0047611b  39d0                   +cmp eax, edx
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
    // 0047611d  7e0f                   -jle 0x47612e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047612e;
    }
    // 0047611f  a15ca34c00             -mov eax, dword ptr [0x4ca35c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022556) /* 0x4ca35c */);
    // 00476124  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476126  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00476128  89b1d8bb5100           -mov dword ptr [ecx + 0x51bbd8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.esi;
L_0x0047612e:
    // 0047612e  a122cc5100             -mov eax, dword ptr [0x51cc22]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360674) /* 0x51cc22 */);
    // 00476133  8b91d8bb5100           -mov edx, dword ptr [ecx + 0x51bbd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */);
    // 00476139  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047613c  39d0                   +cmp eax, edx
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
    // 0047613e  7d0e                   -jge 0x47614e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047614e;
    }
    // 00476140  a15ca34c00             -mov eax, dword ptr [0x4ca35c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022556) /* 0x4ca35c */);
    // 00476145  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00476148  89b1d8bb5100           -mov dword ptr [ecx + 0x51bbd8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.esi;
L_0x0047614e:
    // 0047614e  43                     -inc ebx
    (cpu.ebx)++;
    // 0047614f  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00476152  83fb64                 +cmp ebx, 0x64
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
    // 00476155  0f8c62ffffff           -jl 0x4760bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004760bd;
    }
L_0x0047615b:
    // 0047615b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047615c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047615d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047615e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047615f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476160  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476161  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476162:
    // 00476162  e8c9860000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00476167  8b3522cc5100           -mov esi, dword ptr [0x51cc22]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5360674) /* 0x51cc22 */);
    // 0047616d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047616f  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00476172  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476174  a11ecc5100             -mov eax, dword ptr [0x51cc1e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360670) /* 0x51cc1e */);
    // 00476179  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047617c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047617e  8981d8bb5100           -mov dword ptr [ecx + 0x51bbd8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.eax;
    // 00476184  e8a7860000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00476189  8b3520cc5100           -mov esi, dword ptr [0x51cc20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5360672) /* 0x51cc20 */);
    // 0047618f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476191  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00476194  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476196  a124cc5100             -mov eax, dword ptr [0x51cc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360676) /* 0x51cc24 */);
    // 0047619b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047619e  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
    // 004761a3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004761a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004761a7  8981dcbb5100           -mov dword ptr [ecx + 0x51bbdc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */) = cpu.eax;
    // 004761ad  e87e860000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004761b2  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004761b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004761b6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004761b8  8883bccb5100           -mov byte ptr [ebx + 0x51cbbc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */) = cpu.al;
    // 004761be  43                     -inc ebx
    (cpu.ebx)++;
    // 004761bf  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004761c2  83fb64                 +cmp ebx, 0x64
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
    // 004761c5  0f8cf2feffff           -jl 0x4760bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004760bd;
    }
    // 004761cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4761e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004761e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004761e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004761e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004761e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004761e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004761e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004761e6  b8a53c0200             -mov eax, 0x23ca5
    cpu.eax = 146597 /*0x23ca5*/;
    // 004761eb  8b159cf34d00           -mov edx, dword ptr [0x4df39c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108636) /* 0x4df39c */);
    // 004761f1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004761f3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004761f6  c1e810                 +shr eax, 0x10
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
    // 004761f9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004761fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004761fd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00476200  c1e210                 +shl edx, 0x10
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
    // 00476203  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00476205  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00476208  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047620d  2b1db4cb5100           -sub ebx, dword ptr [0x51cbb4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5360564) /* 0x51cbb4 */)));
    // 00476213  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476215  83fb64                 +cmp ebx, 0x64
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
    // 00476218  0f8dcf000000           -jge 0x4762ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004762ed;
    }
    // 0047621e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476220  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 00476225  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00476228  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047622a  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 00476231  bd07000000             -mov ebp, 7
    cpu.ebp = 7 /*0x7*/;
    // 00476236  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00476238  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047623a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
L_0x0047623d:
    // 0047623d  8aa3bccb5100           -mov ah, byte ptr [ebx + 0x51cbbc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */);
    // 00476243  80fcb4                 +cmp ah, 0xb4
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(180 /*0xb4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476246  0f87a8000000           -ja 0x4762f4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004762f4;
    }
    // 0047624c  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0047624e  fec2                   -inc dl
    (cpu.dl)++;
    // 00476250  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00476252  8893bccb5100           -mov byte ptr [ebx + 0x51cbbc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */) = cpu.dl;
    // 00476258  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047625b  7d05                   -jge 0x476262
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476262;
    }
    // 0047625d  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00476262:
    // 00476262  83ff50                 +cmp edi, 0x50
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476265  7e56                   -jle 0x4762bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004762bd;
    }
    // 00476267  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476269  8a93bccb5100           -mov dl, byte ptr [ebx + 0x51cbbc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */);
    // 0047626f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476271  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00476274  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00476276  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476278  7543                   -jne 0x4762bd
    if (!cpu.flags.zf)
    {
        goto L_0x004762bd;
    }
    // 0047627a  a120cc5100             -mov eax, dword ptr [0x51cc20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360672) /* 0x51cc20 */);
    // 0047627f  8bb1dcbb5100           -mov esi, dword ptr [ecx + 0x51bbdc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */);
    // 00476285  8b91d8bb5100           -mov edx, dword ptr [ecx + 0x51bbd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */);
    // 0047628b  4e                     -dec esi
    (cpu.esi)--;
    // 0047628c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047628f  89b1dcbb5100           -mov dword ptr [ecx + 0x51bbdc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */) = cpu.esi;
    // 00476295  39d0                   +cmp eax, edx
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
    // 00476297  7e09                   -jle 0x4762a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004762a2;
    }
    // 00476299  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0047629c  89b1d8bb5100           -mov dword ptr [ecx + 0x51bbd8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.esi;
L_0x004762a2:
    // 004762a2  a122cc5100             -mov eax, dword ptr [0x51cc22]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360674) /* 0x51cc22 */);
    // 004762a7  8b91d8bb5100           -mov edx, dword ptr [ecx + 0x51bbd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */);
    // 004762ad  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004762b0  39d0                   +cmp eax, edx
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
    // 004762b2  7d09                   -jge 0x4762bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004762bd;
    }
    // 004762b4  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004762b7  89b1d8bb5100           -mov dword ptr [ecx + 0x51bbd8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.esi;
L_0x004762bd:
    // 004762bd  83ff0a                 +cmp edi, 0xa
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
    // 004762c0  7d1e                   -jge 0x4762e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004762e0;
    }
    // 004762c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004762c4  8a93bccb5100           -mov dl, byte ptr [ebx + 0x51cbbc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */);
    // 004762ca  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004762cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004762d1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004762d4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004762d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004762d8  7506                   -jne 0x4762e0
    if (!cpu.flags.zf)
    {
        goto L_0x004762e0;
    }
    // 004762da  ff81dcbb5100           -inc dword ptr [ecx + 0x51bbdc]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */))++;
L_0x004762e0:
    // 004762e0  43                     -inc ebx
    (cpu.ebx)++;
    // 004762e1  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004762e4  83fb64                 +cmp ebx, 0x64
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
    // 004762e7  0f8c50ffffff           -jl 0x47623d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047623d;
    }
L_0x004762ed:
    // 004762ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004762f4:
    // 004762f4  e837850000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004762f9  8b3522cc5100           -mov esi, dword ptr [0x51cc22]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5360674) /* 0x51cc22 */);
    // 004762ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476301  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00476304  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476306  a11ecc5100             -mov eax, dword ptr [0x51cc1e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360670) /* 0x51cc1e */);
    // 0047630b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047630e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00476310  8991d8bb5100           -mov dword ptr [ecx + 0x51bbd8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.edx;
    // 00476316  e815850000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0047631b  8b3520cc5100           -mov esi, dword ptr [0x51cc20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5360672) /* 0x51cc20 */);
    // 00476321  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476323  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00476326  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476328  a124cc5100             -mov eax, dword ptr [0x51cc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360676) /* 0x51cc24 */);
    // 0047632d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00476330  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00476332  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
    // 00476337  8991dcbb5100           -mov dword ptr [ecx + 0x51bbdc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356508) /* 0x51bbdc */) = cpu.edx;
    // 0047633d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047633f  e8ec840000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00476344  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476346  b8b4000000             -mov eax, 0xb4
    cpu.eax = 180 /*0xb4*/;
    // 0047634b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047634d  8883bccb5100           -mov byte ptr [ebx + 0x51cbbc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5360572) /* 0x51cbbc */) = cpu.al;
    // 00476353  43                     -inc ebx
    (cpu.ebx)++;
    // 00476354  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00476357  83fb64                 +cmp ebx, 0x64
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
    // 0047635a  0f8cddfeffff           -jl 0x47623d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047623d;
    }
    // 00476360  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476361  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476362  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476363  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476364  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476365  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476366  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476370  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476371  f60538f54d0040         +test byte ptr [0x4df538], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5109048) /* 0x4df538 */) & 64 /*0x40*/));
    // 00476378  7502                   -jne 0x47637c
    if (!cpu.flags.zf)
    {
        goto L_0x0047637c;
    }
    // 0047637a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047637b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047637c:
    // 0047637c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047637d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047637e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047637f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476381  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476383  e87835fcff             -call 0x439900
    cpu.esp -= 4;
    sub_439900(app, cpu);
    if (cpu.terminate) return;
    // 00476388  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 0047638e  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476391  0f85f7000000           -jne 0x47648e
    if (!cpu.flags.zf)
    {
        goto L_0x0047648e;
    }
    // 00476397  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 0047639c  ba5f000000             -mov edx, 0x5f
    cpu.edx = 95 /*0x5f*/;
    // 004763a1  bbb9000000             -mov ebx, 0xb9
    cpu.ebx = 185 /*0xb9*/;
    // 004763a6  bf96000000             -mov edi, 0x96
    cpu.edi = 150 /*0x96*/;
    // 004763ab  66a324cc5100           -mov word ptr [0x51cc24], ax
    app->getMemory<x86::reg16>(x86::reg32(5360676) /* 0x51cc24 */) = cpu.ax;
    // 004763b1  66891526cc5100         -mov word ptr [0x51cc26], dx
    app->getMemory<x86::reg16>(x86::reg32(5360678) /* 0x51cc26 */) = cpu.dx;
    // 004763b8  66891d22cc5100         -mov word ptr [0x51cc22], bx
    app->getMemory<x86::reg16>(x86::reg32(5360674) /* 0x51cc22 */) = cpu.bx;
    // 004763bf  66893d20cc5100         -mov word ptr [0x51cc20], di
    app->getMemory<x86::reg16>(x86::reg32(5360672) /* 0x51cc20 */) = cpu.di;
L_0x004763c6:
    // 004763c6  bedcffffff             -mov esi, 0xffffffdc
    cpu.esi = 4294967260 /*0xffffffdc*/;
    // 004763cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004763cd  bfd0bb5100             -mov edi, 0x51bbd0
    cpu.edi = 5356496 /*0x51bbd0*/;
    // 004763d2  890db4cb5100           -mov dword ptr [0x51cbb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5360564) /* 0x51cbb4 */) = cpu.ecx;
L_0x004763d8:
    // 004763d8  6bd924                 -imul ebx, ecx, 0x24
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 004763db  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004763dd  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 004763e2  89abd0bb5100           -mov dword ptr [ebx + 0x51bbd0], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356496) /* 0x51bbd0 */) = cpu.ebp;
    // 004763e8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004763ea  8983d4bb5100           -mov dword ptr [ebx + 0x51bbd4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356500) /* 0x51bbd4 */) = cpu.eax;
    // 004763f0  bd05000000             -mov ebp, 5
    cpu.ebp = 5 /*0x5*/;
    // 004763f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004763f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004763fa  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004763fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004763fe  0f85bf000000           -jne 0x4764c3
    if (!cpu.flags.zf)
    {
        goto L_0x004764c3;
    }
    // 00476404  c783f0bb51006ccb5100   -mov dword ptr [ebx + 0x51bbf0], 0x51cb6c
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356528) /* 0x51bbf0 */) = 5360492 /*0x51cb6c*/;
L_0x0047640e:
    // 0047640e  e81d840000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00476413  8b1d22cc5100           -mov ebx, dword ptr [0x51cc22]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5360674) /* 0x51cc22 */);
    // 00476419  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047641b  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047641e  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476420  6bd924                 -imul ebx, ecx, 0x24
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00476423  a11ecc5100             -mov eax, dword ptr [0x51cc1e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360670) /* 0x51cc1e */);
    // 00476428  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047642b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047642d  8993d8bb5100           -mov dword ptr [ebx + 0x51bbd8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356504) /* 0x51bbd8 */) = cpu.edx;
    // 00476433  e8f8830000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00476438  8b2d20cc5100           -mov ebp, dword ptr [0x51cc20]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5360672) /* 0x51cc20 */);
    // 0047643e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476440  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00476443  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476445  a124cc5100             -mov eax, dword ptr [0x51cc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360676) /* 0x51cc24 */);
    // 0047644a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047644d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047644f  8993dcbb5100           -mov dword ptr [ebx + 0x51bbdc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356508) /* 0x51bbdc */) = cpu.edx;
    // 00476455  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047645a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047645c  e8cf830000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00476461  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00476463  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00476466  b8b4000000             -mov eax, 0xb4
    cpu.eax = 180 /*0xb4*/;
    // 0047646b  41                     -inc ecx
    (cpu.ecx)++;
    // 0047646c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047646e  83c724                 -add edi, 0x24
    (cpu.edi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00476471  8881bbcb5100           -mov byte ptr [ecx + 0x51cbbb], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5360571) /* 0x51cbbb */) = cpu.al;
    // 00476477  39d9                   +cmp ecx, ebx
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
    // 00476479  7d57                   -jge 0x4764d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004764d2;
    }
    // 0047647b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047647d  0f8e55ffffff           -jle 0x4763d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004763d8;
    }
    // 00476483  89bed0bb5100           -mov dword ptr [esi + 0x51bbd0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5356496) /* 0x51bbd0 */) = cpu.edi;
    // 00476489  e94affffff             -jmp 0x4763d8
    goto L_0x004763d8;
L_0x0047648e:
    // 0047648e  bbf4010000             -mov ebx, 0x1f4
    cpu.ebx = 500 /*0x1f4*/;
    // 00476493  b950000000             -mov ecx, 0x50
    cpu.ecx = 80 /*0x50*/;
    // 00476498  bec8000000             -mov esi, 0xc8
    cpu.esi = 200 /*0xc8*/;
    // 0047649d  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 004764a2  66891d24cc5100         -mov word ptr [0x51cc24], bx
    app->getMemory<x86::reg16>(x86::reg32(5360676) /* 0x51cc24 */) = cpu.bx;
    // 004764a9  66890d26cc5100         -mov word ptr [0x51cc26], cx
    app->getMemory<x86::reg16>(x86::reg32(5360678) /* 0x51cc26 */) = cpu.cx;
    // 004764b0  66893522cc5100         -mov word ptr [0x51cc22], si
    app->getMemory<x86::reg16>(x86::reg32(5360674) /* 0x51cc22 */) = cpu.si;
    // 004764b7  66891520cc5100         -mov word ptr [0x51cc20], dx
    app->getMemory<x86::reg16>(x86::reg32(5360672) /* 0x51cc20 */) = cpu.dx;
    // 004764be  e903ffffff             -jmp 0x4763c6
    goto L_0x004763c6;
L_0x004764c3:
    // 004764c3  c783f0bb510060cb5100   -mov dword ptr [ebx + 0x51bbf0], 0x51cb60
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356528) /* 0x51bbf0 */) = 5360480 /*0x51cb60*/;
    // 004764cd  e93cffffff             -jmp 0x47640e
    goto L_0x0047640e;
L_0x004764d2:
    // 004764d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004764d4  a3b8cb5100             -mov dword ptr [0x51cbb8], eax
    app->getMemory<x86::reg32>(x86::reg32(5360568) /* 0x51cbb8 */) = cpu.eax;
    // 004764d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4764e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004764e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004764e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004764e2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004764e7  8b1d7ca34c00           -mov ebx, dword ptr [0x4ca37c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022588) /* 0x4ca37c */);
    // 004764ed  a380a34c00             -mov dword ptr [0x4ca380], eax
    app->getMemory<x86::reg32>(x86::reg32(5022592) /* 0x4ca380 */) = cpu.eax;
    // 004764f2  891584a34c00           -mov dword ptr [0x4ca384], edx
    app->getMemory<x86::reg32>(x86::reg32(5022596) /* 0x4ca384 */) = cpu.edx;
    // 004764f8  890d78a34c00           -mov dword ptr [0x4ca378], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022584) /* 0x4ca378 */) = cpu.ecx;
    // 004764fe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476500  7403                   -je 0x476505
    if (cpu.flags.zf)
    {
        goto L_0x00476505;
    }
    // 00476502  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476503  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476504  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476505:
    // 00476505  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476506  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476507  68406f4700             -push 0x476f40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4681536 /*0x476f40*/;
    cpu.esp -= 4;
    // 0047650c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047650e  2eff152c744b00         -call dword ptr cs:[0x4b742c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944940) /* 0x4b742c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476515  a37ca34c00             -mov dword ptr [0x4ca37c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022588) /* 0x4ca37c */) = cpu.eax;
    // 0047651a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047651b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047651c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_476520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476521  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476522  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476524  8a25cdd75100           -mov ah, byte ptr [0x51d7cd]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 0047652a  891578a34c00           -mov dword ptr [0x4ca378], edx
    app->getMemory<x86::reg32>(x86::reg32(5022584) /* 0x4ca378 */) = cpu.edx;
    // 00476530  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00476532  740a                   -je 0x47653e
    if (cpu.flags.zf)
    {
        goto L_0x0047653e;
    }
    // 00476534  8b0d7ca34c00           -mov ecx, dword ptr [0x4ca37c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022588) /* 0x4ca37c */);
    // 0047653a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047653c  7503                   -jne 0x476541
    if (!cpu.flags.zf)
    {
        goto L_0x00476541;
    }
L_0x0047653e:
    // 0047653e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047653f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476540  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476541:
    // 00476541  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476542  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476543  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00476545  2eff1540744b00         -call dword ptr cs:[0x4b7440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944960) /* 0x4b7440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047654c  89357ca34c00           -mov dword ptr [0x4ca37c], esi
    app->getMemory<x86::reg32>(x86::reg32(5022588) /* 0x4ca37c */) = cpu.esi;
    // 00476552  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476553  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476554  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476555  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476562  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476563  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476564  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476566  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476568  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047656a  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476571  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00476573  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476575  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00476578  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047657a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047657c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047657e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476580  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476587  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476589  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047658b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047658e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00476590  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00476592  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00476594  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00476596  e805000000             -call 0x4765a0
    cpu.esp -= 4;
    sub_4765a0(app, cpu);
    if (cpu.terminate) return;
    // 0047659b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047659c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047659d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047659e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047659f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4765a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004765a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004765a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004765a2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004765a5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004765a7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004765ab  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004765af  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004765b1  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 004765b3  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004765b7  8b15c4d75100           -mov edx, dword ptr [0x51d7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 004765bd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004765bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004765c0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004765c4  2eff15f8734b00         -call dword ptr cs:[0x4b73f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944888) /* 0x4b73f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004765cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004765cc  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004765d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004765d1  2eff15b0734b00         -call dword ptr cs:[0x4b73b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944816) /* 0x4b73b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004765d8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004765dc  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004765e0  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 004765e2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004765e4  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004765e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004765e9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004765ed  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004765ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004765f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004765f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004765f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004765f4  8b2dc4d75100           -mov ebp, dword ptr [0x51d7c4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 004765fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004765fb  2eff1528744b00         -call dword ptr cs:[0x4b7428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944936) /* 0x4b7428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476602  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476604  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476605  a1c4d75100             -mov eax, dword ptr [0x51d7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047660a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047660b  2eff15e4734b00         -call dword ptr cs:[0x4b73e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944868) /* 0x4b73e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476612  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476614  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476615  8b15c4d75100           -mov edx, dword ptr [0x51d7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047661b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047661c  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476623  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476627  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476628  8b0dc4d75100           -mov ecx, dword ptr [0x51d7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0047662e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047662f  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476636  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047663a  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047663d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047663f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476643  a384d35100             -mov dword ptr [0x51d384], eax
    app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */) = cpu.eax;
    // 00476648  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047664c  891dd4d75100           -mov dword ptr [0x51d7d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5363668) /* 0x51d7d4 */) = cpu.ebx;
    // 00476652  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00476654  8935d8d75100           -mov dword ptr [0x51d7d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5363672) /* 0x51d7d8 */) = cpu.esi;
    // 0047665a  a388d35100             -mov dword ptr [0x51d388], eax
    app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */) = cpu.eax;
    // 0047665f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476662  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476663  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476670  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476671  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476672  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476673  833dc4d7510000         +cmp dword ptr [0x51d7c4], 0
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
    // 0047667a  7504                   -jne 0x476680
    if (!cpu.flags.zf)
    {
        goto L_0x00476680;
    }
    // 0047667c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047667d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047667e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047667f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476680:
    // 00476680  68d0fc4b00             -push 0x4bfcd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979920 /*0x4bfcd0*/;
    cpu.esp -= 4;
    // 00476685  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00476687  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 0047668c  e89f920100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476691  8b0d70a34c00           -mov ecx, dword ptr [0x4ca370]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022576) /* 0x4ca370 */);
    // 00476697  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047669a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047669c  740e                   -je 0x4766ac
    if (cpu.flags.zf)
    {
        goto L_0x004766ac;
    }
    // 0047669e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004766a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004766a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004766a3  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004766a5  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004766ac:
    // 004766ac  8b3574a34c00           -mov esi, dword ptr [0x4ca374]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022580) /* 0x4ca374 */);
    // 004766b2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004766b4  740e                   -je 0x4766c4
    if (cpu.flags.zf)
    {
        goto L_0x004766c4;
    }
    // 004766b6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004766b8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004766ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004766bb  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 004766bd  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004766c4:
    // 004766c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004766c5  68e8fc4b00             -push 0x4bfce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979944 /*0x4bfce8*/;
    cpu.esp -= 4;
    // 004766ca  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004766cc  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004766d1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004766d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004766d5  e856920100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004766da  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004766dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004766df  b866040000             -mov eax, 0x466
    cpu.eax = 1126 /*0x466*/;
    // 004766e4  e8a7150000             -call 0x477c90
    cpu.esp -= 4;
    sub_477c90(app, cpu);
    if (cpu.terminate) return;
    // 004766e9  833dc4d7510000         +cmp dword ptr [0x51d7c4], 0
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
    // 004766f0  741a                   -je 0x47670c
    if (cpu.flags.zf)
    {
        goto L_0x0047670c;
    }
    // 004766f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004766f4:
    // 004766f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004766f6  e821a10000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004766fb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004766fd  e83e350000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00476702  3b15c4d75100           +cmp edx, dword ptr [0x51d7c4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476708  75ea                   -jne 0x4766f4
    if (!cpu.flags.zf)
    {
        goto L_0x004766f4;
    }
    // 0047670a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047670c:
    // 0047670c  680cfd4b00             -push 0x4bfd0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979980 /*0x4bfd0c*/;
    cpu.esp -= 4;
    // 00476711  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00476713  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476718  e813920100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 0047671d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476720  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476721  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476722  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476723  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476731  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476732  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476733  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476734  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00476737  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476739  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0047673d  833d8ca34c0000         +cmp dword ptr [0x4ca38c], 0
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
    // 00476744  750a                   -jne 0x476750
    if (!cpu.flags.zf)
    {
        goto L_0x00476750;
    }
    // 00476746  e82da40000             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 0047674b  a38ca34c00             -mov dword ptr [0x4ca38c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */) = cpu.eax;
L_0x00476750:
    // 00476750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476751  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00476755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476756  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476757  6854fc4b00             -push 0x4bfc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979796 /*0x4bfc54*/;
    cpu.esp -= 4;
    // 0047675c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047675e  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476763  e8c8910100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476768  8a25e0d05100           -mov ah, byte ptr [0x51d0e0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5361888) /* 0x51d0e0 */);
    // 0047676e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00476771  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00476773  0f85c2020000           -jne 0x476a3b
    if (!cpu.flags.zf)
    {
        goto L_0x00476a3b;
    }
    // 00476779  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047677b  2eff1504754b00         -call dword ptr cs:[0x4b7504]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945156) /* 0x4b7504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476782  8b3d98a34c00           -mov edi, dword ptr [0x4ca398]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */);
    // 00476788  a3e0d75100             -mov dword ptr [0x51d7e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5363680) /* 0x51d7e0 */) = cpu.eax;
    // 0047678d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047678f  750c                   -jne 0x47679d
    if (!cpu.flags.zf)
    {
        goto L_0x0047679d;
    }
    // 00476791  a1ec845200             -mov eax, dword ptr [0x5284ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */);
    // 00476796  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00476798  a398a34c00             -mov dword ptr [0x4ca398], eax
    app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */) = cpu.eax;
L_0x0047679d:
    // 0047679d  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 004767a2  ba40704700             -mov edx, 0x477040
    cpu.edx = 4681792 /*0x477040*/;
    // 004767a7  8b3d9ca34c00           -mov edi, dword ptr [0x4ca39c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022620) /* 0x4ca39c */);
    // 004767ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004767af  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004767b2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004767b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004767b7  a1e0d75100             -mov eax, dword ptr [0x51d7e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363680) /* 0x51d7e0 */);
    // 004767bc  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004767c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004767c1  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004767c5  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004767c9  2eff15fc734b00         -call dword ptr cs:[0x4b73fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944892) /* 0x4b73fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004767d0  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004767d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004767d4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004767d8  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004767dc  2eff15a8734b00         -call dword ptr cs:[0x4b73a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944808) /* 0x4b73a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004767e3  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004767e7  a198a34c00             -mov eax, dword ptr [0x4ca398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */);
    // 004767ec  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004767f0  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004767f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004767f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004767f7  2eff1510744b00         -call dword ptr cs:[0x4b7410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944912) /* 0x4b7410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004767fe  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00476801  0f84ff010000           -je 0x476a06
    if (cpu.flags.zf)
    {
        goto L_0x00476a06;
    }
    // 00476807  e86ca30000             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 0047680c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00476811  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00476813  68f0774700             -push 0x4777f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683760 /*0x4777f0*/;
    cpu.esp -= 4;
    // 00476818  a3c8d05100             -mov dword ptr [0x51d0c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */) = cpu.eax;
    // 0047681d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047681f  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00476821  890dd0d05100           -mov dword ptr [0x51d0d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5361872) /* 0x51d0d0 */) = cpu.ecx;
    // 00476827  8935c4d05100           -mov dword ptr [0x51d0c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */) = cpu.esi;
    // 0047682d  8935ccd05100           -mov dword ptr [0x51d0cc], esi
    app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */) = cpu.esi;
    // 00476833  8815e0d05100           -mov byte ptr [0x51d0e0], dl
    app->getMemory<x86::reg8>(x86::reg32(5361888) /* 0x51d0e0 */) = cpu.dl;
    // 00476839  e8e2140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047683e  6870774700             -push 0x477770
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683632 /*0x477770*/;
    cpu.esp -= 4;
    // 00476843  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00476845  e8d6140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047684a  6810774700             -push 0x477710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683536 /*0x477710*/;
    cpu.esp -= 4;
    // 0047684f  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00476851  e8ca140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476856  68f0744700             -push 0x4774f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682992 /*0x4774f0*/;
    cpu.esp -= 4;
    // 0047685b  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0047685d  e8be140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476862  68f0744700             -push 0x4774f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682992 /*0x4774f0*/;
    cpu.esp -= 4;
    // 00476867  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00476869  e8b2140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047686e  68d0764700             -push 0x4776d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683472 /*0x4776d0*/;
    cpu.esp -= 4;
    // 00476873  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00476875  e8a6140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047687a  6860764700             -push 0x477660
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683360 /*0x477660*/;
    cpu.esp -= 4;
    // 0047687f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00476881  e89a140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476886  6890714700             -push 0x477190
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682128 /*0x477190*/;
    cpu.esp -= 4;
    // 0047688b  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0047688d  e88e140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476892  6850714700             -push 0x477150
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682064 /*0x477150*/;
    cpu.esp -= 4;
    // 00476897  6885000000             -push 0x85
    app->getMemory<x86::reg32>(cpu.esp-4) = 133 /*0x85*/;
    cpu.esp -= 4;
    // 0047689c  e87f140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768a1  6870754700             -push 0x477570
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683120 /*0x477570*/;
    cpu.esp -= 4;
    // 004768a6  6a1a                   -push 0x1a
    app->getMemory<x86::reg32>(cpu.esp-4) = 26 /*0x1a*/;
    cpu.esp -= 4;
    // 004768a8  e873140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768ad  6820764700             -push 0x477620
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683296 /*0x477620*/;
    cpu.esp -= 4;
    // 004768b2  6812010000             -push 0x112
    app->getMemory<x86::reg32>(cpu.esp-4) = 274 /*0x112*/;
    cpu.esp -= 4;
    // 004768b7  e864140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768bc  6890764700             -push 0x477690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4683408 /*0x477690*/;
    cpu.esp -= 4;
    // 004768c1  6866040000             -push 0x466
    app->getMemory<x86::reg32>(cpu.esp-4) = 1126 /*0x466*/;
    cpu.esp -= 4;
    // 004768c6  e855140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768cb  6880744700             -push 0x477480
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682880 /*0x477480*/;
    cpu.esp -= 4;
    // 004768d0  6802010000             -push 0x102
    app->getMemory<x86::reg32>(cpu.esp-4) = 258 /*0x102*/;
    cpu.esp -= 4;
    // 004768d5  e846140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768da  6860734700             -push 0x477360
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682592 /*0x477360*/;
    cpu.esp -= 4;
    // 004768df  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004768e4  e837140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768e9  6860734700             -push 0x477360
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682592 /*0x477360*/;
    cpu.esp -= 4;
    // 004768ee  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004768f3  e828140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004768f8  6810734700             -push 0x477310
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682512 /*0x477310*/;
    cpu.esp -= 4;
    // 004768fd  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 00476902  e819140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476907  6810734700             -push 0x477310
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682512 /*0x477310*/;
    cpu.esp -= 4;
    // 0047690c  6805010000             -push 0x105
    app->getMemory<x86::reg32>(cpu.esp-4) = 261 /*0x105*/;
    cpu.esp -= 4;
    // 00476911  e80a140000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476916  68a0724700             -push 0x4772a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682400 /*0x4772a0*/;
    cpu.esp -= 4;
    // 0047691b  6801020000             -push 0x201
    app->getMemory<x86::reg32>(cpu.esp-4) = 513 /*0x201*/;
    cpu.esp -= 4;
    // 00476920  e8fb130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476925  68a0724700             -push 0x4772a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682400 /*0x4772a0*/;
    cpu.esp -= 4;
    // 0047692a  6807020000             -push 0x207
    app->getMemory<x86::reg32>(cpu.esp-4) = 519 /*0x207*/;
    cpu.esp -= 4;
    // 0047692f  e8ec130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476934  68a0724700             -push 0x4772a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682400 /*0x4772a0*/;
    cpu.esp -= 4;
    // 00476939  6804020000             -push 0x204
    app->getMemory<x86::reg32>(cpu.esp-4) = 516 /*0x204*/;
    cpu.esp -= 4;
    // 0047693e  e8dd130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476943  68a0724700             -push 0x4772a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682400 /*0x4772a0*/;
    cpu.esp -= 4;
    // 00476948  6803020000             -push 0x203
    app->getMemory<x86::reg32>(cpu.esp-4) = 515 /*0x203*/;
    cpu.esp -= 4;
    // 0047694d  e8ce130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476952  68a0724700             -push 0x4772a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682400 /*0x4772a0*/;
    cpu.esp -= 4;
    // 00476957  6809020000             -push 0x209
    app->getMemory<x86::reg32>(cpu.esp-4) = 521 /*0x209*/;
    cpu.esp -= 4;
    // 0047695c  e8bf130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476961  68a0724700             -push 0x4772a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682400 /*0x4772a0*/;
    cpu.esp -= 4;
    // 00476966  6806020000             -push 0x206
    app->getMemory<x86::reg32>(cpu.esp-4) = 518 /*0x206*/;
    cpu.esp -= 4;
    // 0047696b  e8b0130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 00476970  6830724700             -push 0x477230
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682288 /*0x477230*/;
    cpu.esp -= 4;
    // 00476975  6802020000             -push 0x202
    app->getMemory<x86::reg32>(cpu.esp-4) = 514 /*0x202*/;
    cpu.esp -= 4;
    // 0047697a  e8a1130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047697f  6830724700             -push 0x477230
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682288 /*0x477230*/;
    cpu.esp -= 4;
    // 00476984  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00476989  e892130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047698e  6830724700             -push 0x477230
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682288 /*0x477230*/;
    cpu.esp -= 4;
    // 00476993  6805020000             -push 0x205
    app->getMemory<x86::reg32>(cpu.esp-4) = 517 /*0x205*/;
    cpu.esp -= 4;
    // 00476998  e883130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047699d  6830724700             -push 0x477230
    app->getMemory<x86::reg32>(cpu.esp-4) = 4682288 /*0x477230*/;
    cpu.esp -= 4;
    // 004769a2  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004769a7  e874130000             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
L_0x004769ac:
    // 004769ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004769b1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004769b6  881dcdd75100           -mov byte ptr [0x51d7cd], bl
    app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */) = cpu.bl;
    // 004769bc  a3e4d75100             -mov dword ptr [0x51d7e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5363684) /* 0x51d7e4 */) = cpu.eax;
    // 004769c1  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004769c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004769c7  a388d35100             -mov dword ptr [0x51d388], eax
    app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */) = cpu.eax;
    // 004769cc  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004769d0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004769d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004769d6  b8506b4700             -mov eax, 0x476b50
    cpu.eax = 4680528 /*0x476b50*/;
    // 004769db  892d84d35100           -mov dword ptr [0x51d384], ebp
    app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */) = cpu.ebp;
    // 004769e1  e87a9d0000             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 004769e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004769e8  7449                   -je 0x476a33
    if (cpu.flags.zf)
    {
        goto L_0x00476a33;
    }
    // 004769ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004769ec:
    // 004769ec  8b1d68a34c00           -mov ebx, dword ptr [0x4ca368]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */);
    // 004769f2  39da                   +cmp edx, ebx
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
    // 004769f4  7571                   -jne 0x476a67
    if (!cpu.flags.zf)
    {
        goto L_0x00476a67;
    }
    // 004769f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004769f8  e843320000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 004769fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004769ff  e8189e0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00476a04  ebe6                   -jmp 0x4769ec
    goto L_0x004769ec;
L_0x00476a06:
    // 00476a06  ba78fc4b00             -mov edx, 0x4bfc78
    cpu.edx = 4979832 /*0x4bfc78*/;
    // 00476a0b  b950030000             -mov ecx, 0x350
    cpu.ecx = 848 /*0x350*/;
    // 00476a10  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00476a16  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 00476a1c  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476a23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476a24  6898fc4b00             -push 0x4bfc98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979864 /*0x4bfc98*/;
    cpu.esp -= 4;
    // 00476a29  e852340000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00476a2e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476a31  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00476a33:
    // 00476a33  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00476a36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476a3b:
    // 00476a3b  833dc4d7510000         +cmp dword ptr [0x51d7c4], 0
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
    // 00476a42  0f8464ffffff           -je 0x4769ac
    if (cpu.flags.zf)
    {
        goto L_0x004769ac;
    }
    // 00476a48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476a4a  a0cdd75100             -mov al, byte ptr [0x51d7cd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 00476a4f  39c3                   +cmp ebx, eax
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
    // 00476a51  0f8455ffffff           -je 0x4769ac
    if (cpu.flags.zf)
    {
        goto L_0x004769ac;
    }
    // 00476a57  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00476a59  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476a5b  e800fbffff             -call 0x476560
    cpu.esp -= 4;
    sub_476560(app, cpu);
    if (cpu.terminate) return;
    // 00476a60  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00476a65  ebcc                   -jmp 0x476a33
    goto L_0x00476a33;
L_0x00476a67:
    // 00476a67  833dc4d7510000         +cmp dword ptr [0x51d7c4], 0
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
    // 00476a6e  7405                   -je 0x476a75
    if (cpu.flags.zf)
    {
        goto L_0x00476a75;
    }
    // 00476a70  e8fbfbffff             -call 0x476670
    cpu.esp -= 4;
    sub_476670(app, cpu);
    if (cpu.terminate) return;
L_0x00476a75:
    // 00476a75  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00476a79  8b1568a34c00           -mov edx, dword ptr [0x4ca368]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */);
    // 00476a7f  e81ca00000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00476a84  833d68a34c0000         +cmp dword ptr [0x4ca368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476a8b  741b                   -je 0x476aa8
    if (cpu.flags.zf)
    {
        goto L_0x00476aa8;
    }
    // 00476a8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00476a8f:
    // 00476a8f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476a91  e8869d0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00476a96  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476a98  e8a3310000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00476a9d  3b1568a34c00           +cmp edx, dword ptr [0x4ca368]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476aa3  75ea                   -jne 0x476a8f
    if (!cpu.flags.zf)
    {
        goto L_0x00476a8f;
    }
    // 00476aa5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00476aa8:
    // 00476aa8  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00476aac  bfb0d05100             -mov edi, 0x51d0b0
    cpu.edi = 5361840 /*0x51d0b0*/;
    // 00476ab1  8a35cdd75100           -mov dh, byte ptr [0x51d7cd]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 00476ab7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476ab8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476ab9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476aba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476abb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00476abc  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00476abe  7461                   -je 0x476b21
    if (cpu.flags.zf)
    {
        goto L_0x00476b21;
    }
    // 00476ac0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476ac2  6870a34c00             -push 0x4ca370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022576 /*0x4ca370*/;
    cpu.esp -= 4;
    // 00476ac7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476ac9  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00476acb  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476ad2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476ad4  6874a34c00             -push 0x4ca374
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022580 /*0x4ca374*/;
    cpu.esp -= 4;
    // 00476ad9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476adb  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 00476add  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476ae4  833d70a34c0000         +cmp dword ptr [0x4ca370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022576) /* 0x4ca370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476aeb  740f                   -je 0x476afc
    if (cpu.flags.zf)
    {
        goto L_0x00476afc;
    }
    // 00476aed  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00476aef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476af1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476af3  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00476af5  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00476afc:
    // 00476afc  833d74a34c0000         +cmp dword ptr [0x4ca374], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022580) /* 0x4ca374 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476b03  740f                   -je 0x476b14
    if (cpu.flags.zf)
    {
        goto L_0x00476b14;
    }
    // 00476b05  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00476b07  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476b09  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476b0b  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 00476b0d  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00476b14:
    // 00476b14  a1c4d75100             -mov eax, dword ptr [0x51d7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00476b19  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00476b1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476b21:
    // 00476b21  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00476b25  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476b27  e834faffff             -call 0x476560
    cpu.esp -= 4;
    sub_476560(app, cpu);
    if (cpu.terminate) return;
    // 00476b2c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476b2e  891570a34c00           -mov dword ptr [0x4ca370], edx
    app->getMemory<x86::reg32>(x86::reg32(5022576) /* 0x4ca370 */) = cpu.edx;
    // 00476b34  891574a34c00           -mov dword ptr [0x4ca374], edx
    app->getMemory<x86::reg32>(x86::reg32(5022580) /* 0x4ca374 */) = cpu.edx;
    // 00476b3a  a1c4d75100             -mov eax, dword ptr [0x51d7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00476b3f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00476b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476b50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476b51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476b52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476b53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476b54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476b55  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00476b58  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00476b5d  e8fe010000             -call 0x476d60
    cpu.esp -= 4;
    sub_476d60(app, cpu);
    if (cpu.terminate) return;
    // 00476b62  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476b64  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476b66  e8219f0000             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 00476b6b  a368a34c00             -mov dword ptr [0x4ca368], eax
    app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */) = cpu.eax;
    // 00476b70  e8679f0000             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00476b75  a168a34c00             -mov eax, dword ptr [0x4ca368]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */);
    // 00476b7a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476b7c  e8e79f0000             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 00476b81  8a25cdd75100           -mov ah, byte ptr [0x51d7cd]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5363661) /* 0x51d7cd */);
    // 00476b87  891dc4d75100           -mov dword ptr [0x51d7c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */) = cpu.ebx;
    // 00476b8d  89156ca34c00           -mov dword ptr [0x4ca36c], edx
    app->getMemory<x86::reg32>(x86::reg32(5022572) /* 0x4ca36c */) = cpu.edx;
    // 00476b93  891568a34c00           -mov dword ptr [0x4ca368], edx
    app->getMemory<x86::reg32>(x86::reg32(5022568) /* 0x4ca368 */) = cpu.edx;
    // 00476b99  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00476b9b  0f845a010000           -je 0x476cfb
    if (cpu.flags.zf)
    {
        goto L_0x00476cfb;
    }
    // 00476ba1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476ba2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476ba4  2eff1524744b00         -call dword ptr cs:[0x4b7424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944932) /* 0x4b7424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476bab  891dd4d75100           -mov dword ptr [0x51d7d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5363668) /* 0x51d7d4 */) = cpu.ebx;
    // 00476bb1  891dd8d75100           -mov dword ptr [0x51d7d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5363672) /* 0x51d7d8 */) = cpu.ebx;
L_0x00476bb7:
    // 00476bb7  68b4fb4b00             -push 0x4bfbb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979636 /*0x4bfbb4*/;
    cpu.esp -= 4;
    // 00476bbc  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00476bbe  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476bc3  e8688d0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476bc8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476bcb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476bcc  2eff1518744b00         -call dword ptr cs:[0x4b7418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944920) /* 0x4b7418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476bd3  3b35c4d75100           +cmp esi, dword ptr [0x51d7c4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476bd9  0f85ff000000           -jne 0x476cde
    if (!cpu.flags.zf)
    {
        goto L_0x00476cde;
    }
L_0x00476bdf:
    // 00476bdf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476be1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476be3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476be5  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476be9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476bea  2eff15f0734b00         -call dword ptr cs:[0x4b73f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944880) /* 0x4b73f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476bf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476bf3  0f8433010000           -je 0x476d2c
    if (cpu.flags.zf)
    {
        goto L_0x00476d2c;
    }
    // 00476bf9  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00476bfe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476bff  68d4fb4b00             -push 0x4bfbd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979668 /*0x4bfbd4*/;
    cpu.esp -= 4;
    // 00476c04  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00476c06  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476c0b  e8208d0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476c10  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476c13  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00476c18  e8ab9f0000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00476c1d  833dd8d0510000         +cmp dword ptr [0x51d0d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5361880) /* 0x51d0d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476c24  751b                   -jne 0x476c41
    if (!cpu.flags.zf)
    {
        goto L_0x00476c41;
    }
    // 00476c26  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476c2a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476c2e  e8fd0b0000             -call 0x477830
    cpu.esp -= 4;
    sub_477830(app, cpu);
    if (cpu.terminate) return;
    // 00476c33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476c35  750a                   -jne 0x476c41
    if (!cpu.flags.zf)
    {
        goto L_0x00476c41;
    }
    // 00476c37  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476c39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476c3a  2eff153c744b00         -call dword ptr cs:[0x4b743c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944956) /* 0x4b743c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00476c41:
    // 00476c41  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476c43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476c44  2eff15d4734b00         -call dword ptr cs:[0x4b73d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944852) /* 0x4b73d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476c4b  a18ca34c00             -mov eax, dword ptr [0x4ca38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022604) /* 0x4ca38c */);
    // 00476c50  e88b9f0000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00476c55  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00476c5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476c5b  68e4fb4b00             -push 0x4bfbe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979684 /*0x4bfbe4*/;
    cpu.esp -= 4;
    // 00476c60  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00476c62  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476c67  e8c48c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476c6c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00476c6f:
    // 00476c6f  833d6ca34c0000         +cmp dword ptr [0x4ca36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022572) /* 0x4ca36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476c76  745a                   -je 0x476cd2
    if (cpu.flags.zf)
    {
        goto L_0x00476cd2;
    }
    // 00476c78  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476c7a  8b3d70d35100           -mov edi, dword ptr [0x51d370]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5362544) /* 0x51d370 */);
    // 00476c80  891d6ca34c00           -mov dword ptr [0x4ca36c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022572) /* 0x4ca36c */) = cpu.ebx;
    // 00476c86  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00476c88  7427                   -je 0x476cb1
    if (cpu.flags.zf)
    {
        goto L_0x00476cb1;
    }
    // 00476c8a  833d80d3510000         +cmp dword ptr [0x51d380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5362560) /* 0x51d380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476c91  741e                   -je 0x476cb1
    if (cpu.flags.zf)
    {
        goto L_0x00476cb1;
    }
    // 00476c93  680cfc4b00             -push 0x4bfc0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979724 /*0x4bfc0c*/;
    cpu.esp -= 4;
    // 00476c98  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476c9a  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476c9f  e88c8c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476ca4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476ca7  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00476cac  e833190100             -call 0x4885e4
    cpu.esp -= 4;
    sub_4885e4(app, cpu);
    if (cpu.terminate) return;
L_0x00476cb1:
    // 00476cb1  6828fc4b00             -push 0x4bfc28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979752 /*0x4bfc28*/;
    cpu.esp -= 4;
    // 00476cb6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476cb8  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476cbd  e86e8c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476cc2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476cc5  a1c4d75100             -mov eax, dword ptr [0x51d7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00476cca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476ccb  2eff15d0734b00         -call dword ptr cs:[0x4b73d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944848) /* 0x4b73d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00476cd2:
    // 00476cd2  3b35c4d75100           +cmp esi, dword ptr [0x51d7c4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476cd8  0f8401ffffff           -je 0x476bdf
    if (cpu.flags.zf)
    {
        goto L_0x00476bdf;
    }
L_0x00476cde:
    // 00476cde  6838fc4b00             -push 0x4bfc38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979768 /*0x4bfc38*/;
    cpu.esp -= 4;
    // 00476ce3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476ce5  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476cea  e8418c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476cef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476cf2  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476cf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cf7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476cfb:
    // 00476cfb  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00476cff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476d01  2eff15e4734b00         -call dword ptr cs:[0x4b73e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944868) /* 0x4b73e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476d08  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00476d0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476d0d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476d0e  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476d15  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00476d19  a3d4d75100             -mov dword ptr [0x51d7d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5363668) /* 0x51d7d4 */) = cpu.eax;
    // 00476d1e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00476d22  a3d8d75100             -mov dword ptr [0x51d7d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5363672) /* 0x51d7d8 */) = cpu.eax;
    // 00476d27  e98bfeffff             -jmp 0x476bb7
    goto L_0x00476bb7;
L_0x00476d2c:
    // 00476d2c  68f4fb4b00             -push 0x4bfbf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979700 /*0x4bfbf4*/;
    cpu.esp -= 4;
    // 00476d31  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00476d33  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476d38  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00476d3d  e8ee8b0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476d42  83c40c                 +add esp, 0xc
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
    // 00476d45  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00476d4a  b8507c4700             -mov eax, 0x477c50
    cpu.eax = 4684880 /*0x477c50*/;
    // 00476d4f  e80c2e0000             -call 0x479b60
    cpu.esp -= 4;
    sub_479b60(app, cpu);
    if (cpu.terminate) return;
    // 00476d54  e916ffffff             -jmp 0x476c6f
    goto L_0x00476c6f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476d61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476d62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476d63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476d64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476d65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476d66  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476d69  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476d6b  8aa05d040000           -mov ah, byte ptr [eax + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
    // 00476d71  8b3588a34c00           -mov esi, dword ptr [0x4ca388]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022600) /* 0x4ca388 */);
    // 00476d77  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00476d79  0f8503010000           -jne 0x476e82
    if (!cpu.flags.zf)
    {
        goto L_0x00476e82;
    }
    // 00476d7f  8a15dca34c00           -mov dl, byte ptr [0x4ca3dc]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 00476d85  81ce0000ca00           -or esi, 0xca0000
    cpu.esi |= x86::reg32(x86::sreg32(13238272 /*0xca0000*/));
    // 00476d8b  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00476d8e  0f8428010000           -je 0x476ebc
    if (cpu.flags.zf)
    {
        goto L_0x00476ebc;
    }
    // 00476d94  81ce00000500           -or esi, 0x50000
    cpu.esi |= x86::reg32(x86::sreg32(327680 /*0x50000*/));
L_0x00476d9a:
    // 00476d9a  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476da1  0f8420010000           -je 0x476ec7
    if (cpu.flags.zf)
    {
        goto L_0x00476ec7;
    }
    // 00476da7  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00476dad  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00476db1  8b8364040000           -mov eax, dword ptr [ebx + 0x464]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00476db7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00476dba:
    // 00476dba  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476dbe  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00476dc1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00476dc3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00476dc7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00476dca  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00476dcd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476dcf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476dd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476dd2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00476dd6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476dda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476ddb  2eff15b0734b00         -call dword ptr cs:[0x4b73b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944816) /* 0x4b73b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476de2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00476de5  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 00476deb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476def  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00476df5  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476df9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00476dfc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476e00  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00476e02  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00476e04  b900000400             -mov ecx, 0x40000
    cpu.ecx = 262144 /*0x40000*/;
L_0x00476e09:
    // 00476e09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476e0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476e0b  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00476e11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476e12  8bab64040000           -mov ebp, dword ptr [ebx + 0x464]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00476e18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476e19  6868fb4b00             -push 0x4bfb68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979560 /*0x4bfb68*/;
    cpu.esp -= 4;
    // 00476e1e  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00476e20  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476e25  e8068b0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476e2a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00476e2d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476e2f  a1e0d75100             -mov eax, dword ptr [0x51d7e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363680) /* 0x51d7e0 */);
    // 00476e34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476e35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476e37  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476e39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476e3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476e3b  8b9368040000           -mov edx, dword ptr [ebx + 0x468]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00476e41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476e42  8bbb64040000           -mov edi, dword ptr [ebx + 0x464]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00476e48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476e49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476e4a  8b2d98a34c00           -mov ebp, dword ptr [0x4ca398]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */);
    // 00476e50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476e51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476e52  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476e53  2eff15c8734b00         -call dword ptr cs:[0x4b73c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944840) /* 0x4b73c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476e5a  6898fb4b00             -push 0x4bfb98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979608 /*0x4bfb98*/;
    cpu.esp -= 4;
    // 00476e5f  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00476e61  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00476e66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476e68  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476e6a  e8c18a0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00476e6f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476e72  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476e74  7562                   -jne 0x476ed8
    if (!cpu.flags.zf)
    {
        goto L_0x00476ed8;
    }
L_0x00476e76:
    // 00476e76  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476e78  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476e7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476e82:
    // 00476e82  c7836404000000000000   -mov dword ptr [ebx + 0x464], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = 0 /*0x0*/;
    // 00476e8c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476e8e  c7836804000000000000   -mov dword ptr [ebx + 0x468], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = 0 /*0x0*/;
    // 00476e98  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476e9f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476ea1  81ce00000080           +or esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 00476ea7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476ea9  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476eb0  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00476eb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476eb7  e94dffffff             -jmp 0x476e09
    goto L_0x00476e09;
L_0x00476ebc:
    // 00476ebc  81ce00008000           +or esi, 0x800000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(8388608 /*0x800000*/))));
    // 00476ec2  e9d3feffff             -jmp 0x476d9a
    goto L_0x00476d9a;
L_0x00476ec7:
    // 00476ec7  b900e0ffff             -mov ecx, 0xffffe000
    cpu.ecx = 4294959104 /*0xffffe000*/;
    // 00476ecc  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00476ecf  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00476ed3  e9e2feffff             -jmp 0x476dba
    goto L_0x00476dba;
L_0x00476ed8:
    // 00476ed8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476eda  2eff151c744b00         -call dword ptr cs:[0x4b741c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944924) /* 0x4b741c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476ee1  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476ee8  7409                   -je 0x476ef3
    if (cpu.flags.zf)
    {
        goto L_0x00476ef3;
    }
    // 00476eea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476eec  2eff1530744b00         -call dword ptr cs:[0x4b7430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944944) /* 0x4b7430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00476ef3:
    // 00476ef3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476ef5  8b0d94a34c00           -mov ecx, dword ptr [0x4ca394]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022612) /* 0x4ca394 */);
    // 00476efb  89156ca74c00           -mov dword ptr [0x4ca76c], edx
    app->getMemory<x86::reg32>(x86::reg32(5023596) /* 0x4ca76c */) = cpu.edx;
    // 00476f01  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476f03  0f856dffffff           -jne 0x476e76
    if (!cpu.flags.zf)
    {
        goto L_0x00476e76;
    }
    // 00476f09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476f0b  e800f10100             -call 0x496010
    cpu.esp -= 4;
    sub_496010(app, cpu);
    if (cpu.terminate) return;
    // 00476f10  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00476f15  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476f17  e8f4f00100             -call 0x496010
    cpu.esp -= 4;
    sub_496010(app, cpu);
    if (cpu.terminate) return;
    // 00476f1c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00476f21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476f23  e8e8f00100             -call 0x496010
    cpu.esp -= 4;
    sub_496010(app, cpu);
    if (cpu.terminate) return;
    // 00476f28  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476f2a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476f2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476f40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476f41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476f42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476f43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476f44  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00476f48  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476f4c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476f4e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476f50  754b                   -jne 0x476f9d
    if (!cpu.flags.zf)
    {
        goto L_0x00476f9d;
    }
    // 00476f52  833d78a34c0000         +cmp dword ptr [0x4ca378], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022584) /* 0x4ca378 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f59  7442                   -je 0x476f9d
    if (cpu.flags.zf)
    {
        goto L_0x00476f9d;
    }
    // 00476f5b  833de4d7510000         +cmp dword ptr [0x51d7e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363684) /* 0x51d7e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f62  7439                   -je 0x476f9d
    if (cpu.flags.zf)
    {
        goto L_0x00476f9d;
    }
    // 00476f64  833d80a34c0000         +cmp dword ptr [0x4ca380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022592) /* 0x4ca380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f6b  744f                   -je 0x476fbc
    if (cpu.flags.zf)
    {
        goto L_0x00476fbc;
    }
    // 00476f6d  f644241f20             +test byte ptr [esp + 0x1f], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */) & 32 /*0x20*/));
    // 00476f72  7448                   -je 0x476fbc
    if (cpu.flags.zf)
    {
        goto L_0x00476fbc;
    }
    // 00476f74  bd38000000             -mov ebp, 0x38
    cpu.ebp = 56 /*0x38*/;
    // 00476f79  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f7c  7530                   -jne 0x476fae
    if (!cpu.flags.zf)
    {
        goto L_0x00476fae;
    }
    // 00476f7e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00476f83  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
L_0x00476f88:
    // 00476f88  833d84a34c0000         +cmp dword ptr [0x4ca384], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022596) /* 0x4ca384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476f8f  740c                   -je 0x476f9d
    if (cpu.flags.zf)
    {
        goto L_0x00476f9d;
    }
    // 00476f91  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00476f93  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476f95  ff1584a34c00           -call dword ptr [0x4ca384]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022596) /* 0x4ca384 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476f9b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00476f9d:
    // 00476f9d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476f9f  0f846b000000           -je 0x477010
    if (cpu.flags.zf)
    {
        goto L_0x00477010;
    }
    // 00476fa5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476fa7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fa8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476faa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fab  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00476fae:
    // 00476fae  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476fb1  7536                   -jne 0x476fe9
    if (!cpu.flags.zf)
    {
        goto L_0x00476fe9;
    }
    // 00476fb3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00476fb8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00476fba  ebcc                   -jmp 0x476f88
    goto L_0x00476f88;
L_0x00476fbc:
    // 00476fbc  83fe5b                 +cmp esi, 0x5b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476fbf  750b                   -jne 0x476fcc
    if (!cpu.flags.zf)
    {
        goto L_0x00476fcc;
    }
L_0x00476fc1:
    // 00476fc1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00476fc6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00476fc8  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00476fca  ebbc                   -jmp 0x476f88
    goto L_0x00476f88;
L_0x00476fcc:
    // 00476fcc  83fe5c                 +cmp esi, 0x5c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476fcf  74f0                   -je 0x476fc1
    if (cpu.flags.zf)
    {
        goto L_0x00476fc1;
    }
    // 00476fd1  83fe5d                 +cmp esi, 0x5d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476fd4  74eb                   -je 0x476fc1
    if (cpu.flags.zf)
    {
        goto L_0x00476fc1;
    }
    // 00476fd6  83fe2c                 +cmp esi, 0x2c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476fd9  74e6                   -je 0x476fc1
    if (cpu.flags.zf)
    {
        goto L_0x00476fc1;
    }
    // 00476fdb  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00476fdd  2eff15e0734b00         -call dword ptr cs:[0x4b73e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944864) /* 0x4b73e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476fe4  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00476fe7  7c11                   -jl 0x476ffa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476ffa;
    }
L_0x00476fe9:
    // 00476fe9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476feb  759b                   -jne 0x476f88
    if (!cpu.flags.zf)
    {
        goto L_0x00476f88;
    }
    // 00476fed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476fef  741f                   -je 0x477010
    if (cpu.flags.zf)
    {
        goto L_0x00477010;
    }
    // 00476ff1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476ff3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ff4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ff5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ff6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ff7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00476ffa:
    // 00476ffa  bd1d000000             -mov ebp, 0x1d
    cpu.ebp = 29 /*0x1d*/;
    // 00476fff  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477002  75e5                   -jne 0x476fe9
    if (!cpu.flags.zf)
    {
        goto L_0x00476fe9;
    }
    // 00477004  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00477009  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047700b  e978ffffff             -jmp 0x476f88
    goto L_0x00476f88;
L_0x00477010:
    // 00477010  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00477014  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477015  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477016  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047701a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047701b  8b3d7ca34c00           -mov edi, dword ptr [0x4ca37c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022588) /* 0x4ca37c */);
    // 00477021  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477022  2eff15b8734b00         -call dword ptr cs:[0x4b73b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944824) /* 0x4b73b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477029  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047702b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047702d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047702e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047702f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477030  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477031  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477041  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477042  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477043  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477044  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00477046  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477049  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047704c  b970d35100             -mov ecx, 0x51d370
    cpu.ecx = 5362544 /*0x51d370*/;
    // 00477051  68807e4700             -push 0x477e80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4685440 /*0x477e80*/;
    cpu.esp -= 4;
    // 00477056  bab0cc5100             -mov edx, 0x51ccb0
    cpu.edx = 5360816 /*0x51ccb0*/;
    // 0047705b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047705e  8b1d64a34c00           -mov ebx, dword ptr [0x4ca364]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022564) /* 0x4ca364 */);
    // 00477064  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 00477067  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00477069  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047706c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00477071  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 00477074  e828e70100             -call 0x4957a1
    cpu.esp -= 4;
    sub_4957a1(app, cpu);
    if (cpu.terminate) return;
    // 00477079  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047707b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047707d  0f8486000000           -je 0x477109
    if (cpu.flags.zf)
    {
        goto L_0x00477109;
    }
    // 00477083  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
L_0x00477088:
    // 00477088  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477089  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047708c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047708d  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00477090  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00477093  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477094  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477096  0f8477000000           -je 0x477113
    if (cpu.flags.zf)
    {
        goto L_0x00477113;
    }
    // 0047709c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004770a1:
    // 004770a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004770a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004770a3  6848fb4b00             -push 0x4bfb48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979528 /*0x4bfb48*/;
    cpu.esp -= 4;
    // 004770a8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004770aa  746b                   -je 0x477117
    if (cpu.flags.zf)
    {
        goto L_0x00477117;
    }
    // 004770ac  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x004770b1:
    // 004770b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004770b2  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004770b7  e874880100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004770bc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004770bf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004770c1  741a                   -je 0x4770dd
    if (cpu.flags.zf)
    {
        goto L_0x004770dd;
    }
    // 004770c3  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004770c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004770c7  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004770ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004770cb  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004770ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004770cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004770d0  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004770d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004770d4  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004770d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004770d8  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004770db  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004770dd:
    // 004770dd  6864fb4b00             -push 0x4bfb64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979556 /*0x4bfb64*/;
    cpu.esp -= 4;
    // 004770e2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004770e4  7438                   -je 0x47711e
    if (cpu.flags.zf)
    {
        goto L_0x0047711e;
    }
    // 004770e6  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004770eb:
    // 004770eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004770ec  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004770f1  e83a880100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004770f6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004770f9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004770fb  7428                   -je 0x477125
    if (cpu.flags.zf)
    {
        goto L_0x00477125;
    }
    // 004770fd  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00477100  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00477102  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477103  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477104  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477105  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477106  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00477109:
    // 00477109  b83b000000             -mov eax, 0x3b
    cpu.eax = 59 /*0x3b*/;
    // 0047710e  e975ffffff             -jmp 0x477088
    goto L_0x00477088;
L_0x00477113:
    // 00477113  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00477115  eb8a                   -jmp 0x4770a1
    goto L_0x004770a1;
L_0x00477117:
    // 00477117  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047711c  eb93                   -jmp 0x4770b1
    goto L_0x004770b1;
L_0x0047711e:
    // 0047711e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00477123  ebc6                   -jmp 0x4770eb
    goto L_0x004770eb;
L_0x00477125:
    // 00477125  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00477128  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477129  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047712c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047712d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047712e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00477131  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477132  2eff15cc734b00         -call dword ptr cs:[0x4b73cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944844) /* 0x4b73cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477139  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0047713b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047713c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047713d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047713e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047713f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477150  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477154  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477156  741d                   -je 0x477175
    if (cpu.flags.zf)
    {
        goto L_0x00477175;
    }
    // 00477158  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047715c  3b9054040000           +cmp edx, dword ptr [eax + 0x454]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477162  7511                   -jne 0x477175
    if (!cpu.flags.zf)
    {
        goto L_0x00477175;
    }
    // 00477164  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047716b  7408                   -je 0x477175
    if (cpu.flags.zf)
    {
        goto L_0x00477175;
    }
    // 0047716d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477172  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00477175:
    // 00477175  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0047717a  e8499a0000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0047717f  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00477184  e8579a0000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477189  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047718b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_477190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477191  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00477194  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00477198  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047719a  7409                   -je 0x4771a5
    if (cpu.flags.zf)
    {
        goto L_0x004771a5;
    }
    // 0047719c  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004771a3  750c                   -jne 0x4771b1
    if (!cpu.flags.zf)
    {
        goto L_0x004771b1;
    }
L_0x004771a5:
    // 004771a5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004771aa  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004771ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004771ae  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004771b1:
    // 004771b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004771b2  683cfb4b00             -push 0x4bfb3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979516 /*0x4bfb3c*/;
    cpu.esp -= 4;
    // 004771b7  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004771b9  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004771be  e86d870100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004771c3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004771c6  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004771cb  e8f8990000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004771d0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004771d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004771d5  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004771db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004771dc  2eff15b4734b00         -call dword ptr cs:[0x4b73b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944820) /* 0x4b73b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004771e3  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004771e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004771e8  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004771ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004771ef  2eff15d8734b00         -call dword ptr cs:[0x4b73d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944856) /* 0x4b73d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004771f6  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004771fb  e8e0990000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477200  833d70a64c0000         +cmp dword ptr [0x4ca670], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477207  7406                   -je 0x47720f
    if (cpu.flags.zf)
    {
        goto L_0x0047720f;
    }
    // 00477209  ff1570a64c00           -call dword ptr [0x4ca670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047720f:
    // 0047720f  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00477213  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 00477219  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047721a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047721f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00477222  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477223  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477230  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477234  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477238  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0047723d  7505                   -jne 0x477244
    if (!cpu.flags.zf)
    {
        goto L_0x00477244;
    }
    // 0047723f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477241  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00477244:
    // 00477244  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477245  6830fb4b00             -push 0x4bfb30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979504 /*0x4bfb30*/;
    cpu.esp -= 4;
    // 0047724a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047724c  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477251  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477253  e8d8860100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477258  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047725b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0047725e  7405                   -je 0x477265
    if (cpu.flags.zf)
    {
        goto L_0x00477265;
    }
    // 00477260  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00477265:
    // 00477265  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00477268  7403                   -je 0x47726d
    if (cpu.flags.zf)
    {
        goto L_0x0047726d;
    }
    // 0047726a  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0047726d:
    // 0047726d  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00477270  7403                   -je 0x477275
    if (cpu.flags.zf)
    {
        goto L_0x00477275;
    }
    // 00477272  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00477275:
    // 00477275  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00477277  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477279  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047727c  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0047727f  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00477285  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047728b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047728d  e8f2ea0100             -call 0x495d84
    cpu.esp -= 4;
    sub_495d84(app, cpu);
    if (cpu.terminate) return;
    // 00477292  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477293  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477295  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4772a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772a0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004772a4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004772a8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004772ad  7505                   -jne 0x4772b4
    if (!cpu.flags.zf)
    {
        goto L_0x004772b4;
    }
    // 004772af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004772b1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004772b4:
    // 004772b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004772b5  6824fb4b00             -push 0x4bfb24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979492 /*0x4bfb24*/;
    cpu.esp -= 4;
    // 004772ba  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004772bc  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004772c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004772c3  e868860100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004772c8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004772cb  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004772ce  7405                   -je 0x4772d5
    if (cpu.flags.zf)
    {
        goto L_0x004772d5;
    }
    // 004772d0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004772d5:
    // 004772d5  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004772d8  7403                   -je 0x4772dd
    if (cpu.flags.zf)
    {
        goto L_0x004772dd;
    }
    // 004772da  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004772dd:
    // 004772dd  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004772e0  7403                   -je 0x4772e5
    if (cpu.flags.zf)
    {
        goto L_0x004772e5;
    }
    // 004772e2  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004772e5:
    // 004772e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004772e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004772e9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004772ec  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 004772ef  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004772f5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004772fa  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00477300  e87fea0100             -call 0x495d84
    cpu.esp -= 4;
    sub_495d84(app, cpu);
    if (cpu.terminate) return;
    // 00477305  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477306  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477308  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477310  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00477315  743a                   -je 0x477351
    if (cpu.flags.zf)
    {
        goto L_0x00477351;
    }
    // 00477317  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047731b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047731e  8b0d94a34c00           -mov ecx, dword ptr [0x4ca394]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022612) /* 0x4ca394 */);
    // 00477324  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00477327  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477329  740a                   -je 0x477335
    if (cpu.flags.zf)
    {
        goto L_0x00477335;
    }
    // 0047732b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047732d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 00477330  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00477335:
    // 00477335  6818fb4b00             -push 0x4bfb18
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979480 /*0x4bfb18*/;
    cpu.esp -= 4;
    // 0047733a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047733c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047733e  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477343  889070a74c00           -mov byte ptr [eax + 0x4ca770], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023600) /* 0x4ca770 */) = cpu.dl;
    // 00477349  e8e2850100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 0047734e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00477351:
    // 00477351  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477353  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477361  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477362  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477363  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477367  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 0047736c  0f84b1000000           -je 0x477423
    if (cpu.flags.zf)
    {
        goto L_0x00477423;
    }
    // 00477372  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00477374  8b0dd0d05100           -mov ecx, dword ptr [0x51d0d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5361872) /* 0x51d0d0 */);
    // 0047737a  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00477380  39ce                   +cmp esi, ecx
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
    // 00477382  7e02                   -jle 0x477386
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477386;
    }
    // 00477384  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00477386:
    // 00477386  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477388  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047738b  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047738e  8b1d94a34c00           -mov ebx, dword ptr [0x4ca394]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022612) /* 0x4ca394 */);
    // 00477394  a3dcd05100             -mov dword ptr [0x51d0dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5361884) /* 0x51d0dc */) = cpu.eax;
    // 00477399  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047739b  740e                   -je 0x4773ab
    if (cpu.flags.zf)
    {
        goto L_0x004773ab;
    }
    // 0047739d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047739f  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004773a1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004773a6  a3dcd05100             -mov dword ptr [0x51d0dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5361884) /* 0x51d0dc */) = cpu.eax;
L_0x004773ab:
    // 004773ab  a1dcd05100             -mov eax, dword ptr [0x51d0dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361884) /* 0x51d0dc */);
    // 004773b0  c68070a74c0001         -mov byte ptr [eax + 0x4ca770], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023600) /* 0x4ca770 */) = 1 /*0x1*/;
    // 004773b7  833d68a74c0000         +cmp dword ptr [0x4ca768], 0
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
    // 004773be  7424                   -je 0x4773e4
    if (cpu.flags.zf)
    {
        goto L_0x004773e4;
    }
    // 004773c0  3b0590a34c00           +cmp eax, dword ptr [0x4ca390]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022608) /* 0x4ca390 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004773c6  751c                   -jne 0x4773e4
    if (!cpu.flags.zf)
    {
        goto L_0x004773e4;
    }
    // 004773c8  803da8a74c0000         +cmp byte ptr [0x4ca7a8], 0
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
    // 004773cf  7413                   -je 0x4773e4
    if (cpu.flags.zf)
    {
        goto L_0x004773e4;
    }
    // 004773d1  68c4fa4b00             -push 0x4bfac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979396 /*0x4bfac4*/;
    cpu.esp -= 4;
    // 004773d6  2eff1550754b00         -call dword ptr cs:[0x4b7550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945232) /* 0x4b7550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004773dd  2eff1568744b00         -call dword ptr cs:[0x4b7468]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945000) /* 0x4b7468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004773e4:
    // 004773e4  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 004773e7  8b1dd8d05100           -mov ebx, dword ptr [0x51d0d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5361880) /* 0x51d0d8 */);
    // 004773ed  83e701                 -and edi, 1
    cpu.edi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004773f0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004773f2  743a                   -je 0x47742e
    if (cpu.flags.zf)
    {
        goto L_0x0047742e;
    }
    // 004773f4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004773f6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004773f8:
    // 004773f8  4e                     -dec esi
    (cpu.esi)--;
    // 004773f9  83feff                 +cmp esi, -1
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
    // 004773fc  7411                   -je 0x47740f
    if (cpu.flags.zf)
    {
        goto L_0x0047740f;
    }
    // 004773fe  8b15dcd05100           -mov edx, dword ptr [0x51d0dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361884) /* 0x51d0dc */);
    // 00477404  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00477406  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00477408  e883070000             -call 0x477b90
    cpu.esp -= 4;
    sub_477b90(app, cpu);
    if (cpu.terminate) return;
    // 0047740d  ebe9                   -jmp 0x4773f8
    goto L_0x004773f8;
L_0x0047740f:
    // 0047740f  68d4fa4b00             -push 0x4bfad4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979412 /*0x4bfad4*/;
    cpu.esp -= 4;
L_0x00477414:
    // 00477414  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477416  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 0047741b  e810850100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477420  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00477423:
    // 00477423  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477428  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477429  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047742a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047742b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047742e:
    // 0047742e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00477432  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477436  e8f5030000             -call 0x477830
    cpu.esp -= 4;
    sub_477830(app, cpu);
    if (cpu.terminate) return;
    // 0047743b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047743d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047743f  7417                   -je 0x477458
    if (cpu.flags.zf)
    {
        goto L_0x00477458;
    }
L_0x00477441:
    // 00477441  4e                     -dec esi
    (cpu.esi)--;
    // 00477442  83feff                 +cmp esi, -1
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
    // 00477445  742d                   -je 0x477474
    if (cpu.flags.zf)
    {
        goto L_0x00477474;
    }
    // 00477447  8b15dcd05100           -mov edx, dword ptr [0x51d0dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361884) /* 0x51d0dc */);
    // 0047744d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047744f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477451  e83a070000             -call 0x477b90
    cpu.esp -= 4;
    sub_477b90(app, cpu);
    if (cpu.terminate) return;
    // 00477456  ebe9                   -jmp 0x477441
    goto L_0x00477441;
L_0x00477458:
    // 00477458  6804fb4b00             -push 0x4bfb04
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979460 /*0x4bfb04*/;
    cpu.esp -= 4;
    // 0047745d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047745f  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477464  e8c7840100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477469  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047746c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047746e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047746f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477470  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477471  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00477474:
    // 00477474  68e8fa4b00             -push 0x4bfae8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979432 /*0x4bfae8*/;
    cpu.esp -= 4;
    // 00477479  eb99                   -jmp 0x477414
    goto L_0x00477414;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477480  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477481  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477482  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477486  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047748a  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047748f  744f                   -je 0x4774e0
    if (cpu.flags.zf)
    {
        goto L_0x004774e0;
    }
    // 00477491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477492  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477493  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00477495  8b1dd0d05100           -mov ebx, dword ptr [0x51d0d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5361872) /* 0x51d0d0 */);
    // 0047749b  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004774a1  39d9                   +cmp ecx, ebx
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
    // 004774a3  7f21                   -jg 0x4774c6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004774c6;
    }
L_0x004774a5:
    // 004774a5  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004774a7  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004774aa  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004774ad  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004774b0  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x004774b3:
    // 004774b3  49                     -dec ecx
    (cpu.ecx)--;
    // 004774b4  83f9ff                 +cmp ecx, -1
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
    // 004774b7  7411                   -je 0x4774ca
    if (cpu.flags.zf)
    {
        goto L_0x004774ca;
    }
    // 004774b9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004774bb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004774bd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004774bf  e8cc060000             -call 0x477b90
    cpu.esp -= 4;
    sub_477b90(app, cpu);
    if (cpu.terminate) return;
    // 004774c4  ebed                   -jmp 0x4774b3
    goto L_0x004774b3;
L_0x004774c6:
    // 004774c6  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004774c8  ebdb                   -jmp 0x4774a5
    goto L_0x004774a5;
L_0x004774ca:
    // 004774ca  68b8fa4b00             -push 0x4bfab8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979384 /*0x4bfab8*/;
    cpu.esp -= 4;
    // 004774cf  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004774d1  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004774d6  e855840100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004774db  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004774de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004774e0:
    // 004774e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004774e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774e7  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4774f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004774f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004774f1  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004774f4  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004774f8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004774fa  7509                   -jne 0x477505
    if (!cpu.flags.zf)
    {
        goto L_0x00477505;
    }
L_0x004774fc:
    // 004774fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004774fe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477501  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477502  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00477505:
    // 00477505  68a8fa4b00             -push 0x4bfaa8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979368 /*0x4bfaa8*/;
    cpu.esp -= 4;
    // 0047750a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047750c  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477511  e81a840100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477516  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 0047751c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047751f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00477521  75d9                   -jne 0x4774fc
    if (!cpu.flags.zf)
    {
        goto L_0x004774fc;
    }
    // 00477523  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00477525  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477526  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047752c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047752d  2eff15e4734b00         -call dword ptr cs:[0x4b73e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944868) /* 0x4b73e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477534  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00477536  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477537  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047753d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047753e  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477545  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00477548  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0047754e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477552  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00477558  833d70a64c0000         +cmp dword ptr [0x4ca670], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047755f  749b                   -je 0x4774fc
    if (cpu.flags.zf)
    {
        goto L_0x004774fc;
    }
    // 00477561  ff1570a64c00           -call dword ptr [0x4ca670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477567  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477569  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047756c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047756d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_477570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477570  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477574  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477578  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477579  687cfa4b00             -push 0x4bfa7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979324 /*0x4bfa7c*/;
    cpu.esp -= 4;
    // 0047757e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477580  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477585  e8a6830100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 0047758a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047758d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047758f  7409                   -je 0x47759a
    if (cpu.flags.zf)
    {
        goto L_0x0047759a;
    }
    // 00477591  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477598  750f                   -jne 0x4775a9
    if (!cpu.flags.zf)
    {
        goto L_0x004775a9;
    }
L_0x0047759a:
    // 0047759a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047759e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004775a0  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004775a6  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004775a9:
    // 004775a9  6890fa4b00             -push 0x4bfa90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979344 /*0x4bfa90*/;
    cpu.esp -= 4;
    // 004775ae  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004775b0  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004775b5  e876830100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004775ba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004775bd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004775bf  6870a34c00             -push 0x4ca370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022576 /*0x4ca370*/;
    cpu.esp -= 4;
    // 004775c4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004775c6  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004775c8  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004775cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004775d1  6874a34c00             -push 0x4ca374
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022580 /*0x4ca374*/;
    cpu.esp -= 4;
    // 004775d6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004775d8  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 004775da  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004775e1  833d70a34c0000         +cmp dword ptr [0x4ca370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022576) /* 0x4ca370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004775e8  740f                   -je 0x4775f9
    if (cpu.flags.zf)
    {
        goto L_0x004775f9;
    }
    // 004775ea  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004775ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004775ee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004775f0  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004775f2  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004775f9:
    // 004775f9  833d74a34c0000         +cmp dword ptr [0x4ca374], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022580) /* 0x4ca374 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477600  7498                   -je 0x47759a
    if (cpu.flags.zf)
    {
        goto L_0x0047759a;
    }
    // 00477602  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477604  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477606  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477608  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 0047760a  2eff1538744b00         -call dword ptr cs:[0x4b7438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944952) /* 0x4b7438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477611  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477615  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477617  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047761d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_477620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477620  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477624  3d60f00000             +cmp eax, 0xf060
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61536 /*0xf060*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477629  7424                   -je 0x47764f
    if (cpu.flags.zf)
    {
        goto L_0x0047764f;
    }
    // 0047762b  3d20f00000             +cmp eax, 0xf020
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61472 /*0xf020*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477630  741d                   -je 0x47764f
    if (cpu.flags.zf)
    {
        goto L_0x0047764f;
    }
    // 00477632  3d30f00000             +cmp eax, 0xf030
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61488 /*0xf030*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477637  7416                   -je 0x47764f
    if (cpu.flags.zf)
    {
        goto L_0x0047764f;
    }
    // 00477639  3d20f10000             +cmp eax, 0xf120
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61728 /*0xf120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047763e  740f                   -je 0x47764f
    if (cpu.flags.zf)
    {
        goto L_0x0047764f;
    }
    // 00477640  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477644  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477646  8a825d040000           -mov al, byte ptr [edx + 0x45d]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
    // 0047764c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047764f:
    // 0047764f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477651  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477660  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477664  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477666  7505                   -jne 0x47766d
    if (!cpu.flags.zf)
    {
        goto L_0x0047766d;
    }
    // 00477668  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047766a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047766d:
    // 0047766d  6868fa4b00             -push 0x4bfa68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979304 /*0x4bfa68*/;
    cpu.esp -= 4;
    // 00477672  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477674  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477679  c7805404000000000000   -mov dword ptr [eax + 0x454], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */) = 0 /*0x0*/;
    // 00477683  e8a8820100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477688  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047768b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047768d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_477690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477690  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00477695  7508                   -jne 0x47769f
    if (!cpu.flags.zf)
    {
        goto L_0x0047769f;
    }
    // 00477697  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047769c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047769f:
    // 0047769f  6858fa4b00             -push 0x4bfa58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979288 /*0x4bfa58*/;
    cpu.esp -= 4;
    // 004776a4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004776a6  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004776ab  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004776b0  e87b820100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004776b5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004776b8  890d6ca34c00           -mov dword ptr [0x4ca36c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022572) /* 0x4ca36c */) = cpu.ecx;
    // 004776be  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004776c3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4776d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004776d0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004776d5  7508                   -jne 0x4776df
    if (!cpu.flags.zf)
    {
        goto L_0x004776df;
    }
    // 004776d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004776dc  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004776df:
    // 004776df  684cfa4b00             -push 0x4bfa4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979276 /*0x4bfa4c*/;
    cpu.esp -= 4;
    // 004776e4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004776e6  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004776eb  e840820100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004776f0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004776f3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004776f5  2eff1508744b00         -call dword ptr cs:[0x4b7408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944904) /* 0x4b7408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004776fc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477701  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477710  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477714  3b15c4d75100           +cmp edx, dword ptr [0x51d7c4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047771a  7405                   -je 0x477721
    if (cpu.flags.zf)
    {
        goto L_0x00477721;
    }
    // 0047771c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047771e  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00477721:
    // 00477721  683cfa4b00             -push 0x4bfa3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979260 /*0x4bfa3c*/;
    cpu.esp -= 4;
    // 00477726  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00477728  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 0047772d  e8fe810100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477732  8b0dd4d05100           -mov ecx, dword ptr [0x51d0d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5361876) /* 0x51d0d4 */);
    // 00477738  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047773b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047773d  7408                   -je 0x477747
    if (cpu.flags.zf)
    {
        goto L_0x00477747;
    }
    // 0047773f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477741  ff15d4d05100           -call dword ptr [0x51d0d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5361876) /* 0x51d0d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00477747:
    // 00477747  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477749  2eff1530744b00         -call dword ptr cs:[0x4b7430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944944) /* 0x4b7430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477750  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 00477755  b870a74c00             -mov eax, 0x4ca770
    cpu.eax = 5023600 /*0x4ca770*/;
    // 0047775a  e83d950000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0047775f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477761  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477770  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477774  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477776  7465                   -je 0x4777dd
    if (cpu.flags.zf)
    {
        goto L_0x004777dd;
    }
    // 00477778  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047777c  3b0dc4d75100           +cmp ecx, dword ptr [0x51d7c4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477782  7559                   -jne 0x4777dd
    if (!cpu.flags.zf)
    {
        goto L_0x004777dd;
    }
    // 00477784  833dd4d0510000         +cmp dword ptr [0x51d0d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5361876) /* 0x51d0d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047778b  7555                   -jne 0x4777e2
    if (!cpu.flags.zf)
    {
        goto L_0x004777e2;
    }
L_0x0047778d:
    // 0047778d  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477794  7409                   -je 0x47779f
    if (cpu.flags.zf)
    {
        goto L_0x0047779f;
    }
    // 00477796  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477798  2eff1530744b00         -call dword ptr cs:[0x4b7430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944944) /* 0x4b7430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047779f:
    // 0047779f  833de4d7510000         +cmp dword ptr [0x51d7e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363684) /* 0x51d7e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004777a6  7521                   -jne 0x4777c9
    if (!cpu.flags.zf)
    {
        goto L_0x004777c9;
    }
    // 004777a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004777a9  681cfa4b00             -push 0x4bfa1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979228 /*0x4bfa1c*/;
    cpu.esp -= 4;
    // 004777ae  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004777b0  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004777b5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004777ba  e871810100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004777bf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004777c2  893de4d75100           -mov dword ptr [0x51d7e4], edi
    app->getMemory<x86::reg32>(x86::reg32(5363684) /* 0x51d7e4 */) = cpu.edi;
    // 004777c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004777c9:
    // 004777c9  682cfa4b00             -push 0x4bfa2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979244 /*0x4bfa2c*/;
    cpu.esp -= 4;
    // 004777ce  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004777d0  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 004777d5  e856810100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 004777da  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004777dd:
    // 004777dd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004777df  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004777e2:
    // 004777e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004777e7  ff15d4d05100           -call dword ptr [0x51d0d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5361876) /* 0x51d0d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004777ed  eb9e                   -jmp 0x47778d
    goto L_0x0047778d;
}

/* align: skip 0x00 */
void Application::sub_4777f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004777f0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004777f4  a3e4d75100             -mov dword ptr [0x51d7e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5363684) /* 0x51d7e4 */) = cpu.eax;
    // 004777f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004777fb  741f                   -je 0x47781c
    if (cpu.flags.zf)
    {
        goto L_0x0047781c;
    }
    // 004777fd  b8f4f94b00             -mov eax, 0x4bf9f4
    cpu.eax = 4979188 /*0x4bf9f4*/;
L_0x00477802:
    // 00477802  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477803  6808fa4b00             -push 0x4bfa08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979208 /*0x4bfa08*/;
    cpu.esp -= 4;
    // 00477808  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047780a  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 0047780f  e81c810100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477814  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477817  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00477819  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047781c:
    // 0047781c  b8fcf94b00             -mov eax, 0x4bf9fc
    cpu.eax = 4979196 /*0x4bf9fc*/;
    // 00477821  ebdf                   -jmp 0x477802
    goto L_0x00477802;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477830  3d04010000             +cmp eax, 0x104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477835  752d                   -jne 0x477864
    if (!cpu.flags.zf)
    {
        goto L_0x00477864;
    }
L_0x00477837:
    // 00477837  83fa65                 +cmp edx, 0x65
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047783a  7334                   -jae 0x477870
    if (!cpu.flags.cf)
    {
        goto L_0x00477870;
    }
    // 0047783c  83fa28                 +cmp edx, 0x28
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
    // 0047783f  0f83c9000000           -jae 0x47790e
    if (!cpu.flags.cf)
    {
        goto L_0x0047790e;
    }
    // 00477845  83fa24                 +cmp edx, 0x24
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
    // 00477848  0f8311010000           -jae 0x47795f
    if (!cpu.flags.cf)
    {
        goto L_0x0047795f;
    }
    // 0047784e  83fa22                 +cmp edx, 0x22
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
    // 00477851  0f8319010000           -jae 0x477970
    if (!cpu.flags.cf)
    {
        goto L_0x00477970;
    }
    // 00477857  83fa21                 +cmp edx, 0x21
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047785a  750f                   -jne 0x47786b
    if (!cpu.flags.zf)
    {
        goto L_0x0047786b;
    }
    // 0047785c  ba00490000             -mov edx, 0x4900
    cpu.edx = 18688 /*0x4900*/;
    // 00477861  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477864:
    // 00477864  3d00010000             +cmp eax, 0x100
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
    // 00477869  74cc                   -je 0x477837
    if (cpu.flags.zf)
    {
        goto L_0x00477837;
    }
L_0x0047786b:
    // 0047786b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047786d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047786f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477870:
    // 00477870  0f864c010000           -jbe 0x4779c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004779c2;
    }
    // 00477876  83fa73                 +cmp edx, 0x73
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477879  731c                   -jae 0x477897
    if (!cpu.flags.cf)
    {
        goto L_0x00477897;
    }
    // 0047787b  83fa69                 +cmp edx, 0x69
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047787e  7364                   -jae 0x4778e4
    if (!cpu.flags.cf)
    {
        goto L_0x004778e4;
    }
    // 00477880  83fa67                 +cmp edx, 0x67
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477883  0f8241010000           -jb 0x4779ca
    if (cpu.flags.cf)
    {
        goto L_0x004779ca;
    }
    // 00477889  0f8743010000           -ja 0x4779d2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004779d2;
    }
    // 0047788f  ba51000000             -mov edx, 0x51
    cpu.edx = 81 /*0x51*/;
    // 00477894  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477896  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477897:
    // 00477897  0f864d010000           -jbe 0x4779ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004779ea;
    }
    // 0047789d  83fa77                 +cmp edx, 0x77
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778a0  7317                   -jae 0x4778b9
    if (!cpu.flags.cf)
    {
        goto L_0x004778b9;
    }
    // 004778a2  83fa75                 +cmp edx, 0x75
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778a5  0f8247010000           -jb 0x4779f2
    if (cpu.flags.cf)
    {
        goto L_0x004779f2;
    }
    // 004778ab  0f8749010000           -ja 0x4779fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004779fa;
    }
    // 004778b1  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 004778b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004778b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004778b9:
    // 004778b9  0f8643010000           -jbe 0x477a02
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00477a02;
    }
    // 004778bf  83fa79                 +cmp edx, 0x79
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778c2  0f8242010000           -jb 0x477a0a
    if (cpu.flags.cf)
    {
        goto L_0x00477a0a;
    }
    // 004778c8  0f8644010000           -jbe 0x477a12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00477a12;
    }
    // 004778ce  83fa7a                 +cmp edx, 0x7a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778d1  0f8643010000           -jbe 0x477a1a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00477a1a;
    }
    // 004778d7  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778da  758f                   -jne 0x47786b
    if (!cpu.flags.zf)
    {
        goto L_0x0047786b;
    }
    // 004778dc  ba00880000             -mov edx, 0x8800
    cpu.edx = 34816 /*0x8800*/;
    // 004778e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004778e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004778e4:
    // 004778e4  0f86f0000000           -jbe 0x4779da
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004779da;
    }
    // 004778ea  83fa71                 +cmp edx, 0x71
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(113 /*0x71*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778ed  7311                   -jae 0x477900
    if (!cpu.flags.cf)
    {
        goto L_0x00477900;
    }
    // 004778ef  83fa70                 +cmp edx, 0x70
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004778f2  0f8573ffffff           -jne 0x47786b
    if (!cpu.flags.zf)
    {
        goto L_0x0047786b;
    }
    // 004778f8  ba003b0000             -mov edx, 0x3b00
    cpu.edx = 15104 /*0x3b00*/;
    // 004778fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004778ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477900:
    // 00477900  0f87dc000000           -ja 0x4779e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004779e2;
    }
    // 00477906  ba003c0000             -mov edx, 0x3c00
    cpu.edx = 15360 /*0x3c00*/;
    // 0047790b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047790d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047790e:
    // 0047790e  0f8686000000           -jbe 0x47799a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047799a;
    }
    // 00477914  83fa61                 +cmp edx, 0x61
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477917  7316                   -jae 0x47792f
    if (!cpu.flags.cf)
    {
        goto L_0x0047792f;
    }
    // 00477919  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047791c  732e                   -jae 0x47794c
    if (!cpu.flags.cf)
    {
        goto L_0x0047794c;
    }
    // 0047791e  83fa2d                 +cmp edx, 0x2d
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
    // 00477921  0f8544ffffff           -jne 0x47786b
    if (!cpu.flags.zf)
    {
        goto L_0x0047786b;
    }
    // 00477927  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 0047792c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047792e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047792f:
    // 0047792f  0f8675000000           -jbe 0x4779aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004779aa;
    }
    // 00477935  83fa63                 +cmp edx, 0x63
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477938  0f8274000000           -jb 0x4779b2
    if (cpu.flags.cf)
    {
        goto L_0x004779b2;
    }
    // 0047793e  0f8776000000           -ja 0x4779ba
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004779ba;
    }
    // 00477944  ba47000000             -mov edx, 0x47
    cpu.edx = 71 /*0x47*/;
    // 00477949  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047794b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047794c:
    // 0047794c  7654                   -jbe 0x4779a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004779a2;
    }
    // 0047794e  83fa60                 +cmp edx, 0x60
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477951  0f8514ffffff           -jne 0x47786b
    if (!cpu.flags.zf)
    {
        goto L_0x0047786b;
    }
    // 00477957  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 0047795c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047795e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047795f:
    // 0047795f  7621                   -jbe 0x477982
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00477982;
    }
    // 00477961  83fa26                 +cmp edx, 0x26
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477964  7224                   -jb 0x47798a
    if (cpu.flags.cf)
    {
        goto L_0x0047798a;
    }
    // 00477966  772a                   -ja 0x477992
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00477992;
    }
    // 00477968  ba00480000             -mov edx, 0x4800
    cpu.edx = 18432 /*0x4800*/;
    // 0047796d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047796f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477970:
    // 00477970  7708                   -ja 0x47797a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047797a;
    }
    // 00477972  ba00510000             -mov edx, 0x5100
    cpu.edx = 20736 /*0x5100*/;
    // 00477977  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477979  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047797a:
    // 0047797a  ba004f0000             -mov edx, 0x4f00
    cpu.edx = 20224 /*0x4f00*/;
    // 0047797f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477981  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477982:
    // 00477982  ba00470000             -mov edx, 0x4700
    cpu.edx = 18176 /*0x4700*/;
    // 00477987  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477989  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047798a:
    // 0047798a  ba004b0000             -mov edx, 0x4b00
    cpu.edx = 19200 /*0x4b00*/;
    // 0047798f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477991  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477992:
    // 00477992  ba004d0000             -mov edx, 0x4d00
    cpu.edx = 19712 /*0x4d00*/;
    // 00477997  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477999  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047799a:
    // 0047799a  ba00500000             -mov edx, 0x5000
    cpu.edx = 20480 /*0x5000*/;
    // 0047799f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779a2:
    // 004779a2  ba00530000             -mov edx, 0x5300
    cpu.edx = 21248 /*0x5300*/;
    // 004779a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779aa:
    // 004779aa  ba5a000000             -mov edx, 0x5a
    cpu.edx = 90 /*0x5a*/;
    // 004779af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779b2:
    // 004779b2  ba58000000             -mov edx, 0x58
    cpu.edx = 88 /*0x58*/;
    // 004779b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779ba:
    // 004779ba  ba41000000             -mov edx, 0x41
    cpu.edx = 65 /*0x41*/;
    // 004779bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779c2:
    // 004779c2  ba004c0000             -mov edx, 0x4c00
    cpu.edx = 19456 /*0x4c00*/;
    // 004779c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779ca:
    // 004779ca  ba44000000             -mov edx, 0x44
    cpu.edx = 68 /*0x44*/;
    // 004779cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779d2:
    // 004779d2  ba57000000             -mov edx, 0x57
    cpu.edx = 87 /*0x57*/;
    // 004779d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779da:
    // 004779da  ba45000000             -mov edx, 0x45
    cpu.edx = 69 /*0x45*/;
    // 004779df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779e2:
    // 004779e2  ba003d0000             -mov edx, 0x3d00
    cpu.edx = 15616 /*0x3d00*/;
    // 004779e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779ea:
    // 004779ea  ba003e0000             -mov edx, 0x3e00
    cpu.edx = 15872 /*0x3e00*/;
    // 004779ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779f2:
    // 004779f2  ba003f0000             -mov edx, 0x3f00
    cpu.edx = 16128 /*0x3f00*/;
    // 004779f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004779f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779fa:
    // 004779fa  ba00410000             -mov edx, 0x4100
    cpu.edx = 16640 /*0x4100*/;
    // 004779ff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477a01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477a02:
    // 00477a02  ba00420000             -mov edx, 0x4200
    cpu.edx = 16896 /*0x4200*/;
    // 00477a07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477a09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477a0a:
    // 00477a0a  ba00430000             -mov edx, 0x4300
    cpu.edx = 17152 /*0x4300*/;
    // 00477a0f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477a11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477a12:
    // 00477a12  ba00440000             -mov edx, 0x4400
    cpu.edx = 17408 /*0x4400*/;
    // 00477a17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477a19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477a1a:
    // 00477a1a  ba00870000             -mov edx, 0x8700
    cpu.edx = 34560 /*0x8700*/;
    // 00477a1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477a21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477a30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477a32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477a33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477a34  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477a37  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477a3d  a1c8d05100             -mov eax, dword ptr [0x51d0c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */);
    // 00477a42  e881910000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00477a47  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477a49  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477a4f  8b15ccd05100           -mov edx, dword ptr [0x51d0cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */);
    // 00477a55  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477a57  39d6                   +cmp esi, edx
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
    // 00477a59  7455                   -je 0x477ab0
    if (cpu.flags.zf)
    {
        goto L_0x00477ab0;
    }
L_0x00477a5b:
    // 00477a5b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477a5d  7551                   -jne 0x477ab0
    if (!cpu.flags.zf)
    {
        goto L_0x00477ab0;
    }
    // 00477a5f  8935c4d05100           -mov dword ptr [0x51d0c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */) = cpu.esi;
    // 00477a65  8b04b530cc5100         -mov eax, dword ptr [esi*4 + 0x51cc30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360688) /* 0x51cc30 */ + cpu.esi * 4);
    // 00477a6c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477a6e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477a70  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00477a73  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00477a76  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00477a7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477a7c  750e                   -jne 0x477a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00477a8c;
    }
    // 00477a7e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477a80  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477a82  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00477a85  e8165f0000             -call 0x47d9a0
    cpu.esp -= 4;
    sub_47d9a0(app, cpu);
    if (cpu.terminate) return;
    // 00477a8a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00477a8c:
    // 00477a8c  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477a92  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477a94  7512                   -jne 0x477aa8
    if (!cpu.flags.zf)
    {
        goto L_0x00477aa8;
    }
    // 00477a96  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00477a99  8b35d0d05100           -mov esi, dword ptr [0x51d0d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361872) /* 0x51d0d0 */);
    // 00477a9f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477aa1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477aa4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00477aa6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00477aa8:
    // 00477aa8  3b35ccd05100           +cmp esi, dword ptr [0x51d0cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477aae  75ab                   -jne 0x477a5b
    if (!cpu.flags.zf)
    {
        goto L_0x00477a5b;
    }
L_0x00477ab0:
    // 00477ab0  a1c8d05100             -mov eax, dword ptr [0x51d0c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */);
    // 00477ab5  8935c4d05100           -mov dword ptr [0x51d0c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */) = cpu.esi;
    // 00477abb  e820910000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477ac0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477ac2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00477ac5  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477acb  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477acd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477ad0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ad1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ad2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ad3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ad4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477ae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477ae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477ae2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477ae3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477ae4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477ae5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477ae8  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477aee  a1c8d05100             -mov eax, dword ptr [0x51d0c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */);
    // 00477af3  e8d0900000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00477af8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477afa  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477b00  8b15ccd05100           -mov edx, dword ptr [0x51d0cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */);
    // 00477b06  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477b08  39d6                   +cmp esi, edx
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
    // 00477b0a  7453                   -je 0x477b5f
    if (cpu.flags.zf)
    {
        goto L_0x00477b5f;
    }
L_0x00477b0c:
    // 00477b0c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477b0e  754f                   -jne 0x477b5f
    if (!cpu.flags.zf)
    {
        goto L_0x00477b5f;
    }
    // 00477b10  8935c4d05100           -mov dword ptr [0x51d0c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */) = cpu.esi;
    // 00477b16  8b04b530cc5100         -mov eax, dword ptr [esi*4 + 0x51cc30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5360688) /* 0x51cc30 */ + cpu.esi * 4);
    // 00477b1d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477b1f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477b21  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00477b24  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00477b27  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00477b2b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477b2d  750e                   -jne 0x477b3d
    if (!cpu.flags.zf)
    {
        goto L_0x00477b3d;
    }
    // 00477b2f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477b31  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477b33  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00477b36  e8655e0000             -call 0x47d9a0
    cpu.esp -= 4;
    sub_47d9a0(app, cpu);
    if (cpu.terminate) return;
    // 00477b3b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00477b3d:
    // 00477b3d  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477b43  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00477b46  8b35d0d05100           -mov esi, dword ptr [0x51d0d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361872) /* 0x51d0d0 */);
    // 00477b4c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477b4e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477b51  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00477b53  8b3dccd05100           -mov edi, dword ptr [0x51d0cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */);
    // 00477b59  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00477b5b  39fa                   +cmp edx, edi
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
    // 00477b5d  75ad                   -jne 0x477b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00477b0c;
    }
L_0x00477b5f:
    // 00477b5f  a1c8d05100             -mov eax, dword ptr [0x51d0c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */);
    // 00477b64  8935c4d05100           -mov dword ptr [0x51d0c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */) = cpu.esi;
    // 00477b6a  e871900000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477b6f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477b71  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00477b74  8b35c4d05100           -mov esi, dword ptr [0x51d0c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477b7a  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477b7c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477b91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477b92  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477b94  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00477b96  a1c8d05100             -mov eax, dword ptr [0x51d0c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */);
    // 00477b9b  8b15ccd05100           -mov edx, dword ptr [0x51d0cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */);
    // 00477ba1  e822900000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00477ba6  6689349532cc5100       -mov word ptr [edx*4 + 0x51cc32], si
    app->getMemory<x86::reg16>(x86::reg32(5360690) /* 0x51cc32 */ + cpu.edx * 4) = cpu.si;
    // 00477bae  880c9531cc5100         -mov byte ptr [edx*4 + 0x51cc31], cl
    app->getMemory<x86::reg8>(x86::reg32(5360689) /* 0x51cc31 */ + cpu.edx * 4) = cpu.cl;
    // 00477bb5  881c9530cc5100         -mov byte ptr [edx*4 + 0x51cc30], bl
    app->getMemory<x86::reg8>(x86::reg32(5360688) /* 0x51cc30 */ + cpu.edx * 4) = cpu.bl;
    // 00477bbc  8b15ccd05100           -mov edx, dword ptr [0x51d0cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */);
    // 00477bc2  42                     -inc edx
    (cpu.edx)++;
    // 00477bc3  8b0dd0d05100           -mov ecx, dword ptr [0x51d0d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5361872) /* 0x51d0d0 */);
    // 00477bc9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477bcb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477bce  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00477bd0  a1c4d05100             -mov eax, dword ptr [0x51d0c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477bd5  8915ccd05100           -mov dword ptr [0x51d0cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5361868) /* 0x51d0cc */) = cpu.edx;
    // 00477bdb  39d0                   +cmp eax, edx
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
    // 00477bdd  7514                   -jne 0x477bf3
    if (!cpu.flags.zf)
    {
        goto L_0x00477bf3;
    }
    // 00477bdf  8b15c4d05100           -mov edx, dword ptr [0x51d0c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */);
    // 00477be5  42                     -inc edx
    (cpu.edx)++;
    // 00477be6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477be8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477beb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00477bed  8915c4d05100           -mov dword ptr [0x51d0c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5361860) /* 0x51d0c4 */) = cpu.edx;
L_0x00477bf3:
    // 00477bf3  a1c8d05100             -mov eax, dword ptr [0x51d0c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5361864) /* 0x51d0c8 */);
    // 00477bf8  e8e38f0000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00477bfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bfe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477c01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c02  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477c05  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00477c07  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00477c0a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00477c0c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00477c10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c11  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 00477c17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c18  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477c1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477c21  7420                   -je 0x477c43
    if (cpu.flags.zf)
    {
        goto L_0x00477c43;
    }
    // 00477c23  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477c27  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477c28  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477c2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00477c2d:
    // 00477c2d  2eff1520744b00         -call dword ptr cs:[0x4b7420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944928) /* 0x4b7420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477c34  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477c36  2eff151c744b00         -call dword ptr cs:[0x4b741c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944924) /* 0x4b741c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477c3d  83c408                 +add esp, 8
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
    // 00477c40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477c43:
    // 00477c43  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477c44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c45  ebe6                   -jmp 0x477c2d
    goto L_0x00477c2d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c50  68d8f94b00             -push 0x4bf9d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979160 /*0x4bf9d8*/;
    cpu.esp -= 4;
    // 00477c55  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00477c57  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477c5c  e8cf7c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477c61  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00477c64  e8b3020000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00477c69  b8507c4700             -mov eax, 0x477c50
    cpu.eax = 4684880 /*0x477c50*/;
    // 00477c6e  e8811f0000             -call 0x479bf4
    cpu.esp -= 4;
    sub_479bf4(app, cpu);
    if (cpu.terminate) return;
    // 00477c73  e8698a0100             -call 0x4906e1
    cpu.esp -= 4;
    sub_4906e1(app, cpu);
    if (cpu.terminate) return;
    // 00477c78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477c7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c80  a3d4d05100             -mov dword ptr [0x51d0d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5361876) /* 0x51d0d4 */) = cpu.eax;
    // 00477c85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477c93  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477c95  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00477c97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477c98  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477c9b  6898f94b00             -push 0x4bf998
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979096 /*0x4bf998*/;
    cpu.esp -= 4;
    // 00477ca0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00477ca2  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477ca7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477ca9  e8827c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477cae  8b2dc4d75100           -mov ebp, dword ptr [0x51d7c4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00477cb4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477cb7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00477cb9  7456                   -je 0x477d11
    if (cpu.flags.zf)
    {
        goto L_0x00477d11;
    }
    // 00477cbb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477cbd  7545                   -jne 0x477d04
    if (!cpu.flags.zf)
    {
        goto L_0x00477d04;
    }
    // 00477cbf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477cc0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477cc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477cc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477cc3  2eff1504744b00         -call dword ptr cs:[0x4b7404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944900) /* 0x4b7404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477cca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477ccc  7509                   -jne 0x477cd7
    if (!cpu.flags.zf)
    {
        goto L_0x00477cd7;
    }
    // 00477cce  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00477cd5:
    // 00477cd5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00477cd7:
    // 00477cd7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477cd9  741c                   -je 0x477cf7
    if (cpu.flags.zf)
    {
        goto L_0x00477cf7;
    }
    // 00477cdb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477cdd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00477ce2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477ce3  68c0f94b00             -push 0x4bf9c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979136 /*0x4bf9c0*/;
    cpu.esp -= 4;
    // 00477ce8  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00477cea  6860a34c00             -push 0x4ca360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5022560 /*0x4ca360*/;
    cpu.esp -= 4;
    // 00477cef  e83c7c0100             -call 0x48f930
    cpu.esp -= 4;
    sub_48f930(app, cpu);
    if (cpu.terminate) return;
    // 00477cf4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00477cf7:
    // 00477cf7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477cf9  7516                   -jne 0x477d11
    if (!cpu.flags.zf)
    {
        goto L_0x00477d11;
    }
    // 00477cfb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477d00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477d04:
    // 00477d04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477d05  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477d06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477d07  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477d08  2eff1514744b00         -call dword ptr cs:[0x4b7414]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944916) /* 0x4b7414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477d0f  ebc4                   -jmp 0x477cd5
    goto L_0x00477cd5;
L_0x00477d11:
    // 00477d11  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477d13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d16  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
