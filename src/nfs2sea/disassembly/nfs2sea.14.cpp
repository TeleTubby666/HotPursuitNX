#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475b40);
    // 00475b40  e90b000000             -jmp 0x475b50
    return sub_475b50(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475b50);
    // 00475b50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475b51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475b52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475b53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475b54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475b55  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00475b5a  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475b60  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475b62  89152c595400           -mov dword ptr [0x54592c], edx
    app->getMemory<x86::reg32>(x86::reg32(5527852) /* 0x54592c */) = cpu.edx;
    // 00475b68  891530595400           -mov dword ptr [0x545930], edx
    app->getMemory<x86::reg32>(x86::reg32(5527856) /* 0x545930 */) = cpu.edx;
    // 00475b6e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00475b70:
    // 00475b70  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475b72  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475b74  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
L_0x00475b77:
    // 00475b77  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475b7a  899028565400           -mov dword ptr [eax + 0x545628], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5527080) /* 0x545628 */) = cpu.edx;
    // 00475b80  89b828585400           -mov dword ptr [eax + 0x545828], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5527592) /* 0x545828 */) = cpu.edi;
    // 00475b86  899028575400           -mov dword ptr [eax + 0x545728], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5527336) /* 0x545728 */) = cpu.edx;
    // 00475b8c  39c8                   +cmp eax, ecx
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
    // 00475b8e  75e7                   -jne 0x475b77
    if (!cpu.flags.zf)
    {
        goto L_0x00475b77;
    }
    // 00475b90  43                     -inc ebx
    (cpu.ebx)++;
    // 00475b91  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475b94  83fb10                 +cmp ebx, 0x10
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475b97  7cd7                   -jl 0x475b70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475b70;
    }
    // 00475b99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_475ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475ba0);
    // 00475ba0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475ba1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475ba2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475ba3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475ba6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00475ba8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00475baa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00475bac  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00475bae  83e70f                 -and edi, 0xf
    cpu.edi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00475bb1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475bb3  751d                   -jne 0x475bd2
    if (!cpu.flags.zf)
    {
        goto L_0x00475bd2;
    }
    // 00475bb5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475bb7  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 00475bbe  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00475bc1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475bc3  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475bc8  2b812c565400           -sub eax, dword ptr [ecx + 0x54562c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5527084) /* 0x54562c */)));
    // 00475bce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475bd0  7e50                   -jle 0x475c22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475c22;
    }
L_0x00475bd2:
    // 00475bd2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00475bd4  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00475bdb  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00475bde  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475be0  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475be5  89812c565400           -mov dword ptr [ecx + 0x54562c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5527084) /* 0x54562c */) = cpu.eax;
    // 00475beb  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00475bf2  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00475bf4  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00475bf8  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00475bff  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00475c06  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00475c08  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00475c0b  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00475c0e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00475c11  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475c15  83bb2c58540000         +cmp dword ptr [ebx + 0x54582c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5527596) /* 0x54582c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c1c  7524                   -jne 0x475c42
    if (!cpu.flags.zf)
    {
        goto L_0x00475c42;
    }
    // 00475c1e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475c20  7407                   -je 0x475c29
    if (cpu.flags.zf)
    {
        goto L_0x00475c29;
    }
L_0x00475c22:
    // 00475c22  83c40c                 +add esp, 0xc
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
    // 00475c25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475c29:
    // 00475c29  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00475c2c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00475c31  8dbf2c535400           -lea edi, [edi + 0x54532c]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5526316) /* 0x54532c */);
    // 00475c37  89932c585400           -mov dword ptr [ebx + 0x54582c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5527596) /* 0x54582c */) = cpu.edx;
    // 00475c3d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c3e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c3f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00475c40  ebe0                   -jmp 0x475c22
    goto L_0x00475c22;
L_0x00475c42:
    // 00475c42  052c535400             -add eax, 0x54532c
    (cpu.eax) += x86::reg32(x86::sreg32(5526316 /*0x54532c*/));
    // 00475c47  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475c49  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00475c4d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475c4f  7435                   -je 0x475c86
    if (cpu.flags.zf)
    {
        goto L_0x00475c86;
    }
    // 00475c51  bb33330000             -mov ebx, 0x3333
    cpu.ebx = 13107 /*0x3333*/;
    // 00475c56  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475c58  e813b2ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00475c5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475c5f  7512                   -jne 0x475c73
    if (!cpu.flags.zf)
    {
        goto L_0x00475c73;
    }
    // 00475c61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475c62  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475c66  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475c68  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475c6a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00475c6c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475c6e  e85d000000             -call 0x475cd0
    cpu.esp -= 4;
    sub_475cd0(app, cpu);
    if (cpu.terminate) return;
L_0x00475c73:
    // 00475c73  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00475c76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475c78  8984af2c585400         -mov dword ptr [edi + ebp*4 + 0x54582c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5527596) /* 0x54582c */ + cpu.ebp * 4) = cpu.eax;
    // 00475c7f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475c82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475c86:
    // 00475c86  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 00475c8b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475c8d  e8deb1ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00475c92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475c94  758c                   -jne 0x475c22
    if (!cpu.flags.zf)
    {
        goto L_0x00475c22;
    }
    // 00475c96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475c97  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475c9b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475c9d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00475c9f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00475ca1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475ca3  e828000000             -call 0x475cd0
    cpu.esp -= 4;
    sub_475cd0(app, cpu);
    if (cpu.terminate) return;
    // 00475ca8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475cac  c7802c58540001000000   -mov dword ptr [eax + 0x54582c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5527596) /* 0x54582c */) = 1 /*0x1*/;
    // 00475cb6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00475cb9  8dbf2c535400           -lea edi, [edi + 0x54532c]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5526316) /* 0x54532c */);
    // 00475cbf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
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
    // 00475cc2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475cc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475cd0);
    // 00475cd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475cd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475cd3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00475cd6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00475cd8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00475cdc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00475cde  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00475ce0  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00475ce4  bb00000e00             -mov ebx, 0xe0000
    cpu.ebx = 917504 /*0xe0000*/;
    // 00475ce9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475ceb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00475ced  e87eb1ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00475cf2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475cf4  0f857e000000           -jne 0x475d78
    if (!cpu.flags.zf)
    {
        goto L_0x00475d78;
    }
    // 00475cfa  83f903                 +cmp ecx, 3
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
    // 00475cfd  7d5c                   -jge 0x475d5b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475d5b;
    }
    // 00475cff  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00475d01  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475d03  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475d05  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00475d08  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00475d0b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475d0f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475d11  41                     -inc ecx
    (cpu.ecx)++;
    // 00475d12  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475d14  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00475d16  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00475d1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475d1b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00475d1e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00475d22  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00475d24  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00475d26  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00475d28  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475d2c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00475d30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475d32  e899ffffff             -call 0x475cd0
    cpu.esp -= 4;
    sub_475cd0(app, cpu);
    if (cpu.terminate) return;
    // 00475d37  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475d3b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00475d3f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475d40  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475d44  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475d46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475d47  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475d4b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475d4d  e87effffff             -call 0x475cd0
    cpu.esp -= 4;
    sub_475cd0(app, cpu);
    if (cpu.terminate) return;
    // 00475d52  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00475d55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d58  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00475d5b:
    // 00475d5b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00475d5f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475d63  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00475d65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475d66  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475d68  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475d6a  e8d1990000             -call 0x47f740
    cpu.esp -= 4;
    sub_47f740(app, cpu);
    if (cpu.terminate) return;
    // 00475d6f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00475d72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d75  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00475d78:
    // 00475d78  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00475d7c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00475d7e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00475d80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475d81  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475d83  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00475d87  e8b4990000             -call 0x47f740
    cpu.esp -= 4;
    sub_47f740(app, cpu);
    if (cpu.terminate) return;
    // 00475d8c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00475d8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475d92  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475da0);
    // 00475da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475da1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475da2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475da4  8b152c595400           -mov edx, dword ptr [0x54592c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5527852) /* 0x54592c */);
    // 00475daa  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475daf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475db1  83f804                 +cmp eax, 4
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
    // 00475db4  7f03                   -jg 0x475db9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00475db9;
    }
    // 00475db6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475db7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475db8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475db9:
    // 00475db9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475dba  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475dbf  a32c595400             -mov dword ptr [0x54592c], eax
    app->getMemory<x86::reg32>(x86::reg32(5527852) /* 0x54592c */) = cpu.eax;
    // 00475dc4  e8ab220100             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 00475dc9  a807                   +test al, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 7 /*0x7*/));
    // 00475dcb  7415                   -je 0x475de2
    if (cpu.flags.zf)
    {
        goto L_0x00475de2;
    }
    // 00475dcd  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00475dd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475dd4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475dd6  e899e8ffff             -call 0x474674
    cpu.esp -= 4;
    sub_474674(app, cpu);
    if (cpu.terminate) return;
    // 00475ddb  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
L_0x00475de2:
    // 00475de2  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00475de7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475de9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475deb  e884e8ffff             -call 0x474674
    cpu.esp -= 4;
    sub_474674(app, cpu);
    if (cpu.terminate) return;
    // 00475df0  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
    // 00475df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475df8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475df9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475dfa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475e00);
    // 00475e00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475e01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475e02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00475e04  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475e06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475e08  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00475e0a  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475e0e  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00475e11  83f908                 +cmp ecx, 8
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
    // 00475e14  751e                   -jne 0x475e34
    if (!cpu.flags.zf)
    {
        goto L_0x00475e34;
    }
L_0x00475e16:
    // 00475e16  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00475e19  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00475e1c  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00475e1e  8b35480f5400           -mov esi, dword ptr [0x540f48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475e24  2bb72c575400           -sub esi, dword ptr [edi + 0x54572c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5527340) /* 0x54572c */)));
    // 00475e2a  83fe02                 +cmp esi, 2
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
    // 00475e2d  7f28                   -jg 0x475e57
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00475e57;
    }
L_0x00475e2f:
    // 00475e2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e31  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00475e34:
    // 00475e34  83f907                 +cmp ecx, 7
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
    // 00475e37  74dd                   -je 0x475e16
    if (cpu.flags.zf)
    {
        goto L_0x00475e16;
    }
    // 00475e39  83f909                 +cmp ecx, 9
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
    // 00475e3c  74d8                   -je 0x475e16
    if (cpu.flags.zf)
    {
        goto L_0x00475e16;
    }
    // 00475e3e  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00475e41  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00475e44  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00475e46  8b35480f5400           -mov esi, dword ptr [0x540f48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475e4c  2bb72c575400           -sub esi, dword ptr [edi + 0x54572c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5527340) /* 0x54572c */)));
    // 00475e52  83fe05                 +cmp esi, 5
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
    // 00475e55  7ed8                   -jle 0x475e2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475e2f;
    }
L_0x00475e57:
    // 00475e57  8b35480f5400           -mov esi, dword ptr [0x540f48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00475e5d  89b72c575400           -mov dword ptr [edi + 0x54572c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5527340) /* 0x54572c */) = cpu.esi;
    // 00475e63  e80ce8ffff             -call 0x474674
    cpu.esp -= 4;
    sub_474674(app, cpu);
    if (cpu.terminate) return;
    // 00475e68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e6a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_475e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475e70);
    // 00475e70  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475e71  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00475e73  803800                 +cmp byte ptr [eax], 0
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
    // 00475e76  7515                   -jne 0x475e8d
    if (!cpu.flags.zf)
    {
        goto L_0x00475e8d;
    }
    // 00475e78  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00475e7b  e8d81a0100             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00475e80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475e82  7402                   -je 0x475e86
    if (cpu.flags.zf)
    {
        goto L_0x00475e86;
    }
    // 00475e84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e86:
    // 00475e86  e81a4f0200             -call 0x49ada5
    cpu.esp -= 4;
    sub_49ada5(app, cpu);
    if (cpu.terminate) return;
    // 00475e8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475e8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e8d:
    // 00475e8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475e8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475e8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475e90  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00475e92  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475e94  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00475e97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475e98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475e9a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00475e9d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475e9f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00475ea1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00475ea4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00475ea6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ea7  015d08                 -add dword ptr [ebp + 8], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00475eaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475eab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475eac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ead  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475eae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_475eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475eb0);
    // 00475eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475eb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475eb2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475eb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475eb7  803800                 +cmp byte ptr [eax], 0
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
    // 00475eba  7414                   -je 0x475ed0
    if (cpu.flags.zf)
    {
        goto L_0x00475ed0;
    }
    // 00475ebc  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00475ebf  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00475ec1  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00475ec4  ff4208                 -inc dword ptr [edx + 8]
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */))++;
L_0x00475ec7:
    // 00475ec7  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00475eca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475ecd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ece  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ecf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475ed0:
    // 00475ed0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475ed5  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00475ed8  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00475eda  e8791a0100             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00475edf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475ee1  75e4                   -jne 0x475ec7
    if (!cpu.flags.zf)
    {
        goto L_0x00475ec7;
    }
    // 00475ee3  e8bd4e0200             -call 0x49ada5
    cpu.esp -= 4;
    sub_49ada5(app, cpu);
    if (cpu.terminate) return;
    // 00475ee8  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00475eeb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475eee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475eef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ef0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475f00);
    // 00475f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475f01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475f02  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475f05  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475f07  803800                 +cmp byte ptr [eax], 0
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
    // 00475f0a  7415                   -je 0x475f21
    if (cpu.flags.zf)
    {
        goto L_0x00475f21;
    }
    // 00475f0c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00475f0f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00475f11  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00475f14  83420804               -add dword ptr [edx + 8], 4
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00475f18:
    // 00475f18  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475f1b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475f1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475f21:
    // 00475f21  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00475f26  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00475f29  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00475f2b  e8281a0100             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00475f30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475f32  75e4                   -jne 0x475f18
    if (!cpu.flags.zf)
    {
        goto L_0x00475f18;
    }
    // 00475f34  e86c4e0200             -call 0x49ada5
    cpu.esp -= 4;
    sub_49ada5(app, cpu);
    if (cpu.terminate) return;
    // 00475f39  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475f3c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475f3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475f50);
    // 00475f50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475f51  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475f53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475f55  741c                   -je 0x475f73
    if (cpu.flags.zf)
    {
        goto L_0x00475f73;
    }
    // 00475f57  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475f58  803800                 +cmp byte ptr [eax], 0
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
    // 00475f5b  750e                   -jne 0x475f6b
    if (!cpu.flags.zf)
    {
        goto L_0x00475f6b;
    }
    // 00475f5d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00475f60  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475f62  7407                   -je 0x475f6b
    if (cpu.flags.zf)
    {
        goto L_0x00475f6b;
    }
    // 00475f64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475f66  e8e5190100             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
L_0x00475f6b:
    // 00475f6b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475f6d  e88ae90000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00475f72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00475f73:
    // 00475f73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475f80);
    // 00475f80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475f81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475f82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475f83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475f84  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475f87  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00475f89  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00475f8b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00475f8f  baf0e24c00             -mov edx, 0x4ce2f0
    cpu.edx = 5038832 /*0x4ce2f0*/;
    // 00475f94  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00475f99  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00475f9e  b810e34c00             -mov eax, 0x4ce310
    cpu.eax = 5038864 /*0x4ce310*/;
    // 00475fa3  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 00475fa9  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 00475faf  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00475fb4  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00475fb9  e806e50000             -call 0x4844c4
    cpu.esp -= 4;
    sub_4844c4(app, cpu);
    if (cpu.terminate) return;
    // 00475fbe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00475fc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475fc2  7533                   -jne 0x475ff7
    if (!cpu.flags.zf)
    {
        goto L_0x00475ff7;
    }
    // 00475fc4  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00475fc9  7422                   -je 0x475fed
    if (cpu.flags.zf)
    {
        goto L_0x00475fed;
    }
    // 00475fcb  bdf0e24c00             -mov ebp, 0x4ce2f0
    cpu.ebp = 5038832 /*0x4ce2f0*/;
    // 00475fd0  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00475fd5  681ce34c00             -push 0x4ce31c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038876 /*0x4ce31c*/;
    cpu.esp -= 4;
    // 00475fda  892dd8b14d00           -mov dword ptr [0x4db1d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebp;
    // 00475fe0  a3dcb14d00             -mov dword ptr [0x4db1dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.eax;
    // 00475fe5  e806e10000             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00475fea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00475fed:
    // 00475fed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475fef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475ff2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ff3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ff4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ff5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ff6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475ff7:
    // 00475ff7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00475ff9  7543                   -jne 0x47603e
    if (!cpu.flags.zf)
    {
        goto L_0x0047603e;
    }
    // 00475ffb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00475ffd  753f                   -jne 0x47603e
    if (!cpu.flags.zf)
    {
        goto L_0x0047603e;
    }
L_0x00475fff:
    // 00475fff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00476001  7407                   -je 0x47600a
    if (cpu.flags.zf)
    {
        goto L_0x0047600a;
    }
    // 00476003  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476005  e8f2e80000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0047600a:
    // 0047600a  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0047600f  74dc                   -je 0x475fed
    if (cpu.flags.zf)
    {
        goto L_0x00475fed;
    }
    // 00476011  bbf0e24c00             -mov ebx, 0x4ce2f0
    cpu.ebx = 5038832 /*0x4ce2f0*/;
    // 00476016  be18000000             -mov esi, 0x18
    cpu.esi = 24 /*0x18*/;
    // 0047601b  683ce34c00             -push 0x4ce33c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038908 /*0x4ce33c*/;
    cpu.esp -= 4;
    // 00476020  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 00476026  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 0047602c  e8bfe00000             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00476031  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476034  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476036  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476039  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047603a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047603b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047603c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047603d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047603e:
    // 0047603e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00476040  7404                   -je 0x476046
    if (cpu.flags.zf)
    {
        goto L_0x00476046;
    }
    // 00476042  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00476044  75b9                   -jne 0x475fff
    if (!cpu.flags.zf)
    {
        goto L_0x00475fff;
    }
L_0x00476046:
    // 00476046  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00476048  7417                   -je 0x476061
    if (cpu.flags.zf)
    {
        goto L_0x00476061;
    }
    // 0047604a  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00476051  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 00476054  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x00476057:
    // 00476057  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476059  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047605c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047605d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047605e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047605f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476060  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476061:
    // 00476061  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476065  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476069  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047606b  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047606e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00476072  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00476075  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476076  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00476079  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047607b  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047607e  e8e5150100             -call 0x487668
    cpu.esp -= 4;
    sub_487668(app, cpu);
    if (cpu.terminate) return;
    // 00476083  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476087  75ce                   -jne 0x476057
    if (!cpu.flags.zf)
    {
        goto L_0x00476057;
    }
    // 00476089  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047608b  e86ce80000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00476090  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476092  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476095  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476096  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476097  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476098  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476099  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 09000000000000000b000000020000000d000000040000000e000000050000000c000000030000000f0000000600000010000000070000001100000008000000 */
void Application::sub_4760e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004760e0);
    // 004760e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4760f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004760f0);
    // 004760f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004760f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004760f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004760f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004760f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004760f5  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004760fb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004760fd  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004760ff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476101  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00476102:
    // 00476102  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00476104  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00476106  3c00                   +cmp al, 0
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
    // 00476108  7410                   -je 0x47611a
    if (cpu.flags.zf)
    {
        goto L_0x0047611a;
    }
    // 0047610a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047610d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00476110  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00476113  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00476116  3c00                   +cmp al, 0
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
    // 00476118  75e8                   -jne 0x476102
    if (!cpu.flags.zf)
    {
        goto L_0x00476102;
    }
L_0x0047611a:
    // 0047611a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047611b  be24e54c00             -mov esi, 0x4ce524
    cpu.esi = 5039396 /*0x4ce524*/;
    // 00476120  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00476122  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476124  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476125  2bc9                   +sub ecx, ecx
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
    // 00476127  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476128  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047612a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047612c  4f                     -dec edi
    (cpu.edi)--;
L_0x0047612d:
    // 0047612d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047612f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00476131  3c00                   +cmp al, 0
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
    // 00476133  7410                   -je 0x476145
    if (cpu.flags.zf)
    {
        goto L_0x00476145;
    }
    // 00476135  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00476138  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047613b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047613e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00476141  3c00                   +cmp al, 0
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
    // 00476143  75e8                   -jne 0x47612d
    if (!cpu.flags.zf)
    {
        goto L_0x0047612d;
    }
L_0x00476145:
    // 00476145  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476146  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476148  e8030e0100             -call 0x486f50
    cpu.esp -= 4;
    sub_486f50(app, cpu);
    if (cpu.terminate) return;
    // 0047614d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047614f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476151  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476153  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047615a  e805f20000             -call 0x485364
    cpu.esp -= 4;
    sub_485364(app, cpu);
    if (cpu.terminate) return;
    // 0047615f  83f807                 +cmp eax, 7
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
    // 00476162  742f                   -je 0x476193
    if (cpu.flags.zf)
    {
        goto L_0x00476193;
    }
L_0x00476164:
    // 00476164  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0047616b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047616d  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00476174  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047617b  899918b45000           -mov dword ptr [ecx + 0x50b418], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5288984) /* 0x50b418 */) = cpu.ebx;
    // 00476181  898110b45000           -mov dword ptr [ecx + 0x50b410], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5288976) /* 0x50b410 */) = cpu.eax;
    // 00476187  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047618d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047618e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047618f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476190  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476191  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476192  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476193:
    // 00476193  ba34e44c00             -mov edx, 0x4ce434
    cpu.edx = 5039156 /*0x4ce434*/;
    // 00476198  bb10030000             -mov ebx, 0x310
    cpu.ebx = 784 /*0x310*/;
    // 0047619d  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004761a4  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 004761aa  891ddcb14d00           -mov dword ptr [0x4db1dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebx;
    // 004761b0  e8abef0000             -call 0x485160
    cpu.esp -= 4;
    sub_485160(app, cpu);
    if (cpu.terminate) return;
    // 004761b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004761b7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004761b9  b82ce54c00             -mov eax, 0x4ce52c
    cpu.eax = 5039404 /*0x4ce52c*/;
    // 004761be  e8d5e20000             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004761c3  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004761ca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004761cc  e847f00000             -call 0x485218
    cpu.esp -= 4;
    sub_485218(app, cpu);
    if (cpu.terminate) return;
    // 004761d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004761d3  e824e70000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004761d8  eb8a                   -jmp 0x476164
    goto L_0x00476164;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4761e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004761e0);
    // 004761e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004761e1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004761e6  e819020100             -call 0x486404
    cpu.esp -= 4;
    sub_486404(app, cpu);
    if (cpu.terminate) return;
    // 004761eb  8b1518b45000           -mov edx, dword ptr [0x50b418]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5288984) /* 0x50b418 */);
    // 004761f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004761f3  7502                   -jne 0x4761f7
    if (!cpu.flags.zf)
    {
        goto L_0x004761f7;
    }
    // 004761f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004761f7:
    // 004761f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004761f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004761fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004761fc  e8fbe60000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00476201  890d18b45000           -mov dword ptr [0x50b418], ecx
    app->getMemory<x86::reg32>(x86::reg32(5288984) /* 0x50b418 */) = cpu.ecx;
    // 00476207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476208  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476209  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476210);
    // 00476210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476212  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476213  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00476215:
    // 00476215  8b8a18b45000           -mov ecx, dword ptr [edx + 0x50b418]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5288984) /* 0x50b418 */);
    // 0047621b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047621d  750c                   -jne 0x47622b
    if (!cpu.flags.zf)
    {
        goto L_0x0047622b;
    }
    // 0047621f  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476222  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476225  75ee                   -jne 0x476215
    if (!cpu.flags.zf)
    {
        goto L_0x00476215;
    }
    // 00476227  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476228  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476229  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047622a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047622b:
    // 0047622b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047622d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047622f  e8c8e60000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00476234  899a18b45000           -mov dword ptr [edx + 0x50b418], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5288984) /* 0x50b418 */) = cpu.ebx;
    // 0047623a  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047623d  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476240  75d3                   -jne 0x476215
    if (!cpu.flags.zf)
    {
        goto L_0x00476215;
    }
    // 00476242  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476243  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476244  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476250);
    // 00476250  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476257  7509                   -jne 0x476262
    if (!cpu.flags.zf)
    {
        goto L_0x00476262;
    }
    // 00476259  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476260  7501                   -jne 0x476263
    if (!cpu.flags.zf)
    {
        goto L_0x00476263;
    }
L_0x00476262:
    // 00476262  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476263:
    // 00476263  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476264  e827f70100             -call 0x495990
    cpu.esp -= 4;
    sub_495990(app, cpu);
    if (cpu.terminate) return;
    // 00476269  a1a8964d00             -mov eax, dword ptr [0x4d96a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */);
    // 0047626e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00476270  e837d70100             -call 0x4939ac
    cpu.esp -= 4;
    sub_4939ac(app, cpu);
    if (cpu.terminate) return;
    // 00476275  890da8964d00           -mov dword ptr [0x4d96a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */) = cpu.ecx;
    // 0047627b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047627c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_476280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476280);
    // 00476280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476281  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476288  7509                   -jne 0x476293
    if (!cpu.flags.zf)
    {
        goto L_0x00476293;
    }
    // 0047628a  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476291  7502                   -jne 0x476295
    if (!cpu.flags.zf)
    {
        goto L_0x00476295;
    }
L_0x00476293:
    // 00476293  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476294  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476295:
    // 00476295  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476297  e864350100             -call 0x489800
    cpu.esp -= 4;
    sub_489800(app, cpu);
    if (cpu.terminate) return;
    // 0047629c  e88bf80100             -call 0x495b2c
    cpu.esp -= 4;
    sub_495b2c(app, cpu);
    if (cpu.terminate) return;
    // 004762a1  803da4964d0000         +cmp byte ptr [0x4d96a4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084836) /* 0x4d96a4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004762a8  7422                   -je 0x4762cc
    if (cpu.flags.zf)
    {
        goto L_0x004762cc;
    }
    // 004762aa  e8e1f60100             -call 0x495990
    cpu.esp -= 4;
    sub_495990(app, cpu);
    if (cpu.terminate) return;
L_0x004762af:
    // 004762af  8b0d40595400           -mov ecx, dword ptr [0x545940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5527872) /* 0x545940 */);
    // 004762b5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004762b7  74da                   -je 0x476293
    if (cpu.flags.zf)
    {
        goto L_0x00476293;
    }
    // 004762b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004762ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004762bc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004762be  e839e60000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004762c3  891d40595400           -mov dword ptr [0x545940], ebx
    app->getMemory<x86::reg32>(x86::reg32(5527872) /* 0x545940 */) = cpu.ebx;
    // 004762c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004762cc:
    // 004762cc  e81b7d0200             -call 0x49dfec
    cpu.esp -= 4;
    sub_49dfec(app, cpu);
    if (cpu.terminate) return;
    // 004762d1  ebdc                   -jmp 0x4762af
    goto L_0x004762af;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4762e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004762e0);
    // 004762e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004762e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004762e2  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004762e9  7509                   -jne 0x4762f4
    if (!cpu.flags.zf)
    {
        goto L_0x004762f4;
    }
    // 004762eb  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004762f2  7503                   -jne 0x4762f7
    if (!cpu.flags.zf)
    {
        goto L_0x004762f7;
    }
L_0x004762f4:
    // 004762f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004762f7:
    // 004762f7  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004762fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004762fe  e89d010100             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
L_0x00476303:
    // 00476303  e8e89b0200             -call 0x49fef0
    cpu.esp -= 4;
    sub_49fef0(app, cpu);
    if (cpu.terminate) return;
    // 00476308  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047630a  7e09                   -jle 0x476315
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00476315;
    }
    // 0047630c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047630e  e89ddb0000             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00476313  ebee                   -jmp 0x476303
    goto L_0x00476303;
L_0x00476315:
    // 00476315  e812f80100             -call 0x495b2c
    cpu.esp -= 4;
    sub_495b2c(app, cpu);
    if (cpu.terminate) return;
    // 0047631a  803da4964d0000         +cmp byte ptr [0x4d96a4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084836) /* 0x4d96a4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476321  7423                   -je 0x476346
    if (cpu.flags.zf)
    {
        goto L_0x00476346;
    }
    // 00476323  e868f60100             -call 0x495990
    cpu.esp -= 4;
    sub_495990(app, cpu);
    if (cpu.terminate) return;
L_0x00476328:
    // 00476328  8b0d40595400           -mov ecx, dword ptr [0x545940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5527872) /* 0x545940 */);
    // 0047632e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476330  74c2                   -je 0x4762f4
    if (cpu.flags.zf)
    {
        goto L_0x004762f4;
    }
    // 00476332  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476333  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476335  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00476337  e8c0e50000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0047633c  891d40595400           -mov dword ptr [0x545940], ebx
    app->getMemory<x86::reg32>(x86::reg32(5527872) /* 0x545940 */) = cpu.ebx;
    // 00476342  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476343  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476344  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476345  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476346:
    // 00476346  e8a17c0200             -call 0x49dfec
    cpu.esp -= 4;
    sub_49dfec(app, cpu);
    if (cpu.terminate) return;
    // 0047634b  ebdb                   -jmp 0x476328
    goto L_0x00476328;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_476350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476350);
    // 00476350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476351  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476352  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00476358  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047635a  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047635d  7502                   -jne 0x476361
    if (!cpu.flags.zf)
    {
        goto L_0x00476361;
    }
    // 0047635f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00476361:
    // 00476361  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476368  0f85d5000000           -jne 0x476443
    if (!cpu.flags.zf)
    {
        goto L_0x00476443;
    }
    // 0047636e  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476375  0f84c8000000           -je 0x476443
    if (cpu.flags.zf)
    {
        goto L_0x00476443;
    }
    // 0047637b  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047637e  0f8fbf000000           -jg 0x476443
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00476443;
    }
    // 00476384  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476386  0f85c0000000           -jne 0x47644c
    if (!cpu.flags.zf)
    {
        goto L_0x0047644c;
    }
    // 0047638c  a3385a4d00             -mov dword ptr [0x4d5a38], eax
    app->getMemory<x86::reg32>(x86::reg32(5069368) /* 0x4d5a38 */) = cpu.eax;
L_0x00476391:
    // 00476391  833d085a4d0001         +cmp dword ptr [0x4d5a08], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069320) /* 0x4d5a08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476398  7511                   -jne 0x4763ab
    if (!cpu.flags.zf)
    {
        goto L_0x004763ab;
    }
    // 0047639a  83f809                 +cmp eax, 9
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
    // 0047639d  7d0c                   -jge 0x4763ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004763ab;
    }
    // 0047639f  803d3f2f510000         +cmp byte ptr [0x512f3f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320511) /* 0x512f3f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004763a6  7403                   -je 0x4763ab
    if (cpu.flags.zf)
    {
        goto L_0x004763ab;
    }
    // 004763a8  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x004763ab:
    // 004763ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004763ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004763ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004763ae  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004763b1  0f84a4000000           -je 0x47645b
    if (cpu.flags.zf)
    {
        goto L_0x0047645b;
    }
    // 004763b7  8b148558974d00         -mov edx, dword ptr [eax*4 + 0x4d9758]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085016) /* 0x4d9758 */ + cpu.eax * 4);
    // 004763be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004763bf  8b0da0345100           -mov ecx, dword ptr [0x5134a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 004763c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004763c6  687ce44c00             -push 0x4ce47c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039228 /*0x4ce47c*/;
    cpu.esp -= 4;
    // 004763cb  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004763cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004763d0  e82c010100             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004763d5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004763d8:
    // 004763d8  be00e54c00             -mov esi, 0x4ce500
    cpu.esi = 5039360 /*0x4ce500*/;
    // 004763dd  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004763e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004763e2  2bc9                   +sub ecx, ecx
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
    // 004763e4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004763e5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004763e7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004763e9  4f                     -dec edi
    (cpu.edi)--;
L_0x004763ea:
    // 004763ea  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004763ec  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004763ee  3c00                   +cmp al, 0
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
    // 004763f0  7410                   -je 0x476402
    if (cpu.flags.zf)
    {
        goto L_0x00476402;
    }
    // 004763f2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004763f5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004763f8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004763fb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004763fe  3c00                   +cmp al, 0
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
    // 00476400  75e8                   -jne 0x4763ea
    if (!cpu.flags.zf)
    {
        goto L_0x004763ea;
    }
L_0x00476402:
    // 00476402  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476403  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0047640a  e871ef0000             -call 0x485380
    cpu.esp -= 4;
    sub_485380(app, cpu);
    if (cpu.terminate) return;
    // 0047640f  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00476411  8d94240c010000         -lea edx, [esp + 0x10c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00476418  88842414010000         -mov byte ptr [esp + 0x114], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.al;
    // 0047641f  a1a8964d00             -mov eax, dword ptr [0x4d96a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */);
    // 00476424  e8a7f40100             -call 0x4958d0
    cpu.esp -= 4;
    sub_4958d0(app, cpu);
    if (cpu.terminate) return;
    // 00476429  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047642d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047642f  e8b8f50100             -call 0x4959ec
    cpu.esp -= 4;
    sub_4959ec(app, cpu);
    if (cpu.terminate) return;
    // 00476434  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00476439  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047643b  e860000100             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
    // 00476440  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476441  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00476443:
    // 00476443  81c410010000           +add esp, 0x110
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(272 /*0x110*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476449  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047644a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047644b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047644c:
    // 0047644c  c705385a4d0001000000   -mov dword ptr [0x4d5a38], 1
    app->getMemory<x86::reg32>(x86::reg32(5069368) /* 0x4d5a38 */) = 1 /*0x1*/;
    // 00476456  e936ffffff             -jmp 0x476391
    goto L_0x00476391;
L_0x0047645b:
    // 0047645b  803daa974d0000         +cmp byte ptr [0x4d97aa], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085098) /* 0x4d97aa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476462  742d                   -je 0x476491
    if (cpu.flags.zf)
    {
        goto L_0x00476491;
    }
    // 00476464  a1a0345100             -mov eax, dword ptr [0x5134a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476469  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047646a  6884e44c00             -push 0x4ce484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039236 /*0x4ce484*/;
    cpu.esp -= 4;
L_0x0047646f:
    // 0047646f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476473  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476474  e888000100             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476479  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047647c  803daa974d0000         +cmp byte ptr [0x4d97aa], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085098) /* 0x4d97aa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476483  751a                   -jne 0x47649f
    if (!cpu.flags.zf)
    {
        goto L_0x0047649f;
    }
    // 00476485  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00476487  a2aa974d00             -mov byte ptr [0x4d97aa], al
    app->getMemory<x86::reg8>(x86::reg32(5085098) /* 0x4d97aa */) = cpu.al;
    // 0047648c  e947ffffff             -jmp 0x4763d8
    goto L_0x004763d8;
L_0x00476491:
    // 00476491  8b2da0345100           -mov ebp, dword ptr [0x5134a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476497  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476498  688ce44c00             -push 0x4ce48c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039244 /*0x4ce48c*/;
    cpu.esp -= 4;
    // 0047649d  ebd0                   -jmp 0x47646f
    goto L_0x0047646f;
L_0x0047649f:
    // 0047649f  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004764a1  a2aa974d00             -mov byte ptr [0x4d97aa], al
    app->getMemory<x86::reg8>(x86::reg32(5085098) /* 0x4d97aa */) = cpu.al;
    // 004764a6  e92dffffff             -jmp 0x4763d8
    goto L_0x004763d8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4764b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004764b0);
    // 004764b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004764b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004764b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004764b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004764b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004764b5  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004764bb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004764bd  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 004764c4  bbdc050000             -mov ebx, 0x5dc
    cpu.ebx = 1500 /*0x5dc*/;
    // 004764c9  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004764cc  7502                   -jne 0x4764d0
    if (!cpu.flags.zf)
    {
        goto L_0x004764d0;
    }
    // 004764ce  31c5                   -xor ebp, eax
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004764d0:
    // 004764d0  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004764d2  8a15cc2e5100           -mov dl, byte ptr [0x512ecc]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
    // 004764d8  8825a4964d00           -mov byte ptr [0x4d96a4], ah
    app->getMemory<x86::reg8>(x86::reg32(5084836) /* 0x4d96a4 */) = cpu.ah;
    // 004764de  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004764e0  7543                   -jne 0x476525
    if (!cpu.flags.zf)
    {
        goto L_0x00476525;
    }
    // 004764e2  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004764e9  743a                   -je 0x476525
    if (cpu.flags.zf)
    {
        goto L_0x00476525;
    }
    // 004764eb  83fd13                 +cmp ebp, 0x13
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004764ee  7f35                   -jg 0x476525
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00476525;
    }
    // 004764f0  803d3f2f510000         +cmp byte ptr [0x512f3f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320511) /* 0x512f3f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004764f7  7538                   -jne 0x476531
    if (!cpu.flags.zf)
    {
        goto L_0x00476531;
    }
    // 004764f9  83fd09                 +cmp ebp, 9
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
    // 004764fc  7d33                   -jge 0x476531
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476531;
    }
    // 004764fe  803d402f510000         +cmp byte ptr [0x512f40], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320512) /* 0x512f40 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476505  7609                   -jbe 0x476510
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00476510;
    }
    // 00476507  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476509  e8c2010000             -call 0x4766d0
    cpu.esp -= 4;
    sub_4766d0(app, cpu);
    if (cpu.terminate) return;
    // 0047650e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00476510:
    // 00476510  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00476517  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476519  e832feffff             -call 0x476350
    cpu.esp -= 4;
    sub_476350(app, cpu);
    if (cpu.terminate) return;
    // 0047651e  c605a4964d0001         -mov byte ptr [0x4d96a4], 1
    app->getMemory<x86::reg8>(x86::reg32(5084836) /* 0x4d96a4 */) = 1 /*0x1*/;
L_0x00476525:
    // 00476525  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047652b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047652c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047652d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047652e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047652f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476530  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476531:
    // 00476531  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00476533  0f852f010000           -jne 0x476668
    if (!cpu.flags.zf)
    {
        goto L_0x00476668;
    }
    // 00476539  892d385a4d00           -mov dword ptr [0x4d5a38], ebp
    app->getMemory<x86::reg32>(x86::reg32(5069368) /* 0x4d5a38 */) = cpu.ebp;
L_0x0047653f:
    // 0047653f  833d085a4d0001         +cmp dword ptr [0x4d5a08], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069320) /* 0x4d5a08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476546  7508                   -jne 0x476550
    if (!cpu.flags.zf)
    {
        goto L_0x00476550;
    }
    // 00476548  83fd09                 +cmp ebp, 9
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
    // 0047654b  7d03                   -jge 0x476550
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476550;
    }
    // 0047654d  83c509                 -add ebp, 9
    (cpu.ebp) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00476550:
    // 00476550  83fd12                 +cmp ebp, 0x12
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476553  0f841e010000           -je 0x476677
    if (cpu.flags.zf)
    {
        goto L_0x00476677;
    }
    // 00476559  8b0cad58974d00         -mov ecx, dword ptr [ebp*4 + 0x4d9758]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085016) /* 0x4d9758 */ + cpu.ebp * 4);
    // 00476560  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476561  8b35a0345100           -mov esi, dword ptr [0x5134a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476567  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476568  687ce44c00             -push 0x4ce47c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039228 /*0x4ce47c*/;
    cpu.esp -= 4;
    // 0047656d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476571  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476572  e88aff0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476577  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047657a:
    // 0047657a  beb4e44c00             -mov esi, 0x4ce4b4
    cpu.esi = 5039284 /*0x4ce4b4*/;
    // 0047657f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00476581  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00476586  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476587  2bc9                   +sub ecx, ecx
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
    // 00476589  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047658a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047658c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047658e  4f                     -dec edi
    (cpu.edi)--;
L_0x0047658f:
    // 0047658f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00476591  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00476593  3c00                   +cmp al, 0
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
    // 00476595  7410                   -je 0x4765a7
    if (cpu.flags.zf)
    {
        goto L_0x004765a7;
    }
    // 00476597  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047659a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047659d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004765a0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004765a3  3c00                   +cmp al, 0
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
    // 004765a5  75e8                   -jne 0x47658f
    if (!cpu.flags.zf)
    {
        goto L_0x0047658f;
    }
L_0x004765a7:
    // 004765a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765a8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004765aa  e891090100             -call 0x486f40
    cpu.esp -= 4;
    sub_486f40(app, cpu);
    if (cpu.terminate) return;
    // 004765af  a340595400             -mov dword ptr [0x545940], eax
    app->getMemory<x86::reg32>(x86::reg32(5527872) /* 0x545940 */) = cpu.eax;
    // 004765b4  e81b780200             -call 0x49ddd4
    cpu.esp -= 4;
    sub_49ddd4(app, cpu);
    if (cpu.terminate) return;
    // 004765b9  8b3d84345100           -mov edi, dword ptr [0x513484]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5321860) /* 0x513484 */);
    // 004765bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004765c0  68f8e44c00             -push 0x4ce4f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039352 /*0x4ce4f8*/;
    cpu.esp -= 4;
    // 004765c5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004765c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004765ca  bed0e44c00             -mov esi, 0x4ce4d0
    cpu.esi = 5039312 /*0x4ce4d0*/;
    // 004765cf  e82dff0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004765d4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004765d7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004765d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004765db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004765dc  2bc9                   +sub ecx, ecx
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
    // 004765de  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004765df  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004765e1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004765e3  4f                     -dec edi
    (cpu.edi)--;
L_0x004765e4:
    // 004765e4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004765e6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004765e8  3c00                   +cmp al, 0
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
    // 004765ea  7410                   -je 0x4765fc
    if (cpu.flags.zf)
    {
        goto L_0x004765fc;
    }
    // 004765ec  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004765ef  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004765f2  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004765f5  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004765f8  3c00                   +cmp al, 0
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
    // 004765fa  75e8                   -jne 0x4765e4
    if (!cpu.flags.zf)
    {
        goto L_0x004765e4;
    }
L_0x004765fc:
    // 004765fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765fd  a1a8964d00             -mov eax, dword ptr [0x4d96a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */);
    // 00476602  e869780200             -call 0x49de70
    cpu.esp -= 4;
    sub_49de70(app, cpu);
    if (cpu.terminate) return;
    // 00476607  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047660c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047660e  e88dfe0000             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
    // 00476613  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047661a  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0047661f  e87cfe0000             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
    // 00476624  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047662b  0f84f4feffff           -je 0x476525
    if (cpu.flags.zf)
    {
        goto L_0x00476525;
    }
    // 00476631  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00476633  0f84ecfeffff           -je 0x476525
    if (cpu.flags.zf)
    {
        goto L_0x00476525;
    }
    // 00476639  83fd09                 +cmp ebp, 9
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
    // 0047663c  0f84e3feffff           -je 0x476525
    if (cpu.flags.zf)
    {
        goto L_0x00476525;
    }
    // 00476642  8a04adb8964d00         -mov al, byte ptr [ebp*4 + 0x4d96b8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5084856) /* 0x4d96b8 */ + cpu.ebp * 4);
    // 00476649  a2045a4d00             -mov byte ptr [0x4d5a04], al
    app->getMemory<x86::reg8>(x86::reg32(5069316) /* 0x4d5a04 */) = cpu.al;
    // 0047664e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476650  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476652  a0045a4d00             -mov al, byte ptr [0x4d5a04]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5069316) /* 0x4d5a04 */);
    // 00476657  e808790200             -call 0x49df64
    cpu.esp -= 4;
    sub_49df64(app, cpu);
    if (cpu.terminate) return;
    // 0047665c  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476662  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476663  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476664  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476665  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476666  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476667  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476668:
    // 00476668  c705385a4d0001000000   -mov dword ptr [0x4d5a38], 1
    app->getMemory<x86::reg32>(x86::reg32(5069368) /* 0x4d5a38 */) = 1 /*0x1*/;
    // 00476672  e9c8feffff             -jmp 0x47653f
    goto L_0x0047653f;
L_0x00476677:
    // 00476677  803da9974d0000         +cmp byte ptr [0x4d97a9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085097) /* 0x4d97a9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047667e  742e                   -je 0x4766ae
    if (cpu.flags.zf)
    {
        goto L_0x004766ae;
    }
    // 00476680  8b15a0345100           -mov edx, dword ptr [0x5134a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476686  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476687  6884e44c00             -push 0x4ce484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039236 /*0x4ce484*/;
    cpu.esp -= 4;
L_0x0047668c:
    // 0047668c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476690  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476691  e86bfe0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476696  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476699  803da9974d0000         +cmp byte ptr [0x4d97a9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085097) /* 0x4d97a9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004766a0  7519                   -jne 0x4766bb
    if (!cpu.flags.zf)
    {
        goto L_0x004766bb;
    }
    // 004766a2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004766a4  a2a9974d00             -mov byte ptr [0x4d97a9], al
    app->getMemory<x86::reg8>(x86::reg32(5085097) /* 0x4d97a9 */) = cpu.al;
    // 004766a9  e9ccfeffff             -jmp 0x47657a
    goto L_0x0047657a;
L_0x004766ae:
    // 004766ae  a1a0345100             -mov eax, dword ptr [0x5134a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 004766b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004766b4  688ce44c00             -push 0x4ce48c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039244 /*0x4ce48c*/;
    cpu.esp -= 4;
    // 004766b9  ebd1                   -jmp 0x47668c
    goto L_0x0047668c;
L_0x004766bb:
    // 004766bb  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004766bd  a2a9974d00             -mov byte ptr [0x4d97a9], al
    app->getMemory<x86::reg8>(x86::reg32(5085097) /* 0x4d97a9 */) = cpu.al;
    // 004766c2  e9b3feffff             -jmp 0x47657a
    goto L_0x0047657a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4766d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004766d0);
    // 004766d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004766d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004766d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004766d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004766d4  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004766d7  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004766dc  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004766de  bea0604700             -mov esi, 0x4760a0
    cpu.esi = 4677792 /*0x4760a0*/;
    // 004766e3  8a153f2f5100           -mov dl, byte ptr [0x512f3f]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5320511) /* 0x512f3f */);
    // 004766e9  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004766eb  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004766ed  7513                   -jne 0x476702
    if (!cpu.flags.zf)
    {
        goto L_0x00476702;
    }
    // 004766ef  8a35402f5100           -mov dh, byte ptr [0x512f40]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5320512) /* 0x512f40 */);
    // 004766f5  80fe11                 +cmp dh, 0x11
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004766f8  7410                   -je 0x47670a
    if (cpu.flags.zf)
    {
        goto L_0x0047670a;
    }
    // 004766fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004766fc  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 004766fe  8b4484fc               -mov eax, dword ptr [esp + eax*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
L_0x00476702:
    // 00476702  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00476705  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476706  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476707  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476708  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476709  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047670a:
    // 0047670a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047670b  8a1d80b45000           -mov bl, byte ptr [0x50b480]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5289088) /* 0x50b480 */);
    // 00476711  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476713  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 00476715  8a92495a4d00           -mov dl, byte ptr [edx + 0x4d5a49]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5069385) /* 0x4d5a49 */);
    // 0047671b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476721  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00476726  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476728  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047672b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047672d  fec3                   -inc bl
    (cpu.bl)++;
    // 0047672f  881d80b45000           -mov byte ptr [0x50b480], bl
    app->getMemory<x86::reg8>(x86::reg32(5289088) /* 0x50b480 */) = cpu.bl;
    // 00476735  8b449404               -mov eax, dword ptr [esp + edx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 00476739  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047673a  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047673d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047673e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047673f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476740  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476741  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476750);
    // 00476750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476751  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476752  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00476758  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047675a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047675c  c7842400010000dc050000 -mov dword ptr [esp + 0x100], 0x5dc
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = 1500 /*0x5dc*/;
    // 00476767  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047676a  7502                   -jne 0x47676e
    if (!cpu.flags.zf)
    {
        goto L_0x0047676e;
    }
    // 0047676c  31c3                   -xor ebx, eax
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047676e:
    // 0047676e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00476770  8a15cc2e5100           -mov dl, byte ptr [0x512ecc]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
    // 00476776  8825a4964d00           -mov byte ptr [0x4d96a4], ah
    app->getMemory<x86::reg8>(x86::reg32(5084836) /* 0x4d96a4 */) = cpu.ah;
    // 0047677c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047677e  0f854d010000           -jne 0x4768d1
    if (!cpu.flags.zf)
    {
        goto L_0x004768d1;
    }
    // 00476784  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047678b  0f8440010000           -je 0x4768d1
    if (cpu.flags.zf)
    {
        goto L_0x004768d1;
    }
    // 00476791  83fb13                 +cmp ebx, 0x13
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
    // 00476794  0f8f37010000           -jg 0x4768d1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004768d1;
    }
    // 0047679a  803d3f2f510000         +cmp byte ptr [0x512f3f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320511) /* 0x512f3f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004767a1  7509                   -jne 0x4767ac
    if (!cpu.flags.zf)
    {
        goto L_0x004767ac;
    }
    // 004767a3  83fb09                 +cmp ebx, 9
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
    // 004767a6  0f8c2e010000           -jl 0x4768da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004768da;
    }
L_0x004767ac:
    // 004767ac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004767ae  0f853f010000           -jne 0x4768f3
    if (!cpu.flags.zf)
    {
        goto L_0x004768f3;
    }
    // 004767b4  891d385a4d00           -mov dword ptr [0x4d5a38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5069368) /* 0x4d5a38 */) = cpu.ebx;
L_0x004767ba:
    // 004767ba  833d085a4d0001         +cmp dword ptr [0x4d5a08], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069320) /* 0x4d5a08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004767c1  7508                   -jne 0x4767cb
    if (!cpu.flags.zf)
    {
        goto L_0x004767cb;
    }
    // 004767c3  83fb09                 +cmp ebx, 9
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
    // 004767c6  7d03                   -jge 0x4767cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004767cb;
    }
    // 004767c8  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x004767cb:
    // 004767cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004767cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004767cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004767ce  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004767d1  0f842b010000           -je 0x476902
    if (cpu.flags.zf)
    {
        goto L_0x00476902;
    }
    // 004767d7  8b349d58974d00         -mov esi, dword ptr [ebx*4 + 0x4d9758]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085016) /* 0x4d9758 */ + cpu.ebx * 4);
    // 004767de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004767df  8b3da0345100           -mov edi, dword ptr [0x5134a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 004767e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004767e6  687ce44c00             -push 0x4ce47c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039228 /*0x4ce47c*/;
    cpu.esp -= 4;
    // 004767eb  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004767ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004767f0  e80cfd0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004767f5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004767f8:
    // 004767f8  beb4e44c00             -mov esi, 0x4ce4b4
    cpu.esi = 5039284 /*0x4ce4b4*/;
    // 004767fd  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476801  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00476806  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476807  2bc9                   +sub ecx, ecx
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
    // 00476809  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047680a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047680c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047680e  4f                     -dec edi
    (cpu.edi)--;
L_0x0047680f:
    // 0047680f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00476811  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00476813  3c00                   +cmp al, 0
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
    // 00476815  7410                   -je 0x476827
    if (cpu.flags.zf)
    {
        goto L_0x00476827;
    }
    // 00476817  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047681a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047681d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00476820  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00476823  3c00                   +cmp al, 0
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
    // 00476825  75e8                   -jne 0x47680f
    if (!cpu.flags.zf)
    {
        goto L_0x0047680f;
    }
L_0x00476827:
    // 00476827  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476828  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047682c  e80f070100             -call 0x486f40
    cpu.esp -= 4;
    sub_486f40(app, cpu);
    if (cpu.terminate) return;
    // 00476831  a340595400             -mov dword ptr [0x545940], eax
    app->getMemory<x86::reg32>(x86::reg32(5527872) /* 0x545940 */) = cpu.eax;
    // 00476836  e899750200             -call 0x49ddd4
    cpu.esp -= 4;
    sub_49ddd4(app, cpu);
    if (cpu.terminate) return;
    // 0047683b  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047683e  0f8412010000           -je 0x476956
    if (cpu.flags.zf)
    {
        goto L_0x00476956;
    }
    // 00476844  8b0c9d08974d00         -mov ecx, dword ptr [ebx*4 + 0x4d9708]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084936) /* 0x4d9708 */ + cpu.ebx * 4);
    // 0047684b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047684c  8b1da0345100           -mov ebx, dword ptr [0x5134a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476852  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476853  687ce44c00             -push 0x4ce47c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039228 /*0x4ce47c*/;
    cpu.esp -= 4;
    // 00476858  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047685c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047685d  e89ffc0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476862  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00476865:
    // 00476865  bed0e44c00             -mov esi, 0x4ce4d0
    cpu.esi = 5039312 /*0x4ce4d0*/;
    // 0047686a  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047686e  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00476875  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476876  2bc9                   +sub ecx, ecx
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
    // 00476878  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476879  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047687b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047687d  4f                     -dec edi
    (cpu.edi)--;
L_0x0047687e:
    // 0047687e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00476880  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00476882  3c00                   +cmp al, 0
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
    // 00476884  7410                   -je 0x476896
    if (cpu.flags.zf)
    {
        goto L_0x00476896;
    }
    // 00476886  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00476889  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047688c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047688f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00476892  3c00                   +cmp al, 0
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
    // 00476894  75e8                   -jne 0x47687e
    if (!cpu.flags.zf)
    {
        goto L_0x0047687e;
    }
L_0x00476896:
    // 00476896  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476897  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476899  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047689d  e80e720200             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 004768a2  a1a8964d00             -mov eax, dword ptr [0x4d96a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */);
    // 004768a7  e8c4750200             -call 0x49de70
    cpu.esp -= 4;
    sub_49de70(app, cpu);
    if (cpu.terminate) return;
    // 004768ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004768b1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004768b3  e8e8fb0000             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
    // 004768b8  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 004768bd  e8ee710200             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 004768c2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004768c4  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004768c9  e8d2fb0000             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
    // 004768ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004768d1:
    // 004768d1  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004768d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004768da:
    // 004768da  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004768dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004768de  e86dfaffff             -call 0x476350
    cpu.esp -= 4;
    sub_476350(app, cpu);
    if (cpu.terminate) return;
    // 004768e3  c605a4964d0001         -mov byte ptr [0x4d96a4], 1
    app->getMemory<x86::reg8>(x86::reg32(5084836) /* 0x4d96a4 */) = 1 /*0x1*/;
    // 004768ea  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004768f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004768f3:
    // 004768f3  c705385a4d0001000000   -mov dword ptr [0x4d5a38], 1
    app->getMemory<x86::reg32>(x86::reg32(5069368) /* 0x4d5a38 */) = 1 /*0x1*/;
    // 004768fd  e9b8feffff             -jmp 0x4767ba
    goto L_0x004767ba;
L_0x00476902:
    // 00476902  803da8974d0000         +cmp byte ptr [0x4d97a8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085096) /* 0x4d97a8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476909  7529                   -jne 0x476934
    if (!cpu.flags.zf)
    {
        goto L_0x00476934;
    }
    // 0047690b  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047690d:
    // 0047690d  a2a8974d00             -mov byte ptr [0x4d97a8], al
    app->getMemory<x86::reg8>(x86::reg32(5085096) /* 0x4d97a8 */) = cpu.al;
    // 00476912  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00476914  7422                   -je 0x476938
    if (cpu.flags.zf)
    {
        goto L_0x00476938;
    }
    // 00476916  8b0da0345100           -mov ecx, dword ptr [0x5134a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 0047691c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047691d  6884e44c00             -push 0x4ce484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039236 /*0x4ce484*/;
    cpu.esp -= 4;
    // 00476922  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476926  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476927  e8d5fb0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0047692c  83c40c                 +add esp, 0xc
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
    // 0047692f  e9c4feffff             -jmp 0x4767f8
    goto L_0x004767f8;
L_0x00476934:
    // 00476934  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00476936  ebd5                   -jmp 0x47690d
    goto L_0x0047690d;
L_0x00476938:
    // 00476938  8b15a0345100           -mov edx, dword ptr [0x5134a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 0047693e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047693f  688ce44c00             -push 0x4ce48c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039244 /*0x4ce48c*/;
    cpu.esp -= 4;
    // 00476944  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476948  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476949  e8b3fb0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0047694e  83c40c                 +add esp, 0xc
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
    // 00476951  e9a2feffff             -jmp 0x4767f8
    goto L_0x004767f8;
L_0x00476956:
    // 00476956  803da8974d0000         +cmp byte ptr [0x4d97a8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085096) /* 0x4d97a8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047695d  741e                   -je 0x47697d
    if (cpu.flags.zf)
    {
        goto L_0x0047697d;
    }
    // 0047695f  8b15a0345100           -mov edx, dword ptr [0x5134a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476965  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476966  6884e44c00             -push 0x4ce484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039236 /*0x4ce484*/;
    cpu.esp -= 4;
    // 0047696b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047696f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476970  e88cfb0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476975  83c40c                 +add esp, 0xc
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
    // 00476978  e9e8feffff             -jmp 0x476865
    goto L_0x00476865;
L_0x0047697d:
    // 0047697d  a1a0345100             -mov eax, dword ptr [0x5134a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476982  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476983  688ce44c00             -push 0x4ce48c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039244 /*0x4ce48c*/;
    cpu.esp -= 4;
    // 00476988  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047698c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047698d  e86ffb0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476992  83c40c                 +add esp, 0xc
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
    // 00476995  e9cbfeffff             -jmp 0x476865
    goto L_0x00476865;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4769a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004769a0);
    // 004769a0  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004769a7  7509                   -jne 0x4769b2
    if (!cpu.flags.zf)
    {
        goto L_0x004769b2;
    }
    // 004769a9  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004769b0  7501                   -jne 0x4769b3
    if (!cpu.flags.zf)
    {
        goto L_0x004769b3;
    }
L_0x004769b2:
    // 004769b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004769b3:
    // 004769b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004769b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004769b5  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 004769ba  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004769bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004769bf  e854cd0100             -call 0x493718
    cpu.esp -= 4;
    sub_493718(app, cpu);
    if (cpu.terminate) return;
    // 004769c4  a3a8964d00             -mov dword ptr [0x4d96a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */) = cpu.eax;
    // 004769c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004769ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004769cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4769d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004769d0);
    // 004769d0  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004769d7  7509                   -jne 0x4769e2
    if (!cpu.flags.zf)
    {
        goto L_0x004769e2;
    }
    // 004769d9  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004769e0  7501                   -jne 0x4769e3
    if (!cpu.flags.zf)
    {
        goto L_0x004769e3;
    }
L_0x004769e2:
    // 004769e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004769e3:
    // 004769e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004769e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004769e5  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 004769ea  b800b00400             -mov eax, 0x4b000
    cpu.eax = 307200 /*0x4b000*/;
    // 004769ef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004769f1  e822cd0100             -call 0x493718
    cpu.esp -= 4;
    sub_493718(app, cpu);
    if (cpu.terminate) return;
    // 004769f6  a3a8964d00             -mov dword ptr [0x4d96a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5084840) /* 0x4d96a8 */) = cpu.eax;
    // 004769fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004769fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004769fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_476a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476a00);
    // 00476a00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476a01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476a02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476a03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476a04  81ec20010000           -sub esp, 0x120
    (cpu.esp) -= x86::reg32(x86::sreg32(288 /*0x120*/));
    // 00476a0a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476a0c  be00000800             -mov esi, 0x80000
    cpu.esi = 524288 /*0x80000*/;
    // 00476a11  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00476a13  8a253f2f5100           -mov ah, byte ptr [0x512f3f]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5320511) /* 0x512f3f */);
    // 00476a19  89bc241c010000         -mov dword ptr [esp + 0x11c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */) = cpu.edi;
    // 00476a20  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00476a22  0f845b010000           -je 0x476b83
    if (cpu.flags.zf)
    {
        goto L_0x00476b83;
    }
    // 00476a28  803dcc2e510000         +cmp byte ptr [0x512ecc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320396) /* 0x512ecc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476a2f  0f854e010000           -jne 0x476b83
    if (!cpu.flags.zf)
    {
        goto L_0x00476b83;
    }
    // 00476a35  833d085a4d0001         +cmp dword ptr [0x4d5a08], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069320) /* 0x4d5a08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476a3c  7508                   -jne 0x476a46
    if (!cpu.flags.zf)
    {
        goto L_0x00476a46;
    }
    // 00476a3e  83f909                 +cmp ecx, 9
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
    // 00476a41  7d03                   -jge 0x476a46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476a46;
    }
    // 00476a43  83c109                 -add ecx, 9
    (cpu.ecx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00476a46:
    // 00476a46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476a47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476a48  bd34e44c00             -mov ebp, 0x4ce434
    cpu.ebp = 5039156 /*0x4ce434*/;
    // 00476a4d  b85a010000             -mov eax, 0x15a
    cpu.eax = 346 /*0x15a*/;
    // 00476a52  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00476a54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476a56  a3dcb14d00             -mov dword ptr [0x4db1dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.eax;
    // 00476a5b  b850e44c00             -mov eax, 0x4ce450
    cpu.eax = 5039184 /*0x4ce450*/;
    // 00476a60  892dd8b14d00           -mov dword ptr [0x4db1d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebp;
    // 00476a66  e82dda0000             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00476a6b  8b148d08974d00         -mov edx, dword ptr [ecx*4 + 0x4d9708]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084936) /* 0x4d9708 */ + cpu.ecx * 4);
    // 00476a72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476a73  8b0da0345100           -mov ecx, dword ptr [0x5134a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5321888) /* 0x5134a0 */);
    // 00476a79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476a7a  6858e44c00             -push 0x4ce458
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039192 /*0x4ce458*/;
    cpu.esp -= 4;
    // 00476a7f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476a81  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476a85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476a86  e876fa0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476a8b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476a8e  8b1d84345100           -mov ebx, dword ptr [0x513484]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5321860) /* 0x513484 */);
    // 00476a94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476a95  680ce44c00             -push 0x4ce40c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039116 /*0x4ce40c*/;
    cpu.esp -= 4;
    // 00476a9a  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00476aa1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476aa2  e85afa0000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476aa7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476aaa  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476aae  e8cd780200             -call 0x49e380
    cpu.esp -= 4;
    sub_49e380(app, cpu);
    if (cpu.terminate) return;
    // 00476ab3  89842420010000         -mov dword ptr [esp + 0x120], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.eax;
    // 00476aba  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00476ac1  e8aa1a0100             -call 0x488570
    cpu.esp -= 4;
    sub_488570(app, cpu);
    if (cpu.terminate) return;
    // 00476ac6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476ac8  0f85c0000000           -jne 0x476b8e
    if (!cpu.flags.zf)
    {
        goto L_0x00476b8e;
    }
L_0x00476ace:
    // 00476ace  8d8c2418010000         -lea ecx, [esp + 0x118]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 00476ad5  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00476adc  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00476ae3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476ae7  e8c80c0100             -call 0x4877b4
    cpu.esp -= 4;
    sub_4877b4(app, cpu);
    if (cpu.terminate) return;
    // 00476aec  8d8c241c010000         -lea ecx, [esp + 0x11c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00476af3  8d9c240c010000         -lea ebx, [esp + 0x10c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00476afa  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00476b01  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00476b08  e8b70c0100             -call 0x4877c4
    cpu.esp -= 4;
    sub_4877c4(app, cpu);
    if (cpu.terminate) return;
L_0x00476b0d:
    // 00476b0d  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00476b14  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00476b16  39f0                   +cmp eax, esi
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
    // 00476b18  7d0d                   -jge 0x476b27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476b27;
    }
    // 00476b1a  c784242401000001000000 -mov dword ptr [esp + 0x124], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = 1 /*0x1*/;
    // 00476b25  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00476b27:
    // 00476b27  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00476b2e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00476b30  e8330e0100             -call 0x487968
    cpu.esp -= 4;
    sub_487968(app, cpu);
    if (cpu.terminate) return;
    // 00476b35  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00476b37  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00476b3e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00476b40  e8130e0100             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00476b45  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00476b4c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00476b4e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00476b50  e80b0e0100             -call 0x487960
    cpu.esp -= 4;
    sub_487960(app, cpu);
    if (cpu.terminate) return;
    // 00476b55  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 00476b5c  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00476b5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476b60  74ab                   -je 0x476b0d
    if (cpu.flags.zf)
    {
        goto L_0x00476b0d;
    }
    // 00476b62  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00476b69  e8e20d0100             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 00476b6e  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00476b75  e8d60d0100             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 00476b7a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476b7c  e87bdd0000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00476b81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00476b83:
    // 00476b83  81c420010000           +add esp, 0x120
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476b89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476b8e:
    // 00476b8e  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00476b90  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00476b97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476b98  2eff158c654c00         -call dword ptr cs:[0x4c658c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006732) /* 0x4c658c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476b9f  e92affffff             -jmp 0x476ace
    goto L_0x00476ace;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476bb0);
    // 00476bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476bb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476bb4  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00476bba  8b1584345100           -mov edx, dword ptr [0x513484]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321860) /* 0x513484 */);
    // 00476bc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476bc1  680ce44c00             -push 0x4ce40c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039116 /*0x4ce40c*/;
    cpu.esp -= 4;
    // 00476bc6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476bca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476bcb  e831f90000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476bd0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476bd3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476bd5  be0000f000             -mov esi, 0xf00000
    cpu.esi = 15728640 /*0xf00000*/;
    // 00476bda  e891190100             -call 0x488570
    cpu.esp -= 4;
    sub_488570(app, cpu);
    if (cpu.terminate) return;
    // 00476bdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476be1  7545                   -jne 0x476c28
    if (!cpu.flags.zf)
    {
        goto L_0x00476c28;
    }
L_0x00476be3:
    // 00476be3  8d8c2484000000         -lea ecx, [esp + 0x84]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00476bea  8d9c2488000000         -lea ebx, [esp + 0x88]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00476bf1  8d942480000000         -lea edx, [esp + 0x80]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00476bf8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476bfa  e8c50b0100             -call 0x4877c4
    cpu.esp -= 4;
    sub_4877c4(app, cpu);
    if (cpu.terminate) return;
    // 00476bff  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00476c06  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00476c08  e8e32dfeff             -call 0x4599f0
    cpu.esp -= 4;
    sub_4599f0(app, cpu);
    if (cpu.terminate) return;
    // 00476c0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476c0f  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00476c16  e8350d0100             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 00476c1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476c1d  81c48c000000           +add esp, 0x8c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476c28:
    // 00476c28  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00476c2a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476c2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476c2f  2eff158c654c00         -call dword ptr cs:[0x4c658c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006732) /* 0x4c658c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476c36  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476c38  e8710d0100             -call 0x4879ae
    cpu.esp -= 4;
    sub_4879ae(app, cpu);
    if (cpu.terminate) return;
    // 00476c3d  eba4                   -jmp 0x476be3
    goto L_0x00476be3;
}

/* align: skip 0x00 */
void Application::sub_476c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476c40);
    // 00476c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476c41  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00476c47  8b1584345100           -mov edx, dword ptr [0x513484]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321860) /* 0x513484 */);
    // 00476c4d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476c4e  680ce44c00             -push 0x4ce40c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039116 /*0x4ce40c*/;
    cpu.esp -= 4;
    // 00476c53  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476c57  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476c58  e8a4f80000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00476c5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476c60  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00476c62  e809190100             -call 0x488570
    cpu.esp -= 4;
    sub_488570(app, cpu);
    if (cpu.terminate) return;
    // 00476c67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476c69  7508                   -jne 0x476c73
    if (!cpu.flags.zf)
    {
        goto L_0x00476c73;
    }
    // 00476c6b  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00476c71  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476c73:
    // 00476c73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476c74  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00476c76  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476c7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476c7b  2eff158c654c00         -call dword ptr cs:[0x4c658c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006732) /* 0x4c658c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476c82  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476c86  e8230d0100             -call 0x4879ae
    cpu.esp -= 4;
    sub_4879ae(app, cpu);
    if (cpu.terminate) return;
    // 00476c8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c8c  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00476c92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476ca0);
    // 00476ca0  833d1c5a4d0000         +cmp dword ptr [0x4d5a1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069340) /* 0x4d5a1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476ca7  0f85a3900200           -jne 0x49fd50
    if (!cpu.flags.zf)
    {
        return sub_49fd50(app, cpu);
    }
    // 00476cad  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476cb4  0f8596900200           -jne 0x49fd50
    if (!cpu.flags.zf)
    {
        return sub_49fd50(app, cpu);
    }
    // 00476cba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476cc0);
    // 00476cc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476cc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476cc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476cc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476cc4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00476cc6  8b3d1c5a4d00           -mov edi, dword ptr [0x4d5a1c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5069340) /* 0x4d5a1c */);
    // 00476ccc  8935b0964d00           -mov dword ptr [0x4d96b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */) = cpu.esi;
    // 00476cd2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00476cd4  7445                   -je 0x476d1b
    if (cpu.flags.zf)
    {
        goto L_0x00476d1b;
    }
L_0x00476cd6:
    // 00476cd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476cd8  7558                   -jne 0x476d32
    if (!cpu.flags.zf)
    {
        goto L_0x00476d32;
    }
    // 00476cda  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476cdc  7554                   -jne 0x476d32
    if (!cpu.flags.zf)
    {
        goto L_0x00476d32;
    }
    // 00476cde  81e308080000           -and ebx, 0x808
    cpu.ebx &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 00476ce4  81fb08080000           +cmp ebx, 0x808
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476cea  743d                   -je 0x476d29
    if (cpu.flags.zf)
    {
        goto L_0x00476d29;
    }
L_0x00476cec:
    // 00476cec  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476cf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00476cf3:
    // 00476cf3  e808900200             -call 0x49fd00
    cpu.esp -= 4;
    sub_49fd00(app, cpu);
    if (cpu.terminate) return;
    // 00476cf8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00476cfa:
    // 00476cfa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476cfc  0f8d9b000000           -jge 0x476d9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476d9d;
    }
    // 00476d02  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00476d04  890d205a4d00           -mov dword ptr [0x4d5a20], ecx
    app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */) = cpu.ecx;
    // 00476d0a  890d3c5a4d00           -mov dword ptr [0x4d5a3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5069372) /* 0x4d5a3c */) = cpu.ecx;
    // 00476d10  890d1c5a4d00           -mov dword ptr [0x4d5a1c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5069340) /* 0x4d5a1c */) = cpu.ecx;
    // 00476d16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476d1b:
    // 00476d1b  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476d22  75b2                   -jne 0x476cd6
    if (!cpu.flags.zf)
    {
        goto L_0x00476cd6;
    }
    // 00476d24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d27  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476d29:
    // 00476d29  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476d2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476d30  ebc1                   -jmp 0x476cf3
    goto L_0x00476cf3;
L_0x00476d32:
    // 00476d32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476d34  751c                   -jne 0x476d52
    if (!cpu.flags.zf)
    {
        goto L_0x00476d52;
    }
    // 00476d36  83fa01                 +cmp edx, 1
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
    // 00476d39  7517                   -jne 0x476d52
    if (!cpu.flags.zf)
    {
        goto L_0x00476d52;
    }
    // 00476d3b  81e304080000           -and ebx, 0x804
    cpu.ebx &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 00476d41  81fb04080000           +cmp ebx, 0x804
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476d47  75a3                   -jne 0x476cec
    if (!cpu.flags.zf)
    {
        goto L_0x00476cec;
    }
    // 00476d49  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476d4e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476d50  eba1                   -jmp 0x476cf3
    goto L_0x00476cf3;
L_0x00476d52:
    // 00476d52  83f801                 +cmp eax, 1
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
    // 00476d55  751b                   -jne 0x476d72
    if (!cpu.flags.zf)
    {
        goto L_0x00476d72;
    }
    // 00476d57  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476d59  7517                   -jne 0x476d72
    if (!cpu.flags.zf)
    {
        goto L_0x00476d72;
    }
    // 00476d5b  81e302080000           -and ebx, 0x802
    cpu.ebx &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00476d61  81fb02080000           +cmp ebx, 0x802
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476d67  7583                   -jne 0x476cec
    if (!cpu.flags.zf)
    {
        goto L_0x00476cec;
    }
    // 00476d69  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476d6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476d70  eb81                   -jmp 0x476cf3
    goto L_0x00476cf3;
L_0x00476d72:
    // 00476d72  83f801                 +cmp eax, 1
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
    // 00476d75  7583                   -jne 0x476cfa
    if (!cpu.flags.zf)
    {
        goto L_0x00476cfa;
    }
    // 00476d77  39c2                   +cmp edx, eax
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
    // 00476d79  0f857bffffff           -jne 0x476cfa
    if (!cpu.flags.zf)
    {
        goto L_0x00476cfa;
    }
    // 00476d7f  81e301080000           -and ebx, 0x801
    cpu.ebx &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00476d85  81fb01080000           +cmp ebx, 0x801
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476d8b  0f855bffffff           -jne 0x476cec
    if (!cpu.flags.zf)
    {
        goto L_0x00476cec;
    }
    // 00476d91  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476d96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476d98  e956ffffff             -jmp 0x476cf3
    goto L_0x00476cf3;
L_0x00476d9d:
    // 00476d9d  e88eb3fcff             -call 0x442130
    cpu.esp -= 4;
    sub_442130(app, cpu);
    if (cpu.terminate) return;
    // 00476da2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00476da7  e8901a0100             -call 0x48883c
    cpu.esp -= 4;
    sub_48883c(app, cpu);
    if (cpu.terminate) return;
    // 00476dac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476dae  a3b4964d00             -mov dword ptr [0x4d96b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5084852) /* 0x4d96b4 */) = cpu.eax;
    // 00476db3  a3b0964d00             -mov dword ptr [0x4d96b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */) = cpu.eax;
    // 00476db8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476db9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476dba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476dbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476dbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_476dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476dc0);
    // 00476dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476dc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476dc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476dc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476dc5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476dc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00476dc9:
    // 00476dc9  898210b45000           -mov dword ptr [edx + 0x50b410], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5288976) /* 0x50b410 */) = cpu.eax;
    // 00476dcf  40                     -inc eax
    (cpu.eax)++;
    // 00476dd0  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00476dd3  83f809                 +cmp eax, 9
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
    // 00476dd6  7cf1                   -jl 0x476dc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476dc9;
    }
    // 00476dd8  0fb63d3e2f5100         -movzx edi, byte ptr [0x512f3e]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5320510) /* 0x512f3e */));
    // 00476ddf  8b351c5a4d00           -mov esi, dword ptr [0x4d5a1c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5069340) /* 0x4d5a1c */);
    // 00476de5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476de7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476de9  8a1dff2d5100           -mov bl, byte ptr [0x512dff]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5320191) /* 0x512dff */);
    // 00476def  8915b0964d00           -mov dword ptr [0x4d96b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */) = cpu.edx;
    // 00476df5  8a15412f5100           -mov dl, byte ptr [0x512f41]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5320513) /* 0x512f41 */);
    // 00476dfb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00476dfd  7509                   -jne 0x476e08
    if (!cpu.flags.zf)
    {
        goto L_0x00476e08;
    }
    // 00476dff  833d205a4d0000         +cmp dword ptr [0x4d5a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476e06  7458                   -je 0x476e60
    if (cpu.flags.zf)
    {
        goto L_0x00476e60;
    }
L_0x00476e08:
    // 00476e08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00476e0d  e82a1a0100             -call 0x48883c
    cpu.esp -= 4;
    sub_48883c(app, cpu);
    if (cpu.terminate) return;
    // 00476e12  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476e14  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476e16  7557                   -jne 0x476e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00476e6f;
    }
    // 00476e18  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476e1a  7553                   -jne 0x476e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00476e6f;
    }
    // 00476e1c  81e608080000           -and esi, 0x808
    cpu.esi &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 00476e22  81fe08080000           +cmp esi, 0x808
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476e28  743c                   -je 0x476e66
    if (cpu.flags.zf)
    {
        goto L_0x00476e66;
    }
L_0x00476e2a:
    // 00476e2a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476e2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00476e31:
    // 00476e31  e8ca8e0200             -call 0x49fd00
    cpu.esp -= 4;
    sub_49fd00(app, cpu);
    if (cpu.terminate) return;
    // 00476e36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00476e38:
    // 00476e38  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476e3a  0f8c8a000000           -jl 0x476eca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476eca;
    }
    // 00476e40  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00476e42  0f849c000000           -je 0x476ee4
    if (cpu.flags.zf)
    {
        goto L_0x00476ee4;
    }
    // 00476e48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00476e4a:
    // 00476e4a  e8491a0100             -call 0x488898
    cpu.esp -= 4;
    sub_488898(app, cpu);
    if (cpu.terminate) return;
    // 00476e4f  e8dcb2fcff             -call 0x442130
    cpu.esp -= 4;
    sub_442130(app, cpu);
    if (cpu.terminate) return;
    // 00476e54  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00476e56  a3b4964d00             -mov dword ptr [0x4d96b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5084852) /* 0x4d96b4 */) = cpu.eax;
    // 00476e5b  a3b0964d00             -mov dword ptr [0x4d96b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */) = cpu.eax;
L_0x00476e60:
    // 00476e60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476e65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476e66:
    // 00476e66  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476e6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476e6d  ebc2                   -jmp 0x476e31
    goto L_0x00476e31;
L_0x00476e6f:
    // 00476e6f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476e71  7518                   -jne 0x476e8b
    if (!cpu.flags.zf)
    {
        goto L_0x00476e8b;
    }
    // 00476e73  83fb01                 +cmp ebx, 1
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
    // 00476e76  7513                   -jne 0x476e8b
    if (!cpu.flags.zf)
    {
        goto L_0x00476e8b;
    }
    // 00476e78  2504080000             -and eax, 0x804
    cpu.eax &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 00476e7d  3d04080000             +cmp eax, 0x804
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476e82  75a6                   -jne 0x476e2a
    if (!cpu.flags.zf)
    {
        goto L_0x00476e2a;
    }
    // 00476e84  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476e89  eba6                   -jmp 0x476e31
    goto L_0x00476e31;
L_0x00476e8b:
    // 00476e8b  83fa01                 +cmp edx, 1
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
    // 00476e8e  7517                   -jne 0x476ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00476ea7;
    }
    // 00476e90  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476e92  7513                   -jne 0x476ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00476ea7;
    }
    // 00476e94  2502080000             -and eax, 0x802
    cpu.eax &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00476e99  3d02080000             +cmp eax, 0x802
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476e9e  758a                   -jne 0x476e2a
    if (!cpu.flags.zf)
    {
        goto L_0x00476e2a;
    }
    // 00476ea0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476ea5  eb8a                   -jmp 0x476e31
    goto L_0x00476e31;
L_0x00476ea7:
    // 00476ea7  83fa01                 +cmp edx, 1
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
    // 00476eaa  758c                   -jne 0x476e38
    if (!cpu.flags.zf)
    {
        goto L_0x00476e38;
    }
    // 00476eac  39d3                   +cmp ebx, edx
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
    // 00476eae  7588                   -jne 0x476e38
    if (!cpu.flags.zf)
    {
        goto L_0x00476e38;
    }
    // 00476eb0  2501080000             -and eax, 0x801
    cpu.eax &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00476eb5  3d01080000             +cmp eax, 0x801
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476eba  0f856affffff           -jne 0x476e2a
    if (!cpu.flags.zf)
    {
        goto L_0x00476e2a;
    }
    // 00476ec0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00476ec5  e967ffffff             -jmp 0x476e31
    goto L_0x00476e31;
L_0x00476eca:
    // 00476eca  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00476ecc  890d205a4d00           -mov dword ptr [0x4d5a20], ecx
    app->getMemory<x86::reg32>(x86::reg32(5069344) /* 0x4d5a20 */) = cpu.ecx;
    // 00476ed2  890d3c5a4d00           -mov dword ptr [0x4d5a3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5069372) /* 0x4d5a3c */) = cpu.ecx;
    // 00476ed8  890d1c5a4d00           -mov dword ptr [0x4d5a1c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5069340) /* 0x4d5a1c */) = cpu.ecx;
    // 00476ede  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476edf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ee0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ee1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ee2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ee3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476ee4:
    // 00476ee4  b8ceffffff             -mov eax, 0xffffffce
    cpu.eax = 4294967246 /*0xffffffce*/;
    // 00476ee9  e95cffffff             -jmp 0x476e4a
    goto L_0x00476e4a;
}

/* align: skip 0x00 0x00 */
void Application::sub_476ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476ef0);
    // 00476ef0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476ef1  8b15ac974d00           -mov edx, dword ptr [0x4d97ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */);
    // 00476ef7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476ef9  7502                   -jne 0x476efd
    if (!cpu.flags.zf)
    {
        goto L_0x00476efd;
    }
    // 00476efb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476efc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476efd:
    // 00476efd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476efe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476f00  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00476f02  e8f5d90000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00476f07  890dac974d00           -mov dword ptr [0x4d97ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */) = cpu.ecx;
    // 00476f0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476f10);
    // 00476f10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476f11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476f12  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476f14  8b0dac974d00           -mov ecx, dword ptr [0x4d97ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */);
    // 00476f1a  8915b0974d00           -mov dword ptr [0x4d97b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */) = cpu.edx;
    // 00476f20  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476f22  7403                   -je 0x476f27
    if (cpu.flags.zf)
    {
        goto L_0x00476f27;
    }
    // 00476f24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476f27:
    // 00476f27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476f28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476f29  bb50e54c00             -mov ebx, 0x4ce550
    cpu.ebx = 5039440 /*0x4ce550*/;
    // 00476f2e  beec020000             -mov esi, 0x2ec
    cpu.esi = 748 /*0x2ec*/;
    // 00476f33  ba20480100             -mov edx, 0x14820
    cpu.edx = 84000 /*0x14820*/;
    // 00476f38  b86ce54c00             -mov eax, 0x4ce56c
    cpu.eax = 5039468 /*0x4ce56c*/;
    // 00476f3d  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 00476f43  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476f45  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 00476f4b  e860d50000             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 00476f50  a3ac974d00             -mov dword ptr [0x4d97ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */) = cpu.eax;
    // 00476f55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00476f60);
    // 00476f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476f62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476f63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476f64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476f65  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00476f68  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 00476f6c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476f6e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00476f70  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00476f73  8b0485881b5100         -mov eax, dword ptr [eax*4 + 0x511b88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315464) /* 0x511b88 */ + cpu.eax * 4);
    // 00476f7a  898210060000           -mov dword ptr [edx + 0x610], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1552) /* 0x610 */) = cpu.eax;
    // 00476f80  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00476f84  898288000000           -mov dword ptr [edx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00476f8a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00476f8c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00476f8f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00476f96  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00476f98  8b9e1c020000           -mov ebx, dword ptr [esi + 0x21c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(540) /* 0x21c */);
    // 00476f9e  8b0485c8195100         -mov eax, dword ptr [eax*4 + 0x5119c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315016) /* 0x5119c8 */ + cpu.eax * 4);
    // 00476fa5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476fa7  898614060000           -mov dword ptr [esi + 0x614], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00476fad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476faf  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00476fb2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00476fb4  e837040000             -call 0x4773f0
    cpu.esp -= 4;
    sub_4773f0(app, cpu);
    if (cpu.terminate) return;
    // 00476fb9  a1b0974d00             -mov eax, dword ptr [0x4d97b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */);
    // 00476fbe  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00476fc2  898618060000           -mov dword ptr [esi + 0x618], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00476fc8  894c2450               -mov dword ptr [esp + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00476fcc  898284000000           -mov dword ptr [edx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00476fd2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00476fd7  89861c060000           -mov dword ptr [esi + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 00476fdd  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00476fe1  8915b8974d00           -mov dword ptr [0x4d97b8], edx
    app->getMemory<x86::reg32>(x86::reg32(5085112) /* 0x4d97b8 */) = cpu.edx;
    // 00476fe7  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
L_0x00476feb:
    // 00476feb  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00476fef  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00476ff2  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00476ff6  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00476ff9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00476ffc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476ffe  7533                   -jne 0x477033
    if (!cpu.flags.zf)
    {
        goto L_0x00477033;
    }
L_0x00477000:
    // 00477000  8b7c2450               -mov edi, dword ptr [esp + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00477004  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00477008  47                     -inc edi
    (cpu.edi)++;
    // 00477009  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047700c  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 00477010  895c2454               -mov dword ptr [esp + 0x54], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.ebx;
    // 00477014  83ff20                 +cmp edi, 0x20
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
    // 00477017  7cd2                   -jl 0x476feb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476feb;
    }
    // 00477019  e882800000             -call 0x47f0a0
    cpu.esp -= 4;
    sub_47f0a0(app, cpu);
    if (cpu.terminate) return;
    // 0047701e  a300a24d00             -mov dword ptr [0x4da200], eax
    app->getMemory<x86::reg32>(x86::reg32(5087744) /* 0x4da200 */) = cpu.eax;
    // 00477023  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477025  a3b8974d00             -mov dword ptr [0x4d97b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085112) /* 0x4d97b8 */) = cpu.eax;
    // 0047702a  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0047702d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047702e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047702f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477030  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477031  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477032  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477033:
    // 00477033  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00477037  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0047703b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047703d  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00477041  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00477043  897c244c               -mov dword ptr [esp + 0x4c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edi;
    // 00477047  897c2460               -mov dword ptr [esp + 0x60], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edi;
L_0x0047704b:
    // 0047704b  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0047704f  03442458               -add eax, dword ptr [esp + 0x58]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
    // 00477053  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00477056  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047705a  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047705d  7da1                   -jge 0x477000
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477000;
    }
    // 0047705f  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00477063  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00477066  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00477068  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047706a  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 0047706d  0f843b010000           -je 0x4771ae
    if (cpu.flags.zf)
    {
        goto L_0x004771ae;
    }
    // 00477073  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00477075  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047707a  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047707d  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
L_0x00477081:
    // 00477081  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477083  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00477087  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0047708b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047708d  0f8e02010000           -jle 0x477195
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477195;
    }
    // 00477093  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00477097  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00477099  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
L_0x0047709d:
    // 0047709d  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004770a0  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004770a3  8a440708               -mov al, byte ptr [edi + eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 004770a7  88442438               -mov byte ptr [esp + 0x38], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 004770ab  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004770ae  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004770b1  8a440709               -mov al, byte ptr [edi + eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */ + cpu.eax * 1);
    // 004770b5  88442439               -mov byte ptr [esp + 0x39], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 004770b9  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004770bc  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004770bf  8a44070a               -mov al, byte ptr [edi + eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */ + cpu.eax * 1);
    // 004770c3  8844243a               -mov byte ptr [esp + 0x3a], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(58) /* 0x3a */) = cpu.al;
    // 004770c7  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004770ca  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004770cd  8a44070b               -mov al, byte ptr [edi + eax + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */ + cpu.eax * 1);
    // 004770d1  8a5c2439               -mov bl, byte ptr [esp + 0x39]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(57) /* 0x39 */);
    // 004770d5  8844243b               -mov byte ptr [esp + 0x3b], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(59) /* 0x3b */) = cpu.al;
    // 004770d9  8a442448               -mov al, byte ptr [esp + 0x48]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004770dd  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004770df  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 004770e1  8874243c               -mov byte ptr [esp + 0x3c], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.dh;
    // 004770e5  885c2439               -mov byte ptr [esp + 0x39], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(57) /* 0x39 */) = cpu.bl;
    // 004770e9  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004770ec  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004770ef  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004770f1  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004770f3  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004770f6  0f84ec000000           -je 0x4771e8
    if (cpu.flags.zf)
    {
        goto L_0x004771e8;
    }
    // 004770fc  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004770ff  0f84b6000000           -je 0x4771bb
    if (cpu.flags.zf)
    {
        goto L_0x004771bb;
    }
    // 00477105  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00477107  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047710b  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00477111  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00477117  e8a4e1fbff             -call 0x4352c0
    cpu.esp -= 4;
    sub_4352c0(app, cpu);
    if (cpu.terminate) return;
    // 0047711c  6b1db0974d001c         -imul ebx, dword ptr [0x4d97b0], 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00477123  a1ac974d00             -mov eax, dword ptr [0x4d97ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */);
    // 00477128  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x0047712d:
    // 0047712d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047712f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00477131:
    // 00477131  e8cedffbff             -call 0x435104
    cpu.esp -= 4;
    sub_435104(app, cpu);
    if (cpu.terminate) return;
    // 00477136  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0047713a  66a1b0974d00           -mov ax, word ptr [0x4d97b0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5085104) /* 0x4d97b0 */);
    // 00477140  668b9a84000000         -mov bx, word ptr [edx + 0x84]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 00477147  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477149  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0047714d  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00477151  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477153  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00477156  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477158  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047715c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047715f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00477161  66895002               -mov word ptr [eax + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00477165  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00477169  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047716c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047716f  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00477173  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00477175  42                     -inc edx
    (cpu.edx)++;
    // 00477176  c6400100               -mov byte ptr [eax + 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 0047717a  a1b0974d00             -mov eax, dword ptr [0x4d97b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */);
    // 0047717f  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00477183  40                     -inc eax
    (cpu.eax)++;
    // 00477184  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00477188  a3b0974d00             -mov dword ptr [0x4d97b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */) = cpu.eax;
    // 0047718d  39ca                   +cmp edx, ecx
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
    // 0047718f  0f8c08ffffff           -jl 0x47709d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047709d;
    }
L_0x00477195:
    // 00477195  8b7c2460               -mov edi, dword ptr [esp + 0x60]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00477199  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047719d  47                     -inc edi
    (cpu.edi)++;
    // 0047719e  83c30c                 +add ebx, 0xc
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004771a1  897c2460               -mov dword ptr [esp + 0x60], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edi;
    // 004771a5  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004771a9  e99dfeffff             -jmp 0x47704b
    goto L_0x0047704b;
L_0x004771ae:
    // 004771ae  c744246401000000       -mov dword ptr [esp + 0x64], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1 /*0x1*/;
    // 004771b6  e9c6feffff             -jmp 0x477081
    goto L_0x00477081;
L_0x004771bb:
    // 004771bb  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004771bd  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004771c1  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 004771c7  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 004771cd  e8eee0fbff             -call 0x4352c0
    cpu.esp -= 4;
    sub_4352c0(app, cpu);
    if (cpu.terminate) return;
    // 004771d2  6b1db0974d001c         +imul ebx, dword ptr [0x4d97b0], 0x1c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 004771d9  a1ac974d00             -mov eax, dword ptr [0x4d97ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */);
    // 004771de  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004771e3  e945ffffff             -jmp 0x47712d
    goto L_0x0047712d;
L_0x004771e8:
    // 004771e8  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004771ea  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004771ee  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 004771f4  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 004771fa  e8c1e0fbff             -call 0x4352c0
    cpu.esp -= 4;
    sub_4352c0(app, cpu);
    if (cpu.terminate) return;
    // 004771ff  8d5c241c               -lea ebx, [esp + 0x1c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00477203  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00477208  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047720a  e8f5defbff             -call 0x435104
    cpu.esp -= 4;
    sub_435104(app, cpu);
    if (cpu.terminate) return;
    // 0047720f  6b1db0974d001c         -imul ebx, dword ptr [0x4d97b0], 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00477216  a1ac974d00             -mov eax, dword ptr [0x4d97ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */);
    // 0047721b  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00477220  01c3                   +add ebx, eax
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
    // 00477222  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00477226  e906ffffff             -jmp 0x477131
    goto L_0x00477131;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477230);
    // 00477230  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477231  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477232  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477233  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00477236  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047723a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047723e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477240  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00477242  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00477245  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047724c  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 00477253  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477255  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477259  8b8486c8195100         -mov eax, dword ptr [esi + eax*4 + 0x5119c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5315016) /* 0x5119c8 */ + cpu.eax * 4);
    // 00477260  898314060000           -mov dword ptr [ebx + 0x614], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00477266  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047726a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047726c  e87f010000             -call 0x4773f0
    cpu.esp -= 4;
    sub_4773f0(app, cpu);
    if (cpu.terminate) return;
    // 00477271  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477275  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00477277  a1b0974d00             -mov eax, dword ptr [0x4d97b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */);
    // 0047727c  89861c060000           -mov dword ptr [esi + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 00477282  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477284  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 0047728a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047728e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00477292  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00477296:
    // 00477296  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047729a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047729d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004772a1  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004772a4  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004772a7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004772a9  7534                   -jne 0x4772df
    if (!cpu.flags.zf)
    {
        goto L_0x004772df;
    }
L_0x004772ab:
    // 004772ab  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004772af  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004772b3  42                     -inc edx
    (cpu.edx)++;
    // 004772b4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004772b7  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004772bb  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004772bf  83fa20                 +cmp edx, 0x20
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
    // 004772c2  7cd2                   -jl 0x477296
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477296;
    }
    // 004772c4  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004772c8  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004772cc  8b801c060000           -mov eax, dword ptr [eax + 0x61c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1564) /* 0x61c */);
    // 004772d2  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 004772d8  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004772db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004772df:
    // 004772df  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004772e3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004772e5  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004772e9  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004772ec  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x004772f0:
    // 004772f0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004772f4  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004772f8  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004772fb  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004772ff  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477302  7da7                   -jge 0x4772ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004772ab;
    }
    // 00477304  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00477307  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047730a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047730c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047730e  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 00477311  0f84c5000000           -je 0x4773dc
    if (cpu.flags.zf)
    {
        goto L_0x004773dc;
    }
    // 00477317  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00477319  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047731e  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00477321  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00477325:
    // 00477325  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00477329  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047732b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047732d  0f8e92000000           -jle 0x4773c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004773c5;
    }
    // 00477333  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00477336  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0047733a:
    // 0047733a  6b15b0974d001c         -imul edx, dword ptr [0x4d97b0], 0x1c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00477341  a1ac974d00             -mov eax, dword ptr [0x4d97ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085100) /* 0x4d97ac */);
    // 00477346  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00477349  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047734d  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00477350  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477354  8b5b18                 -mov ebx, dword ptr [ebx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00477357  8b9214060000           -mov edx, dword ptr [edx + 0x614]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1556) /* 0x614 */);
    // 0047735d  668b5c1e02             -mov bx, word ptr [esi + ebx + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.ebx * 1);
    // 00477362  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00477368  039d84000000           -add ebx, dword ptr [ebp + 0x84]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(132) /* 0x84 */)));
    // 0047736e  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00477370  6bdb1c                 -imul ebx, ebx, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00477373  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00477375  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477379  e822dffbff             -call 0x4352a0
    cpu.esp -= 4;
    sub_4352a0(app, cpu);
    if (cpu.terminate) return;
    // 0047737e  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477382  66a1b0974d00           -mov ax, word ptr [0x4d97b0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5085104) /* 0x4d97b0 */);
    // 00477388  668b9a18060000         -mov bx, word ptr [edx + 0x618]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(1560) /* 0x618 */);
    // 0047738f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477391  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00477394  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477396  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00477399  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047739b  6689540602             -mov word ptr [esi + eax + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = cpu.dx;
    // 004773a0  8b15b0974d00           -mov edx, dword ptr [0x4d97b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */);
    // 004773a6  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004773a9  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004773ad  42                     -inc edx
    (cpu.edx)++;
    // 004773ae  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004773b1  41                     -inc ecx
    (cpu.ecx)++;
    // 004773b2  8915b0974d00           -mov dword ptr [0x4d97b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5085104) /* 0x4d97b0 */) = cpu.edx;
    // 004773b8  c644060100             -mov byte ptr [esi + eax + 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 004773bd  39d9                   +cmp ecx, ebx
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
    // 004773bf  0f8c75ffffff           -jl 0x47733a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047733a;
    }
L_0x004773c5:
    // 004773c5  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004773c9  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004773cc  45                     -inc ebp
    (cpu.ebp)++;
    // 004773cd  83c60c                 +add esi, 0xc
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
    // 004773d0  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004773d4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004773d7  e914ffffff             -jmp 0x4772f0
    goto L_0x004772f0;
L_0x004773dc:
    // 004773dc  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004773e4  e93cffffff             -jmp 0x477325
    goto L_0x00477325;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4773f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004773f0);
    // 004773f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004773f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004773f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004773f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004773f4  81ec10030000           -sub esp, 0x310
    (cpu.esp) -= x86::reg32(x86::sreg32(784 /*0x310*/));
    // 004773fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004773fc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004773fe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477400  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00477403  8b0485881b5100         -mov eax, dword ptr [eax*4 + 0x511b88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315464) /* 0x511b88 */ + cpu.eax * 4);
    // 0047740a  8b0db4974d00           -mov ecx, dword ptr [0x4d97b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085108) /* 0x4d97b4 */);
    // 00477410  898610060000           -mov dword ptr [esi + 0x610], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */) = cpu.eax;
    // 00477416  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477419  7c08                   -jl 0x477423
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477423;
    }
    // 0047741b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047741d  891db4974d00           -mov dword ptr [0x4d97b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085108) /* 0x4d97b4 */) = cpu.ebx;
L_0x00477423:
    // 00477423  8b2db4974d00           -mov ebp, dword ptr [0x4d97b4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5085108) /* 0x4d97b4 */);
    // 00477429  a1b4974d00             -mov eax, dword ptr [0x4d97b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085108) /* 0x4d97b4 */);
    // 0047742e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00477430  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00477433  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00477435  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00477438  898614060000           -mov dword ptr [esi + 0x614], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 0047743e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00477445  81c544595400           -add ebp, 0x545944
    (cpu.ebp) += x86::reg32(x86::sreg32(5527876 /*0x545944*/));
    // 0047744b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047744d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00477450  892d00a24d00           -mov dword ptr [0x4da200], ebp
    app->getMemory<x86::reg32>(x86::reg32(5087744) /* 0x4da200 */) = cpu.ebp;
    // 00477456  899c82c8195100         -mov dword ptr [edx + eax*4 + 0x5119c8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315016) /* 0x5119c8 */ + cpu.eax * 4) = cpu.ebx;
    // 0047745d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047745f  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 00477464  42                     -inc edx
    (cpu.edx)++;
    // 00477465  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 0047746b  8915b4974d00           -mov dword ptr [0x4d97b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5085108) /* 0x4d97b4 */) = cpu.edx;
    // 00477471  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00477473  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00477475  e8467d0000             -call 0x47f1c0
    cpu.esp -= 4;
    sub_47f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0047747a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047747f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00477481  e8aa0ffeff             -call 0x458430
    cpu.esp -= 4;
    sub_458430(app, cpu);
    if (cpu.terminate) return;
    // 00477486  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0047748d  8d8c240c030000         -lea ecx, [esp + 0x30c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00477494  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477495  8b861c020000           -mov eax, dword ptr [esi + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(540) /* 0x21c */);
    // 0047749b  8d9c240c030000         -lea ebx, [esp + 0x30c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 004774a2  8d942408030000         -lea edx, [esp + 0x308]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 004774a9  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004774ac  e8bf11feff             -call 0x458670
    cpu.esp -= 4;
    sub_458670(app, cpu);
    if (cpu.terminate) return;
    // 004774b1  8b8c2404030000         -mov ecx, dword ptr [esp + 0x304]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004774b8  8b2d00a24d00           -mov ebp, dword ptr [0x4da200]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5087744) /* 0x4da200 */);
    // 004774be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004774c0  0f8496000000           -je 0x47755c
    if (cpu.flags.zf)
    {
        goto L_0x0047755c;
    }
L_0x004774c6:
    // 004774c6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004774c8  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
L_0x004774ca:
    // 004774ca  8a3c34                 -mov bh, byte ptr [esp + esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1);
    // 004774cd  38f8                   +cmp al, bh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004774cf  7507                   -jne 0x4774d8
    if (!cpu.flags.zf)
    {
        goto L_0x004774d8;
    }
    // 004774d1  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 004774d3  fec1                   -inc cl
    (cpu.cl)++;
    // 004774d5  880c34                 -mov byte ptr [esp + esi], cl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.cl;
L_0x004774d8:
    // 004774d8  8a6c3401               -mov ch, byte ptr [esp + esi + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1);
    // 004774dc  38e8                   +cmp al, ch
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004774de  7508                   -jne 0x4774e8
    if (!cpu.flags.zf)
    {
        goto L_0x004774e8;
    }
    // 004774e0  88ec                   -mov ah, ch
    cpu.ah = cpu.ch;
    // 004774e2  fec4                   -inc ah
    (cpu.ah)++;
    // 004774e4  88643401               -mov byte ptr [esp + esi + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1) = cpu.ah;
L_0x004774e8:
    // 004774e8  8a543402               -mov dl, byte ptr [esp + esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1);
    // 004774ec  38d0                   +cmp al, dl
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
    // 004774ee  7508                   -jne 0x4774f8
    if (!cpu.flags.zf)
    {
        goto L_0x004774f8;
    }
    // 004774f0  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004774f2  fec6                   -inc dh
    (cpu.dh)++;
    // 004774f4  88743402               -mov byte ptr [esp + esi + 2], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.dh;
L_0x004774f8:
    // 004774f8  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004774fb  81fefd020000           +cmp esi, 0x2fd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(765 /*0x2fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477501  7cc7                   -jl 0x4774ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004774ca;
    }
L_0x00477503:
    // 00477503  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00477505  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00477508  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0047750a  885c3401               -mov byte ptr [esp + esi + 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1) = cpu.bl;
    // 0047750e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00477510  885c3402               -mov byte ptr [esp + esi + 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.bl;
    // 00477514  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00477516:
    // 00477516  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00477518  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0047751f  c6440203ff             -mov byte ptr [edx + eax + 3], 0xff
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */ + cpu.eax * 1) = 255 /*0xff*/;
    // 00477524  8d1476                 -lea edx, [esi + esi*2]
    cpu.edx = x86::reg32(cpu.esi + cpu.esi * 2);
L_0x00477527:
    // 00477527  8d0c28                 -lea ecx, [eax + ebp]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0047752a  8a1c14                 -mov bl, byte ptr [esp + edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 0047752d  885902                 -mov byte ptr [ecx + 2], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00477530  8a5c1401               -mov bl, byte ptr [esp + edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 00477534  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00477537  885901                 -mov byte ptr [ecx + 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0047753a  46                     -inc esi
    (cpu.esi)++;
    // 0047753b  8a5c14ff               -mov bl, byte ptr [esp + edx - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1);
    // 0047753f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477542  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 00477544  3d00040000             +cmp eax, 0x400
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
    // 00477549  0f8d69000000           -jge 0x4775b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004775b8;
    }
    // 0047754f  3dfc030000             +cmp eax, 0x3fc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1020 /*0x3fc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477554  75c0                   -jne 0x477516
    if (!cpu.flags.zf)
    {
        goto L_0x00477516;
    }
    // 00477556  887c0703               -mov byte ptr [edi + eax + 3], bh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */ + cpu.eax * 1) = cpu.bh;
    // 0047755a  ebcb                   -jmp 0x477527
    goto L_0x00477527;
L_0x0047755c:
    // 0047755c  83bc240803000000       +cmp dword ptr [esp + 0x308], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477564  0f855cffffff           -jne 0x4774c6
    if (!cpu.flags.zf)
    {
        goto L_0x004774c6;
    }
    // 0047756a  8bb4240c030000         -mov esi, dword ptr [esp + 0x30c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00477571  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477573  0f854dffffff           -jne 0x4774c6
    if (!cpu.flags.zf)
    {
        goto L_0x004774c6;
    }
    // 00477579  83bc240003000000       +cmp dword ptr [esp + 0x300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477581  0f853fffffff           -jne 0x4774c6
    if (!cpu.flags.zf)
    {
        goto L_0x004774c6;
    }
    // 00477587  b050                   -mov al, 0x50
    cpu.al = 80 /*0x50*/;
    // 00477589  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
L_0x0047758b:
    // 0047758b  3a0434                 +cmp al, byte ptr [esp + esi]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047758e  7603                   -jbe 0x477593
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00477593;
    }
    // 00477590  882434                 -mov byte ptr [esp + esi], ah
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.ah;
L_0x00477593:
    // 00477593  3a443401               +cmp al, byte ptr [esp + esi + 1]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477597  7604                   -jbe 0x47759d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047759d;
    }
    // 00477599  88643401               -mov byte ptr [esp + esi + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1) = cpu.ah;
L_0x0047759d:
    // 0047759d  3a443402               +cmp al, byte ptr [esp + esi + 2]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004775a1  7604                   -jbe 0x4775a7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004775a7;
    }
    // 004775a3  88643402               -mov byte ptr [esp + esi + 2], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.ah;
L_0x004775a7:
    // 004775a7  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004775aa  81fefd020000           +cmp esi, 0x2fd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(765 /*0x2fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004775b0  0f8d4dffffff           -jge 0x477503
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477503;
    }
    // 004775b6  ebd3                   -jmp 0x47758b
    goto L_0x0047758b;
L_0x004775b8:
    // 004775b8  892d00a24d00           -mov dword ptr [0x4da200], ebp
    app->getMemory<x86::reg32>(x86::reg32(5087744) /* 0x4da200 */) = cpu.ebp;
    // 004775be  81c410030000           -add esp, 0x310
    (cpu.esp) += x86::reg32(x86::sreg32(784 /*0x310*/));
    // 004775c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004775c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: ffffffff0000000000000000ffffffff010000000000000000000000010000000000000000000000ffffffff0000000000000000ffffffff010000000000000000000000010000000000000000000000 */
void Application::sub_477620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477620);
    // 00477620  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477622  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477625  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00477627  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00477629  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047762b  e82088ffff             -call 0x46fe50
    cpu.esp -= 4;
    sub_46fe50(app, cpu);
    if (cpu.terminate) return;
    // 00477630  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00477632  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00477633  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00477634  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477636  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477639  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047763a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047763b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_477640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477640);
    // 00477640  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477641  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477642  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477645  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00477647  8a2518755500           -mov ah, byte ptr [0x557518]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5600536) /* 0x557518 */);
    // 0047764d  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047764f  754b                   -jne 0x47769c
    if (!cpu.flags.zf)
    {
        goto L_0x0047769c;
    }
    // 00477651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477652  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477653  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00477658  be0c755500             -mov esi, 0x55750c
    cpu.esi = 5600524 /*0x55750c*/;
    // 0047765d  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477661  a214755500             -mov byte ptr [0x557514], al
    app->getMemory<x86::reg8>(x86::reg32(5600532) /* 0x557514 */) = cpu.al;
    // 00477666  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477668  891d10755500           -mov dword ptr [0x557510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5600528) /* 0x557510 */) = cpu.ebx;
    // 0047766e  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00477672  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00477676  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047767a  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 0047767c  890d0c755500           -mov dword ptr [0x55750c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5600524) /* 0x55750c */) = cpu.ecx;
    // 00477682  fec3                   -inc bl
    (cpu.bl)++;
    // 00477684  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00477685  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00477686  881d18755500           -mov byte ptr [0x557518], bl
    app->getMemory<x86::reg8>(x86::reg32(5600536) /* 0x557518 */) = cpu.bl;
    // 0047768c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047768d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047768e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00477690  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00477692  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00477693  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00477694  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477696  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477699  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047769a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047769b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047769c:
    // 0047769c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047769e  e8ad87ffff             -call 0x46fe50
    cpu.esp -= 4;
    sub_46fe50(app, cpu);
    if (cpu.terminate) return;
    // 004776a3  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004776a5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004776a7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004776a8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004776a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004776ab  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004776ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4776c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004776c0);
    // 004776c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004776c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004776c3  e8d83bfdff             -call 0x44b2a0
    cpu.esp -= 4;
    sub_44b2a0(app, cpu);
    if (cpu.terminate) return;
    // 004776c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004776ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004776cc  e88f3ffdff             -call 0x44b660
    cpu.esp -= 4;
    sub_44b660(app, cpu);
    if (cpu.terminate) return;
    // 004776d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004776d3  7517                   -jne 0x4776ec
    if (!cpu.flags.zf)
    {
        goto L_0x004776ec;
    }
    // 004776d5  80bade02000000         +cmp byte ptr [edx + 0x2de], 0
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
    // 004776dc  750e                   -jne 0x4776ec
    if (!cpu.flags.zf)
    {
        goto L_0x004776ec;
    }
    // 004776de  a15c205100             -mov eax, dword ptr [0x51205c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316700) /* 0x51205c */);
    // 004776e3  8b04856c984d00         -mov eax, dword ptr [eax*4 + 0x4d986c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085292) /* 0x4d986c */ + cpu.eax * 4);
    // 004776ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004776ec:
    // 004776ec  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 004776f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477700);
    // 00477700  a15c205100             -mov eax, dword ptr [0x51205c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316700) /* 0x51205c */);
    // 00477705  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00477708  050c984d00             -add eax, 0x4d980c
    (cpu.eax) += x86::reg32(x86::sreg32(5085196 /*0x4d980c*/));
    // 0047770d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_477710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477710);
    // 00477710  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00477716  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047771c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00477722  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477730);
    // 00477730  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477731  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477733  891500755500           -mov dword ptr [0x557500], edx
    app->getMemory<x86::reg32>(x86::reg32(5600512) /* 0x557500 */) = cpu.edx;
    // 00477739  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047773a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477740);
    // 00477740  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477750);
    // 00477750  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477760);
    // 00477760  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477770);
    // 00477770  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477780);
    // 00477780  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477782  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477784  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477786  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477788  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047778a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047778c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047778e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477790  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477792  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477794  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477796  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00477798  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047779a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047779c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0047779e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004777a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004777a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4777b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004777b0);
    // 004777b0  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004777b5  0f8555000000           -jne 0x477810
    if (!cpu.flags.zf)
    {
        goto L_0x00477810;
    }
    // 004777bb  f6056879550020         +test byte ptr [0x557968], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) & 32 /*0x20*/));
    // 004777c2  7546                   -jne 0x47780a
    if (!cpu.flags.zf)
    {
        goto L_0x0047780a;
    }
L_0x004777c4:
    // 004777c4  83f84b                 +cmp eax, 0x4b
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
    // 004777c7  7509                   -jne 0x4777d2
    if (!cpu.flags.zf)
    {
        goto L_0x004777d2;
    }
    // 004777c9  f6056879550004         +test byte ptr [0x557968], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) & 4 /*0x4*/));
    // 004777d0  7538                   -jne 0x47780a
    if (!cpu.flags.zf)
    {
        goto L_0x0047780a;
    }
L_0x004777d2:
    // 004777d2  83f84d                 +cmp eax, 0x4d
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
    // 004777d5  7509                   -jne 0x4777e0
    if (!cpu.flags.zf)
    {
        goto L_0x004777e0;
    }
    // 004777d7  f6056879550008         +test byte ptr [0x557968], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) & 8 /*0x8*/));
    // 004777de  752a                   -jne 0x47780a
    if (!cpu.flags.zf)
    {
        goto L_0x0047780a;
    }
L_0x004777e0:
    // 004777e0  83f848                 +cmp eax, 0x48
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
    // 004777e3  7509                   -jne 0x4777ee
    if (!cpu.flags.zf)
    {
        goto L_0x004777ee;
    }
    // 004777e5  f6056879550001         +test byte ptr [0x557968], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) & 1 /*0x1*/));
    // 004777ec  751c                   -jne 0x47780a
    if (!cpu.flags.zf)
    {
        goto L_0x0047780a;
    }
L_0x004777ee:
    // 004777ee  83f850                 +cmp eax, 0x50
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
    // 004777f1  7509                   -jne 0x4777fc
    if (!cpu.flags.zf)
    {
        goto L_0x004777fc;
    }
    // 004777f3  f6056879550002         +test byte ptr [0x557968], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) & 2 /*0x2*/));
    // 004777fa  750e                   -jne 0x47780a
    if (!cpu.flags.zf)
    {
        goto L_0x0047780a;
    }
L_0x004777fc:
    // 004777fc  83f81c                 +cmp eax, 0x1c
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
    // 004777ff  751a                   -jne 0x47781b
    if (!cpu.flags.zf)
    {
        goto L_0x0047781b;
    }
    // 00477801  f6056879550010         +test byte ptr [0x557968], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) & 16 /*0x10*/));
    // 00477808  7411                   -je 0x47781b
    if (cpu.flags.zf)
    {
        goto L_0x0047781b;
    }
L_0x0047780a:
    // 0047780a  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0047780f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477810:
    // 00477810  80b8f4b24d0000         +cmp byte ptr [eax + 0x4db2f4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092084) /* 0x4db2f4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477817  74ab                   -je 0x4777c4
    if (cpu.flags.zf)
    {
        goto L_0x004777c4;
    }
    // 00477819  ebef                   -jmp 0x47780a
    goto L_0x0047780a;
L_0x0047781b:
    // 0047781b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047781d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_477820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477820);
    // 00477820  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00477825  80b8f4b24d0000         +cmp byte ptr [eax + 0x4db2f4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092084) /* 0x4db2f4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047782c  7503                   -jne 0x477831
    if (!cpu.flags.zf)
    {
        goto L_0x00477831;
    }
    // 0047782e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477830  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477831:
    // 00477831  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477832  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00477834  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00477839  88352bb34d00           -mov byte ptr [0x4db32b], dh
    app->getMemory<x86::reg8>(x86::reg32(5092139) /* 0x4db32b */) = cpu.dh;
    // 0047783f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477850);
    // 00477850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477853  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477855  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477857  c1ea14                 -shr edx, 0x14
    cpu.edx >>= 20 /*0x14*/ % 32;
    // 0047785a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047785d  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00477860  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00477863  8b848240755500         -mov eax, dword ptr [edx + eax*4 + 0x557540]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5600576) /* 0x557540 */ + cpu.eax * 4);
    // 0047786a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047786c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00477872  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00477878  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0047787b  39ca                   +cmp edx, ecx
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
    // 0047787d  7d34                   -jge 0x4778b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004778b3;
    }
    // 0047787f  39d0                   +cmp eax, edx
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
    // 00477881  7c0d                   -jl 0x477890
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477890;
    }
    // 00477883  39c8                   +cmp eax, ecx
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
    // 00477885  7e0f                   -jle 0x477896
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477896;
    }
L_0x00477887:
    // 00477887  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0047788c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047788d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047788e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047788f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477890:
    // 00477890  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477892  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477894  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477895  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477896:
    // 00477896  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00477898  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047789a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047789d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047789f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004778a1  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004778a4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004778a6  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004778a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004778aa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004778ad  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004778af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004778b3:
    // 004778b3  7e08                   -jle 0x4778bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004778bd;
    }
    // 004778b5  39c8                   +cmp eax, ecx
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
    // 004778b7  7cce                   -jl 0x477887
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477887;
    }
    // 004778b9  39d0                   +cmp eax, edx
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
    // 004778bb  7e06                   -jle 0x4778c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004778c3;
    }
L_0x004778bd:
    // 004778bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004778bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004778c3:
    // 004778c3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004778c5  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004778c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004778c9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004778cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004778ce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004778d0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004778d3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004778d5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004778d7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004778d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004778db  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004778de  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004778e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4778f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004778f0);
    // 004778f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004778f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004778f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004778f4  c1e814                 -shr eax, 0x14
    cpu.eax >>= 20 /*0x14*/ % 32;
    // 004778f7  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004778fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004778fc  e89f000000             -call 0x4779a0
    cpu.esp -= 4;
    sub_4779a0(app, cpu);
    if (cpu.terminate) return;
    // 00477901  b820755500             -mov eax, 0x557520
    cpu.eax = 5600544 /*0x557520*/;
    // 00477906  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 00477909  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047790c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047790e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00477911  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00477914  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00477916  89841120755500         -mov dword ptr [ecx + edx + 0x557520], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5600544) /* 0x557520 */ + cpu.edx * 1) = cpu.eax;
    // 0047791d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047791f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477920  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477921  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477930);
    // 00477930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477931  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477932  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477934  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00477937  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047793a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047793c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477941  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00477944  d3e0                   +shl eax, cl
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
    // 00477946  85825c755500           -test dword ptr [edx + 0x55755c], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5600604) /* 0x55755c */) & cpu.eax));
    // 0047794c  7408                   -je 0x477956
    if (cpu.flags.zf)
    {
        goto L_0x00477956;
    }
    // 0047794e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00477953  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477954  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477955  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477956:
    // 00477956  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477958  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477959  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047795a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477960);
    // 00477960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477961  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477963  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 00477966  83fa10                 +cmp edx, 0x10
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
    // 00477969  7d17                   -jge 0x477982
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477982;
    }
    // 0047796b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047796c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047796f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00477971  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477976  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00477978  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047797a  21049520795500         -and dword ptr [edx*4 + 0x557920], eax
    app->getMemory<x86::reg32>(x86::reg32(5601568) /* 0x557920 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.eax));
    // 00477981  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477982:
    // 00477982  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477984  e817000000             -call 0x4779a0
    cpu.esp -= 4;
    sub_4779a0(app, cpu);
    if (cpu.terminate) return;
    // 00477989  b820755500             -mov eax, 0x557520
    cpu.eax = 5600544 /*0x557520*/;
    // 0047798e  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00477991  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00477993  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00477996  89823c755500           -mov dword ptr [edx + 0x55753c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5600572) /* 0x55753c */) = cpu.eax;
    // 0047799c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047799e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047799f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4779a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004779a0);
    // 004779a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004779a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004779a2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004779a4  b86c795500             -mov eax, 0x55796c
    cpu.eax = 5601644 /*0x55796c*/;
L_0x004779a9:
    // 004779a9  0fbe10                 -movsx edx, byte ptr [eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004779ac  83faff                 +cmp edx, -1
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
    // 004779af  7e07                   -jle 0x4779b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004779b8;
    }
    // 004779b1  39ca                   +cmp edx, ecx
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
    // 004779b3  7403                   -je 0x4779b8
    if (cpu.flags.zf)
    {
        goto L_0x004779b8;
    }
    // 004779b5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004779b6  ebf1                   -jmp 0x4779a9
    goto L_0x004779a9;
L_0x004779b8:
    // 004779b8  803800                 +cmp byte ptr [eax], 0
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
    // 004779bb  7c03                   -jl 0x4779c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004779c0;
    }
    // 004779bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004779c0:
    // 004779c0  c64001ff               -mov byte ptr [eax + 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 255 /*0xff*/;
    // 004779c4  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004779c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004779c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4779d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004779d0);
    // 004779d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004779d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004779d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004779d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004779d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004779d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004779d6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004779d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004779db  bf6c795500             -mov edi, 0x55796c
    cpu.edi = 5601644 /*0x55796c*/;
    // 004779e0  891568795500           -mov dword ptr [0x557968], edx
    app->getMemory<x86::reg32>(x86::reg32(5601640) /* 0x557968 */) = cpu.edx;
L_0x004779e6:
    // 004779e6  0fbe37                 -movsx esi, byte ptr [edi]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edi)));
    // 004779e9  83feff                 +cmp esi, -1
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
    // 004779ec  7e30                   -jle 0x477a1e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477a1e;
    }
    // 004779ee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004779f0  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004779f3  0520755500             +add eax, 0x557520
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5600544 /*0x557520*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004779f8  8b6818                 -mov ebp, dword ptr [eax + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004779fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004779fc  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004779ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477a00  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00477a03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477a04  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00477a07  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00477a0a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477a0b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00477a0e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00477a11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477a12  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00477a14  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477a16  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477a17  e8f4010000             -call 0x477c10
    cpu.esp -= 4;
    sub_477c10(app, cpu);
    if (cpu.terminate) return;
    // 00477a1c  ebc8                   -jmp 0x4779e6
    goto L_0x004779e6;
L_0x00477a1e:
    // 00477a1e  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00477a23  e828eb0000             -call 0x486550
    cpu.esp -= 4;
    sub_486550(app, cpu);
    if (cpu.terminate) return;
    // 00477a28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477a2a  754d                   -jne 0x477a79
    if (!cpu.flags.zf)
    {
        goto L_0x00477a79;
    }
    // 00477a2c  833d280f540000         +cmp dword ptr [0x540f28], 0
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
    // 00477a33  743b                   -je 0x477a70
    if (cpu.flags.zf)
    {
        goto L_0x00477a70;
    }
L_0x00477a35:
    // 00477a35  8b3d64795500           -mov edi, dword ptr [0x557964]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5601636) /* 0x557964 */);
    // 00477a3b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00477a3d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00477a3f  7e38                   -jle 0x477a79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477a79;
    }
    // 00477a41  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x00477a45:
    // 00477a45  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477a49  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477a4d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477a4f  b96c795500             -mov ecx, 0x55796c
    cpu.ecx = 5601644 /*0x55796c*/;
    // 00477a54  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00477a58  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00477a5c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00477a5f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
L_0x00477a61:
    // 00477a61  0fbe01                 -movsx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx)));
    // 00477a64  83f8ff                 +cmp eax, -1
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
    // 00477a67  7e51                   -jle 0x477aba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477aba;
    }
    // 00477a69  39f0                   +cmp eax, esi
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
    // 00477a6b  7416                   -je 0x477a83
    if (cpu.flags.zf)
    {
        goto L_0x00477a83;
    }
L_0x00477a6d:
    // 00477a6d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477a6e  ebf1                   -jmp 0x477a61
    goto L_0x00477a61;
L_0x00477a70:
    // 00477a70  833d1422510002         +cmp dword ptr [0x512214], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477a77  7dbc                   -jge 0x477a35
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477a35;
    }
L_0x00477a79:
    // 00477a79  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477a7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477a83:
    // 00477a83  ba20755500             -mov edx, 0x557520
    cpu.edx = 5600544 /*0x557520*/;
    // 00477a88  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00477a8b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477a8d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00477a8f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477a91  7407                   -je 0x477a9a
    if (cpu.flags.zf)
    {
        goto L_0x00477a9a;
    }
    // 00477a93  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477a95  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477a97  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00477a9a:
    // 00477a9a  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00477a9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477a9f  7408                   -je 0x477aa9
    if (cpu.flags.zf)
    {
        goto L_0x00477aa9;
    }
    // 00477aa1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477aa3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00477aa5  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00477aa9:
    // 00477aa9  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00477aac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477aae  74bd                   -je 0x477a6d
    if (cpu.flags.zf)
    {
        goto L_0x00477a6d;
    }
    // 00477ab0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477ab2  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00477ab4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00477ab8  ebb3                   -jmp 0x477a6d
    goto L_0x00477a6d;
L_0x00477aba:
    // 00477aba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477abc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477abe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477ac0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477ac2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00477ac4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477ac6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00477ac8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477aca  e841010000             -call 0x477c10
    cpu.esp -= 4;
    sub_477c10(app, cpu);
    if (cpu.terminate) return;
    // 00477acf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477ad1  744e                   -je 0x477b21
    if (cpu.flags.zf)
    {
        goto L_0x00477b21;
    }
    // 00477ad3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00477ad6  3d00400000             +cmp eax, 0x4000
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
    // 00477adb  7d63                   -jge 0x477b40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477b40;
    }
    // 00477add  800d6879550004         -or byte ptr [0x557968], 4
    app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00477ae4:
    // 00477ae4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477ae8  81f900400000           +cmp ecx, 0x4000
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
    // 00477aee  7d60                   -jge 0x477b50
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477b50;
    }
    // 00477af0  800d6879550001         -or byte ptr [0x557968], 1
    app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00477af7:
    // 00477af7  8b1568795500           -mov edx, dword ptr [0x557968]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5601640) /* 0x557968 */);
    // 00477afd  8b3d14225100           -mov edi, dword ptr [0x512214]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
    // 00477b03  80ca10                 -or dl, 0x10
    cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00477b06  83ff02                 +cmp edi, 2
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
    // 00477b09  7c56                   -jl 0x477b61
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477b61;
    }
    // 00477b0b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477b0f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477b13  858120795500           -test dword ptr [ecx + 0x557920], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5601568) /* 0x557920 */) & cpu.eax));
L_0x00477b19:
    // 00477b19  7406                   -je 0x477b21
    if (cpu.flags.zf)
    {
        goto L_0x00477b21;
    }
    // 00477b1b  891568795500           -mov dword ptr [0x557968], edx
    app->getMemory<x86::reg32>(x86::reg32(5601640) /* 0x557968 */) = cpu.edx;
L_0x00477b21:
    // 00477b21  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477b25  8b1564795500           -mov edx, dword ptr [0x557964]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5601636) /* 0x557964 */);
    // 00477b2b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477b2e  46                     -inc esi
    (cpu.esi)++;
    // 00477b2f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00477b33  39d6                   +cmp esi, edx
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
    // 00477b35  0f8d3effffff           -jge 0x477a79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477a79;
    }
    // 00477b3b  e905ffffff             -jmp 0x477a45
    goto L_0x00477a45;
L_0x00477b40:
    // 00477b40  3d00c00000             +cmp eax, 0xc000
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
    // 00477b45  7e9d                   -jle 0x477ae4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477ae4;
    }
    // 00477b47  800d6879550008         +or byte ptr [0x557968], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00477b4e  eb94                   -jmp 0x477ae4
    goto L_0x00477ae4;
L_0x00477b50:
    // 00477b50  81f900c00000           +cmp ecx, 0xc000
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
    // 00477b56  7e9f                   -jle 0x477af7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477af7;
    }
    // 00477b58  800d6879550002         +or byte ptr [0x557968], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5601640) /* 0x557968 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00477b5f  eb96                   -jmp 0x477af7
    goto L_0x00477af7;
L_0x00477b61:
    // 00477b61  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00477b66  ebb1                   -jmp 0x477b19
    goto L_0x00477b19;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477b70);
    // 00477b70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477b71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477b72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b73  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477b76  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477b78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b79  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b7b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b7c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477b7e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477b80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b81  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00477b85  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477b89  e882000000             -call 0x477c10
    cpu.esp -= 4;
    sub_477c10(app, cpu);
    if (cpu.terminate) return;
    // 00477b8e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00477b91  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477b94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477ba0);
    // 00477ba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477ba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477ba2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477ba3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477ba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477ba5  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477ba8  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00477bad  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00477baf  be80774700             -mov esi, 0x477780
    cpu.esi = 4683648 /*0x477780*/;
    // 00477bb4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00477bb6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477bb8  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00477bbc  83fa06                 +cmp edx, 6
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
    // 00477bbf  7d0e                   -jge 0x477bcf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477bcf;
    }
    // 00477bc1  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00477bc8  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477bcc  89140c                 -mov dword ptr [esp + ecx], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1) = cpu.edx;
L_0x00477bcf:
    // 00477bcf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477bd1  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477bd5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477bd6  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477bda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477bdb  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477bdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477be0  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477be4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477be8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477be9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477beb  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477bef  e81c000000             -call 0x477c10
    cpu.esp -= 4;
    sub_477c10(app, cpu);
    if (cpu.terminate) return;
    // 00477bf4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477bf8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00477bfb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bfc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bfe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477c10);
    // 00477c10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477c13  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477c17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c18  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477c1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c1d  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477c21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477c22  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477c26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c27  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00477c2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c2c  e85f9ffaff             -call 0x421b90
    cpu.esp -= 4;
    sub_421b90(app, cpu);
    if (cpu.terminate) return;
    // 00477c31  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c34  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477c40);
    // 00477c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c41  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00477c46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477c48  740c                   -je 0x477c56
    if (cpu.flags.zf)
    {
        goto L_0x00477c56;
    }
    // 00477c4a  b81a000000             -mov eax, 0x1a
    cpu.eax = 26 /*0x1a*/;
    // 00477c4f  e82c3dfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00477c54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477c56:
    // 00477c56  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 00477c5b  e8203dfeff             -call 0x45b980
    cpu.esp -= 4;
    sub_45b980(app, cpu);
    if (cpu.terminate) return;
    // 00477c60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477c70);
    // 00477c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477c76  833d6079550000         +cmp dword ptr [0x557960], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5601632) /* 0x557960 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477c7d  7429                   -je 0x477ca8
    if (cpu.flags.zf)
    {
        goto L_0x00477ca8;
    }
    // 00477c7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477c81:
    // 00477c81  8b82d0285100           -mov eax, dword ptr [edx + 0x5128d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5318864) /* 0x5128d0 */);
    // 00477c87  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00477c8c  83f801                 +cmp eax, 1
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
    // 00477c8f  750c                   -jne 0x477c9d
    if (!cpu.flags.zf)
    {
        goto L_0x00477c9d;
    }
    // 00477c91  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477c93  05d0285100             -add eax, 0x5128d0
    (cpu.eax) += x86::reg32(x86::sreg32(5318864 /*0x5128d0*/));
    // 00477c98  e883010000             -call 0x477e20
    cpu.esp -= 4;
    sub_477e20(app, cpu);
    if (cpu.terminate) return;
L_0x00477c9d:
    // 00477c9d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477ca0  81fa60010000           +cmp edx, 0x160
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
    // 00477ca6  75d9                   -jne 0x477c81
    if (!cpu.flags.zf)
    {
        goto L_0x00477c81;
    }
L_0x00477ca8:
    // 00477ca8  b903010000             -mov ecx, 0x103
    cpu.ecx = 259 /*0x103*/;
    // 00477cad  be04480000             -mov esi, 0x4804
    cpu.esi = 18436 /*0x4804*/;
    // 00477cb2  bf04500000             -mov edi, 0x5004
    cpu.edi = 20484 /*0x5004*/;
    // 00477cb7  bd044b0000             -mov ebp, 0x4b04
    cpu.ebp = 19204 /*0x4b04*/;
    // 00477cbc  b8044d0000             -mov eax, 0x4d04
    cpu.eax = 19716 /*0x4d04*/;
    // 00477cc1  ba041c0000             -mov edx, 0x1c04
    cpu.edx = 7172 /*0x1c04*/;
    // 00477cc6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477cc8  890d48295100           -mov dword ptr [0x512948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5318984) /* 0x512948 */) = cpu.ecx;
    // 00477cce  891d4c295100           -mov dword ptr [0x51294c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5318988) /* 0x51294c */) = cpu.ebx;
    // 00477cd4  893534295100           -mov dword ptr [0x512934], esi
    app->getMemory<x86::reg32>(x86::reg32(5318964) /* 0x512934 */) = cpu.esi;
    // 00477cda  893d38295100           -mov dword ptr [0x512938], edi
    app->getMemory<x86::reg32>(x86::reg32(5318968) /* 0x512938 */) = cpu.edi;
    // 00477ce0  892d3c295100           -mov dword ptr [0x51293c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5318972) /* 0x51293c */) = cpu.ebp;
    // 00477ce6  a340295100             -mov dword ptr [0x512940], eax
    app->getMemory<x86::reg32>(x86::reg32(5318976) /* 0x512940 */) = cpu.eax;
    // 00477ceb  891544295100           -mov dword ptr [0x512944], edx
    app->getMemory<x86::reg32>(x86::reg32(5318980) /* 0x512944 */) = cpu.edx;
    // 00477cf1  b9030f0000             -mov ecx, 0xf03
    cpu.ecx = 3843 /*0xf03*/;
    // 00477cf6  bb033b0000             -mov ebx, 0x3b03
    cpu.ebx = 15107 /*0x3b03*/;
    // 00477cfb  be033c0000             -mov esi, 0x3c03
    cpu.esi = 15363 /*0x3c03*/;
    // 00477d00  bf033d0000             -mov edi, 0x3d03
    cpu.edi = 15619 /*0x3d03*/;
    // 00477d05  bd033e0000             -mov ebp, 0x3e03
    cpu.ebp = 15875 /*0x3e03*/;
    // 00477d0a  b8033f0000             -mov eax, 0x3f03
    cpu.eax = 16131 /*0x3f03*/;
    // 00477d0f  ba03400000             -mov edx, 0x4003
    cpu.edx = 16387 /*0x4003*/;
    // 00477d14  890d50295100           -mov dword ptr [0x512950], ecx
    app->getMemory<x86::reg32>(x86::reg32(5318992) /* 0x512950 */) = cpu.ecx;
    // 00477d1a  891d5c295100           -mov dword ptr [0x51295c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319004) /* 0x51295c */) = cpu.ebx;
    // 00477d20  893558295100           -mov dword ptr [0x512958], esi
    app->getMemory<x86::reg32>(x86::reg32(5319000) /* 0x512958 */) = cpu.esi;
    // 00477d26  893d64295100           -mov dword ptr [0x512964], edi
    app->getMemory<x86::reg32>(x86::reg32(5319012) /* 0x512964 */) = cpu.edi;
    // 00477d2c  892d68295100           -mov dword ptr [0x512968], ebp
    app->getMemory<x86::reg32>(x86::reg32(5319016) /* 0x512968 */) = cpu.ebp;
    // 00477d32  a378295100             -mov dword ptr [0x512978], eax
    app->getMemory<x86::reg32>(x86::reg32(5319032) /* 0x512978 */) = cpu.eax;
    // 00477d37  89157c295100           -mov dword ptr [0x51297c], edx
    app->getMemory<x86::reg32>(x86::reg32(5319036) /* 0x51297c */) = cpu.edx;
    // 00477d3d  b903410000             -mov ecx, 0x4103
    cpu.ecx = 16643 /*0x4103*/;
    // 00477d42  bb03420000             -mov ebx, 0x4203
    cpu.ebx = 16899 /*0x4203*/;
    // 00477d47  be03430000             -mov esi, 0x4303
    cpu.esi = 17155 /*0x4303*/;
    // 00477d4c  bf03440000             -mov edi, 0x4403
    cpu.edi = 17411 /*0x4403*/;
    // 00477d51  a114225100             -mov eax, dword ptr [0x512214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317140) /* 0x512214 */);
    // 00477d56  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00477d58  890d74295100           -mov dword ptr [0x512974], ecx
    app->getMemory<x86::reg32>(x86::reg32(5319028) /* 0x512974 */) = cpu.ecx;
    // 00477d5e  891d88295100           -mov dword ptr [0x512988], ebx
    app->getMemory<x86::reg32>(x86::reg32(5319048) /* 0x512988 */) = cpu.ebx;
    // 00477d64  893584295100           -mov dword ptr [0x512984], esi
    app->getMemory<x86::reg32>(x86::reg32(5319044) /* 0x512984 */) = cpu.esi;
    // 00477d6a  893d54295100           -mov dword ptr [0x512954], edi
    app->getMemory<x86::reg32>(x86::reg32(5318996) /* 0x512954 */) = cpu.edi;
    // 00477d70  892d30295100           -mov dword ptr [0x512930], ebp
    app->getMemory<x86::reg32>(x86::reg32(5318960) /* 0x512930 */) = cpu.ebp;
    // 00477d76  83f802                 +cmp eax, 2
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
    // 00477d79  0f8c6e000000           -jl 0x477ded
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477ded;
    }
    // 00477d7f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00477d84  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477d86:
    // 00477d86  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477d89  898a1c795500           -mov dword ptr [edx + 0x55791c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5601564) /* 0x55791c */) = cpu.ecx;
    // 00477d8f  83fa40                 +cmp edx, 0x40
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
    // 00477d92  75f2                   -jne 0x477d86
    if (!cpu.flags.zf)
    {
        goto L_0x00477d86;
    }
    // 00477d94  a18c295100             -mov eax, dword ptr [0x51298c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319052) /* 0x51298c */);
    // 00477d99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477d9b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00477da1  83fa02                 +cmp edx, 2
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
    // 00477da4  752b                   -jne 0x477dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00477dd1;
    }
    // 00477da6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477da8  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00477dab  83fa10                 +cmp edx, 0x10
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
    // 00477dae  7d21                   -jge 0x477dd1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477dd1;
    }
    // 00477db0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477db2  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00477db5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477dba  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00477dbd  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00477dbf  8b1c9520795500         -mov ebx, dword ptr [edx*4 + 0x557920]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5601568) /* 0x557920 */ + cpu.edx * 4);
    // 00477dc6  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00477dc8  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00477dca  891c9520795500         -mov dword ptr [edx*4 + 0x557920], ebx
    app->getMemory<x86::reg32>(x86::reg32(5601568) /* 0x557920 */ + cpu.edx * 4) = cpu.ebx;
L_0x00477dd1:
    // 00477dd1  a194295100             -mov eax, dword ptr [0x512994]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319060) /* 0x512994 */);
    // 00477dd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477dd8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00477dde  83fa02                 +cmp edx, 2
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
    // 00477de1  750a                   -jne 0x477ded
    if (!cpu.flags.zf)
    {
        goto L_0x00477ded;
    }
    // 00477de3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477de5  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00477de8  83fa10                 +cmp edx, 0x10
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
    // 00477deb  7c07                   -jl 0x477df4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477df4;
    }
L_0x00477ded:
    // 00477ded  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477dee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477def  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477df0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477df1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477df2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477df3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477df4:
    // 00477df4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477df6  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00477df9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477dfe  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00477e01  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00477e03  8b349520795500         -mov esi, dword ptr [edx*4 + 0x557920]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5601568) /* 0x557920 */ + cpu.edx * 4);
    // 00477e0a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00477e0c  21c6                   -and esi, eax
    cpu.esi &= x86::reg32(x86::sreg32(cpu.eax));
    // 00477e0e  89349520795500         -mov dword ptr [edx*4 + 0x557920], esi
    app->getMemory<x86::reg32>(x86::reg32(5601568) /* 0x557920 */ + cpu.edx * 4) = cpu.esi;
    // 00477e15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_477e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00477e20);
    // 00477e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477e22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477e23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477e24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477e25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477e26  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477e29  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00477e2d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477e31  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477e35  8b0d60795500           -mov ecx, dword ptr [0x557960]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5601632) /* 0x557960 */);
    // 00477e3b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477e3d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00477e3f  c1f81c                 -sar eax, 0x1c
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (28 /*0x1c*/ % 32));
    // 00477e42  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477e45  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00477e49  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477e4d  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00477e4f  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00477e51  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00477e53  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00477e56  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00477e59  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477e5d  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00477e60  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 00477e63  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00477e67  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00477e6a  81e600ff0000           -and esi, 0xff00
    cpu.esi &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00477e70  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477e72  81e300ff0000           -and ebx, 0xff00
    cpu.ebx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00477e78  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00477e7b:
    // 00477e7b  a160795500             -mov eax, dword ptr [0x557960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601632) /* 0x557960 */);
    // 00477e80  3b38                   +cmp edi, dword ptr [eax]
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
    // 00477e82  0f8d7f010000           -jge 0x478007
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478007;
    }
    // 00477e88  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00477e8c  3b29                   +cmp ebp, dword ptr [ecx]
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
    // 00477e8e  7406                   -je 0x477e96
    if (cpu.flags.zf)
    {
        goto L_0x00477e96;
    }
L_0x00477e90:
    // 00477e90  83c114                 +add ecx, 0x14
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
    // 00477e93  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477e94  ebe5                   -jmp 0x477e7b
    goto L_0x00477e7b;
L_0x00477e96:
    // 00477e96  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477e9a  3b5104                 +cmp edx, dword ptr [ecx + 4]
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
    // 00477e9d  75f1                   -jne 0x477e90
    if (!cpu.flags.zf)
    {
        goto L_0x00477e90;
    }
    // 00477e9f  8d830080ffff           -lea eax, [ebx - 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-32768) /* -0x8000 */);
    // 00477ea5  8dae0080ffff           -lea ebp, [esi - 0x8000]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-32768) /* -0x8000 */);
    // 00477eab  39f3                   +cmp ebx, esi
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
    // 00477ead  0f8dcb000000           -jge 0x477f7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477f7e;
    }
    // 00477eb3  81fb00800000           +cmp ebx, 0x8000
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
    // 00477eb9  0f8d8b000000           -jge 0x477f4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477f4a;
    }
    // 00477ebf  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00477ec2  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00477ec5  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00477ec7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00477ec9  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00477ecb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477ecd  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00477ed0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477ed2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477ed5  c1e20f                 +shl edx, 0xf
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
    // 00477ed8  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477eda  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477edd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00477edf  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00477ee2  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00477ee5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477ee7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477ee9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477eec  c1e20f                 +shl edx, 0xf
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
    // 00477eef  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477ef1  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477ef4  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00477ef7:
    // 00477ef7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00477ef9:
    // 00477ef9  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00477efc  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 00477eff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477f01  0f8cf2000000           -jl 0x477ff9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477ff9;
    }
    // 00477f07  81fbff000000           +cmp ebx, 0xff
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
    // 00477f0d  7e05                   -jle 0x477f14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477f14;
    }
    // 00477f0f  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
L_0x00477f14:
    // 00477f14  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477f16  0f8ce4000000           -jl 0x478000
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478000;
    }
    // 00477f1c  81feff000000           +cmp esi, 0xff
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
    // 00477f22  7e05                   -jle 0x477f29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477f29;
    }
    // 00477f24  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
L_0x00477f29:
    // 00477f29  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00477f2b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00477f2e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00477f31  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477f33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477f35  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00477f38  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00477f3a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477f3e  40                     -inc eax
    (cpu.eax)++;
    // 00477f3f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00477f41  83c114                 +add ecx, 0x14
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
    // 00477f44  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00477f45  e931ffffff             -jmp 0x477e7b
    goto L_0x00477e7b;
L_0x00477f4a:
    // 00477f4a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00477f4d  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00477f50  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477f52  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00477f55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477f57  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477f5a  c1e20f                 +shl edx, 0xf
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
    // 00477f5d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477f5f  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477f62  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00477f64  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00477f67  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477f69  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477f6b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477f6e  c1e20f                 +shl edx, 0xf
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
    // 00477f71  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477f73  c1f80f                 +sar eax, 0xf
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
    // 00477f76  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00477f79  e979ffffff             -jmp 0x477ef7
    goto L_0x00477ef7;
L_0x00477f7e:
    // 00477f7e  81fb00800000           +cmp ebx, 0x8000
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
    // 00477f84  7e3d                   -jle 0x477fc3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477fc3;
    }
    // 00477f86  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00477f89  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00477f8c  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00477f8e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477f90  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00477f92  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00477f95  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477f97  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477f9a  c1e20f                 +shl edx, 0xf
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
    // 00477f9d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477f9f  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477fa2  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00477fa5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477fa7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00477fa9  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00477fac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477fae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477fb1  c1e20f                 +shl edx, 0xf
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
    // 00477fb4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477fb6  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477fb9  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00477fbc  29c3                   +sub ebx, eax
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
    // 00477fbe  e936ffffff             -jmp 0x477ef9
    goto L_0x00477ef9;
L_0x00477fc3:
    // 00477fc3  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00477fc6  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00477fc9  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477fcb  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00477fce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477fd0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477fd3  c1e20f                 +shl edx, 0xf
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
    // 00477fd6  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477fd8  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477fdb  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00477fdd  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00477fe0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477fe2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477fe4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477fe7  c1e20f                 +shl edx, 0xf
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
    // 00477fea  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00477fec  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00477fef  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00477ff2  29c6                   +sub esi, eax
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
    // 00477ff4  e900ffffff             -jmp 0x477ef9
    goto L_0x00477ef9;
L_0x00477ff9:
    // 00477ff9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00477ffb  e914ffffff             -jmp 0x477f14
    goto L_0x00477f14;
L_0x00478000:
    // 00478000  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00478002  e922ffffff             -jmp 0x477f29
    goto L_0x00477f29;
L_0x00478007:
    // 00478007  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047800a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047800b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047800c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047800d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047800e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047800f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478010  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478020);
    // 00478020  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478021  8b1560795500           -mov edx, dword ptr [0x557960]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5601632) /* 0x557960 */);
    // 00478027  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00478029  7502                   -jne 0x47802d
    if (!cpu.flags.zf)
    {
        goto L_0x0047802d;
    }
    // 0047802b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047802c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047802d:
    // 0047802d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047802f  e8c8c80000             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00478034  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478035  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478040);
    // 00478040  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478041  b824e74c00             -mov eax, 0x4ce724
    cpu.eax = 5039908 /*0x4ce724*/;
    // 00478046  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478048  e803ef0000             -call 0x486f50
    cpu.esp -= 4;
    sub_486f50(app, cpu);
    if (cpu.terminate) return;
    // 0047804d  a360795500             -mov dword ptr [0x557960], eax
    app->getMemory<x86::reg32>(x86::reg32(5601632) /* 0x557960 */) = cpu.eax;
    // 00478052  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478053  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478060);
    // 00478060  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478062  e8a99efaff             -call 0x421f10
    cpu.esp -= 4;
    sub_421f10(app, cpu);
    if (cpu.terminate) return;
    // 00478067  2eff15ec654c00         -call dword ptr cs:[0x4c65ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006828) /* 0x4c65ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047806e  83f810                 +cmp eax, 0x10
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
    // 00478071  7238                   -jb 0x4780ab
    if (cpu.flags.cf)
    {
        goto L_0x004780ab;
    }
    // 00478073  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00478078:
    // 00478078  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047807d  a364795500             -mov dword ptr [0x557964], eax
    app->getMemory<x86::reg32>(x86::reg32(5601636) /* 0x557964 */) = cpu.eax;
    // 00478082  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478085:
    // 00478085  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478088  89901c795500           -mov dword ptr [eax + 0x55791c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601564) /* 0x55791c */) = cpu.edx;
    // 0047808e  83f840                 +cmp eax, 0x40
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
    // 00478091  75f2                   -jne 0x478085
    if (!cpu.flags.zf)
    {
        goto L_0x00478085;
    }
    // 00478093  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 00478098  b820755500             -mov eax, 0x557520
    cpu.eax = 5600544 /*0x557520*/;
    // 0047809d  e87a1f0100             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 004780a2  c6056c795500ff         -mov byte ptr [0x55796c], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5601644) /* 0x55796c */) = 255 /*0xff*/;
    // 004780a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004780aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004780ab:
    // 004780ab  2eff15ec654c00         -call dword ptr cs:[0x4c65ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006828) /* 0x4c65ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004780b2  ebc4                   -jmp 0x478078
    goto L_0x00478078;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4780c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004780c0);
    // 004780c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004780c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004780c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004780c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004780c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004780c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004780c6  a10c2e5100             -mov eax, dword ptr [0x512e0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5320204) /* 0x512e0c */);
    // 004780cb  8b15102e5100           -mov edx, dword ptr [0x512e10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5320208) /* 0x512e10 */);
    // 004780d1  8b0d142e5100           -mov ecx, dword ptr [0x512e14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5320212) /* 0x512e14 */);
    // 004780d7  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004780d9  8b1d182e5100           -mov ebx, dword ptr [0x512e18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5320216) /* 0x512e18 */);
    // 004780df  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004780e1  8b351c2e5100           -mov esi, dword ptr [0x512e1c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5320220) /* 0x512e1c */);
    // 004780e7  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004780e9  8b3d202e5100           -mov edi, dword ptr [0x512e20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5320224) /* 0x512e20 */);
    // 004780ef  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004780f1  8b2d242e5100           -mov ebp, dword ptr [0x512e24]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5320228) /* 0x512e24 */);
    // 004780f7  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004780f9  8b15282e5100           -mov edx, dword ptr [0x512e28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5320232) /* 0x512e28 */);
    // 004780ff  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00478101  8b0d2c2e5100           -mov ecx, dword ptr [0x512e2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5320236) /* 0x512e2c */);
    // 00478107  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00478109  8b1d302e5100           -mov ebx, dword ptr [0x512e30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5320240) /* 0x512e30 */);
    // 0047810f  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478111  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478113  e828ccf8ff             -call 0x404d40
    cpu.esp -= 4;
    sub_404d40(app, cpu);
    if (cpu.terminate) return;
    // 00478118  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0047811a  740c                   -je 0x478128
    if (cpu.flags.zf)
    {
        goto L_0x00478128;
    }
    // 0047811c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00478121  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478122  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478123  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478124  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478125  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478126  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478127  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478128:
    // 00478128  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047812a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047812b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047812c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047812d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047812e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047812f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478130  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478140);
    // 00478140  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478141  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478142  8b0d401e5100           -mov ecx, dword ptr [0x511e40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00478148  3b0d0c225100           +cmp ecx, dword ptr [0x51220c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047814e  7e2d                   -jle 0x47817d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047817d;
    }
    // 00478150  8b90b8020000           -mov edx, dword ptr [eax + 0x2b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(696) /* 0x2b8 */);
L_0x00478156:
    // 00478156  b9703d0200             -mov ecx, 0x23d70
    cpu.ecx = 146800 /*0x23d70*/;
    // 0047815b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047815d  7e26                   -jle 0x478185
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478185;
    }
    // 0047815f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00478161:
    // 00478161  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00478163  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00478165  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478168  c1e810                 +shr eax, 0x10
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
    // 0047816b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047816d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047816f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00478172  c1e210                 +shl edx, 0x10
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
    // 00478175  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00478177  c1f810                 +sar eax, 0x10
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
    // 0047817a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047817b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047817c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047817d:
    // 0047817d  8b90a0030000           -mov edx, dword ptr [eax + 0x3a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(928) /* 0x3a0 */);
    // 00478183  ebd1                   -jmp 0x478156
    goto L_0x00478156;
L_0x00478185:
    // 00478185  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478187  f7d8                   +neg eax
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
    // 00478189  ebd6                   -jmp 0x478161
    goto L_0x00478161;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478190);
    // 00478190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478191  66833d1c994d0000       +cmp word ptr [0x4d991c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5085468) /* 0x4d991c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00478199  750b                   -jne 0x4781a6
    if (!cpu.flags.zf)
    {
        goto L_0x004781a6;
    }
    // 0047819b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047819d  66891d1c994d00         -mov word ptr [0x4d991c], bx
    app->getMemory<x86::reg16>(x86::reg32(5085468) /* 0x4d991c */) = cpu.bx;
    // 004781a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004781a6:
    // 004781a6  a182795500             -mov eax, dword ptr [0x557982]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601666) /* 0x557982 */);
    // 004781ab  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004781ae  e8cda7faff             -call 0x422980
    cpu.esp -= 4;
    sub_422980(app, cpu);
    if (cpu.terminate) return;
    // 004781b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004781b5  66891d1c994d00         -mov word ptr [0x4d991c], bx
    app->getMemory<x86::reg16>(x86::reg32(5085468) /* 0x4d991c */) = cpu.bx;
    // 004781bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4781c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004781c0);
    // 004781c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004781c1  833d10994d0000         +cmp dword ptr [0x4d9910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781c8  7516                   -jne 0x4781e0
    if (!cpu.flags.zf)
    {
        goto L_0x004781e0;
    }
L_0x004781ca:
    // 004781ca  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004781cc  890d14994d00           -mov dword ptr [0x4d9914], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */) = cpu.ecx;
    // 004781d2  890d18994d00           -mov dword ptr [0x4d9918], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */) = cpu.ecx;
    // 004781d8  890d10994d00           -mov dword ptr [0x4d9910], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = cpu.ecx;
    // 004781de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004781df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004781e0:
    // 004781e0  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 004781e5  c1f810                 +sar eax, 0x10
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
    // 004781e8  e893a7faff             -call 0x422980
    cpu.esp -= 4;
    sub_422980(app, cpu);
    if (cpu.terminate) return;
    // 004781ed  ebdb                   -jmp 0x4781ca
    goto L_0x004781ca;
}

/* align: skip 0x00 */
void Application::sub_4781f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004781f0);
    // 004781f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004781f1  8b35601e5100           -mov esi, dword ptr [0x511e60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316192) /* 0x511e60 */);
    // 004781f7  3b3520994d00           +cmp esi, dword ptr [0x4d9920]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085472) /* 0x4d9920 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781fd  7d02                   -jge 0x478201
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478201;
    }
    // 004781ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478201:
    // 00478201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478202  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478204  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478206  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478208  c1f903                 -sar ecx, 3
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (3 /*0x3*/ % 32));
    // 0047820b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047820c  8b35601e5100           -mov esi, dword ptr [0x511e60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316192) /* 0x511e60 */);
    // 00478212  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478214  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478216  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478218  893520994d00           -mov dword ptr [0x4d9920], esi
    app->getMemory<x86::reg32>(x86::reg32(5085472) /* 0x4d9920 */) = cpu.esi;
    // 0047821e  8b357e795500           -mov esi, dword ptr [0x55797e]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5601662) /* 0x55797e */);
    // 00478224  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478226  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00478229  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047822e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478230  e88ba3faff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478235  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478236  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478237  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478240);
    // 00478240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478241  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478242  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478243  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478244  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478245  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00478248  ba10270000             -mov edx, 0x2710
    cpu.edx = 10000 /*0x2710*/;
    // 0047824d  b9c8000000             -mov ecx, 0xc8
    cpu.ecx = 200 /*0xc8*/;
    // 00478252  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00478254  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00478256  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00478259  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047825d  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 00478261  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00478265  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 00478267  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0047826b  8854243c               -mov byte ptr [esp + 0x3c], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.dl;
    // 0047826f  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 00478271  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478273  8874243d               -mov byte ptr [esp + 0x3d], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(61) /* 0x3d */) = cpu.dh;
    // 00478277  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00478279  89742444               -mov dword ptr [esp + 0x44], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.esi;
    // 0047827d  e8b2a7faff             -call 0x422a34
    cpu.esp -= 4;
    sub_422a34(app, cpu);
    if (cpu.terminate) return;
    // 00478282  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00478285  7d0b                   -jge 0x478292
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478292;
    }
L_0x00478287:
    // 00478287  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478289  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0047828c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047828d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047828e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047828f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478291  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478292:
    // 00478292  b303                   -mov bl, 3
    cpu.bl = 3 /*0x3*/;
    // 00478294  bd10270000             -mov ebp, 0x2710
    cpu.ebp = 10000 /*0x2710*/;
    // 00478299  b9e4720000             -mov ecx, 0x72e4
    cpu.ecx = 29412 /*0x72e4*/;
    // 0047829e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004782a0  66a380795500           -mov word ptr [0x557980], ax
    app->getMemory<x86::reg16>(x86::reg32(5601664) /* 0x557980 */) = cpu.ax;
    // 004782a6  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004782aa  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004782ae  881c24                 -mov byte ptr [esp], bl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.bl;
    // 004782b1  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004782b5  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004782b9  bbffffff00             -mov ebx, 0xffffff
    cpu.ebx = 16777215 /*0xffffff*/;
    // 004782be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004782c0  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004782c4  e86ba7faff             -call 0x422a34
    cpu.esp -= 4;
    sub_422a34(app, cpu);
    if (cpu.terminate) return;
    // 004782c9  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004782cc  7cb9                   -jl 0x478287
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478287;
    }
    // 004782ce  b709                   -mov bh, 9
    cpu.bh = 9 /*0x9*/;
    // 004782d0  66a382795500           -mov word ptr [0x557982], ax
    app->getMemory<x86::reg16>(x86::reg32(5601666) /* 0x557982 */) = cpu.ax;
    // 004782d6  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004782da  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004782de  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004782e2  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004782e6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004782e8  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004782ec  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004782f0  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004782f4  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004782f8  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004782fc  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 00478300  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 00478304  31ea                   -xor edx, ebp
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00478306  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00478308  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0047830c  31e8                   -xor eax, ebp
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047830e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00478310  883c24                 -mov byte ptr [esp], bh
    app->getMemory<x86::reg8>(cpu.esp) = cpu.bh;
    // 00478313  e81ca7faff             -call 0x422a34
    cpu.esp -= 4;
    sub_422a34(app, cpu);
    if (cpu.terminate) return;
    // 00478318  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0047831b  0f8c66ffffff           -jl 0x478287
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478287;
    }
    // 00478321  66a384795500           -mov word ptr [0x557984], ax
    app->getMemory<x86::reg16>(x86::reg32(5601668) /* 0x557984 */) = cpu.ax;
    // 00478327  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047832c  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0047832f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478330  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478331  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478332  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478333  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478334  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478340);
    // 00478340  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478347  7501                   -jne 0x47834a
    if (!cpu.flags.zf)
    {
        goto L_0x0047834a;
    }
    // 00478349  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047834a:
    // 0047834a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047834b  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00478350  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478352  e839abfaff             -call 0x422e90
    cpu.esp -= 4;
    sub_422e90(app, cpu);
    if (cpu.terminate) return;
    // 00478357  890dec984d00           -mov dword ptr [0x4d98ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */) = cpu.ecx;
    // 0047835d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047835e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_478360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478360);
    // 00478360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478363  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478364  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478365  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478366  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478369  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047836b  833df0984d0000         +cmp dword ptr [0x4d98f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085424) /* 0x4d98f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478372  0f84e3000000           -je 0x47845b
    if (cpu.flags.zf)
    {
        goto L_0x0047845b;
    }
    // 00478378  3b050c994d00           +cmp eax, dword ptr [0x4d990c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085452) /* 0x4d990c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047837e  0f85d7000000           -jne 0x47845b
    if (!cpu.flags.zf)
    {
        goto L_0x0047845b;
    }
    // 00478384  833d1422510001         +cmp dword ptr [0x512214], 1
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
    // 0047838b  7e0d                   -jle 0x47839a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047839a;
    }
    // 0047838d  833d9427520002         +cmp dword ptr [0x522794], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478394  0f85cb000000           -jne 0x478465
    if (!cpu.flags.zf)
    {
        goto L_0x00478465;
    }
L_0x0047839a:
    // 0047839a  83b95c01000000         +cmp dword ptr [ecx + 0x15c], 0
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
    // 004783a1  0f8cca000000           -jl 0x478471
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478471;
    }
    // 004783a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004783a9  668b914c010000         -mov dx, word ptr [ecx + 0x14c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
    // 004783b0  a300994d00             -mov dword ptr [0x4d9900], eax
    app->getMemory<x86::reg32>(x86::reg32(5085440) /* 0x4d9900 */) = cpu.eax;
    // 004783b5  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004783b8  0f85c9000000           -jne 0x478487
    if (!cpu.flags.zf)
    {
        goto L_0x00478487;
    }
    // 004783be  833dfc984d0000         +cmp dword ptr [0x4d98fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085436) /* 0x4d98fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004783c5  744c                   -je 0x478413
    if (cpu.flags.zf)
    {
        goto L_0x00478413;
    }
    // 004783c7  be44020000             -mov esi, 0x244
    cpu.esi = 580 /*0x244*/;
    // 004783cc  bb10270000             -mov ebx, 0x2710
    cpu.ebx = 10000 /*0x2710*/;
    // 004783d1  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004783d5  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004783d8  8b3d601e5100           -mov edi, dword ptr [0x511e60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5316192) /* 0x511e60 */);
    // 004783de  66f7c70100             +test di, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & 1 /*0x1*/));
    // 004783e3  0f84b5000000           -je 0x47849e
    if (cpu.flags.zf)
    {
        goto L_0x0047849e;
    }
    // 004783e9  c744241c14000000       -mov dword ptr [esp + 0x1c], 0x14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 20 /*0x14*/;
L_0x004783f1:
    // 004783f1  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004783f3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004783f7  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004783fb  e8f0fdffff             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00478400  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00478405  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478407  891530994d00           -mov dword ptr [0x4d9930], edx
    app->getMemory<x86::reg32>(x86::reg32(5085488) /* 0x4d9930 */) = cpu.edx;
    // 0047840d  891dfc984d00           -mov dword ptr [0x4d98fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085436) /* 0x4d98fc */) = cpu.ebx;
L_0x00478413:
    // 00478413  8b3508994d00           -mov esi, dword ptr [0x4d9908]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085448) /* 0x4d9908 */);
    // 00478419  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047841b  7412                   -je 0x47842f
    if (cpu.flags.zf)
    {
        goto L_0x0047842f;
    }
    // 0047841d  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00478420  893d08994d00           -mov dword ptr [0x4d9908], edi
    app->getMemory<x86::reg32>(x86::reg32(5085448) /* 0x4d9908 */) = cpu.edi;
    // 00478426  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00478428  7505                   -jne 0x47842f
    if (!cpu.flags.zf)
    {
        goto L_0x0047842f;
    }
    // 0047842a  e891fdffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
L_0x0047842f:
    // 0047842f  833dfc984d0000         +cmp dword ptr [0x4d98fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085436) /* 0x4d98fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478436  7510                   -jne 0x478448
    if (!cpu.flags.zf)
    {
        goto L_0x00478448;
    }
    // 00478438  833d00994d0000         +cmp dword ptr [0x4d9900], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085440) /* 0x4d9900 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047843f  7507                   -jne 0x478448
    if (!cpu.flags.zf)
    {
        goto L_0x00478448;
    }
    // 00478441  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478443  e814010000             -call 0x47855c
    cpu.esp -= 4;
    sub_47855c(app, cpu);
    if (cpu.terminate) return;
L_0x00478448:
    // 00478448  8b1d30994d00           -mov ebx, dword ptr [0x4d9930]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085488) /* 0x4d9930 */);
    // 0047844e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00478450  7e59                   -jle 0x4784ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004784ab;
    }
    // 00478452  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00478455  893530994d00           -mov dword ptr [0x4d9930], esi
    app->getMemory<x86::reg32>(x86::reg32(5085488) /* 0x4d9930 */) = cpu.esi;
L_0x0047845b:
    // 0047845b  83c420                 +add esp, 0x20
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
    // 0047845e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047845f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478460  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478461  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478462  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478463  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478464  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478465:
    // 00478465  e856fdffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
    // 0047846a  e821fdffff             -call 0x478190
    cpu.esp -= 4;
    sub_478190(app, cpu);
    if (cpu.terminate) return;
    // 0047846f  ebea                   -jmp 0x47845b
    goto L_0x0047845b;
L_0x00478471:
    // 00478471  e84afdffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
    // 00478476  e815fdffff             -call 0x478190
    cpu.esp -= 4;
    sub_478190(app, cpu);
    if (cpu.terminate) return;
    // 0047847b  c70500994d0001000000   -mov dword ptr [0x4d9900], 1
    app->getMemory<x86::reg32>(x86::reg32(5085440) /* 0x4d9900 */) = 1 /*0x1*/;
    // 00478485  ebd4                   -jmp 0x47845b
    goto L_0x0047845b;
L_0x00478487:
    // 00478487  e834fdffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
    // 0047848c  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00478491  e8fafcffff             -call 0x478190
    cpu.esp -= 4;
    sub_478190(app, cpu);
    if (cpu.terminate) return;
    // 00478496  892dfc984d00           -mov dword ptr [0x4d98fc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5085436) /* 0x4d98fc */) = cpu.ebp;
    // 0047849c  ebbd                   -jmp 0x47845b
    goto L_0x0047845b;
L_0x0047849e:
    // 0047849e  c744241c54010000       -mov dword ptr [esp + 0x1c], 0x154
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 340 /*0x154*/;
    // 004784a6  e946ffffff             -jmp 0x4783f1
    goto L_0x004783f1;
L_0x004784ab:
    // 004784ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004784ad  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 004784b2  e8a5040000             -call 0x47895c
    cpu.esp -= 4;
    sub_47895c(app, cpu);
    if (cpu.terminate) return;
    // 004784b7  893d30994d00           -mov dword ptr [0x4d9930], edi
    app->getMemory<x86::reg32>(x86::reg32(5085488) /* 0x4d9930 */) = cpu.edi;
    // 004784bd  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004784c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4784d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004784d0);
    // 004784d0  833df0984d0000         +cmp dword ptr [0x4d98f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085424) /* 0x4d98f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004784d7  7433                   -je 0x47850c
    if (cpu.flags.zf)
    {
        goto L_0x0047850c;
    }
    // 004784d9  3b050c994d00           +cmp eax, dword ptr [0x4d990c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085452) /* 0x4d990c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004784df  752b                   -jne 0x47850c
    if (!cpu.flags.zf)
    {
        goto L_0x0047850c;
    }
    // 004784e1  833d00994d0000         +cmp dword ptr [0x4d9900], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085440) /* 0x4d9900 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004784e8  7522                   -jne 0x47850c
    if (!cpu.flags.zf)
    {
        goto L_0x0047850c;
    }
    // 004784ea  833d1422510001         +cmp dword ptr [0x512214], 1
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
    // 004784f1  7e09                   -jle 0x4784fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004784fc;
    }
    // 004784f3  833d9427520002         +cmp dword ptr [0x522794], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004784fa  7506                   -jne 0x478502
    if (!cpu.flags.zf)
    {
        goto L_0x00478502;
    }
L_0x004784fc:
    // 004784fc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00478501  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478502:
    // 00478502  e8b9fcffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
    // 00478507  e884fcffff             -call 0x478190
    cpu.esp -= 4;
    sub_478190(app, cpu);
    if (cpu.terminate) return;
L_0x0047850c:
    // 0047850c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047850e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_478510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478510);
    // 00478510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47855c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0047855c);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047855c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047855d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047855e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047855f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478560  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478561  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478562  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00478564  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478567  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0047856a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047856c  e8cffbffff             -call 0x478140
    cpu.esp -= 4;
    sub_478140(app, cpu);
    if (cpu.terminate) return;
    // 00478571  83f802                 +cmp eax, 2
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
    // 00478574  7c41                   -jl 0x4785b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004785b7;
    }
    // 00478576  83f805                 +cmp eax, 5
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
    // 00478579  7d43                   -jge 0x4785be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004785be;
    }
    // 0047857b  bec4090000             -mov esi, 0x9c4
    cpu.esi = 2500 /*0x9c4*/;
    // 00478580  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
L_0x00478585:
    // 00478585  8b8284010000           -mov eax, dword ptr [edx + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(388) /* 0x184 */);
    // 0047858b  a3f4984d00             -mov dword ptr [0x4d98f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5085428) /* 0x4d98f4 */) = cpu.eax;
    // 00478590  48                     -dec eax
    (cpu.eax)--;
    // 00478591  83f80e                 +cmp eax, 0xe
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
    // 00478594  7707                   -ja 0x47859d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047859d;
    }
    // 00478596  ff248520854700         -jmp dword ptr [eax*4 + 0x478520]
    cpu.ip = app->getMemory<x86::reg32>(4687136 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047859d:
L_0x0047859d:
    // 0047859d  e81efcffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x004785a2:
L_0x004785a2:
    // 004785a2  893518994d00           -mov dword ptr [0x4d9918], esi
    app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */) = cpu.esi;
    // 004785a8  893d14994d00           -mov dword ptr [0x4d9914], edi
    app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */) = cpu.edi;
L_0x004785ae:
    // 004785ae  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004785b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004785b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004785b7:
    // 004785b7  e804fcffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
    // 004785bc  ebf0                   -jmp 0x4785ae
    goto L_0x004785ae;
L_0x004785be:
    // 004785be  83f80a                 +cmp eax, 0xa
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
    // 004785c1  7d0c                   -jge 0x4785cf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004785cf;
    }
    // 004785c3  beb80b0000             -mov esi, 0xbb8
    cpu.esi = 3000 /*0xbb8*/;
    // 004785c8  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
    // 004785cd  ebb6                   -jmp 0x478585
    goto L_0x00478585;
L_0x004785cf:
    // 004785cf  83f80f                 +cmp eax, 0xf
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
    // 004785d2  7d0c                   -jge 0x4785e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004785e0;
    }
    // 004785d4  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 004785d9  bf07000000             -mov edi, 7
    cpu.edi = 7 /*0x7*/;
    // 004785de  eba5                   -jmp 0x478585
    goto L_0x00478585;
L_0x004785e0:
    // 004785e0  83f814                 +cmp eax, 0x14
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
    // 004785e3  7d0c                   -jge 0x4785f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004785f1;
    }
    // 004785e5  bea00f0000             -mov esi, 0xfa0
    cpu.esi = 4000 /*0xfa0*/;
    // 004785ea  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004785ef  eb94                   -jmp 0x478585
    goto L_0x00478585;
L_0x004785f1:
    // 004785f1  83f81e                 +cmp eax, 0x1e
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
    // 004785f4  7d0c                   -jge 0x478602
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478602;
    }
    // 004785f6  be94110000             -mov esi, 0x1194
    cpu.esi = 4500 /*0x1194*/;
    // 004785fb  bf09000000             -mov edi, 9
    cpu.edi = 9 /*0x9*/;
    // 00478600  eb83                   -jmp 0x478585
    goto L_0x00478585;
L_0x00478602:
    // 00478602  83f828                 +cmp eax, 0x28
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
    // 00478605  7d0f                   -jge 0x478616
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478616;
    }
    // 00478607  be88130000             -mov esi, 0x1388
    cpu.esi = 5000 /*0x1388*/;
    // 0047860c  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 00478611  e96fffffff             -jmp 0x478585
    goto L_0x00478585;
L_0x00478616:
    // 00478616  83f83c                 +cmp eax, 0x3c
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
    // 00478619  7d0f                   -jge 0x47862a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047862a;
    }
    // 0047861b  be94110000             -mov esi, 0x1194
    cpu.esi = 4500 /*0x1194*/;
    // 00478620  bf0b000000             -mov edi, 0xb
    cpu.edi = 11 /*0xb*/;
    // 00478625  e95bffffff             -jmp 0x478585
    goto L_0x00478585;
L_0x0047862a:
    // 0047862a  83f850                 +cmp eax, 0x50
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
    // 0047862d  7d0f                   -jge 0x47863e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047863e;
    }
    // 0047862f  bea00f0000             -mov esi, 0xfa0
    cpu.esi = 4000 /*0xfa0*/;
    // 00478634  bf0c000000             -mov edi, 0xc
    cpu.edi = 12 /*0xc*/;
    // 00478639  e947ffffff             -jmp 0x478585
    goto L_0x00478585;
L_0x0047863e:
    // 0047863e  83f864                 +cmp eax, 0x64
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
    // 00478641  7d0f                   -jge 0x478652
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478652;
    }
    // 00478643  bea00f0000             -mov esi, 0xfa0
    cpu.esi = 4000 /*0xfa0*/;
    // 00478648  bf0d000000             -mov edi, 0xd
    cpu.edi = 13 /*0xd*/;
    // 0047864d  e933ffffff             -jmp 0x478585
    goto L_0x00478585;
L_0x00478652:
    // 00478652  3d8c000000             +cmp eax, 0x8c
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
    // 00478657  7d0f                   -jge 0x478668
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478668;
    }
    // 00478659  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 0047865e  bf0e000000             -mov edi, 0xe
    cpu.edi = 14 /*0xe*/;
    // 00478663  e91dffffff             -jmp 0x478585
    goto L_0x00478585;
L_0x00478668:
    // 00478668  3da4060000             +cmp eax, 0x6a4
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
    // 0047866d  7d0f                   -jge 0x47867e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047867e;
    }
    // 0047866f  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 00478674  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 00478679  e907ffffff             -jmp 0x478585
    goto L_0x00478585;
L_0x0047867e:
    // 0047867e  3dc8000000             +cmp eax, 0xc8
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
    // 00478683  7d0f                   -jge 0x478694
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478694;
    }
    // 00478685  beac0d0000             -mov esi, 0xdac
    cpu.esi = 3500 /*0xdac*/;
    // 0047868a  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 0047868f  e9f1feffff             -jmp 0x478585
    goto L_0x00478585;
L_0x00478694:
    // 00478694  beb80b0000             -mov esi, 0xbb8
    cpu.esi = 3000 /*0xbb8*/;
    // 00478699  bf11000000             -mov edi, 0x11
    cpu.edi = 17 /*0x11*/;
    // 0047869e  e9e2feffff             -jmp 0x478585
    goto L_0x00478585;
  case 0x004786a3:
    // 004786a3  8b0d10994d00           -mov ecx, dword ptr [0x4d9910]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */);
    // 004786a9  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004786ac  81eee8030000           -sub esi, 0x3e8
    (cpu.esi) -= x86::reg32(x86::sreg32(1000 /*0x3e8*/));
    // 004786b2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004786b4  7414                   -je 0x4786ca
    if (cpu.flags.zf)
    {
        goto L_0x004786ca;
    }
    // 004786b6  3b3d14994d00           +cmp edi, dword ptr [0x4d9914]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004786bc  750c                   -jne 0x4786ca
    if (!cpu.flags.zf)
    {
        goto L_0x004786ca;
    }
    // 004786be  3b3518994d00           +cmp esi, dword ptr [0x4d9918]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004786c4  0f84d8feffff           -je 0x4785a2
    if (cpu.flags.zf)
    {
        goto L_0x004785a2;
    }
L_0x004786ca:
    // 004786ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004786cc  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004786d0  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004786d4  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004786d8  dc3d50e84c00           -fdivr qword ptr [0x4ce850]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(5040208) /* 0x4ce850 */)) / cpu.fpu.st(0);
    // 004786de  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004786e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004786e1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004786e5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004786e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004786e8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004786ea  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004786ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004786ef  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004786f3  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 004786f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004786f9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004786fe  dc0558e84c00           -fadd qword ptr [0x4ce858]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5040216) /* 0x4ce858 */));
    // 00478704  c1f810                 +sar eax, 0x10
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
    // 00478707  e824de0000             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 0047870c  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00478710  e8ab9efaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478715  c70510994d0001000000   -mov dword ptr [0x4d9910], 1
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = 1 /*0x1*/;
    // 0047871f  e97efeffff             -jmp 0x4785a2
    goto L_0x004785a2;
  case 0x00478724:
    // 00478724  a110994d00             -mov eax, dword ptr [0x4d9910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */);
    // 00478729  4f                     -dec edi
    (cpu.edi)--;
    // 0047872a  81eedc050000           -sub esi, 0x5dc
    (cpu.esi) -= x86::reg32(x86::sreg32(1500 /*0x5dc*/));
    // 00478730  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478732  7414                   -je 0x478748
    if (cpu.flags.zf)
    {
        goto L_0x00478748;
    }
    // 00478734  3b3d14994d00           +cmp edi, dword ptr [0x4d9914]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047873a  750c                   -jne 0x478748
    if (!cpu.flags.zf)
    {
        goto L_0x00478748;
    }
    // 0047873c  3b3518994d00           +cmp esi, dword ptr [0x4d9918]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478742  0f845afeffff           -je 0x4785a2
    if (cpu.flags.zf)
    {
        goto L_0x004785a2;
    }
L_0x00478748:
    // 00478748  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047874a  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0047874e  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00478752  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00478756  dc3d50e84c00           -fdivr qword ptr [0x4ce850]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(5040208) /* 0x4ce850 */)) / cpu.fpu.st(0);
    // 0047875c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047875e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047875f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478764  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00478768  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478769  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047876b  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047876f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478770  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00478774  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 00478779  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047877a  dc0558e84c00           -fadd qword ptr [0x4ce858]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5040216) /* 0x4ce858 */));
    // 00478780  c1f810                 +sar eax, 0x10
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
    // 00478783  e8a8dd0000             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00478788  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047878c  e82f9efaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478791  c70510994d0001000000   -mov dword ptr [0x4d9910], 1
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = 1 /*0x1*/;
    // 0047879b  e902feffff             -jmp 0x4785a2
    goto L_0x004785a2;
  case 0x004787a0:
    // 004787a0  8b1510994d00           -mov edx, dword ptr [0x4d9910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */);
    // 004787a6  47                     -inc edi
    (cpu.edi)++;
    // 004787a7  81eef4010000           -sub esi, 0x1f4
    (cpu.esi) -= x86::reg32(x86::sreg32(500 /*0x1f4*/));
    // 004787ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004787af  7414                   -je 0x4787c5
    if (cpu.flags.zf)
    {
        goto L_0x004787c5;
    }
    // 004787b1  3b3d14994d00           +cmp edi, dword ptr [0x4d9914]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004787b7  750c                   -jne 0x4787c5
    if (!cpu.flags.zf)
    {
        goto L_0x004787c5;
    }
    // 004787b9  3b3518994d00           +cmp esi, dword ptr [0x4d9918]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004787bf  0f84ddfdffff           -je 0x4785a2
    if (cpu.flags.zf)
    {
        goto L_0x004785a2;
    }
L_0x004787c5:
    // 004787c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004787c7  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004787cb  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004787cf  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004787d3  dc3d50e84c00           -fdivr qword ptr [0x4ce850]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(5040208) /* 0x4ce850 */)) / cpu.fpu.st(0);
    // 004787d9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004787de  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004787e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004787e2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004787e6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004787ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004787eb  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004787ef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004787f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004787f2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004787f4  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 004787f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004787fa  dc0558e84c00           -fadd qword ptr [0x4ce858]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5040216) /* 0x4ce858 */));
    // 00478800  c1f810                 +sar eax, 0x10
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
    // 00478803  e828dd0000             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00478808  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047880c  e8af9dfaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478811  c70510994d0001000000   -mov dword ptr [0x4d9910], 1
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = 1 /*0x1*/;
    // 0047881b  e982fdffff             -jmp 0x4785a2
    goto L_0x004785a2;
  case 0x00478820:
    // 00478820  8b1d10994d00           -mov ebx, dword ptr [0x4d9910]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */);
    // 00478826  47                     -inc edi
    (cpu.edi)++;
    // 00478827  81c6e8030000           -add esi, 0x3e8
    (cpu.esi) += x86::reg32(x86::sreg32(1000 /*0x3e8*/));
    // 0047882d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047882f  7414                   -je 0x478845
    if (cpu.flags.zf)
    {
        goto L_0x00478845;
    }
    // 00478831  3b3d14994d00           +cmp edi, dword ptr [0x4d9914]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478837  750c                   -jne 0x478845
    if (!cpu.flags.zf)
    {
        goto L_0x00478845;
    }
    // 00478839  3b3518994d00           +cmp esi, dword ptr [0x4d9918]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047883f  0f845dfdffff           -je 0x4785a2
    if (cpu.flags.zf)
    {
        goto L_0x004785a2;
    }
L_0x00478845:
    // 00478845  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478847  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0047884b  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0047884f  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00478853  dc3d50e84c00           -fdivr qword ptr [0x4ce850]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(5040208) /* 0x4ce850 */)) / cpu.fpu.st(0);
    // 00478859  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047885b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047885c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478861  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00478865  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478866  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478868  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047886c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047886d  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00478871  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 00478876  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478877  dc0558e84c00           -fadd qword ptr [0x4ce858]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5040216) /* 0x4ce858 */));
    // 0047887d  c1f810                 +sar eax, 0x10
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
    // 00478880  e8abdc0000             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00478885  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00478889  e8329dfaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 0047888e  c70510994d0001000000   -mov dword ptr [0x4d9910], 1
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = 1 /*0x1*/;
    // 00478898  e905fdffff             -jmp 0x4785a2
    goto L_0x004785a2;
  case 0x0047889d:
    // 0047889d  8b1510994d00           -mov edx, dword ptr [0x4d9910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */);
    // 004788a3  83ef05                 -sub edi, 5
    (cpu.edi) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004788a6  81c6d0070000           -add esi, 0x7d0
    (cpu.esi) += x86::reg32(x86::sreg32(2000 /*0x7d0*/));
    // 004788ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004788ae  7414                   -je 0x4788c4
    if (cpu.flags.zf)
    {
        goto L_0x004788c4;
    }
    // 004788b0  3b3d14994d00           +cmp edi, dword ptr [0x4d9914]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085460) /* 0x4d9914 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004788b6  750c                   -jne 0x4788c4
    if (!cpu.flags.zf)
    {
        goto L_0x004788c4;
    }
    // 004788b8  3b3518994d00           +cmp esi, dword ptr [0x4d9918]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5085464) /* 0x4d9918 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004788be  0f84defcffff           -je 0x4785a2
    if (cpu.flags.zf)
    {
        goto L_0x004785a2;
    }
L_0x004788c4:
    // 004788c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004788c6  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004788ca  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004788ce  df6c2418               -fild qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004788d2  dc3d50e84c00           -fdivr qword ptr [0x4ce850]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(x86::reg32(5040208) /* 0x4ce850 */)) / cpu.fpu.st(0);
    // 004788d8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004788dd  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004788e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004788e1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004788e5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004788e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004788ea  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004788ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004788f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004788f1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004788f3  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 004788f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004788f9  dc0558e84c00           -fadd qword ptr [0x4ce858]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5040216) /* 0x4ce858 */));
    // 004788ff  c1f810                 +sar eax, 0x10
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
    // 00478902  e829dc0000             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00478907  db5c241c               +fistp dword ptr [esp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047890b  e8b09cfaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478910  c70510994d0001000000   -mov dword ptr [0x4d9910], 1
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = 1 /*0x1*/;
    // 0047891a  e983fcffff             -jmp 0x4785a2
    goto L_0x004785a2;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_47895c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0047895c);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047895c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047895d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047895e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047895f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478960  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478961  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478962  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00478965  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478967  e8d4f7ffff             -call 0x478140
    cpu.esp -= 4;
    sub_478140(app, cpu);
    if (cpu.terminate) return;
    // 0047896c  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0047896e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00478970  8b8264060000           -mov eax, dword ptr [edx + 0x664]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1636) /* 0x664 */);
    // 00478976  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00478978  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0047897b  8b0d2c994d00           -mov ecx, dword ptr [0x4d992c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085484) /* 0x4d992c */);
    // 00478981  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00478983  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00478985  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00478987  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00478989  3df0d8ffff             +cmp eax, 0xffffd8f0
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
    // 0047898e  7d05                   -jge 0x478995
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478995;
    }
    // 00478990  b8f0d8ffff             -mov eax, 0xffffd8f0
    cpu.eax = 4294957296 /*0xffffd8f0*/;
L_0x00478995:
    // 00478995  3d10270000             +cmp eax, 0x2710
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
    // 0047899a  7e05                   -jle 0x4789a1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004789a1;
    }
    // 0047899c  b810270000             -mov eax, 0x2710
    cpu.eax = 10000 /*0x2710*/;
L_0x004789a1:
    // 004789a1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004789a3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004789a5  7502                   -jne 0x4789a9
    if (!cpu.flags.zf)
    {
        goto L_0x004789a9;
    }
    // 004789a7  31c3                   -xor ebx, eax
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004789a9:
    // 004789a9  891d2c994d00           -mov dword ptr [0x4d992c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085484) /* 0x4d992c */) = cpu.ebx;
    // 004789af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004789b1  0f8c0d010000           -jl 0x478ac4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478ac4;
    }
    // 004789b7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x004789b9:
    // 004789b9  8b8268060000           -mov eax, dword ptr [edx + 0x668]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1640) /* 0x668 */);
    // 004789bf  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004789c1  8b3528994d00           -mov esi, dword ptr [0x4d9928]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085480) /* 0x4d9928 */);
    // 004789c7  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004789c9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004789cb  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004789cd  83f89c                 +cmp eax, -0x64
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
    // 004789d0  7d05                   -jge 0x4789d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004789d7;
    }
    // 004789d2  b89cffffff             -mov eax, 0xffffff9c
    cpu.eax = 4294967196 /*0xffffff9c*/;
L_0x004789d7:
    // 004789d7  83f864                 +cmp eax, 0x64
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
    // 004789da  7e05                   -jle 0x4789e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004789e1;
    }
    // 004789dc  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
L_0x004789e1:
    // 004789e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004789e3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004789e5  7502                   -jne 0x4789e9
    if (!cpu.flags.zf)
    {
        goto L_0x004789e9;
    }
    // 004789e7  31c6                   -xor esi, eax
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004789e9:
    // 004789e9  8a0d04994d00           -mov cl, byte ptr [0x4d9904]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5085444) /* 0x4d9904 */);
    // 004789ef  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 004789f1  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004789f4  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004789f6  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004789f9  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004789fb  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 004789fd  893528994d00           -mov dword ptr [0x4d9928], esi
    app->getMemory<x86::reg32>(x86::reg32(5085480) /* 0x4d9928 */) = cpu.esi;
    // 00478a03  83f964                 +cmp ecx, 0x64
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
    // 00478a06  7e05                   -jle 0x478a0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478a0d;
    }
    // 00478a08  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x00478a0d:
    // 00478a0d  8baa24030000           -mov ebp, dword ptr [edx + 0x324]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(804) /* 0x324 */);
    // 00478a13  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478a15  81fd00000100           +cmp ebp, 0x10000
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
    // 00478a1b  7e03                   -jle 0x478a20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478a20;
    }
    // 00478a1d  8d41f6                 -lea eax, [ecx - 0xa]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-10) /* -0xa */);
L_0x00478a20:
    // 00478a20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478a22  0f8ca5000000           -jl 0x478acd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478acd;
    }
    // 00478a28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00478a2a:
    // 00478a2a  8b0df4984d00           -mov ecx, dword ptr [0x4d98f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085428) /* 0x4d98f4 */);
    // 00478a30  49                     -dec ecx
    (cpu.ecx)--;
    // 00478a31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478a33  83f90e                 +cmp ecx, 0xe
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
    // 00478a36  7707                   -ja 0x478a3f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00478a3f;
    }
    // 00478a38  ff248d20894700         -jmp dword ptr [ecx*4 + 0x478920]
    cpu.ip = app->getMemory<x86::reg32>(4688160 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00478a3f:
L_0x00478a3f:
    // 00478a3f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478a41  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00478a45  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00478a49  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00478a4d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00478a50  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00478a54  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478a56  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00478a5a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00478a5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478a5f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478a61  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478a63  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00478a66  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 00478a6d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00478a71  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00478a75  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00478a79  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00478a7d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00478a7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478a81  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00478a84  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00478a88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478a89  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00478a8d  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478a8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478a90  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478a94  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00478a97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478a98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478a9a  a182795500             -mov eax, dword ptr [0x557982]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601666) /* 0x557982 */);
    // 00478a9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478aa0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478aa5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00478aa8  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00478aac  e80f9bfaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478ab1  66c7051c994d000100     -mov word ptr [0x4d991c], 1
    app->getMemory<x86::reg16>(x86::reg32(5085468) /* 0x4d991c */) = 1 /*0x1*/;
    // 00478aba  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00478abd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478abe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478abf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ac0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ac1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ac2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ac3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478ac4:
    // 00478ac4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00478ac6  f7df                   +neg edi
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
    // 00478ac8  e9ecfeffff             -jmp 0x4789b9
    goto L_0x004789b9;
L_0x00478acd:
    // 00478acd  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00478acf  e956ffffff             -jmp 0x478a2a
    goto L_0x00478a2a;
  case 0x00478ad4:
    // 00478ad4  8d42f6                 -lea eax, [edx - 0xa]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-10) /* -0xa */);
    // 00478ad7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478ad9  0f8d60ffffff           -jge 0x478a3f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478a3f;
    }
    // 00478adf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478ae1  e959ffffff             -jmp 0x478a3f
    goto L_0x00478a3f;
  case 0x00478ae6:
    // 00478ae6  83e814                 -sub eax, 0x14
    (cpu.eax) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00478ae9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478aeb  0f8d4effffff           -jge 0x478a3f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478a3f;
    }
    // 00478af1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478af3  e947ffffff             -jmp 0x478a3f
    goto L_0x00478a3f;
  case 0x00478af8:
    // 00478af8  83e81e                 -sub eax, 0x1e
    (cpu.eax) -= x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 00478afb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478afd  7c07                   -jl 0x478b06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478b06;
    }
  [[fallthrough]];
  case 0x00478aff:
    // 00478aff  f7d8                   +neg eax
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
    // 00478b01  e939ffffff             -jmp 0x478a3f
    goto L_0x00478a3f;
L_0x00478b06:
    // 00478b06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478b08  f7d8                   +neg eax
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
    // 00478b0a  e930ffffff             -jmp 0x478a3f
    goto L_0x00478a3f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_478b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478b10);
    // 00478b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478b15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478b16  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478b19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478b1b  8a1d24994d00           -mov bl, byte ptr [0x4d9924]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5085476) /* 0x4d9924 */);
    // 00478b21  e8aaf9ffff             -call 0x4784d0
    cpu.esp -= 4;
    sub_4784d0(app, cpu);
    if (cpu.terminate) return;
    // 00478b26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478b28  7436                   -je 0x478b60
    if (cpu.flags.zf)
    {
        goto L_0x00478b60;
    }
    // 00478b2a  803d24994d0064         +cmp byte ptr [0x4d9924], 0x64
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085476) /* 0x4d9924 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478b31  7437                   -je 0x478b6a
    if (cpu.flags.zf)
    {
        goto L_0x00478b6a;
    }
    // 00478b33  8b8ab8020000           -mov ecx, dword ptr [edx + 0x2b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
    // 00478b39  81f999190000           +cmp ecx, 0x1999
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
    // 00478b3f  7c1f                   -jl 0x478b60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478b60;
    }
    // 00478b41  8a82da020000           -mov al, byte ptr [edx + 0x2da]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(730) /* 0x2da */);
    // 00478b47  a224994d00             -mov byte ptr [0x4d9924], al
    app->getMemory<x86::reg8>(x86::reg32(5085476) /* 0x4d9924 */) = cpu.al;
    // 00478b4c  3c02                   +cmp al, 2
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
    // 00478b4e  0f837c000000           -jae 0x478bd0
    if (!cpu.flags.cf)
    {
        goto L_0x00478bd0;
    }
    // 00478b54  3c01                   +cmp al, 1
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
    // 00478b56  7408                   -je 0x478b60
    if (cpu.flags.zf)
    {
        goto L_0x00478b60;
    }
    // 00478b58  81f900000100           +cmp ecx, 0x10000
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
    // 00478b5e  7f17                   -jg 0x478b77
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00478b77;
    }
L_0x00478b60:
    // 00478b60  83c420                 +add esp, 0x20
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
    // 00478b63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478b6a:
    // 00478b6a  8a82da020000           -mov al, byte ptr [edx + 0x2da]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(730) /* 0x2da */);
    // 00478b70  a224994d00             -mov byte ptr [0x4d9924], al
    app->getMemory<x86::reg8>(x86::reg32(5085476) /* 0x4d9924 */) = cpu.al;
    // 00478b75  ebe9                   -jmp 0x478b60
    goto L_0x00478b60;
L_0x00478b77:
    // 00478b77  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00478b7c  be88130000             -mov esi, 0x1388
    cpu.esi = 5000 /*0x1388*/;
    // 00478b81  b8409c0000             -mov eax, 0x9c40
    cpu.eax = 40000 /*0x9c40*/;
    // 00478b86  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478b8b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00478b8d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478b8f  891d08994d00           -mov dword ptr [0x4d9908], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085448) /* 0x4d9908 */) = cpu.ebx;
    // 00478b95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478b96  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00478b9a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00478b9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478b9f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00478ba3  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00478ba7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478ba8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478baa  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 00478baf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478bb0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00478bb3  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00478bb7  e8049afaff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00478bbc  c70510994d0001000000   -mov dword ptr [0x4d9910], 1
    app->getMemory<x86::reg32>(x86::reg32(5085456) /* 0x4d9910 */) = 1 /*0x1*/;
    // 00478bc6  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478bc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478bd0:
    // 00478bd0  38c3                   +cmp bl, al
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
    // 00478bd2  7640                   -jbe 0x478c14
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00478c14;
    }
    // 00478bd4  c7442418b5000000       -mov dword ptr [esp + 0x18], 0xb5
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 181 /*0xb5*/;
L_0x00478bdc:
    // 00478bdc  8bbaf0020000           -mov edi, dword ptr [edx + 0x2f0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(752) /* 0x2f0 */);
    // 00478be2  81ffd0070000           +cmp edi, 0x7d0
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
    // 00478be8  7d34                   -jge 0x478c1e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478c1e;
    }
    // 00478bea  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00478bef  b868100000             -mov eax, 0x1068
    cpu.eax = 4200 /*0x1068*/;
    // 00478bf4  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00478bf8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00478bfb:
    // 00478bfb  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00478bfd  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00478c01  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00478c05  e8e6f5ffff             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00478c0a  83c420                 +add esp, 0x20
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
    // 00478c0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478c14:
    // 00478c14  c744241801000000       -mov dword ptr [esp + 0x18], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 1 /*0x1*/;
    // 00478c1c  ebbe                   -jmp 0x478bdc
    goto L_0x00478bdc;
L_0x00478c1e:
    // 00478c1e  81ffb80b0000           +cmp edi, 0xbb8
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
    // 00478c24  7d13                   -jge 0x478c39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478c39;
    }
    // 00478c26  bd96000000             -mov ebp, 0x96
    cpu.ebp = 150 /*0x96*/;
    // 00478c2b  bf50140000             -mov edi, 0x1450
    cpu.edi = 5200 /*0x1450*/;
    // 00478c30  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 00478c34  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00478c37  ebc2                   -jmp 0x478bfb
    goto L_0x00478bfb;
L_0x00478c39:
    // 00478c39  81ffa00f0000           +cmp edi, 0xfa0
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
    // 00478c3f  7d13                   -jge 0x478c54
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478c54;
    }
    // 00478c41  bec8000000             -mov esi, 0xc8
    cpu.esi = 200 /*0xc8*/;
    // 00478c46  bb38180000             -mov ebx, 0x1838
    cpu.ebx = 6200 /*0x1838*/;
    // 00478c4b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00478c4f  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00478c52  eba7                   -jmp 0x478bfb
    goto L_0x00478bfb;
L_0x00478c54:
    // 00478c54  b9fa000000             -mov ecx, 0xfa
    cpu.ecx = 250 /*0xfa*/;
    // 00478c59  ba201c0000             -mov edx, 0x1c20
    cpu.edx = 7200 /*0x1c20*/;
    // 00478c5e  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00478c62  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00478c65  eb94                   -jmp 0x478bfb
    goto L_0x00478bfb;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478c70);
    // 00478c70  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478c73  e858f8ffff             -call 0x4784d0
    cpu.esp -= 4;
    sub_4784d0(app, cpu);
    if (cpu.terminate) return;
    // 00478c78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478c7a  7504                   -jne 0x478c80
    if (!cpu.flags.zf)
    {
        goto L_0x00478c80;
    }
    // 00478c7c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478c7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478c80:
    // 00478c80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478c81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478c82  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478c83  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 00478c88  b95a000000             -mov ecx, 0x5a
    cpu.ecx = 90 /*0x5a*/;
    // 00478c8d  bb0e010000             -mov ebx, 0x10e
    cpu.ebx = 270 /*0x10e*/;
    // 00478c92  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00478c96  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00478c9a  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00478c9e  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478ca2  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00478ca6  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00478caa  e841f5ffff             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00478caf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cb2  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478cb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478cc0);
    // 00478cc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478cc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478cc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478cc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478cc4  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478cc7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478cc9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00478ccb  e800f8ffff             -call 0x4784d0
    cpu.esp -= 4;
    sub_4784d0(app, cpu);
    if (cpu.terminate) return;
    // 00478cd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478cd2  7508                   -jne 0x478cdc
    if (!cpu.flags.zf)
    {
        goto L_0x00478cdc;
    }
L_0x00478cd4:
    // 00478cd4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478cd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478cdc:
    // 00478cdc  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00478cdf  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00478ce6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478ce8  8b15a4185100           -mov edx, dword ptr [0x5118a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 00478cee  8b54820c               -mov edx, dword ptr [edx + eax*4 + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 00478cf2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00478cf5  8b81dc000000           -mov eax, dword ptr [ecx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 00478cfb  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00478cfd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478d00  c1e810                 +shr eax, 0x10
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
    // 00478d03  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00478d05  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00478d08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478d0a  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00478d11  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478d13  8b15a4185100           -mov edx, dword ptr [0x5118a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 00478d19  8b54820d               -mov edx, dword ptr [edx + eax*4 + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */ + cpu.eax * 4);
    // 00478d1d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00478d20  8b81e0000000           -mov eax, dword ptr [ecx + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 00478d26  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00478d28  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478d2b  c1e810                 +shr eax, 0x10
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
    // 00478d2e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00478d30  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00478d33  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478d35  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00478d3c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478d3e  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 00478d43  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00478d46  8b54020e               -mov edx, dword ptr [edx + eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */ + cpu.eax * 1);
    // 00478d4a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00478d4d  8b81e4000000           -mov eax, dword ptr [ecx + 0xe4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 00478d53  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00478d55  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00478d58  c1e810                 +shr eax, 0x10
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
    // 00478d5b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00478d5d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00478d5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478d61  7c40                   -jl 0x478da3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478da3;
    }
L_0x00478d63:
    // 00478d63  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00478d65  7e44                   -jle 0x478dab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478dab;
    }
    // 00478d67  c744241c5a000000       -mov dword ptr [esp + 0x1c], 0x5a
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 90 /*0x5a*/;
L_0x00478d6f:
    // 00478d6f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478d71  e8caf3ffff             -call 0x478140
    cpu.esp -= 4;
    sub_478140(app, cpu);
    if (cpu.terminate) return;
    // 00478d76  83f828                 +cmp eax, 0x28
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
    // 00478d79  7e54                   -jle 0x478dcf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478dcf;
    }
    // 00478d7b  bbc8000000             -mov ebx, 0xc8
    cpu.ebx = 200 /*0xc8*/;
    // 00478d80  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00478d85  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00478d89  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
L_0x00478d8c:
    // 00478d8c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00478d8e  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00478d92  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00478d96  e855f4ffff             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00478d9b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478d9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478da0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478da1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478da2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478da3:
    // 00478da3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00478da5  74bc                   -je 0x478d63
    if (cpu.flags.zf)
    {
        goto L_0x00478d63;
    }
    // 00478da7  f7db                   +neg ebx
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
    // 00478da9  ebb8                   -jmp 0x478d63
    goto L_0x00478d63;
L_0x00478dab:
    // 00478dab  7d0a                   -jge 0x478db7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478db7;
    }
    // 00478dad  c744241c0e010000       -mov dword ptr [esp + 0x1c], 0x10e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 270 /*0x10e*/;
    // 00478db5  ebb8                   -jmp 0x478d6f
    goto L_0x00478d6f;
L_0x00478db7:
    // 00478db7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478db9  e882f3ffff             -call 0x478140
    cpu.esp -= 4;
    sub_478140(app, cpu);
    if (cpu.terminate) return;
    // 00478dbe  83f805                 +cmp eax, 5
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
    // 00478dc1  0f8e0dffffff           -jle 0x478cd4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478cd4;
    }
    // 00478dc7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00478dc9  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00478dcd  eba0                   -jmp 0x478d6f
    goto L_0x00478d6f;
L_0x00478dcf:
    // 00478dcf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478dd1  e86af3ffff             -call 0x478140
    cpu.esp -= 4;
    sub_478140(app, cpu);
    if (cpu.terminate) return;
    // 00478dd6  83f814                 +cmp eax, 0x14
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
    // 00478dd9  7e13                   -jle 0x478dee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478dee;
    }
    // 00478ddb  ba2c010000             -mov edx, 0x12c
    cpu.edx = 300 /*0x12c*/;
    // 00478de0  b828230000             -mov eax, 0x2328
    cpu.eax = 9000 /*0x2328*/;
    // 00478de5  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00478de9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00478dec  eb9e                   -jmp 0x478d8c
    goto L_0x00478d8c;
L_0x00478dee:
    // 00478dee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478def  bd90010000             -mov ebp, 0x190
    cpu.ebp = 400 /*0x190*/;
    // 00478df4  bf581b0000             -mov edi, 0x1b58
    cpu.edi = 7000 /*0x1b58*/;
    // 00478df9  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 00478dfd  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00478e01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e02  eb88                   -jmp 0x478d8c
    goto L_0x00478d8c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478e10);
    // 00478e10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478e11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478e12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478e13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478e14  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478e17  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00478e1b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478e1d  8b350c225100           -mov esi, dword ptr [0x51220c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 00478e23  3bb0e8010000           +cmp esi, dword ptr [eax + 0x1e8]
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
    // 00478e29  0f85bd000000           -jne 0x478eec
    if (!cpu.flags.zf)
    {
        goto L_0x00478eec;
    }
    // 00478e2f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00478e31:
    // 00478e31  e89af6ffff             -call 0x4784d0
    cpu.esp -= 4;
    sub_4784d0(app, cpu);
    if (cpu.terminate) return;
    // 00478e36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478e38  0f84b5000000           -je 0x478ef3
    if (cpu.flags.zf)
    {
        goto L_0x00478ef3;
    }
L_0x00478e3e:
    // 00478e3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478e3f  81fb00200000           +cmp ebx, 0x2000
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
    // 00478e45  0f8db8000000           -jge 0x478f03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478f03;
    }
    // 00478e4b  b9401f0000             -mov ecx, 0x1f40
    cpu.ecx = 8000 /*0x1f40*/;
    // 00478e50  b88a020000             -mov eax, 0x28a
    cpu.eax = 650 /*0x28a*/;
L_0x00478e55:
    // 00478e55  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00478e59  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00478e5d:
    // 00478e5d  8b1df8984d00           -mov ebx, dword ptr [0x4d98f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085432) /* 0x4d98f8 */);
    // 00478e63  8b35f8984d00           -mov esi, dword ptr [0x4d98f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085432) /* 0x4d98f8 */);
    // 00478e69  8b829c000000           -mov eax, dword ptr [edx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */);
    // 00478e6f  8baa9c000000           -mov ebp, dword ptr [edx + 0x9c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */);
    // 00478e75  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478e77  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478e79  8b8270010000           -mov eax, dword ptr [edx + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(368) /* 0x170 */);
    // 00478e7f  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00478e81  39e8                   +cmp eax, ebp
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
    // 00478e83  0f8ee6000000           -jle 0x478f6f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f6f;
    }
    // 00478e89  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00478e8e:
    // 00478e8e  8b8278010000           -mov eax, dword ptr [edx + 0x178]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(376) /* 0x178 */);
    // 00478e94  3b82a4000000           +cmp eax, dword ptr [edx + 0xa4]
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
    // 00478e9a  0f8ed6000000           -jle 0x478f76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f76;
    }
    // 00478ea0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00478ea5:
    // 00478ea5  8baa70010000           -mov ebp, dword ptr [edx + 0x170]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(368) /* 0x170 */);
    // 00478eab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478ead  39eb                   +cmp ebx, ebp
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
    // 00478eaf  0f8dc8000000           -jge 0x478f7d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478f7d;
    }
L_0x00478eb5:
    // 00478eb5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00478eba:
    // 00478eba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00478ebc  0f84e2000000           -je 0x478fa4
    if (cpu.flags.zf)
    {
        goto L_0x00478fa4;
    }
    // 00478ec2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478ec4  0f84c2000000           -je 0x478f8c
    if (cpu.flags.zf)
    {
        goto L_0x00478f8c;
    }
    // 00478eca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478ecc:
    // 00478ecc  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00478ed0  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00478ed4  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00478ed8  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00478edc  e80ff3ffff             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00478ee1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478ee2:
    // 00478ee2  83c420                 +add esp, 0x20
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
    // 00478ee5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ee6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ee7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ee8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ee9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00478eec:
    // 00478eec  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00478eee  e93effffff             -jmp 0x478e31
    goto L_0x00478e31;
L_0x00478ef3:
    // 00478ef3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478ef5  e8d6f5ffff             -call 0x4784d0
    cpu.esp -= 4;
    sub_4784d0(app, cpu);
    if (cpu.terminate) return;
    // 00478efa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478efc  74e4                   -je 0x478ee2
    if (cpu.flags.zf)
    {
        goto L_0x00478ee2;
    }
    // 00478efe  e93bffffff             -jmp 0x478e3e
    goto L_0x00478e3e;
L_0x00478f03:
    // 00478f03  81fb00500000           +cmp ebx, 0x5000
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
    // 00478f09  7d17                   -jge 0x478f22
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478f22;
    }
    // 00478f0b  bd34210000             -mov ebp, 0x2134
    cpu.ebp = 8500 /*0x2134*/;
    // 00478f10  bff4010000             -mov edi, 0x1f4
    cpu.edi = 500 /*0x1f4*/;
    // 00478f15  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478f19  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00478f1d  e93bffffff             -jmp 0x478e5d
    goto L_0x00478e5d;
L_0x00478f22:
    // 00478f22  81fb00000100           +cmp ebx, 0x10000
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
    // 00478f28  7d17                   -jge 0x478f41
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478f41;
    }
    // 00478f2a  be28230000             -mov esi, 0x2328
    cpu.esi = 9000 /*0x2328*/;
    // 00478f2f  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 00478f34  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00478f38  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00478f3c  e91cffffff             -jmp 0x478e5d
    goto L_0x00478e5d;
L_0x00478f41:
    // 00478f41  81fb00001000           +cmp ebx, 0x100000
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
    // 00478f47  7d0f                   -jge 0x478f58
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478f58;
    }
    // 00478f49  b91c250000             -mov ecx, 0x251c
    cpu.ecx = 9500 /*0x251c*/;
    // 00478f4e  b85e010000             -mov eax, 0x15e
    cpu.eax = 350 /*0x15e*/;
    // 00478f53  e9fdfeffff             -jmp 0x478e55
    goto L_0x00478e55;
L_0x00478f58:
    // 00478f58  bd10270000             -mov ebp, 0x2710
    cpu.ebp = 10000 /*0x2710*/;
    // 00478f5d  bf5e010000             -mov edi, 0x15e
    cpu.edi = 350 /*0x15e*/;
    // 00478f62  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478f66  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00478f6a  e9eefeffff             -jmp 0x478e5d
    goto L_0x00478e5d;
L_0x00478f6f:
    // 00478f6f  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00478f71  e918ffffff             -jmp 0x478e8e
    goto L_0x00478e8e;
L_0x00478f76:
    // 00478f76  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478f78  e928ffffff             -jmp 0x478ea5
    goto L_0x00478ea5;
L_0x00478f7d:
    // 00478f7d  39ef                   +cmp edi, ebp
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
    // 00478f7f  0f8f30ffffff           -jg 0x478eb5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00478eb5;
    }
    // 00478f85  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478f87  e92effffff             -jmp 0x478eba
    goto L_0x00478eba;
L_0x00478f8c:
    // 00478f8c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00478f8e  740a                   -je 0x478f9a
    if (cpu.flags.zf)
    {
        goto L_0x00478f9a;
    }
    // 00478f90  b82d000000             -mov eax, 0x2d
    cpu.eax = 45 /*0x2d*/;
    // 00478f95  e932ffffff             -jmp 0x478ecc
    goto L_0x00478ecc;
L_0x00478f9a:
    // 00478f9a  b83b010000             -mov eax, 0x13b
    cpu.eax = 315 /*0x13b*/;
    // 00478f9f  e928ffffff             -jmp 0x478ecc
    goto L_0x00478ecc;
L_0x00478fa4:
    // 00478fa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478fa6  740a                   -je 0x478fb2
    if (cpu.flags.zf)
    {
        goto L_0x00478fb2;
    }
    // 00478fa8  b8b4000000             -mov eax, 0xb4
    cpu.eax = 180 /*0xb4*/;
    // 00478fad  e91affffff             -jmp 0x478ecc
    goto L_0x00478ecc;
L_0x00478fb2:
    // 00478fb2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00478fb4  740a                   -je 0x478fc0
    if (cpu.flags.zf)
    {
        goto L_0x00478fc0;
    }
    // 00478fb6  b887000000             -mov eax, 0x87
    cpu.eax = 135 /*0x87*/;
    // 00478fbb  e90cffffff             -jmp 0x478ecc
    goto L_0x00478ecc;
L_0x00478fc0:
    // 00478fc0  b8e1000000             -mov eax, 0xe1
    cpu.eax = 225 /*0xe1*/;
    // 00478fc5  e902ffffff             -jmp 0x478ecc
    goto L_0x00478ecc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_478fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00478fd0);
    // 00478fd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478fd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478fd2  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478fd5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478fd7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00478fd9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00478fdb  e8f0f4ffff             -call 0x4784d0
    cpu.esp -= 4;
    sub_4784d0(app, cpu);
    if (cpu.terminate) return;
    // 00478fe0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478fe2  7506                   -jne 0x478fea
    if (!cpu.flags.zf)
    {
        goto L_0x00478fea;
    }
L_0x00478fe4:
    // 00478fe4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00478fe7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fe8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fe9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478fea:
    // 00478fea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478fec  e84ff1ffff             -call 0x478140
    cpu.esp -= 4;
    sub_478140(app, cpu);
    if (cpu.terminate) return;
    // 00478ff1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478ff3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478ff5  74ed                   -je 0x478fe4
    if (cpu.flags.zf)
    {
        goto L_0x00478fe4;
    }
    // 00478ff7  be58020000             -mov esi, 0x258
    cpu.esi = 600 /*0x258*/;
    // 00478ffc  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00478ffe  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00479000  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00479004  81fec8000000           +cmp esi, 0xc8
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
    // 0047900a  7308                   -jae 0x479014
    if (!cpu.flags.cf)
    {
        goto L_0x00479014;
    }
    // 0047900c  c7442418c8000000       -mov dword ptr [esp + 0x18], 0xc8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 200 /*0xc8*/;
L_0x00479014:
    // 00479014  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00479016  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00479019  0534210000             -add eax, 0x2134
    (cpu.eax) += x86::reg32(x86::sreg32(8500 /*0x2134*/));
    // 0047901e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00479021  3d10270000             +cmp eax, 0x2710
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
    // 00479026  7e07                   -jle 0x47902f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047902f;
    }
    // 00479028  c7042410270000         -mov dword ptr [esp], 0x2710
    app->getMemory<x86::reg32>(cpu.esp) = 10000 /*0x2710*/;
L_0x0047902f:
    // 0047902f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479031  7e3c                   -jle 0x47906f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047906f;
    }
    // 00479033  c744241c1e000000       -mov dword ptr [esp + 0x1c], 0x1e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 30 /*0x1e*/;
L_0x0047903b:
    // 0047903b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047903d  751b                   -jne 0x47905a
    if (!cpu.flags.zf)
    {
        goto L_0x0047905a;
    }
    // 0047903f  b864190000             -mov eax, 0x1964
    cpu.eax = 6500 /*0x1964*/;
    // 00479044  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00479047  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479049  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047904d  81eb5e010000           -sub ebx, 0x15e
    (cpu.ebx) -= x86::reg32(x86::sreg32(350 /*0x15e*/));
    // 00479053  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00479056  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
L_0x0047905a:
    // 0047905a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047905c  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479060  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479064  e887f1ffff             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00479069  83c420                 +add esp, 0x20
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
    // 0047906c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047906d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047906e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047906f:
    // 0047906f  c744241c4a010000       -mov dword ptr [esp + 0x1c], 0x14a
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 330 /*0x14a*/;
    // 00479077  ebc2                   -jmp 0x47903b
    goto L_0x0047903b;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479080);
    // 00479080  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479087  7501                   -jne 0x47908a
    if (!cpu.flags.zf)
    {
        goto L_0x0047908a;
    }
    // 00479089  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047908a:
    // 0047908a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047908b  e830f1ffff             -call 0x4781c0
    cpu.esp -= 4;
    sub_4781c0(app, cpu);
    if (cpu.terminate) return;
    // 00479090  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479092  e8f9f0ffff             -call 0x478190
    cpu.esp -= 4;
    sub_478190(app, cpu);
    if (cpu.terminate) return;
    // 00479097  890de4795500           -mov dword ptr [0x5579e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5601764) /* 0x5579e4 */) = cpu.ecx;
    // 0047909d  890d20994d00           -mov dword ptr [0x4d9920], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085472) /* 0x4d9920 */) = cpu.ecx;
    // 004790a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004790a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4790e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004790e0);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004790e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004790e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004790e2  e8cd000000             -call 0x4791b4
    cpu.esp -= 4;
    sub_4791b4(app, cpu);
    if (cpu.terminate) return;
    // 004790e7  8b1c85081d5100         -mov ebx, dword ptr [eax*4 + 0x511d08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5315848) /* 0x511d08 */ + cpu.eax * 4);
    // 004790ee  e8cdefffff             -call 0x4780c0
    cpu.esp -= 4;
    sub_4780c0(app, cpu);
    if (cpu.terminate) return;
    // 004790f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004790f5  0f848a000000           -je 0x479185
    if (cpu.flags.zf)
    {
        goto L_0x00479185;
    }
    // 004790fb  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479102  0f847d000000           -je 0x479185
    if (cpu.flags.zf)
    {
        goto L_0x00479185;
    }
    // 00479108  803dd42e510000         +cmp byte ptr [0x512ed4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320404) /* 0x512ed4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047910f  7474                   -je 0x479185
    if (cpu.flags.zf)
    {
        goto L_0x00479185;
    }
    // 00479111  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479112  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479113  8b9308010000           -mov edx, dword ptr [ebx + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(264) /* 0x108 */);
    // 00479119  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047911b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047911e  c1e202                 +shl edx, 2
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
    // 00479121  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479123  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00479126  a3f8984d00             -mov dword ptr [0x4d98f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085432) /* 0x4d98f8 */) = cpu.eax;
    // 0047912b  8b831c020000           -mov eax, dword ptr [ebx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(540) /* 0x21c */);
    // 00479131  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00479136  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00479138  890df0984d00           -mov dword ptr [0x4d98f0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085424) /* 0x4d98f0 */) = cpu.ecx;
    // 0047913e  83f80b                 +cmp eax, 0xb
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
    // 00479141  774d                   -ja 0x479190
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00479190;
    }
    // 00479143  ff2485b0904700         -jmp dword ptr [eax*4 + 0x4790b0]
    cpu.ip = app->getMemory<x86::reg32>(4690096 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047914a:
    // 0047914a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047914b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047914d  893d04994d00           -mov dword ptr [0x4d9904], edi
    app->getMemory<x86::reg32>(x86::reg32(5085444) /* 0x4d9904 */) = cpu.edi;
    // 00479153  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479154:
    // 00479154  e85b000000             -call 0x4791b4
    cpu.esp -= 4;
    sub_4791b4(app, cpu);
    if (cpu.terminate) return;
    // 00479159  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0047915e  8b0485081d5100         -mov eax, dword ptr [eax*4 + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315848) /* 0x511d08 */ + cpu.eax * 4);
    // 00479165  ba60834700             -mov edx, 0x478360
    cpu.edx = 4686688 /*0x478360*/;
    // 0047916a  a30c994d00             -mov dword ptr [0x4d990c], eax
    app->getMemory<x86::reg32>(x86::reg32(5085452) /* 0x4d990c */) = cpu.eax;
    // 0047916f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479171  a1540f5400             -mov eax, dword ptr [0x540f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508948) /* 0x540f54 */);
    // 00479176  e86583ffff             -call 0x4714e0
    cpu.esp -= 4;
    sub_4714e0(app, cpu);
    if (cpu.terminate) return;
    // 0047917b  e800ffffff             -call 0x479080
    cpu.esp -= 4;
    sub_479080(app, cpu);
    if (cpu.terminate) return;
    // 00479180  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479181  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479184  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479185:
    // 00479185  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00479187  892df0984d00           -mov dword ptr [0x4d98f0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5085424) /* 0x4d98f0 */) = cpu.ebp;
    // 0047918d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047918e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047918f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00479190:
L_0x00479190:
    // 00479190  c70504994d0001000000   -mov dword ptr [0x4d9904], 1
    app->getMemory<x86::reg32>(x86::reg32(5085444) /* 0x4d9904 */) = 1 /*0x1*/;
    // 0047919a  ebb8                   -jmp 0x479154
    goto L_0x00479154;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4791b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004791b4);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004791b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004791b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004791b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004791b7  a108225100             -mov eax, dword ptr [0x512208]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 004791bc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004791be  83f804                 +cmp eax, 4
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
    // 004791c1  770d                   -ja 0x4791d0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004791d0;
    }
    // 004791c3  ff2485a0914700         -jmp dword ptr [eax*4 + 0x4791a0]
    cpu.ip = app->getMemory<x86::reg32>(4690336 + cpu.eax * 4); goto dynamic_jump;
  case 0x004791ca:
    // 004791ca  8b1d0c225100           -mov ebx, dword ptr [0x51220c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
L_0x004791d0:
    // 004791d0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004791d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004791d5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004791d6:
    // 004791d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004791d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004791da:
    // 004791da  8b8a1c204d00           -mov ecx, dword ptr [edx + 0x4d201c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5054492) /* 0x4d201c */);
    // 004791e0  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004791e2  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004791e8  83f903                 +cmp ecx, 3
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
    // 004791eb  750b                   -jne 0x4791f8
    if (!cpu.flags.zf)
    {
        goto L_0x004791f8;
    }
    // 004791ed  40                     -inc eax
    (cpu.eax)++;
    // 004791ee  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004791f1  83f814                 +cmp eax, 0x14
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
    // 004791f4  7dda                   -jge 0x4791d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004791d0;
    }
    // 004791f6  ebe2                   -jmp 0x4791da
    goto L_0x004791da;
L_0x004791f8:
    // 004791f8  83f809                 +cmp eax, 9
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
    // 004791fb  7e12                   -jle 0x47920f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047920f;
    }
    // 004791fd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00479202  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00479204  40                     -inc eax
    (cpu.eax)++;
    // 00479205  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479208  83f814                 +cmp eax, 0x14
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
    // 0047920b  7dc3                   -jge 0x4791d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004791d0;
    }
    // 0047920d  ebcb                   -jmp 0x4791da
    goto L_0x004791da;
L_0x0047920f:
    // 0047920f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479211  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00479213  40                     -inc eax
    (cpu.eax)++;
    // 00479214  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479217  83f814                 +cmp eax, 0x14
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
    // 0047921a  7db4                   -jge 0x4791d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004791d0;
    }
    // 0047921c  ebbc                   -jmp 0x4791da
    goto L_0x004791da;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_479220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479220);
    // 00479220  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479227  7501                   -jne 0x47922a
    if (!cpu.flags.zf)
    {
        goto L_0x0047922a;
    }
    // 00479229  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047922a:
    // 0047922a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0047922f  e95c9cfaff             -jmp 0x422e90
    return sub_422e90(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479240);
    // 00479240  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479247  7501                   -jne 0x47924a
    if (!cpu.flags.zf)
    {
        goto L_0x0047924a;
    }
    // 00479249  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047924a:
    // 0047924a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0047924f  e99c9cfaff             -jmp 0x422ef0
    return sub_422ef0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479260);
    // 00479260  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479267  7501                   -jne 0x47926a
    if (!cpu.flags.zf)
    {
        goto L_0x0047926a;
    }
    // 00479269  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047926a:
    // 0047926a  e811feffff             -call 0x479080
    cpu.esp -= 4;
    sub_479080(app, cpu);
    if (cpu.terminate) return;
    // 0047926f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00479274  e8e79cfaff             -call 0x422f60
    cpu.esp -= 4;
    sub_422f60(app, cpu);
    if (cpu.terminate) return;
    // 00479279  e9a2ffffff             -jmp 0x479220
    return sub_479220(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_479280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479280);
    // 00479280  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479287  7501                   -jne 0x47928a
    if (!cpu.flags.zf)
    {
        goto L_0x0047928a;
    }
    // 00479289  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047928a:
    // 0047928a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0047928f  e9cc9cfaff             -jmp 0x422f60
    return sub_422f60(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4792a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004792a0);
    // 004792a0  833dec984d0000         +cmp dword ptr [0x4d98ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004792a7  7501                   -jne 0x4792aa
    if (!cpu.flags.zf)
    {
        goto L_0x004792aa;
    }
    // 004792a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004792aa:
    // 004792aa  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004792af  e90c9dfaff             -jmp 0x422fc0
    return sub_422fc0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4792c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004792c0);
    // 004792c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004792c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004792c3  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004792c8  e8939afaff             -call 0x422d60
    cpu.esp -= 4;
    sub_422d60(app, cpu);
    if (cpu.terminate) return;
    // 004792cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004792ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4792d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004792d0);
    // 004792d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004792d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004792d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004792d3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004792d6  c60424ff               -mov byte ptr [esp], 0xff
    app->getMemory<x86::reg8>(cpu.esp) = 255 /*0xff*/;
    // 004792da  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 004792df  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004792e2  e80996faff             -call 0x4228f0
    cpu.esp -= 4;
    sub_4228f0(app, cpu);
    if (cpu.terminate) return;
    // 004792e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004792e9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004792ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004792ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004792f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004792f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004792f4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004792f6  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 004792fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004792fd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479300  e8bb92faff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 00479305  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479308  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479309  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047930a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047930b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_479310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479310);
    // 00479310  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479311  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479313  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00479318  e8439afaff             -call 0x422d60
    cpu.esp -= 4;
    sub_422d60(app, cpu);
    if (cpu.terminate) return;
    // 0047931d  66833d1e994d0000       +cmp word ptr [0x4d991e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5085470) /* 0x4d991e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00479325  7402                   -je 0x479329
    if (cpu.flags.zf)
    {
        goto L_0x00479329;
    }
    // 00479327  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479328  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479329:
    // 00479329  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 0047932e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479331  e87a96faff             -call 0x4229b0
    cpu.esp -= 4;
    sub_4229b0(app, cpu);
    if (cpu.terminate) return;
    // 00479336  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479337  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479340);
    // 00479340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479343  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479344  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00479347  baffffff00             -mov edx, 0xffffff
    cpu.edx = 16777215 /*0xffffff*/;
    // 0047934c  b988130000             -mov ecx, 0x1388
    cpu.ecx = 5000 /*0x1388*/;
    // 00479351  bfe4720000             -mov edi, 0x72e4
    cpu.edi = 29412 /*0x72e4*/;
    // 00479356  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479358  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047935a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047935e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00479361  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00479365  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00479369  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047936d  668b151e994d00         -mov dx, word ptr [0x4d991e]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5085470) /* 0x4d991e */);
    // 00479374  8864241c               -mov byte ptr [esp + 0x1c], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ah;
    // 00479378  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0047937b  742e                   -je 0x4793ab
    if (cpu.flags.zf)
    {
        goto L_0x004793ab;
    }
    // 0047937d  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x0047937f:
    // 0047937f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479381  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479385  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479389  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047938a  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047938e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479391  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00479394  a180795500             -mov eax, dword ptr [0x557980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5601664) /* 0x557980 */);
    // 00479399  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047939b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047939e  e81d92faff             -call 0x4225c0
    cpu.esp -= 4;
    sub_4225c0(app, cpu);
    if (cpu.terminate) return;
    // 004793a3  83c420                 +add esp, 0x20
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
    // 004793a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004793ab:
    // 004793ab  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004793ad  ebd0                   -jmp 0x47937f
    goto L_0x0047937f;
}

/* align: skip 0x00 */
void Application::sub_4793b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004793b0);
    // 004793b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004793b1  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 004793b6  8b15ec984d00           -mov edx, dword ptr [0x4d98ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */);
    // 004793bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004793be  7407                   -je 0x4793c7
    if (cpu.flags.zf)
    {
        goto L_0x004793c7;
    }
    // 004793c0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004793c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004793c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004793c7:
    // 004793c7  e8748efcff             -call 0x442240
    cpu.esp -= 4;
    sub_442240(app, cpu);
    if (cpu.terminate) return;
    // 004793cc  e84f9cfaff             -call 0x423020
    cpu.esp -= 4;
    sub_423020(app, cpu);
    if (cpu.terminate) return;
    // 004793d1  a3ec984d00             -mov dword ptr [0x4d98ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */) = cpu.eax;
    // 004793d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004793d8  7450                   -je 0x47942a
    if (cpu.flags.zf)
    {
        goto L_0x0047942a;
    }
    // 004793da  e861eeffff             -call 0x478240
    cpu.esp -= 4;
    sub_478240(app, cpu);
    if (cpu.terminate) return;
    // 004793df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004793e1  7450                   -je 0x479433
    if (cpu.flags.zf)
    {
        goto L_0x00479433;
    }
    // 004793e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004793e4  e8078efcff             -call 0x4421f0
    cpu.esp -= 4;
    sub_4421f0(app, cpu);
    if (cpu.terminate) return;
    // 004793e9  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004793ee  8a15d42e5100           -mov dl, byte ptr [0x512ed4]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5320404) /* 0x512ed4 */);
    // 004793f4  e86799faff             -call 0x422d60
    cpu.esp -= 4;
    sub_422d60(app, cpu);
    if (cpu.terminate) return;
    // 004793f9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004793fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004793fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004793ff  e8cc87faff             -call 0x421bd0
    cpu.esp -= 4;
    sub_421bd0(app, cpu);
    if (cpu.terminate) return;
    // 00479404  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479406  741a                   -je 0x479422
    if (cpu.flags.zf)
    {
        goto L_0x00479422;
    }
    // 00479408  ba30e74c00             -mov edx, 0x4ce730
    cpu.edx = 5039920 /*0x4ce730*/;
    // 0047940d  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00479410  e8ec3d0200             -call 0x49d201
    cpu.esp -= 4;
    sub_49d201(app, cpu);
    if (cpu.terminate) return;
    // 00479415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479417  7409                   -je 0x479422
    if (cpu.flags.zf)
    {
        goto L_0x00479422;
    }
    // 00479419  66c7051e994d000100     -mov word ptr [0x4d991e], 1
    app->getMemory<x86::reg16>(x86::reg32(5085470) /* 0x4d991e */) = 1 /*0x1*/;
L_0x00479422:
    // 00479422  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00479427  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479428  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047942a:
    // 0047942a  e8c18dfcff             -call 0x4421f0
    cpu.esp -= 4;
    sub_4421f0(app, cpu);
    if (cpu.terminate) return;
    // 0047942f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479431  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479432  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479433:
    // 00479433  e8b88dfcff             -call 0x4421f0
    cpu.esp -= 4;
    sub_4421f0(app, cpu);
    if (cpu.terminate) return;
    // 00479438  8915ec984d00           -mov dword ptr [0x4d98ec], edx
    app->getMemory<x86::reg32>(x86::reg32(5085420) /* 0x4d98ec */) = cpu.edx;
    // 0047943e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479440  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479441  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 2626a4ff0000e3ff30ffffff0df700ff00001f3f0000513f0000513f00001f3f0000023f0000023f0000343f0000343f0d0000000b0000000f000000110000000c0000000a0000000e000000100000001b0000001c0000001d0000001e0000001f0000002000000021000000220000002300000012000000130000001400000015000000160000001700000018000000190000001a000000000000000000000092954700429647006f9647009b964700d79647001a9747004297470069974700 */
void Application::sub_479510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479510);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00479510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479513  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479514  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479515  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479518  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047951a  8d7c2458               -lea edi, [esp + 0x58]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047951e  be80944700             -mov esi, 0x479480
    cpu.esi = 4691072 /*0x479480*/;
    // 00479523  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479524  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479525  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479526  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479527  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047952b  be90944700             -mov esi, 0x479490
    cpu.esi = 4691088 /*0x479490*/;
    // 00479530  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479531  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479532  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479533  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479534  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00479539  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047953d  bea0944700             -mov esi, 0x4794a0
    cpu.esi = 4691104 /*0x4794a0*/;
    // 00479542  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00479544  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00479549  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047954b  bec4944700             -mov esi, 0x4794c4
    cpu.esi = 4691140 /*0x4794c4*/;
    // 00479550  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479552  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479554  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00479556  e82568ffff             -call 0x46fd80
    cpu.esp -= 4;
    sub_46fd80(app, cpu);
    if (cpu.terminate) return;
    // 0047955b  b915000000             -mov ecx, 0x15
    cpu.ecx = 21 /*0x15*/;
    // 00479560  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479562  e8d9020000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 00479567  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00479569  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047956b:
    // 0047956b  8b15a0275200           -mov edx, dword ptr [0x5227a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5384096) /* 0x5227a0 */);
    // 00479571  39d6                   +cmp esi, edx
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
    // 00479573  0f8518020000           -jne 0x479791
    if (!cpu.flags.zf)
    {
        goto L_0x00479791;
    }
    // 00479579  8b1da4275200           -mov ebx, dword ptr [0x5227a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5384100) /* 0x5227a4 */);
    // 0047957f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479581  0f8441010000           -je 0x4796c8
    if (cpu.flags.zf)
    {
        goto L_0x004796c8;
    }
    // 00479587  83fa03                 +cmp edx, 3
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
    // 0047958a  773c                   -ja 0x4795c8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004795c8;
    }
    // 0047958c  ffa7f0944700           -jmp dword ptr [edi + 0x4794f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + 4691184); goto dynamic_jump;
  case 0x00479592:
    // 00479592  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479597  bae1ffffff             -mov edx, 0xffffffe1
    cpu.edx = 4294967265 /*0xffffffe1*/;
    // 0047959c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004795a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004795a3  e898020000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 004795a8  8b1590275200           -mov edx, dword ptr [0x522790]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5384080) /* 0x522790 */);
    // 004795ae  83fa01                 +cmp edx, 1
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
    // 004795b1  0f8578000000           -jne 0x47962f
    if (!cpu.flags.zf)
    {
        goto L_0x0047962f;
    }
    // 004795b7  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004795bc  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004795c1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004795c3:
    // 004795c3  e878020000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
L_0x004795c8:
    // 004795c8  46                     -inc esi
    (cpu.esi)++;
    // 004795c9  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004795cc  83fe04                 +cmp esi, 4
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
    // 004795cf  7c9a                   -jl 0x47956b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047956b;
    }
    // 004795d1  8b0d5c954d00           -mov ecx, dword ptr [0x4d955c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084508) /* 0x4d955c */);
    // 004795d7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004795d9  7438                   -je 0x479613
    if (cpu.flags.zf)
    {
        goto L_0x00479613;
    }
    // 004795db  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 004795e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004795e3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004795e6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004795e8  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004795eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004795ed  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004795f0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004795f2  3d88000000             +cmp eax, 0x88
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
    // 004795f7  0f8ef9010000           -jle 0x4797f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004797f6;
    }
    // 004795fd  ba88000000             -mov edx, 0x88
    cpu.edx = 136 /*0x88*/;
L_0x00479602:
    // 00479602  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479607  b824000000             -mov eax, 0x24
    cpu.eax = 36 /*0x24*/;
    // 0047960c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047960e  e82d020000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
L_0x00479613:
    // 00479613  8d742468               -lea esi, [esp + 0x68]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00479617  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00479619  e8d266ffff             -call 0x46fcf0
    cpu.esp -= 4;
    sub_46fcf0(app, cpu);
    if (cpu.terminate) return;
    // 0047961e  8d742468               -lea esi, [esp + 0x68]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00479622  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479623  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479624  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00479626  83c470                 +add esp, 0x70
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
    // 00479629  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047962a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047962b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047962c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047962d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047962e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047962f:
    // 0047962f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479634  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00479639  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0047963e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00479640  eb81                   -jmp 0x4795c3
    goto L_0x004795c3;
  case 0x00479642:
    // 00479642  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479647  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047964c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047964e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479650  e8eb010000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 00479655  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047965a  a194275200             -mov eax, dword ptr [0x522794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */);
    // 0047965f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479664  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00479666  8b448458               -mov eax, dword ptr [esp + eax*4 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */ + cpu.eax * 4);
    // 0047966a  e954ffffff             -jmp 0x4795c3
    goto L_0x004795c3;
  case 0x0047966f:
    // 0047966f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479674  ba1f000000             -mov edx, 0x1f
    cpu.edx = 31 /*0x1f*/;
    // 00479679  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047967e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00479680  e8bb010000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 00479685  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047968a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047968f  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00479694  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00479696  e928ffffff             -jmp 0x4795c3
    goto L_0x004795c3;
  case 0x0047969b:
    // 0047969b  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004796a0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004796a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004796a7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004796a9  e892010000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 004796ae  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004796b3  a19c275200             -mov eax, dword ptr [0x52279c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384092) /* 0x52279c */);
    // 004796b8  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004796bd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004796bf  8b448424               -mov eax, dword ptr [esp + eax*4 + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */ + cpu.eax * 4);
    // 004796c3  e9fbfeffff             -jmp 0x4795c3
    goto L_0x004795c3;
L_0x004796c8:
    // 004796c8  83fa03                 +cmp edx, 3
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
    // 004796cb  0f87f7feffff           -ja 0x4795c8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004795c8;
    }
    // 004796d1  ffa700954700           -jmp dword ptr [edi + 0x479500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + 4691200); goto dynamic_jump;
  case 0x004796d7:
    // 004796d7  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004796dc  bae1ffffff             -mov edx, 0xffffffe1
    cpu.edx = 4294967265 /*0xffffffe1*/;
    // 004796e1  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004796e6  e855010000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 004796eb  833d9027520001         +cmp dword ptr [0x522790], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5384080) /* 0x522790 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004796f2  7513                   -jne 0x479707
    if (!cpu.flags.zf)
    {
        goto L_0x00479707;
    }
    // 004796f4  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004796f9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004796fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479700  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479702  e9bcfeffff             -jmp 0x4795c3
    goto L_0x004795c3;
L_0x00479707:
    // 00479707  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047970c  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00479711  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479713  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479715  e9a9feffff             -jmp 0x4795c3
    goto L_0x004795c3;
  case 0x0047971a:
    // 0047971a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047971f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00479724  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479726  e815010000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 0047972b  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479730  a194275200             -mov eax, dword ptr [0x522794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */);
    // 00479735  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479737  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479739  8b448458               -mov eax, dword ptr [esp + eax*4 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */ + cpu.eax * 4);
    // 0047973d  e981feffff             -jmp 0x4795c3
    goto L_0x004795c3;
  case 0x00479742:
    // 00479742  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00479747  ba1f000000             -mov edx, 0x1f
    cpu.edx = 31 /*0x1f*/;
    // 0047974c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00479751  e8ea000000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 00479756  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047975b  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00479760  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479762  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479764  e95afeffff             -jmp 0x4795c3
    goto L_0x004795c3;
  case 0x00479769:
    // 00479769  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047976e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479773  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479775  e8c6000000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 0047977a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047977f  a19c275200             -mov eax, dword ptr [0x52279c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384092) /* 0x52279c */);
    // 00479784  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479786  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00479788  8b448424               -mov eax, dword ptr [esp + eax*4 + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */ + cpu.eax * 4);
    // 0047978c  e932feffff             -jmp 0x4795c3
    goto L_0x004795c3;
L_0x00479791:
    // 00479791  83fe01                 +cmp esi, 1
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
    // 00479794  7328                   -jae 0x4797be
    if (!cpu.flags.cf)
    {
        goto L_0x004797be;
    }
    // 00479796  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479798  0f852afeffff           -jne 0x4795c8
    if (!cpu.flags.zf)
    {
        goto L_0x004795c8;
    }
    // 0047979e  833d9027520001         +cmp dword ptr [0x522790], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5384080) /* 0x522790 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004797a5  0f851dfeffff           -jne 0x4795c8
    if (!cpu.flags.zf)
    {
        goto L_0x004795c8;
    }
    // 004797ab  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004797b0  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004797b5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004797b7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004797b9  e905feffff             -jmp 0x4795c3
    goto L_0x004795c3;
L_0x004797be:
    // 004797be  761f                   -jbe 0x4797df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004797df;
    }
    // 004797c0  83fe03                 +cmp esi, 3
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
    // 004797c3  0f85fffdffff           -jne 0x4795c8
    if (!cpu.flags.zf)
    {
        goto L_0x004795c8;
    }
    // 004797c9  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004797ce  a19c275200             -mov eax, dword ptr [0x52279c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384092) /* 0x52279c */);
    // 004797d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004797d5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004797d7  8b0484                 -mov eax, dword ptr [esp + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 4);
    // 004797da  e9e4fdffff             -jmp 0x4795c3
    goto L_0x004795c3;
L_0x004797df:
    // 004797df  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004797e4  a194275200             -mov eax, dword ptr [0x522794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5384084) /* 0x522794 */);
    // 004797e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004797eb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004797ed  8b448448               -mov eax, dword ptr [esp + eax*4 + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */ + cpu.eax * 4);
    // 004797f1  e9cdfdffff             -jmp 0x4795c3
    goto L_0x004795c3;
L_0x004797f6:
    // 004797f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004797f8  e905feffff             -jmp 0x479602
    goto L_0x00479602;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_479800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479800);
    // 00479800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479804  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479805  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479808  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047980a  e87165ffff             -call 0x46fd80
    cpu.esp -= 4;
    sub_46fd80(app, cpu);
    if (cpu.terminate) return;
    // 0047980f  b915000000             -mov ecx, 0x15
    cpu.ecx = 21 /*0x15*/;
    // 00479814  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479816  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479818  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047981a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047981c  e81f000000             -call 0x479840
    cpu.esp -= 4;
    sub_479840(app, cpu);
    if (cpu.terminate) return;
    // 00479821  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00479823  e8c864ffff             -call 0x46fcf0
    cpu.esp -= 4;
    sub_46fcf0(app, cpu);
    if (cpu.terminate) return;
    // 00479828  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047982a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047982b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047982c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047982e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479831  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479832  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479833  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479834  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479835  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479840);
    // 00479840  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479841  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479842  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479845  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00479847  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00479849  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0047984e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479850  e8db64ffff             -call 0x46fd30
    cpu.esp -= 4;
    sub_46fd30(app, cpu);
    if (cpu.terminate) return;
    // 00479855  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479857  7506                   -jne 0x47985f
    if (!cpu.flags.zf)
    {
        goto L_0x0047985f;
    }
    // 00479859  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047985c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047985d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047985e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047985f:
    // 0047985f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00479862  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00479865  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00479868  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047986a  c74020c8885500         -mov dword ptr [eax + 0x20], 0x5588c8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 5605576 /*0x5588c8*/;
    // 00479871  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00479878  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047987a  8b14c558994d00         -mov edx, dword ptr [eax*8 + 0x4d9958]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085528) /* 0x4d9958 */ + cpu.eax * 8);
    // 00479881  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00479884  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479886  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00479889  8b14c55c994d00         -mov edx, dword ptr [eax*8 + 0x4d995c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085532) /* 0x4d995c */ + cpu.eax * 8);
    // 00479890  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00479893  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00479895  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00479898  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047989b  8b0cc550994d00         -mov ecx, dword ptr [eax*8 + 0x4d9950]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085520) /* 0x4d9950 */ + cpu.eax * 8);
    // 004798a2  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004798a5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004798a8  8b0cc554994d00         -mov ecx, dword ptr [eax*8 + 0x4d9954]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085524) /* 0x4d9954 */ + cpu.eax * 8);
    // 004798af  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004798b2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004798b5  8b0cc548994d00         -mov ecx, dword ptr [eax*8 + 0x4d9948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085512) /* 0x4d9948 */ + cpu.eax * 8);
    // 004798bc  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004798bf  8b14c54c994d00         -mov edx, dword ptr [eax*8 + 0x4d994c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085516) /* 0x4d994c */ + cpu.eax * 8);
    // 004798c6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004798c9  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004798cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004798cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004798d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4798e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004798e0);
    // 004798e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004798e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004798e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004798e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004798e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004798e5  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004798e8  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004798ec  e8af19fdff             -call 0x44b2a0
    cpu.esp -= 4;
    sub_44b2a0(app, cpu);
    if (cpu.terminate) return;
    // 004798f1  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 004798f6  b944000000             -mov ecx, 0x44
    cpu.ecx = 68 /*0x44*/;
    // 004798fb  8b1da0185100           -mov ebx, dword ptr [0x5118a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 00479901  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00479905  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00479908  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0047990c  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 0047990f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00479911  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479913  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479916  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00479918  a310a14d00             -mov dword ptr [0x4da110], eax
    app->getMemory<x86::reg32>(x86::reg32(5087504) /* 0x4da110 */) = cpu.eax;
    // 0047991d  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 00479923  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00479926  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047992a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047992c  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00479932  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00479934  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00479937  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0047993b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047993f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479941  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00479943  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00479945  e8a6070000             -call 0x47a0f0
    cpu.esp -= 4;
    sub_47a0f0(app, cpu);
    if (cpu.terminate) return;
    // 0047994a  a100e35500             -mov eax, dword ptr [0x55e300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5628672) /* 0x55e300 */);
    // 0047994f  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00479953  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00479959  c0e507                 +shl ch, 7
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
    // 0047995c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047995e  00ed                   +add ch, ch
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
    // 00479960  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00479962  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479964  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00479969  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047996b  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 00479972  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479974  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00479976  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479978  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047997c  a100e35500             -mov eax, dword ptr [0x55e300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5628672) /* 0x55e300 */);
    // 00479981  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479985  c0e407                 +shl ah, 7
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
    // 00479988  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047998a  00e4                   +add ah, ah
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
    // 0047998c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0047998e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479990  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00479995  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479997  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0047999e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004799a0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004799a2  0335109d4d00           -add esi, dword ptr [0x4d9d10]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5086480) /* 0x4d9d10 */)));
    // 004799a8  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004799ac  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004799af  bf7e000000             -mov edi, 0x7e
    cpu.edi = 126 /*0x7e*/;
    // 004799b4  ba109d4d00             -mov edx, 0x4d9d10
    cpu.edx = 5086480 /*0x4d9d10*/;
    // 004799b9  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 004799bd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004799c0  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004799c4  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 004799c8  033d109f4d00           -add edi, dword ptr [0x4d9f10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5086992) /* 0x4d9f10 */)));
    // 004799ce  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004799d1  bd109f4d00             -mov ebp, 0x4d9f10
    cpu.ebp = 5086992 /*0x4d9f10*/;
    // 004799d6  b94ce45500             -mov ecx, 0x55e44c
    cpu.ecx = 5629004 /*0x55e44c*/;
    // 004799db  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004799de  8b1528225100           -mov edx, dword ptr [0x512228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 004799e4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004799e6  33152c225100           -xor edx, dword ptr [0x51222c]
    cpu.edx ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */)));
    // 004799ec  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004799ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004799f1  0f8458030000           -je 0x479d4f
    if (cpu.flags.zf)
    {
        goto L_0x00479d4f;
    }
    // 004799f7  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 004799fc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004799fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00479a00:
    // 00479a00  0faf7c242c             -imul edi, dword ptr [esp + 0x2c]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00479a05  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00479a09  0faf742428             -imul esi, dword ptr [esp + 0x28]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00479a0e  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00479a11  8b1528225100           -mov edx, dword ptr [0x512228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479a17  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479a1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479a1c  0f8435030000           -je 0x479d57
    if (cpu.flags.zf)
    {
        goto L_0x00479d57;
    }
    // 00479a22  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
L_0x00479a26:
    // 00479a26  bb14a14d00             -mov ebx, 0x4da114
    cpu.ebx = 5087508 /*0x4da114*/;
    // 00479a2b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00479a2f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479a31  b818a14d00             -mov eax, 0x4da118
    cpu.eax = 5087512 /*0x4da118*/;
L_0x00479a36:
    // 00479a36  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00479a3a  660fbe33               -movsx si, byte ptr [ebx]
    cpu.si = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx)));
    // 00479a3e  43                     -inc ebx
    (cpu.ebx)++;
    // 00479a3f  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479a41  40                     -inc eax
    (cpu.eax)++;
    // 00479a42  66897908               -mov word ptr [ecx + 8], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.di;
    // 00479a46  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479a4a  660fbe70ff             -movsx si, byte ptr [eax - 1]
    cpu.si = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */)));
    // 00479a4f  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479a52  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479a54  42                     -inc edx
    (cpu.edx)++;
    // 00479a55  668979f6               -mov word ptr [ecx - 0xa], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-10) /* -0xa */) = cpu.di;
    // 00479a59  83fa04                 +cmp edx, 4
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
    // 00479a5c  7cd8                   -jl 0x479a36
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479a36;
    }
    // 00479a5e  83e950                 -sub ecx, 0x50
    (cpu.ecx) -= x86::reg32(x86::sreg32(80 /*0x50*/));
L_0x00479a61:
    // 00479a61  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00479a65  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479a69  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00479a6c  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00479a6e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00479a70  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479a74  89742438               -mov dword ptr [esp + 0x38], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.esi;
    // 00479a78  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00479a7a  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00479a7c  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479a7e  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479a82  0faff2                 -imul esi, edx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00479a85  8b3d2c225100           -mov edi, dword ptr [0x51222c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */);
    // 00479a8b  333d28225100           -xor edi, dword ptr [0x512228]
    cpu.edi ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)));
    // 00479a91  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00479a95  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479a98  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00479a9a  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00479a9d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00479aa0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00479aa2  0f84bc020000           -je 0x479d64
    if (cpu.flags.zf)
    {
        goto L_0x00479d64;
    }
    // 00479aa8  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479aac  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00479aae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00479ab0:
    // 00479ab0  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479ab4  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479ab7  0faf542428             -imul edx, dword ptr [esp + 0x28]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00479abc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00479abe  8b3d28225100           -mov edi, dword ptr [0x512228]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479ac4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479ac7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00479ac9  0f849e020000           -je 0x479d6d
    if (cpu.flags.zf)
    {
        goto L_0x00479d6d;
    }
    // 00479acf  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
L_0x00479ad3:
    // 00479ad3  ba14a14d00             -mov edx, 0x4da114
    cpu.edx = 5087508 /*0x4da114*/;
    // 00479ad8  bb18a14d00             -mov ebx, 0x4da118
    cpu.ebx = 5087512 /*0x4da118*/;
    // 00479add  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479ae1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479ae3:
    // 00479ae3  660fbe3a               -movsx di, byte ptr [edx]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 00479ae7  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479ae9  43                     -inc ebx
    (cpu.ebx)++;
    // 00479aea  6689790c               -mov word ptr [ecx + 0xc], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.di;
    // 00479aee  42                     -inc edx
    (cpu.edx)++;
    // 00479aef  660fbe7bff             -movsx di, byte ptr [ebx - 1]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */)));
    // 00479af4  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479af7  037c2408               -add edi, dword ptr [esp + 8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00479afb  40                     -inc eax
    (cpu.eax)++;
    // 00479afc  668979fa               -mov word ptr [ecx - 6], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-6) /* -0x6 */) = cpu.di;
    // 00479b00  83f804                 +cmp eax, 4
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
    // 00479b03  7cde                   -jl 0x479ae3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479ae3;
    }
    // 00479b05  bb18a14d00             -mov ebx, 0x4da118
    cpu.ebx = 5087512 /*0x4da118*/;
    // 00479b0a  ba14a14d00             -mov edx, 0x4da114
    cpu.edx = 5087508 /*0x4da114*/;
    // 00479b0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479b11:
    // 00479b11  660fbe3a               -movsx di, byte ptr [edx]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 00479b15  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479b17  43                     -inc ebx
    (cpu.ebx)++;
    // 00479b18  66897908               -mov word ptr [ecx + 8], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.di;
    // 00479b1c  42                     -inc edx
    (cpu.edx)++;
    // 00479b1d  660fbe7bff             -movsx di, byte ptr [ebx - 1]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */)));
    // 00479b22  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479b25  037c2408               -add edi, dword ptr [esp + 8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00479b29  40                     -inc eax
    (cpu.eax)++;
    // 00479b2a  668979f6               -mov word ptr [ecx - 0xa], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-10) /* -0xa */) = cpu.di;
    // 00479b2e  83f804                 +cmp eax, 4
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
    // 00479b31  7cde                   -jl 0x479b11
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479b11;
    }
    // 00479b33  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00479b37  4b                     -dec ebx
    (cpu.ebx)--;
    // 00479b38  83e950                 -sub ecx, 0x50
    (cpu.ecx) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00479b3b  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 00479b3f  83fbff                 +cmp ebx, -1
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
    // 00479b42  0f8519ffffff           -jne 0x479a61
    if (!cpu.flags.zf)
    {
        goto L_0x00479a61;
    }
    // 00479b48  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479b4c  8b3d109d4d00           -mov edi, dword ptr [0x4d9d10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5086480) /* 0x4d9d10 */);
    // 00479b52  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479b56  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00479b58  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479b5b  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479b5f  8b2d109f4d00           -mov ebp, dword ptr [0x4d9f10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5086992) /* 0x4d9f10 */);
    // 00479b65  8b352c225100           -mov esi, dword ptr [0x51222c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */);
    // 00479b6b  8b3d28225100           -mov edi, dword ptr [0x512228]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479b71  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00479b73  31f7                   -xor edi, esi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00479b75  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00479b79  0faff2                 -imul esi, edx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00479b7c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00479b7e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479b81  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00479b83  0f84f1010000           -je 0x479d7a
    if (cpu.flags.zf)
    {
        goto L_0x00479d7a;
    }
    // 00479b89  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479b8d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479b8f:
    // 00479b8f  0faf54242c             -imul edx, dword ptr [esp + 0x2c]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00479b94  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00479b98  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479b9b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00479b9d  8b2d28225100           -mov ebp, dword ptr [0x512228]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479ba3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479ba6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00479ba8  0f84d7010000           -je 0x479d85
    if (cpu.flags.zf)
    {
        goto L_0x00479d85;
    }
    // 00479bae  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
L_0x00479bb2:
    // 00479bb2  bb14a14d00             -mov ebx, 0x4da114
    cpu.ebx = 5087508 /*0x4da114*/;
    // 00479bb7  ba18a14d00             -mov edx, 0x4da118
    cpu.edx = 5087512 /*0x4da118*/;
    // 00479bbc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479bc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479bc2:
    // 00479bc2  660fbe3b               -movsx di, byte ptr [ebx]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx)));
    // 00479bc6  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479bc8  42                     -inc edx
    (cpu.edx)++;
    // 00479bc9  6689790c               -mov word ptr [ecx + 0xc], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.di;
    // 00479bcd  43                     -inc ebx
    (cpu.ebx)++;
    // 00479bce  660fbe7aff             -movsx di, byte ptr [edx - 1]
    cpu.di = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */)));
    // 00479bd3  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00479bd6  037c2408               -add edi, dword ptr [esp + 8]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00479bda  40                     -inc eax
    (cpu.eax)++;
    // 00479bdb  668979fa               -mov word ptr [ecx - 6], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-6) /* -0x6 */) = cpu.di;
    // 00479bdf  83f804                 +cmp eax, 4
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
    // 00479be2  7cde                   -jl 0x479bc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479bc2;
    }
    // 00479be4  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479be8  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 00479bed  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479bf1  8b35109d4d00           -mov esi, dword ptr [0x4d9d10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5086480) /* 0x4d9d10 */);
    // 00479bf7  8b500f                 -mov edx, dword ptr [eax + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 00479bfa  8b7811                 -mov edi, dword ptr [eax + 0x11]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 00479bfd  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479bff  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00479c02  a1109f4d00             -mov eax, dword ptr [0x4d9f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086992) /* 0x4d9f10 */);
    // 00479c07  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00479c0a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479c0c  c1fa0d                 -sar edx, 0xd
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (13 /*0xd*/ % 32));
    // 00479c0f  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479c13  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00479c15  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479c18  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00479c1b  c1e709                 -shl edi, 9
    cpu.edi <<= 9 /*0x9*/ % 32;
    // 00479c1e  c1ff0d                 -sar edi, 0xd
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (13 /*0xd*/ % 32));
    // 00479c21  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00479c25  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00479c27  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00479c2b  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00479c2e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00479c30  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479c32  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479c35  c1e210                 +shl edx, 0x10
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
    // 00479c38  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479c3a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479c3d  0faf5c2428             -imul ebx, dword ptr [esp + 0x28]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00479c42  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479c46  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00479c49  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00479c4b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479c4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479c4f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479c52  c1e210                 +shl edx, 0x10
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
    // 00479c55  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479c57  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479c5a  8b1d2c225100           -mov ebx, dword ptr [0x51222c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */);
    // 00479c60  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479c64  a128225100             -mov eax, dword ptr [0x512228]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479c69  31d8                   +xor eax, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00479c6b  0f8421010000           -je 0x479d92
    if (cpu.flags.zf)
    {
        goto L_0x00479d92;
    }
    // 00479c71  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479c75  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00479c77:
    // 00479c77  8b3528225100           -mov esi, dword ptr [0x512228]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479c7d  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00479c81  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479c83  0f8414010000           -je 0x479d9d
    if (cpu.flags.zf)
    {
        goto L_0x00479d9d;
    }
    // 00479c89  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479c8d  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x00479c91:
    // 00479c91  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00479c95  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479c99  8b1d109d4d00           -mov ebx, dword ptr [0x4d9d10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086480) /* 0x4d9d10 */);
    // 00479c9f  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00479ca3  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00479ca5  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479ca9  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00479cab  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00479cae  a1109f4d00             -mov eax, dword ptr [0x4d9f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086992) /* 0x4d9f10 */);
    // 00479cb3  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479cb7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479cb9  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00479cbd  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00479cbf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479cc2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00479cc4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479cc6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479cc9  c1e210                 +shl edx, 0x10
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
    // 00479ccc  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479cce  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479cd1  0faf6c2428             -imul ebp, dword ptr [esp + 0x28]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00479cd6  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479cda  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00479cdd  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00479cdf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00479ce1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479ce3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00479ce6  c1e210                 +shl edx, 0x10
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
    // 00479ce9  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479ceb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00479cee  8b1d2c225100           -mov ebx, dword ptr [0x51222c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */);
    // 00479cf4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00479cf8  a128225100             -mov eax, dword ptr [0x512228]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479cfd  31d8                   +xor eax, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00479cff  0f84a5000000           -je 0x479daa
    if (cpu.flags.zf)
    {
        goto L_0x00479daa;
    }
    // 00479d05  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479d09  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00479d0b:
    // 00479d0b  8b3528225100           -mov esi, dword ptr [0x512228]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479d11  6689410c               -mov word ptr [ecx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 00479d15  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479d17  0f8498000000           -je 0x479db5
    if (cpu.flags.zf)
    {
        goto L_0x00479db5;
    }
    // 00479d1d  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479d21  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x00479d25:
    // 00479d25  ba4c0c5600             -mov edx, 0x560c4c
    cpu.edx = 5639244 /*0x560c4c*/;
    // 00479d2a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00479d2e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00479d30  6689410e               -mov word ptr [ecx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00479d34  b84ce45500             -mov eax, 0x55e44c
    cpu.eax = 5629004 /*0x55e44c*/;
    // 00479d39  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00479d3d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00479d40  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479d41  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00479d42  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00479d46  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00479d49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479d4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479d4f:
    // 00479d4f  83c035                 +add eax, 0x35
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
    // 00479d52  e9a9fcffff             -jmp 0x479a00
    goto L_0x00479a00;
L_0x00479d57:
    // 00479d57  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479d5b  29c2                   +sub edx, eax
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
    // 00479d5d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479d5f  e9c2fcffff             -jmp 0x479a26
    goto L_0x00479a26;
L_0x00479d64:
    // 00479d64  03742424               +add esi, dword ptr [esp + 0x24]
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
    // 00479d68  e943fdffff             -jmp 0x479ab0
    goto L_0x00479ab0;
L_0x00479d6d:
    // 00479d6d  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479d71  29c2                   +sub edx, eax
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
    // 00479d73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479d75  e959fdffff             -jmp 0x479ad3
    goto L_0x00479ad3;
L_0x00479d7a:
    // 00479d7a  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479d7e  01c6                   +add esi, eax
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
    // 00479d80  e90afeffff             -jmp 0x479b8f
    goto L_0x00479b8f;
L_0x00479d85:
    // 00479d85  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479d89  29c2                   +sub edx, eax
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
    // 00479d8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479d8d  e920feffff             -jmp 0x479bb2
    goto L_0x00479bb2;
L_0x00479d92:
    // 00479d92  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479d96  01f0                   +add eax, esi
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
    // 00479d98  e9dafeffff             -jmp 0x479c77
    goto L_0x00479c77;
L_0x00479d9d:
    // 00479d9d  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479da1  2b442408               +sub eax, dword ptr [esp + 8]
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
    // 00479da5  e9e7feffff             -jmp 0x479c91
    goto L_0x00479c91;
L_0x00479daa:
    // 00479daa  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479dae  01f0                   +add eax, esi
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
    // 00479db0  e956ffffff             -jmp 0x479d0b
    goto L_0x00479d0b;
L_0x00479db5:
    // 00479db5  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479db9  2b442408               +sub eax, dword ptr [esp + 8]
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
    // 00479dbd  e963ffffff             -jmp 0x479d25
    goto L_0x00479d25;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_479dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00479dd0);
    // 00479dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479dd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479dd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479dd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479dd5  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00479dd8  8b1d34e45500           -mov ebx, dword ptr [0x55e434]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5628980) /* 0x55e434 */);
    // 00479dde  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00479de2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00479de4  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 00479de9  be44000000             -mov esi, 0x44
    cpu.esi = 68 /*0x44*/;
    // 00479dee  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00479df5  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00479df9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00479dfb  b960bf5500             -mov ecx, 0x55bf60
    cpu.ecx = 5619552 /*0x55bf60*/;
    // 00479e00  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00479e03  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00479e07  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479e09  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00479e0b  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00479e0e  e88d14fdff             -call 0x44b2a0
    cpu.esp -= 4;
    sub_44b2a0(app, cpu);
    if (cpu.terminate) return;
    // 00479e13  8b909c000000           -mov edx, dword ptr [eax + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 00479e19  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00479e1d  c1fa13                 -sar edx, 0x13
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (19 /*0x13*/ % 32));
    // 00479e20  8b80a4000000           -mov eax, dword ptr [eax + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00479e26  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00479e2a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00479e2c  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00479e2f  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00479e31  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00479e35  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00479e37  a100e35500             -mov eax, dword ptr [0x55e300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5628672) /* 0x55e300 */);
    // 00479e3c  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00479e40  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00479e42  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00479e48  c0e507                 +shl ch, 7
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
    // 00479e4b  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479e4d  00ed                   +add ch, ch
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
    // 00479e4f  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00479e51  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479e53  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00479e58  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479e5a  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 00479e61  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479e63  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00479e65  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00479e69  a100e35500             -mov eax, dword ptr [0x55e300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5628672) /* 0x55e300 */);
    // 00479e6e  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 00479e72  c0e407                 +shl ah, 7
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
    // 00479e75  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00479e77  00e4                   +add ah, ah
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
    // 00479e79  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00479e7b  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479e7d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00479e82  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479e84  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 00479e8b  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479e8d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00479e8f  8b1d34e45500           -mov ebx, dword ptr [0x55e434]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5628980) /* 0x55e434 */);
    // 00479e95  8b152c225100           -mov edx, dword ptr [0x51222c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */);
    // 00479e9b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00479e9f  a128225100             -mov eax, dword ptr [0x512228]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00479ea4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00479ea6  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00479ea8  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00479eac  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00479eb0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00479eb2:
    // 00479eb2  8b35441e5100           -mov esi, dword ptr [0x511e44]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316164) /* 0x511e44 */);
    // 00479eb8  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00479ebb  39f1                   +cmp ecx, esi
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
    // 00479ebd  0f8d4e010000           -jge 0x47a011
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a011;
    }
    // 00479ec3  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00479ec7  3bbac81c5100           +cmp edi, dword ptr [edx + 0x511cc8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315784) /* 0x511cc8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479ecd  0f8431010000           -je 0x47a004
    if (cpu.flags.zf)
    {
        goto L_0x0047a004;
    }
    // 00479ed3  83fb77                 +cmp ebx, 0x77
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
    // 00479ed6  7c02                   -jl 0x479eda
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479eda;
    }
    // 00479ed8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00479eda:
    // 00479eda  6bc028                 -imul eax, eax, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00479edd  be60bf5500             -mov esi, 0x55bf60
    cpu.esi = 5619552 /*0x55bf60*/;
    // 00479ee2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479ee4  6bc328                 -imul eax, ebx, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00479ee7  bd1e000000             -mov ebp, 0x1e
    cpu.ebp = 30 /*0x1e*/;
    // 00479eec  89b060bf5500           -mov dword ptr [eax + 0x55bf60], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619552) /* 0x55bf60 */) = cpu.esi;
    // 00479ef2  8bb2c81c5100           -mov esi, dword ptr [edx + 0x511cc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315784) /* 0x511cc8 */);
    // 00479ef8  89a864bf5500           -mov dword ptr [eax + 0x55bf64], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619556) /* 0x55bf64 */) = cpu.ebp;
    // 00479efe  f686f401000004         +test byte ptr [esi + 0x1f4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(500) /* 0x1f4 */) & 4 /*0x4*/));
    // 00479f05  0f84d4000000           -je 0x479fdf
    if (cpu.flags.zf)
    {
        goto L_0x00479fdf;
    }
    // 00479f0b  bf09000000             -mov edi, 9
    cpu.edi = 9 /*0x9*/;
L_0x00479f10:
    // 00479f10  89b874bf5500           -mov dword ptr [eax + 0x55bf74], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619572) /* 0x55bf74 */) = cpu.edi;
    // 00479f16  89b870bf5500           -mov dword ptr [eax + 0x55bf70], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619568) /* 0x55bf70 */) = cpu.edi;
    // 00479f1c  8bb60c060000           -mov esi, dword ptr [esi + 0x60c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1548) /* 0x60c */);
    // 00479f22  8b34b56c0c5600         -mov esi, dword ptr [esi*4 + 0x560c6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5639276) /* 0x560c6c */ + cpu.esi * 4);
    // 00479f29  89b084bf5500           -mov dword ptr [eax + 0x55bf84], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619588) /* 0x55bf84 */) = cpu.esi;
    // 00479f2f  8b82c81c5100           -mov eax, dword ptr [edx + 0x511cc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5315784) /* 0x511cc8 */);
    // 00479f35  8bb89c000000           -mov edi, dword ptr [eax + 0x9c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 00479f3b  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00479f3f  c1ff13                 -sar edi, 0x13
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (19 /*0x13*/ % 32));
    // 00479f42  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00479f44  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00479f48  0faff7                 -imul esi, edi
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00479f4b  8b80a4000000           -mov eax, dword ptr [eax + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00479f51  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00479f55  c1f813                 -sar eax, 0x13
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (19 /*0x13*/ % 32));
    // 00479f58  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00479f5a  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00479f5e  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00479f62  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00479f65  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479f69  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00479f6b  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00479f6d  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 00479f72  0faf44242c             -imul eax, dword ptr [esp + 0x2c]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00479f77  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00479f79  6bc328                 -imul eax, ebx, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00479f7c  c78080bf5500c8885500   -mov dword ptr [eax + 0x55bf80], 0x5588c8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619584) /* 0x55bf80 */) = 5605576 /*0x5588c8*/;
    // 00479f86  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479f88  89a878bf5500           -mov dword ptr [eax + 0x55bf78], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619576) /* 0x55bf78 */) = cpu.ebp;
    // 00479f8e  bd2c000000             -mov ebp, 0x2c
    cpu.ebp = 44 /*0x2c*/;
    // 00479f93  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00479f96  89a87cbf5500           -mov dword ptr [eax + 0x55bf7c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619580) /* 0x55bf7c */) = cpu.ebp;
    // 00479f9c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00479fa0  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00479fa3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479fa5  7442                   -je 0x479fe9
    if (cpu.flags.zf)
    {
        goto L_0x00479fe9;
    }
    // 00479fa7  b835000000             -mov eax, 0x35
    cpu.eax = 53 /*0x35*/;
    // 00479fac  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00479fae  8d70fc                 -lea esi, [eax - 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x00479fb1:
    // 00479fb1  6bc328                 -imul eax, ebx, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00479fb4  89b068bf5500           -mov dword ptr [eax + 0x55bf68], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5619560) /* 0x55bf68 */) = cpu.esi;
    // 00479fba  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479fc1  742b                   -je 0x479fee
    if (cpu.flags.zf)
    {
        goto L_0x00479fee;
    }
    // 00479fc3  8d4740                 -lea eax, [edi + 0x40]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(64) /* 0x40 */);
L_0x00479fc6:
    // 00479fc6  6bf328                 -imul esi, ebx, 0x28
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00479fc9  89866cbf5500           -mov dword ptr [esi + 0x55bf6c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5619564) /* 0x55bf6c */) = cpu.eax;
    // 00479fcf  83fb77                 +cmp ebx, 0x77
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
    // 00479fd2  7c26                   -jl 0x479ffa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00479ffa;
    }
    // 00479fd4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00479fd6  41                     -inc ecx
    (cpu.ecx)++;
    // 00479fd7  83c204                 +add edx, 4
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
    // 00479fda  e9d3feffff             -jmp 0x479eb2
    goto L_0x00479eb2;
L_0x00479fdf:
    // 00479fdf  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
    // 00479fe4  e927ffffff             -jmp 0x479f10
    goto L_0x00479f10;
L_0x00479fe9:
    // 00479fe9  83c631                 +add esi, 0x31
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00479fec  ebc3                   -jmp 0x479fb1
    goto L_0x00479fb1;
L_0x00479fee:
    // 00479fee  b844000000             -mov eax, 0x44
    cpu.eax = 68 /*0x44*/;
    // 00479ff3  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00479ff5  83e804                 +sub eax, 4
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
    // 00479ff8  ebcc                   -jmp 0x479fc6
    goto L_0x00479fc6;
L_0x00479ffa:
    // 00479ffa  43                     -inc ebx
    (cpu.ebx)++;
    // 00479ffb  41                     -inc ecx
    (cpu.ecx)++;
    // 00479ffc  83c204                 +add edx, 4
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
    // 00479fff  e9aefeffff             -jmp 0x479eb2
    goto L_0x00479eb2;
L_0x0047a004:
    // 0047a004  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0047a008  41                     -inc ecx
    (cpu.ecx)++;
    // 0047a009  83c204                 +add edx, 4
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
    // 0047a00c  e9a1feffff             -jmp 0x479eb2
    goto L_0x00479eb2;
L_0x0047a011:
    // 0047a011  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 0047a018  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a01a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047a01c  b9c8885500             -mov ecx, 0x5588c8
    cpu.ecx = 5605576 /*0x5588c8*/;
    // 0047a021  893cd560bf5500         -mov dword ptr [edx*8 + 0x55bf60], edi
    app->getMemory<x86::reg32>(x86::reg32(5619552) /* 0x55bf60 */ + cpu.edx * 8) = cpu.edi;
    // 0047a028  bd1e000000             -mov ebp, 0x1e
    cpu.ebp = 30 /*0x1e*/;
    // 0047a02d  890cd580bf5500         -mov dword ptr [edx*8 + 0x55bf80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5619584) /* 0x55bf80 */ + cpu.edx * 8) = cpu.ecx;
    // 0047a034  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a038  892cd564bf5500         -mov dword ptr [edx*8 + 0x55bf64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5619556) /* 0x55bf64 */ + cpu.edx * 8) = cpu.ebp;
    // 0047a03f  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a042  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 0047a047  890cd568bf5500         -mov dword ptr [edx*8 + 0x55bf68], ecx
    app->getMemory<x86::reg32>(x86::reg32(5619560) /* 0x55bf68 */ + cpu.edx * 8) = cpu.ecx;
    // 0047a04e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a052  8934d570bf5500         -mov dword ptr [edx*8 + 0x55bf70], esi
    app->getMemory<x86::reg32>(x86::reg32(5619568) /* 0x55bf70 */ + cpu.edx * 8) = cpu.esi;
    // 0047a059  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a05c  890cd56cbf5500         -mov dword ptr [edx*8 + 0x55bf6c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5619564) /* 0x55bf6c */ + cpu.edx * 8) = cpu.ecx;
    // 0047a063  c704d57cbf55002c000000 -mov dword ptr [edx*8 + 0x55bf7c], 0x2c
    app->getMemory<x86::reg32>(x86::reg32(5619580) /* 0x55bf7c */ + cpu.edx * 8) = 44 /*0x2c*/;
    // 0047a06e  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047a072  8934d574bf5500         -mov dword ptr [edx*8 + 0x55bf74], esi
    app->getMemory<x86::reg32>(x86::reg32(5619572) /* 0x55bf74 */ + cpu.edx * 8) = cpu.esi;
    // 0047a079  8b0c8dc81c5100         -mov ecx, dword ptr [ecx*4 + 0x511cc8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5315784) /* 0x511cc8 */ + cpu.ecx * 4);
    // 0047a080  893cd578bf5500         -mov dword ptr [edx*8 + 0x55bf78], edi
    app->getMemory<x86::reg32>(x86::reg32(5619576) /* 0x55bf78 */ + cpu.edx * 8) = cpu.edi;
    // 0047a087  8b890c060000           -mov ecx, dword ptr [ecx + 0x60c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1548) /* 0x60c */);
    // 0047a08d  8b0c8d6c0c5600         -mov ecx, dword ptr [ecx*4 + 0x560c6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5639276) /* 0x560c6c */ + cpu.ecx * 4);
    // 0047a094  890cd584bf5500         -mov dword ptr [edx*8 + 0x55bf84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5619588) /* 0x55bf84 */ + cpu.edx * 8) = cpu.ecx;
    // 0047a09b  83fb77                 +cmp ebx, 0x77
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
    // 0047a09e  7c02                   -jl 0x47a0a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a0a2;
    }
    // 0047a0a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a0a2:
    // 0047a0a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047a0a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a0a6  7e35                   -jle 0x47a0dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a0dd;
    }
    // 0047a0a8  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0047a0ab:
    // 0047a0ab  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0047a0b2  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047a0b4  ba60bf5500             -mov edx, 0x55bf60
    cpu.edx = 5619552 /*0x55bf60*/;
    // 0047a0b9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047a0bc  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a0c0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a0c2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047a0c4  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047a0c8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047a0c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047a0ca  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a0ce  891d34e45500           -mov dword ptr [0x55e434], ebx
    app->getMemory<x86::reg32>(x86::reg32(5628980) /* 0x55e434 */) = cpu.ebx;
    // 0047a0d4  83c434                 +add esp, 0x34
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
    // 0047a0d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a0d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a0d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a0da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a0db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a0dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a0dd:
    // 0047a0dd  be77000000             -mov esi, 0x77
    cpu.esi = 119 /*0x77*/;
    // 0047a0e2  ebc7                   -jmp 0x47a0ab
    goto L_0x0047a0ab;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47a0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0047a0f0);
    // 0047a0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a0f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a0f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a0f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a0f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a0f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a0f9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047a0fb  8b15a0185100           -mov edx, dword ptr [0x5118a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0047a101  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047a104  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047a106  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a108  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047a10b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047a10d:
    // 0047a10d  6bf824                 -imul edi, eax, 0x24
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 0047a110  8b0da4185100           -mov ecx, dword ptr [0x5118a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0047a116  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a118  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a11b  8b490e                 -mov ecx, dword ptr [ecx + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0047a11e  40                     -inc eax
    (cpu.eax)++;
    // 0047a11f  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0047a122  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 0047a125  c1e109                 -shl ecx, 9
    cpu.ecx <<= 9 /*0x9*/ % 32;
    // 0047a128  c1e709                 -shl edi, 9
    cpu.edi <<= 9 /*0x9*/ % 32;
    // 0047a12b  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a12d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047a130  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a132  39c8                   +cmp eax, ecx
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
    // 0047a134  7d45                   -jge 0x47a17b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a17b;
    }
L_0x0047a136:
    // 0047a136  42                     -inc edx
    (cpu.edx)++;
    // 0047a137  83fa20                 +cmp edx, 0x20
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
    // 0047a13a  7cd1                   -jl 0x47a10d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a10d;
    }
    // 0047a13c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047a13e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a140  c1fa05                 -sar edx, 5
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (5 /*0x5*/ % 32));
    // 0047a143  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047a146  e895360200             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 0047a14b  8b9d88020000           -mov ebx, dword ptr [ebp + 0x288]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(648) /* 0x288 */);
    // 0047a151  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a153  81fb94000000           +cmp ebx, 0x94
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
    // 0047a159  7c11                   -jl 0x47a16c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a16c;
    }
    // 0047a15b  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0047a160  3d00020000             +cmp eax, 0x200
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
    // 0047a165  7c05                   -jl 0x47a16c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a16c;
    }
    // 0047a167  2d00040000             -sub eax, 0x400
    (cpu.eax) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
L_0x0047a16c:
    // 0047a16c  a300e35500             -mov dword ptr [0x55e300], eax
    app->getMemory<x86::reg32>(x86::reg32(5628672) /* 0x55e300 */) = cpu.eax;
    // 0047a171  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047a174  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a175  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a176  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a177  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a178  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a179  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a17a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a17b:
    // 0047a17b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a17d  ebb7                   -jmp 0x47a136
    goto L_0x0047a136;
}

/* align: skip 0x00 */
void Application::sub_47a180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0047a180);
    // 0047a180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a181  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a182  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a183  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a184  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a185  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a188  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047a18a  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047a18c  68147d5500             -push 0x557d14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5602580 /*0x557d14*/;
    cpu.esp -= 4;
    // 0047a191  b987000000             -mov ecx, 0x87
    cpu.ecx = 135 /*0x87*/;
    // 0047a196  be50bf5500             -mov esi, 0x55bf50
    cpu.esi = 5619536 /*0x55bf50*/;
    // 0047a19b  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 0047a1a0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a1a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047a1a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047a1a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a1a6  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a1aa  e871000000             -call 0x47a220
    cpu.esp -= 4;
    sub_47a220(app, cpu);
    if (cpu.terminate) return;
    // 0047a1af  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a1b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a1b4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a1b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a1b9  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a1bd  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a1c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a1c2  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0047a1c7  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0047a1cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a1cd  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047a1d1  bb61000000             -mov ebx, 0x61
    cpu.ebx = 97 /*0x61*/;
    // 0047a1d6  e8c55bffff             -call 0x46fda0
    cpu.esp -= 4;
    sub_46fda0(app, cpu);
    if (cpu.terminate) return;
    // 0047a1db  68007d5500             -push 0x557d00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5602560 /*0x557d00*/;
    cpu.esp -= 4;
    // 0047a1e0  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a1e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a1e6  e835000000             -call 0x47a220
    cpu.esp -= 4;
    sub_47a220(app, cpu);
    if (cpu.terminate) return;
    // 0047a1eb  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a1ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a1f0  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a1f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a1f5  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a1f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a1fa  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a1fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a1ff  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047a203  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047a205  e8965bffff             -call 0x46fda0
    cpu.esp -= 4;
    sub_46fda0(app, cpu);
    if (cpu.terminate) return;
    // 0047a20a  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047a20e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047a20f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047a210  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047a212  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a215  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a216  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a217  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a218  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a219  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a21a  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
